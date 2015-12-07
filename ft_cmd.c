#include "minishell.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int   ft_check_cmd(char **path, char **cmd, char *cmd_i)
{
  char  *tmp;
  struct stat *buf;
  int   i;

  i = 0;
  buf = malloc(sizeof(struct stat));
  if (stat(*cmd, buf) != 0)
  {
    while (path[i])
    {
      tmp = *cmd;
      *cmd = ft_strjoin("/", cmd_i);
      ft_free(&tmp);
      tmp = *cmd;
      *cmd = ft_strjoin(path[i], tmp);
      ft_free(&tmp);
      if (stat(*cmd, buf) == 0)
        break ;
      i++;
    }
  }
  free(buf);
  return (i);
}

void  ft_fork_cmd(char **cmd)
{
  pid_t pid;

  pid = fork();
  if (pid == 0)
  {
    execve(cmd[0], cmd, NULL);
    exit(0);
  }
  wait(NULL);
}

int   ft_exec(char **env, char *line, char **av)
{
  char  **cmd;
  char  **path;
  char  *cmd_i;

  cmd = ft_strsplit(line, ' ');
  if (ft_strcmp(cmd[0], "exit") == 0)
  {
    ft_free_tab(&cmd);
    return (1);
  }
  cmd_i = ft_strdup(cmd[0]);
  path = ft_build_path(env);
  if (path[ft_check_cmd(path, &cmd[0], cmd_i)] == NULL)
    ft_printf("%s: command not found: %s\n", av[0], cmd_i);
  else
    ft_fork_cmd(cmd);
  ft_free(&cmd_i);
  ft_free_tab(&path);
  ft_free_tab(&cmd);
  return (0);
}
