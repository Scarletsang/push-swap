################################
######     Variables     #######
################################

NAME:=push_swap
CHECKER_NAME:=checker
CC:=cc
CFLAGS= -Wall -Wextra -Werror
ifdef FSANITIZE
	CFLAGS+= -g3 -fsanitize=address
	LDFLAGS+= -g3 -fsanitize=address
endif
INCLUDE_DIR:= include

###################################
######     Source files     #######
###################################

# To add souce files, create a varaible for each folder, and then
# contatenate them in the SRC variable like this:

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
INSTRUCTOR_SRC:=\
	sorter/instructor/instruction.c \
	sorter/instructor/instructor.c \
	sorter/instructor/instruction_adder.c \
	sorter/instructor/instruction_executor.c \
	sorter/instructor/printer.c
TRIANGLE_PLANNER_SRC:= \
	sorter/triangle_planner/triangles_planner.c \
	sorter/triangle_planner/triangles_getter.c \
	sorter/triangle_planner/calculate_triangle_shape.c \
	sorter/triangle_planner/calculate_triangle_size.c \
	sorter/triangle_planner/triangles_calculator.c \
	sorter/triangle_planner/printer.c
TRIANGLE_MAKER_SRC:= \
	sorter/triangle_maker/triangle_maker.c \
	sorter/triangle_maker/stack_a_formula_size4.c \
	sorter/triangle_maker/stack_a_formula_size2356.c \
	sorter/triangle_maker/emulation.c
EMULATOR_SRC:= \
	sorter/triangle_maker/emulator/emulator.c \
	sorter/triangle_maker/emulator/emulated_instructor.c \
	sorter/triangle_maker/emulator/stack_b_formula.c \
	sorter/triangle_maker/emulator/priority_elements_mover.c
SORTER_SRC:= \
	sorter/sorter.c \
	sorter/merger.c \
	sorter/sorter_merge.c
OPTIMIZER_SRC:= \
	optimizer/optimizer.c \
	optimizer/striker.c \
	optimizer/combiner.c
MAIN_SRC:= \
	main.c \
	shared.c
CHECKER_MAIN_SRC:= \
	checker_main.c \
	shared.c \
	checker/parse_operation.c \
	checker/stack_manipulator.c
SRC:=$(PARSER_SRC) $(STACK_SRC) $(INSTRUCTOR_SRC) $(TRIANGLE_PLANNER_SRC) $(TRIANGLE_MAKER_SRC) $(EMULATOR_SRC) $(SORTER_SRC) $(OPTIMIZER_SRC) $(MAIN_SRC)
CHECKER_SRC:=$(PARSER_SRC) $(STACK_SRC) $(CHECKER_MAIN_SRC)

####################################
######     Library files     #######
####################################

# To compile a library, store a variable for their library file and add a rule for it after the main rules
PRINTF=lib/ft_printf/libftprintf.a
GET_NEXT_LINE=lib/get_next_line/get_next_line.a

# To add a library, add the library header file like this:
INCLUDE_DIR+=lib/ft_printf/include

# Then add the library to the linking process in one of the following ways:
# LDFLAGS+= -Llib/LIBRARY_NAME -lLIBRARY_NAME
# LDFLAGS+= lib/LIBRARY_NAME/libLIBRARY_NAME.a
LDFLAGS+= -L lib/ft_printf -lftprintf

###########################################
######     Object name reformat     #######
###########################################

# This in effect makes all the object files to be compiled in the OBJ_DIR directory

SRC_DIR:=src
OBJ_DIR:=obj
OBJ:=$(addprefix $(OBJ_DIR)/,$(subst /,@,$(SRC:.c=.o)))

################################
######    Main rules     #######
################################

all:
	@${MAKE} $(NAME) -j

$(NAME): $(PRINTF) $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) && echo "Compilation of $(NAME) successful"

bonus: $(CHECKER_NAME)

$(CHECKER_NAME): INCLUDE_DIR+= lib/get_next_line/include
$(CHECKER_NAME): LDFLAGS+= ${GET_NEXT_LINE}
$(CHECKER_NAME): OBJ:=$(addprefix $(OBJ_DIR)/,$(subst /,@,$(CHECKER_SRC:.c=.o)))
.SECONDEXPANSION:
$(CHECKER_NAME): $(PRINTF) $(GET_NEXT_LINE) $$(OBJ)
	@$(CC) $(OBJ) -o $(CHECKER_NAME) $(LDFLAGS) && echo "Compilation of $(CHECKER_NAME) successful"

##########################################
######     Library compilation     #######
##########################################

$(PRINTF):
	@${MAKE} $(if $(FSANITIZE),FSANITIZE=yes,) -C lib/ft_printf/

$(GET_NEXT_LINE):
	@${MAKE} $(if $(FSANITIZE),FSANITIZE=yes,) -C lib/get_next_line/

#########################################
######     Object compilation     #######
#########################################

.SECONDEXPANSION:
$(OBJ_DIR)/%.o: $(SRC_DIR)/$$(subst @,/,$$*).c
	@$(CC) $(CFLAGS) $(addprefix -iquote ,$(INCLUDE_DIR)) -c $< -o $@

$(OBJ): $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

###############################
######     Cleaning     #######
###############################

clean:
	@${MAKE} clean -C lib/ft_printf/
	@${MAKE} clean -C lib/get_next_line/
	@rm -f $(OBJ_DIR)/*.o

fclean: clean
	@rm -f $(PRINTF)
	@rm -f $(GET_NEXT_LINE)
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@rm -f $(CHECKER_NAME)

re: fclean all

.PHONY: clean fclean re bonus