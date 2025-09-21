# Top-level Makefile for libmyutils project
CC = gcc
CFLAGS = -Wall -Wextra -fPIC -Iinclude
AR = ar
RANLIB = ranlib
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))
LIBDIR = lib
BINDIR = bin
INCLUDEDIR = include
MANSDIR = man/man3

.PHONY: all clean distclean install uninstall multifile static dynamic

all: multifile static dynamic

# ----- multifile: compile all sources into one executable (direct link) -----
multifile: $(BINDIR)/client

$(BINDIR)/client: $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^

# ----- static library build -----
static: $(LIBDIR)/libmyutils.a $(BINDIR)/client_static

$(LIBDIR)/libmyutils.a: $(OBJ)
	@mkdir -p $(LIBDIR)
	$(AR) rcs $@ $^
	$(RANLIB) $@

$(BINDIR)/client_static: $(patsubst obj/%.o, src/%.o, $(OBJ)) $(LIBDIR)/libmyutils.a
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ src/main.c -L$(LIBDIR) -lmyutils

# ----- dynamic (shared) library -----
dynamic: $(LIBDIR)/libmyutils.so $(BINDIR)/client_dynamic

$(LIBDIR)/libmyutils.so: $(OBJ)
	@mkdir -p $(LIBDIR)
	$(CC) -shared -o $@ $^
	chmod 755 $@

$(BINDIR)/client_dynamic: src/main.c $(LIBDIR)/libmyutils.so
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ src/main.c -L$(LIBDIR) -lmyutils

# Object files
obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

# ----- man pages and install -----
install: all
	@echo "Installing binary to /usr/local/bin and man pages to /usr/local/share/man/man3/"
	sudo mkdir -p /usr/local/bin
	sudo cp bin/client /usr/local/bin/client
	sudo cp lib/libmyutils.so /usr/local/lib/libmyutils.so || true
	sudo mkdir -p /usr/local/share/man/man3
	# install man pages
	for f in $(MANSDIR)/*; do sudo cp $$f /usr/local/share/man/man3/; done
	sudo mandb || true
	@echo "Install complete."

uninstall:
	sudo rm -f /usr/local/bin/client
	sudo rm -f /usr/local/lib/libmyutils.so
	sudo rm -f /usr/local/share/man/man3/*

clean:
	rm -rf obj
	rm -rf bin
	rm -rf lib

distclean: clean
	rm -rf *.zip

# Convenience targets
run_dynamic: all
	export LD_LIBRARY_PATH=$(PWD)/lib:$$LD_LIBRARY_PATH; ./bin/client_dynamic

