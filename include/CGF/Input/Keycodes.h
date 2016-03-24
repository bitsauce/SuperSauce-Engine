/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2014 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

/**
 *  \file CGF_keycode.h
 *
 *  Defines constants which identify keyboard keys and modifiers.
 */
#ifndef CGF_KEYCODES_H
#define CGF_KEYCODES_H

#include <CGF/Config.h>
#include "Scancodes.h"

BEGIN_CGF_NAMESPACE

/**
 *  \brief The SDL virtual key representation.
 *
 *  Values of this type are used to represent keyboard keys using the current
 *  layout of the keyboard.  These values include Unicode values representing
 *  the unmodified character that would be generated by pressing the key, or
 *  an CGF_KEY_* constant for those keys that do not generate characters.
 */

#define CGF_KEY_SCANCODE_MASK (1<<30)
#define CGF_SCANCODE_TO_KEYCODE(X)  (X | CGF_KEY_SCANCODE_MASK)

enum Keycode
{
    CGF_KEY_UNKNOWN = 0,

    CGF_KEY_RETURN = '\r',
    CGF_KEY_ESCAPE = '\033',
    CGF_KEY_BACKSPACE = '\b',
    CGF_KEY_TAB = '\t',
    CGF_KEY_SPACE = ' ',
    CGF_KEY_EXCLAIM = '!',
    CGF_KEY_QUOTEDBL = '"',
    CGF_KEY_HASH = '#',
    CGF_KEY_PERCENT = '%',
    CGF_KEY_DOLLAR = '$',
    CGF_KEY_AMPERSAND = '&',
    CGF_KEY_QUOTE = '\'',
    CGF_KEY_LEFTPAREN = '(',
    CGF_KEY_RIGHTPAREN = ')',
    CGF_KEY_ASTERISK = '*',
    CGF_KEY_PLUS = '+',
    CGF_KEY_COMMA = ',',
    CGF_KEY_MINUS = '-',
    CGF_KEY_PERIOD = '.',
    CGF_KEY_SLASH = '/',
    CGF_KEY_0 = '0',
    CGF_KEY_1 = '1',
    CGF_KEY_2 = '2',
    CGF_KEY_3 = '3',
    CGF_KEY_4 = '4',
    CGF_KEY_5 = '5',
    CGF_KEY_6 = '6',
    CGF_KEY_7 = '7',
    CGF_KEY_8 = '8',
    CGF_KEY_9 = '9',
    CGF_KEY_COLON = ':',
    CGF_KEY_SEMICOLON = ';',
    CGF_KEY_LESS = '<',
    CGF_KEY_EQUALS = '=',
    CGF_KEY_GREATER = '>',
    CGF_KEY_QUESTION = '?',
    CGF_KEY_AT = '@',
    /*
       Skip uppercase letters
     */
    CGF_KEY_LEFTBRACKET = '[',
    CGF_KEY_BACKSLASH = '\\',
    CGF_KEY_RIGHTBRACKET = ']',
    CGF_KEY_CARET = '^',
    CGF_KEY_UNDERSCORE = '_',
    CGF_KEY_BACKQUOTE = '`',
    CGF_KEY_A = 'a',
    CGF_KEY_B = 'b',
    CGF_KEY_C = 'c',
    CGF_KEY_D = 'd',
    CGF_KEY_E = 'e',
    CGF_KEY_F = 'f',
    CGF_KEY_G = 'g',
    CGF_KEY_H = 'h',
    CGF_KEY_I = 'i',
    CGF_KEY_J = 'j',
    CGF_KEY_K = 'k',
    CGF_KEY_L = 'l',
    CGF_KEY_M = 'm',
    CGF_KEY_N = 'n',
    CGF_KEY_O = 'o',
    CGF_KEY_P = 'p',
    CGF_KEY_Q = 'q',
    CGF_KEY_R = 'r',
    CGF_KEY_S = 's',
    CGF_KEY_T = 't',
    CGF_KEY_U = 'u',
    CGF_KEY_V = 'v',
    CGF_KEY_W = 'w',
    CGF_KEY_X = 'x',
    CGF_KEY_Y = 'y',
    CGF_KEY_Z = 'z',

