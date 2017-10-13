function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:39,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:76,type:"fcn"};
this.def["rtU"] = {file: "mode_selecction_c.html",line:26,type:"var"};
this.def["rtY"] = {file: "mode_selecction_c.html",line:29,type:"var"};
this.def["rtM_"] = {file: "mode_selecction_c.html",line:32,type:"var"};
this.def["rtM"] = {file: "mode_selecction_c.html",line:33,type:"var"};
this.def["mode_selecction_step"] = {file: "mode_selecction_c.html",line:36,type:"fcn"};
this.def["mode_selecction_initialize"] = {file: "mode_selecction_c.html",line:52,type:"fcn"};
this.def["mode_selecction_terminate"] = {file: "mode_selecction_c.html",line:61,type:"fcn"};
this.def["ExtU"] = {file: "mode_selecction_h.html",line:55,type:"type"};
this.def["ExtY"] = {file: "mode_selecction_h.html",line:60,type:"type"};
this.def["RT_MODEL"] = {file: "mode_selecction_types_h.html",line:26,type:"type"};
this.def["norm"] = {file: "mode_selecction_a_c.html",line:32,type:"fcn"};
this.def["mode_selecction_a"] = {file: "mode_selecction_a_c.html",line:82,type:"fcn"};
this.def["rtGetInf"] = {file: "rtGetInf_c.html",line:33,type:"fcn"};
this.def["rtGetInfF"] = {file: "rtGetInf_c.html",line:57,type:"fcn"};
this.def["rtGetMinusInf"] = {file: "rtGetInf_c.html",line:68,type:"fcn"};
this.def["rtGetMinusInfF"] = {file: "rtGetInf_c.html",line:92,type:"fcn"};
this.def["rtGetNaN"] = {file: "rtGetNaN_c.html",line:33,type:"fcn"};
this.def["rtGetNaNF"] = {file: "rtGetNaN_c.html",line:57,type:"fcn"};
this.def["rtInf"] = {file: "rt_nonfinite_c.html",line:31,type:"var"};
this.def["rtMinusInf"] = {file: "rt_nonfinite_c.html",line:32,type:"var"};
this.def["rtNaN"] = {file: "rt_nonfinite_c.html",line:33,type:"var"};
this.def["rtInfF"] = {file: "rt_nonfinite_c.html",line:34,type:"var"};
this.def["rtMinusInfF"] = {file: "rt_nonfinite_c.html",line:35,type:"var"};
this.def["rtNaNF"] = {file: "rt_nonfinite_c.html",line:36,type:"var"};
this.def["rt_InitInfAndNaN"] = {file: "rt_nonfinite_c.html",line:42,type:"fcn"};
this.def["rtIsInf"] = {file: "rt_nonfinite_c.html",line:54,type:"fcn"};
this.def["rtIsInfF"] = {file: "rt_nonfinite_c.html",line:60,type:"fcn"};
this.def["rtIsNaN"] = {file: "rt_nonfinite_c.html",line:66,type:"fcn"};
this.def["rtIsNaNF"] = {file: "rt_nonfinite_c.html",line:72,type:"fcn"};
this.def["BigEndianIEEEDouble"] = {file: "rt_nonfinite_h.html",line:43,type:"type"};
this.def["LittleEndianIEEEDouble"] = {file: "rt_nonfinite_h.html",line:50,type:"type"};
this.def["IEEESingle"] = {file: "rt_nonfinite_h.html",line:57,type:"type"};
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
	this.html2SrcPath["mode_selecction_c.html"] = "../mode_selecction.c";
	this.html2Root["mode_selecction_c.html"] = "mode_selecction_c.html";
	this.html2SrcPath["mode_selecction_h.html"] = "../mode_selecction.h";
	this.html2Root["mode_selecction_h.html"] = "mode_selecction_h.html";
	this.html2SrcPath["mode_selecction_private_h.html"] = "../mode_selecction_private.h";
	this.html2Root["mode_selecction_private_h.html"] = "mode_selecction_private_h.html";
	this.html2SrcPath["mode_selecction_types_h.html"] = "../mode_selecction_types.h";
	this.html2Root["mode_selecction_types_h.html"] = "mode_selecction_types_h.html";
	this.html2SrcPath["mode_selecction_a_c.html"] = "../mode_selecction_a.c";
	this.html2Root["mode_selecction_a_c.html"] = "mode_selecction_a_c.html";
	this.html2SrcPath["mode_selecction_a_h.html"] = "../mode_selecction_a.h";
	this.html2Root["mode_selecction_a_h.html"] = "mode_selecction_a_h.html";
	this.html2SrcPath["rtGetInf_c.html"] = "../rtGetInf.c";
	this.html2Root["rtGetInf_c.html"] = "rtGetInf_c.html";
	this.html2SrcPath["rtGetInf_h.html"] = "../rtGetInf.h";
	this.html2Root["rtGetInf_h.html"] = "rtGetInf_h.html";
	this.html2SrcPath["rtGetNaN_c.html"] = "../rtGetNaN.c";
	this.html2Root["rtGetNaN_c.html"] = "rtGetNaN_c.html";
	this.html2SrcPath["rtGetNaN_h.html"] = "../rtGetNaN.h";
	this.html2Root["rtGetNaN_h.html"] = "rtGetNaN_h.html";
	this.html2SrcPath["rt_nonfinite_c.html"] = "../rt_nonfinite.c";
	this.html2Root["rt_nonfinite_c.html"] = "rt_nonfinite_c.html";
	this.html2SrcPath["rt_nonfinite_h.html"] = "../rt_nonfinite.h";
	this.html2Root["rt_nonfinite_h.html"] = "rt_nonfinite_h.html";
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
"ert_main_c.html","mode_selecction_c.html","mode_selecction_h.html","mode_selecction_private_h.html","mode_selecction_types_h.html","mode_selecction_a_c.html","mode_selecction_a_h.html","rtGetInf_c.html","rtGetInf_h.html","rtGetNaN_c.html","rtGetNaN_h.html","rt_nonfinite_c.html","rt_nonfinite_h.html","rtwtypes_h.html"];
