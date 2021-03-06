# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sganon <sganon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/28 17:26:52 by sganon            #+#    #+#              #
#    Updated: 2018/07/28 23:59:03 by sganon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
OS = $(shell uname)

NAME ?= ft_ssl
BUILD_DIR ?= ./build

ifeq ($(OS), Linux)
	SRCS	= $(shell find src -regex '[a-zA-Z.\/_0-9]+\.c$$')
endif
ifeq ($(OS), Darwin)
	SRCS	= $(shell find -E src -regex '[a-zA-Z.\/_0-9]+\.c$$' | sed 's|^./||')
endif

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

CC_FLAGS = -Wall -Werror -Wextra
INC_FLAG = -I./includes -I./libft
DEPS_FLAG = -L./libft -lft

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
ifeq ($(CC_JSON_FLAG), -MJ)
	$(CC) $(CC_JSON_FLAG) $@.json $(CC_FLAGS) -c $< -o $@ $(INC_FLAG)
else
	$(CC) $(CC_FLAGS) -c $< -o $@ $(INC_FLAG)
endif

all : $(NAME)

deps:
	@echo "Updating dependencies (libft)"
	@sh ./install_deps.sh
	@echo "Building libft"
	@make -C libft/

$(NAME): deps $(OBJS)
	$(CC) $(OBJS) -o $@ $(INC_FLAG) $(DEPS_FLAG)
	@echo "ft_ssl created"

compile_commands.json:
	@rm -rf $(BUILD_DIR)
	@make CC_JSON_FLAG="-MJ" $(NAME)
	@/usr/bin/sed -e '1s/^/[\n/' -e '$$s/,$$/\n]/' $(BUILD_DIR)/**/*.o.json > compile_commands.json
clean:
	@make -C libft/ clean
	@rm -rf $(BUILD_DIR)
	@echo "Objects cleaned"

fclean : clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "ft_ssl cleaned"

re : fclean all

.PHONY : all clean fclean re
