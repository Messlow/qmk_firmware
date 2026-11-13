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

#include "keymap_canadian_french.h"
#include QMK_KEYBOARD_H

enum layer_names {
    BASE_COLEMAK_LAYER,
    NAVIGATION_LAYER,
    SYMBOL_LAYER,
};

// Dedicated thumb modifiers and layer holds; one-shot Shift on the left edge.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_COLEMAK_LAYER] = LAYOUT(
        // Left number rows
        FR_HASH, KC_1, KC_2, KC_3, KC_4, KC_5,
        // Right number rows
        KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,

        // Left top row
        KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_B,
        // Right top row
        KC_J, KC_L, KC_U, KC_Y, FR_DCIR, FR_CEDL,

        // Left home row
        KC_TAB, KC_A, KC_R, KC_S, KC_T, KC_G,
        // Right home row
        KC_M, KC_N, KC_E, KC_I, KC_O, FR_SCLN,

        // Left bottom row + encoder
        OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_D, KC_V, KC_MPLY,
        // Right bottom row + encoder
        MS_BTN3, KC_K, KC_H, KC_COMM, KC_DOT, FR_EACU, FR_DGRV,

        // Left thumb cluster
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(NAVIGATION_LAYER),
        // Right thumb cluster
        MO(SYMBOL_LAYER), KC_ENT, KC_BSPC, KC_RGUI, KC_ALGR),

    [NAVIGATION_LAYER] = LAYOUT(
        // Left number rows
        KC_NO, LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5),
        // Right number rows
        LCTL(KC_6), LCTL(KC_7), LCTL(KC_8), LCTL(KC_9), LCTL(KC_0), KC_NO,

        // Left top row
        KC_NO, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO,
        // Right top row
        KC_AGIN, KC_PSTE, KC_COPY, KC_CUT, KC_UNDO, KC_DEL,

        // Left home row
        KC_TAB, OSM(MOD_LGUI | MOD_LSFT), OSM(MOD_LCTL | MOD_LSFT), OSM(MOD_LCTL | MOD_LGUI), OSM(MOD_LCTL | MOD_LSFT), KC_NO,
        // Right home row
        KC_CAPS_LOCK, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO,

        // Left bottom row + encoder
        OSM(MOD_LSFT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPLY,
        // Right bottom row + encoder
        MS_BTN3, KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO,

        // Left thumb cluster
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(NAVIGATION_LAYER),
        // Right thumb cluster
        MO(SYMBOL_LAYER), KC_ENT, KC_BSPC, KC_RGUI, KC_ALGR),

    [SYMBOL_LAYER] = LAYOUT(
        // Left number rows
        KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
        // Right number rows
        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,

        // Left top row
        KC_NO, FR_TILD, FR_BSLS, FR_SLSH, FR_PIPE, FR_DLR,
        // Right top row
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        // Left home row
        KC_TAB, FR_LABK, FR_LBRC, FR_LCBR, FR_LPRN, FR_PERC,
        // Right home row
        KC_NO, FR_RPRN, FR_RBRC, FR_RCBR, FR_RABK, KC_NO,

        // Left bottom row + encoder
        OSM(MOD_LSFT), FR_ASTR, FR_MINS, FR_PLUS, FR_EQL, FR_AMPR, KC_MPLY,
        // Right bottom row + encoder
        MS_BTN3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        // Left thumb cluster
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(NAVIGATION_LAYER),
        // Right thumb cluster
        MO(SYMBOL_LAYER), KC_ENT, KC_BSPC, KC_RGUI, KC_ALGR),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE_COLEMAK_LAYER] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
    [NAVIGATION_LAYER]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
    [SYMBOL_LAYER]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
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
