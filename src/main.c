/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julekgwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 10:31:17 by julekgwa          #+#    #+#             */
/*   Updated: 2016/07/10 17:08:31 by julekgwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**envp_cpy(char **envp) {
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)malloc((ft_array_len(envp) + 1) * sizeof(char *));
	copy[ft_array_len(envp)] = NULL;
	if (copy) {
		while (envp[i]) {
			copy[i] = strdup(envp[i]);
			i++;
		}
	}
	return (copy);
}

void freecopy(char **copy) {
	int i = 0;
	while (copy[i]) {
		free(copy[i]);
		i++;
	}
	free(copy);
}

int		ft_search_command(char *command)
{
	static char	*comm_list = "echo pwd cd setenv unsetenv env exit clear";
	char		**comm_split;
	int			i;

	comm_split = ft_strsplit(comm_list, ' ');
	i = 0;
	while (comm_split[i])
	{
		if (ft_strcmp(comm_split[i], command) == 0)
		{
			freecopy(comm_split);
			return (1);
		}
		i++;
	}
	freecopy(comm_split);
	return (0);
}

void	ft_execute_commands(char **command, char *get_line, char **envp)
{
	char *dir;

	if (ft_strequ(command[0], "cd"))
		ft_cd(command, envp);
	else if (ft_strequ(command[0], "pwd"))
	{
		dir = ft_pwd();
		ft_putendl(dir);
		free(dir);
	}
	else if (ft_strequ(command[0], "echo"))
		ft_echo(get_line, envp);
	else if (ft_strequ(command[0], "env"))
		ft_print_env(envp);
	else if (ft_strequ(command[0], "setenv"))
		ft_set_envir(envp, get_line);
	else if (ft_strequ(command[0], "unsetenv"))
		ft_unsetting_env(get_line, envp);
	else if (ft_strequ(command[0], "clear"))
		write(1, "\033c", 3);
}

void	ft_run_commands(char **user_comm, char *get_line, char **envp)
{
	pid_t	pid;
	char	**sp;
	char 	*more;

	sp = ft_strsplit(get_line, ' ');
	more = NULL;
	if (ft_search_command(user_comm[0]))
	{
		if ((pid = fork()) < 0)
			ft_putendl("error while forking");
		else if (pid == 0)
			ft_execute_commands(user_comm, get_line, envp);
		if (pid > 0)
		{
			wait(NULL);
			freecopy(sp);
			exit(0);
		}
	}
	else if ((more = ft_more(envp, sp)))
		ft_execute(envp, sp);
	else if (ft_is_execute(sp[0]))
		ft_execute_bin(sp, envp);
	else
		ft_print_error(sp[0], 0);
	freecopy(sp);
	// freesplit(user_comm);
	if (more)
		free(more);
	// free(get_line);
}

void	prompt(char **commands)
{
	ft_putstr(GRN);
	ft_putstr("$> ");
	ft_putstr(RESET);
	get_next_line(0, commands);
}

int	ft_spaces_tabs(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != 32 && s[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av, char **envp)
{
	char	*get_line;
	char	**user_comm;
	char    **envp_copy;

	get_line = NULL;
	envp_copy = envp_cpy(envp);
	get_line = getcwd(get_line, 1024);
	get_line = ft_strcat(get_line, "/");
	get_line = ft_strcat(get_line, av[0]);
	// ft_setenv("SHELL", get_line, 1, envp);
	free(get_line);
	signal(SIGINT, ft_ctrl_c_signal_handler);
	(void)ac;
	(void)av;
	while (1)
	{
		prompt(&get_line);
		if (!ft_strequ(get_line, "") && ft_spaces_tabs(get_line))
		{
			user_comm = ft_strsplit(get_line, ' ');
			if (ft_strequ(user_comm[0], "exit")){
				freecopy(user_comm);
				freecopy(envp_copy);
			free(get_line);
				exit(0);
			}
			ft_run_commands(user_comm, get_line, envp);
			freecopy(user_comm);
			free(get_line);
		}
	}
	return (0);
}
