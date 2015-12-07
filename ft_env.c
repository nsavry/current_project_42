#include <stdlib.h>
#include "minishell.h"
#include "libft.h"

char  **ft_build_env(void)
{
  char  **env;

  env = malloc(sizeof(char *) * 2);
  env[0] = ft_strdup("/bin:/usr/bin");
  env[1] = NULL;
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
