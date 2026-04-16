/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// Right now the symbols are messed up because it assumes an english layout. Seems like this does not work.
#include "keymap_canadian_french.h"
#include QMK_KEYBOARD_H

// TODO: Add dead keys FR ([], {} <>, ç, `, é)
enum layer_names {
    // BASE_QWERTY_LAYER,
    BASE_COLEMAK_LAYER,
    NAVIGATION_LAYER,
    TRANSPARENT_LAYER,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCTL | LGUI | LCMD | LALT | /Enter  /       \Space \  | RALT | RCMD | RGUI | RCTL |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    // [BASE_QWERTY_LAYER] = LAYOUT(
    //     KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_RGUI,
    //     KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
    //     KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    //     KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY,   MS_BTN3,KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    //                     KC_LCTL, KC_LALT, TT(NAVIGATION_LAYER), KC_ENT, KC_DEL,    KC_BSPC, KC_SPC,  NAV_ESC,  KC_RALT, KC_RCTL
    // ),

    // /*
    //  * COLEMAK-DH
    //  * ,-----------------------------------------.                    ,-----------------------------------------.
    //  * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * | ESC  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
    //  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    //  * | Tab  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
    //  * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
    //  * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
    //  * `-----------------------------------------/       /     \      \-----------------------------------------'
    //  *            | LCTL | LGUI | LCMD | LALT | /Enter  /       \Space \  | RALT | RCMD | RGUI | RCTL |
    //  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    //  *            `----------------------------------'           '------''---------------------------'
    //  */
    [BASE_COLEMAK_LAYER] = LAYOUT(
        KC_GRV,   KC_1,         KC_2,         KC_3,         KC_4,         KC_5,                          KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_RGUI,
        KC_ESC,   KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,                          KC_J,     KC_L,     KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_TAB,   LALT_T(KC_A), LCTL_T(KC_R), LSFT_T(KC_S), LGUI_T(KC_T), KC_G,                          KC_M, RGUI_T(KC_N), RSFT_T(KC_E), RCTL_T(KC_I), RALT_T(KC_O), KC_QUOT,
        KC_LSFT,  KC_Z,         KC_X,         KC_C,         KC_D,         KC_V, KC_MPLY,        MS_BTN3, KC_K,     KC_H,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,

        // Thumb left
        _______, _______, KC_ESC, LT(NAVIGATION_LAYER, KC_SPC), KC_TAB,

        // Thumb right
        LT(SYMBOL_LAYER, KC_ENT), KC_BSPC,  KC_DEL,  _______, _______
    ),

    /*
     * NAVIGATION
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |______|______|______|______|______|______|                    |______|______|______|______|______|______|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |______|______|______|______|______|______|                    |______|______|______|______|______|______|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |______|______|______|______|______|______|-------.    ,-------|______|   <  |   ∨  |   ∧  |   >  |______|
     * |------+------+------+------+------+------|______ |    |______ |------+------+------+------+------+------|
     * |______|______|______|______|______|______|-------|    |-------|______|______|______|______|______|______|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |______|______|______|______| /______ /       \______\  |______|______|______|______|
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [NAVIGATION_LAYER] = LAYOUT(
         KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM,  KC_EQL,   KC_LT,   KC_GT, KC_MINUS,                        KC_AGIN, KC_PSTE,  KC_COPY,  KC_CUT,  KC_UNDO, KC_BSPC,
        _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_PIPE,                         _______, KC_LEFT,  KC_DOWN,   KC_UP, KC_RIGHT,  KC_DEL,
        _______, _______, KC_HASH, KC_LCBR, KC_RCBR, KC_PLUS, _______,       _______,  KC_INS, KC_HOME,  KC_PGDN, KC_PGUP,   KC_END, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______,  _______, _______
    ),

    [TRANSPARENT_LAYER] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______,  _______, _______
    )

};
// clang-format on

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // [BASE_QWERTY_LAYER] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
    [BASE_COLEMAK_LAYER] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
    [NAVIGATION_LAYER]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
    [TRANSPARENT_LAYER] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
};
#endif

#ifdef OLED_ENABLE
#    include "oled.c"
#endif

#ifdef RGB_MATRIX_ENABLE
#    include "rgb.c"
#endif

void keyboard_post_init_user(void) {
    // Call the post init code.
    // set_single_persistent_default_layer(BASE_QWERTY_LAYER);
    set_single_persistent_default_layer(BASE_COLEMAK_LAYER);
}
