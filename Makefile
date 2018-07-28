# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sganon <sganon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/28 17:26:52 by sganon            #+#    #+#              #
#    Updated: 2018/07/28 18:29:30 by sganon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME ?= ft_ssl
BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

SRCS := $(shell find -E . -regex '[a-zA-Z.\/_]+\.c$$' | sed 's|^./||')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

CC_FLAGS = -Wall -Werror -Wextra
INC_FLAG = -I./includes

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) -c $< -o $@ $(INC_FLAG)

all : $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $@ $(INC_FLAG)
		@echo "ft_ssl created"

clean:
		@rm -rf $(BUILD_DIR)
		@echo "Objects cleaned"

fclean : clean
		@rm -f $(NAME)
		@echo "ft_ssl cleaned"

re : fclean all

.PHONY : all clean fclean re