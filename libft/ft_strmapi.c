/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:45:52 by lewlee            #+#    #+#             */
/*   Updated: 2023/05/03 11:55:55 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*r_str;

	i = 0;
	if (!s)
		return (NULL);
	r_str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!r_str)
		return (NULL);
	while (s[i])
	{
		r_str[i] = (*f)(i, s[i]);
		i++;
	}
	r_str[i] = '\0';
	return (r_str);
}
