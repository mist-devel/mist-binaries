CROSS_GCC=i586-mingw32msvc-gcc
TOOL=mdvtool

all: $(TOOL)

$(TOOL): $(TOOL).c
	gcc -o $@ $< -lzip

$(TOOL).exe: $(TOOL).c
	$(CROSS_GCC) -o $@ $<

test: $(TOOL)
	./$(TOOL) ../../GamesCart.mdv erase name Gunner zip_import ../../gunner.zip write gunner.mdv

