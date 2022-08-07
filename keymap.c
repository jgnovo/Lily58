#include QMK_KEYBOARD_H
#include "keymap_spanish.h"
#include <stdio.h>

// This is a global timer for the oled screen
static uint32_t oled_timer = 0;

#define _QWERTY 0
#define _QWERTYF 1
#define _QWERTYS 2
#define _LOWER 3
#define _RAISE 4

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * +-----------------------------------------------+                    +-----------------------------------------------+
 * |  ESC  |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   |   '   |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  TAB  |   Q   |   W   |   E   |   R   |   T   |                    |   Y   |   U   |   I   |   O   |   P   |   `   |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  SFT  |   A   |   S   |   D   |   F   |   G   |-------+    +-------|   H   |   J   |   K   |   L   |   Ñ   |   ´   |
 * |-------+-------+-------+-------+-------+-------| CICLE |    |       |-------+-------+-------+-------+-------+-------|
 * |  ALT  |   Z   |   X   |   C   |   V   |   B   |-------|    |-------|   N   |   M   |   ,   |   .   |   -   |   ¡   |
 * +----------------------------------------------/   S   /      \   S   \----------------------------------------------+
 *                 |       |  GUI  | LCTRL |     /   P   /        \   N   \     | LOWER | RAISE | RALT  |
 *                 |       |       | ESC   |    /   C   /          \   T   \    | DEL   | SUP   |       |
 *                 +-------+-------+-------+---+-------+            +-------+---+-------+-------+-------+
 */
 [_QWERTY] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                 KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    ES_QUOT,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                                 KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    ES_GRV,
    KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                                 KC_H,     KC_J,    KC_K,    KC_L,    ES_NTIL, ES_ACUT,
    KC_LALT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, DF(_QWERTYF),          KC_B,    KC_N,     KC_M,    ES_COMM, ES_DOT,  ES_MINS, ES_LABK,
                               KC_LALT, KC_LGUI, LCTL_T(KC_ESC), KC_SPC, KC_SFTENT, LT(_LOWER, KC_BSPC), LT(_RAISE, KC_DEL), KC_RALT
),
/* QWERTYF
 * +-----------------------------------------------+                    +-----------------------------------------------+
 * |  F1   |   F2  |   F3  |   F4  |   F5  |   F6  |                    |   F7  |   F8  |   F9  |  F10  |  F11  |  F12  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  TAB  |   Q   |   W   |   E   |   R   |   T   |                    |   Y   |   U   |   I   |   O   |   P   |   `   |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  SFT  |   A   |   S   |   D   |   F   |   G   |-------+    +-------|   H   |   J   |   K   |   L   |   Ñ   |   ´   |
 * |-------+-------+-------+-------+-------+-------| CICLE |    |       |-------+-------+-------+-------+-------+-------|
 * |  ALT  |   Z   |   X   |   C   |   V   |   B   |-------|    |-------|   N   |   M   |   ,   |   .   |   -   |   ¡   |
 * +----------------------------------------------/   S   /      \   S   \----------------------------------------------+
 *                 |       |  GUI  | LCTRL |     /   P   /        \   N   \     | LOWER | RAISE | RALT  |
 *                 |       |       | ESC   |    /   C   /          \   T   \    | DEL   | SUP   |       |
 *                 +-------+-------+-------+---+-------+            +-------+---+-------+-------+-------+
 */
 [_QWERTYF] = LAYOUT(
    KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,  KC_F6,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_TAB, KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ES_GRV,
    KC_LSFT, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    ES_NTIL, ES_ACUT,
    KC_LALT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, DF(_QWERTYS),    KC_B, KC_N,    KC_M,    ES_COMM, ES_DOT,  ES_MINS, ES_LABK,
                           KC_LALT, KC_LGUI, LCTL_T(KC_ESC), KC_SPC, KC_SFTENT, LT(_LOWER, KC_BSPC), LT(_RAISE, KC_DEL), KC_RALT
),

/* QWERTYS
 * +-----------------------------------------------+                    +-----------------------------------------------+
 * |   \   |   !   |   "   |   #   |   $   |   %   |                    |   &   |   /   |   (   |   )   |   =   |   '   |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  TAB  |   Q   |   W   |   E   |   R   |   T   |                    |   Y   |   U   |   I   |   O   |   P   |   `   |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  SFT  |   A   |   S   |   D   |   F   |   G   |-------+    +-------|   H   |   J   |   K   |   L   |   Ñ   |   ´   |
 * |-------+-------+-------+-------+-------+-------| CICLE |    |       |-------+-------+-------+-------+-------+-------|
 * |  ALT  |   Z   |   X   |   C   |   V   |   B   |-------|    |-------|   N   |   M   |   ,   |   .   |   -   |   ¡   |
 * +----------------------------------------------/   S   /      \   S   \----------------------------------------------+
 *                 |       |  GUI  | LCTRL |     /   P   /        \   N   \     | LOWER | RAISE | RALT  |
 *                 |       |       | ESC   |    /   C   /          \   T   \    | DEL   | SUP   |       |
 *                 +-------+-------+-------+---+-------+            +-------+---+-------+-------+-------+
 */
 [_QWERTYS] = LAYOUT(
    ES_MORD, ES_EXLM, ES_DQUO, ES_HASH, ES_DLR,  ES_PERC,                  ES_AMPR, ES_SLSH, ES_LPRN,  ES_RPRN,  ES_EQL,   ES_QUOT,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,       KC_U, KC_I,     KC_O,     KC_P,     ES_GRV,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,       KC_J, KC_K,     KC_L,     ES_NTIL,  ES_ACUT,
    KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, DF(_QWERTY),  KC_B, KC_N,       KC_M, ES_COMM,  ES_DOT,   ES_MINS,  ES_LABK,
                            KC_LALT, KC_LGUI, LCTL_T(KC_ESC), KC_SPC, KC_SFTENT,  LT(_LOWER, KC_BSPC), LT(_RAISE, KC_DEL), KC_RALT

),

