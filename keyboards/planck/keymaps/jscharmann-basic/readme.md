# Jay's Basic Workman Planck

This is a basic Workman layout I came up with, in case my more complicated
keymap is or was buggy and I needed a usable one to get by until I solve or
solved the bugs. I created 4 layers total - Base, Function Keys, Numbers with
Navigation keys, and an Adjust layer to house the RESET key. Most of the
Modifier Keys are available, through transparency, on all layers except the
Adjustment layer. Details on the logic that I followed to place the keys
is described below.

## Layer 0 - Workman Layout Base
```
,-----------------------------------------------------------------------------------.
| Esc  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  |   -  |
|------+------+------+------+------+-------------+------+------+------+------+------|
| Tab  |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  | Ent  |
|------+------+------+------+------+------|------+------+------+------+------+------|
| Shift|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  | Shift|
|------+------+------+------+------+------+------+------+------+------+------+------|
| Ctrl | GUI  | Alt  | SGUI |Lower |Bkspce|  Spc |Raise | SGUI |  Alt |  GUI | Ctl  |
`-----------------------------------------------------------------------------------'
```
This layer is the default workman layout that I use.

### Changes from default "basic" layout
It goes without saying that I changed this layout considerably, since I use
Workman as my default, but also I made several, dare I say, unique changes.

#### TAB and Escape swapped
I couldn't get used to the TAB and ESC keys being in the opposite places that
I was used to so I changed them to reflect that.

#### Enter key at same row as Home Row
On all of the keyboards that I have used in my life, regardless if it was
QWERTY, DVORAK, or WORKMAN, the Enter key was always on the home row, and I
found it being one row below was awkward for me, so I changed it to my
tastes.

#### Modifiers
I must have symmetry where my modifier keys are concerned, so I had to alter
the default structure of the keymap to include the right side modifiers as
well as a shift key on both sides.

#### Placing of the Backspace key
I have a Planck with a grid layout, so I moved the Backspace key to the left
of the Space "key", as it made no sense to have two space "keys" and it seemed
like prime real estate for the backspace key to be triggered with the left
thumb, especially since I always have hit the space bar with my right thumb.

#### Symmetric Shift+GUI keys
The experimental keyboard layout that I am currently working on has a second
pair of modifiers that triggers up to 16 layers (including the base layer)
using different combinations of the keys being depressed (if it works, all
credit goes to user gunp, which I definitely encourage others to check out -
very awesome!), but as this was only a backup, I opted to fill the other two
keys with Shift+GUI keys for some of the shortcuts I use in the i3 window
manager.

---

## Layer 1 - Function and Media keys
```
,-----------------------------------------------------------------------------------.
|xxxxxx|  F1  |  F2  |  F3  |  F4  | Prev | Next |  F13 |  F14 |  F15 |  F16 |  Del |
|------+------+------+------+------+-------------+------+------+------+------+------|
|CapsLk|  F5  |  F6  |  F7  |  F8  | Mute | Play |  F17 |  F18 |  F19 |  F20 |Insert|
|------+------+------+------+------+------|------+------+------+------+------+------|
|      |  F9  |  F10 |  F11 |  F12 | Vol- | Vol+ |  F21 |  F22 |  F23 |  F24 |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |
`-----------------------------------------------------------------------------------'
```

I wanted to use the traditional shifted numbers to symbols on Layer 2, so that
freed up space on layer 1 for all the function keys as well as several media
keys in the middle columns. I also placed the forward Delete key where the
backspace usually was on the main layer and the Insert key to toggle between
insert and replace mode in Vim. And, since I am learning to program in C and
C++, I needed access to Caps Lock so that declaring constants wouldn't be so
painful, so I placed Caps Lock in the far left column of the home row.

---

## Layer 2 - Numbers, Symbols, and Navigation
```
,-----------------------------------------------------------------------------------.
|   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   =  |
|------+------+------+------+------+-------------+------+------+------+------+------|
|   "  | Home | PgUp | PgDn |  End |   [  |   ]  | Left | Down |  Up  | Right|   \  |
|------+------+------+------+------+------|------+------+------+------+------+------|
|      |xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |
`-----------------------------------------------------------------------------------'
```

To me, it made no sense to declare a layer just for symbols that I could get
from using shift on the number keys, but I was left with the remaining symbol
specific keys - quote, grave, left and right square bracket, equals sign, and
backslash - without a home, and so I laid out the most useful layout I could
come up with to account for them. 

I also figured that I should find a place for the navigation keys so I used a
Vim and i3 like placement for the arrow keys and similarly laid out the left
side for "Home", "Page Up", "Page Down", and "End".

---

## Layer 3 - Adjustment, a.k.a., Reset Layer
```
,-----------------------------------------------------------------------------------.
| Reset|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|
|------+------+------+------+------+-------------+------+------+------+------+------|
|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|
|------+------+------+------+------+------|------+------+------+------+------+------|
|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|xxxxxx|
|------+------+------+------+------+------+------+------+------+------+------+------|
|xxxxxx|xxxxxx|xxxxxx|xxxxxx|      |xxxxxx|xxxxxx|      |xxxxxx|xxxxxx|xxxxxx|xxxxxx|
`-----------------------------------------------------------------------------------'
```

I still wanted to have a quick way of reseting the keyboard as I enjoy
experimenting, so I made the last layer just to house the RESET key in a
place least used. It is the only key here, but I might place other less used
keys here in the future if it seems appropriate.

---

And that is it. As I was saying I am always working on a more extensive and
complex layout in my main directory, so if you are at all curious as to that
one, check it out.

HAPPY HACKING!!!

-Jay
