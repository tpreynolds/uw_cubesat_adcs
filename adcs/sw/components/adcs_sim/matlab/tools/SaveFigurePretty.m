
function SaveFigurePretty(hFig, fileName, varargin)
    
    % Default values for all possible arguments
    args = struct( ...
        'Ext', 'png', ...
        'DPI', 300, ...
        'Size', [], ...
        'Units', 'inches', ...
        'Trim', false);
    
    args = parseArgs(varargin, args);
    
    if (args.Trim)
        if (~contains(lower(computer()),'win')) 
            warning('Cannot use the ''Trim'' argument on non-windows computers.  Ignoring option.');
            args.Trim = false;
        end
    end
    
    if (isempty(args.Size))
        sx = 4;
        figSize = get(hFig, 'Position');
        ar = figSize(3) / figSize(4);
        sy = sx / ar;
        
        args.Size = [sx, sy];
    end
    
    % Save current figure settings
    hFigBak_CloseFcn = get(hFig, 'CloseRequestFcn');
    hFigBak_PU = get(hFig, 'PaperUnits');
    hFigBak_PP = get(hFig, 'PaperPosition');
    hFigBak_PS = get(hFig, 'PaperSize');
    
    % Prevent someone from closing the figure while we are saving it
    set(hFig, 'CloseRequestFcn', @SaveFigurePretty_CloseFcn);
    
    try
        set(hFig, 'PaperUnits', args.Units);
        set(hFig, 'PaperPosition', [0 0 args.Size(1) args.Size(2)]);
        set(hFig, 'PaperSize', args.Size);
        
        %
        % Save the image
        %
        if (~iscell(args.Ext))
            args.Ext = {args.Ext};
        end
        
        SaveFigurePrettyImpl(hFig, fileName, args);
        
        % Restore original figure settings
        set(hFig, 'PaperUnits', hFigBak_PU);
        set(hFig, 'PaperPosition', hFigBak_PP);
        set(hFig, 'PaperSize', hFigBak_PS);
        
    catch err
        fprintf('Encountered an error saving the file\n');
    end
    
    set(hFig, 'CloseRequestFcn', hFigBak_CloseFcn);
end

function SaveFigurePrettyImpl(hFig, fileName, args)
    
    % Imagemagick has a bug.  Once it is fixed, we can allow trimming again
    % Might need to install imagemagick
    %   From:   http://www.imagemagick.org/script/binary-releases.php
    %   To:     C:\Program Files (x86)\LyX 2.1\imagemagick
    %   convert.exe: unable to load module `C:\Program Files (x86)\LyX 2.1\imagemagick\modules\coders\IM_MOD_RL_PNG_.dll': The specified module could not be found.  @ error/module.c/OpenModule/1300. 
    %   convert.exe: no decode delegate for this image format `PNG' @ error/constitute.c/ReadImage/501. 
    %   convert.exe: no images defined `[PATH_TO_FILE].png' @ error/convert.c/ConvertImageCommand/3241. 
    ALLOW_TRIM = true;
    
    if (ALLOW_TRIM)
        persistent strImageMagickConvertPath;
        persistent fIsImageMagickPresent;
    end
    
    N = length(args.Ext);
    
    %strImageMagickConvertPath = [];
    %fIsImageMagickPresent = [];
    
    for i=1:N
        if (strcmpi(args.Ext{i}, 'png'))
            format = '-dpng';
        elseif (strcmpi(args.Ext{i}, 'eps'))
            format = '-depsc';
        else
            error(['Unknown format specifier. Ext: ' args.Ext]);
        end
        
        print(hFig, format, ['-r' num2str(args.DPI)], '-loose', ['-', lower(get(hFig, 'Renderer'))], fileName);
        
        if (args.Trim)
            if (exist('TrimImage.exe', 'file')==2)
                strAppPath = which('TrimImage.exe');
                % convert.exe apparently does not play nice with eps files.
                if (strcmpi(args.Ext{i}, 'png'))
                    
                    strFullFileName = sprintf('%s.%s', fileName, args.Ext{i});
                    system(sprintf('cd /d %s', pwd()));
                    
                    cmd = sprintf('%s %s %s', strAppPath, strFullFileName, strFullFileName);
                    system(cmd);
                else
                    if (ALLOW_TRIM)
                        if (isempty(strImageMagickConvertPath) && isempty(fIsImageMagickPresent))
                            fprintf('Searching for ImageMagick utility convert.exe to trim images.  Each time MATLAB runs, this will be slow the first time.\n');
                            strImageMagickConvertPath = FindFile('*program*imagemagick*convert.exe');
                            fIsImageMagickPresent = ~isempty(strImageMagickConvertPath);
                        end
                        if (fIsImageMagickPresent)
                            strFullFileName = sprintf('%s.%s', fileName, args.Ext{i});
                            system(sprintf('cd /d %s', pwd()));
                            
                            cmd = sprintf('"%s" %s -trim %s', strImageMagickConvertPath, strFullFileName, strFullFileName);
                            system(cmd);
                        end
                    end
                end
            end
        end
    end
end

function SaveFigurePretty_CloseFcn(~,~,~)
    fprintf('Cannot close this figure while a save operation is in progress.\n');
end