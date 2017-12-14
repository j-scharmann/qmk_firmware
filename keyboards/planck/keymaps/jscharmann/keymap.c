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
#define MY_CLHM  LCTL(KC_HOME)
#define MY_CLED  LCTL(KC_END)

enum my_layers {
    LY_0000, LY_0001, LY_0010, LY_0011,
    LY_0100, LY_0101, LY_0110, LY_0111,
    LY_1000, LY_1001, LY_1010, LY_1011,
    LY_1100, LY_1101, LY_1110, LY_1111,
}

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
    MY_DCLK,
    MY_TCLK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Workman
     *  ╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
     *  ║ Esc ║  Q  ║  D  ║  R  ║  W  ║  B  ║  J  ║  F  ║  U  ║  P  ║  ;  ║ Bsp ║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║ Tab ║  A  ║  S  ║  H  ║  T  ║  G  ║  Y  ║  N  ║  E  ║  O  ║  I  ║ Ent ║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║  '  ║  Z  ║  X  ║  M  ║  C  ║  V  ║  K  ║  L  ║  ,  ║  .  ║  /  ║  -  ║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║ Ctl ║ GUI ║ Alt ║ F_A ║ F_B ║ Sft ║ Spc ║ F_C ║ F_D ║ Alt ║ GUI ║ Ctl ║
     *  ╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
     */
    [LY_0000] = {
        {KC_ESC,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_BSPC},
        {KC_TAB,  KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_ENT },
        {KC_QUOT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS},
        {KC_LCTL, KC_LGUI, KC_LALT, FN_A,    FN_B,    KC_LSFT, KC_SPC,  FN_C,    FN_D,    KC_RALT, KC_RGUI, KC_RCTL}
    },
    /* Function Layer
     *
     * ╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
     * ║xxxxx║ F1  ║ F2  ║ F3  ║ F4  ║xxxxx║xxxxx║ F13 ║ F14 ║ F15 ║ F16 ║xxxxx║
     * ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     * ║xxxxx║ F5  ║ F6  ║ F7  ║ F8  ║xxxxx║xxxxx║ F17 ║ F18 ║ F19 ║ F20 ║xxxxx║
     * ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     * ║xxxxx║ F9  ║ F10 ║ F11 ║ F12 ║xxxxx║xxxxx║ F21 ║ F22 ║ F23 ║ F24 ║xxxxx║
     * ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     * ║     ║     ║     ║     ║     ║     ║xxxxx║     ║     ║     ║     ║     ║
     * ╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
     */
    [LY_0001] = {
        {___X___, KC_F1,   KC_F2,   KC_F3,   KC_F4,   ___X___, ___X___, KC_F13,  MY_F14,  MY_F15,  KC_F16,  ___X___},
        {___X___, KC_F5,   KC_F6,   KC_F7,   KC_F8,   ___X___, ___X___, KC_F17,  KC_F18,  KC_F19,  KC_F20,  ___X___},
        {___X___, KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___X___, ___X___, KC_F21,  KC_F22,  KC_F23,  MY_F24,  ___X___},
        {_______, _______, _______, _______, _______, _______, ___X___, _______, _______, _______, _______, _______}
    },
    /* Navigation Layer (zt, zb, zz, ^, g_, and gm are used in Vim; Ctrl-Home same as 'gg' and Ctrl-End same as 'G'
     * in Vim.
     *
     * ╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
     * ║xxxxx║xxxxx║SrlUp║ MUp ║SrlDn║xxxxx║ zt  ║Home ║ClHme║ClEnd║ End ║xxxxx║
     * ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     * ║xxxxx║DClk ║ MLt ║ MDn ║ MRt ║TClk ║ zz  ║Left ║Down ║ Up  ║Right║ gm  ║
     * ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     * ║xxxxx║xxxxx║ Bn2 ║ Bn3 ║ Bn1 ║xxxxx║ zb  ║  ^  ║PgUp ║PgDn ║ g_  ║xxxxx║
     * ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     * ║xxxxx║xxxxx║xxxxx║     ║     ║     ║xxxxx║     ║     ║xxxxx║xxxxx║xxxxx║
     * ╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
     */
    [LY_0010] = {
        {___X___, ___X___, KC_MW_U, KC_MS_U, KC_MW_D, ___X___, MY_ZT,   KC_HOME, MY_CLHM, MY_CLED, KC_END,  ___X___},
        {___X___, MY_DCLK, KC_MS_L, KC_MS_D, KC_MS_R, MY_TCLK, MY_ZZ,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, MY_GM  },
        {___X___, ___X___, KC_BTN2, KC_BTN3, KC_BTN1, ___X___, MY_ZB,   KC_CIRC, KC_PGUP, KC_PGDN, MY_GUND, ___X___},
        {___X___, ___X___, ___X___, _______, _______, _______, ___X___, _______, _______, ___X___, ___X___, ___X___}
    },
    [LY_0011] = UNUSED_LAYER,
    /* Symbols and Numbers
     *  ╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
     *  ║xxxxx║  %  ║  &  ║  ?  ║  +  ║  @  ║  $  ║  #  ║  [  ║  ]  ║  !  ║ Del ║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║  `  ║  /  ║  (  ║  =  ║  0  ║  {  ║  }  ║  1  ║  *  ║  )  ║  ^  ║Caps ║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║  ~  ║  6  ║  7  ║  8  ║  9  ║  |  ║  \  ║  2  ║  3  ║  4  ║  5  ║xxxxx║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║     ║     ║     ║     ║     ║xxxxx║     ║     ║     ║     ║     ║     ║
     *  ╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
     */
    [LY_0100] = {
        {___X___, KC_PERC, KC_AMPR, KC_QUES, KC_PLUS, KC_AT,   KC_DLR,  KC_HASH, KC_LBRC, KC_RBRC, KC_EXLM, KC_DEL },
        {KC_GRV,  KC_SLSH, KC_LPRN, KC_EQL,  KC_0,    KC_LCBR, KC_LCBR, KC_1,    KC_ASTR, KC_RPRN, KC_CIRC, KC_CAPS},
        {KC_TILD, KC_6,    KC_7,    KC_8,    KC_9,    KC_PIPE, KC_BSLS, KC_2,    KC_3,    KC_4,    KC_5,    ___X___},
        {_______, _______, _______, _______, _______, ___X___, _______, _______, _______, _______, _______, _______}
    },
    [LY_0101] = UNUSED_LAYER, // Web Browser
    /* Dual and Trial C-code Operators
     *  ╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
     *  ║xxxxx║xxxxx║ &&  ║ ||  ║ |=  ║ #!  ║ []  ║ ()  ║ -=  ║ *=  ║xxxxx║xxxxx║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║xxxxx║ <=  ║ !=  ║ ==  ║ >=  ║ <<  ║ >>  ║ ++  ║ --  ║ +=  ║ /=  ║xxxxx║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║xxxxx║xxxxx║xxxxx║ ->  ║ ::  ║ <<= ║ >>= ║ %=  ║ &=  ║ ^=  ║xxxxx║xxxxx║
     *  ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     *  ║xxxxx║xxxxx║xxxxx║     ║     ║xxxxx║xxxxx║     ║     ║xxxxx║xxxxx║xxxxx║
     *  ╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
     */
    [LY_0110] = {
        {___X___, ___X___, MY_AND,  MY_OR,   MY_BORA, MY_HHBG, MY_SUBS, MY_FCLL, MY_SEQL, MY_MEQL, ___X___, ___X___},
        {___X___, MY_LEQL, MY_NEQL, MY_IDNT, MY_GEQL, MY_SHL,  MY_SHR,  MY_INC,  MY_DEC,  MY_PEQL, MY_DEQL, ___X___},
        {___X___, ___X___, ___X___, MY_PNTR, MY_SCPE, MY_SHLA, MY_SHRA, MY_MDEQ, MY_BNDA, MY_XORA, ___X___, ___X___},
        {___X___, ___X___, ___X___, _______, _______, ___X___, ___X___, _______, _______, ___X___, ___X___, ___X___}
    },
    [LY_0111] = UNUSED_LAYER,
    [LY_1000] = UNUSED_LAYER, // Calculator
    [LY_1001] = UNUSED_LAYER, // i3
    [LY_1010] = UNUSED_LAYER,
    [LY_1011] = UNUSED_LAYER,
    [LY_1100] = UNUSED_LAYER,
    [LY_1101] = UNUSED_LAYER,
    [LY_1110] = UNUSED_LAYER,
    /* Keyboard System Layer
     *
     * ╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
     * ║xxxxx║ T0  ║ T1  ║ T2  ║ T3  ║AudOn║AdOff║ T8  ║ T9  ║ T10 ║ T11 ║Reset║
     * ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     * ║xxxxx║ T4  ║ T5  ║ T6  ║ T7  ║MusOn║MsOff║ T12 ║ T13 ║ T14 ║ T15 ║xxxxx║
     * ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     * ║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║Vce -║Vce +║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║
     * ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
     * ║xxxxx║xxxxx║xxxxx║     ║     ║xxxxx║xxxxx║     ║     ║xxxxx║xxxxx║xxxxx║
     * ╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
     */
    [LY_1111] = {
        {___X___,TG(LY_0000),TG(LY_0001),TG(LY_0010),TG(LY_0011),AU_ON,  AU_OFF, TG(LY_1000),TG(LY_1001),TG(LY_1010),TG(LY_1011),RESET  },
        {___X___,TG(LY_0100),TG(LY_0101),TG(LY_0110),TG(LY_0111),MU_ON,  MU_OFF, TG(LY_1100),TG(LY_1101),TG(LY_1110),TG(LY_1111),___X___},
        {___X___,___X___,    ___X___,    ___X___,    ___X___,    MUV_DE, MUV_IN, ___X___,    ___X___,    ___X___,    ___X___,    ___X___},
        {___X___,___X___,    ___X___,    _______,    _______,    ___X___,___X___,_______,    _______,    ___X___,    ___X___,    ___X___}
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

void double_click(uint16_t key) {
    int i, max = 1;
    for (i = 0; i <= max; i++) {
        register_code(key);
        unregister_code(key);
    }
}

void triple_click(uint16_t key) {
    int i, max = 2;
    for (i = 0; i <= max; i++) {
        register_code(key);
        unregister_code(key);
    }
}

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
                SEND_STRING(">=");
            }
            return false;
        case MY_GEQL:
            if (record->event.pressed) {
                SEND_STRING("<=");
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
        case MY_ZT:
            if (record->event.pressed) {
                SEND_STRING("zt");
            }
            return false;
        case MY_ZZ:
            if (record->event.pressed) {
                SEND_STRING("zz");
            }
            return false;
        case MY_ZB:
            if (record->event.pressed) {
                SEND_STRING("zb");
            }
            return false;
        case MY_GUND:
            if (record->event.pressed) {
                SEND_STRING("g_");
            }
            return false;
        case MY_GM:
            if (record->event.pressed) {
                SEND_STRING("gm");
            }
            return false;
        case MY_DCLK:
            if (record->event.pressed) {
                double_click(KC_BTN1);
            }
            return false;
        case MY_TCLICK:
            if (record->event.pressed) {
                triple_click(KC_BTN1);
            }
            return false;
    }
    return true;
}
