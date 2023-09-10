/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 08:02:05 by lewlee            #+#    #+#             */
/*   Updated: 2023/05/03 08:39:30 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*val;
	size_t			i;

	val = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (val[i] == (unsigned char)c)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
