NAME = a.out
CC = gcc 
SRC = main.c compiler.c libft.c libft2.c libft3.c file.c file2.c dir.c pick.c

all		:$(NAME)
$(NAME)	:$(SRC)
	$(CC) -g $(SRC) -o $@
clean	:
	rm -f $(NAME)
fclean	:
	rm -f $(NAME)
re		:fclean clean all

.PHONY		:all clean fclean re