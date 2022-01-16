# Apple1_MIST

Apple-I core for the MiST FPGA.

## What's implemented

- 512 bytes ROM (Woz monitor and ACI), remaing space is RAM
- full working audio cassette interface (see below how to operate it)
- CPU clock is accurate and RAM refresh lost cycles are implemented
- NTSC output (with crosstalk pixel artifacts!)
- Keyboard: ASCII keyboard with clear screen and reset keys

## How to use it

F5 resets the machine, F1 clears the screen.

You can load `.PRG` files from the SD card via the F12 MiST menu. `.PRG` files
are plain binary files with an header of two bytes containing the load address
of the program.

If you have a binary file (usually they come with a `.bin` extension, or no
extension at all) you need to convert it to `.PRG` before you can load with
it with the F12 menu option. Check my other repo
[apple1-videocard-lib](https://github.com/nippur72/apple1-videocard-lib)
where I have some tools for converting from and to various Apple-I
formats (prg, bin, wav, woz).

After you load a file, you can run it from the monitor, for example
if you have a program that starts at address `$0280` type:
```
280R (return)
```

## Using the ACI Audio Cassette Interface

To be able to use the ACI you need to connect your audio input source (tape,
mp3 player, PC, ect...) to the `UART_RX` pin of the MiST (Mistica units
have a dedicated "audio input" jack plug).

Audio output (for saving programs on tape) is simply taken for the speakers output.

The F12 menu option "Audio monitor" allows you to choose from:
- "tape in": audio coming from the tape is also played on the speaker as feedback
- "tape out": the speakers play the tape out signal (for recording on a real tape or sampling it on a PC).

The ACI is commanded from its own monitor program. Enter it with:
```
C100R (return)
```
(a `*` will be shown as prompt).

### How to load a file

On the ACI monitor type the start and end address of the program you are going to read,
followed by a "R", e.g.:
````
280.2CAR (enter)
````
Note: make sure the tape (or WAV) is already playing before pressing (enter).

### How to save a file

On the ACI monitor type the start and end address of the program you are going to write,
followed by a "W", e.g.:
````
280.2CAW (enter)
````
Note: press record & play on tape before pressing (enter) on the ACI.

## Acknowledgments

This FPGA core is based on the previous projects:
- [apple-one](https://github.com/alangarf/apple-one) by Alan Garfield
- [Mist_FPGA](https://github.com/Gehstock/Mist_FPGA) by Gehstock

Thanks also to [P-L4B](https://github.com/P-L4B) and [UncleBernie](https://www.applefritter.com/users/unclebernie), for all the techincal details and explanations that allowed me to write
a more accurate implementation.

