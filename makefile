.PHONY : all clean fclean re clear mandatory bonus norminette main bmain

NAME = minitalk

# ╭━━━━━━━━━━━━══════════╕出 ❖ BASICS VARIABLES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

CC := cc

CFLAGS := -Wall -Wextra -Werror

RM := rm -rf

MAKEFLAGS += --no-print-directory

# ╰━━━━━━━━━━━━━━━━════════════════╛出 ❖ 力╘════════════════━━━━━━━━━━━━━━━━╯ #

# ╭━━━━━━━━━━━━══════════╕出 ❖ FILE TREE ❖ 力╒═══════════━━━━━━━━━━━━╮ #

# directories
LIB		:=	ft_printf/
INC		:=	inc/
SRC		:=	src/

# file lists
LST_SRC =	client.c server.c sigaction_setters.c signal_handlers.c

# ╭━━━━━━━━━━━━══════════╕出 ❖ RULES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

all : $(NAME)

$(NAME) : makeprintf
	@$(MAKE) server
	@$(MAKE) client

makeprintf:
	@$(MAKE) -C $(LIB) all

server:
	$(CC) -I$(LIB)$(INC) -I$(INC) -L$(LIB) $(SRC)server.c $(SRC)sigaction_setters.c -o server -lftprintf
	@echo "\e[0;32mLe server à été créé avec succès ! 🧬\e[0m"


client:
	$(CC) -I$(LIB)$(INC) -I$(INC) -L$(LIB) $(SRC)client.c  $(SRC)sigaction_setters.c -o client -lftprintf
	@echo "\e[0;32mLe client à été créé avec succès ! 🧬\e[0m"

clean:
	@$(MAKE) -C $(LIB) clean

fclean:
	@$(RM) client server
	@$(MAKE) -C $(LIB) fclean
	@echo "\e[0;34mClient et server supprimés 🧽\e[0m"

re :
	@$(MAKE) fclean
	@$(MAKE) all
	@echo "\e[0;32mExecutables recréés avec succès ! 🫡\e[0m"