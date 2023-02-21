NAME:=push_swap

STACK_SRC:= \
	stack/stack.c \
	stack/queue.c \
	stack/operations.c
SRC:= \
	main.c
OBJS:=${addprefix src/,${STACK_SRC:.c=.o} ${SRC:.c=.o}}
CC:=cc
CFLAGS:= -Wall -Wextra -Werror
INCLUDE:= include

all: ${NAME}

${NAME}: ${OBJS}
	@ar -rcs ${NAME} ${OBJS}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean: 
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

bonus: re