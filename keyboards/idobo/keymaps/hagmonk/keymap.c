/* Copyright 2017 Wunder
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

#include QMK_KEYBOARD_H

enum xd75_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum xd75_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  I_SCOLON
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CAP LK | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QWERTY] = { /* QWERTY */
   {KC_GRV,    KC_EXLM,   KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,  RESET,   _______, KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN,  KC_RPRN,   KC_BSPC},
   {KC_TAB,    KC_Q,      KC_W,    KC_E,    KC_R,    KC_T,    KC_7,     KC_8,    KC_9,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,      KC_BSLASH},
   {KC_LCTL,   KC_A,      KC_S,    KC_D,    KC_F,    KC_G,    KC_4,     KC_5,    KC_6,    KC_H,    KC_J,    KC_K,     KC_L,     KC_QUOT,   KC_ENT},
   {KC_LSFT,   KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,    KC_1,     KC_2,    KC_3,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,   KC_RSFT},
   {MO(_LOWER), MO(_RAISE), _______, _______, KC_LALT, KC_LGUI, KC_EQUAL, KC_0,    KC_ESC,  KC_BSPC, KC_SPC,  I_SCOLON, KC_MINUS, MO(_RAISE), MO(_LOWER)}
 }

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 /* [LOWER] = { /\* FUNCTION *\/ */
 /*  { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12   }, */
 /*  { KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS  }, */
 /*  { KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, _______  }, */
 /*  { KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______  }, */
 /*  { _______, _______, RGB_TOG, MO(_FN), RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, _______  }, */
 /* } */
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
