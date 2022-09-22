NAME_SERVER = server
NAME_CLIENT = client

COMPILE = gcc -Wall -Wextra -Werror

LIBFT_SRC = $(wildcard ./libft/*.c)

CLIENT_SRC = ./src/client.c
CLIENT_SRC += $(LIBFT_SRC)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_SRC = ./src/server.c
SERVER_SRC += $(LIBFT_SRC)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

REMOVE = rm -f

all:	$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(SERVER_OBJ)
	$(COMPILE) $(SERVER_OBJ) -o $(NAME_SERVER)

$(NAME_CLIENT): $(CLIENT_OBJ)
	$(COMPILE)  $(CLIENT_OBJ) -o $(NAME_CLIENT)

.c.o:
	$(COMPILE) -c $< -o $@

clean:
	$(REMOVE) $(CLIENT_OBJ)
	$(REMOVE) $(SERVER_OBJ)

fclean: clean
	$(REMOVE) $(LIBFT)
	$(REMOVE) $(NAME_CLIENT)
	$(REMOVE) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re