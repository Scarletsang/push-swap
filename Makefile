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
SRC:= \
	main.c \
	shared.c
OBJS_DIR:=obj
SRCS_DIR:=src
OBJS:=$(addprefix $(OBJS_DIR)/,$(subst /,@,$(PARSER_SRC:.c=.o) $(STACK_SRC:.c=.o) $(INSTRUCTOR_SRC:.c=.o) $(TRIANGLE_PLANNER_SRC:.c=.o) $(TRIANGLE_MAKER_SRC:.c=.o) $(EMULATOR_SRC:.c=.o) $(SORTER_SRC:.c=.o) $(OPTIMIZER_SRC:.c=.o) $(SRC:.c=.o)))
PRINTF:=lib/ft_printf/libftprintf.a
LDFLAGS= -L lib/ft_printf -lftprintf
INCLUDE:= \
	include \
	lib/ft_printf/include

################################
######     Push swap     #######
################################

all:
	@${MAKE} $(NAME) -j

$(NAME): $(PRINTF) $(OBJS_DIR) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) && echo "Compilation of $(NAME) successful"

##############################
######     Checker     #######
##############################

CHECKER_NAME:=checker
GET_NEXT_LINE:=lib/get_next_line/get_next_line.a
CHECKER_SRC:= \
	checker_main.c \
	shared.c \
	checker/parse_operation.c \
	checker/stack_manipulator.c
CHECKER_OBJS:=$(addprefix $(OBJS_DIR)/,$(subst /,@,$(PARSER_SRC:.c=.o) $(STACK_SRC:.c=.o) $(CHECKER_SRC:.c=.o)))

bonus: INCLUDE+= lib/get_next_line/include
bonus: LDFLAGS+= ${GET_NEXT_LINE}
bonus: $(PRINTF) $(GET_NEXT_LINE) $(OBJS_DIR) $(CHECKER_OBJS)
	@$(CC) $(CHECKER_OBJS) -o $(CHECKER_NAME) $(LDFLAGS) && echo "Compilation of $(CHECKER_NAME) successful"

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
$(OBJS_DIR)/%.o: $(SRCS_DIR)/$$(subst @,/,$$*).c
	@$(CC) $(CFLAGS) $(addprefix -iquote ,$(INCLUDE)) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

###############################
######     Cleaning     #######
###############################

clean:
	@${MAKE} clean -C lib/ft_printf/
	@${MAKE} clean -C lib/get_next_line/
	@rm -f $(OBJS)
	@rm -f $(CHECKER_OBJS)

fclean: clean
	@rm -f $(PRINTF)
	@rm -f $(GET_NEXT_LINE)
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)
	@rm -f $(CHECKER_NAME)

re: fclean all

.PHONY: clean fclean re bonus
