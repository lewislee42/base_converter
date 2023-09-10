/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:22:38 by lewlee            #+#    #+#             */
/*   Updated: 2023/05/08 16:43:04 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
//#include <stdio.h>

int	ft_mstrstr(const char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		if (str[i] == '+' || str[i] == '-')
			return (1);
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	incheck(char *str, t_vals *i, va_list a)
{
	char	*b;

	b = "0123456789";
	if (str[1] == '\0' || !ft_strchr("cspdiuxX%", str[1]))
		return ;
	if (str[1] == 'd' || str[1] == 'i')
		ft_putnbase(va_arg(a, int), b, i);
	else if (str[1] == 'c')
		i->temp += ft_mputchar(va_arg(a, int));
	else if (str[1] == 'p')
		ft_putpoint(va_arg(a, uintptr_t), i);
	else if (str[1] == 's')
		ft_mputstr(va_arg(a, char *), i);
	else if (str[1] == 'u')
		ft_putnbase((unsigned int)va_arg(a, unsigned int), b, i);
	else if (str[1] == 'x')
		ft_putnbase(va_arg(a, unsigned int), "0123456789abcdef", i);
	else if (str[1] == 'X')
		ft_putnbase(va_arg(a, unsigned int), "0123456789ABCDEF", i);
	else if (str[1] == '%')
		i->temp += ft_mputchar('%');
}

static int	incheckmain(const char *str, t_vals *vals, va_list args)
{
	int		i;

	i = 0;
	while (str[i])
	{
		vals->temp = 0;
		if (str[i] == '%')
		{
			incheck((char *)str + i, vals, args);
			i++;
		}
		else
			vals->temp += ft_mputchar(str[i]);
		vals->totallen += vals->temp;
		i++;
	}
	return (vals->totallen);
}

int	ft_printf(const char *s, ...)
{
	t_vals	*vals;
	va_list	args;
	int		r_val;

	r_val = 0;
	if (*s == '\0')
		return (0);
	vals = (t_vals *)malloc(sizeof(t_vals));
	if (!vals)
		return (0);
	vals->totallen = 0;
	vals->temp = 0;
	va_start(args, s);
	r_val = incheckmain(s, vals, args);
	va_end(args);
	free(vals);
	return (r_val);
}
