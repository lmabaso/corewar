NAME1	=	asm
NAME2	=	corewar

SRC1	= 	asm_src/main.c \
			asm_src/ft_init.c \
			asm_src/ft_free_stuff.c \
			asm_src/ft_error_check.c \
			asm_src/ft_lst_funt.c \
			asm_src/ft_read_proc.c \
			asm_src/ft_make_encode.c \
			asm_src/ft_alloc_size.c \
			asm_src/ft_write_op.c \
			asm_src/ft_make_header.c \

SRC2	=	src/main.c \

OJB		= 	*.o

FLAGS	=	gcc -Wall -Wextra -Werror -o

all: $(NAME1) $(NAME2)

$(NAME1):
	@make -C libft/ fclean && make -C libft/
	@$(FLAGS) $(NAME1) $(SRC1) -L libft/ -lft -I libft/includes -I includes

$(NAME2):
	@make -C libft/ fclean && make -C libft/
	@$(FLAGS) $(NAME2) $(SRC2) -L libft/ -lft -I libft/includes -I includes

clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME1)
	@rm -f $(NAME2)

re:	fclean all
