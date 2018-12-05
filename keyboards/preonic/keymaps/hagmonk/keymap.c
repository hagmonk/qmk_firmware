/* Copyright 2015-2017 Jack Humbert
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

#include "preonic.h"
#include "action_layer.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  I_SCOLON
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |                                                               */

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | \    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | LCtrl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   '  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lower| Raise| Alt  | GUI  | LGui | Backspace   |Space |   :  |   -  |Raise |Lower |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
             //  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_GRV,    KC_EXLM,     KC_AT,  KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    KC_BSPC},
  {KC_TAB     , KC_Q,       KC_W,   KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,         KC_O,     KC_P,       KC_BSLASH},
  {KC_LCTL    , KC_A,       KC_S,   KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,         KC_L,     KC_QUOT,    KC_ENT},
  {KC_LSFT    , KC_Z,       KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM,      KC_DOT,   KC_SLSH,    KC_RSFT},
  {MO(_LOWER) , MO(_RAISE), KC_ESC, KC_LALT, KC_LGUI, KC_BSPC, KC_BSPC, KC_SPC, I_SCOLON, KC_MINUS, MO(_RAISE), MO(_LOWER)}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  {   |  [   |  (   |      |      |   )  |   ]  |   }  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   7  |   8  |   9  |   )  |Reset |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | LCtrl|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   4  |   5  |   6  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  {   |  [   |  (   |  F11 |  F12 |   1  |   2  |   3  | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | LAlt | LGui |             |   0  |   .  |  =   |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, _______, S(KC_LBRACKET), KC_LBRACKET, S(KC_9), _______, _______, S(KC_0), KC_RBRACKET, S(KC_RBRACKET), _______, _______},
  {KC_TILD, KC_EXLM, KC_AT,          KC_HASH,     KC_DLR,  KC_PERC, KC_CIRC, KC_7,     KC_8, KC_9,   KC_RPRN,  RESET},
  {KC_LCTL, KC_F1,   KC_F2,          KC_F3,       KC_F4,   KC_F5,   KC_F6,   KC_4,     KC_5, KC_6,   KC_RCBR,  KC_PIPE},
  {KC_LSFT, KC_F7,   S(KC_LBRACKET), KC_LBRACKET, S(KC_9), KC_F11,  KC_F12,  KC_1,     KC_2, KC_3,   KC_END,   _______},
  {_______, _______, _______,        KC_LALT,     KC_LGUI, _______, _______, KC_EQUAL, KC_0, KC_DOT, _______ , _______}
},


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |  *   |   (  |  )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |  *   |   (  |  )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | LCtrl|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  F7  |  }   |  ]   |  )   |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_EXLM, KC_AT,          KC_HASH,     KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  RESET},
  {KC_GRV,  KC_EXLM, KC_AT,          KC_HASH,     KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  RESET},
  {KC_LCTL, KC_F1,   KC_F2,          KC_F3,       KC_F4,   KC_F5,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, KC_BSLS},
  {KC_LSFT, KC_F7,   S(KC_RBRACKET), KC_RBRACKET, S(KC_0), KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN,  _______},
  {_______, _______, _______,        KC_LALT,     KC_LGUI, _______, _______, _______, KC_MNXT, KC_VOLD, _______,  _______}
},


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL},
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case I_SCOLON:
    if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
      if (record->event.pressed) {
        unregister_code(KC_LSFT);
        register_code(KC_SCOLON);
        unregister_code(KC_SCOLON);
        register_code(KC_LSFT);
      }
    } else {
      if (record->event.pressed) {
        register_code(KC_LSFT);
        register_code(KC_SCOLON);
        unregister_code(KC_SCOLON);
        unregister_code(KC_LSFT);
      }
    }
    break;
  }
  return true;
}
