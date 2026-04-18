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

// TODO: consider removing home row mods in favor of tap toggles with OSM keys in dedicated layer?
// TODO: rework thumb clusters (probably shortcuts or OSM keys or toggles for additional shortcut layers)
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
        // OSM(MOD_LSFT), LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G, // home row mods
        KC_U, KC_A, KC_R, KC_S, KC_T, KC_G, // using KC_U instead of OSM(MOD_LSFT) to debug the not working key
        // Right home row
        // KC_M, RCTL_T(KC_N), RSFT_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), FR_SCLN,  // home row mods
        KC_M, KC_N, KC_E, KC_I, KC_O, FR_SCLN,

        // Left bottom row + encoder
        OSM(MOD_LCTL), KC_Z, KC_X, KC_C, KC_D, KC_V, KC_MPLY,
        // Right bottom row + encoder
        MS_BTN3, KC_K, KC_H, KC_COMM, KC_DOT, FR_EACU, FR_DGRV,

        // Left thumb cluster
        KC_LALT, KC_LCTL, KC_LSFT, KC_SPC, LT(NAVIGATION_LAYER, KC_TAB),
        // Right thumb cluster
        LT(SYMBOL_LAYER, KC_ENT), KC_BSPC, KC_RGUI, KC_DEL, KC_ALGR),

    [NAVIGATION_LAYER] = LAYOUT(
        // Left number rows
        KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
        // Right number rows
        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,

        // Left top row
        KC_NO, OSM(MOD_HYPR), OSM(MOD_LCTL | MOD_LALT), OSM(MOD_LCTL | MOD_LSFT), OSM(MOD_LCTL | MOD_LGUI), KC_NO,
        // Right top row
        KC_AGIN, KC_PSTE, KC_COPY, KC_CUT, KC_UNDO, KC_NO,

        // Left home row
        OS_TOGG, KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_SHIFT, KC_LEFT_CTRL, KC_NO,
        // Right home row
        KC_CAPS_LOCK, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO,

        // Left bottom row + encoder
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______,
        // Right bottom row + encoder
        _______, KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO,

        // Left thumb cluster
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        // Right thumb cluster
        _______, _______, _______, _______, _______),

    [SYMBOL_LAYER] = LAYOUT(
        // Left number rows
        _______, _______, _______, _______, _______, _______,
        // Right number rows
        _______, _______, _______, _______, _______, _______,

        // Left top row
        KC_NO, FR_TILD, FR_BSLS, FR_SLSH, FR_PIPE, FR_DLR,
        // Right top row
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        // Left home row
        KC_NO, FR_LABK, FR_LBRC, FR_LBRC, FR_LPRN, FR_PERC,
        // Right home row
        KC_NO, FR_RPRN, FR_RBRC, FR_RBRC, FR_RABK, KC_NO,

        // Left bottom row + encoder
        KC_NO, FR_ASTR, FR_MINS, FR_PLUS, FR_EQL, FR_AMPR, _______,
        // Right bottom row + encoder
        _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        // Left thumb cluster
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        // Right thumb cluster
        _______, _______, _______, _______, _______),
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
