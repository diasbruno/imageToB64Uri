CC?=cc
DEBUG?=0

BIN=imageToB64Uri
SOURCES  = $(wildcard ./deps/b64/*.c)
SOURCES += $(wildcard ./deps/file2str/*.c)
SOURCES += $(wildcard ./deps/str-concat/*.c)
SOURCES += $(wildcard *.c) 
OBJECTS  = $(SOURCES:%.c=%.o)
$(info $(OBJECTS))

CFLAGS=-std=c99 -Wall -Werror
CFLAGS+= -I deps/b64 -I deps/file2str -I deps/str-concat
LDFLAGS=

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(BIN)

clean:
	rm -rf $(OBJECTS) $(BIN)
