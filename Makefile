# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tbruinem <tbruinem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/04/09 14:57:35 by tbruinem      #+#    #+#                  #
#    Updated: 2021/01/16 16:46:40 by tbruinem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#----------------------------------USERPREFS-----------------------------------

GNL_DIR = ../gnl/
GNL_INCL = ./

#----------------------------------FLAGS---------------------------------------

BUFFER_SIZE = 128
READEMPTYFD = 0
BONUS = 0

#----------------------------------VARIABLES-----------------------------------

NAME = gnltest
INCL_DIR = ./incl
SRC_DIR = ./src/
OBJ_DIR = ./obj/

GNL_SRC :=	get_next_line \
			get_next_line_utils
GNL_SRC :=	$(addprefix $(GNL_DIR), $(GNL_SRC))
ifeq ($(BONUS),1)
GNL_SRC :=	$(addsuffix _bonus, $(GNL_SRC))
endif
GNL_SRC :=	$(addsuffix .c, $(GNL_SRC))

SRC =	fd.c \
		main.c \
		utils.c

OBJ = $(SRC:%.c=%.o)

#----------------------------------RULES---------------------------------------

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) -D READEMPTYFD=$(READEMPTYFD) -D BUFFER_SIZE=$(BUFFER_SIZE) \
	-c -I $(INCL_DIR) -I $(GNL_DIR) $< -o $@

GNL:
	make -C $(GNL_DIR)

$(NAME): $(addprefix $(OBJ_DIR), $(OBJ))
	gcc -D READEMPTYFD=$(READEMPTYFD) -I $(INCL_DIR) \
	-I $(GNL_DIR) $(GNL_SRC) -D BUFFER_SIZE=$(BUFFER_SIZE) $^ -o $(NAME)

clean:
	rm -rf $(addprefix $(OBJ_DIR), $(OBJ))

fclean: clean
	rm -rf $(NAME)

re: fclean all
