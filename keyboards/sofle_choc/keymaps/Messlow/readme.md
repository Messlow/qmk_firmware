# Messlow

Colemak with dedicated navigation and symbol layer holds. Letter keys have no
hold actions. Tab and Enter are ordinary keys.

Thumb keys, in physical left-to-right order:

| Left outer | | | | Left inner |
| --- | --- | --- | --- | --- |
| Ctrl | Alt | Cmd | Space | Hold Nav |

| Right inner | | | | Right outer |
| --- | --- | --- | --- | --- |
| Hold Symbols | Backspace | Enter | Cmd | AltGr |

Backspace occupies the position mirroring left Space, with Enter one key farther
outward. This is a comfort experiment; the physical resting thumb position
depends on hand size and keyboard placement, not the diagram alone.
Backspace is also available at the far-right top letter-row key on Base and
Symbols, so the right pinky and thumb positions can be compared. Nav uses Delete
at that pinky position. Left-thumb Alt remains available.

Thumb keys remain available on both layers. On the base layer, the left outer
column is Esc / Ctrl / one-shot Shift; the right outer column is Backspace / Cmd /
right Shift. Right Alt remains AltGr on the thumb.
The far-left home-row key is Tab on Nav and Symbols.
The far-left bottom-row key is one-shot Shift on every layer. Tap Shift, release
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
│  Esc  │   Q   │   W   │   F   │   P   │   B   │    │   J   │   L   │   U   │   Y   │   '   │ Bksp  │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│ Ctrl  │   A   │   R   │   S   │   T   │   G   │    │   M   │   N   │   E   │   I   │   O   │  Cmd  │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│Shift* │   Z   │   X   │   C   │   D   │   V   │    │   K   │   H   │   ,   │   .   │   é   │ Shift │
└───────┴───────┴───────┴───────┴───────┴───────┘    └───────┴───────┴───────┴───────┴───────┴───────┘
        ┌───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┐
        │ Ctrl  │  Alt  │  Cmd  │ Space │  NAV  │    │  SYM  │ Bksp  │ Enter │  Cmd  │ AltGr │
        └───────┴───────┴───────┴───────┴───────┘    └───────┴───────┴───────┴───────┴───────┘
```

### Navigation · hold NAV

```text
┌───────┬───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┬───────┐
│  --   │  C-1  │  C-2  │  C-3  │  C-4  │  C-5  │    │  C-6  │  C-7  │  C-8  │  C-9  │  C-0  │  --   │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│  --   │  Cmd  │  Alt  │ Shift │ Ctrl  │  --   │    │ Again │ Paste │ Copy  │  Cut  │ Undo  │Delete │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│  Tab  │ G-S*  │ C-S*  │ C-G*  │ C-S*  │  --   │    │ Caps  │ Left  │ Down  │  Up   │ Right │  Cmd  │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│Shift* │  --   │  --   │  --   │  --   │  --   │    │Insert │ Home  │PgDown │ PgUp  │  End  │ Shift │
└───────┴───────┴───────┴───────┴───────┴───────┘    └───────┴───────┴───────┴───────┴───────┴───────┘
        ┌───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┐
        │ Ctrl  │  Alt  │  Cmd  │ Space │  NAV  │    │  SYM  │ Bksp  │ Enter │  Cmd  │ AltGr │
        └───────┴───────┴───────┴───────┴───────┘    └───────┴───────┴───────┴───────┴───────┘
```

### Symbols · hold SYM

```text
┌───────┬───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┬───────┐
│  F12  │  F1   │  F2   │  F3   │  F4   │  F5   │    │  F6   │  F7   │  F8   │  F9   │  F10  │  F11  │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│  --   │   ~   │   \   │   /   │   |   │   $   │    │` dead │   :   │   ;   │  --   │^ dead │ Bksp  │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│  Tab  │   <   │   [   │   {   │   (   │   %   │    │cedilla│   )   │   }   │   ]   │   >   │  Cmd  │
├───────┼───────┼───────┼───────┼───────┼───────┤    ├───────┼───────┼───────┼───────┼───────┼───────┤
│Shift* │   *   │   -   │   +   │   =   │   &   │    │  --   │   à   │   è   │   ç   │  --   │ Shift │
└───────┴───────┴───────┴───────┴───────┴───────┘    └───────┴───────┴───────┴───────┴───────┴───────┘
        ┌───────┬───────┬───────┬───────┬───────┐    ┌───────┬───────┬───────┬───────┬───────┐
        │ Ctrl  │  Alt  │  Cmd  │ Space │  NAV  │    │  SYM  │ Bksp  │ Enter │  Cmd  │ AltGr │
        └───────┴───────┴───────┴───────┴───────┘    └───────┴───────┴───────┴───────┴───────┘
```

## Encoder knobs

`ENCODER_DIRECTION_FLIP` corrects the physical direction of both knobs.
Flash both halves after changing this setting, since each half reads its own
encoder pins.

Base-layer rotation uses custom keycodes that hold each shortcut for 20 ms
and add a 20 ms gap after release. Nav scrolling and Symbols volume/RGB
controls retain QMK's default encoder timing, with no added delay. The base
timing adjustment tests host shortcut recognition when physical key chords
work but knob turns interrupt a terminal TUI. The shortcut combinations are
unchanged; the effect on macOS workspace switching needs testing on the host.

