#include QMK_KEYBOARD_H
// Layer names
#define _COLEMAK 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3
// Layer colours, in HSV (255 is max)
#define HSV_QWERTY 14, 255, 50
#define HSV_LOWER 11, 176, 50
#define HSV_RAISE 30, 218, 50
#define HSV_SDPINK 240, 255, 50
#define HSV_SDPURPLE 200, 255, 50
#define HSV_SDBLUE 130, 255, 50
// Shorthand, for longer key names that break my delicate, beautiful grid
#define SPC_LT3 LT(3,KC_SPC)          // Space on press, layer 3 on hold
#define ENT_ALT MT(MOD_LALT,KC_ENT)   // Enter on press, Left Alt on hold
#define SFT_CAP TD(SHIFT_CAPS)        // Caps on double press, shift on hold
#define PRTSCR  KC_PSCREEN            // Print Screen
#define OSM_CTL OSM(MOD_LCTL)         // One shot LCTR
#define OSM_GUI OSM(MOD_LGUI)         // One shot LGUI
#define OSM_ALT OSM(MOD_LALT)         // One shot LALT
enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
};

// Tap Dance declarations
enum {
    SHIFT_CAPS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Shift, twice for Caps Lock
    // TODO: change this to tap once for oneshot shift, quad tap for caps
   [SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

// KAT Space Dust pattern, for colemak layer
const rgblight_segment_t PROGMEM colemak_layer[] = RGBLIGHT_LAYER_SEGMENTS(
   // Left half, rotating from top right to bottom right counterclockwise.
    {0, 1, HSV_SDPURPLE}, //
    {1, 3, HSV_SDPINK},
    {4, 1, HSV_SDPURPLE},
    {5, 1, HSV_SDBLUE}, 
   // Right half, rotating from bottom left to top left counterclockwise. 
    {6, 6, HSV_SDBLUE}
    );

// KAT Space Dust pattern (inverted), for qwerty layer
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_SDPURPLE},
    {1, 3, HSV_SDBLUE},
    {4, 1, HSV_SDPURPLE},
    {5, 1, HSV_SDPINK},
    {6, 6, HSV_SDPINK}
);
// Caps lock indicator
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 3, HSV_SDPURPLE},
    {6, 3, HSV_SDPURPLE}
);

