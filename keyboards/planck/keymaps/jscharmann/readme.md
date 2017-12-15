# Jay's Happy Hacking Workman Planck

This is a Workman Layout that has the capability of being programmed with up
to 16 layers all togglable with four keys, two each on each side of the middle
columns.

## Preface and Acknowledgments
Before I get started explaining the layers that are programmed at present, I
would like to give credit where credit is due in regards to the layer
switching algorithm and the inspiration behind the dual and trial C and C++
operators.

My knowledge of C is limited at present so I can't explain how the mechanism
works. I leave that to the person who came up with it, the planck user, gunp.
I was amazed at the simple yet mystifying way in which it is implemented,
so I recommend anyone reading this to refer to his layout to see how it was
originally implemented.

As for the dual and trial C and C++ operators, I was inspired by the user,
jeremy-dev, but instead of sending two or more signals for the keys I opted to
make use of the SEND_STRING() function to send the characters as a string
instead.

At present, the following layers have been defined:

1. 0000 - The Base Alpha Workman Layer
2. 0001 - The C and C++ Dual and Trial Operator Layer
3. 0010 - Numerals, Symbols, and Navigation
4. 0100 - Function, Media, and Toggle Modifier keys
5. 1111 - Reset Layer (Future home of keyboard setting keys)

As time goes by, I will be adding more to these.

### The *F* Keys

The "F_*" keys are the layer keys that act as momentary switches while
depressed. The layer numbers are the logical on and off of each combination of
keys from left to right.  I'll give a quick rundown of the possibilities:

- The base is all off, hence "0000"
- 4 layers accessible using one key
	- 0001 - "C" keys
	- 0010 - Numbers, Symbols, and Navigation
	- 0100 - Function, Media, and Toggle Modifier Keys
	- 1000 - (Unassigned)
- 6 layers accessible using two keys
	- 0011 - (Unassigned)
	- 0101 - (Unassigned)
	- 0110 - (Unassigned)
	- 1001 - (Unassigned)
	- 1010 - (Unassigned)
	- 1100 - (Unassigned)
- 4 layers accessible using three keys
	- 0111 - (Unassigned)
	- 1011 - (Unassigned)
	- 1101 - (Unassigned)
	- 1110 - (Unassigned)
- 1 layer accessible with all 4 keys, "1111" - RESET Layer (may add more
  settings keys in the future here.)

It may be true that I might never program all of these layers, but simply
having the option is strangely satisfying. I often think of those that write
Mathematic, Linguistic, or other symbols in Latex and how useful it would be
to have those symbols ready at hand. I also love box drawing characters, so I
would love to be able to program in obscure unicode characters for the fun of
it. I also know of a few emoji freaks that would love to have those always
hand, too!

I will go through each of the presently assigned layers in succession.

---

## 0000 - Workman Base
```
╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
║ Esc ║  Q  ║  D  ║  R  ║  W  ║  B  ║  J  ║  F  ║  U  ║  P  ║  ;  ║  -  ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║ Tab ║  A  ║  S  ║  H  ║  T  ║  G  ║  Y  ║  N  ║  E  ║  O  ║  I  ║ Ent ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║ Sft ║  Z  ║  X  ║  M  ║  C  ║  V  ║  K  ║  L  ║  ,  ║  .  ║  /  ║ Sft ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║ Ctl ║ Alt ║ GUI ║ F_A ║ F_B ║ Bsp ║ Spc ║ F_C ║ F_D ║ GUI ║ Alt ║ Ctl ║
╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
```

This layer is the base alpha input layer with Workman as the default layout.
I'll go over the key layout differences in modifier layout, etc. in what
follows.

I swapped the Esc and Tab keys as the default Planck layout of these keys
made no sense to me. I need to have symmetry in my modifiers so that my hands
are free to move around the board with the least amount of effort. As I have a
grid layout, I moved the backspace key next to the Space key, and never looked
back. I moved the "-" key to where the Backspace was, and positioned the Enter
key on the home row, as it was much better place for me there.

