// Copyright 2021 Grant Emsley (@grantemsley)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "numpad.h"

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    return encoder_update_user(index, clockwise);
}
#endif

// Make numlock always on at startup
void numlock_on(void) {
	led_t led_state = host_keyboard_led_state();
	bool b = led_state.num_lock;
	if (!b) {
		register_code(KC_NUMLOCK);
		unregister_code(KC_NUMLOCK);
	}
}

void keyboard_post_init_kb() {
	keyboard_post_init_user();
	numlock_on();
	
	rgblight_enable_noeeprom();
	rgblight_sethsv_noeeprom(180,255,255);
}
