// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
     _QWERTY,
     _SYMBOLS,
     _NUMPAD,
     _FUNCTIONS,
};

enum combo_events {
    COMBO_CAPS,
    COMBO_LENGTH,
};

// void keyboard_post_init_user(void) {
//     eeconfig_init();
// }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────────────────┬───┬───┬───┬─────────────┬───────────────────┐                                        ┌───────────────────┬──────────────┬───┬───┬───┬─────────────┐
//    │ MO(_FUNCTIONS) │ 1 │ 2 │ 3 │      4      │         5         │                                        │         6         │      7       │ 8 │ 9 │ 0 │ MO(_NUMPAD) │
//    ├────────────────┼───┼───┼───┼─────────────┼───────────────────┤                                        ├───────────────────┼──────────────┼───┼───┼───┼─────────────┤
//    │      tab       │ q │ w │ e │      r      │         t         │                                        │         y         │      u       │ i │ o │ p │     del     │
//    ├────────────────┼───┼───┼───┼─────────────┼───────────────────┤                                        ├───────────────────┼──────────────┼───┼───┼───┼─────────────┤
//    │      lctl      │ a │ s │ d │      f      │         g         │                                        │         h         │      j       │ k │ l │ ; │      '      │
//    ├────────────────┼───┼───┼───┼─────────────┼───────────────────┼───────────────────┬────────────────────┼───────────────────┼──────────────┼───┼───┼───┼─────────────┤
//    │      lsft      │ z │ x │ c │      v      │         b         │       lalt        │        del         │         n         │      m       │ , │ . │ / │    rsft     │
//    └────────────────┴───┴───┴───┼─────────────┼───────────────────┼───────────────────┼────────────────────┼───────────────────┼──────────────┼───┴───┴───┴─────────────┘
//                                 │ MO(_NUMPAD) │ MT(MOD_LGUI, esc) │ MT(MOD_LCTL, ent) │ MT(MOD_RCTL, bspc) │ MT(MOD_RALT, spc) │ MO(_SYMBOLS) │
//                                 └─────────────┴───────────────────┴───────────────────┴────────────────────┴───────────────────┴──────────────┘
[_QWERTY] = LAYOUT(
  MO(_FUNCTIONS) , KC_1 , KC_2 , KC_3 , KC_4        , KC_5                 ,                                                KC_6                 , KC_7         , KC_8    , KC_9   , KC_0    , MO(_NUMPAD),
  KC_TAB         , KC_Q , KC_W , KC_E , KC_R        , KC_T                 ,                                                KC_Y                 , KC_U         , KC_I    , KC_O   , KC_P    , KC_DEL     ,
  KC_LCTL        , KC_A , KC_S , KC_D , KC_F        , KC_G                 ,                                                KC_H                 , KC_J         , KC_K    , KC_L   , KC_SCLN , KC_QUOT    ,
  KC_LSFT        , KC_Z , KC_X , KC_C , KC_V        , KC_B                 , KC_LALT              , KC_DEL                , KC_N                 , KC_M         , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT    ,
                                        MO(_NUMPAD) , MT(MOD_LGUI, KC_ESC) , MT(MOD_LCTL, KC_ENT) , MT(MOD_RCTL, KC_BSPC) , MT(MOD_RALT, KC_SPC) , MO(_SYMBOLS)
),

//    ┌────┬────┬────┬────┬─────┬─────┐           ┌─────┬─────┬────┬────┬────┬────┐
//    │ no │ no │ no │ no │ no  │ no  │           │ no  │ no  │ no │ no │ no │ no │
//    ├────┼────┼────┼────┼─────┼─────┤           ├─────┼─────┼────┼────┼────┼────┤
//    │ no │ (  │ )  │ _  │  [  │  ]  │           │  {  │  }  │ +  │ -  │ |  │ no │
//    ├────┼────┼────┼────┼─────┼─────┤           ├─────┼─────┼────┼────┼────┼────┤
//    │ no │ !  │ @  │ #  │  $  │  %  │           │  ^  │  &  │ *  │ (  │ )  │ no │
//    ├────┼────┼────┼────┼─────┼─────┼─────┬─────┼─────┼─────┼────┼────┼────┼────┤
//    │ no │ no │ no │ no │ no  │ no  │     │     │ no  │ no  │ no │ no │ no │ no │
//    └────┴────┴────┴────┼─────┼─────┼─────┼─────┼─────┼─────┼────┴────┴────┴────┘
//                        │     │     │     │     │     │     │
//                        └─────┴─────┴─────┴─────┴─────┴─────┘
[_SYMBOLS] = LAYOUT(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX,
  XXXXXXX , KC_LPRN , KC_RPRN , KC_UNDS , KC_LBRC , KC_RBRC ,                     KC_LCBR , KC_RCBR , KC_PLUS , KC_MINUS , KC_PIPE , XXXXXXX,
  XXXXXXX , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,                     KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN  , KC_RPRN , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX,
                                          _______ , _______ , _______ , _______ , _______ , _______
),

