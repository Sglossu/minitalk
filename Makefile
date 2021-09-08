SERVER		= server
CLIENT		= client
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
RMF			= rm -f

SERVER_SRCS		= server.c add_functions.c
CLIENT_SRCS		= client.c add_functions.c

SERVER_OBJS	= $(patsubst %.c,%.o, $(SERVER_SRCS))
CLIENT_OBJS	= $(patsubst %.c,%.o, $(CLIENT_SRCS))

HEAD		= minitalk.h

all	:	$(SERVER) $(CLIENT)

$(SERVER)	:	$(SERVER_OBJS) $(HEAD)
	$(CC) $(FLAGS) $(SERVER_SRCS) -o $(SERVER) 

$(CLIENT)	:	$(CLIENT_OBJS) $(HEAD)
	$(CC) $(FLAGS) $(CLIENT_SRCS) -o $(CLIENT)

clean :
	$(RM) *.o

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY		:	all clean fclean re