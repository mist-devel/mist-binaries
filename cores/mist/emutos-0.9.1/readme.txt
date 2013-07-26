The TG68 CPU core used by the Atari/MIST is not correctly implementing
the stop instruction. This is being used by EmuTOS to allow emulators
to save some host cpu power and there's no benefit on real hardware or
the MIST.

Fortunately there's a config option and the use of the stop
instruction can easily be disabled. To compile EmuTOS for MIST youself
simply use the original source tree from
http://sourceforge.net/projects/emutos and change

# define USE_STOP_INSN_TO_FREE_HOST_CPU 1

to 

# define USE_STOP_INSN_TO_FREE_HOST_CPU 0

in the file include/config.h
