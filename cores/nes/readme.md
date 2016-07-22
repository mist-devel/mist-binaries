# NES core for MiST

This is a port of Luddes NES core to the MIST. See his FPGANES blog at
<http://fpganes.blogspot.de> for details. The original source code can
be found at <https://github.com/strigeus/fpganes>

You need a USB game pad with at least 2 buttons to run NES games. With
4 buttons SELECT and START will also be mapped. For pads with two buttons
START and SELECT can also be reached from the OSD.

## 15 khz support (TV)
Create a mist.ini file with at least the following line:

```
[mist]
scandoubler_disable=1
```

## Keyboard support in NES

* 1 - switch to joystick A
* 2 - switch to joystick B
* Up,Down,Left,Right
* Esc - start
* Tab - select
* Space - fire 1
* Left Alt - fire 2
