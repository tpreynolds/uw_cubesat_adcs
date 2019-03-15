% File to save data to CSV

% fid = fopen('test_fsw_inputs','w');

n1 = numel(fieldnames(act_meas));
n2 = numel(fieldnames(telecommands));
n3 = numel(fieldnames(sp2fsw));

T = length(telecommands.MET.Time);

M = NaN(T,n1+n2+n3);
H = cell(1,n1+n2+n3);

M(:,1:3) = act_meas.MT_pwr.Data;
M(:,4:6) = act_meas.MT_valid.Data;
M(:,7:9) = act_meas.RW_pwr.Data;
M(:,10:12) = act_meas.RW_rpm.Data;
M(:,13:15) = act_meas.RW_valid.Data;
M(:,16) = act_meas.thruster_on.Data;
H{1}    = act_meas.MT_pwr.Name;
H{2}    = act_meas.MT_pwr.Name;
H{3}    = act_meas.MT_pwr.Name;
H{4} = act_meas.MT_valid.Name;
H{5} = act_meas.MT_valid.Name;
H{6} = act_meas.MT_valid.Name;
H{7} = act_meas.RW_pwr.Name;
H{8} = act_meas.RW_pwr.Name;
H{9} = act_meas.RW_pwr.Name;
H{10} = act_meas.RW_rpm.Name;
H{11} = act_meas.RW_rpm.Name;
H{12} = act_meas.RW_rpm.Name;
H{13} = act_meas.RW_valid.Name;
H{14} = act_meas.RW_valid.Name;
H{15} = act_meas.RW_valid.Name;
H{16} = act_meas.thruster_on.Name;

M(:,17) = telecommands.MET.Data;
M(:,18) = telecommands.MET_epoch.Data;
M(:,19:21) = telecommands.telecom.Data;
H{17} = telecommands.MET.Name;
H{18} = telecommands.MET_epoch.Name;
H{19} = telecommands.telecom.Name;
H{20} = telecommands.telecom.Name;
H{21} = telecommands.telecom.Name;

M(:,22:25) = sp2fsw.mag_vec_body_T.Data;
M(:,26:29) = sp2fsw.gyro_omega_body_radps.Data;
M(:,30:32) = sp2fsw.faceinsun_body_unit.Data;
M(:,33:36) = sp2fsw.sun_vec_body_sunsensor.Data;
M(:,37:45) = sp2fsw.orbit_tle.Data;
M(:,46:47) = sp2fsw.GPS_time.Data;
H{22} = sp2fsw.mag_vec_body_T.Name;
H{23} = sp2fsw.mag_vec_body_T.Name;
H{24} = sp2fsw.mag_vec_body_T.Name;
H{25} = sp2fsw.mag_vec_body_T.Name;
H{26} = sp2fsw.gyro_omega_body_radps.Name;
H{27} = sp2fsw.gyro_omega_body_radps.Name;
H{28} = sp2fsw.gyro_omega_body_radps.Name;
H{29} = sp2fsw.gyro_omega_body_radps.Name;
H{30} = sp2fsw.faceinsun_body_unit.Name;
H{31} = sp2fsw.faceinsun_body_unit.Name;
H{32} = sp2fsw.faceinsun_body_unit.Name;
H{33} = sp2fsw.sun_vec_body_sunsensor.Name;
H{34} = sp2fsw.sun_vec_body_sunsensor.Name;
H{35} = sp2fsw.sun_vec_body_sunsensor.Name;
H{36} = sp2fsw.sun_vec_body_sunsensor.Name;
H{37} = sp2fsw.orbit_tle.Name;
H{38} = sp2fsw.orbit_tle.Name;
H{39} = sp2fsw.orbit_tle.Name;
H{40} = sp2fsw.orbit_tle.Name;
H{41} = sp2fsw.orbit_tle.Name;
H{42} = sp2fsw.orbit_tle.Name;
H{43} = sp2fsw.orbit_tle.Name;
H{44} = sp2fsw.orbit_tle.Name;
H{45} = sp2fsw.orbit_tle.Name;
H{46} = sp2fsw.GPS_time.Name;
H{47} = sp2fsw.GPS_time.Name;

csvwrite_with_headers('test_fsw_inputs.csv',M,H);