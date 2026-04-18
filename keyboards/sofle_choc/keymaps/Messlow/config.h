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
#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
// Enabling this option changes the startup behavior to listen for an
// active USB communication to delegate which part is master and which
// is slave. With this option enabled and theres’s USB communication,
// then that half assumes it is the master, otherwise it assumes it
// is the slave.
//
// I've found this helps with some ProMicros where the slave does not boot
#define SPLIT_USB_DETECT

#define RGB_DISABLE_WHEN_USB_SUSPENDED    // turn off effects when suspended
#define SPLIT_TRANSPORT_MIRROR            // If LED_MATRIX_KEYPRESSES or LED_MATRIX_KEYRELEASES is enabled, you also will want to enable SPLIT_TRANSPORT_MIRROR
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100 // limits maximum brightness of LEDs (max 255). Higher may cause the controller to crash.

#define RGBLED_NUM 70
#define RGBLED_SPLIT {35, 35}

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

#define BACKLIGHT_BREATHING

// Double tap locks layer
#define TAPPING_TOGGLE 2

// Helpful defines
#define GRAVE_MODS (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT))

// Double tap shift for caps lock
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Home row mods
#define TAPPING_TERM 250 // milliseconds before hold activates
#define PERMISSIVE_HOLD  // tap other keys while holding mod = hold activates
#define FLOW_TAP_TERM 150
#define CHORDAL_HOLD    // opposite hands rule
#define SPECULATIVE_HOLD

// Hints: ("false positives" = triggering modifiers accidentally, "false negatives" = failing to trigger modifiers when they are desired)
// Noticeable delay when tapping HRMs: Increase FLOW_TAP_TERM.
// False negatives (same-hand): Reduce TAPPING_TERM (or disable Chordal Hold)
// False negatives (cross-hand): Reduce FLOW_TAP_TERM
// False positives (same-hand): Increase TAPPING_TERM
// False positives (cross-hand): Increase FLOW_TAP_TERM
