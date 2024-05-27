CC = cc

FLAGS = -Wall -Wextra -Werror

all: libft client server

bonus: libft client_bonus server_bonus

libft/libft.a:
	make -C libft all

client: client.o libft/libft.a
	$(CC) -o client client.o libft/libft.a

server: server.o libft/libft.a
	$(CC) -o server server.o libft/libft.a

client_bonus.o: client_bonus.c
	$(CC) $(FLAGS) -I./libft -c client_bonus.c

server_bonus.o: server_bonus.c
	$(CC) $(FLAGS) -I./libft -c server_bonus.c

client_bonus: client_bonus.o libft/libft.a
	$(CC) -o client_bonus client_bonus.o libft/libft.a

server_bonus: server_bonus.o libft/libft.a
	$(CC) -o server_bonus server_bonus.o libft/libft.a

clean:
	rm -f client.o server.o client_bonus.o server_bonus.o

fclean: clean
	rm -f client server client_bonus server_bonus

re: fclean all

.PHONY: all clean fclean re bonus
