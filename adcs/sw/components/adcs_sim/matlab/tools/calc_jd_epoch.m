function jd_epoch_days = calc_jd_epoch(int_year, dec_day)

y = int_year + 2000;

jd_int_days = 365.25*(y-1) + (floor((y - 1)/400) - floor((y - 1)/100) + floor((y - 1)/4)) + floor(30.6001*14) + 1720996.5;
jd_epoch_days = dec_day + jd_int_days;

end