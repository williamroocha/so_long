/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:23:45 by wiferrei          #+#    #+#             */
/*   Updated: 2023/09/20 19:39:12 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_types(char *str, va_list args, int i, long int *chr_total)
{
	if (str[i] == 'c')
		ft_putchar(va_arg(args, int), chr_total);
	else if (str[i] == 's')
		ft_putstr(va_arg(args, char *), chr_total);
	else if (str[i] == 'p')
		ft_putadd(va_arg(args, unsigned long int), chr_total, 0);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr(va_arg(args, int), chr_total);
	else if (str[i] == 'u')
		ft_unsgint(va_arg(args, unsigned int), chr_total);
	else if (str[i] == 'x')
		ft_puthexa(va_arg(args, unsigned int), chr_total, 0);
	else if (str[i] == 'X')
		ft_puthexa(va_arg(args, unsigned int), chr_total, 1);
	else if (str[i] == '%')
		ft_putchar('%', chr_total);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	long int	i;
	long int	chr_total;

	i = 0;
	chr_total = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ft_types((char *)str, args, ++i, &chr_total);
		else
			ft_putchar(str[i], &chr_total);
		i++;
	}
	va_end(args);
	return (chr_total);
}
