function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S1>/Constant */
	this.urlHashMap["bdot_simple_sim:154:47"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=bdot_simple_sim:154:47";
	/* <S1>/Control Gain */
	this.urlHashMap["bdot_simple_sim:154:3"] = "bdot_controller_lib.c:159,173,189";
	/* <S1>/Discrete
Transfer Fcn */
	this.urlHashMap["bdot_simple_sim:154:32"] = "bdot_controller_lib.c:115,116,217,218,227,228,232,237,238,247,248&bdot_controller_lib.h:46";
	/* <S1>/Logical
Operator */
	this.urlHashMap["bdot_simple_sim:154:28"] = "bdot_controller_lib.c:126";
	/* <S1>/Logical
Operator1 */
	this.urlHashMap["bdot_simple_sim:154:42"] = "bdot_controller_lib.c:106";
	/* <S1>/Multiport
Switch1 */
	this.urlHashMap["bdot_simple_sim:154:33"] = "bdot_controller_lib.c:125,149";
	/* <S1>/Multiport
Switch2 */
	this.urlHashMap["bdot_simple_sim:154:46"] = "bdot_controller_lib.c:151,206";
	/* <S1>/Rate Transition1 */
	this.urlHashMap["bdot_simple_sim:154:6"] = "bdot_controller_lib.c:65,73,246&bdot_controller_lib.h:48";
	/* <S1>/Rate Transition2 */
	this.urlHashMap["bdot_simple_sim:154:29"] = "bdot_controller_lib.c:56,63,109&bdot_controller_lib.h:51,53";
	/* <S1>/Rate Transition3 */
	this.urlHashMap["bdot_simple_sim:154:30"] = "bdot_controller_lib.c:47,54,101&bdot_controller_lib.h:50,52";
	/* <S1>/Rate Transition4 */
	this.urlHashMap["bdot_simple_sim:154:7"] = "bdot_controller_lib.c:75,84,208&bdot_controller_lib.h:49,54";
	/* <S1>/Saturation */
	this.urlHashMap["bdot_simple_sim:154:8"] = "bdot_controller_lib.c:162,178,194";
	/* <S1>/To DigVal1 */
	this.urlHashMap["bdot_simple_sim:154:17"] = "bdot_controller_lib.c:152,174,190";
	/* <S1>/Unit Delay */
	this.urlHashMap["bdot_simple_sim:154:45"] = "bdot_controller_lib.c:128,226&bdot_controller_lib.h:45";
	/* <S2>/Data Type
Duplicate */
	this.urlHashMap["bdot_simple_sim:154:41:2"] = "msg=rtwMsg_SimulationReducedBlock&block=bdot_simple_sim:154:41:2";
	/* <S2>/Diff */
	this.urlHashMap["bdot_simple_sim:154:41:3"] = "bdot_controller_lib.c:127,131";
	/* <S2>/TSamp */
	this.urlHashMap["bdot_simple_sim:154:41:4"] = "bdot_controller_lib.c:114,118";
	/* <S2>/UD */
	this.urlHashMap["bdot_simple_sim:154:41:5"] = "bdot_controller_lib.c:129,135,236,240&bdot_controller_lib.h:47";
	/* <S3>/Constant */
	this.urlHashMap["bdot_simple_sim:154:54"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=bdot_simple_sim:154:54";
	/* <S3>/Constant1 */
	this.urlHashMap["bdot_simple_sim:154:56"] = "bdot_controller_lib.c:216&bdot_controller_lib.h:60&bdot_controller_lib_data.c:27";
	/* <S3>/Product */
	this.urlHashMap["bdot_simple_sim:154:55"] = "bdot_controller_lib.c:215";
	/* <S3>/Sum */
	this.urlHashMap["bdot_simple_sim:154:53"] = "bdot_controller_lib.c:219";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "bdot_controller_lib"};
	this.sidHashMap["bdot_controller_lib"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "bdot_simple_sim:154"};
	this.sidHashMap["bdot_simple_sim:154"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "bdot_simple_sim:154:41"};
	this.sidHashMap["bdot_simple_sim:154:41"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "bdot_simple_sim:154:50"};
	this.sidHashMap["bdot_simple_sim:154:50"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S1>/B_body_in_T"] = {sid: "bdot_simple_sim:154:22"};
	this.sidHashMap["bdot_simple_sim:154:22"] = {rtwname: "<S1>/B_body_in_T"};
	this.rtwnameHashMap["<S1>/B_meas_valid"] = {sid: "bdot_simple_sim:154:25"};
	this.sidHashMap["bdot_simple_sim:154:25"] = {rtwname: "<S1>/B_meas_valid"};
	this.rtwnameHashMap["<S1>/MT_on"] = {sid: "bdot_simple_sim:154:27"};
	this.sidHashMap["bdot_simple_sim:154:27"] = {rtwname: "<S1>/MT_on"};
	this.rtwnameHashMap["<S1>/Constant"] = {sid: "bdot_simple_sim:154:47"};
	this.sidHashMap["bdot_simple_sim:154:47"] = {rtwname: "<S1>/Constant"};
	this.rtwnameHashMap["<S1>/Control Gain"] = {sid: "bdot_simple_sim:154:3"};
	this.sidHashMap["bdot_simple_sim:154:3"] = {rtwname: "<S1>/Control Gain"};
	this.rtwnameHashMap["<S1>/Discrete Transfer Fcn"] = {sid: "bdot_simple_sim:154:32"};
	this.sidHashMap["bdot_simple_sim:154:32"] = {rtwname: "<S1>/Discrete Transfer Fcn"};
	this.rtwnameHashMap["<S1>/Discrete Derivative"] = {sid: "bdot_simple_sim:154:41"};
	this.sidHashMap["bdot_simple_sim:154:41"] = {rtwname: "<S1>/Discrete Derivative"};
	this.rtwnameHashMap["<S1>/Logical Operator"] = {sid: "bdot_simple_sim:154:28"};
	this.sidHashMap["bdot_simple_sim:154:28"] = {rtwname: "<S1>/Logical Operator"};
	this.rtwnameHashMap["<S1>/Logical Operator1"] = {sid: "bdot_simple_sim:154:42"};
	this.sidHashMap["bdot_simple_sim:154:42"] = {rtwname: "<S1>/Logical Operator1"};
	this.rtwnameHashMap["<S1>/Multiport Switch1"] = {sid: "bdot_simple_sim:154:33"};
	this.sidHashMap["bdot_simple_sim:154:33"] = {rtwname: "<S1>/Multiport Switch1"};
	this.rtwnameHashMap["<S1>/Multiport Switch2"] = {sid: "bdot_simple_sim:154:46"};
	this.sidHashMap["bdot_simple_sim:154:46"] = {rtwname: "<S1>/Multiport Switch2"};
	this.rtwnameHashMap["<S1>/Rate Transition1"] = {sid: "bdot_simple_sim:154:6"};
	this.sidHashMap["bdot_simple_sim:154:6"] = {rtwname: "<S1>/Rate Transition1"};
	this.rtwnameHashMap["<S1>/Rate Transition2"] = {sid: "bdot_simple_sim:154:29"};
	this.sidHashMap["bdot_simple_sim:154:29"] = {rtwname: "<S1>/Rate Transition2"};
	this.rtwnameHashMap["<S1>/Rate Transition3"] = {sid: "bdot_simple_sim:154:30"};
	this.sidHashMap["bdot_simple_sim:154:30"] = {rtwname: "<S1>/Rate Transition3"};
	this.rtwnameHashMap["<S1>/Rate Transition4"] = {sid: "bdot_simple_sim:154:7"};
	this.sidHashMap["bdot_simple_sim:154:7"] = {rtwname: "<S1>/Rate Transition4"};
	this.rtwnameHashMap["<S1>/Saturation"] = {sid: "bdot_simple_sim:154:8"};
	this.sidHashMap["bdot_simple_sim:154:8"] = {rtwname: "<S1>/Saturation"};
	this.rtwnameHashMap["<S1>/Signal Processing"] = {sid: "bdot_simple_sim:154:50"};
	this.sidHashMap["bdot_simple_sim:154:50"] = {rtwname: "<S1>/Signal Processing"};
	this.rtwnameHashMap["<S1>/To DigVal1"] = {sid: "bdot_simple_sim:154:17"};
	this.sidHashMap["bdot_simple_sim:154:17"] = {rtwname: "<S1>/To DigVal1"};
	this.rtwnameHashMap["<S1>/Unit Delay"] = {sid: "bdot_simple_sim:154:45"};
	this.sidHashMap["bdot_simple_sim:154:45"] = {rtwname: "<S1>/Unit Delay"};
	this.rtwnameHashMap["<S1>/Dig_val"] = {sid: "bdot_simple_sim:154:23"};
	this.sidHashMap["bdot_simple_sim:154:23"] = {rtwname: "<S1>/Dig_val"};
	this.rtwnameHashMap["<S2>/U"] = {sid: "bdot_simple_sim:154:41:1"};
	this.sidHashMap["bdot_simple_sim:154:41:1"] = {rtwname: "<S2>/U"};
	this.rtwnameHashMap["<S2>/Data Type Duplicate"] = {sid: "bdot_simple_sim:154:41:2"};
	this.sidHashMap["bdot_simple_sim:154:41:2"] = {rtwname: "<S2>/Data Type Duplicate"};
	this.rtwnameHashMap["<S2>/Diff"] = {sid: "bdot_simple_sim:154:41:3"};
	this.sidHashMap["bdot_simple_sim:154:41:3"] = {rtwname: "<S2>/Diff"};
	this.rtwnameHashMap["<S2>/TSamp"] = {sid: "bdot_simple_sim:154:41:4"};
	this.sidHashMap["bdot_simple_sim:154:41:4"] = {rtwname: "<S2>/TSamp"};
	this.rtwnameHashMap["<S2>/UD"] = {sid: "bdot_simple_sim:154:41:5"};
	this.sidHashMap["bdot_simple_sim:154:41:5"] = {rtwname: "<S2>/UD"};
	this.rtwnameHashMap["<S2>/Y"] = {sid: "bdot_simple_sim:154:41:6"};
	this.sidHashMap["bdot_simple_sim:154:41:6"] = {rtwname: "<S2>/Y"};
	this.rtwnameHashMap["<S3>/b_in_T"] = {sid: "bdot_simple_sim:154:51"};
	this.sidHashMap["bdot_simple_sim:154:51"] = {rtwname: "<S3>/b_in_T"};
	this.rtwnameHashMap["<S3>/Constant"] = {sid: "bdot_simple_sim:154:54"};
	this.sidHashMap["bdot_simple_sim:154:54"] = {rtwname: "<S3>/Constant"};
	this.rtwnameHashMap["<S3>/Constant1"] = {sid: "bdot_simple_sim:154:56"};
	this.sidHashMap["bdot_simple_sim:154:56"] = {rtwname: "<S3>/Constant1"};
	this.rtwnameHashMap["<S3>/Product"] = {sid: "bdot_simple_sim:154:55"};
	this.sidHashMap["bdot_simple_sim:154:55"] = {rtwname: "<S3>/Product"};
	this.rtwnameHashMap["<S3>/Sum"] = {sid: "bdot_simple_sim:154:53"};
	this.sidHashMap["bdot_simple_sim:154:53"] = {rtwname: "<S3>/Sum"};
	this.rtwnameHashMap["<S3>/b_out_T"] = {sid: "bdot_simple_sim:154:52"};
	this.sidHashMap["bdot_simple_sim:154:52"] = {rtwname: "<S3>/b_out_T"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
