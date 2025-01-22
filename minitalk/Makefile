CFLAGS = -Wall -Werror -Wextra -g
CC = cc 
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus 
SERVER_BONUS = server_bonus


all : $(CLIENT) $(SERVER)

$(CLIENT) : client.c
	$(CC) $(CFLAGS) client.c utils.c -o client
$(SERVER) : server.c
	$(CC) $(CFLAGS) server.c utils.c -o server

$(CLIENT_BONUS) : client_bonus.c
	$(CC) $(CFLAGS) client_bonus.c utils.c -o client_bonus
$(SERVER_BONUS) : server_bonus.c
	$(CC) $(CFLAGS) server_bonus.c utils.c -o server_bonus


bonus : $(CLIENT_BONUS) $(SERVER_BONUS)

clean : fclean

fclean :
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re : fclean all 
