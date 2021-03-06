/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julekgwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:04:21 by julekgwa          #+#    #+#             */
/*   Updated: 2016/06/05 17:04:25 by julekgwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strhex(char *str)
{
	int	i;

	i = 0;
	ft_putstr("0x");
	while (str[i])
		ft_putchar(ft_tolower(str[i++]));
}
