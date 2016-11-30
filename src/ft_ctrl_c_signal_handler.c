/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrl_c_signal_handler.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julekgwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 10:12:50 by julekgwa          #+#    #+#             */
/*   Updated: 2016/07/14 10:45:04 by julekgwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ctrl_c_signal_handler(int signum)
{
	ft_putstr("Control + c");
	(void)signum;
	// exit(signum);
}

void	ft_print_error(char *cmd, int errorno)
{
	ft_putstr("minishell: ");
	ft_putstr(cmd);
	if (errorno == 0)
	{
		ft_putstr(": command not found...\n");
	}
	else if (errorno == 1)
	{
		ft_putstr(": Permission denied\n");
	}
}

int		ft_contains(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_multi_com(char *get_line, char **envp)
{
	char	**tmp_com;
	char 	**split_com;
	int		i;

	split_com = ft_strsplit(get_line, ';');
	i = 0;
	while (split_com[i])
	{
		tmp_com = ft_strsplit(split_com[i], ' ');
		if (tmp_com)
			ft_run_commands(tmp_com, split_com[i], envp);
		i++;
		freesplit(tmp_com);
	}
	if (split_com)
		freecopy(split_com);
}