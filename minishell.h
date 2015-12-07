#ifndef MINISHELL_H
# define MINISHELL_H

char  **ft_build_env(void);
char  **ft_build_path(char **env);

int   ft_check_cmd(char **path, char **cmd, char *cmd_i);
void  ft_fork_cmd(char **cmd);
int   ft_exec(char **env, char *line, char **av);
int   ft_read_cmd(char **env, char **av);

#endif
