NAME:=push_swap

CC:=cc
CFLAGS= -Wall -Wextra -Werror
ifdef FSANITIZE
	CFLAGS+= -g3 -fsanitize=address
	LDFLAGS+= -g3 -fsanitize=address
endif

PARSER_SRC:= \
	parser/parser.c \
	parser/collector.c \
	parser/parse_from_cli.c \
	parser/parse_number.c
STACK_SRC:= \
	stack/stack.c \
	stack/queue.c \
	stack/operations.c \
	stack/printer.c
SORTER_SRC:= \
	sorter/sorter.c \
	sorter/printer.c
SRC:= \
	main.c
OBJS:=${addprefix src/,${PARSER_SRC:.c=.o} ${STACK_SRC:.c=.o} ${SORTER_SRC:.c=.o} ${SRC:.c=.o}}
PRINTF:=lib/ft_printf/libftprintf.a
INCLUDE:= include

all: ${NAME}

${NAME}: ${PRINTF} ${OBJS}
	@${CC} ${PRINTF} ${OBJS} -o ${NAME} ${LDFLAGS} && echo "Compilation successful"

%.o: %.c
	@${CC} ${CFLAGS} ${addprefix -I ,${INCLUDE}} -c $< -o $@

${PRINTF}:
	@make ${if ${FSANITIZE},FSANITIZE=yes,} -C lib/ft_printf/

clean:
	@make clean -C lib/ft_printf/
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${PRINTF}
	@rm -f ${NAME}

re: fclean all

bonus: re

.PHONY: clean fclean re bonus