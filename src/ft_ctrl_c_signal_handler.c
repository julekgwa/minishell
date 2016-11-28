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

void	ft_print_error(char *erro)
{
	ft_putstr("minishell: ");
	ft_putstr(erro);
	ft_putstr(": command not found...\n");
}
