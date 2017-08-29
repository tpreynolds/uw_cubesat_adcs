function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "/Users/Taylor/uw_cubesat_adcs_2/adcs/sw/components/adcs_bdot/matlab/bdot_controller_lib_ert_rtw/bdot_controller_lib.c",
	size: 139};
	 this.metricsArray.var["rtM_"] = {file: "/Users/Taylor/uw_cubesat_adcs_2/adcs/sw/components/adcs_bdot/matlab/bdot_controller_lib_ert_rtw/bdot_controller_lib.c",
	size: 3};
	 this.metricsArray.var["rtU"] = {file: "/Users/Taylor/uw_cubesat_adcs_2/adcs/sw/components/adcs_bdot/matlab/bdot_controller_lib_ert_rtw/bdot_controller_lib.c",
	size: 40};
	 this.metricsArray.var["rtY"] = {file: "/Users/Taylor/uw_cubesat_adcs_2/adcs/sw/components/adcs_bdot/matlab/bdot_controller_lib_ert_rtw/bdot_controller_lib.c",
	size: 24};
	 this.metricsArray.fcn["bdot_controller_lib_initialize"] = {file: "/Users/Taylor/uw_cubesat_adcs_2/adcs/sw/components/adcs_bdot/matlab/bdot_controller_lib_ert_rtw/bdot_controller_lib.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["bdot_controller_lib_step0"] = {file: "/Users/Taylor/uw_cubesat_adcs_2/adcs/sw/components/adcs_bdot/matlab/bdot_controller_lib_ert_rtw/bdot_controller_lib.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["bdot_controller_lib_step1"] = {file: "/Users/Taylor/uw_cubesat_adcs_2/adcs/sw/components/adcs_bdot/matlab/bdot_controller_lib_ert_rtw/bdot_controller_lib.c",
	stack: 147,
	stackTotal: 147};
	 this.metricsArray.fcn["bdot_controller_lib_terminate"] = {file: "/Users/Taylor/uw_cubesat_adcs_2/adcs/sw/components/adcs_bdot/matlab/bdot_controller_lib_ert_rtw/bdot_controller_lib.c",
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
