NAME = a.out
CC = gcc 
SRC = main.c compiler.c class_compiler.c class_VerDec_compiler.c expression.c subroutine.c statement.c check_fprintf.c fprintf.c file.c file2.c dir.c is.c libft.c libft2.c  pick.c skip.c skip2.c

all		:$(NAME)
$(NAME)	:$(SRC)
	$(CC) -g $(SRC) -o $@
clean	:
	rm -f $(NAME)
fclean	:
	rm -f $(NAME)
re		:fclean clean all

.PHONY		:all clean fclean re