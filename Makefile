NAME = minishell

FTC =	ft_main.c\
		ft_env.c\
		ft_cmd.c\

FTO = $(subst .c,.o,$(FTC))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@echo ""
	@make -C ./libft
	@gcc -o $(NAME) $(FTO) ./libft/libft.a
	@echo "\033[32m$(NAME) created!\033[0m"

%.o: %.c
	@gcc -Wall -Wextra -Werror -I./libft/includes -I./includes -c $<
	@echo "\033[33m.\033[0m\c"

clean:
	@make -C ./libft clean
	@rm -rf $(FTO)
	@echo "\033[33m$(NAME) object deleted!\033[0m"

fclean: clean
	@make -C ./libft fcleana
	@rm -rf $(NAME)
	@echo "\033[31m$(NAME) deleted!\033[0m"

re: fclean all
