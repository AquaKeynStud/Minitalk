.PHONY : all clean fclean re clear mandatory bonus norminette main bmain

NAME = libftprintf.a

# ╭━━━━━━━━━━━━══════════╕出 ❖ BASICS VARIABLES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

CC := cc

CFLAGS := -Wall -Wextra -Werror

RM := rm -rf

SHOW_MSG_CLEAN = true

# ╰━━━━━━━━━━━━━━━━════════════════╛出 ❖ 力╘════════════════━━━━━━━━━━━━━━━━╯ #

# ╭━━━━━━━━━━━━══════════╕出 ❖ FILE TREE ❖ 力╒═══════════━━━━━━━━━━━━╮ #

# directories
D_SRC = src/
D_INC = inc/
D_OBJ = .obj/

# file lists
LST_SRC =	mandatory_main.c		\
			mandatory_handlers.c	\
			mandatory_printers.c	\
			utils.c					\
			mandatory_parser.c		\

LST_INC = 	ft_printf.h				\

# files paths
SRC  =	$(addprefix $(D_SRC), $(LST_SRC))
INC  = 	$(addprefix $(D_INC), $(LST_INC))
OBJ  = 	$(subst  $(D_SRC), $(D_OBJ), $(SRC:.c=.o))

# ╭━━━━━━━━━━━━══════════╕出 ❖ RULES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\e[0;32mArchive de ft_printf créée avec succès ! 🧬\e[0m"

$(D_OBJ)%.o: $(D_SRC)%.c $(D_INC)ft_printf.h
	@mkdir -p $(D_OBJ)
	$(CC) $(FLAGS) -I$(D_INC) -c $< -o $@

clean:
ifeq ($(SHOW_MSG_CLEAN), true)
	@echo "\e[0;36mJ'ai enlevé tous les objets relatifs à ft_printf 🧹\e[0m"
endif
	@$(RM) $(D_OBJ)

fclean:
	@$(MAKE) -s SHOW_MSG_CLEAN=false clean
	@$(RM) $(NAME) mandatory_tester bonus_tester .bonus
	@echo "\e[0;34mArchive de ft_printf nettoyée 🧼\e[0m"

re :
	$(MAKE) fclean
	$(MAKE) all
	@echo "\e[0;32mArchive de ft_printf recréée avec succès ! 🫡\e[0m"

norminette :
	norminette -R CheckForbiddenSourceHeader $(D_SRC) $(D_INC)