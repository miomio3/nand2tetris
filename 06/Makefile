NAME = a.out
CC = gcc 
SRC = asm.c libft.c libft2.c file.c symbol_table.c perser.c

all		:$(NAME)
$(NAME)	:$(SRC)
	$(CC) $(SRC) -o $@
clean	:
	rm -f $(NAME)
fclean	:
	rm -f $(NAME)
re		:fclean clean all

.PHONY		:all clean fclean re