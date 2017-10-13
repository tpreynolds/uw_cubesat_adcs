function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "/Users/taylorreynolds/uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_fsw/matlab/test/fsw-autocode-test/control_selection/control_selection0_ert_rtw/control_selection0.c",
	size: 366};
	 this.metricsArray.var["rtM_"] = {file: "/Users/taylorreynolds/uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_fsw/matlab/test/fsw-autocode-test/control_selection/control_selection0_ert_rtw/control_selection0.c",
	size: 5};
	 this.metricsArray.var["rtU"] = {file: "/Users/taylorreynolds/uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_fsw/matlab/test/fsw-autocode-test/control_selection/control_selection0_ert_rtw/control_selection0.c",
	size: 121};
	 this.metricsArray.var["rtY"] = {file: "/Users/taylorreynolds/uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_fsw/matlab/test/fsw-autocode-test/control_selection/control_selection0_ert_rtw/control_selection0.c",
	size: 56};
	 this.metricsArray.fcn["control_selection0_initialize"] = {file: "/Users/taylorreynolds/uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_fsw/matlab/test/fsw-autocode-test/control_selection/control_selection0_ert_rtw/control_selection0.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["control_selection0_step0"] = {file: "/Users/taylorreynolds/uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_fsw/matlab/test/fsw-autocode-test/control_selection/control_selection0_ert_rtw/control_selection0.c",
	stack: 2,
	stackTotal: 2};
	 this.metricsArray.fcn["control_selection0_step1"] = {file: "/Users/taylorreynolds/uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_fsw/matlab/test/fsw-autocode-test/control_selection/control_selection0_ert_rtw/control_selection0.c",
	stack: 179,
	stackTotal: 179};
	 this.metricsArray.fcn["control_selection0_step2"] = {file: "/Users/taylorreynolds/uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_fsw/matlab/test/fsw-autocode-test/control_selection/control_selection0_ert_rtw/control_selection0.c",
	stack: 94,
	stackTotal: 94};
	 this.metricsArray.fcn["control_selection0_terminate"] = {file: "/Users/taylorreynolds/uw_cubesat_adcs_sourcetree/adcs/sw/components/adcs_fsw/matlab/test/fsw-autocode-test/control_selection/control_selection0_ert_rtw/control_selection0.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sqrt"] = {file: "/Applications/MATLAB_R2016b.app/sys/lcc/include/math.h",
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