/* LOWER
 * +-----------------------------------------------+                    +-----------------------------------------------+
 * |   º   |   !   |   "   |   ·   |   $   |   %   |                    |   &   |   /   |   (   |   )   |   =   |   ?   |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |   ª   |   |   |   @   |   #   |   ~   |   €   |                    |   ¬   |  INI  |   ^   |  FIN  |   +   |   ^   |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |   \   |   [   |   ]   |   {   |   }   |       |-------+    +-------|  REP  |   <   |   _   |   >   |  AVP  |   ¨   |
 * |-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
 * |       |   <   |   >   |   Ç   |       |       |-------|    |-------|       |   *   |   ;   |   :   |   _   |   ¿   |
 * +----------------------------------------------/   S   /      \   S   \----------------------------------------------+
 *                 | LALT  | LALT  | LCTRL |     /   P   /        \   T   \     | LOWER | RAISE | RALT  |
 *                 | TAB   | TAB   | ESC   |    /   C   /          \   R   \    | DEL   | SUP   |       |
 *                 +-------+-------+-------+---+-------+            +-------+---+-------+-------+-------+
 */
[_LOWER] = LAYOUT(
    ES_MORD, ES_EXLM, ES_DQUO, ES_HASH, ES_DLR,  ES_PERC,                   ES_AMPR, ES_SLSH, ES_LPRN, ES_RPRN, ES_EQL,  ES_QUES,
    ES_BSLS, ES_PIPE, ES_AT,   ES_BULT, ES_TILD, ES_EURO,                   ES_NOT,  KC_PGUP, KC_UP,   KC_PGDN, KC_PSCR, ES_ASTR,
    ES_FORD, ES_LBRC, ES_RBRC, ES_LCBR, ES_RCBR, _______,                   KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  ES_DIAE,
    _______, ES_IEXL, ES_IQUE, ES_CCED, _______, _______, _______, _______, ES_PLUS, ES_ASTR, ES_SCLN, ES_COLN, ES_UNDS, ES_RABK,
                               _______, _______, _______, _______, _______, _______, _______, _______
),

 /* RAISE
* +-----------------------------------------------+                    +-----------------------------------------------+
* |       |       |       |       |       |       |                    |       |       |       |       |       |       |
* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
* |  F1   |   F2  |   F3  |   F4  |   F5  |   F6  |                    |   F7  |   F8  |   F9  |  F10  |  F11  |  F12  |
* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
* |   ^   |   1   |   2   |   3   |   4   |   5   |-------+    +-------|   6   |   7   |   8   |   9   |   0   |   $   |
* |-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
* |       |       |       |       |       |       |-------|    |-------|       |   *   |   ,   |   .   |   -   |       |
* +----------------------------------------------/   S   /      \   S   \----------------------------------------------+
*                 | LALT  | LALT  | LCTRL |     /   P   /        \   T   \     | LOWER | RAISE | RALT  |
*                 | TAB   | TAB   | ESC   |    /   C   /          \   R   \    | DEL   | SUP   |       |
*                 +-------+-------+-------+---+-------+            +-------+---+-------+-------+-------+
*/
 [_RAISE] = LAYOUT(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______
 )
};


// This is need to process keypresses on both sides, by default it is only done in the master half
bool should_process_keypress(void) { return true; }

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM lily_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(lily_logo, false);
    //oled_write_P(PSTR("     "), false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    if(layer_state_is(_LOWER)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_RAISE)) {
        oled_write_P(raise_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

void render_status_main(void) {
    render_space();
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    if (!is_oled_on()) {
        return;
    }

    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {

        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }
}

/* KEYBOARD PET END */

void render_status_secondary( void) {
    /* wpm counter */
    uint8_t n = get_current_wpm();
    char wpm_str[5];
    wpm_str[4] = '\0';
    wpm_str[3] = '0' + n % 10;
    wpm_str[2] = '0' + (n /= 10) % 10;
    wpm_str[1] = '0' + n / 10;
    wpm_str[0] = ' ';

    render_space();
    render_logo();
    render_space();
    render_space();
    oled_write(wpm_str, false);
    oled_write("  wpm ", false);
    render_luna(0, 10);
}

bool oled_task_user(void) {
    if (timer_elapsed32(oled_timer) < OLED_TIMEOUT) {
        current_wpm   = get_current_wpm();
        led_usb_state = host_keyboard_led_state();

        if (is_keyboard_master()) {
            render_status_secondary();
        } else {
            render_status_main();
        }
    }

    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
        default:
          if (record->event.pressed) {
              #ifdef OLED_ENABLE
                  oled_timer = timer_read32();
                  if(!is_oled_on()) {
                      oled_on();
                  }
              #endif
          }
    }
    return true;
}

