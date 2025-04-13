#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.13.2                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2920419535240836945) {
   out_2920419535240836945[0] = delta_x[0] + nom_x[0];
   out_2920419535240836945[1] = delta_x[1] + nom_x[1];
   out_2920419535240836945[2] = delta_x[2] + nom_x[2];
   out_2920419535240836945[3] = delta_x[3] + nom_x[3];
   out_2920419535240836945[4] = delta_x[4] + nom_x[4];
   out_2920419535240836945[5] = delta_x[5] + nom_x[5];
   out_2920419535240836945[6] = delta_x[6] + nom_x[6];
   out_2920419535240836945[7] = delta_x[7] + nom_x[7];
   out_2920419535240836945[8] = delta_x[8] + nom_x[8];
   out_2920419535240836945[9] = delta_x[9] + nom_x[9];
   out_2920419535240836945[10] = delta_x[10] + nom_x[10];
   out_2920419535240836945[11] = delta_x[11] + nom_x[11];
   out_2920419535240836945[12] = delta_x[12] + nom_x[12];
   out_2920419535240836945[13] = delta_x[13] + nom_x[13];
   out_2920419535240836945[14] = delta_x[14] + nom_x[14];
   out_2920419535240836945[15] = delta_x[15] + nom_x[15];
   out_2920419535240836945[16] = delta_x[16] + nom_x[16];
   out_2920419535240836945[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8864130747844547765) {
   out_8864130747844547765[0] = -nom_x[0] + true_x[0];
   out_8864130747844547765[1] = -nom_x[1] + true_x[1];
   out_8864130747844547765[2] = -nom_x[2] + true_x[2];
   out_8864130747844547765[3] = -nom_x[3] + true_x[3];
   out_8864130747844547765[4] = -nom_x[4] + true_x[4];
   out_8864130747844547765[5] = -nom_x[5] + true_x[5];
   out_8864130747844547765[6] = -nom_x[6] + true_x[6];
   out_8864130747844547765[7] = -nom_x[7] + true_x[7];
   out_8864130747844547765[8] = -nom_x[8] + true_x[8];
   out_8864130747844547765[9] = -nom_x[9] + true_x[9];
   out_8864130747844547765[10] = -nom_x[10] + true_x[10];
   out_8864130747844547765[11] = -nom_x[11] + true_x[11];
   out_8864130747844547765[12] = -nom_x[12] + true_x[12];
   out_8864130747844547765[13] = -nom_x[13] + true_x[13];
   out_8864130747844547765[14] = -nom_x[14] + true_x[14];
   out_8864130747844547765[15] = -nom_x[15] + true_x[15];
   out_8864130747844547765[16] = -nom_x[16] + true_x[16];
   out_8864130747844547765[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_9080618096703126986) {
   out_9080618096703126986[0] = 1.0;
   out_9080618096703126986[1] = 0.0;
   out_9080618096703126986[2] = 0.0;
   out_9080618096703126986[3] = 0.0;
   out_9080618096703126986[4] = 0.0;
   out_9080618096703126986[5] = 0.0;
   out_9080618096703126986[6] = 0.0;
   out_9080618096703126986[7] = 0.0;
   out_9080618096703126986[8] = 0.0;
   out_9080618096703126986[9] = 0.0;
   out_9080618096703126986[10] = 0.0;
   out_9080618096703126986[11] = 0.0;
   out_9080618096703126986[12] = 0.0;
   out_9080618096703126986[13] = 0.0;
   out_9080618096703126986[14] = 0.0;
   out_9080618096703126986[15] = 0.0;
   out_9080618096703126986[16] = 0.0;
   out_9080618096703126986[17] = 0.0;
   out_9080618096703126986[18] = 0.0;
   out_9080618096703126986[19] = 1.0;
   out_9080618096703126986[20] = 0.0;
   out_9080618096703126986[21] = 0.0;
   out_9080618096703126986[22] = 0.0;
   out_9080618096703126986[23] = 0.0;
   out_9080618096703126986[24] = 0.0;
   out_9080618096703126986[25] = 0.0;
   out_9080618096703126986[26] = 0.0;
   out_9080618096703126986[27] = 0.0;
   out_9080618096703126986[28] = 0.0;
   out_9080618096703126986[29] = 0.0;
   out_9080618096703126986[30] = 0.0;
   out_9080618096703126986[31] = 0.0;
   out_9080618096703126986[32] = 0.0;
   out_9080618096703126986[33] = 0.0;
   out_9080618096703126986[34] = 0.0;
   out_9080618096703126986[35] = 0.0;
   out_9080618096703126986[36] = 0.0;
   out_9080618096703126986[37] = 0.0;
   out_9080618096703126986[38] = 1.0;
   out_9080618096703126986[39] = 0.0;
   out_9080618096703126986[40] = 0.0;
   out_9080618096703126986[41] = 0.0;
   out_9080618096703126986[42] = 0.0;
   out_9080618096703126986[43] = 0.0;
   out_9080618096703126986[44] = 0.0;
   out_9080618096703126986[45] = 0.0;
   out_9080618096703126986[46] = 0.0;
   out_9080618096703126986[47] = 0.0;
   out_9080618096703126986[48] = 0.0;
   out_9080618096703126986[49] = 0.0;
   out_9080618096703126986[50] = 0.0;
   out_9080618096703126986[51] = 0.0;
   out_9080618096703126986[52] = 0.0;
   out_9080618096703126986[53] = 0.0;
   out_9080618096703126986[54] = 0.0;
   out_9080618096703126986[55] = 0.0;
   out_9080618096703126986[56] = 0.0;
   out_9080618096703126986[57] = 1.0;
   out_9080618096703126986[58] = 0.0;
   out_9080618096703126986[59] = 0.0;
   out_9080618096703126986[60] = 0.0;
   out_9080618096703126986[61] = 0.0;
   out_9080618096703126986[62] = 0.0;
   out_9080618096703126986[63] = 0.0;
   out_9080618096703126986[64] = 0.0;
   out_9080618096703126986[65] = 0.0;
   out_9080618096703126986[66] = 0.0;
   out_9080618096703126986[67] = 0.0;
   out_9080618096703126986[68] = 0.0;
   out_9080618096703126986[69] = 0.0;
   out_9080618096703126986[70] = 0.0;
   out_9080618096703126986[71] = 0.0;
   out_9080618096703126986[72] = 0.0;
   out_9080618096703126986[73] = 0.0;
   out_9080618096703126986[74] = 0.0;
   out_9080618096703126986[75] = 0.0;
   out_9080618096703126986[76] = 1.0;
   out_9080618096703126986[77] = 0.0;
   out_9080618096703126986[78] = 0.0;
   out_9080618096703126986[79] = 0.0;
   out_9080618096703126986[80] = 0.0;
   out_9080618096703126986[81] = 0.0;
   out_9080618096703126986[82] = 0.0;
   out_9080618096703126986[83] = 0.0;
   out_9080618096703126986[84] = 0.0;
   out_9080618096703126986[85] = 0.0;
   out_9080618096703126986[86] = 0.0;
   out_9080618096703126986[87] = 0.0;
   out_9080618096703126986[88] = 0.0;
   out_9080618096703126986[89] = 0.0;
   out_9080618096703126986[90] = 0.0;
   out_9080618096703126986[91] = 0.0;
   out_9080618096703126986[92] = 0.0;
   out_9080618096703126986[93] = 0.0;
   out_9080618096703126986[94] = 0.0;
   out_9080618096703126986[95] = 1.0;
   out_9080618096703126986[96] = 0.0;
   out_9080618096703126986[97] = 0.0;
   out_9080618096703126986[98] = 0.0;
   out_9080618096703126986[99] = 0.0;
   out_9080618096703126986[100] = 0.0;
   out_9080618096703126986[101] = 0.0;
   out_9080618096703126986[102] = 0.0;
   out_9080618096703126986[103] = 0.0;
   out_9080618096703126986[104] = 0.0;
   out_9080618096703126986[105] = 0.0;
   out_9080618096703126986[106] = 0.0;
   out_9080618096703126986[107] = 0.0;
   out_9080618096703126986[108] = 0.0;
   out_9080618096703126986[109] = 0.0;
   out_9080618096703126986[110] = 0.0;
   out_9080618096703126986[111] = 0.0;
   out_9080618096703126986[112] = 0.0;
   out_9080618096703126986[113] = 0.0;
   out_9080618096703126986[114] = 1.0;
   out_9080618096703126986[115] = 0.0;
   out_9080618096703126986[116] = 0.0;
   out_9080618096703126986[117] = 0.0;
   out_9080618096703126986[118] = 0.0;
   out_9080618096703126986[119] = 0.0;
   out_9080618096703126986[120] = 0.0;
   out_9080618096703126986[121] = 0.0;
   out_9080618096703126986[122] = 0.0;
   out_9080618096703126986[123] = 0.0;
   out_9080618096703126986[124] = 0.0;
   out_9080618096703126986[125] = 0.0;
   out_9080618096703126986[126] = 0.0;
   out_9080618096703126986[127] = 0.0;
   out_9080618096703126986[128] = 0.0;
   out_9080618096703126986[129] = 0.0;
   out_9080618096703126986[130] = 0.0;
   out_9080618096703126986[131] = 0.0;
   out_9080618096703126986[132] = 0.0;
   out_9080618096703126986[133] = 1.0;
   out_9080618096703126986[134] = 0.0;
   out_9080618096703126986[135] = 0.0;
   out_9080618096703126986[136] = 0.0;
   out_9080618096703126986[137] = 0.0;
   out_9080618096703126986[138] = 0.0;
   out_9080618096703126986[139] = 0.0;
   out_9080618096703126986[140] = 0.0;
   out_9080618096703126986[141] = 0.0;
   out_9080618096703126986[142] = 0.0;
   out_9080618096703126986[143] = 0.0;
   out_9080618096703126986[144] = 0.0;
   out_9080618096703126986[145] = 0.0;
   out_9080618096703126986[146] = 0.0;
   out_9080618096703126986[147] = 0.0;
   out_9080618096703126986[148] = 0.0;
   out_9080618096703126986[149] = 0.0;
   out_9080618096703126986[150] = 0.0;
   out_9080618096703126986[151] = 0.0;
   out_9080618096703126986[152] = 1.0;
   out_9080618096703126986[153] = 0.0;
   out_9080618096703126986[154] = 0.0;
   out_9080618096703126986[155] = 0.0;
   out_9080618096703126986[156] = 0.0;
   out_9080618096703126986[157] = 0.0;
   out_9080618096703126986[158] = 0.0;
   out_9080618096703126986[159] = 0.0;
   out_9080618096703126986[160] = 0.0;
   out_9080618096703126986[161] = 0.0;
   out_9080618096703126986[162] = 0.0;
   out_9080618096703126986[163] = 0.0;
   out_9080618096703126986[164] = 0.0;
   out_9080618096703126986[165] = 0.0;
   out_9080618096703126986[166] = 0.0;
   out_9080618096703126986[167] = 0.0;
   out_9080618096703126986[168] = 0.0;
   out_9080618096703126986[169] = 0.0;
   out_9080618096703126986[170] = 0.0;
   out_9080618096703126986[171] = 1.0;
   out_9080618096703126986[172] = 0.0;
   out_9080618096703126986[173] = 0.0;
   out_9080618096703126986[174] = 0.0;
   out_9080618096703126986[175] = 0.0;
   out_9080618096703126986[176] = 0.0;
   out_9080618096703126986[177] = 0.0;
   out_9080618096703126986[178] = 0.0;
   out_9080618096703126986[179] = 0.0;
   out_9080618096703126986[180] = 0.0;
   out_9080618096703126986[181] = 0.0;
   out_9080618096703126986[182] = 0.0;
   out_9080618096703126986[183] = 0.0;
   out_9080618096703126986[184] = 0.0;
   out_9080618096703126986[185] = 0.0;
   out_9080618096703126986[186] = 0.0;
   out_9080618096703126986[187] = 0.0;
   out_9080618096703126986[188] = 0.0;
   out_9080618096703126986[189] = 0.0;
   out_9080618096703126986[190] = 1.0;
   out_9080618096703126986[191] = 0.0;
   out_9080618096703126986[192] = 0.0;
   out_9080618096703126986[193] = 0.0;
   out_9080618096703126986[194] = 0.0;
   out_9080618096703126986[195] = 0.0;
   out_9080618096703126986[196] = 0.0;
   out_9080618096703126986[197] = 0.0;
   out_9080618096703126986[198] = 0.0;
   out_9080618096703126986[199] = 0.0;
   out_9080618096703126986[200] = 0.0;
   out_9080618096703126986[201] = 0.0;
   out_9080618096703126986[202] = 0.0;
   out_9080618096703126986[203] = 0.0;
   out_9080618096703126986[204] = 0.0;
   out_9080618096703126986[205] = 0.0;
   out_9080618096703126986[206] = 0.0;
   out_9080618096703126986[207] = 0.0;
   out_9080618096703126986[208] = 0.0;
   out_9080618096703126986[209] = 1.0;
   out_9080618096703126986[210] = 0.0;
   out_9080618096703126986[211] = 0.0;
   out_9080618096703126986[212] = 0.0;
   out_9080618096703126986[213] = 0.0;
   out_9080618096703126986[214] = 0.0;
   out_9080618096703126986[215] = 0.0;
   out_9080618096703126986[216] = 0.0;
   out_9080618096703126986[217] = 0.0;
   out_9080618096703126986[218] = 0.0;
   out_9080618096703126986[219] = 0.0;
   out_9080618096703126986[220] = 0.0;
   out_9080618096703126986[221] = 0.0;
   out_9080618096703126986[222] = 0.0;
   out_9080618096703126986[223] = 0.0;
   out_9080618096703126986[224] = 0.0;
   out_9080618096703126986[225] = 0.0;
   out_9080618096703126986[226] = 0.0;
   out_9080618096703126986[227] = 0.0;
   out_9080618096703126986[228] = 1.0;
   out_9080618096703126986[229] = 0.0;
   out_9080618096703126986[230] = 0.0;
   out_9080618096703126986[231] = 0.0;
   out_9080618096703126986[232] = 0.0;
   out_9080618096703126986[233] = 0.0;
   out_9080618096703126986[234] = 0.0;
   out_9080618096703126986[235] = 0.0;
   out_9080618096703126986[236] = 0.0;
   out_9080618096703126986[237] = 0.0;
   out_9080618096703126986[238] = 0.0;
   out_9080618096703126986[239] = 0.0;
   out_9080618096703126986[240] = 0.0;
   out_9080618096703126986[241] = 0.0;
   out_9080618096703126986[242] = 0.0;
   out_9080618096703126986[243] = 0.0;
   out_9080618096703126986[244] = 0.0;
   out_9080618096703126986[245] = 0.0;
   out_9080618096703126986[246] = 0.0;
   out_9080618096703126986[247] = 1.0;
   out_9080618096703126986[248] = 0.0;
   out_9080618096703126986[249] = 0.0;
   out_9080618096703126986[250] = 0.0;
   out_9080618096703126986[251] = 0.0;
   out_9080618096703126986[252] = 0.0;
   out_9080618096703126986[253] = 0.0;
   out_9080618096703126986[254] = 0.0;
   out_9080618096703126986[255] = 0.0;
   out_9080618096703126986[256] = 0.0;
   out_9080618096703126986[257] = 0.0;
   out_9080618096703126986[258] = 0.0;
   out_9080618096703126986[259] = 0.0;
   out_9080618096703126986[260] = 0.0;
   out_9080618096703126986[261] = 0.0;
   out_9080618096703126986[262] = 0.0;
   out_9080618096703126986[263] = 0.0;
   out_9080618096703126986[264] = 0.0;
   out_9080618096703126986[265] = 0.0;
   out_9080618096703126986[266] = 1.0;
   out_9080618096703126986[267] = 0.0;
   out_9080618096703126986[268] = 0.0;
   out_9080618096703126986[269] = 0.0;
   out_9080618096703126986[270] = 0.0;
   out_9080618096703126986[271] = 0.0;
   out_9080618096703126986[272] = 0.0;
   out_9080618096703126986[273] = 0.0;
   out_9080618096703126986[274] = 0.0;
   out_9080618096703126986[275] = 0.0;
   out_9080618096703126986[276] = 0.0;
   out_9080618096703126986[277] = 0.0;
   out_9080618096703126986[278] = 0.0;
   out_9080618096703126986[279] = 0.0;
   out_9080618096703126986[280] = 0.0;
   out_9080618096703126986[281] = 0.0;
   out_9080618096703126986[282] = 0.0;
   out_9080618096703126986[283] = 0.0;
   out_9080618096703126986[284] = 0.0;
   out_9080618096703126986[285] = 1.0;
   out_9080618096703126986[286] = 0.0;
   out_9080618096703126986[287] = 0.0;
   out_9080618096703126986[288] = 0.0;
   out_9080618096703126986[289] = 0.0;
   out_9080618096703126986[290] = 0.0;
   out_9080618096703126986[291] = 0.0;
   out_9080618096703126986[292] = 0.0;
   out_9080618096703126986[293] = 0.0;
   out_9080618096703126986[294] = 0.0;
   out_9080618096703126986[295] = 0.0;
   out_9080618096703126986[296] = 0.0;
   out_9080618096703126986[297] = 0.0;
   out_9080618096703126986[298] = 0.0;
   out_9080618096703126986[299] = 0.0;
   out_9080618096703126986[300] = 0.0;
   out_9080618096703126986[301] = 0.0;
   out_9080618096703126986[302] = 0.0;
   out_9080618096703126986[303] = 0.0;
   out_9080618096703126986[304] = 1.0;
   out_9080618096703126986[305] = 0.0;
   out_9080618096703126986[306] = 0.0;
   out_9080618096703126986[307] = 0.0;
   out_9080618096703126986[308] = 0.0;
   out_9080618096703126986[309] = 0.0;
   out_9080618096703126986[310] = 0.0;
   out_9080618096703126986[311] = 0.0;
   out_9080618096703126986[312] = 0.0;
   out_9080618096703126986[313] = 0.0;
   out_9080618096703126986[314] = 0.0;
   out_9080618096703126986[315] = 0.0;
   out_9080618096703126986[316] = 0.0;
   out_9080618096703126986[317] = 0.0;
   out_9080618096703126986[318] = 0.0;
   out_9080618096703126986[319] = 0.0;
   out_9080618096703126986[320] = 0.0;
   out_9080618096703126986[321] = 0.0;
   out_9080618096703126986[322] = 0.0;
   out_9080618096703126986[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2413180922831470386) {
   out_2413180922831470386[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2413180922831470386[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2413180922831470386[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2413180922831470386[3] = dt*state[12] + state[3];
   out_2413180922831470386[4] = dt*state[13] + state[4];
   out_2413180922831470386[5] = dt*state[14] + state[5];
   out_2413180922831470386[6] = state[6];
   out_2413180922831470386[7] = state[7];
   out_2413180922831470386[8] = state[8];
   out_2413180922831470386[9] = state[9];
   out_2413180922831470386[10] = state[10];
   out_2413180922831470386[11] = state[11];
   out_2413180922831470386[12] = state[12];
   out_2413180922831470386[13] = state[13];
   out_2413180922831470386[14] = state[14];
   out_2413180922831470386[15] = state[15];
   out_2413180922831470386[16] = state[16];
   out_2413180922831470386[17] = state[17];
}
void F_fun(double *state, double dt, double *out_837735418568786151) {
   out_837735418568786151[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_837735418568786151[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_837735418568786151[2] = 0;
   out_837735418568786151[3] = 0;
   out_837735418568786151[4] = 0;
   out_837735418568786151[5] = 0;
   out_837735418568786151[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_837735418568786151[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_837735418568786151[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_837735418568786151[9] = 0;
   out_837735418568786151[10] = 0;
   out_837735418568786151[11] = 0;
   out_837735418568786151[12] = 0;
   out_837735418568786151[13] = 0;
   out_837735418568786151[14] = 0;
   out_837735418568786151[15] = 0;
   out_837735418568786151[16] = 0;
   out_837735418568786151[17] = 0;
   out_837735418568786151[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_837735418568786151[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_837735418568786151[20] = 0;
   out_837735418568786151[21] = 0;
   out_837735418568786151[22] = 0;
   out_837735418568786151[23] = 0;
   out_837735418568786151[24] = 0;
   out_837735418568786151[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_837735418568786151[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_837735418568786151[27] = 0;
   out_837735418568786151[28] = 0;
   out_837735418568786151[29] = 0;
   out_837735418568786151[30] = 0;
   out_837735418568786151[31] = 0;
   out_837735418568786151[32] = 0;
   out_837735418568786151[33] = 0;
   out_837735418568786151[34] = 0;
   out_837735418568786151[35] = 0;
   out_837735418568786151[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_837735418568786151[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_837735418568786151[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_837735418568786151[39] = 0;
   out_837735418568786151[40] = 0;
   out_837735418568786151[41] = 0;
   out_837735418568786151[42] = 0;
   out_837735418568786151[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_837735418568786151[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_837735418568786151[45] = 0;
   out_837735418568786151[46] = 0;
   out_837735418568786151[47] = 0;
   out_837735418568786151[48] = 0;
   out_837735418568786151[49] = 0;
   out_837735418568786151[50] = 0;
   out_837735418568786151[51] = 0;
   out_837735418568786151[52] = 0;
   out_837735418568786151[53] = 0;
   out_837735418568786151[54] = 0;
   out_837735418568786151[55] = 0;
   out_837735418568786151[56] = 0;
   out_837735418568786151[57] = 1;
   out_837735418568786151[58] = 0;
   out_837735418568786151[59] = 0;
   out_837735418568786151[60] = 0;
   out_837735418568786151[61] = 0;
   out_837735418568786151[62] = 0;
   out_837735418568786151[63] = 0;
   out_837735418568786151[64] = 0;
   out_837735418568786151[65] = 0;
   out_837735418568786151[66] = dt;
   out_837735418568786151[67] = 0;
   out_837735418568786151[68] = 0;
   out_837735418568786151[69] = 0;
   out_837735418568786151[70] = 0;
   out_837735418568786151[71] = 0;
   out_837735418568786151[72] = 0;
   out_837735418568786151[73] = 0;
   out_837735418568786151[74] = 0;
   out_837735418568786151[75] = 0;
   out_837735418568786151[76] = 1;
   out_837735418568786151[77] = 0;
   out_837735418568786151[78] = 0;
   out_837735418568786151[79] = 0;
   out_837735418568786151[80] = 0;
   out_837735418568786151[81] = 0;
   out_837735418568786151[82] = 0;
   out_837735418568786151[83] = 0;
   out_837735418568786151[84] = 0;
   out_837735418568786151[85] = dt;
   out_837735418568786151[86] = 0;
   out_837735418568786151[87] = 0;
   out_837735418568786151[88] = 0;
   out_837735418568786151[89] = 0;
   out_837735418568786151[90] = 0;
   out_837735418568786151[91] = 0;
   out_837735418568786151[92] = 0;
   out_837735418568786151[93] = 0;
   out_837735418568786151[94] = 0;
   out_837735418568786151[95] = 1;
   out_837735418568786151[96] = 0;
   out_837735418568786151[97] = 0;
   out_837735418568786151[98] = 0;
   out_837735418568786151[99] = 0;
   out_837735418568786151[100] = 0;
   out_837735418568786151[101] = 0;
   out_837735418568786151[102] = 0;
   out_837735418568786151[103] = 0;
   out_837735418568786151[104] = dt;
   out_837735418568786151[105] = 0;
   out_837735418568786151[106] = 0;
   out_837735418568786151[107] = 0;
   out_837735418568786151[108] = 0;
   out_837735418568786151[109] = 0;
   out_837735418568786151[110] = 0;
   out_837735418568786151[111] = 0;
   out_837735418568786151[112] = 0;
   out_837735418568786151[113] = 0;
   out_837735418568786151[114] = 1;
   out_837735418568786151[115] = 0;
   out_837735418568786151[116] = 0;
   out_837735418568786151[117] = 0;
   out_837735418568786151[118] = 0;
   out_837735418568786151[119] = 0;
   out_837735418568786151[120] = 0;
   out_837735418568786151[121] = 0;
   out_837735418568786151[122] = 0;
   out_837735418568786151[123] = 0;
   out_837735418568786151[124] = 0;
   out_837735418568786151[125] = 0;
   out_837735418568786151[126] = 0;
   out_837735418568786151[127] = 0;
   out_837735418568786151[128] = 0;
   out_837735418568786151[129] = 0;
   out_837735418568786151[130] = 0;
   out_837735418568786151[131] = 0;
   out_837735418568786151[132] = 0;
   out_837735418568786151[133] = 1;
   out_837735418568786151[134] = 0;
   out_837735418568786151[135] = 0;
   out_837735418568786151[136] = 0;
   out_837735418568786151[137] = 0;
   out_837735418568786151[138] = 0;
   out_837735418568786151[139] = 0;
   out_837735418568786151[140] = 0;
   out_837735418568786151[141] = 0;
   out_837735418568786151[142] = 0;
   out_837735418568786151[143] = 0;
   out_837735418568786151[144] = 0;
   out_837735418568786151[145] = 0;
   out_837735418568786151[146] = 0;
   out_837735418568786151[147] = 0;
   out_837735418568786151[148] = 0;
   out_837735418568786151[149] = 0;
   out_837735418568786151[150] = 0;
   out_837735418568786151[151] = 0;
   out_837735418568786151[152] = 1;
   out_837735418568786151[153] = 0;
   out_837735418568786151[154] = 0;
   out_837735418568786151[155] = 0;
   out_837735418568786151[156] = 0;
   out_837735418568786151[157] = 0;
   out_837735418568786151[158] = 0;
   out_837735418568786151[159] = 0;
   out_837735418568786151[160] = 0;
   out_837735418568786151[161] = 0;
   out_837735418568786151[162] = 0;
   out_837735418568786151[163] = 0;
   out_837735418568786151[164] = 0;
   out_837735418568786151[165] = 0;
   out_837735418568786151[166] = 0;
   out_837735418568786151[167] = 0;
   out_837735418568786151[168] = 0;
   out_837735418568786151[169] = 0;
   out_837735418568786151[170] = 0;
   out_837735418568786151[171] = 1;
   out_837735418568786151[172] = 0;
   out_837735418568786151[173] = 0;
   out_837735418568786151[174] = 0;
   out_837735418568786151[175] = 0;
   out_837735418568786151[176] = 0;
   out_837735418568786151[177] = 0;
   out_837735418568786151[178] = 0;
   out_837735418568786151[179] = 0;
   out_837735418568786151[180] = 0;
   out_837735418568786151[181] = 0;
   out_837735418568786151[182] = 0;
   out_837735418568786151[183] = 0;
   out_837735418568786151[184] = 0;
   out_837735418568786151[185] = 0;
   out_837735418568786151[186] = 0;
   out_837735418568786151[187] = 0;
   out_837735418568786151[188] = 0;
   out_837735418568786151[189] = 0;
   out_837735418568786151[190] = 1;
   out_837735418568786151[191] = 0;
   out_837735418568786151[192] = 0;
   out_837735418568786151[193] = 0;
   out_837735418568786151[194] = 0;
   out_837735418568786151[195] = 0;
   out_837735418568786151[196] = 0;
   out_837735418568786151[197] = 0;
   out_837735418568786151[198] = 0;
   out_837735418568786151[199] = 0;
   out_837735418568786151[200] = 0;
   out_837735418568786151[201] = 0;
   out_837735418568786151[202] = 0;
   out_837735418568786151[203] = 0;
   out_837735418568786151[204] = 0;
   out_837735418568786151[205] = 0;
   out_837735418568786151[206] = 0;
   out_837735418568786151[207] = 0;
   out_837735418568786151[208] = 0;
   out_837735418568786151[209] = 1;
   out_837735418568786151[210] = 0;
   out_837735418568786151[211] = 0;
   out_837735418568786151[212] = 0;
   out_837735418568786151[213] = 0;
   out_837735418568786151[214] = 0;
   out_837735418568786151[215] = 0;
   out_837735418568786151[216] = 0;
   out_837735418568786151[217] = 0;
   out_837735418568786151[218] = 0;
   out_837735418568786151[219] = 0;
   out_837735418568786151[220] = 0;
   out_837735418568786151[221] = 0;
   out_837735418568786151[222] = 0;
   out_837735418568786151[223] = 0;
   out_837735418568786151[224] = 0;
   out_837735418568786151[225] = 0;
   out_837735418568786151[226] = 0;
   out_837735418568786151[227] = 0;
   out_837735418568786151[228] = 1;
   out_837735418568786151[229] = 0;
   out_837735418568786151[230] = 0;
   out_837735418568786151[231] = 0;
   out_837735418568786151[232] = 0;
   out_837735418568786151[233] = 0;
   out_837735418568786151[234] = 0;
   out_837735418568786151[235] = 0;
   out_837735418568786151[236] = 0;
   out_837735418568786151[237] = 0;
   out_837735418568786151[238] = 0;
   out_837735418568786151[239] = 0;
   out_837735418568786151[240] = 0;
   out_837735418568786151[241] = 0;
   out_837735418568786151[242] = 0;
   out_837735418568786151[243] = 0;
   out_837735418568786151[244] = 0;
   out_837735418568786151[245] = 0;
   out_837735418568786151[246] = 0;
   out_837735418568786151[247] = 1;
   out_837735418568786151[248] = 0;
   out_837735418568786151[249] = 0;
   out_837735418568786151[250] = 0;
   out_837735418568786151[251] = 0;
   out_837735418568786151[252] = 0;
   out_837735418568786151[253] = 0;
   out_837735418568786151[254] = 0;
   out_837735418568786151[255] = 0;
   out_837735418568786151[256] = 0;
   out_837735418568786151[257] = 0;
   out_837735418568786151[258] = 0;
   out_837735418568786151[259] = 0;
   out_837735418568786151[260] = 0;
   out_837735418568786151[261] = 0;
   out_837735418568786151[262] = 0;
   out_837735418568786151[263] = 0;
   out_837735418568786151[264] = 0;
   out_837735418568786151[265] = 0;
   out_837735418568786151[266] = 1;
   out_837735418568786151[267] = 0;
   out_837735418568786151[268] = 0;
   out_837735418568786151[269] = 0;
   out_837735418568786151[270] = 0;
   out_837735418568786151[271] = 0;
   out_837735418568786151[272] = 0;
   out_837735418568786151[273] = 0;
   out_837735418568786151[274] = 0;
   out_837735418568786151[275] = 0;
   out_837735418568786151[276] = 0;
   out_837735418568786151[277] = 0;
   out_837735418568786151[278] = 0;
   out_837735418568786151[279] = 0;
   out_837735418568786151[280] = 0;
   out_837735418568786151[281] = 0;
   out_837735418568786151[282] = 0;
   out_837735418568786151[283] = 0;
   out_837735418568786151[284] = 0;
   out_837735418568786151[285] = 1;
   out_837735418568786151[286] = 0;
   out_837735418568786151[287] = 0;
   out_837735418568786151[288] = 0;
   out_837735418568786151[289] = 0;
   out_837735418568786151[290] = 0;
   out_837735418568786151[291] = 0;
   out_837735418568786151[292] = 0;
   out_837735418568786151[293] = 0;
   out_837735418568786151[294] = 0;
   out_837735418568786151[295] = 0;
   out_837735418568786151[296] = 0;
   out_837735418568786151[297] = 0;
   out_837735418568786151[298] = 0;
   out_837735418568786151[299] = 0;
   out_837735418568786151[300] = 0;
   out_837735418568786151[301] = 0;
   out_837735418568786151[302] = 0;
   out_837735418568786151[303] = 0;
   out_837735418568786151[304] = 1;
   out_837735418568786151[305] = 0;
   out_837735418568786151[306] = 0;
   out_837735418568786151[307] = 0;
   out_837735418568786151[308] = 0;
   out_837735418568786151[309] = 0;
   out_837735418568786151[310] = 0;
   out_837735418568786151[311] = 0;
   out_837735418568786151[312] = 0;
   out_837735418568786151[313] = 0;
   out_837735418568786151[314] = 0;
   out_837735418568786151[315] = 0;
   out_837735418568786151[316] = 0;
   out_837735418568786151[317] = 0;
   out_837735418568786151[318] = 0;
   out_837735418568786151[319] = 0;
   out_837735418568786151[320] = 0;
   out_837735418568786151[321] = 0;
   out_837735418568786151[322] = 0;
   out_837735418568786151[323] = 1;
}
void h_4(double *state, double *unused, double *out_5525965845073693878) {
   out_5525965845073693878[0] = state[6] + state[9];
   out_5525965845073693878[1] = state[7] + state[10];
   out_5525965845073693878[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4213607591967343895) {
   out_4213607591967343895[0] = 0;
   out_4213607591967343895[1] = 0;
   out_4213607591967343895[2] = 0;
   out_4213607591967343895[3] = 0;
   out_4213607591967343895[4] = 0;
   out_4213607591967343895[5] = 0;
   out_4213607591967343895[6] = 1;
   out_4213607591967343895[7] = 0;
   out_4213607591967343895[8] = 0;
   out_4213607591967343895[9] = 1;
   out_4213607591967343895[10] = 0;
   out_4213607591967343895[11] = 0;
   out_4213607591967343895[12] = 0;
   out_4213607591967343895[13] = 0;
   out_4213607591967343895[14] = 0;
   out_4213607591967343895[15] = 0;
   out_4213607591967343895[16] = 0;
   out_4213607591967343895[17] = 0;
   out_4213607591967343895[18] = 0;
   out_4213607591967343895[19] = 0;
   out_4213607591967343895[20] = 0;
   out_4213607591967343895[21] = 0;
   out_4213607591967343895[22] = 0;
   out_4213607591967343895[23] = 0;
   out_4213607591967343895[24] = 0;
   out_4213607591967343895[25] = 1;
   out_4213607591967343895[26] = 0;
   out_4213607591967343895[27] = 0;
   out_4213607591967343895[28] = 1;
   out_4213607591967343895[29] = 0;
   out_4213607591967343895[30] = 0;
   out_4213607591967343895[31] = 0;
   out_4213607591967343895[32] = 0;
   out_4213607591967343895[33] = 0;
   out_4213607591967343895[34] = 0;
   out_4213607591967343895[35] = 0;
   out_4213607591967343895[36] = 0;
   out_4213607591967343895[37] = 0;
   out_4213607591967343895[38] = 0;
   out_4213607591967343895[39] = 0;
   out_4213607591967343895[40] = 0;
   out_4213607591967343895[41] = 0;
   out_4213607591967343895[42] = 0;
   out_4213607591967343895[43] = 0;
   out_4213607591967343895[44] = 1;
   out_4213607591967343895[45] = 0;
   out_4213607591967343895[46] = 0;
   out_4213607591967343895[47] = 1;
   out_4213607591967343895[48] = 0;
   out_4213607591967343895[49] = 0;
   out_4213607591967343895[50] = 0;
   out_4213607591967343895[51] = 0;
   out_4213607591967343895[52] = 0;
   out_4213607591967343895[53] = 0;
}
void h_10(double *state, double *unused, double *out_8779894212277310676) {
   out_8779894212277310676[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_8779894212277310676[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_8779894212277310676[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_7326000222581309245) {
   out_7326000222581309245[0] = 0;
   out_7326000222581309245[1] = 9.8100000000000005*cos(state[1]);
   out_7326000222581309245[2] = 0;
   out_7326000222581309245[3] = 0;
   out_7326000222581309245[4] = -state[8];
   out_7326000222581309245[5] = state[7];
   out_7326000222581309245[6] = 0;
   out_7326000222581309245[7] = state[5];
   out_7326000222581309245[8] = -state[4];
   out_7326000222581309245[9] = 0;
   out_7326000222581309245[10] = 0;
   out_7326000222581309245[11] = 0;
   out_7326000222581309245[12] = 1;
   out_7326000222581309245[13] = 0;
   out_7326000222581309245[14] = 0;
   out_7326000222581309245[15] = 1;
   out_7326000222581309245[16] = 0;
   out_7326000222581309245[17] = 0;
   out_7326000222581309245[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_7326000222581309245[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_7326000222581309245[20] = 0;
   out_7326000222581309245[21] = state[8];
   out_7326000222581309245[22] = 0;
   out_7326000222581309245[23] = -state[6];
   out_7326000222581309245[24] = -state[5];
   out_7326000222581309245[25] = 0;
   out_7326000222581309245[26] = state[3];
   out_7326000222581309245[27] = 0;
   out_7326000222581309245[28] = 0;
   out_7326000222581309245[29] = 0;
   out_7326000222581309245[30] = 0;
   out_7326000222581309245[31] = 1;
   out_7326000222581309245[32] = 0;
   out_7326000222581309245[33] = 0;
   out_7326000222581309245[34] = 1;
   out_7326000222581309245[35] = 0;
   out_7326000222581309245[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_7326000222581309245[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_7326000222581309245[38] = 0;
   out_7326000222581309245[39] = -state[7];
   out_7326000222581309245[40] = state[6];
   out_7326000222581309245[41] = 0;
   out_7326000222581309245[42] = state[4];
   out_7326000222581309245[43] = -state[3];
   out_7326000222581309245[44] = 0;
   out_7326000222581309245[45] = 0;
   out_7326000222581309245[46] = 0;
   out_7326000222581309245[47] = 0;
   out_7326000222581309245[48] = 0;
   out_7326000222581309245[49] = 0;
   out_7326000222581309245[50] = 1;
   out_7326000222581309245[51] = 0;
   out_7326000222581309245[52] = 0;
   out_7326000222581309245[53] = 1;
}
void h_13(double *state, double *unused, double *out_7758925961027514582) {
   out_7758925961027514582[0] = state[3];
   out_7758925961027514582[1] = state[4];
   out_7758925961027514582[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1001333766635011094) {
   out_1001333766635011094[0] = 0;
   out_1001333766635011094[1] = 0;
   out_1001333766635011094[2] = 0;
   out_1001333766635011094[3] = 1;
   out_1001333766635011094[4] = 0;
   out_1001333766635011094[5] = 0;
   out_1001333766635011094[6] = 0;
   out_1001333766635011094[7] = 0;
   out_1001333766635011094[8] = 0;
   out_1001333766635011094[9] = 0;
   out_1001333766635011094[10] = 0;
   out_1001333766635011094[11] = 0;
   out_1001333766635011094[12] = 0;
   out_1001333766635011094[13] = 0;
   out_1001333766635011094[14] = 0;
   out_1001333766635011094[15] = 0;
   out_1001333766635011094[16] = 0;
   out_1001333766635011094[17] = 0;
   out_1001333766635011094[18] = 0;
   out_1001333766635011094[19] = 0;
   out_1001333766635011094[20] = 0;
   out_1001333766635011094[21] = 0;
   out_1001333766635011094[22] = 1;
   out_1001333766635011094[23] = 0;
   out_1001333766635011094[24] = 0;
   out_1001333766635011094[25] = 0;
   out_1001333766635011094[26] = 0;
   out_1001333766635011094[27] = 0;
   out_1001333766635011094[28] = 0;
   out_1001333766635011094[29] = 0;
   out_1001333766635011094[30] = 0;
   out_1001333766635011094[31] = 0;
   out_1001333766635011094[32] = 0;
   out_1001333766635011094[33] = 0;
   out_1001333766635011094[34] = 0;
   out_1001333766635011094[35] = 0;
   out_1001333766635011094[36] = 0;
   out_1001333766635011094[37] = 0;
   out_1001333766635011094[38] = 0;
   out_1001333766635011094[39] = 0;
   out_1001333766635011094[40] = 0;
   out_1001333766635011094[41] = 1;
   out_1001333766635011094[42] = 0;
   out_1001333766635011094[43] = 0;
   out_1001333766635011094[44] = 0;
   out_1001333766635011094[45] = 0;
   out_1001333766635011094[46] = 0;
   out_1001333766635011094[47] = 0;
   out_1001333766635011094[48] = 0;
   out_1001333766635011094[49] = 0;
   out_1001333766635011094[50] = 0;
   out_1001333766635011094[51] = 0;
   out_1001333766635011094[52] = 0;
   out_1001333766635011094[53] = 0;
}
void h_14(double *state, double *unused, double *out_205901232063653773) {
   out_205901232063653773[0] = state[6];
   out_205901232063653773[1] = state[7];
   out_205901232063653773[2] = state[8];
}
void H_14(double *state, double *unused, double *out_7296396024262716191) {
   out_7296396024262716191[0] = 0;
   out_7296396024262716191[1] = 0;
   out_7296396024262716191[2] = 0;
   out_7296396024262716191[3] = 0;
   out_7296396024262716191[4] = 0;
   out_7296396024262716191[5] = 0;
   out_7296396024262716191[6] = 1;
   out_7296396024262716191[7] = 0;
   out_7296396024262716191[8] = 0;
   out_7296396024262716191[9] = 0;
   out_7296396024262716191[10] = 0;
   out_7296396024262716191[11] = 0;
   out_7296396024262716191[12] = 0;
   out_7296396024262716191[13] = 0;
   out_7296396024262716191[14] = 0;
   out_7296396024262716191[15] = 0;
   out_7296396024262716191[16] = 0;
   out_7296396024262716191[17] = 0;
   out_7296396024262716191[18] = 0;
   out_7296396024262716191[19] = 0;
   out_7296396024262716191[20] = 0;
   out_7296396024262716191[21] = 0;
   out_7296396024262716191[22] = 0;
   out_7296396024262716191[23] = 0;
   out_7296396024262716191[24] = 0;
   out_7296396024262716191[25] = 1;
   out_7296396024262716191[26] = 0;
   out_7296396024262716191[27] = 0;
   out_7296396024262716191[28] = 0;
   out_7296396024262716191[29] = 0;
   out_7296396024262716191[30] = 0;
   out_7296396024262716191[31] = 0;
   out_7296396024262716191[32] = 0;
   out_7296396024262716191[33] = 0;
   out_7296396024262716191[34] = 0;
   out_7296396024262716191[35] = 0;
   out_7296396024262716191[36] = 0;
   out_7296396024262716191[37] = 0;
   out_7296396024262716191[38] = 0;
   out_7296396024262716191[39] = 0;
   out_7296396024262716191[40] = 0;
   out_7296396024262716191[41] = 0;
   out_7296396024262716191[42] = 0;
   out_7296396024262716191[43] = 0;
   out_7296396024262716191[44] = 1;
   out_7296396024262716191[45] = 0;
   out_7296396024262716191[46] = 0;
   out_7296396024262716191[47] = 0;
   out_7296396024262716191[48] = 0;
   out_7296396024262716191[49] = 0;
   out_7296396024262716191[50] = 0;
   out_7296396024262716191[51] = 0;
   out_7296396024262716191[52] = 0;
   out_7296396024262716191[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_2920419535240836945) {
  err_fun(nom_x, delta_x, out_2920419535240836945);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8864130747844547765) {
  inv_err_fun(nom_x, true_x, out_8864130747844547765);
}
void pose_H_mod_fun(double *state, double *out_9080618096703126986) {
  H_mod_fun(state, out_9080618096703126986);
}
void pose_f_fun(double *state, double dt, double *out_2413180922831470386) {
  f_fun(state,  dt, out_2413180922831470386);
}
void pose_F_fun(double *state, double dt, double *out_837735418568786151) {
  F_fun(state,  dt, out_837735418568786151);
}
void pose_h_4(double *state, double *unused, double *out_5525965845073693878) {
  h_4(state, unused, out_5525965845073693878);
}
void pose_H_4(double *state, double *unused, double *out_4213607591967343895) {
  H_4(state, unused, out_4213607591967343895);
}
void pose_h_10(double *state, double *unused, double *out_8779894212277310676) {
  h_10(state, unused, out_8779894212277310676);
}
void pose_H_10(double *state, double *unused, double *out_7326000222581309245) {
  H_10(state, unused, out_7326000222581309245);
}
void pose_h_13(double *state, double *unused, double *out_7758925961027514582) {
  h_13(state, unused, out_7758925961027514582);
}
void pose_H_13(double *state, double *unused, double *out_1001333766635011094) {
  H_13(state, unused, out_1001333766635011094);
}
void pose_h_14(double *state, double *unused, double *out_205901232063653773) {
  h_14(state, unused, out_205901232063653773);
}
void pose_H_14(double *state, double *unused, double *out_7296396024262716191) {
  H_14(state, unused, out_7296396024262716191);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
