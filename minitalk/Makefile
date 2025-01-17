CFLAGS = -Wall -Werror -Wextra
CC = cc 
CLIENT = client
SERVER = server
# CLIENT_BONUS = client_bonus
# SERVER_BONUS = server_bonus

all : $(CLIENT) $(SERVER)

$(CLIENT) : client.c
	$(CC) $(CFLAGS) client.c utils.c -o client
$(SERVER) : server.c
	$(CC) $(CFLAGS) server.c utils.c -o server

clean : fclean

fclean :
	rm -rf $(CLIENT) $(SERVER) 

re : fclean all 
