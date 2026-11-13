# Messlow

Colemak with dedicated navigation and symbol layer holds. Letter keys have no
hold actions. Tab and Enter are ordinary keys.

Thumb keys, in physical left-to-right order:

| Left outer | | | | Left inner |
| --- | --- | --- | --- | --- |
| Ctrl | Alt | Cmd | Space | Hold Nav |

| Right inner | | | | Right outer |
| --- | --- | --- | --- | --- |
| Hold Symbols | Enter | Backspace | Cmd | AltGr |

Thumb keys remain available on both layers. The far-left home-row key is Tab;
the far-left bottom-row key is one-shot Shift on every layer. Tap Shift, release
it, then type the key to shift. It expires after three seconds if unused. It can
also be held normally. Repeated taps do not lock modifiers; double-tapping Shift
still activates Caps Word.

Unused layer positions are blocked with `KC_NO`. Shared keys are mapped
explicitly rather than falling through to the base layer.

## Layer maps

Viewed from above, with the split between the hands. Thumb rows run from left
to right; NAV and SYM are the innermost thumb keys. The diagrams show key
positions without reproducing the physical column stagger.

`--` = blocked (`KC_NO`), `*` = one shot (or hold normally).
`C` = Ctrl, `G` = Cmd, `S` = Shift: `C-G*` means one shot Ctrl+Cmd.
`NAV` / `SYM` = hold to access that layer; release to return.

### Base · Colemak

```text
┌───────┬───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┬───────┐
│   #   │   1   │   2   │   3   │   4   │   5   │    │   6   │   7   │   8   │   9   │   0   │   -   │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│  Esc  │   Q   │   W   │   F   │   P   │   B   │    │   J   │   L   │   U   │   Y   │^ dead │cedilla│
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│  Tab  │   A   │   R   │   S   │   T   │   G   │    │   M   │   N   │   E   │   I   │   O   │   ;   │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│Shift* │   Z   │   X   │   C   │   D   │   V   │    │   K   │   H   │   ,   │   .   │   é   │` dead │
└───────┴───────┴───────┴───────┴───────┴───────┘    └───────┴───────┴───────┴───────┴───────┴───────┘
        ┌───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┐
        │ Ctrl  │  Alt  │  Cmd  │ Space │  NAV  │    │  SYM  │ Enter │ Bksp  │  Cmd  │ AltGr │
        └───────┴───────┴───────┴───────┴───────┘    └───────┴───────┴───────┴───────┴───────┘
```

### Navigation · hold NAV

```text
┌───────┬───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┬───────┐
│  --   │  C-1  │  C-2  │  C-3  │  C-4  │  C-5  │    │  C-6  │  C-7  │  C-8  │  C-9  │  C-0  │  --   │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│  --   │  Cmd  │  Alt  │ Shift │ Ctrl  │  --   │    │ Again │ Paste │ Copy  │  Cut  │ Undo  │Delete │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│  Tab  │ G-S*  │ C-S*  │ C-G*  │ C-S*  │  --   │    │ Caps  │ Left  │ Down  │  Up   │ Right │  --   │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│Shift* │  --   │  --   │  --   │  --   │  --   │    │Insert │ Home  │PgDown │ PgUp  │  End  │  --   │
└───────┴───────┴───────┴───────┴───────┴───────┘    └───────┴───────┴───────┴───────┴───────┴───────┘
        ┌───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┐
        │ Ctrl  │  Alt  │  Cmd  │ Space │  NAV  │    │  SYM  │ Enter │ Bksp  │  Cmd  │ AltGr │
        └───────┴───────┴───────┴───────┴───────┘    └───────┴───────┴───────┴───────┴───────┘
```

### Symbols · hold SYM

```text
┌───────┬───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┬───────┐
│  F12  │  F1   │  F2   │  F3   │  F4   │  F5   │    │  F6   │  F7   │  F8   │  F9   │  F10  │  F11  │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│  --   │   ~   │   \   │   /   │   |   │   $   │    │  --   │  --   │  --   │  --   │  --   │  --   │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│  Tab  │   <   │   [   │   {   │   (   │   %   │    │  --   │   )   │   ]   │   }   │   >   │  --   │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│Shift* │   *   │   -   │   +   │   =   │   &   │    │  --   │  --   │  --   │  --   │  --   │  --   │
└───────┴───────┴───────┴───────┴───────┴───────┘    └───────┴───────┴───────┴───────┴───────┴───────┘
        ┌───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┐
        │ Ctrl  │  Alt  │  Cmd  │ Space │  NAV  │    │  SYM  │ Enter │ Bksp  │  Cmd  │ AltGr │
        └───────┴───────┴───────┴───────┴───────┘    └───────┴───────┴───────┴───────┴───────┘
```

On every layer, the left encoder turns volume down/up and presses Play/Pause.
The right encoder scrolls down/up and presses the middle mouse button.
The base layer's circumflex, cedilla and grave accent keys are dead keys.

## Navigation

Positions below refer to the letters on the base layer. Keep Nav held while using
these keys, then release it to return to typing.

| Action | Keys |
| --- | --- |
| Left / down / up / right | N / E / I / O |
| Ctrl + left/right | Hold P (Ctrl), tap N/O; alternatively hold thumb Ctrl |
| Ctrl + Backspace | Hold thumb Ctrl, tap thumb Backspace; also works on Nav using P |
| Kitty previous/next tab | Tap T or R (one-shot Ctrl+Shift), then N/O |
| macOS previous/next Space | Tap S (one-shot Ctrl+Cmd), then N/O |
| Neovim numbered tab | On Nav, tap 1–0 to send Ctrl+1–0; or use thumb Ctrl + number on base |
| Delete | Nav + far-right top-row key (base dead cedilla) |

The A/R/S/T combined modifiers can also be held while tapping arrows repeatedly.
On Nav, Q/W/F/P are ordinary held Cmd/Alt/Shift/Ctrl modifiers.
The two Ctrl+Shift keys on R and T are intentional.
These bindings send the listed modifiers; their effects depend on the host and
application configuration.

## Symbols

Hold Symbols to access punctuation, including paired brackets, braces and
parentheses on the home row. These keycodes expect a Canadian French host layout.
The number row sends F1–F10 at positions 1–0, F11 at the minus position, and F12
at the hash position.

## Build

For the RP2040 CE conversion:

```sh
qmk compile -kb sofle_choc -km Messlow -e CONVERT_TO=rp2040_ce
```
