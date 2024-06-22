# Arkanoid-VHDL
Arkanoid hardware implementation for FPGA, tested on Altera Cyclone II DE1 board, developed using Altera Quartus II Web Edition.

Video presentation: https://www.youtube.com/watch?v=pVajZEJieoY

##Project structure
* arkanoid-vhdl-master: main project files (source code)
* Arkanoid Level Editor: a nice wysiwyg level editor that lets you create your own levels, 
providing functions for loading/saving .mif files. Remember to compile after editing arkanoid-vhdl-master/levels.mif
* Project report (ITALIAN only).pdf: project final report (italian only)

##Setup
1. Create new Quartus II project "arkanoid-vhdl-master"
2. Copy arkanoid-vhdl-master source files inside project
3. (Quartus II) Assignments -> Import Assignments -> File name: /PATH_TO/DE1.qsf -> Ok (DE1.qsf is located in "arkanoid-vhdl-master" folder)
3. Compile
4. Program device (after connecting DE1 board through USB port)
5. Connect a display through DE1 VGA port
6. Connect a PS/2 Keyboard to DE1 PS/2 Port
7. (optional) Connect a buzzer to DE1 GPIO_0(0) pin
8. Press spacebar
9. Enjoy :)


##Key bindings
* Move LEFT: "Y"
* Move RIGHT: "I"
* Start: spacebar
* Pause: "P"
* Reset: Altera DE1 Key(0) physical button

##Authors
Pietro Bassi

Marco Torsello
