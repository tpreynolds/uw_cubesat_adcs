function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:39,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:149,type:"fcn"};
this.def["rtDW"] = {file: "control_selection0_c.html",line:25,type:"var"};
this.def["rtU"] = {file: "control_selection0_c.html",line:28,type:"var"};
this.def["rtY"] = {file: "control_selection0_c.html",line:31,type:"var"};
this.def["rtM_"] = {file: "control_selection0_c.html",line:34,type:"var"};
this.def["rtM"] = {file: "control_selection0_c.html",line:35,type:"var"};
this.def["_assert"] = {file: "control_selection0_c.html",line:48,type:"fcn"};
this.def["control_selection0_step0"] = {file: "control_selection0_c.html",line:62,type:"fcn"};
this.def["control_selection0_step1"] = {file: "control_selection0_c.html",line:157,type:"fcn"};
this.def["control_selection0_step2"] = {file: "control_selection0_c.html",line:541,type:"fcn"};
this.def["control_selection0_initialize"] = {file: "control_selection0_c.html",line:635,type:"fcn"};
this.def["control_selection0_terminate"] = {file: "control_selection0_c.html",line:641,type:"fcn"};
this.def["RT_MODEL"] = {file: "control_selection0_h.html",line:42,type:"type"};
this.def["DW"] = {file: "control_selection0_h.html",line:64,type:"type"};
this.def["ConstB"] = {file: "control_selection0_h.html",line:69,type:"type"};
this.def["ConstP"] = {file: "control_selection0_h.html",line:82,type:"type"};
this.def["ExtU"] = {file: "control_selection0_h.html",line:92,type:"type"};
this.def["ExtY"] = {file: "control_selection0_h.html",line:99,type:"type"};
this.def["rtConstB"] = {file: "control_selection0_data_c.html",line:25,type:"var"};
this.def["rtConstP"] = {file: "control_selection0_data_c.html",line:31,type:"var"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:59,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:73,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:74,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:92,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "/";
var isPC = false;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["control_selection0_c.html"] = "../control_selection0.c";
	this.html2Root["control_selection0_c.html"] = "control_selection0_c.html";
	this.html2SrcPath["control_selection0_h.html"] = "../control_selection0.h";
	this.html2Root["control_selection0_h.html"] = "control_selection0_h.html";
	this.html2SrcPath["control_selection0_data_c.html"] = "../control_selection0_data.c";
	this.html2Root["control_selection0_data_c.html"] = "control_selection0_data_c.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","control_selection0_c.html","control_selection0_h.html","control_selection0_data_c.html","rtwtypes_h.html"];
