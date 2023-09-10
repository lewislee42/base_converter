/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:52:13 by lewlee            #+#    #+#             */
/*   Updated: 2023/05/03 08:39:33 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_val;
	char	*src_val;
	size_t	i;

	dest_val = (char *)dest;
	src_val = (char *)src;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		dest_val[i] = src_val[i];
		i++;
	}
	return (dest_val);
}
