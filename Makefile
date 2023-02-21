NAME:=push_swap

CC:=cc
CFLAGS:= -Wall -Wextra -Werror

STACK_SRC:= \
	stack/stack.c \
	stack/queue.c \
	stack/operations.c \
	stack/printer.c
SRC:= \
	main.c
OBJS:=${addprefix src/,${STACK_SRC:.c=.o} ${SRC:.c=.o}}
PRINTF:=lib/ft_printf/libftprintf.a
INCLUDE:= include

all: ${NAME}

${NAME}: ${PRINTF} ${OBJS}
	@${CC} ${PRINTF} ${OBJS} -o ${NAME} && echo "Compilation successful"

%.o: %.c
	@${CC} ${CFLAGS} ${addprefix -I ,${INCLUDE}} -c $< -o $@

${PRINTF}:
	@make -C lib/ft_printf/

clean:
	@make clean -C lib/ft_printf/
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${PRINTF}
	@rm -f ${NAME}

re: fclean all

bonus: re

.PHONY: clean fclean re bonus