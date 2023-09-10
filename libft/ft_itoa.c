/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:57:27 by lewlee            #+#    #+#             */
/*   Updated: 2023/05/03 08:39:28 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static int	checknum(int n, int type)
{
	int	sign;

	sign = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (-1);
		n *= -1;
		sign++;
	}
	if (n == 0)
		sign = 0;
	if (type == 0)
		return (n);
	else
		return (sign);
}

static char	*minval(void)
{
	char	*r_str;

	r_str = malloc(12 * sizeof (char));
	ft_strlcpy(r_str, "-2147483648", 12);
	return (r_str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*r_str;
	int		sign;

	i = 0;
	sign = checknum(n, 1);
	n = checknum(n, 0);
	if (n == -1)
		return (minval());
	len = digit_count(n);
	r_str = malloc((len + sign + 1) * sizeof(char));
	if (!r_str)
		return (NULL);
	while (i < len - 1 + sign)
		i++;
	while (n >= 0 && i >= (0 + sign))
	{
		r_str[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == 1)
		r_str[i] = '-';
	r_str[len + sign] = '\0';
	return (r_str);
}
