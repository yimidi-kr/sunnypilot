"""
Copyright (c) 2021-, rav4kumar, Haibin Wen, sunnypilot, and a number of other contributors.

This file is part of sunnypilot and is licensed under the MIT License.
See the LICENSE.md file in the root directory for more details.
"""

# Acceleration profile for maximum allowed acceleration
MAX_ACCEL_ECO     = [2.00, 1.80, 1.58, 1.45, 0.82, .532, .44, .33, .31, .09]
MAX_ACCEL_NORMAL  = [2.00, 1.90, 1.72, 1.65, 1.00, .75,  .61, .50, .38, .2]
MAX_ACCEL_SPORT   = [2.00, 2.00, 1.98, 1.90, 1.30, 1.00, .72, .60, .48, .3]

# Acceleration profile for minimum (braking) acceleration
MIN_ACCEL_ECO     = [-1.0, -1.0, -1.0, -1.0, -1.0]
MIN_ACCEL_NORMAL  = [-1.1, -1.1, -1.1, -1.1, -1.1]
MIN_ACCEL_SPORT   = [-1.4, -1.4, -1.4, -1.4, -1.4]
MIN_ACCEL_STOCK   = [-1.2, -1.2, -1.2, -1.2, -1.2]

# Speed breakpoints for interpolation
MAX_ACCEL_BREAKPOINTS = [0., 1., 6., 8., 11., 16, 20., 25., 30., 55.]
MIN_ACCEL_BREAKPOINTS = [0., 0.3, 1., 27, 40]
