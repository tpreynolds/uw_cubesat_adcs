function tle_array = parse_tle(file)

fid = fopen(file, 'r');
line1 = fgetl(fid);
line2 = fgetl(fid);

% Line 1
sat_num = str2double(line1(3:7));
class = line1(8);
epoch_year_str = line1(19:20);
epoch_fday = str2double(line1(21:32));
first_drv_mean_motion = str2double(line1(34:43)) * 2.0;
second_drv_mean_motion = str2double(['0.', line1(45:52)]) * 6.0;
bstar = str2double([line1(54), '0.', line1(55:59)]) * 10^(str2double(line1(60:61)));
elem_set_num = str2double(line1(65:68));
checksum_1 = mod(str2double(line1(69)), 10);

% Line 2
inc_deg = str2double(line2(9:16));
raan_deg = str2double(line2(18:25));
% ecc = str2double(['0.', line2(27:33)]);
ecc = str2double(line2(27:33));
arg_peri_deg = str2double(line2(35:42));
mean_anom_deg = str2double(line2(44:51));
mean_motion_revpday = str2double(line2(53:63));
rev_num_epoch_revs = str2double(line2(64:68));
checksum_2 = mod(str2double(line2(69)), 10);

% if checksum_1 == checksum_2
% 	valid = true;
% else
%     valid = false;
% end

tle_array = [ ...
    epoch_to_jd(epoch_year_str, epoch_fday)
    inc_deg
    raan_deg
    ecc
    arg_peri_deg
    mean_anom_deg
    mean_motion_revpday
    bstar
];

% tle_array = [2458134.71933102, 97.5545, 78.3611, 8494.0, 269.8656, ...
%     112.4361, 15.2221532, 2.9689e-05];


end

function epoch_jd_days = epoch_to_jd(epoch_year_str, epoch_fday)

year = str2double(['20', epoch_year_str]);
epoch_jd_days = juliandate(year, 0, 0, 0, 0, 0) + epoch_fday;

end