NAME = a.out
CC = gcc 
SRC = main.c flow_command.c func_command1.c func_command2.c func_command3.c libft.c libft2.c libft3.c file.c free.c vm.c neg_not.c other_inst.c pick.c push.c pop.c write_asm.c write_asm2.c

all		:$(NAME)
$(NAME)	:$(SRC)
	$(CC) -g $(SRC) -o $@
clean	:
	rm -f $(NAME)
fclean	:
	rm -f $(NAME)
re		:fclean clean all

.PHONY		:all clean fclean re