/* Original Version Copyright 2015-2017 Jack Humbert
* Modifications by Armin Jenewein in 2018
*/

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _BOTTOM,
  _LOWER,
  _RAISE,
  _TOP,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BOTTOM,
  TOP,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define BOTTOM MO(_BOTTOM)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define TOP MO(_TOP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
KC_LCTL, KC_LGUI, KC_LALT, BOTTOM, LOWER, KC_SPC, KC_SPC, RAISE, TOP, KC_RALT, KC_RGUI, KC_ENT
),

[_BOTTOM] = LAYOUT_planck_grid(
RESET, XXXXXXX, KC_Q, KC_F, KC_J, KC_T, KC_Y, KC_7, KC_8, KC_9, KC_P, KC_BSPC,
KC_TAB, KC_A, S(KC_BSPC), S(KC_ENT), S(KC_INS), KC_G, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_RBRACKET, KC_QUOT,
KC_LSFT, KC_Y, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_V, KC_B, KC_1, KC_2, KC_3, KC_SLSH, KC_MS_BTN2,
KC_LCTL, BACKLIT, KC_LALT, KC_LGUI, LOWER, KC_MS_BTN1, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, KC_RSFT, KC_RALT, KC_ENT
),

[_LOWER] = LAYOUT_planck_grid(
KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_RPRN, LSFT(KC_MINS),
KC_DEL, KC_UNDS, KC_PLUS, RALT(KC_8), RALT(KC_9), KC_LCBR, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_LBRACKET, KC_RBRACKET, 
_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, RALT(KC_8), RALT(KC_9), RALT(KC_RBRC), LSFT(KC_EQL), S(KC_NUHS),
_______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_CAPSLOCK, KC_NUHS, S(KC_SLSH), KC_SLSH, KC_NUHS
),

[_RAISE] = LAYOUT_planck_grid(
KC_INS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
KC_DEL, RALT(KC_7), RALT(KC_0), LSFT(KC_8), LSFT(KC_9), KC_RBRC, KC_LEFT, KC_PGDN, KC_PGUP, KC_RGHT, KC_LBRC, KC_PLUS,
_______, KC_NUBS, LSFT(KC_NUBS), RALT(KC_MINS), RALT(KC_NUBS), LSFT(KC_7), KC_RBRC, KC_MINS, KC_PGUP, KC_SCLN, KC_QUOT, KC_NUHS,
KC_GRV, LSFT(KC_LBRC), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______, LSFT(KC_RBRC), KC_NUBS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_TOP] = LAYOUT_planck_grid(
RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_T, KC_Y, KC_7, KC_8, KC_9, KC_P, KC_BSPC,
KC_TAB, KC_F5, KC_F6, KC_F7, KC_F8, KC_G, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_RBRACKET, KC_QUOT,
KC_LSFT, KC_F9, KC_F10, KC_F11, KC_F12, KC_V, KC_B, KC_1, KC_2, KC_3, KC_SLSH, KC_MS_BTN2,
KC_LCTL, BACKLIT, KC_LALT, KC_LGUI, LOWER, KC_MS_BTN1, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, KC_RSFT, KC_RALT, KC_ENT
),

[_PLOVER] = LAYOUT_planck_grid(
KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1 ,
XXXXXXX, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
XXXXXXX, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
EXT_PLV, XXXXXXX, XXXXXXX, KC_C, KC_V, XXXXXXX, XXXXXXX, KC_N, KC_M, XXXXXXX, XXXXXXX, XXXXXXX
),

[_ADJUST] = LAYOUT_planck_grid(
_______, RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
_______, _______, MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______,
_______, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, TERM_ON, TERM_OFF, _______, _______, _______,
_______, _______, _______, _______, _______, _______, _______, QWERTY, COLEMAK, DVORAK, PLOVER, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2] = SONG(PLOVER_SOUND);
  float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      return false;
      break;
    case DVORAK:
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
