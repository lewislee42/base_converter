/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:11:35 by codespace         #+#    #+#             */
/*   Updated: 2023/09/05 13:16:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// -a for ascii
// -o for octal
// -b for binary
// -h for hexa
// -c for character

// can only combine up to 2 flags

// usage ./base_converter "*string to convert" -ca

// default is convert to binary
// max 2 flags
// one flags mean to
// 2 flags: first one means from, second one means to

typedef struct	s_flags
{
	bool	c;
	bool	a;
	bool	o;
	bool	b;
	bool	h;
}	t_flags;

// error
int	error(int code)
{
	if (code == 1)
		printf("Error: invalid flags");
	return (1);
}



// flags getting and initialising
void	init_flags(t_flags *flags)
{
	flags->c = false;
	flags->a = false;
	flags->o = false;
	flags->b = false;
	flags->h = false;
}

int	setting_flag(t_flags *flags, char c)
{
	if (c == 'c' && flags->c == false)
		flags->c = true;
	else if (c == 'a' && flags->a == false)
		flags->a = true;
	else if (c == 'o' && flags->o == false)
		flags->o = true;
	else if (c == 'b' && flags->b == false)
		flags->b = true;
	else if (c == 'h' && flags->h == false)
		flags->h = true;
	else
		return (0);
	return (1);
}

int	get_flags(t_flags *flags, char **av)
{
	int	i;
	int	j;
	int	flag_found;

	i = -1;
	flag_found = 0;
	init_flags(flags);
	while (av[++i])
	{
		if (av[i][0] == '-')
		{
			j = 1;
			while (av[i][j])
			{
				if (!setting_flag(flags, av[i][j++]))
					return (1);
				else
					flag_found++;
			}
		}
	}
	if (flag_found > 2)
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	t_flags	flags;

    
	if (ac > 3 && !get_flags(&flags, av))
		return (error(1));
	
}