// Lower layer indicator
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_SDBLUE}
);
// Raise layer indicator
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_SDPINK}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    colemak_layer,
    capslock_layer,
    lower_layer,
    raise_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //       ┌───────┬───────┬───────┬───────┬───────┬───────┐                       ┌───────┬───────┬───────┬───────┬───────┬───────┐
  //       │ PB 01 │ PB 02 │ PB 03 │ PB 04 │ PB 05 │ PB 06 │                       │ PB 07 │ PB 08 │ PB 09 │ PB 10 │ PB 11 │ PB 12 │
  //       ├───────┼───────┼───────┼───────┼───────┼───────┤                       ├───────┼───────┼───────┼───────┼───────┼───────┤
  //       │  Esc  │   q   │   w   │   f   │   p   │   b   │                       │   j   │   l   │   u   │   y   │   ;   │ QWERTY│
  //       ├───────┼───────┼───────┼───────┼───────┼───────┤                       ├───────┼───────┼───────┼───────┼───────┼───────┤
  //       │  Tab  │   a   │   r   │   s   │   t   │   g   │                       │   m   │   n   │   e   │   i   │   o   │   '   │
  //       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┐       ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  //       │ Ctrl  │   z   │   x   │   c   │   d   │   v   │  Alt  │       │  Del  │   k   │   h   │   ,   │   .   │   /   │LAltEnt│
  //       └───────┴───────┴───────┴───┬───┴───┬───┴───┬───┴───┬───┘       └───┬───┴───┬───┴───┬───┴───┬───┴───────┴───────┴───────┘
  //                                   │  Gui  │Numbers│  Bksp │               │ Space │ Shift │ PrtSc │     
  //                                   └───────┴───────┴───────┘               └───────┴───────┴───────┘        

        PB_1,    PB_2,    PB_3,    PB_4,    PB_5,    PB_6,                           PB_7,    PB_8,    PB_9,    PB_10,   PB_11,   PB_12,
        KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                           KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, DF(1),
        KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                           KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        MOD_LCTL, KC_Z,   KC_X,    KC_C,    KC_D,   KC_V,  MOD_LALT,        KC_DEL, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, ENT_ALT,
                                            MOD_LGUI, OSL(2),KC_BSPC,        SPC_LT3, SFT_CAP, PRTSCR
  ),

  [_QWERTY] = LAYOUT(
  //       ┌───────┬───────┬───────┬───────┬───────┬───────┐                       ┌───────┬───────┬───────┬───────┬───────┬───────┐
  //       │▼PB 01 │▼PB 02 │▼PB 03 │▼PB 04 │▼PB 05 │▼PB 06 │                       │▼PB 07 │▼PB 08 │▼PB 09 │▼PB 10 │▼PB 11 │▼PB 12 │
  //       ├───────┼───────┼───────┼───────┼───────┼───────┤                       ├───────┼───────┼───────┼───────┼───────┼───────┤
  //       │▼ Esc  │   q   │   w   │   e   │   r   │   t   │                       │   y   │   u   │   i   │   o   │   p   │ COLMK │
  //       ├───────┼───────┼───────┼───────┼───────┼───────┤                       ├───────┼───────┼───────┼───────┼───────┼───────┤
  //       │▼ Tab  │   a   │   s   │   d   │   f   │   g   │                       │   h   │   j   │   k   │   l   │   ;   │▼  '   │
  //       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┐       ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  //       │▼Ctrl  │   z   │   x   │   c   │   v   │   b   │▼ Alt  │       │▼ Del  │   n   │   m   │   ,   │   .   │   /   │▼AltEnt│
  //       └───────┴───────┴───────┴───┬───┴───┬───┴───┬───┴───┬───┘       └───┬───┴───┬───┴───┬───┴───┬───┴───────┴───────┴───────┘
  //                                   │▼ Gui  │▼Numbrs│▼ Bksp │               │▼Space │▼Shift │▼PrtSc │
  //                                   └───────┴───────┴───────┘               └───────┴───────┴───────┘

     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, 
     _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    DF(0),
     _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
     _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                         _______, _______, _______,          _______, _______, _______
  ),

  [_LOWER] = LAYOUT(
  //       ┌───────┬───────┬───────┬───────┬───────┬───────┐                       ┌───────┬───────┬───────┬───────┬───────┬───────┐
  //       │  F12  │  F01  │  F02  │  F03  │  F04  │  F05  │                       │  F06  │  F07  │  F08  │  F09  │  F10  │  F11  │
  //       ├───────┼───────┼───────┼───────┼───────┼───────┤                       ├───────┼───────┼───────┼───────┼───────┼───────┤
  //       │▼ Esc  │       │       │   (   │   )   │   -   │                       │   =   │   [   │   ]   │       │       │       │
  //       ├───────┼───────┼───────┼───────┼───────┼───────┤                       ├───────┼───────┼───────┼───────┼───────┼───────┤
  //       │▼ Tab  │   1   │   2   │   3   │   4   │   5   │                       │   6   │   7   │   8   │   9   │   0   │       │
  //       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┐       ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  //       │ Ctrl  │       │       │       │       │   `   │▼ Del  │       │▼ Del  │   \   │   *   │       │       │       │▼AltEnt│
  //       └───────┴───────┴───────┴───┬───┴───┬───┴───┬───┴───┬───┘       └───┬───┴───┬───┴───┬───┴───┬───┴───────┴───────┴───────┘
  //                                   │▼ Gui  │▼Numbrs│▼ Bksp │               │▼Space │▼Shift │▼PrtSc │
  //                                   └───────┴───────┴───────┘               └───────┴───────┴───────┘

     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
     _______, KC_NO,   KC_NO,   KC_LCBR, KC_RCBR, KC_MINS,                            KC_EQL,  KC_LBRC, KC_RBRC, KC_NO,   KC_NO,   KC_NO,    
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
     _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_GRV,  _______,          _______, KC_BSLS, KC_ASTR, KC_NO,   KC_NO,   KC_NO,   _______,
                                         _______, _______, _______,          _______, _______, _______
  ),

  [_RAISE] = LAYOUT(
  //       ┌───────┬───────┬───────┬───────┬───────┬───────┐                       ┌───────┬───────┬───────┬───────┬───────┬───────┐
  //       │       │       │       │       │       │ RESET │                       │EEP RST│       │       │       │       │ AS RP │ (Report autoshift speed)
  //       ├───────┼───────┼───────┼───────┼───────┼───────┤                       ├───────┼───────┼───────┼───────┼───────┼───────┤
  //       │  RGB  │Effect+│ +HUE  │ +SAT  │ +BRT  │ Mode+ │ (RGB mode)            │       │  End  │ PG DN │ PG UP │ Home  │ AS UP │
  //       ├───────┼───────┼───────┼───────┼───────┼───────┤                       ├───────┼───────┼───────┼───────┼───────┼───────┤
  //       │RGBMOD+│Effect-│ -HUE  │ -SAT  │ -BRT  │ Mode- │                       │       │   ←   │   ↓   │   ↑   │   →   │ AS DN │
  //       ├───────┼───────┼───────┼───────┼───────┼───────┼───────┐       ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
  //       │       │       │       │       │       │       │       │       │       │       │       │       │       │       │       │
  //       └───────┴───────┴───────┴───┬───┴───┬───┴───┬───┴───┬───┘       └───┬───┴───┬───┴───┬───┴───┬───┴───────┴───────┴───────┘
  //                                   │       │▼Numbrs│       │               │▼Space │▼Shift │       │
  //                                   └───────┴───────┴───────┘               └───────┴───────┴───────┘
  // TODO: remove left hand colour controls as they don't do anything
  // 	   or alternatively, make them work somehow

     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,                              EEP_RST, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ASRP,   
     RGB_TOG, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,                            KC_NO,   KC_END,  KC_PGDN, KC_PGUP, KC_HOME, KC_ASUP,   
     KC_NO,   RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD,                           KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ASDN,   
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   
                                         KC_NO,   _______, KC_NO,            _______, _______, KC_NO   
  )
};


bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(2, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _COLEMAK));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
//    rgblight_set_layer_state(2, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(4, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
    return state;
}
