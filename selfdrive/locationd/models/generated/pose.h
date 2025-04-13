#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_2920419535240836945);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8864130747844547765);
void pose_H_mod_fun(double *state, double *out_9080618096703126986);
void pose_f_fun(double *state, double dt, double *out_2413180922831470386);
void pose_F_fun(double *state, double dt, double *out_837735418568786151);
void pose_h_4(double *state, double *unused, double *out_5525965845073693878);
void pose_H_4(double *state, double *unused, double *out_4213607591967343895);
void pose_h_10(double *state, double *unused, double *out_8779894212277310676);
void pose_H_10(double *state, double *unused, double *out_7326000222581309245);
void pose_h_13(double *state, double *unused, double *out_7758925961027514582);
void pose_H_13(double *state, double *unused, double *out_1001333766635011094);
void pose_h_14(double *state, double *unused, double *out_205901232063653773);
void pose_H_14(double *state, double *unused, double *out_7296396024262716191);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}