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
#include "os_detection.h"

enum layer_names {
    BASE_COLEMAK_LAYER,
    NAVIGATION_LAYER,
    SYMBOL_LAYER,
};

enum custom_keycodes {
    APP_SWITCH = SAFE_RANGE,
    WINDOW_OVERVIEW,
    ENC_TAB_PREV,
    ENC_TAB_NEXT,
    ENC_SPACE_PREV,
    ENC_SPACE_NEXT,
    FR_A_GRAVE,
    FR_E_GRAVE,
    FR_C_CEDILLA,
};

// Apply modifiers to the letter, never to the dead accent. Consume one-shot
// modifiers with this character while preserving physically held modifiers.
static void tap_accented_letter(uint16_t accent, uint8_t letter) {
    const uint8_t mods = get_mods();
    const uint8_t weak_mods = get_weak_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();
    clear_mods();
    clear_weak_mods();
    clear_oneshot_mods();
    tap_code16_delay(accent, 10);
    set_mods(mods);
    set_weak_mods(weak_mods | oneshot_mods);
    tap_code16_delay(letter, 10);
    set_weak_mods(weak_mods);
    send_keyboard_report();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint16_t encoder_shortcut;
    switch (keycode) {
        case FR_A_GRAVE:
        case FR_E_GRAVE:
        case FR_C_CEDILLA:
            if (record->event.pressed) {
                tap_accented_letter(keycode == FR_C_CEDILLA ? FR_CEDL : FR_DGRV,
                                    keycode == FR_A_GRAVE ? KC_A : keycode == FR_E_GRAVE ? KC_E : KC_C);
            }
            return false;
        case ENC_TAB_PREV:
            encoder_shortcut = LCTL(LSFT(KC_LEFT));
            break;
        case ENC_TAB_NEXT:
            encoder_shortcut = LCTL(LSFT(KC_RGHT));
            break;
        case ENC_SPACE_PREV:
            encoder_shortcut = LCTL(LGUI(KC_LEFT));
            break;
        case ENC_SPACE_NEXT:
            encoder_shortcut = LCTL(LGUI(KC_RGHT));
            break;
        case APP_SWITCH:
        case WINDOW_OVERVIEW:
            if (record->event.pressed) {
                // Prefer macOS when detection is inconclusive.
                const bool windows = detected_host_os() == OS_WINDOWS;
                if (keycode == APP_SWITCH) {
                    tap_code16(windows ? LALT(KC_TAB) : LGUI(KC_TAB));
                } else {
                    tap_code16(windows ? LGUI(KC_TAB) : LCTL(KC_UP));
                }
            }
            return false;
        default:
            return true;
    }

    if (record->event.pressed) {
        // Only base-layer rotation shortcuts get host recognition time.
        tap_code16_delay(encoder_shortcut, 20);
        wait_ms(20);
    }
    return false;
}

// Pinky and thumb modifiers; one-shot left Shift and dedicated right Shift.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_COLEMAK_LAYER] = LAYOUT(
        // Left number rows
        FR_HASH, KC_1, KC_2, KC_3, KC_4, KC_5,
        // Right number rows
        KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,

        // Left top row
        KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_B,
        // Right top row
        KC_J, KC_L, KC_U, KC_Y, FR_QUOT, KC_BSPC,

        // Left home row
        KC_LCTL, KC_A, KC_R, KC_S, KC_T, KC_G,
        // Right home row
        KC_M, KC_N, KC_E, KC_I, KC_O, KC_RGUI,

        // Left bottom row + encoder
        OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_D, KC_V, APP_SWITCH,
        // Right bottom row + encoder
        WINDOW_OVERVIEW, KC_K, KC_H, KC_COMM, KC_DOT, FR_EACU, KC_RSFT,

        // Left thumb cluster
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(NAVIGATION_LAYER),
        // Right thumb cluster
        MO(SYMBOL_LAYER), KC_BSPC, KC_ENT, KC_RGUI, KC_ALGR),

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
        KC_CAPS_LOCK, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_RGUI,

        // Left bottom row + encoder
        OSM(MOD_LSFT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MS_BTN1,
        // Right bottom row + encoder
        MS_BTN3, KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_RSFT,

        // Left thumb cluster
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(NAVIGATION_LAYER),
        // Right thumb cluster
        MO(SYMBOL_LAYER), KC_BSPC, KC_ENT, KC_RGUI, KC_ALGR),

    [SYMBOL_LAYER] = LAYOUT(
        // Left number rows
        KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
        // Right number rows
        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,

        // Left top row
        KC_NO, FR_TILD, FR_BSLS, FR_SLSH, FR_PIPE, FR_DLR,
        // Right top row
        FR_DGRV, FR_COLN, FR_SCLN, KC_NO, FR_DCIR, KC_BSPC,

        // Left home row
        KC_TAB, FR_LABK, FR_LBRC, FR_LCBR, FR_LPRN, FR_PERC,
        // Right home row
        FR_CEDL, FR_RPRN, FR_RCBR, FR_RBRC, FR_RABK, KC_RGUI,

        // Left bottom row + encoder
        OSM(MOD_LSFT), FR_ASTR, FR_MINS, FR_PLUS, FR_EQL, FR_AMPR, KC_MPLY,
        // Right bottom row + encoder
        RM_TOGG, KC_NO, FR_A_GRAVE, FR_E_GRAVE, FR_C_CEDILLA, KC_NO, KC_RSFT,

        // Left thumb cluster
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(NAVIGATION_LAYER),
        // Right thumb cluster
        MO(SYMBOL_LAYER), KC_BSPC, KC_ENT, KC_RGUI, KC_ALGR),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE_COLEMAK_LAYER] = {ENCODER_CCW_CW(ENC_TAB_PREV, ENC_TAB_NEXT), ENCODER_CCW_CW(ENC_SPACE_PREV, ENC_SPACE_NEXT)},
    [NAVIGATION_LAYER]   = {ENCODER_CCW_CW(MS_WHLL, MS_WHLR), ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
    [SYMBOL_LAYER]       = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RM_VALD, RM_VALU)},
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
