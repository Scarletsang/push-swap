NAME:=get_next_line.a

CC:=cc
CFLAGS= -Wall -Wextra -Werror
ifdef FSANITIZE
	CFLAGS+= -g3 -fsanitize=address
endif

ifdef BONUS
	SRC:= \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c
else
	SRC:= \
		get_next_line.c \
		get_next_line_utils.c
endif
SRC:=${addprefix src/,${SRC}}
OBJS:=${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@ar -rcs ${NAME} ${OBJS} && echo "Compilation of ${NAME} successful"

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

bonus: re

.PHONY: clean fclean re bonus