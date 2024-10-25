##
## SpotifyManager, 2024
## File description:
## Makefile
##

NAME    		=       spotify

SRC             =       ${wildcard src/*.c}

OBJ             =       ${SRC:.c=.o}

FLAGS		  	=       -lreadline

EXTRA_FLAGS     =       -Wall -Werror -Wextra

all:    build

build:  ${OBJ}
	gcc -o ${NAME} ${OBJ} ${FLAGS} ${EXTRA_FLAGS}

valgrind:  ${OBJ}
	gcc -o ${NAME} ${OBJ} ${EXTRA_FLAGS} -g

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re:	fclean  build