    CGF_KEY_CAPSLOCK = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_CAPSLOCK),

    CGF_KEY_F1 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F1),
    CGF_KEY_F2 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F2),
    CGF_KEY_F3 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F3),
    CGF_KEY_F4 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F4),
    CGF_KEY_F5 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F5),
    CGF_KEY_F6 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F6),
    CGF_KEY_F7 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F7),
    CGF_KEY_F8 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F8),
    CGF_KEY_F9 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F9),
    CGF_KEY_F10 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F10),
    CGF_KEY_F11 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F11),
    CGF_KEY_F12 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F12),

    CGF_KEY_PRINTSCREEN = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_PRINTSCREEN),
    CGF_KEY_SCROLLLOCK = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_SCROLLLOCK),
    CGF_KEY_PAUSE = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_PAUSE),
    CGF_KEY_INSERT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_INSERT),
    CGF_KEY_HOME = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_HOME),
    CGF_KEY_PAGEUP = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_PAGEUP),
    CGF_KEY_DELETE = '\177',
    CGF_KEY_END = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_END),
    CGF_KEY_PAGEDOWN = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_PAGEDOWN),
    CGF_KEY_RIGHT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_RIGHT),
    CGF_KEY_LEFT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_LEFT),
    CGF_KEY_DOWN = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_DOWN),
    CGF_KEY_UP = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_UP),

    CGF_KEY_NUMLOCKCLEAR = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_NUMLOCKCLEAR),
    CGF_KEY_KP_DIVIDE = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_DIVIDE),
    CGF_KEY_KP_MULTIPLY = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_MULTIPLY),
    CGF_KEY_KP_MINUS = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_MINUS),
    CGF_KEY_KP_PLUS = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_PLUS),
    CGF_KEY_KP_ENTER = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_ENTER),
    CGF_KEY_KP_1 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_1),
    CGF_KEY_KP_2 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_2),
    CGF_KEY_KP_3 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_3),
    CGF_KEY_KP_4 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_4),
    CGF_KEY_KP_5 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_5),
    CGF_KEY_KP_6 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_6),
    CGF_KEY_KP_7 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_7),
    CGF_KEY_KP_8 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_8),
    CGF_KEY_KP_9 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_9),
    CGF_KEY_KP_0 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_0),
    CGF_KEY_KP_PERIOD = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_PERIOD),

    CGF_KEY_APPLICATION = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_APPLICATION),
    CGF_KEY_POWER = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_POWER),
    CGF_KEY_KP_EQUALS = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_EQUALS),
    CGF_KEY_F13 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F13),
    CGF_KEY_F14 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F14),
    CGF_KEY_F15 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F15),
    CGF_KEY_F16 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F16),
    CGF_KEY_F17 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F17),
    CGF_KEY_F18 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F18),
    CGF_KEY_F19 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F19),
    CGF_KEY_F20 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F20),
    CGF_KEY_F21 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F21),
    CGF_KEY_F22 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F22),
    CGF_KEY_F23 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F23),
    CGF_KEY_F24 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_F24),
    CGF_KEY_EXECUTE = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_EXECUTE),
    CGF_KEY_HELP = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_HELP),
    CGF_KEY_MENU = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_MENU),
    CGF_KEY_SELECT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_SELECT),
    CGF_KEY_STOP = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_STOP),
    CGF_KEY_AGAIN = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_AGAIN),
    CGF_KEY_UNDO = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_UNDO),
    CGF_KEY_CUT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_CUT),
    CGF_KEY_COPY = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_COPY),
    CGF_KEY_PASTE = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_PASTE),
    CGF_KEY_FIND = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_FIND),
    CGF_KEY_MUTE = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_MUTE),
    CGF_KEY_VOLUMEUP = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_VOLUMEUP),
    CGF_KEY_VOLUMEDOWN = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_VOLUMEDOWN),
    CGF_KEY_KP_COMMA = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_COMMA),
    CGF_KEY_KP_EQUALSAS400 =
        CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_EQUALSAS400),

    CGF_KEY_ALTERASE = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_ALTERASE),
    CGF_KEY_SYSREQ = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_SYSREQ),
    CGF_KEY_CANCEL = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_CANCEL),
    CGF_KEY_CLEAR = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_CLEAR),
    CGF_KEY_PRIOR = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_PRIOR),
    CGF_KEY_RETURN2 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_RETURN2),
    CGF_KEY_SEPARATOR = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_SEPARATOR),
    CGF_KEY_OUT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_OUT),
    CGF_KEY_OPER = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_OPER),
    CGF_KEY_CLEARAGAIN = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_CLEARAGAIN),
    CGF_KEY_CRSEL = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_CRSEL),
    CGF_KEY_EXSEL = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_EXSEL),

    CGF_KEY_KP_00 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_00),
    CGF_KEY_KP_000 = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_000),
    CGF_KEY_THOUSANDSSEPARATOR =
        CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_THOUSANDSSEPARATOR),
    CGF_KEY_DECIMALSEPARATOR =
        CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_DECIMALSEPARATOR),
    CGF_KEY_CURRENCYUNIT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_CURRENCYUNIT),
    CGF_KEY_CURRENCYSUBUNIT =
        CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_CURRENCYSUBUNIT),
    CGF_KEY_KP_LEFTPAREN = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_LEFTPAREN),
    CGF_KEY_KP_RIGHTPAREN = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_RIGHTPAREN),
    CGF_KEY_KP_LEFTBRACE = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_LEFTBRACE),
    CGF_KEY_KP_RIGHTBRACE = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_RIGHTBRACE),
    CGF_KEY_KP_TAB = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_TAB),
    CGF_KEY_KP_BACKSPACE = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_BACKSPACE),
    CGF_KEY_KP_A = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_A),
    CGF_KEY_KP_B = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_B),
    CGF_KEY_KP_C = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_C),
    CGF_KEY_KP_D = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_D),
    CGF_KEY_KP_E = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_E),
    CGF_KEY_KP_F = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_F),
    CGF_KEY_KP_XOR = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_XOR),
    CGF_KEY_KP_POWER = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_POWER),
    CGF_KEY_KP_PERCENT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_PERCENT),
    CGF_KEY_KP_LESS = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_LESS),
    CGF_KEY_KP_GREATER = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_GREATER),
    CGF_KEY_KP_AMPERSAND = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_AMPERSAND),
    CGF_KEY_KP_DBLAMPERSAND =
        CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_DBLAMPERSAND),
    CGF_KEY_KP_VERTICALBAR =
        CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_VERTICALBAR),
    CGF_KEY_KP_DBLVERTICALBAR =
        CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_DBLVERTICALBAR),
    CGF_KEY_KP_COLON = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_COLON),
    CGF_KEY_KP_HASH = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_HASH),
    CGF_KEY_KP_SPACE = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_SPACE),
    CGF_KEY_KP_AT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_AT),
    CGF_KEY_KP_EXCLAM = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_EXCLAM),
    CGF_KEY_KP_MEMSTORE = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_MEMSTORE),
    CGF_KEY_KP_MEMRECALL = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_MEMRECALL),
    CGF_KEY_KP_MEMCLEAR = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_MEMCLEAR),
    CGF_KEY_KP_MEMADD = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_MEMADD),
    CGF_KP_MEMSUBTRACT =
        CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_MEMSUBTRACT),
    CGF_KEY_KP_MEMMULTIPLY =
        CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_MEMMULTIPLY),
    CGF_KEY_KP_MEMDIVIDE = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_MEMDIVIDE),
    CGF_KEY_KP_PLUSMINUS = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_PLUSMINUS),
    CGF_KEY_KP_CLEAR = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_CLEAR),
    CGF_KEY_KP_CLEARENTRY = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_CLEARENTRY),
    CGF_KEY_KP_BINARY = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_BINARY),
    CGF_KEY_KP_OCTAL = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_OCTAL),
    CGF_KEY_KP_DECIMAL = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_DECIMAL),
    CGF_KEY_KP_HEXADECIMAL =
        CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KP_HEXADECIMAL),

    CGF_KEY_LCTRL = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_LCTRL),
    CGF_KEY_LSHIFT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_LSHIFT),
    CGF_KEY_LALT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_LALT),
    CGF_KEY_LGUI = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_LGUI),
    CGF_KEY_RCTRL = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_RCTRL),
    CGF_KEY_RSHIFT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_RSHIFT),
    CGF_KEY_RALT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_RALT),
    CGF_KEY_RGUI = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_RGUI),

    CGF_KEY_MODE = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_MODE),

    CGF_KEY_AUDIONEXT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_AUDIONEXT),
    CGF_KEY_AUDIOPREV = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_AUDIOPREV),
    CGF_KEY_AUDIOSTOP = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_AUDIOSTOP),
    CGF_KEY_AUDIOPLAY = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_AUDIOPLAY),
    CGF_KEY_AUDIOMUTE = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_AUDIOMUTE),
    CGF_KEY_MEDIASELECT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_MEDIASELECT),
    CGF_KEY_WWW = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_WWW),
    CGF_KEY_MAIL = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_MAIL),
    CGF_KEY_CALCULATOR = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_CALCULATOR),
    CGF_KEY_COMPUTER = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_COMPUTER),
    CGF_KEY_AC_SEARCH = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_AC_SEARCH),
    CGF_KEY_AC_HOME = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_AC_HOME),
    CGF_KEY_AC_BACK = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_AC_BACK),
    CGF_KEY_AC_FORWARD = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_AC_FORWARD),
    CGF_KEY_AC_STOP = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_AC_STOP),
    CGF_KEY_AC_REFRESH = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_AC_REFRESH),
    CGF_KEY_AC_BOOKMARKS = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_AC_BOOKMARKS),

    CGF_KEY_BRIGHTNESSDOWN =
        CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_BRIGHTNESSDOWN),
    CGF_KEY_BRIGHTNESSUP = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_BRIGHTNESSUP),
    CGF_KEY_DISPLAYSWITCH = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_DISPLAYSWITCH),
    CGF_KEY_KBDILLUMTOGGLE =
        CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KBDILLUMTOGGLE),
    CGF_KEY_KBDILLUMDOWN = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KBDILLUMDOWN),
    CGF_KEY_KBDILLUMUP = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_KBDILLUMUP),
    CGF_KEY_EJECT = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_EJECT),
    CGF_KEY_SLEEP = CGF_SCANCODE_TO_KEYCODE(CGF_SCANCODE_SLEEP)
};


