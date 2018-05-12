# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 14:57:58 by pchadeni          #+#    #+#              #
#    Updated: 2018/05/12 21:47:57 by hlely            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------Name of the project------#

NAME = hlely.filler

#------Compilation's flags------#

CC = gcc

# flags
C_FLAGS = -Wall -Wextra

ifneq ($(NOERR),yes)
C_FLAGS += -Werror
endif

ifeq ($(DEV),yes)
FLAGS += -g
endif

ifeq ($(SAN),yes)
FLAGS += -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif

#------All sources------#

FILLER = main.c			\
		 parse_map.c	\
		 fill_map.c		\
		 put_piece.c	

#------All includes------#

LIBINC = ./libft
INC += -I$(LIBINC)/includes

INCLUDES = ./includes
INC += -I$(INCLUDES)

#------Path------#

SRCS_PATH = srcs
OBJ_PATH  = obj
FILLER_PATH = 
SRCS_FILLER += $(addprefix $(FILLER_PATH), $(FILLER))

SRCS += $(addprefix $(SRCS_PATH)/, $(SRCS_FILLER))

OBJP += $(addprefix ./$(OBJ_PATH)/, $(FILLER_PATH))

OBJ += $(addprefix ./$(OBJ_PATH)/, $(SRCS_FILLER:.c=.o))

#------Lib------#

LIB = ./libft/libft.a

#------Main rules------#

all: makelib $(OBJ_PATH) $(NAME)

makelib:
	@make -C $(LIBINC) NOERR=$(NOERR) DEV=$(DEV) SAN=$(SAN)

$(NAME): $(OBJ)
	@echo "Start making $(NAME)..."
	@$(CC) $(FLAGS) $(C_FLAGS) $(INC) -o $@ $^ $(LIB)
	@echo "$(BOLD_GREEN)$(NAME) created ✓$(EOC)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c
	@$(CC) $(FLAGS) $(C_FLAGS) $(INC) -o $@ -c $<
	@echo " $(COL_GREEN)[OK]$(EOC)    $(COL_YELLOW)Compiling:$(EOC)" $<

clean: cleanlib
	@rm -Rf $(OBJ_PATH)
	@echo "$(BOLD_GREEN)$(NAME) clean ✓$(EOC)"

fclean: clean fcleanlib
	@rm -Rf $(NAME)
	@echo "$(BOLD_GREEN)$(NAME) fclean ✓$(EOC)"

cleanlib:
	@make clean -C ./libft

fcleanlib:
	@make fclean -C ./libft

re: fclean all
#------Define colors------#

BOLD_GREEN = \033[01;32m
COL_GREEN = \033[0;32m
COL_YELLOW = \033[0;33m
EOC = \033[0m

.PHONY : re all clean fclean
