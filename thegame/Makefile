CC = g++
CFLAGS = -Wall
LIBS = -lm -lSDL2 -lSDL2_image
DEPS = inc/thegame.h
OBJ = main.o entity.o missile.o player.o npc.o obstacle.o weapon.o

all: main clean
	
main: $(OBJ)
	$(CC) -o main $^ $(CFLAGS) $(LIBS)
	printf "make: "
	printf "\033[1;32m"
	printf "Successfully created main"
	printf "\033[0m\n"

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

debug: $(OBJ)
	$(CC) -g $^ $(CFLAGS) $(LIBS) 
	printf "make: "
	printf "\033[1;32m"
	printf "Successfully created a.out, run [gdb a.out] to debug"
	printf "\033[0m\n"

clean:
	rm -f $(OBJ)

prepare:
	hg pull
	hg update
