#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "libft.h"

char  **ft_build_env(void)
{
  char  **env;
  char  *str;

  env = malloc(sizeof(char *) * 5);
  str = getcwd(NULL, 1);
  env[0] = ft_strdup("PATH=/bin:/usr/bin");
  env[1] = ft_strjoin("HOME=", str);
  env[2] = ft_strjoin("PWD=", str);
  env[3] = ft_strjoin("OLDPWD=", str);
  env[4] = NULL;
  ft_free(&str);
  return (env);
}

char  **ft_build_path(char **env)
{
  char   **tab;
  char   **path;
  int   i;

  i = 0;
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
  return (path);
}
