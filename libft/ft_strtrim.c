/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:03:52 by lewlee            #+#    #+#             */
/*   Updated: 2023/05/05 10:04:07 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	int		start;
	int		end;
	char	*r_str;

	if (!str || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(str) - 1;
	while (ft_strchr(set, str[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup((char *)str + (end + 1)));
	while (ft_strrchr(set, str[end]) && end >= 0)
		end--;
	r_str = malloc(((end - start) + 2) * sizeof(char));
	if (!r_str)
		return (NULL);
	ft_strlcpy(r_str, &str[start], ((end - start) + 2));
	return (r_str);
}
