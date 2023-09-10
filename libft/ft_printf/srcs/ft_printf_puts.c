/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:15:01 by lewlee            #+#    #+#             */
/*   Updated: 2023/06/23 09:38:30 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_mputchar(char c)
{
	write (1, &c, 1);
	return (1);
}

void	ft_mputstr(char *str, t_vals *j)
{
	int	i;

	i = 0;
	if (!str)
		ft_mputstr("(null)", j);
	else
		while (str[i])
			i += ft_mputchar(str[i]);
	j->temp += i;
}

void	ft_putnbaseptr(uintptr_t nbr, const char *base, t_vals *i)
{
	uintptr_t	j;

	j = ft_strlen(base);
	if (nbr >= j)
	{
		ft_putnbaseptr(nbr / j, base, i);
		i->temp += ft_mputchar(base[nbr % j]);
	}
	else if (nbr < j)
		i->temp += ft_mputchar(base[nbr]);
}

void	ft_putnbase(long int nbr, const char *base, t_vals *i)
{
	long int	j;

	j = ft_strlen(base);
	if (nbr < 0)
	{
		i->temp += ft_mputchar('-');
		ft_putnbase(nbr * -1, base, i);
	}
	else if (nbr >= j)
	{
		ft_putnbase(nbr / j, base, i);
		i->temp += ft_mputchar(base[nbr % j]);
	}
	else if (nbr < j && nbr >= 0)
		i->temp += ft_mputchar(base[nbr]);
}

void	ft_putpoint(uintptr_t nbr, t_vals *i)
{
	ft_mputstr("0x", i);
	ft_putnbaseptr(nbr, "0123456789abcdef", i);
}
