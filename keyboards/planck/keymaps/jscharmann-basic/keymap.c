/* Copyright 2015-2017 Jack Humbert, 2017 Jason Scharmann
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

#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___X___ KC_NO
// Shift + GUI - Easy i3 shift + Mod key use
#define KC_SWIN SWIN(KC_NO)

// Layers specified by utility, less ambiguous
enum my_layers {
    _WORKMAN,
    _FUNCTIONS,
    _NUMBERS_AND_SYMBOLS,
    _ADJUST
};

enum my_keycodes {
    MY_FUNC = SAFE_RANGE,
    MY_NUMB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Workman
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  |   -  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  | Ent  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  | Shift|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | GUI  | Alt  | SGUI |Lower |Bkspce|  Spc |Raise | SGUI |  Alt |  GUI | Ctl  |
     * `-----------------------------------------------------------------------------------'
     */
    [_WORKMAN] = {
        {KC_ESC,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_MINS},
        {KC_TAB,  KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_ENT },
        {KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
        {KC_LCTL, KC_LALT, KC_LGUI, KC_SWIN, MY_FUNC, KC_BSPC, KC_SPC,  MY_NUMB, KC_SWIN, KC_RGUI, KC_RALT, KC_RCTL}
    },

    /* Function Keys
     * ,-----------------------------------------------------------------------------------.
     * |xxxxxx|  F1  |  F2  |  F3  |  F4  | Prev | Next |  F13 |  F14 |  F15 |  F16 |  Del |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |CapsLk|  F5  |  F6  |  F7  |  F8  | Mute | Play |  F17 |  F18 |  F19 |  F20 |Insert|
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |xxxxxx|  F9  |  F10 |  F11 |  F12 | Vol- | Vol+ |  F21 |  F22 |  F23 |  F24 |xxxxxx|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_FUNCTIONS] = {
        {___X___, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_MPRV, KC_MNXT, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_DEL },
        {KC_CAPS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_MUTE, KC_MPLY, KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_INS },
        {___X___, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_VOLD, KC_VOLU, KC_F21,  KC_F22,  KC_F23,  KC_F24,  ___X___},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
    },

    /* Numbers & Symbols
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   =  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   "  | Home | PgUp | PgDn |  End |   [  |   ]  | Left | Down |  Up  | Right|   \  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_NUMBERS_AND_SYMBOLS] = {
        {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL },
        {KC_QUOT, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS},
        {___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
    },
    /* Adjustment Layer
     * ,-----------------------------------------------------------------------------------.
     * | Reset|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |xxxxxx|xxxxxx|xxxxxx|xxxxxx|      |xxxxxx|xxxxxx|      |xxxxxx|xxxxxx|xxxxxx|xxxxxx|
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = {
        {RESET,   ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___},
        {___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___},
        {___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___},
        {___X___, ___X___, ___X___, ___X___, _______, ___X___, ___X___, _______, ___X___, ___X___, ___X___, ___X___}
    },
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case MY_FUNC:
            if (record->event.pressed) {
                layer_on(_FUNCTIONS);
                update_tri_layer(_FUNCTIONS, _NUMBERS_AND_SYMBOLS, _ADJUST);
            } else {
                layer_off(_FUNCTIONS);
                update_tri_layer(_FUNCTIONS, _NUMBERS_AND_SYMBOLS, _ADJUST);
            }
            return false;
            break;
        case MY_NUMB:
            if (record->event.pressed) {
                layer_on(_NUMBERS_AND_SYMBOLS);
                update_tri_layer(_FUNCTIONS, _NUMBERS_AND_SYMBOLS, _ADJUST);
            } else {
                layer_off(_NUMBERS_AND_SYMBOLS);
                update_tri_layer(_FUNCTIONS, _NUMBERS_AND_SYMBOLS, _ADJUST);
            }
            return false;
            break;
    }
    return true;
}
