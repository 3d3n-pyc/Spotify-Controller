##
## SpotifyManager, 2024
## File description:
## Makefile
##

NAME    		=       spotify

SRC             =       ${wildcard src/*.c}

OBJ             =       ${SRC:.c=.o}

FLAGS		  	=       -lreadline

CFLAGS     =       -Wall -Werror -Wextra -Iincludes

all:    build

build:  ${OBJ}
	gcc -o ${NAME} ${OBJ} ${FLAGS}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

debug: fclean
debug: CFLAGS += -g
debug: build

re:	fclean  build

.POETRY: all build clean fclean debug re
