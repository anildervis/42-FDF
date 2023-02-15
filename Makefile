FRAEMWORKS=-framework OpenGL -framework AppKit

FLAGS=-Werror -Wextra -Wall

NAME=fdf

SRC=src/*.c

INCLUDES=libft/libft.a mlx/libmlx.a get_git/get_next_line.a

all:
	@make -C libft/ all
	@make -C mlx/ all
	@make -C get_git/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS) 

clean:
	@make -C libft/ clean
	@make -C mlx/ clean
	@make -C get_git/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean
	@make -C get_git/ fclean

re: fclean all

.PHONY: all clean fclean re