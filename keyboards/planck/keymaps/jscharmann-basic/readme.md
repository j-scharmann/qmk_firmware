# Jay's Basic Workman Planck

This is a basic Workman layout I came up with, in case my more complicated
keymap is or was buggy and I needed a usable one to get by with until I solve
or solved the bugs.

## Layer 0 - Workman Layout Base
This layer is the default workman layout that I use.

### Changes from default "basic" layout

#### TAB and Escape swapped
I couldn't get used to the TAB and ESC keys being in the opposite places that
I was used to so I changed them to reflect that.

#### Enter key at same row as Home Row
On all of the keyboards that I have used in my life, regardless if it was
QWERTY, DVORAK, or WORKMAN, the Enter key was always on the home row, and I
found placing it one row below was awkward for me, so I changed it to my
tastes.

#### Modifiers

I must have symmetry where my modifier keys are concerned, so I had to alter
the default structure of the keymap to include the right side modifiers as
well. I have a Planck with a grid layout, so I moved the Shift key to the left
of the Space "key", as it made no sense to have two space "keys" and it seemed
like prime real estate for the shift key to be held down with the left thumb,
especially since I always have hit the space bar with my right thumb.

Below is the layout for Layer 0  as seen in the keymap file:

```
Workman
,-----------------------------------------------------------------------------------.
| Esc  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  | Bksp |
|------+------+------+------+------+-------------+------+------+------+------+------|
| Tab  |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  | Ent  |
|------+------+------+------+------+------|------+------+------+------+------+------|
|   '  |   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |   -  |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Ctrl | GUI  | Alt  | SGUI |Lower |  Sft |  Spc |Raise | SGUI |  Alt |  GUI | Ctl  |
`-----------------------------------------------------------------------------------'
```

## Layer 1 "Lower" - Symbols and Arrow keys

Since I removed the arrow keys from the base layer I had to move them to the
"Lower" layer below the symbols on the right Home row. As I wanted to have
access to all of the modifiers on every layer, I moved the vertical bar
character below the Enter key. Programming in C and C++ requires typing a lot
of successive capital characters so I needed access to the Caps Lock on this
layer as a toggle. As well, I placed the forward Delete key here in the same
place as the Backspace key on layer 0, as a convenience.

Layer 1 is shown below as it appears in the keymap file:

```
Lower
,-----------------------------------------------------------------------------------.
|   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  Del |
|------+------+------+------+------+-------------+------+------+------+------+------|
|CapsLk|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |      |
|------+------+------+------+------+------|------+------+------+------+------+------|
|      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Left | Down |  Up  | Right|   |  |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |
`-----------------------------------------------------------------------------------'
```

## Layer 2 "Raise" - Numbers and 
```
Raise
,-----------------------------------------------------------------------------------.
|   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |      |
|------+------+------+------+------+------|------+------+------+------+------+------|
|      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |   \  |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |
`-----------------------------------------------------------------------------------'
```
