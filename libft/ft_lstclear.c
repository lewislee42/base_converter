/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:02:39 by lewlee            #+#    #+#             */
/*   Updated: 2023/05/08 09:19:09 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*i;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		i = *lst;
		*lst = (*lst)->next;
		del(i->content);
		free(i);
	}
	*lst = NULL;
}
