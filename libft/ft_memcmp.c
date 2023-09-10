/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:44:31 by lewlee            #+#    #+#             */
/*   Updated: 2023/05/22 09:10:40 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *val1, const void *val2, size_t n)
{
	size_t			i;
	unsigned char	*val1_c;
	unsigned char	*val2_c;

	i = 0;
	if (n == 0)
		return (0);
	val1_c = (unsigned char *)val1;
	val2_c = (unsigned char *)val2;
	while (val1_c[i] == val2_c[i] && i < n - 1)
	{
		i++;
	}
	return (val1_c[i] - val2_c[i]);
}
