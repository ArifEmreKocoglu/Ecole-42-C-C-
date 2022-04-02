/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:37:37 by akocoglu          #+#    #+#             */
/*   Updated: 2022/02/10 18:12:43 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *r)
{
	while (*str)
	{
		*r += write(1, str, 1);
		str++;
	}
}

void	charyaz(char result, int *r)
{
	*r += write(1, &result, 1);
}

void	decimalyaz(int result, int *r)
{
	char	*k;

	k = ft_itoa(result);
	ft_putstr(k, r);
	free(k);
}

void	stringyaz(char *result, int *r)
{
	if (!result)
	{
		stringyaz("(null)", r);
		return ;
	}
	ft_putstr(result, r);
}
