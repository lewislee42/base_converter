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
	char	from;
	char	to;
}	t_flags;

// error
int	error(int code)
{
	if (code == 1)
		printf("Error: invalid flags");
	return (1);
}



// flags initialising
void	init_flags(t_flags *flags)
{
	flags->from == 'c';
	flags->to = 'b';
}

// gets from and to flags
// DOES NOT SET IF NO FLAGS ARE FOUND
int	get_flags(t_flags *flags, char **av)
{
	int		i;
	int		j;
	int		flag_found;
	char	*temp;

	i = -1;
	flag_found = 0;
	init_flags(flags);
	while (av[++i])
	{
		if (av[i][0] == '-')
		{
			j = 0;
			while (av[i][++j])
			{
				temp = strchr("caobh", av[i][j]);
				if (!temp)
					return (0);
				if (flag_found == 0)
					flags->from = temp[0];
				else if (flag_found == 1)
					flags->to = temp[0];
				flag_found++;
			}
		}
	}
	if (flag_found > 2)
		return (0);
	return (1);
}

int	args_check(int ac, char **av)
{
	int	i;
	int	flag_found;

	i = 0;
	flag_found = 0;
	if (ac > 4)
		return (0);
	while (av[i])
	{
		if (av[i][0] == '-')
			flag_found++;
		i++;
	}
	if ((flag_found != 2 && i == 4) || (flag_found != 1 && i == 3))
		return (0);
	return (1);
}

// problem now is that im trying to figure out a way to check if the arguments are correct
int main(int ac, char **av)
{
	t_flags	flags;

    
	if (!args_check(ac, av) || !get_flags(&flags, av))
		return (error(1));
	
}