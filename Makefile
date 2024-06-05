CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SERVER_SRCS = server.c utils.c ft_atoi.c
CLIENT_SRCS = client.c utils.c ft_atoi.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_SRCS_BONUS = server_bonus.c utils_bonus.c ft_atoi_bonus.c
CLIENT_SRCS_BONUS = client_bonus.c utils_bonus.c ft_atoi_bonus.c
SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(SERVER): $(SERVER_OBJS) minitalk.h
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJS) minitalk.h
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT)

$(SERVER_BONUS): $(SERVER_OBJS_BONUS) minitalk_bonus.h
	$(CC) $(CFLAGS) $(SERVER_OBJS_BONUS) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_OBJS_BONUS) minitalk_bonus.h
	$(CC) $(CFLAGS) $(CLIENT_OBJS_BONUS) -o $(CLIENT_BONUS)

clean:
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)

fclean: clean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all
