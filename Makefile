CC=g++
CFLAGS=
ifeq ($(PREFIX),) 
  PREFIX := /usr/local
endif

SRCDIR=src

_DEPS = Fraction.h Matrix.h
DEPS = $(patsubst %,$(SRCDIR)/%,$(_DEPS))

OBJ = Fraction.o Matrix.o mat.o

all: mat

%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mat: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

install: all
	install -d $(DESTDIR)$(PREFIX)/bin/
	install mat $(DESTDIR)$(PREFIX)/bin/

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/mat

clean:
	rm -f $(OBJ) *~ core

.PHONY: clean install uninstall