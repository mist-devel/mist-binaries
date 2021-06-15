CROSS_GCC=i586-mingw32msvc-gcc
TOOL=mdump2qlay

all: $(TOOL) 

$(TOOL): $(TOOL).c

$(TOOL).exe: $(TOOL).c
	$(CROSS_GCC) -o $@ $<

