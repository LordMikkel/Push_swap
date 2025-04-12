# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 16:22:48 by migarrid          #+#    #+#              #
#    Updated: 2025/04/12 04:07:07 by migarrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de la biblioteca
NAME				= push_swap
BONUS_NAME			= checker

# Compilador y opciones
CC					= cc
CFLAGS				= -Wall -Wextra -Werror -g #-fsanitize=address

# Comandos
PRINTF				= printf
RM 					= rm -f

# Directorios
INCLUDE_DIR			= includes
LIB_DIR 			= lib
OBJ_DIR 			= obj
OBJ_BONUS_DIR		= obj/bonus
SRC_DIR 			= src
SRC_BONUS_DIR		= src/bonus
CHECK_DIR			= checking

# Colores
DEFAULT				= \033[0;39m
GREEN 				= \033[0;92m
BLUE 				= \033[0;94m
MAGENTA 			= \033[0;95m
CYAN 				= \033[0;96m
YELLOW 				= \033[0;33m
RED 				= \033[0;31m
GREY 				= \033[38;5;240m
PURPLE 				= \033[38;5;141m
RESET 				= \033[0m
BOLD 				= \033[1m
CLEAR 				= \r\033[K

# Variable
ARGS = ${CHECK_DIR}/python3 random_numbers.py

# Archivos fuente obligatorios
SRCS =				push_swap.c \
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

SRC_BONUS = 		checker_bonus.c \
					ft_init_checker_bonus.c \
					ft_handle_action_bonus.c \
					ft_instructions_bonus.c \
					ft_sort_check_bonus.c \
					ft_error_free_bonus.c \
					ft_args_check_bonus.c \
					ft_args_split_bonus.c \
					ft_args_array_bonus.c \

# Variables de progreso
SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

BONUS_COUNT_TOT := $(shell echo -n $(SRC_BONUS) | wc -w)
ifeq ($(shell test $(BONUS_COUNT_TOT) -le 0; echo $$?),0)
	BONUS_COUNT_TOT := $(shell echo -n $(SRC_BONUS) | wc -w)
endif
BONUS_COUNT := 0
BONUS_PCT = $(shell expr 100 \* $(BONUS_COUNT) / $(BONUS_COUNT_TOT))

# Objetos obligatorios
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS 	= $(SRC_BONUS:%.c=$(OBJ_BONUS_DIR)/%.o)

# Crear la carpeta obj si no existe
${OBJS}: | ${OBJ_DIR}
${OBJS_BONUS}: |  $(OBJ_DIR)
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p ${OBJ_DIR}/bonus

# Regla para compilar archivos .c a .o con barra de progreso
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ./includes/push_swap.h Makefile
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)...\n" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -I. -c -o $@ $<

# Cómo cada archivo .c a .o (Obligatorio + Bonus)
$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c ./includes/push_swap.h Makefile
	@$(eval BONUS_COUNT = $(shell expr $(BONUS_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(MAGENTA)$<$(DEFAULT)...\n" "" $(BONUS_COUNT) $(BONUS_COUNT_TOT) $(BONUS_PCT)
	@$(CC) $(CFLAGS) -I. -c -o $@ $<

# Regla principal: compilar el programa
all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ${LIB_DIR}/libft_plus.a
	@printf "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: ${RED}${BOLD}${NAME} ${RESET}compiled ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

# Regla para compilar el bonus
bonus: $(NAME) ${BONUS_NAME}

$(BONUS_NAME): $(OBJS_BONUS) | $(OBJ_BONUS_DIR)
	@make -s -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME) $(LIB_DIR)/libft_plus.a
	@printf "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${BONUS_NAME}${RESET}]: ${RED}${BOLD}${BONUS_NAME} ${RESET}compiled ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

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

errors: $(NAME)
	@$(PRINTF) "$(CYAN)\n╔════════════════════════════════════════╗$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)║     Initializing tests for push_swap   ║$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)╚════════════════════════════════════════╝$(DEFAULT)\n\n"
	@$(PRINTF) "$(CYAN)🔧 Compilando tests...$(DEFAULT)\n"
	@$(PRINTF) "$(DEFAULT)🔍 Ejecutando Valgrind para verificar memoria...$(DEFAULT)\n\n"
	$(PRINTF) "$(RED)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap; \
	$(PRINTF) "$(RED)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap '#'; \
	$(PRINTF) "$(RED)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 1 1; \
	$(PRINTF) "$(RED)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap "2147483648"; \
	$(PRINTF) "$(RED)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap "-2147483649"; \
	$(PRINTF) "$(RED)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap "1 2 3 hola 4 5"; \
	$(PRINTF) "$(RED)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap '1' '2' '3' ' ' '4' '5'; \
	$(PRINTF) "$(RED)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap '42'; \
	$(PRINTF) "$(RED)🎰 Output push_swap:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap "1 2 3"; \
	$(PRINTF) "\n$(GREEN)✅ Tests completados!$(DEFAULT)\n"

errorsbonus: $(NAME)
	@$(PRINTF) "$(CYAN)\n╔════════════════════════════════════════╗$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)║     Initializing tests for push_swap   ║$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)╚════════════════════════════════════════╝$(DEFAULT)\n\n"
	@$(PRINTF) "$(CYAN)🔧 Compilando tests...$(DEFAULT)\n"
	@$(PRINTF) "$(DEFAULT)🔍 Ejecutando Valgrind para verificar memoria...$(DEFAULT)\n\n"
	$(PRINTF) "$(RED)🎰 Output checker:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./checker 'e';\
	$(PRINTF) "$(RED)🎰 Output checker:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./checker 1 1; \
	$(PRINTF) "$(RED)🎰 Output checker:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./checker "2147483648"; \
	$(PRINTF) "$(RED)🎰 Output checker:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./checker "-2147483649"; \
	$(PRINTF) "$(RED)🎰 Output checker:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./checker; \
	$(PRINTF) "$(RED)🎰 Output checker:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./checker '3' '2' '1';\
	$(PRINTF) "$(RED)🎰 Output checker:$(DEFAULT)\n"; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./checker 3 2 1; \
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
	@make clean -s -C $(LIB_DIR)
	@$(RM) -rf $(OBJ_DIR)
	@printf "${CLEAR}${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Objects were cleaned ${GREEN}successfully${RESET}.\n${RESET}"
	@$(RM) $(OBJS)

# Limpiar todo (objetos + biblioteca)
fclean: clean
	@make fclean -s -C $(LIB_DIR)
	@$(RM) $(NAME)
	@${RM} ${BONUS_NAME}
	@printf "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Project cleaned ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

# Recompilar todo desde cero sin bonus
re: 		fclean all

# Recompilar todo desde cero con bonus
rebonus: 		fclean all bonus

# Asegurar que las reglas se ejecuten como comandos del make
.PHONY: 	all bonus test3 test5 test50 test100 test500 test1000 errrors testbonus re rebonus clean fclean
