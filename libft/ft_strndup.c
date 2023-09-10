/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:05:35 by lewlee            #+#    #+#             */
/*   Updated: 2023/06/06 13:28:01 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s, int len)
{
	char	*r_str;
	int		i;

	i = 0;
	if (len > (int)ft_strlen(s))
		len = ft_strlen(s);
	r_str = (char *)malloc((len + 1) * sizeof(char));
	if (!r_str)
		return (NULL);
	while (s[i] && i < len)
	{
		r_str[i] = s[i];
		i++;
	}
	r_str[i] = '\0';
	return (r_str);
}
