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
	exit(signum);
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
