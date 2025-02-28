// Copyright 2023 Noah Beidelman (@noahbei)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐
     * ├───┼───┬───┐ 
     * │ 7 │   │   │
     * ├───┼───┼───┤
     * │ 4 │ 5 │ 6 │
     * ├───┼───┼───┤
     * │ 1 │ 2 │ 3 │ 
     * └───┴───┴───┘
     */
    [0] = LAYOUT(
        
        KC_7,   
        KC_4,   KC_5,   KC_6,
        KC_1,   KC_2,   KC_3
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case LT(0, KC_NO):
            if (record->event.pressed) {
                // on tap
                if (record->tap.count) {
                    if (get_highest_layer(layer_state) >= 3) {
                        layer_clear(); 
                    } else { 
                        layer_move(get_highest_layer(layer_state) + 1);
                    }
                }
#ifdef OLED_ENABLE
                // on hold
                else {
                    void oled_display_mode_step(void);
                    oled_display_mode_step();
                }
#endif
            }
            return false;
    }
    return true;
}
