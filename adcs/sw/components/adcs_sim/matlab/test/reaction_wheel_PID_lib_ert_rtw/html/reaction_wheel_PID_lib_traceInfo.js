function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S2>/Derivative Gain */
	this.urlHashMap["untitled:1:8:4137"] = "reaction_wheel_PID_lib.c:40";
	/* <S2>/Filter */
	this.urlHashMap["untitled:1:8:4139"] = "reaction_wheel_PID_lib.c:39,63&reaction_wheel_PID_lib.h:33";
	/* <S2>/Filter Coefficient */
	this.urlHashMap["untitled:1:8:4140"] = "reaction_wheel_PID_lib.c:38";
	/* <S2>/Integral Gain */
	this.urlHashMap["untitled:1:8:4136"] = "reaction_wheel_PID_lib.c:67";
	/* <S2>/Integrator */
	this.urlHashMap["untitled:1:8:4138"] = "reaction_wheel_PID_lib.c:51,66&reaction_wheel_PID_lib.h:34";
	/* <S2>/Proportional Gain */
	this.urlHashMap["untitled:1:8:4135"] = "reaction_wheel_PID_lib.c:52";
	/* <S2>/Setpoint Weighting
(Derivative) */
	this.urlHashMap["untitled:1:8:4143"] = "reaction_wheel_PID_lib.c:41";
	/* <S2>/Setpoint Weighting
(Proportional) */
	this.urlHashMap["untitled:1:8:4142"] = "reaction_wheel_PID_lib.c:53";
	/* <S2>/Sum */
	this.urlHashMap["untitled:1:8:4134"] = "reaction_wheel_PID_lib.c:56";
	/* <S2>/Sum1 */
	this.urlHashMap["untitled:1:8:4144"] = "reaction_wheel_PID_lib.c:57";
	/* <S2>/Sum2 */
	this.urlHashMap["untitled:1:8:4145"] = "reaction_wheel_PID_lib.c:70";
	/* <S2>/Sum3 */
	this.urlHashMap["untitled:1:8:4146"] = "reaction_wheel_PID_lib.c:44";
	/* <S2>/SumD */
	this.urlHashMap["untitled:1:8:4141"] = "reaction_wheel_PID_lib.c:45";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "reaction_wheel_PID_lib"};
	this.sidHashMap["reaction_wheel_PID_lib"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "untitled:1"};
	this.sidHashMap["untitled:1"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "untitled:1:8"};
	this.sidHashMap["untitled:1:8"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S1>/omega_ref_radps"] = {sid: "untitled:1:4"};
	this.sidHashMap["untitled:1:4"] = {rtwname: "<S1>/omega_ref_radps"};
	this.rtwnameHashMap["<S1>/omega_in_radps"] = {sid: "untitled:1:6"};
	this.sidHashMap["untitled:1:6"] = {rtwname: "<S1>/omega_in_radps"};
	this.rtwnameHashMap["<S1>/pid_controller"] = {sid: "untitled:1:8"};
	this.sidHashMap["untitled:1:8"] = {rtwname: "<S1>/pid_controller"};
	this.rtwnameHashMap["<S1>/omega_PID_out"] = {sid: "untitled:1:5"};
	this.sidHashMap["untitled:1:5"] = {rtwname: "<S1>/omega_PID_out"};
	this.rtwnameHashMap["<S2>/r"] = {sid: "untitled:1:8:1"};
	this.sidHashMap["untitled:1:8:1"] = {rtwname: "<S2>/r"};
	this.rtwnameHashMap["<S2>/y"] = {sid: "untitled:1:8:2"};
	this.sidHashMap["untitled:1:8:2"] = {rtwname: "<S2>/y"};
	this.rtwnameHashMap["<S2>/Derivative Gain"] = {sid: "untitled:1:8:4137"};
	this.sidHashMap["untitled:1:8:4137"] = {rtwname: "<S2>/Derivative Gain"};
	this.rtwnameHashMap["<S2>/Filter"] = {sid: "untitled:1:8:4139"};
	this.sidHashMap["untitled:1:8:4139"] = {rtwname: "<S2>/Filter"};
	this.rtwnameHashMap["<S2>/Filter Coefficient"] = {sid: "untitled:1:8:4140"};
	this.sidHashMap["untitled:1:8:4140"] = {rtwname: "<S2>/Filter Coefficient"};
	this.rtwnameHashMap["<S2>/Integral Gain"] = {sid: "untitled:1:8:4136"};
	this.sidHashMap["untitled:1:8:4136"] = {rtwname: "<S2>/Integral Gain"};
	this.rtwnameHashMap["<S2>/Integrator"] = {sid: "untitled:1:8:4138"};
	this.sidHashMap["untitled:1:8:4138"] = {rtwname: "<S2>/Integrator"};
	this.rtwnameHashMap["<S2>/Proportional Gain"] = {sid: "untitled:1:8:4135"};
	this.sidHashMap["untitled:1:8:4135"] = {rtwname: "<S2>/Proportional Gain"};
	this.rtwnameHashMap["<S2>/Setpoint Weighting (Derivative)"] = {sid: "untitled:1:8:4143"};
	this.sidHashMap["untitled:1:8:4143"] = {rtwname: "<S2>/Setpoint Weighting (Derivative)"};
	this.rtwnameHashMap["<S2>/Setpoint Weighting (Proportional)"] = {sid: "untitled:1:8:4142"};
	this.sidHashMap["untitled:1:8:4142"] = {rtwname: "<S2>/Setpoint Weighting (Proportional)"};
	this.rtwnameHashMap["<S2>/Sum"] = {sid: "untitled:1:8:4134"};
	this.sidHashMap["untitled:1:8:4134"] = {rtwname: "<S2>/Sum"};
	this.rtwnameHashMap["<S2>/Sum1"] = {sid: "untitled:1:8:4144"};
	this.sidHashMap["untitled:1:8:4144"] = {rtwname: "<S2>/Sum1"};
	this.rtwnameHashMap["<S2>/Sum2"] = {sid: "untitled:1:8:4145"};
	this.sidHashMap["untitled:1:8:4145"] = {rtwname: "<S2>/Sum2"};
	this.rtwnameHashMap["<S2>/Sum3"] = {sid: "untitled:1:8:4146"};
	this.sidHashMap["untitled:1:8:4146"] = {rtwname: "<S2>/Sum3"};
	this.rtwnameHashMap["<S2>/SumD"] = {sid: "untitled:1:8:4141"};
	this.sidHashMap["untitled:1:8:4141"] = {rtwname: "<S2>/SumD"};
	this.rtwnameHashMap["<S2>/u"] = {sid: "untitled:1:8:16"};
	this.sidHashMap["untitled:1:8:16"] = {rtwname: "<S2>/u"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
