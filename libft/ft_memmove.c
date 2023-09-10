/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:10:18 by lewlee            #+#    #+#             */
/*   Updated: 2023/05/03 08:39:35 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*val_dest;
	const char	*val_src;

	val_dest = dest;
	val_src = src;
	if (!dest && !src)
		return (dest);
	if (val_dest < val_src)
		while (n--)
			*val_dest++ = *val_src++;
	else
	{
		val_dest = val_dest + (n - 1);
		val_src = val_src + (n - 1);
		while (n--)
			*val_dest-- = *val_src--;
	}
	return (dest);
}
