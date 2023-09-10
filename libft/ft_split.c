/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:47:17 by lewlee            #+#    #+#             */
/*   Updated: 2023/05/17 16:41:38 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_finder(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_mstrdup(const char *str, int limit)
{
	char	*r_str;
	int		i;

	i = 0;
	r_str = malloc((limit + 1) * sizeof(char));
	if (!r_str)
		return (NULL);
	while (str[i] && i < limit)
	{
		r_str[i] = str[i];
		i++;
	}
	r_str[i] = '\0';
	return (r_str);
}

char	**ft_split(char const *s, char c)
{
	int		i[3];
	char	**r_str;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (!s)
		return (NULL);
	r_str = malloc((len_finder(s, c) + 1) * sizeof(char *));
	if (!r_str)
		return (NULL);
	while (i[0] < (int)ft_strlen(s) + 1)
	{
		if ((s[i[0]] == c || s[i[0]] == '\0') && i[2] != 0)
		{
			r_str[i[1]++] = ft_mstrdup(s + (i[0] - i[2]), i[2]);
			i[2] = 0;
		}
		else if (s[i[0]] != c)
			i[2]++;
		i[0]++;
	}
	r_str[i[1]] = 0;
	return (r_str);
}