enum MouseButton
{
	CGF_MOUSE_BUTTON_NONE = 0,
	CGF_MOUSE_BUTTON_LEFT = SDL_BUTTON_LEFT,
	CGF_MOUSE_BUTTON_MIDDLE = SDL_BUTTON_MIDDLE,
	CGF_MOUSE_BUTTON_RIGHT = SDL_BUTTON_RIGHT
};

END_CGF_NAMESPACE

/**
 * \brief Enumeration of valid key mods (possibly OR'd together).
 */
/*typedef enum
{
    KMOD_NONE = 0x0000,
    KMOD_LSHIFT = 0x0001,
    KMOD_RSHIFT = 0x0002,
    KMOD_LCTRL = 0x0040,
    KMOD_RCTRL = 0x0080,
    KMOD_LALT = 0x0100,
    KMOD_RALT = 0x0200,
    KMOD_LGUI = 0x0400,
    KMOD_RGUI = 0x0800,
    KMOD_NUM = 0x1000,
    KMOD_CAPS = 0x2000,
    KMOD_MODE = 0x4000,
    KMOD_RESERVED = 0x8000
} CGF_Keymod;

#define KMOD_CTRL   (KMOD_LCTRL|KMOD_RCTRL)
#define KMOD_SHIFT  (KMOD_LSHIFT|KMOD_RSHIFT)
#define KMOD_ALT    (KMOD_LALT|KMOD_RALT)
#define KMOD_GUI    (KMOD_LGUI|KMOD_RGUI)*/

#endif /* CGF_KEYCODES_H */