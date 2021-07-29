##
##


CFLAGS=-g 
CPPFLAGS=
LDFLAGS=-g
LDLIBS=

CC=gcc

SRCS=merge.c
OBJS=$(subst .c,.o,$(SRCS))
TARGET=list

$(TARGET): $(OBJS)
	g++ $(LDFLAGS) -o $(TARGET) $(OBJS) 

%.o: %.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)