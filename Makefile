ifneq ($(V),1)
	Q=@
endif

DESTDIR?=
PREFIX?=/usr/
CC:=$(CROSS_COMPILE)gcc
PKG_CONFIG ?= pkg-config

CFLAGS = -fPIC -g -O2

EXTRA_CFLAGS = `$(PKG_CONFIG) --cflags glib-2.0` -I.
EXTRA_LDFLAGS = `$(PKG_CONFIG) --libs glib-2.0` 
EXTRA_LDFLAGS += -pthread

DEMO_CFLAGS = $(CFLAGS) $(EXTRA_CFLAGS)
DEMO_LDFLAGS = $(CFLAGS) $(EXTRA_LDFLAGS)

LIBRARY = librestconf.so

all: $(LIBRARY)

$(LIBRARY): restconf.o
	@echo "Building "$@""
	$(Q)$(CC) -shared $(LDFLAGS) $(EXTRA_LDFLAGS) -o $@ $^

%.o: %.c
	@echo "Compiling "$<""
	$(Q)$(CC) $(CFLAGS) $(EXTRA_CFLAGS) -c $< -o $@

demo: demo.c $(LIBRARY)
	@echo "Compiling $@"
	$(Q)$(CC) $(DEMO_CFLAGS) -o $@ $^ $(DEMO_LDFLAGS)

test: test.c
	@echo "Building $@"
	$(Q)mkdir -p gcov
	$(Q)$(CC) $(CFLAGS) $(EXTRA_CFLAGS) -g -fprofile-arcs -fprofile-dir=gcov -ftest-coverage -o $@ $^ $(EXTRA_LDFLAGS)
	$(Q)G_SLICE=always-malloc VALGRIND_OPTS=--suppressions=valgrind.supp ./test $(TESTSPEC) 2>&1
	$(Q)mv *.gcno gcov/
	$(Q)lcov -q --capture --directory . --output-file gcov/coverage.info
	$(Q)genhtml -q gcov/coverage.info --output-directory gcov

indent:
	indent -kr -nut -l92 *.c *.h
	rm *.c~ *.h~

install: all
	@install -d $(DESTDIR)/$(PREFIX)/lib
	@install -D $(LIBRARY) $(DESTDIR)/$(PREFIX)/lib/
	@install -d $(DESTDIR)/$(PREFIX)/include
	@install -D restconf.h $(DESTDIR)/$(PREFIX)/include
	@install -d $(DESTDIR)/$(PREFIX)/lib/pkgconfig
	@install -D restconf.pc $(DESTDIR)/$(PREFIX)/lib/pkgconfig/

clean:
	@echo "Cleaning..."
	@rm -fr $(LIBRARY) *.o demo test gcov

.PHONY: all clean test
