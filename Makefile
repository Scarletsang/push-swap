################################
######     Push swap     #######
################################

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
	stack/two_stacks.c \
	stack/queue.c \
	stack/operations.c \
	stack/printer.c
SRC:= \
	main.c
OBJS:=${addprefix src/,${PARSER_SRC:.c=.o} ${STACK_SRC:.c=.o} ${SRC:.c=.o}}
PRINTF:=lib/ft_printf/libftprintf.a
INCLUDE:= \
	include \
	lib/ft_printf/include

all: ${NAME}

${NAME}: ${PRINTF} ${OBJS}
	@${CC} ${PRINTF} ${OBJS} -o ${NAME} ${LDFLAGS} && echo "Compilation of ${NAME} successful"

%.o: %.c
	@${CC} ${CFLAGS} ${addprefix -I ,${INCLUDE}} -c $< -o $@

${PRINTF}:
	@make ${if ${FSANITIZE},FSANITIZE=yes,} -C lib/ft_printf/

##############################
######     Checker     #######
##############################

CHECKER_NAME:=checker
GET_NEXT_LINE:=lib/get_next_line/get_next_line.a
CHECKER_SRC:=
CHECKER_OBJS:=${addprefix checker_src/,${CHECKER_SRC:.c=.o}}

bonus: clean ${PRINTF} ${GET_NEXT_LINE} ${CHECKER_OBJS}
	@${CC} ${PRINTF} ${GET_NEXT_LINE} ${CHECKER_OBJS} -o ${CHECKER_OBJS} ${LDFLAGS} && echo "Compilation of ${CHECKER_NAME} successful"

${GET_NEXT_LINE}:
	@make ${if ${FSANITIZE},FSANITIZE=yes,} -C lib/get_next_line/

###############################
######     Cleaning     #######
###############################

clean:
	@make clean -C lib/ft_printf/
	@make clean -C lib/get_next_line/
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${PRINTF}
	@rm -f ${GET_NEXT_LINE}
	@rm -f ${NAME}

re: fclean all

.PHONY: clean fclean re bonus