
#include "libft.h"
#include "minishell.h"

int		main(int ac, char **av, char **env_o)
{
	char	**env;

	(void)ac;
	if (*env_o == NULL)
		env = ft_build_env();
	else
		env = ft_tabdup(env_o);
	while (1)
	{
		if (ft_read_cmd(env, av) == 1)
			break ;
	}
	ft_free_tab(&env);
	return (0);
}
