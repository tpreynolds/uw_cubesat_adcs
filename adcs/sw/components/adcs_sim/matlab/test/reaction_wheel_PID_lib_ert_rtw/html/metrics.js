function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "/Users/Taylor/uw_cubesat_adcs/adcs/sw/components/adcs_sim/matlab/test/reaction_wheel_PID_lib_ert_rtw/reaction_wheel_PID_lib.c",
	size: 16};
	 this.metricsArray.var["rtU"] = {file: "/Users/Taylor/uw_cubesat_adcs/adcs/sw/components/adcs_sim/matlab/test/reaction_wheel_PID_lib_ert_rtw/reaction_wheel_PID_lib.c",
	size: 16};
	 this.metricsArray.var["rtY"] = {file: "/Users/Taylor/uw_cubesat_adcs/adcs/sw/components/adcs_sim/matlab/test/reaction_wheel_PID_lib_ert_rtw/reaction_wheel_PID_lib.c",
	size: 8};
	 this.metricsArray.fcn["reaction_wheel_PID_lib_initialize"] = {file: "/Users/Taylor/uw_cubesat_adcs/adcs/sw/components/adcs_sim/matlab/test/reaction_wheel_PID_lib_ert_rtw/reaction_wheel_PID_lib.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["reaction_wheel_PID_lib_step"] = {file: "/Users/Taylor/uw_cubesat_adcs/adcs/sw/components/adcs_sim/matlab/test/reaction_wheel_PID_lib_ert_rtw/reaction_wheel_PID_lib.c",
	stack: 8,
	stackTotal: 8};
	 this.metricsArray.fcn["reaction_wheel_PID_lib_terminate"] = {file: "/Users/Taylor/uw_cubesat_adcs/adcs/sw/components/adcs_sim/matlab/test/reaction_wheel_PID_lib_ert_rtw/reaction_wheel_PID_lib.c",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data;}
}
	 CodeMetrics.instance = new CodeMetrics();
