// Copyright 2021 Grant Emsley (@grantemsley)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "print.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_F14,                             KC_F13,              KC_F15,
        KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK,
        KC_NUMLOCK,          KC_KP_SLASH,   KC_KP_ASTERISK,      KC_KP_MINUS,
        KC_KP_7,             KC_KP_8,       KC_KP_9,             KC_KP_PLUS,
        KC_KP_4,             KC_KP_5,       KC_KP_6,
        KC_KP_1,             KC_KP_2,       KC_KP_3,             KC_KP_ENTER,
        KC_KP_0,                            KC_KP_DOT    
    )
};

// Handle rotary encoder
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
	print("encoder!");
	if (index == 0) {
		if (clockwise) {
			tap_code(KC_AUDIO_VOL_UP);
		} else {
			tap_code(KC_AUDIO_VOL_DOWN);
		}
	} else {
		uprintf("%s %s encoder", index, clockwise);
	}
	return false;
}
#endif


// Enable debugging

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

