# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/15 23:16:08 by dpattij           #+#    #+#              #
#    Updated: 2020/01/31 23:17:15 by dpattij          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_three

FLAGS_RELEASE = -Wall -Wextra -Werror -O3 -pedantic -lpthread

INCLUDE_DIR = ./include/
OBJ_DIR = ./obj/
SRC_DIR = ./src/

SRC_FILES =	main \
			not_atoi \
			not_isdigit \
			parse_arguments \
			puts_unlocked \
			alloc_p \
			println \
			throw_fatal \
			new_sem_p \
			gettime \
			check_death \
			check_failure \
			check_meal_completion \
			philosopher_check_death \
			philosopher_core \
			philosopher_main \
			spawn_child \
			init_simulation

SRC_FILES := $(SRC_FILES:%=%.o)
SRC_OBJECTS = $(SRC_FILES:%=%)
REL_FILES := $(SRC_FILES:%.o=$(SRC_DIR)%.c)

all: $(NAME)

$(NAME):
	$(CC)	$(REL_FILES) \
			-I $(INCLUDE_DIR) \
			-o $(NAME) \
			$(FLAGS_RELEASE)

clean:
	rm -rf	$(SRC_OBJECTS) $(OBJ_DIR) bonus

fclean: clean
	rm -rf	$(NAME)

re: fclean
	$(MAKE)

bonus: all

debug: FLAGS_RELEASE = -Wall -Wextra -Werror -O3 -pedantic -lpthread #-fsanitize=address
debug: all

rdb: fclean
	$(MAKE) debug

rb:
	rm -rf	$(NAME)
	rm -rf	$(SRC_OBJECTS) $(OBJ_DIR)
	$(MAKE)

rbb:
	rm -rf $(NAME)
	rm -rf $(SRC_OBJECTS) $(OBJ_DIR)
	$(MAKE) bonus
