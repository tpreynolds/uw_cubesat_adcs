function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:39,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:125,type:"fcn"};
this.def["rtDW"] = {file: "bdot_controller_lib_c.html",line:25,type:"var"};
this.def["rtU"] = {file: "bdot_controller_lib_c.html",line:28,type:"var"};
this.def["rtY"] = {file: "bdot_controller_lib_c.html",line:31,type:"var"};
this.def["rtM_"] = {file: "bdot_controller_lib_c.html",line:34,type:"var"};
this.def["rtM"] = {file: "bdot_controller_lib_c.html",line:35,type:"var"};
this.def["bdot_controller_lib_step0"] = {file: "bdot_controller_lib_c.html",line:38,type:"fcn"};
this.def["bdot_controller_lib_step1"] = {file: "bdot_controller_lib_c.html",line:88,type:"fcn"};
this.def["bdot_controller_lib_initialize"] = {file: "bdot_controller_lib_c.html",line:255,type:"fcn"};
this.def["bdot_controller_lib_terminate"] = {file: "bdot_controller_lib_c.html",line:261,type:"fcn"};
this.def["RT_MODEL"] = {file: "bdot_controller_lib_h.html",line:41,type:"type"};
this.def["DW"] = {file: "bdot_controller_lib_h.html",line:55,type:"type"};
this.def["ConstP"] = {file: "bdot_controller_lib_h.html",line:63,type:"type"};
this.def["ExtU"] = {file: "bdot_controller_lib_h.html",line:70,type:"type"};
this.def["ExtY"] = {file: "bdot_controller_lib_h.html",line:75,type:"type"};
this.def["rtConstP"] = {file: "bdot_controller_lib_data_c.html",line:25,type:"var"};
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
	this.html2SrcPath["bdot_controller_lib_c.html"] = "../bdot_controller_lib.c";
	this.html2Root["bdot_controller_lib_c.html"] = "bdot_controller_lib_c.html";
	this.html2SrcPath["bdot_controller_lib_h.html"] = "../bdot_controller_lib.h";
	this.html2Root["bdot_controller_lib_h.html"] = "bdot_controller_lib_h.html";
	this.html2SrcPath["bdot_controller_lib_data_c.html"] = "../bdot_controller_lib_data.c";
	this.html2Root["bdot_controller_lib_data_c.html"] = "bdot_controller_lib_data_c.html";
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
"ert_main_c.html","bdot_controller_lib_c.html","bdot_controller_lib_h.html","bdot_controller_lib_data_c.html","rtwtypes_h.html"];
