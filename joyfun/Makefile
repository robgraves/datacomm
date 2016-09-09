LIBS = -lm -lSDL2
CFLAGS = -Wall $(LIBS)
INC = 
CC = gcc
SRC = $(shell /bin/ls -1 *.c 2>/dev/null)
BIN = $(SRC:.c=)
USERPWD = $(USERPATH)
PROJPWD = $(PROJPATH)
BINPATH = .
all: clean $(SRC) $(BIN) 

debug: CFLAGS += -DDEBUG -g
debug: DEBUG = debug
debug: $(SRC) $(BIN) 

.c:
ifneq ($(MAKECMDGOALS),debug)
	@printf "[\033[0;33mCC\033[0m]   %-20s ... " "$<"
	@$(CC) $(INC) -o $@ $< $(CFLAGS) 2>> errors && echo "\033[0;32mOK\033[0m" || echo "\033[0;31mFAIL\033[0m"
else
	$(CC)  $(INC) -o $@ $< $(CFLAGS)
endif

copy:
	@cp -av $(PROJPWD)/* $(USERPWD)/

clean:
	@rm -f .*.sw[op] *.save* *~ $(BIN) $(BINPATH)/$(BIN) core errors
