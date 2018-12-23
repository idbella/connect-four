NAME=puissance4
all:
	make -C libft/
	gcc -o $(NAME) -Wall -Wextra -Wall *.c libft/libft.a
$(NAME): all
clean :
	make -C libft/ clean
fclean :
	make -C libft/ fclean
	rm -rf $(NAME)
re : fclean all