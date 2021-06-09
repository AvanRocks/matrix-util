CC=g++
CFLAGS=
ifeq ($(PREFIX),) 
  PREFIX := /usr/local
endif

OBJDIR=obj
SRCDIR=src

_DEPS = Fraction.h Matrix.h
DEPS = $(patsubst %,$(SRCDIR)/%,$(_DEPS))

_OBJ = Fraction.o Matrix.o mat.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS) | $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

mat: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(OBJDIR):
	mkdir $(OBJDIR)

install: mat
	install -d $(DESTDIR)$(PREFIX)/bin/
	install mat $(DESTDIR)$(PREFIX)/bin/

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/mat

clean:
	rm -rf $(OBJDIR) *~ core

.PHONY: clean install uninstall