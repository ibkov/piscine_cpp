NAME = Fixed
CC = clang++
FLAGS = -Wall -Wextra -Werror -MMD -std=c++98

SRC =	main.cpp \
		Fixed.cpp

SRCS = $(SRC)

OBJ = $(SRCS:.cpp=.o)
D_FILES = $(SRCS:.cpp=.d)

all: $(NAME)


$(NAME): $(OBJ)
	@echo "\n"
	@echo "\033[0;32mCompiling $(NAME)..."
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)
	@echo "\n\033[0mDone !"

%.o: %.cpp
	@printf "\033[0;33mGenerating $(NAME) objects... %-33.33s\r" $@
	@${CC} -g ${FLAGS} -c $< -o $@

-include $(D_FILES)

clean:
	@echo "\nRemoving dependency..."
	@rm -f$(D_FILES)
	@echo "\033[0m"
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31m\nDeleting dependency..."
	@rm -f $(D_FILES)
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\nDeleting trash..."
	@echo "\033[0m"

re: fclean all

run: $(NAME)
	@./$(NAME)

.PHONY: clean fclean re run
