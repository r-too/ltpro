CC = gcc
CFLAGS =-Wall -O3 
DFLAGS =-g
AFLAGS =
MFLAGS =-lgsl -lgslcblas
GFLAGS =-lgd 
SRC = lt_main.c lt_drvr.c lt_init.c lt_args.c lt_math.c lt_grfx.c lt_prnt.c
INCLUDE =-I.
OBJS = $(SRC:.c=.o)
TARGET = ltpro
DEBUG = d.ltpro
SLIB = ltpro.a
.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(AFLAGS) $(INCLUDE) -o $(TARGET) $(SLIB) $(MFLAGS) $(GFLAGS)
	rm -f *.o

debug:  $(OBJS)
	$(CC) $(DFLAGS) $(CFLAGS) $(INCLUDE) -o $(DEBUG) $(OBJS) $(MFLAGS) $(GFLAGS)

.c.o:
	$(CC) $(DFLAGS) $(CFLAGS) $(INCLUDE) -c $< -o $@ $(MFLAGS) $(GFLAGS)
	ar rcs $(SLIB) $@ 

clean:
	$(RM) $(TARGET) *.o $(DEBUG)
	rm -f $(SLIB)
