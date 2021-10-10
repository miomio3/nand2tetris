NAME = a.out
CC = gcc 
SRC = main.c libft.c libft2.c libft3.c file.c free.c vm.c pick.c push.c write_asm.c

all		:$(NAME)
$(NAME)	:$(SRC)
	$(CC) -g $(SRC) -o $@
clean	:
	rm -f $(NAME)
fclean	:
	rm -f $(NAME)
re		:fclean clean all

.PHONY		:all clean fclean re