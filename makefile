.PHONY : all clean fclean re clear mandatory bonus norminette main bmain

NAME = minitalk

# ╭━━━━━━━━━━━━══════════╕出 ❖ BASICS VARIABLES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

CC := cc

CFLAGS := -Wall -Wextra -Werror

RM := rm -rf

# ╰━━━━━━━━━━━━━━━━════════════════╛出 ❖ 力╘════════════════━━━━━━━━━━━━━━━━╯ #

# ╭━━━━━━━━━━━━══════════╕出 ❖ FILE TREE ❖ 力╒═══════════━━━━━━━━━━━━╮ #

# file lists
LST_SRC =	client.c, server.c		\

LIB	=	ft_printf/

# ╭━━━━━━━━━━━━══════════╕出 ❖ RULES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

all : $(NAME)

$(NAME) : makeprintf
	@$(CC) -Ift_printf/inc -I. -Lft_printf client.c -o client -lftprintf
	@$(CC) -Ift_printf/inc -I. -Lft_printf server.c -o server -lftprintf
	@echo "\e[0;32mLe client et le server ont été créés avec succès ! 🧬\e[0m"

makeprintf:
	$(MAKE) -C ft_printf all

clean:
	@$(RM) client server
	@$(MAKE) -C ft_printf clean
	@echo "\e[0;36mClient et server supprimés 🧹\e[0m"

fclean:
	@$(MAKE) -s SHOW_MSG_CLEAN=false clean
	@$(MAKE) -C ft_printf fclean

re :
	$(MAKE) fclean
	$(MAKE) all
	@echo "\e[0;32mExecutables recréés avec succès ! 🫡\e[0m"