/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:28:04 by lewlee            #+#    #+#             */
/*   Updated: 2023/05/24 09:04:40 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_items, size_t size)
{
	size_t	i;
	char	*r_val;

	i = 0;
	if (num_items == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	r_val = malloc(num_items * size);
	if (!r_val)
		return (NULL);
	while (i < size * num_items)
		r_val[i++] = '\0';
	return ((void *)r_val);
}
