/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:20:33 by lewlee            #+#    #+#             */
/*   Updated: 2023/06/23 09:42:41 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "../../libft.h"

typedef struct s_vals
{
	int	totallen;
	int	temp;
}	t_vals;

// main file
int		ft_printf(const char *s, ...);
// int		ft_mstrstr(const char *str);

void	ft_mputstr(char *str, t_vals *j);
void	ft_putnbaseptr(uintptr_t nbr, const char *base, t_vals *i);
void	ft_putnbase(long int nbr, const char *base, t_vals *i);
void	ft_putpoint(uintptr_t nbr, t_vals *i);
int		ft_mputchar(char c);

#endif