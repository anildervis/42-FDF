FLAGS=-Werror -Wextra -Wall

NAME=map_generator

SRC=*.c

INCLUDES=libft/libft.a get_git/get_next_line.a

all:
	@make -C libft/ all
	@make -C get_git/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES)

clean:
	@make -C libft/ clean
	@make -C get_git/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean
	@make -C get_git/ fclean

re: fclean all

.PHONY: all clean fclean re