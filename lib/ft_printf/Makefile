################################
######     Variables     #######
################################

NAME:=libftprintf.a
CC:=cc
CFLAGS= -Wall -Wextra -Werror
ifdef FSANITIZE
	CFLAGS+= -g3 -fsanitize=address
endif

###################################
######     Source files     #######
###################################

LIBFT_SRC:= \
	libft/ft_strchr.c \
	libft/ft_strlen.c \
	libft/ft_ptrlen.c \
	libft/ft_numlen.c \
	libft/ft_isdigit.c \
	libft/ft_isupper.c
PRINTERS_SRC:= \
	printers/cs.c \
	printers/diu.c \
	printers/xXp.c \
	printers/prefix.c \
	printers/printer.c
PARSERS_SRC:= \
	parsers/parsers.c \
	parsers/calc_numlen.c \
	parsers/calc_strlen.c \
	parsers/calc_states.c \
	parsers/peek.c \
	parsers/utils.c
MAIN_SRC:= \
	ft_printf.c \
	logic.c \
	sequencers.c \
	substitution_printer.c
SRC:=$(LIBFT_SRC) $(PRINTERS_SRC) $(PARSERS_SRC) $(MAIN_SRC)

###########################################
######     Object name reformat     #######
###########################################

SRC_DIR:=src
OBJ_DIR:=obj
OBJ:=$(addprefix $(OBJ_DIR)/,$(subst /,@,$(SRC:.c=.o)))

################################
######    Main rules     #######
################################

all:
	@${MAKE} $(NAME) -j

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

bonus: re

#########################################
######     Object compilation     #######
#########################################

.SECONDEXPANSION:
$(OBJ_DIR)/%.o: $(SRC_DIR)/$$(subst @,/,$$*).c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

###############################
######     Cleaning     #######
###############################

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus