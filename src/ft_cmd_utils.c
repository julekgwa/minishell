/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goisetsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:39:49 by goisetsi          #+#    #+#             */
/*   Updated: 2016/12/13 18:39:55 by goisetsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char **cmd, char *get_line)
{
	freecopy(cmd);
	free(get_line);
	exit(0);
}

void	ft_builtins(char **user_comm, char *get_line, char **envp, char **sp)
{
	(void)sp;
	ft_execute_commands(user_comm, get_line, envp);
}

void	prompt(char **commands)
{
	ft_putstr(GRN);
	ft_putstr("$> ");
	ft_putstr(RESET);
	get_next_line(0, commands);
}

int		ft_spaces_tabs(char *s)
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