//    ┌────┬────┬──────┬──────┬──────┬─────┐          ┌────┬──────┬──────┬──────┬────┬─────┐
//    │ no │ no │  no  │  no  │  no  │ no  │          │ no │  no  │  no  │  no  │ no │ no  │
//    ├────┼────┼──────┼──────┼──────┼─────┤          ├────┼──────┼──────┼──────┼────┼─────┤
//    │ no │ no │  no  │  up  │  no  │ no  │          │ no │ kp_7 │ kp_8 │ kp_9 │ =  │ no  │
//    ├────┼────┼──────┼──────┼──────┼─────┤          ├────┼──────┼──────┼──────┼────┼─────┤
//    │ no │ no │ left │ down │ rght │ no  │          │ no │ kp_4 │ kp_5 │ kp_6 │ +  │ no  │
//    ├────┼────┼──────┼──────┼──────┼─────┼────┬─────┼────┼──────┼──────┼──────┼────┼─────┤
//    │ no │ no │  no  │  no  │  no  │ no  │ no │ no  │ no │ kp_1 │ kp_2 │ kp_3 │ -  │     │
//    └────┴────┴──────┴──────┼──────┼─────┼────┼─────┼────┼──────┼──────┴──────┴────┴─────┘
//                            │      │     │ no │ del │ .  │ kp_0 │
//                            └──────┴─────┴────┴─────┴────┴──────┘
[_NUMPAD] = LAYOUT(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , KC_UP   , XXXXXXX , XXXXXXX ,                     XXXXXXX , KC_P7   , KC_P8   , KC_P9   , KC_EQUAL , XXXXXXX,
  XXXXXXX , XXXXXXX , KC_LEFT , KC_DOWN , KC_RGHT , XXXXXXX ,                     XXXXXXX , KC_P4   , KC_P5   , KC_P6   , KC_PLUS  , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_P1   , KC_P2   , KC_P3   , KC_MINS  , _______,
                                          _______ , _______ , XXXXXXX , KC_DEL  , KC_DOT  , KC_P0
),

//    ┌─────────┬──────┬──────┬────┬────┬────┐         ┌────┬────┬────┬────┬─────┬───────────────┐
//    │   no    │ mCTL │ mute │ no │ no │ no │         │ no │ no │ no │ no │ no  │      no       │
//    ├─────────┼──────┼──────┼────┼────┼────┤         ├────┼────┼────┼────┼─────┼───────────────┤
//    │   no    │  no  │  no  │ no │ no │ no │         │ no │ f1 │ f4 │ f7 │ f10 │      no       │
//    ├─────────┼──────┼──────┼────┼────┼────┤         ├────┼────┼────┼────┼─────┼───────────────┤
//    │ EE_CLR  │  no  │  no  │ no │ no │ no │         │ no │ f2 │ f5 │ f8 │ f11 │ LGUI(LSFT(3)) │
//    ├─────────┼──────┼──────┼────┼────┼────┼────┬────┼────┼────┼────┼────┼─────┼───────────────┤
//    │ QK_BOOT │  no  │  no  │ no │ no │ no │ no │ no │ no │ f3 │ f6 │ f9 │ f12 │ LGUI(LSFT(4)) │
//    └─────────┴──────┴──────┴────┼────┼────┼────┼────┼────┼────┼────┴────┴─────┴───────────────┘
//                                 │ no │ no │ no │ no │ no │ no │
//                                 └────┴────┴────┴────┴────┴────┘
[_FUNCTIONS] = LAYOUT(
  XXXXXXX , KC_MCTL , KC_MUTE , XXXXXXX , XXXXXXX , XXXXXXX ,                     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX         ,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                     XXXXXXX , KC_F1   , KC_F4   , KC_F7   , KC_F10  , XXXXXXX         ,
  EE_CLR  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                     XXXXXXX , KC_F2   , KC_F5   , KC_F8   , KC_F11  , LGUI(LSFT(KC_3)),
  QK_BOOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F3   , KC_F6   , KC_F9   , KC_F12  , LGUI(LSFT(KC_4)),
                                          XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
)
};

const uint16_t PROGMEM asd_combo[] = { KC_A, KC_S, KC_D, COMBO_END };

combo_t key_combos[COMBO_LENGTH] PROGMEM = {
    [COMBO_CAPS] = COMBO(asd_combo, KC_CAPS),
};