My main production computer is, at present a Linux Box, so that I use are
layout like a Windows keyboard, however, when programming the keyboard, the
modifiers had swapped places and at present I can't be bothered to assign the
Magic keys that will swap them to the proper places, so they look like a Mac
layout but are not in actuality as they appear. I might change this but I'm
not at present concerned as they operate perfectly fine as is once I swapped
them in the keymap.c file.

---

## 0001 - "C" keys
```
╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
║ <<= ║ &=  ║ &&  ║ ||  ║ |=  ║ #!  ║ []  ║ ()  ║ -=  ║ *=  ║ ->  ║ >>= ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║ ^=  ║ <=  ║ !=  ║ ==  ║ >=  ║ <<  ║ >>  ║ ++  ║ --  ║ +=  ║ /=  ║ %=  ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║     ║xxxxx║xxxxx║xxxxx║xxxxx║ ::  ║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║     ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║
╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
```

I was inspired by the user, jeremy-dev, to assign dual and trial C and C++
operator keys to reduce on the amount of typing I had to do while programming.
I used the SEND_STRING() function to accomplish this, and have to say it is
working well. Would recommend this track to anyone who uses these types of
operators on a regular basis in their programming, since RSI sucks.

---

## 0010 - Numerals, Symbols, and Navigation
```
╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
║  `  ║  1  ║  2  ║  3  ║  4  ║  5  ║  6  ║  7  ║  8  ║  9  ║  0  ║  =  ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║  '  ║Home ║PgUp ║PgDn ║ End ║  [  ║  ]  ║Left ║Down ║ Up  ║Right║  \  ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║     ║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║     ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║
╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
```

I know I have 16 layers at my disposal, but I won't assign any needlessly. It
makes more sense to me to use the Shift functionality on the numbers instead,
as I was used to it that way anyway. I still needed a place for the other
symbol and punctuation keys, so I arranged them in a way that I believed to be
logical. As well, I arranged the arrow keys in a Vim or i3 like pattern on the
home row, and matched that with the other navigation keys on the other side.
Now that I have been playing with them for a while in this position, I have to
say, I am satisfied with my decision.

---

## 0100 - Function, Media, Delete, and Toggle keys
```
╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
║xxxxx║ F1  ║ F2  ║ F3  ║ F4  ║Prev ║Next ║ F13 ║ F14 ║ F15 ║ F16 ║ Del ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║CapLk║ F5  ║ F6  ║ F7  ║ F8  ║Mute ║Play ║ F17 ║ F18 ║ F19 ║ F20 ║ Ins ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║     ║ F9  ║ F10 ║ F11 ║ F12 ║Vol- ║Vol+ ║ F21 ║ F22 ║ F23 ║ F24 ║     ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║
╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
```

On this layer, I wanted the all the function keys laid out in numeric order in
sets of 4. This way, I could have each collected in groups of 12 on each hand
and every key is accounted for. The delete key, though rarely used, is
usefully in some cases so I placed it on this layer. The two toggle keys,
insert and Caps Lock seemed logically placed on this layer as a sort of
function type key. Caps Lock was especially useful to me since programming in
C requires declaring constants with all capitals, which is a pain without Caps
Lock. And finally I found I could fill the middle columns with the most
usefully media keys.

---

## 1111 - RESET Layer
```
╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
║Reset║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║xxxxx║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║xxxxx║xxxxx║xxxxx║     ║     ║xxxxx║xxxxx║     ║     ║xxxxx║xxxxx║xxxxx║
╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
```

On this last layer, I needed an out of the way place to house my RESET key, so
that it wouldn't be triggered by accident, or foolishly in any way. This layer
requires both thumbs to lay sideways to trigger all 4 keys, so it is not a
common place and easily accessible layer. I have been debating about putting
other keys here as well that deal with keyboard systems management, but there
aren't many keys I can think I would need here. I don't care about turning the
audio off or using the keyboard as an 8-bit instrument or something, so most
of the keys on the default keymap on the adjust layer are out. I might program
the magic modifier swap if it helps to fix the odd issue with the GUI and Alt
keys, but like I said before, it doesn't matter to me at the moment as the
keyboard works just fine as is.
