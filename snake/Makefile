CC=g++
CCFLAGS=
OBJS=main.o arenamap.o

.PHONY:all clean

all:$(OBJS)
	$(CC) -o a.out $^ -lncurses

clean:
	rm -rf $(OBJS) a.out

%.o:%.cpp
	$(CC) $(CCFLAGS) -c $^
