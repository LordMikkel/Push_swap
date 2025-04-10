# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 16:22:48 by migarrid          #+#    #+#              #
#    Updated: 2025/04/10 22:46:23 by migarrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de la biblioteca
NAME =			push_swap
BONUS_NAME=		checker

# Compilador y opciones
CC =		cc
CFLAGS =	-Wall -Wextra -Werror

# Comandos
PRINTF =	printf
RM = 		rm -f

# Directorios
INCLUDE_DIR =		includes
LIB_DIR =			lib
OBJ_DIR =			obj
SRC_DIR =			src
SRC_BONUS_DIR =		src/bonus
CHECK_DIR =			checker

# Colores
DEFAULT =	\033[0;39m
GREEN =		\033[0;92m
BLUE =		\033[0;94m
MAGENTA =	\033[0;95m
CYAN =		\033[0;96m
YELLOW =	\033[0;33m
RED =		\033[0;31m

# Variable
ARGS = ${CHECK_DIR}/python3 random_numbers.py

# Variables de progreso
SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

# Archivos fuente obligatorios
SRCS =	push_swap.c \
		ft_error_free.c \
		ft_args_check.c \
		ft_args_split.c \
		ft_args_array.c \
		ft_sort_init.c \
		ft_sort_algorithm.c \
		ft_sort_check.c \
		ft_sort_helper.c \
		ft_sort_utils.c \
		ft_instructions.c \
		ft_instructions_printer.c \
		#checker_bonus.c \

# Objetos obligatorios
OBJS = 			$(SRCS:%.c=$(OBJ_DIR)/%.o)
#OBJS_BONUS =	$(SRCS_BONUS:%.c=$(OBJ_DIR)/%.o)

# Crear la carpeta obj si no existe
${OBJS}: | ${OBJ_DIR}
#${OBJS_BONUS}: | ${OBJ_DIR}
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
#	@mkdir -p ${OBJ_DIR}/bonus

# Regla para compilar archivos .c a .o con barra de progreso
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | $(OBJ_DIR)
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -I. -c -o $@ $<

# Regla principal: compilar la biblioteca
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ${LIB_DIR}/libft_plus.a
	@$(PRINTF) "\r%100s\r$(GREEN)$(NAME) is up to date!$(DEFAULT)\n"

$(BONUS_NAME): $(OBJS_BONUS)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME)/libft_plus.a
	@$(PRINTF) "\r%100s\r$(MAGENTA) Bonus $(NAME) is up to date!$(DEFAULT)\n"
	@touch .bonus

# Regla para compilar el bonus
bonus: .bonus
.bonus: ${BONUS_NAME}

# Realizar test
test3: $(NAME)
	@$(PRINTF) "$(CYAN)\n╔════════════════════════════════════════╗$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)║     Initializing tests for push_swap   ║$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)╚════════════════════════════════════════╝$(DEFAULT)\n\n"
	@$(PRINTF) "$(CYAN)🔧 Compilando tests...$(DEFAULT)\n"
	@$(PRINTF) "$(DEFAULT)🔍 Ejecutando Valgrind para verificar memoria...$(DEFAULT)\n\n"
	@ARGS=$$(python3 $(CHECK_DIR)/random_numbers.py 3); \
	$(PRINTF) "🔢 Input: $(MAGENTA)$$ARGS\n"; \
	$(PRINTF) "$(DEFAULT)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $$ARGS; \
	$(PRINTF) "$(DEFAULT)📊 Operation count: $(YELLOW)"; \
	./push_swap $$ARGS | wc -l; \
	$(PRINTF) "$(DEFAULT)🧪 Checking with checker_linux:$(BLUE) "; \
	CHECKER_OUTPUT=$$(./push_swap $$ARGS | ${CHECK_DIR}/checker_linux $$ARGS 2>&1); \
	if [ "$$CHECKER_OUTPUT" = "OK" ]; then \
		$(PRINTF) "$(GREEN)$$CHECKER_OUTPUT$(DEFAULT)"; \
	else \
		$(PRINTF) "$(RED)$$CHECKER_OUTPUT$(DEFAULT)"; \
	fi; \
	$(PRINTF) "\n$(GREEN)✅ Tests completados!$(DEFAULT)\n"

test5: $(NAME)
	@$(PRINTF) "$(CYAN)\n╔════════════════════════════════════════╗$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)║     Initializing tests for push_swap   ║$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)╚════════════════════════════════════════╝$(DEFAULT)\n\n"
	@$(PRINTF) "$(CYAN)🔧 Compilando tests...$(DEFAULT)\n"
	@$(PRINTF) "$(DEFAULT)🔍 Ejecutando Valgrind para verificar memoria...$(DEFAULT)\n\n"
	@ARGS=$$(python3 $(CHECK_DIR)/random_numbers.py 5); \
	$(PRINTF) "🔢 Input: $(MAGENTA)$$ARGS\n"; \
	$(PRINTF) "$(DEFAULT)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $$ARGS; \
	$(PRINTF) "$(DEFAULT)📊 Operation count: $(YELLOW)"; \
	./push_swap $$ARGS | wc -l; \
	$(PRINTF) "$(DEFAULT)🧪 Checking with checker_linux:$(BLUE) "; \
	CHECKER_OUTPUT=$$(./push_swap $$ARGS | ${CHECK_DIR}/checker_linux $$ARGS 2>&1); \
	if [ "$$CHECKER_OUTPUT" = "OK" ]; then \
		$(PRINTF) "$(GREEN)$$CHECKER_OUTPUT$(DEFAULT)"; \
	else \
		$(PRINTF) "$(RED)$$CHECKER_OUTPUT$(DEFAULT)"; \
	fi; \
	$(PRINTF) "\n$(GREEN)✅ Tests completados!$(DEFAULT)\n"

test25: $(NAME)
	@$(PRINTF) "$(CYAN)\n╔════════════════════════════════════════╗$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)║     Initializing tests for push_swap   ║$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)╚════════════════════════════════════════╝$(DEFAULT)\n\n"
	@$(PRINTF) "$(CYAN)🔧 Compilando tests...$(DEFAULT)\n"
	@$(PRINTF) "$(DEFAULT)🔍 Ejecutando Valgrind para verificar memoria...$(DEFAULT)\n\n"
	@ARGS=$$(python3 $(CHECK_DIR)/random_numbers.py 25); \
	$(PRINTF) "🔢 Input: $(MAGENTA)$$ARGS\n"; \
	$(PRINTF) "$(DEFAULT)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $$ARGS; \
	$(PRINTF) "$(DEFAULT)📊 Operation count: $(YELLOW)"; \
	./push_swap $$ARGS | wc -l; \
	$(PRINTF) "$(DEFAULT)🧪 Checking with checker_linux:$(BLUE) "; \
	CHECKER_OUTPUT=$$(./push_swap $$ARGS | ${CHECK_DIR}/checker_linux $$ARGS 2>&1); \
	if [ "$$CHECKER_OUTPUT" = "OK" ]; then \
		$(PRINTF) "$(GREEN)$$CHECKER_OUTPUT$(DEFAULT)"; \
	else \
		$(PRINTF) "$(RED)$$CHECKER_OUTPUT$(DEFAULT)"; \
	fi; \
	$(PRINTF) "\n$(GREEN)✅ Tests completados!$(DEFAULT)\n"

test50: $(NAME)
	@$(PRINTF) "$(CYAN)\n╔════════════════════════════════════════╗$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)║     Initializing tests for push_swap   ║$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)╚════════════════════════════════════════╝$(DEFAULT)\n\n"
	@$(PRINTF) "$(CYAN)🔧 Compilando tests...$(DEFAULT)\n"
	@$(PRINTF) "$(DEFAULT)🔍 Ejecutando Valgrind para verificar memoria...$(DEFAULT)\n\n"
	@ARGS=$$(python3 $(CHECK_DIR)/random_numbers.py 50); \
	$(PRINTF) "🔢 Input: $(MAGENTA)$$ARGS\n"; \
	$(PRINTF) "$(DEFAULT)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $$ARGS; \
	$(PRINTF) "$(DEFAULT)📊 Operation count: $(YELLOW)"; \
	./push_swap $$ARGS | wc -l; \
	$(PRINTF) "$(DEFAULT)🧪 Checking with checker_linux:$(BLUE) "; \
	CHECKER_OUTPUT=$$(./push_swap $$ARGS | ${CHECK_DIR}/checker_linux $$ARGS 2>&1); \
	if [ "$$CHECKER_OUTPUT" = "OK" ]; then \
		$(PRINTF) "$(GREEN)$$CHECKER_OUTPUT$(DEFAULT)"; \
	else \
		$(PRINTF) "$(RED)$$CHECKER_OUTPUT$(DEFAULT)"; \
	fi; \
	$(PRINTF) "\n$(GREEN)✅ Tests completados!$(DEFAULT)\n"

test100: $(NAME)
	@$(PRINTF) "$(CYAN)\n╔════════════════════════════════════════╗$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)║     Initializing tests for push_swap   ║$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)╚════════════════════════════════════════╝$(DEFAULT)\n\n"
	@$(PRINTF) "$(CYAN)🔧 Compilando tests...$(DEFAULT)\n"
	@$(PRINTF) "$(DEFAULT)🔍 Ejecutando Valgrind para verificar memoria...$(DEFAULT)\n\n"
	@ARGS=$$(python3 $(CHECK_DIR)/random_numbers.py 100); \
	$(PRINTF) "🔢 Input: $(MAGENTA)$$ARGS\n"; \
	$(PRINTF) "$(DEFAULT)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $$ARGS; \
	$(PRINTF) "$(DEFAULT)📊 Operation count: $(YELLOW)"; \
	./push_swap $$ARGS | wc -l; \
	$(PRINTF) "$(DEFAULT)🧪 Checking with checker_linux:$(BLUE) "; \
	CHECKER_OUTPUT=$$(./push_swap $$ARGS | ${CHECK_DIR}/checker_linux $$ARGS 2>&1); \
	if [ "$$CHECKER_OUTPUT" = "OK" ]; then \
		$(PRINTF) "$(GREEN)$$CHECKER_OUTPUT$(DEFAULT)"; \
	else \
		$(PRINTF) "$(RED)$$CHECKER_OUTPUT$(DEFAULT)"; \
	fi; \
	$(PRINTF) "\n$(GREEN)✅ Tests completados!$(DEFAULT)\n"

test500: $(NAME)
	@$(PRINTF) "$(CYAN)\n╔════════════════════════════════════════╗$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)║     Initializing tests for push_swap   ║$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)╚════════════════════════════════════════╝$(DEFAULT)\n\n"
	@$(PRINTF) "$(CYAN)🔧 Compilando tests...$(DEFAULT)\n"
	@$(PRINTF) "$(DEFAULT)🔍 Ejecutando Valgrind para verificar memoria...$(DEFAULT)\n\n"
	@ARGS=$$(python3 $(CHECK_DIR)/random_numbers.py 500); \
	$(PRINTF) "🔢 Input: $(MAGENTA)$$ARGS\n"; \
	$(PRINTF) "$(DEFAULT)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $$ARGS; \
	$(PRINTF) "$(DEFAULT)📊 Operation count: $(YELLOW)"; \
	./push_swap $$ARGS | wc -l; \
	$(PRINTF) "$(DEFAULT)🧪 Checking with checker_linux:$(BLUE) "; \
	CHECKER_OUTPUT=$$(./push_swap $$ARGS | ${CHECK_DIR}/checker_linux $$ARGS 2>&1); \
	if [ "$$CHECKER_OUTPUT" = "OK" ]; then \
		$(PRINTF) "$(GREEN)$$CHECKER_OUTPUT$(DEFAULT)"; \
	else \
		$(PRINTF) "$(RED)$$CHECKER_OUTPUT$(DEFAULT)"; \
	fi; \
	$(PRINTF) "\n$(GREEN)✅ Tests completados!$(DEFAULT)\n"

test1000: $(NAME)
	@$(PRINTF) "$(CYAN)\n╔════════════════════════════════════════╗$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)║     Initializing tests for push_swap   ║$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)╚════════════════════════════════════════╝$(DEFAULT)\n\n"
	@$(PRINTF) "$(CYAN)🔧 Compilando tests...$(DEFAULT)\n"
	@$(PRINTF) "$(DEFAULT)🔍 Ejecutando Valgrind para verificar memoria...$(DEFAULT)\n\n"
	@ARGS=$$(python3 $(CHECK_DIR)/random_numbers.py 1000); \
	$(PRINTF) "🔢 Input: $(MAGENTA)$$ARGS\n"; \
	$(PRINTF) "$(DEFAULT)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $$ARGS; \
	$(PRINTF) "$(DEFAULT)📊 Operation count: $(YELLOW)"; \
	./push_swap $$ARGS | wc -l; \
	$(PRINTF) "$(DEFAULT)🧪 Checking with checker_linux:$(BLUE) "; \
	CHECKER_OUTPUT=$$(./push_swap $$ARGS | ${CHECK_DIR}/checker_linux $$ARGS 2>&1); \
	if [ "$$CHECKER_OUTPUT" = "OK" ]; then \
		$(PRINTF) "$(GREEN)$$CHECKER_OUTPUT$(DEFAULT)"; \
	else \
		$(PRINTF) "$(RED)$$CHECKER_OUTPUT$(DEFAULT)"; \
	fi; \
	$(PRINTF) "\n$(GREEN)✅ Tests completados!$(DEFAULT)\n"

# Realizar test bonus
testbonus: $(NAME) main.c
	@$(PRINTF) "$(CYAN)\n╔════════════════════════════════════════╗$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)║     Initializing tests for checker     ║$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)╚════════════════════════════════════════╝$(DEFAULT)\n\n"
	@$(PRINTF) "$(CYAN)🔧 Compilando tests bonus...$(DEFAULT)\n"
	@$(PRINTF) "\n$(GREEN)✅ Tests bonus completados!$(DEFAULT)\n"

# Limpiar objetos
clean:
	@$(PRINTF) "$(CYAN)Cleaning up object files...$(DEFAULT)\n"
	@make clean -C $(LIB_DIR)
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) $(OBJS)

# Limpiar todo (objetos + biblioteca)
fclean: clean
	@make fclean -C $(LIB_DIR)
	@$(RM) $(NAME)
#	@${RM} ${BONUS_NAME}
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

# Recompilar todo desde cero sin bonus
re: 		fclean all

# Recompilar todo desde cero
rebonus: 	fclean bonus

# Asegurar que las reglas se ejecuten como comandos del make
.PHONY: 	all bonus test clean fclean test testbonus re rebonus
