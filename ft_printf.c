/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:44:36 by zuonen            #+#    #+#             */
/*   Updated: 2024/11/20 12:06:44 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control2(char c, va_list arg)
{
	int		i;
	void	*ptr;

	i = 0;
	if (c == 'p')
	{
		ptr = va_arg(arg, void *);
		if (ptr == NULL)
		{
			write(1, "(nil)", 5);
			return (5);
		}
		else
		{
			i += ft_putstr("0x");
			i += ft_p((unsigned long)ptr);
		}
	}
	return (i);
}

int	ft_control(char c, va_list arg)
{
	int	r;

	r = 0;
	if (c == 'c')
		r += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		r += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		r += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		r += ft_u(va_arg(arg, unsigned int));
	else if (c == 'x')
		r += ft_x(va_arg(arg, unsigned int));
	else if (c == 'X')
		r += ft_xx(va_arg(arg, unsigned int));
	else if (c == 'p')
		r += ft_control2(c, arg);
	else if (c == '%')
		r += ft_putchar('%');
	else
	{
		r += ft_putchar('%');
		r += ft_putchar(c);
	}
	return (r);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar(s[i]);
			j++;
		}
		if (s[i] == '%')
		{
			i++;
			while (s[i] == ' ' && s[i])
				i++;
			j += ft_control(s[i], arg);
		}
		i++;
	}
	va_end(arg);
	return (j);
}
