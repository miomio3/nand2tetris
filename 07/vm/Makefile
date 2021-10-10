NAME = a.out
CC = gcc 
SRC = main.c libft.c libft2.c libft3.c neg_not.c file.c free.c vm.c pick.c push.c pop.c write_asm.c write_asm2.c

all		:$(NAME)
$(NAME)	:$(SRC)
	$(CC) -g $(SRC) -o $@
clean	:
	rm -f $(NAME)
fclean	:
	rm -f $(NAME)
re		:fclean clean all

.PHONY		:all clean fclean re