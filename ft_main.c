#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

int		main(int ac, char **av, char **env_o)
{
	char	**env;
	char	*line;
	int		ret;

	(void)ac;
	if (*env_o == NULL)
		env = ft_build_env();
	else
		env = env_o;
	while (1)
	{
		ft_printf("$> ");
		ret = ft_get_next_line(0, &line);
		if (!line || ret == -1 || ret == 0)
			break ;
		if (line[0] != 0)
		{
			if (ft_exec(env, line, av))
				break ;
		}
		ft_free(&line);
	}
	ft_free(&line);
	return (0);
}