| Layer held | Left knob: counterclockwise / clockwise | Right knob: counterclockwise / clockwise |
| --- | --- | --- |
| None | Ctrl+Shift+Left / Right | Ctrl+Cmd+Left / Right |
| Nav | Scroll left / right | Scroll down / up |
| Symbols | Volume down / up | Keyboard RGB dimmer / brighter |

| Layer held | Left knob press | Right knob press |
| --- | --- | --- |
| None (macOS) | Switch app: Cmd+Tab | Mission Control: Ctrl+Up |
| None (Windows) | Switch app: Alt+Tab | Task View: Win+Tab |
| Nav | Left mouse click | Middle mouse click |
| Symbols | Play/Pause | RGB on/off |

QMK's USB OS detection selects the base press shortcuts automatically; this
is heuristic and can be affected by USB intermediaries. Inconclusive detection
falls back to macOS. App switching is a single shortcut tap, releasing all
shortcut keys immediately; it does not keep the switcher open for knob turns.
Mission Control assumes the standard macOS Ctrl+Up binding is enabled.
Media keys require `EXTRAKEY_ENABLE = yes`.
Base-layer shortcuts send the listed modifiers with each arrow key; their
effects depend on the host and application. Scrolling direction can also be
affected by host settings.
If the terminal does not consume a base-layer shortcut, it can pass the arrow
to the running program as an escape sequence. The rotation mappings contain
neither Escape nor Ctrl+C; terminal bindings determine whether a shortcut
switches tabs or reaches the program.

Test the encoder timing adjustment first, without Kitty discard mappings.
If shortcut events still leak into the terminal, optional
[`kitty-macos.conf`](kitty-macos.conf) mappings discard Ctrl+Cmd+Left/Right
events that reach Kitty, so those events are not forwarded to a running TUI.
Copy these mappings into the Mac's Kitty configuration and reload it, then
verify workspace switching still works and the TUI keeps running. These
mappings do not configure the macOS workspace shortcut. If a shortcut manager
rewrites the chord, inspect the received keys with `kitten show-key` and match
the discarded chord to those events.
RGB brightness respects the configured maximum of 100.

Circumflex, cedilla, and grave on Symbols are dead keys.

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
| Delete | Nav + far-right top-row key (base Backspace) |
| Tab | Nav + far-left home-row key (base Ctrl); also available on Symbols |

The A/R/S/T combined modifiers can also be held while tapping arrows repeatedly.
On Nav, Q/W/F/P are ordinary held Cmd/Alt/Shift/Ctrl modifiers.
The two Ctrl+Shift keys on R and T are intentional.
These bindings send the listed modifiers; their effects depend on the host and
application configuration.

## Modifier shortcuts

For Ctrl+Shift+T/P, hold left pinky Ctrl and right pinky Shift, then tap T/P.
For Cmd+Shift shortcuts, hold right pinky Cmd and left Shift. Alternatively,
hold Nav, tap R or T for one-shot Ctrl+Shift, release Nav, then type the letter
within three seconds. The one-shot combinations work with base-layer letters,
not only navigation keys.

Right Cmd and Shift remain available on both layers. Right pinky Backspace becomes
Delete on Nav. Left pinky Ctrl becomes Tab on both layers; use thumb Ctrl for
Ctrl+Tab, or hold Nav and P (Ctrl), then tap the Tab position.

## Symbols

Hold Symbols to access punctuation, including paired brackets, braces and
parentheses on the home row. These keycodes expect a Canadian French host layout.
Pairs mirror across hands: pinkies `< >`, ring fingers `[ ]`, middle fingers
`{ }`, and index fingers `( )`.
The number row sends F1–F10 at positions 1–0, F11 at the minus position, and F12
at the hash position.

Frequently used punctuation sits together on the right top letter row:
Symbols + L = colon (no separate Shift press needed).
Symbols + J = dead grave, Symbols + U = semicolon.
Colon and semicolon use the index and middle fingers;
dead grave uses the inner index column.
Hold Symbols with the right thumb, tap the dead key, then release Symbols
before typing the accented letter. Dead cedilla is on the innermost right home-row
key (base M), directly below dead grave, operated with the right index finger.
Tab remains at the far-left home-row position on Nav and Symbols.

Base apostrophe is a single key immediately left of pinky Backspace. It sends
the Canadian French Shift+comma keycode without requiring physical Shift.
Symbols at that same position provides dead circumflex.

Symbols + H / comma / period produces à / è / ç. These macros send the dead
accent followed by the letter, so Symbols can remain held. Hold Shift as well
for À / È / Ç, or tap one-shot left Shift after holding Symbols, then tap the
accented-letter key. Shift applies only to the letter and one-shot Shift is
consumed by that character. Existing base é uses Shift for É as before.
These sequences require a Canadian French host layout; verify accent composition
and capitals on the host after flashing.

## Build

For the RP2040 CE conversion:

```sh
qmk compile -kb sofle_choc -km Messlow -e CONVERT_TO=rp2040_ce
```
