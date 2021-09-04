SRCS			= 	main.cpp \
					Zombie.cpp \
					randomChump.cpp \
					newZombie.cpp

OBJS			= $(SRCS:.cpp=.o)

CC				= clang++
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I. -std=c++98

NAME			= Zombie

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

test:			$(NAME)

.PHONY:			all clean fclean re test