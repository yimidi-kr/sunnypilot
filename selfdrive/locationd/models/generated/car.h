#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_6987676201861307);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4807789933517956751);
void car_H_mod_fun(double *state, double *out_6248460804362489216);
void car_f_fun(double *state, double dt, double *out_6720143844414620984);
void car_F_fun(double *state, double dt, double *out_8863960918731502306);
void car_h_25(double *state, double *unused, double *out_5091950429740318193);
void car_H_25(double *state, double *unused, double *out_431235315473815695);
void car_h_24(double *state, double *unused, double *out_3245688073253467321);
void car_H_24(double *state, double *unused, double *out_1741414283531683871);
void car_h_30(double *state, double *unused, double *out_839112870976605036);
void car_H_30(double *state, double *unused, double *out_4096461014653792503);
void car_h_26(double *state, double *unused, double *out_235796986300127519);
void car_H_26(double *state, double *unused, double *out_3310268003400240529);
void car_h_27(double *state, double *unused, double *out_3271828356940786315);
void car_H_27(double *state, double *unused, double *out_1872866943469849286);
void car_h_29(double *state, double *unused, double *out_1765292449832092615);
void car_H_29(double *state, double *unused, double *out_3586229670339400319);
void car_h_28(double *state, double *unused, double *out_4751756461515133275);
void car_H_28(double *state, double *unused, double *out_1622599398774074068);
void car_h_31(double *state, double *unused, double *out_5591528387148560982);
void car_H_31(double *state, double *unused, double *out_461881277350776123);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}