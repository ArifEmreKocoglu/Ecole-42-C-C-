/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:54:45 by akocoglu          #+#    #+#             */
/*   Updated: 2022/01/31 15:04:07 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int y)
{
	if (((y >= 'A' && y <= 'Z') || (y >= 'a' && y <= 'z')))
	{
		return (1);
	}
	else if (((y >= '0') && (y <= '9')))
	{
		return (1);
	}
	return (0);
}

//  int main(void)
//  {
//     int a = ft_isalnum('3');
//      printf("%d",a);
//      return (0);
//  }
