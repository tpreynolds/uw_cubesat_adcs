function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S1>/Constant */
	this.urlHashMap["adcs_sim_main:42:122:10"] = "mode_selecction_a.c:95";
	/* <S1>/Constant1 */
	this.urlHashMap["adcs_sim_main:42:122:11"] = "mode_selecction_a.c:96";
	/* <S1>/MATLAB Function */
	this.urlHashMap["adcs_sim_main:42:122:9"] = "mode_selecction_a.c:31,94,186";
	/* <S2>:1 */
	this.urlHashMap["adcs_sim_main:42:122:9:1"] = "mode_selecction_a.c:101";
	/* <S2>:1:13 */
	this.urlHashMap["adcs_sim_main:42:122:9:1:13"] = "mode_selecction_a.c:107";
	/* <S2>:1:15 */
	this.urlHashMap["adcs_sim_main:42:122:9:1:15"] = "mode_selecction_a.c:108";
	/* <S2>:1:17 */
	this.urlHashMap["adcs_sim_main:42:122:9:1:17"] = "mode_selecction_a.c:111";
	/* <S2>:1:18 */
	this.urlHashMap["adcs_sim_main:42:122:9:1:18"] = "mode_selecction_a.c:114";
	/* <S2>:1:21 */
	this.urlHashMap["adcs_sim_main:42:122:9:1:21"] = "mode_selecction_a.c:118";
	/* <S2>:1:22 */
	this.urlHashMap["adcs_sim_main:42:122:9:1:22"] = "mode_selecction_a.c:137";
	/* <S2>:1:25 */
	this.urlHashMap["adcs_sim_main:42:122:9:1:25"] = "mode_selecction_a.c:141";
	/* <S2>:1:26 */
	this.urlHashMap["adcs_sim_main:42:122:9:1:26"] = "mode_selecction_a.c:174";
	/* <S2>:1:29 */
	this.urlHashMap["adcs_sim_main:42:122:9:1:29"] = "mode_selecction_a.c:178";
	/* <S2>:1:30 */
	this.urlHashMap["adcs_sim_main:42:122:9:1:30"] = "mode_selecction_a.c:180";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "mode_selecction"};
	this.sidHashMap["mode_selecction"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "adcs_sim_main:42:122"};
	this.sidHashMap["adcs_sim_main:42:122"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "adcs_sim_main:42:122:9"};
	this.sidHashMap["adcs_sim_main:42:122:9"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S1>/MT_powerstate"] = {sid: "adcs_sim_main:42:122:2"};
	this.sidHashMap["adcs_sim_main:42:122:2"] = {rtwname: "<S1>/MT_powerstate"};
	this.rtwnameHashMap["<S1>/RW_powerstate"] = {sid: "adcs_sim_main:42:122:4"};
	this.sidHashMap["adcs_sim_main:42:122:4"] = {rtwname: "<S1>/RW_powerstate"};
	this.rtwnameHashMap["<S1>/RW_RPM"] = {sid: "adcs_sim_main:42:122:7"};
	this.sidHashMap["adcs_sim_main:42:122:7"] = {rtwname: "<S1>/RW_RPM"};
	this.rtwnameHashMap["<S1>/sc_in_sun"] = {sid: "adcs_sim_main:42:122:5"};
	this.sidHashMap["adcs_sim_main:42:122:5"] = {rtwname: "<S1>/sc_in_sun"};
	this.rtwnameHashMap["<S1>/omega_body_radps"] = {sid: "adcs_sim_main:42:122:6"};
	this.sidHashMap["adcs_sim_main:42:122:6"] = {rtwname: "<S1>/omega_body_radps"};
	this.rtwnameHashMap["<S1>/quat_commanded"] = {sid: "adcs_sim_main:42:122:8"};
	this.sidHashMap["adcs_sim_main:42:122:8"] = {rtwname: "<S1>/quat_commanded"};
	this.rtwnameHashMap["<S1>/Constant"] = {sid: "adcs_sim_main:42:122:10"};
	this.sidHashMap["adcs_sim_main:42:122:10"] = {rtwname: "<S1>/Constant"};
	this.rtwnameHashMap["<S1>/Constant1"] = {sid: "adcs_sim_main:42:122:11"};
	this.sidHashMap["adcs_sim_main:42:122:11"] = {rtwname: "<S1>/Constant1"};
	this.rtwnameHashMap["<S1>/MATLAB Function"] = {sid: "adcs_sim_main:42:122:9"};
	this.sidHashMap["adcs_sim_main:42:122:9"] = {rtwname: "<S1>/MATLAB Function"};
	this.rtwnameHashMap["<S1>/sc_mode"] = {sid: "adcs_sim_main:42:122:3"};
	this.sidHashMap["adcs_sim_main:42:122:3"] = {rtwname: "<S1>/sc_mode"};
	this.rtwnameHashMap["<S2>:1"] = {sid: "adcs_sim_main:42:122:9:1"};
	this.sidHashMap["adcs_sim_main:42:122:9:1"] = {rtwname: "<S2>:1"};
	this.rtwnameHashMap["<S2>:1:13"] = {sid: "adcs_sim_main:42:122:9:1:13"};
	this.sidHashMap["adcs_sim_main:42:122:9:1:13"] = {rtwname: "<S2>:1:13"};
	this.rtwnameHashMap["<S2>:1:15"] = {sid: "adcs_sim_main:42:122:9:1:15"};
	this.sidHashMap["adcs_sim_main:42:122:9:1:15"] = {rtwname: "<S2>:1:15"};
	this.rtwnameHashMap["<S2>:1:17"] = {sid: "adcs_sim_main:42:122:9:1:17"};
	this.sidHashMap["adcs_sim_main:42:122:9:1:17"] = {rtwname: "<S2>:1:17"};
	this.rtwnameHashMap["<S2>:1:18"] = {sid: "adcs_sim_main:42:122:9:1:18"};
	this.sidHashMap["adcs_sim_main:42:122:9:1:18"] = {rtwname: "<S2>:1:18"};
	this.rtwnameHashMap["<S2>:1:21"] = {sid: "adcs_sim_main:42:122:9:1:21"};
	this.sidHashMap["adcs_sim_main:42:122:9:1:21"] = {rtwname: "<S2>:1:21"};
	this.rtwnameHashMap["<S2>:1:22"] = {sid: "adcs_sim_main:42:122:9:1:22"};
	this.sidHashMap["adcs_sim_main:42:122:9:1:22"] = {rtwname: "<S2>:1:22"};
	this.rtwnameHashMap["<S2>:1:25"] = {sid: "adcs_sim_main:42:122:9:1:25"};
	this.sidHashMap["adcs_sim_main:42:122:9:1:25"] = {rtwname: "<S2>:1:25"};
	this.rtwnameHashMap["<S2>:1:26"] = {sid: "adcs_sim_main:42:122:9:1:26"};
	this.sidHashMap["adcs_sim_main:42:122:9:1:26"] = {rtwname: "<S2>:1:26"};
	this.rtwnameHashMap["<S2>:1:29"] = {sid: "adcs_sim_main:42:122:9:1:29"};
	this.sidHashMap["adcs_sim_main:42:122:9:1:29"] = {rtwname: "<S2>:1:29"};
	this.rtwnameHashMap["<S2>:1:30"] = {sid: "adcs_sim_main:42:122:9:1:30"};
	this.sidHashMap["adcs_sim_main:42:122:9:1:30"] = {rtwname: "<S2>:1:30"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
