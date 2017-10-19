function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:39,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:76,type:"fcn"};
this.def["rtDW"] = {file: "mag_vector_c.html",line:26,type:"var"};
this.def["rtU"] = {file: "mag_vector_c.html",line:29,type:"var"};
this.def["rtY"] = {file: "mag_vector_c.html",line:32,type:"var"};
this.def["rtM_"] = {file: "mag_vector_c.html",line:35,type:"var"};
this.def["rtM"] = {file: "mag_vector_c.html",line:36,type:"var"};
this.def["BigEndianIEEEDouble"] = {file: "mag_vector_c.html",line:90,type:"type"};
this.def["LittleEndianIEEEDouble"] = {file: "mag_vector_c.html",line:97,type:"type"};
this.def["IEEESingle"] = {file: "mag_vector_c.html",line:104,type:"type"};
this.def["rtInf"] = {file: "mag_vector_c.html",line:106,type:"var"};
this.def["rtMinusInf"] = {file: "mag_vector_c.html",line:107,type:"var"};
this.def["rtNaN"] = {file: "mag_vector_c.html",line:108,type:"var"};
this.def["rtInfF"] = {file: "mag_vector_c.html",line:109,type:"var"};
this.def["rtMinusInfF"] = {file: "mag_vector_c.html",line:110,type:"var"};
this.def["rtNaNF"] = {file: "mag_vector_c.html",line:111,type:"var"};
this.def["rtGetNaN"] = {file: "mag_vector_c.html",line:121,type:"fcn"};
this.def["rtGetNaNF"] = {file: "mag_vector_c.html",line:145,type:"fcn"};
this.def["rt_InitInfAndNaN"] = {file: "mag_vector_c.html",line:157,type:"fcn"};
this.def["rtIsInf"] = {file: "mag_vector_c.html",line:169,type:"fcn"};
this.def["rtIsInfF"] = {file: "mag_vector_c.html",line:175,type:"fcn"};
this.def["rtIsNaN"] = {file: "mag_vector_c.html",line:181,type:"fcn"};
this.def["rtIsNaNF"] = {file: "mag_vector_c.html",line:187,type:"fcn"};
this.def["rtGetInf"] = {file: "mag_vector_c.html",line:196,type:"fcn"};
this.def["rtGetInfF"] = {file: "mag_vector_c.html",line:220,type:"fcn"};
this.def["rtGetMinusInf"] = {file: "mag_vector_c.html",line:231,type:"fcn"};
this.def["rtGetMinusInfF"] = {file: "mag_vector_c.html",line:255,type:"fcn"};
this.def["mul_wide_s32"] = {file: "mag_vector_c.html",line:262,type:"fcn"};
this.def["mul_s32_sat"] = {file: "mag_vector_c.html",line:308,type:"fcn"};
this.def["rt_atan2d_snf"] = {file: "mag_vector_c.html",line:327,type:"fcn"};
this.def["mag_vector_step"] = {file: "mag_vector_c.html",line:364,type:"fcn"};
this.def["mag_vector_initialize"] = {file: "mag_vector_c.html",line:1709,type:"fcn"};
this.def["mag_vector_terminate"] = {file: "mag_vector_c.html",line:1786,type:"fcn"};
this.def["RT_MODEL"] = {file: "mag_vector_h.html",line:44,type:"type"};
this.def["DW"] = {file: "mag_vector_h.html",line:84,type:"type"};
this.def["ConstP"] = {file: "mag_vector_h.html",line:140,type:"type"};
this.def["ExtU"] = {file: "mag_vector_h.html",line:147,type:"type"};
this.def["ExtY"] = {file: "mag_vector_h.html",line:153,type:"type"};
this.def["rtConstP"] = {file: "mag_vector_data_c.html",line:25,type:"var"};
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
	this.html2SrcPath["mag_vector_c.html"] = "../mag_vector.c";
	this.html2Root["mag_vector_c.html"] = "mag_vector_c.html";
	this.html2SrcPath["mag_vector_h.html"] = "../mag_vector.h";
	this.html2Root["mag_vector_h.html"] = "mag_vector_h.html";
	this.html2SrcPath["mag_vector_data_c.html"] = "../mag_vector_data.c";
	this.html2Root["mag_vector_data_c.html"] = "mag_vector_data_c.html";
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
"ert_main_c.html","mag_vector_c.html","mag_vector_h.html","mag_vector_data_c.html","rtwtypes_h.html"];
