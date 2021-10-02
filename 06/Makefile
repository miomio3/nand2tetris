NAME = a.out
CC = gcc 
SRC = main.c asm.c binary.c Cbinary.c Jbinary.c libft.c libft2.c file.c free.c symbol_table.c perser.c token.c tokenA.c tokenC.c tokenJ.c is.c

all		:$(NAME)
$(NAME)	:$(SRC)
	$(CC) $(SRC) -o $@
clean	:
	rm -f $(NAME)
fclean	:
	rm -f $(NAME)
re		:fclean clean all

.PHONY		:all clean fclean re