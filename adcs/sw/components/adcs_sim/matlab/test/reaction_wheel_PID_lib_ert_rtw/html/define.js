function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:39,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:75,type:"fcn"};
this.def["rtDW"] = {file: "reaction_wheel_PID_lib_c.html",line:25,type:"var"};
this.def["rtU"] = {file: "reaction_wheel_PID_lib_c.html",line:28,type:"var"};
this.def["rtY"] = {file: "reaction_wheel_PID_lib_c.html",line:31,type:"var"};
this.def["reaction_wheel_PID_lib_step"] = {file: "reaction_wheel_PID_lib_c.html",line:34,type:"fcn"};
this.def["reaction_wheel_PID_lib_initialize"] = {file: "reaction_wheel_PID_lib_c.html",line:77,type:"fcn"};
this.def["reaction_wheel_PID_lib_terminate"] = {file: "reaction_wheel_PID_lib_c.html",line:83,type:"fcn"};
this.def["DW"] = {file: "reaction_wheel_PID_lib_h.html",line:35,type:"type"};
this.def["ExtU"] = {file: "reaction_wheel_PID_lib_h.html",line:41,type:"type"};
this.def["ExtY"] = {file: "reaction_wheel_PID_lib_h.html",line:46,type:"type"};
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
	this.html2SrcPath["reaction_wheel_PID_lib_c.html"] = "../reaction_wheel_PID_lib.c";
	this.html2Root["reaction_wheel_PID_lib_c.html"] = "reaction_wheel_PID_lib_c.html";
	this.html2SrcPath["reaction_wheel_PID_lib_h.html"] = "../reaction_wheel_PID_lib.h";
	this.html2Root["reaction_wheel_PID_lib_h.html"] = "reaction_wheel_PID_lib_h.html";
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
"ert_main_c.html","reaction_wheel_PID_lib_c.html","reaction_wheel_PID_lib_h.html","rtwtypes_h.html"];
