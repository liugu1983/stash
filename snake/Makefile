CC=g++
CCFLAGS=-g
OBJS=main.o arenamap.o snake.o game.o utils.o

.PHONY:all clean

all:$(OBJS)
	$(CC) -o a.out $^ -lncurses

clean:
	rm -rf $(OBJS) a.out

%.o:%.cpp
	$(CC) $(CCFLAGS) -c $^
