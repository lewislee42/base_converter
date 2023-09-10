/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:00:41 by lewlee            #+#    #+#             */
/*   Updated: 2023/05/23 10:54:50 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mstrlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_mstrlen(dest);
	if (size <= 0 || size < dstlen)
		return (srclen + size);
	while (src[i] != '\0' && i + dstlen < size - 1)
	{
		dest[dstlen + i] = src[i];
		i++;
	}
	if (size > ft_strlen(dest) - 1)
		dest[dstlen + i] = '\0';
	return (dstlen + srclen);
}
