/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:07:03 by akocoglu          #+#    #+#             */
/*   Updated: 2022/02/10 18:05:18 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexayaz(size_t result, int *r)
{
	char	s[16];
	int		i;

	i = 0;
	if (result == 0)
	{
		*r += write(1, "0x0", 3);
		return ;
	}
	ft_memset(s, '\0', 16);
	while (result)
	{
		s[i++] = "0123456789abcdef"[result % 16];
		result = result / 16;
	}
	*r += write(1, "0x", 2);
	while (i--)
		*r += write(1, s + i, 1);
}

void	intisaretsizyaz(unsigned int result, int *r)
{
	char	s[10];
	int		i;

	i = 0;
	if (result == 0)
	{
		*r += write(1, "0", 1);
	}
	while (result)
	{
		s[i++] = result % 10 + '0';
		result = result / 10;
	}
	while (i--)
		*r += write(1, s + i, 1);
}

void	hexadecyaz(unsigned int result, char *k, int *r)
{
	char	s[16];
	int		i;

	i = 0;
	if (result == 0)
	{
		stringyaz("0", r);
		return ;
	}
	while (result)
	{
		s[i++] = k[result % 16];
		result = result / 16;
	}
	while (i--)
		*r += write(1, s + i, 1);
}

int	test(char k, va_list result, int *r)
{
	if (k == 'c')
		charyaz(va_arg(result, int), r);
	else if (k == 'd')
		decimalyaz(va_arg(result, int), r);
	else if (k == 's')
		stringyaz(va_arg(result, char *), r);
	else if (k == 'p')
		hexayaz(va_arg(result, size_t), r);
	else if (k == 'i')
		decimalyaz(va_arg(result, int), r);
	else if (k == 'u')
		intisaretsizyaz(va_arg(result, unsigned int), r);
	else if (k == 'x')
		hexadecyaz(va_arg(result, size_t), "0123456789abcdef", r);
	else if (k == 'X')
		hexadecyaz(va_arg(result, size_t), "0123456789ABCDEF", r);
	else if (k == '%')
		*r += write(1, "%", 1);
	else
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		r;
	int		flag;
	va_list	result;

	va_start(result, str);
	r = 0;
	flag = 0;
	while (*str)
	{
		if (*str == '%')
		{
			flag = 0;
			while (*(++str) == ' ')
				flag = 1;
			if (flag)
				r += write(1, " ", 1);
			if (test(*str, result, &r) == 1)
					r += write(1, "%", 1);
		}
		else
			r += write(1, str, 1);
			str++;
	}
	va_end(result);
	return (r);
}

// int	main(void)
// {
// 	ft_printf("%c", '0');
// 	return (0);
// }
