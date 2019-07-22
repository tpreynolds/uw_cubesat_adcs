function [ fid ] = write_testinput_file( lib_name,varargin )
%WRITE_TESTINPUT_FILE
%
% fid = write_testinput_file(lib_name,varargin) will write the signals
% passed in through varargin to the file specified by lib_name. The format
% is: 
%       { {signal_1}, {signal_2}, ... , {signal_N} },
%                           .
%                           .
%                           .
%       { {signal_1}, {signal_2}, ... , {signal_N} }
% where each row is a set of inputs to the library for a specific
% time instance. All signals must have the same number of rows (the number 
% of such time instances), with their columns representing the number of
% elements in each signal (i.e. a quaternion would have four columns).
%
% T. Reynolds

if ~(nargin>1)
    error('WRITING TEST INPUT: Must have at least one input')
end

ninputs  = size(varargin{1},1);
nsignals = nargin-1;

sizes   = NaN(nsignals,1);

for k = 1:nsignals
    sizes(k) = size(varargin{k},2);
    if (size(varargin{k},1) ~= ninputs)
        error('WRITING TEST INPUT: One of the inputs has the wrong size')
    end
end

fid = fopen(lib_name,'w+');

% loop through number of inputs
for i = 1:ninputs
    % open main input line bracket
    fprintf(fid,'{');
    % loop through number of signals (inputs)
    for j = 1:nsignals
        % open signal bracket
        fprintf(fid,'{');
        % loop through the signal length
        for k = 1:sizes(j)
            % comma separation except the last entry
            if (k<sizes(j))
                fprintf(fid,'%0.6f,',varargin{j}(i,k));
            else
                fprintf(fid,'%0.6f',varargin{j}(i,k));
            end
        end
        % close the bracket for this input. Comma separation except last
        % entry
        if (j<nsignals)
            fprintf(fid,'},');
        else
            fprintf(fid,'}');
        end
    end
    % close main input line bracket
    fprintf(fid,'},\n');
end



end

