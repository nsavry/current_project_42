#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int		main(int ac, char **av, char **env)
{
	pid_t		pid;
	struct stat *buf;
	int			i;
	char		**tab;
	char		**path;
	char		**cmd;
	char		*tmp;
	char		*line;
	char		*cmd_i;

	(void)ac;
	i = 0;
	if (*env == NULL)
	{
		path = malloc(sizeof(char *) * 3);
		path[0] = ft_strdup("/bin");
		path[1] = ft_strdup("/usr/bin");
		path[2] = NULL;
	}
	else
	{
		while (env[i] != NULL)
		{
			tab = ft_strsplit(env[i], '=');
			if (ft_strcmp(tab[0], "PATH") == 0)
				break ;
			i++;
			ft_free_tab(&tab);
		}
		path = ft_strsplit(tab[1], ':');
		ft_free_tab(&tab);
	}
	buf = malloc(sizeof(struct stat));
	while (1)
	{
		ft_printf("$> ");
		ft_get_next_line(0, &line);
		if (line[0] != 0)
		{
			cmd = ft_strsplit(line, ' ');
			if (ft_strcmp(cmd[0], "exit") == 0)
				break ;
			cmd_i = ft_strdup(cmd[0]);
			i = 0;
			if (stat(cmd[0], buf) != 0)
			{
				while (path[i])
				{
					tmp = cmd[0];
					cmd[0] = ft_strjoin("/", cmd_i);
					free(tmp);
					tmp = cmd[0];
					cmd[0] = ft_strjoin(path[i], tmp);
					free(tmp);
					if (stat(cmd[0], buf) == 0)
						break ;
					i++;
				}
			}
			if (path[i] == NULL)
				ft_printf("%s: command not found: %s\n", av[0], cmd_i);
			else
			{
				pid = fork();
				if (pid == 0)
				{
					execve(cmd[0], cmd, NULL);
					exit(0);
				}
				wait(NULL);

			}
			ft_free_tab(&cmd);
			free(cmd_i);
		}
		free(line);
	}
	if (line[0] != 0)
		ft_free_tab(&cmd);
	free(line);
	ft_free_tab(&path);
	free(buf);
	ft_printf("loooool");
	return (0);
}
