// Copyright 2021 Grant Emsley (@grantemsley)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */


#define LAYOUT( \
    k00,      k02, k03, \
    k10, k11, k12, k13, \
    k20, k21, k22, k23, \
    k30, k31, k32, k33, \
    k40, k41, k42,      \
    k50, k51, k52, k53, \
    k60,      k62       \
) { \
    { k00, KC_NO, k02, k03   }, \
    { k10, k11  , k12, k13   }, \
    { k20, k21  , k22, k23   }, \
    { k30, k31  , k32, k33   }, \
    { k40, k41  , k42, KC_NO }, \
    { k50, k51  , k52, k53   }, \
    { k60, KC_NO, k62, KC_NO } \
}
