// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_UP,   KC_LEFT,   KC_RIGHT,
        KC_DOWN,   KC_Y,   KC_X,
        KC_A,   KC_B,   KC_LSFT,
        KC_RSFT,   KC_ENTER,   KC_ESC
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    }
};
#endif

#ifdef OLED_ENABLE

bool oled_task_user(void) {
    oled_clear();

    oled_write_ln_P(PSTR("NEMO'S"), false);
    oled_write_ln_P(PSTR("HACKPAD"), false);
    oled_write_ln_P(PSTR("VOL KNOB"), false);

    return false;
}

#endif