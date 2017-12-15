#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___X___ KC_NO
// Placeholder for any unused layers
#define UNUSED_LAYER {\
    {___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___},\
    {___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___},\
    {___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___},\
    {___X___, ___X___, ___X___, _______, _______, ___X___, ___X___, _______, _______, ___X___, ___X___, ___X___}},
// Aliases for Ctrl+Home & Ctrl+End
// #define MY_CLHM  LCTL(KC_HOME)
// #define MY_CLED  LCTL(KC_END)

enum my_layers {
    LY_0000, LY_0001, LY_0010, LY_0011,
    LY_0100, LY_0101, LY_0110, LY_0111,
    LY_1000, LY_1001, LY_1010, LY_1011,
    LY_1100, LY_1101, LY_1110, LY_1111,
};

enum my_keycodes {
    // Layer Switches
    FN_A = SAFE_RANGE,
    FN_B,
    FN_C,
    FN_D,
    // Dual & Trial Characters
    MY_DEQL, //    /=
    MY_MEQL, //    *=
    MY_SEQL, //    -=
    MY_PEQL, //    +=
    MY_NEQL, //    !=
    MY_OR,   //    ||
    MY_AND,  //    &&
    MY_BORA, //    |=
    MY_BNDA, //    &=
    MY_MDEQ, //    %=
    MY_SUBS, //    []
    MY_FCLL, //    ()
    MY_INC,  //    ++
    MY_DEC,  //    --
    MY_SHL,  //    <<
    MY_SHR,  //    >>
    MY_LEQL, //    <=
    MY_GEQL, //    >=
    MY_IDNT, //    ==
    MY_XORA, //    ^=
    MY_PNTR, //    ->
    MY_SHLA, //    <<=
    MY_SHRA, //    >>=
    MY_SCPE, //    ::
    MY_HHBG, //    #!
    MY_ZT,   //    zt
    MY_ZZ,   //    zz
    MY_ZB,   //    zb
    MY_GUND, //    g_
    MY_GM,   //    gm
    // Mouse Double Click & Triple Click
    // MY_DCLK,
    // MY_TCLK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Workman
     *  ╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
     *  ║ Esc ║  Q  ║  D  ║  R  ║  W  ║  B  ║  J  ║  F  ║  U  ║  P  ║  ;  ║  -  ║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║ Tab ║  A  ║  S  ║  H  ║  T  ║  G  ║  Y  ║  N  ║  E  ║  O  ║  I  ║ Ent ║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║ Sft ║  Z  ║  X  ║  M  ║  C  ║  V  ║  K  ║  L  ║  ,  ║  .  ║  /  ║ Sft ║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║ Ctl ║ Alt ║ GUI ║ F_A ║ F_B ║ Bsp ║ Spc ║ F_C ║ F_D ║ GUI ║ Alt ║ Ctl ║
     *  ╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
     */
    [LY_0000] = {
        {KC_ESC,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_MINS},
        {KC_TAB,  KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_ENT },
        {KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
        {KC_LCTL, KC_LALT, KC_LGUI, FN_A,    FN_B,    KC_BSPC, KC_SPC,  FN_C,    FN_D,    KC_RGUI, KC_RALT, KC_RCTL}
    },
    /* Dual and Trial C-code Operators
     *
     *  ╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
     *  ║ <<= ║ &=  ║ &&  ║ ||  ║ |=  ║ #!  ║ []  ║ ()  ║ -=  ║ *=  ║ ->  ║ >>= ║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║ ^=  ║ <=  ║ !=  ║ ==  ║ >=  ║ <<  ║ >>  ║ ++  ║ --  ║ +=  ║ /=  ║ %=  ║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║     ║xxxxx║xxxxx║xxxxx║xxxxx║ ::  ║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║     ║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║
     *  ╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
     */
    [LY_0001] = {
        {MY_SHLA, MY_BNDA, MY_AND,  MY_OR,   MY_BORA, MY_HHBG, MY_SUBS, MY_FCLL, MY_SEQL, MY_MEQL, MY_PNTR, MY_SHRA},
        {MY_XORA, MY_LEQL, MY_NEQL, MY_IDNT, MY_GEQL, MY_SHL,  MY_SHR,  MY_INC,  MY_DEC,  MY_PEQL, MY_DEQL, MY_MDEQ},
        {_______, ___X___, ___X___, ___X___, ___X___, MY_SCPE, ___X___, ___X___, ___X___, ___X___, ___X___, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
    },
    /* Numbers & Symbols & Basic Navigation
     *
     * ╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
     * ║  `  ║  1  ║  2  ║  3  ║  4  ║  5  ║  6  ║  7  ║  8  ║  9  ║  0  ║  =  ║
     * ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     * ║  '  ║Home ║PgUp ║PgDn ║ End ║  [  ║  ]  ║Left ║Down ║ Up  ║Right║  \  ║
     * ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     * ║     ║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║     ║
     * ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     * ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║
     * ╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
     */
    [LY_0010] = {
        {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL },
        {KC_QUOT, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS},
        {_______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
    },
    [LY_0011] = UNUSED_LAYER
    /* Functions & Media keys & Miscellanious Toggles and Forward Delete
     *
     *  ╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
     *  ║xxxxx║ F1  ║ F2  ║ F3  ║ F4  ║Prev ║Next ║ F13 ║ F14 ║ F15 ║ F16 ║ Del ║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║CapLk║ F5  ║ F6  ║ F7  ║ F8  ║Mute ║Play ║ F17 ║ F18 ║ F19 ║ F20 ║ Ins ║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║     ║ F9  ║ F10 ║ F11 ║ F12 ║Vol- ║Vol+ ║ F21 ║ F22 ║ F23 ║ F24 ║     ║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║
     *  ╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
     */
    [LY_0100] = {
        {___X___, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_MPRV, KC_MNXT, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_DEL },
        {KC_CAPS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_MUTE, KC_MPLY, KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_CAPS},
        {_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_VOLD, KC_VOLU, KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
    },
    [LY_0101] = UNUSED_LAYER // Web Browser
    [LY_0110] = UNUSED_LAYER
    [LY_0111] = UNUSED_LAYER
    [LY_1000] = UNUSED_LAYER // Calculator
    [LY_1001] = UNUSED_LAYER // i3
    [LY_1010] = UNUSED_LAYER
    [LY_1011] = UNUSED_LAYER
    [LY_1100] = UNUSED_LAYER
    [LY_1101] = UNUSED_LAYER
    [LY_1110] = UNUSED_LAYER
    /* Keyboard System Layer
     *
     * ╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
     * ║Reset║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║
     * ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     * ║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║
     * ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     * ║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║
     * ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     * ║xxxxx║xxxxx║xxxxx║     ║     ║xxxxx║xxxxx║     ║     ║xxxxx║xxxxx║xxxxx║
     * ╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
     */
    [LY_1111] = {
        {RESET,   ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___},
        {___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___},
        {___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___},
        {___X___, ___X___, ___X___, _______, _______, ___X___, ___X___, _______, _______, ___X___, ___X___, ___X___}
    },
};

#ifdef AUDIO_ENABLE
float tone_startup[][2]    = SONG(STARTUP_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
float tone_goodbye[][2]    = SONG(GOODBYE_SOUND);
#endif

void startup_user() {
    _delay_ms(20); // gets rid of tick
    set_unicode_input_mode(UC_LNX);
#ifdef AUDIO_ENABLE
    PLAY_SONG(tone_startup);
#endif
}

void shutdown_user() {
#ifdef AUDIO_ENABLE
    PLAY_SONG(tone_goodbye);
    _delay_ms(150);
    stop_all_notes();
#endif
}

/* void double_click(uint16_t key) { */
/*     int i, max = 1; */
/*     for (i = 0; i <= max; i++) { */
/*         register_code(key); */
/*         unregister_code(key); */
/*     } */
/* } */

/* void triple_click(uint16_t key) { */
/*     int i, max = 2; */
/*     for (i = 0; i <= max; i++) { */
/*         register_code(key); */
/*         unregister_code(key); */
/*     } */
/* } */

uint16_t cur_layer_code = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint16_t mask = 1 << (3 - (keycode - FN_A));
    if(FN_A <= keycode && keycode <= FN_D) {
        if(!(cur_layer_code & mask) == record->event.pressed) {
            layer_off(cur_layer_code + LY_0000);
            cur_layer_code ^= mask;
            layer_on(cur_layer_code + LY_0000);
        }
        return false;
    }
    switch(keycode) {
        case MY_DEQL:
            if (record->event.pressed) {
                SEND_STRING("/=");
            }
            return false;
        case MY_MEQL:
            if (record->event.pressed) {
                SEND_STRING("*=");
            }
            return false;
        case MY_SEQL:
            if (record->event.pressed) {
                SEND_STRING("-=");
            }
            return false;
        case MY_PEQL:
            if (record->event.pressed) {
                SEND_STRING("+=");
            }
            return false;
        case MY_NEQL:
            if (record->event.pressed) {
                SEND_STRING("!=");
            }
            return false;
        case MY_OR:
            if (record->event.pressed) {
                SEND_STRING("||");
            }
            return false;
        case MY_AND:
            if (record->event.pressed) {
                SEND_STRING("&&");
            }
            return false;
        case MY_BORA:
            if (record->event.pressed) {
                SEND_STRING("|=");
            }
            return false;
        case MY_BNDA:
            if (record->event.pressed) {
                SEND_STRING("&=");
            }
            return false;
        case MY_MDEQ:
            if (record->event.pressed) {
                SEND_STRING("%=");
            }
            return false;
        case MY_SUBS:
            if (record->event.pressed) {
                SEND_STRING("[]");
            }
            return false;
        case MY_FCLL:
            if (record->event.pressed) {
                SEND_STRING("()");
            }
            return false;
        case MY_INC:
            if (record->event.pressed) {
                SEND_STRING("++");
            }
            return false;
        case MY_DEC:
            if (record->event.pressed) {
                SEND_STRING("--");
            }
            return false;
        case MY_SHL:
            if (record->event.pressed) {
                SEND_STRING("<<");
            }
            return false;
        case MY_SHR:
            if (record->event.pressed) {
                SEND_STRING(">>");
            }
            return false;
        case MY_LEQL:
            if (record->event.pressed) {
                SEND_STRING("<=");
            }
            return false;
        case MY_GEQL:
            if (record->event.pressed) {
                SEND_STRING(">=");
            }
            return false;
        case MY_IDNT:
            if (record->event.pressed) {
                SEND_STRING("==");
            }
            return false;
        case MY_XORA:
            if (record->event.pressed) {
                SEND_STRING("^=");
            }
            return false;
        case MY_HHBG:
            if (record->event.pressed) {
                SEND_STRING("#!");
            }
            return false;
        case MY_PNTR:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
        case MY_SHLA:
            if (record->event.pressed) {
                SEND_STRING("<<=");
            }
            return false;
        case MY_SHRA:
            if (record->event.pressed) {
                SEND_STRING(">>=");
            }
            return false;
        case MY_SCPE:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            return false;
        /* case MY_ZT: */
        /*     if (record->event.pressed) { */
        /*         SEND_STRING("zt"); */
        /*     } */
        /*     return false; */
        /* case MY_ZZ: */
        /*     if (record->event.pressed) { */
        /*         SEND_STRING("zz"); */
        /*     } */
        /*     return false; */
        /* case MY_ZB: */
        /*     if (record->event.pressed) { */
        /*         SEND_STRING("zb"); */
        /*     } */
        /*     return false; */
        /* case MY_GUND: */
        /*     if (record->event.pressed) { */
        /*         SEND_STRING("g_"); */
        /*     } */
        /*     return false; */
        /* case MY_GM: */
        /*     if (record->event.pressed) { */
        /*         SEND_STRING("gm"); */
        /*     } */
        /*     return false; */
        /* case MY_DCLK: */
        /*     if (record->event.pressed) { */
        /*         double_click(KC_BTN1); */
        /*     } */
        /*     return false; */
        /* case MY_TCLK: */
        /*     if (record->event.pressed) { */
        /*         triple_click(KC_BTN1); */
        /*     } */
        /*     return false; */
    }
    return true;
}
