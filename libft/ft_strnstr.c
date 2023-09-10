/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:34:52 by lewlee            #+#    #+#             */
/*   Updated: 2023/05/03 08:38:29 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	if (!str && n <= 0)
		return (NULL);
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i] == to_find[j] && str[i] && i < n)
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0')
			return ((char *)str + (i - j));
		i -= j;
		i++;
	}
	return (0);
}
