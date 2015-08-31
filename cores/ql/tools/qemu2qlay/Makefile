CROSS_GCC=i586-mingw32msvc-gcc
TOOL=qemu2qlay

all: $(TOOL) $(TOOL).exe

$(TOOL): $(TOOL).c

$(TOOL).exe: $(TOOL).c
	$(CROSS_GCC) -o $@ $<
