/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuonen <zuonen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:45:02 by zuonen            #+#    #+#             */
/*   Updated: 2024/11/20 12:02:31 by zuonen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xx(unsigned int a)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789ABCDEF";
	if (a >= 16)
	{
		i += ft_xx(a / 16);
		i += ft_xx(a % 16);
	}
	else
	{
		i += ft_putchar(hex[a % 16]);
	}
	return (i);
}
