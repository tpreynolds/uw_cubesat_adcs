/*
DQPDG 	Dual Quaternion Powered Descent Guidance

T. P. Reynolds -- RAIN Lab
*/

#include "OAC.h"

int main() {

	OAC_T OAC;
	input_T input;

	// initial attitude
	input.q0[0] = 0.866025403784439;
    input.q0[1] = 0.5;
    input.q0[2] = 0.0;
    input.q0[3] = 0.0;
    // initial angular velocity
    input.w0[0] = 0.0;
    input.w0[0] = 0.0;
    input.w0[0] = 0.0;
    // final attitude
    input.qf[0] = 1.0;
    input.qf[1] = 0.0;
    input.qf[2] = 0.0;
    input.qf[3] = 0.0;
    // final angular velocity
    input.wf[0] = 0.0;
    input.wf[1] = 0.0;
    input.wf[2] = 0.0;
    // exclusion constraint matrix
    input.ME[0][0] = 1.14412280563537;
    input.ME[0][1] = 0.0;
    input.ME[0][2] = -0.437016024448821;
    input.ME[0][3] = 0.0;
    input.ME[1][0] = 0.0;
    input.ME[1][1] = 1.14412280563537;
    input.ME[1][2] = 0.0;
    input.ME[1][3] = 0.437016024448821;
    input.ME[2][0] = -0.437016024448821;
    input.ME[2][1] = 0.0;
    input.ME[2][2] = 1.14412280563537;
    input.ME[2][3] = 0.0;
    input.ME[3][0] = 0.0;
    input.ME[3][1] = 0.437016024448821;
    input.ME[3][2] = 0.0;
    input.ME[3][3] = 1.14412280563537;


	// fill up inputs
	int flag;
	flag = init_OAC(&OAC,&input);
    foh(&OAC);
	printOACinfo(OAC,flag);

	return 0;
}