#include "action_layer.h"
#include "rgb_matrix.h"

rgb_t hsv_to_rgb_limited(int h, int s, int v) {
    hsv_t hsv = {h, s, v};
    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    return hsv_to_rgb(hsv);
}

int char_leds[]   = {1, 3, 7, 9, 12, 14, 17, 19, 22, 24};
int home_leds[]   = {2, 8, 13, 18, 23};
int number_leds[] = {0, 10, 11, 20, 21};
int mod_leds[]    = {25, 26, 27, 28};
int thumb_leds[]  = {4, 5, 6, 15, 16};

void set_color(int *leds, size_t size, rgb_t rgb) {
    for (int i = 0; i < size; i++) {
        rgb_matrix_set_color(leds[i], rgb.r, rgb.g, rgb.b);
    }
}

// void keyboard_post_init_user(void) {
//     rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
//     rgb_matrix_sethsv_noeeprom(HSV_OFF);
// }

rgb_t char_color;
rgb_t home_color;
rgb_t number_color;
rgb_t mod_color;
rgb_t thumb_color;

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        default:
            char_color   = hsv_to_rgb_limited(HSV_YELLOW);
            home_color   = hsv_to_rgb_limited(HSV_YELLOW);
            number_color = hsv_to_rgb_limited(HSV_CORAL);
            mod_color    = hsv_to_rgb_limited(HSV_TEAL);
            thumb_color  = hsv_to_rgb_limited(HSV_TEAL);

            set_color(char_leds, sizeof(char_leds) / sizeof(char_leds[0]), char_color);
            set_color(home_leds, sizeof(home_leds) / sizeof(home_leds[0]), home_color);
            set_color(number_leds, sizeof(number_leds) / sizeof(number_leds[0]), number_color);
            set_color(mod_leds, sizeof(mod_leds) / sizeof(mod_leds[0]), mod_color);
            set_color(thumb_leds, sizeof(thumb_leds) / sizeof(thumb_leds[0]), thumb_color);
    }
    return false;
}