SRCS			= 	main.cpp \
					Contact.class.cpp \
					Phonebook.class.cpp

OBJS			= $(SRCS:.cpp=.o)

CC				= clang++
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= phonebook

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