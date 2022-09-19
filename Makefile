SERVER = server
CLIENT = client

COMPILE = gcc -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

CLIENT_SRC = ./src/client.c
SERVER_SRC = ./src/server.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

REMOVE = rm -f

all:	$(CLIENT) $(SERVER)

.c.o:
	$(COMPILE) -c $< -o $@

$(CLIENT):	$(LIBFT) 
	$(COMPILE) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)

$(SERVER):	$(LIBFT) 
	$(COMPILE) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)

$(LIBFT):
	cd libft && make
	cd ..

clean:
	$(REMOVE) $(CLIENT_OBJ)
	$(REMOVE) $(SERVER_OBJ)

fclean: clean
	$(REMOVE) $(LIBFT)
	$(REMOVE) $(CLIENT)
	$(REMOVE) $(SERVER)


re: fclean all

.PHONY: all clean fclean re