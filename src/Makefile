#OBJS is a variable containing o files#
OBJS= string_funcs.o uimain.o history.o

CFLAGS= -g #for debug#

all: tokenizer_ui

#target depends on all the o files#
tokenizer_ui: $(OBJS)
	cc -o tokenizer_ui $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h

clean:
	rm -f *.o tokenizer_ui

run: tokenizer_ui
	./tokenizer_ui
