/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:42:54 by akocoglu          #+#    #+#             */
/*   Updated: 2022/02/10 18:02:24 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		test(char k, va_list result, int *r);

void	hexayaz(size_t result, int *r);
void	intisaretsizyaz(unsigned int result, int *r);
void	hexadecyaz(unsigned int result, char *k, int *r);
void	ft_putstr(char *str, int *r);
void	charyaz(char result, int *r);
void	decimalyaz(int result, int *r);
void	stringyaz(char *result, int *r);
#endif