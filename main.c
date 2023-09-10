/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lewlee <lewlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:11:35 by codespace         #+#    #+#             */
/*   Updated: 2023/09/10 17:32:45 by lewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "libft.h"

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

// error will print out error messages base of the code given
int	error(int code)
{
	if (code == 1)
		printf("Error: invalid flags");
	return (1);
}

int	count_rows(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

// flags init
// since default will be from character to binary so we set it to from = c and to = b
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

int	*convert_to_ascii(char *str)
{
	int i = -1;
	int	*r_arr = malloc((ft_strlen(str) + 1) * sizeof(int));
	if (!r_arr)
		return (0);
	while (str[++i])
		r_arr[i] = (int)str[i];
	r_arr[i] = NULL;
	return (r_arr);
}

int	ft_power(int nb, int power)
{
	int	i;
	int	num;

	i = 0;
	num = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (++i < power)
		nb = nb * num;
	return (nb);
}

int	convert_to_decimal(char *nbr, char *base)
{
	int	i = ft_strlen(nbr) - 1;
	int j;
	int k = 0;
	int	num = 0;
	int	baselen = ft_strlen(base);

	while (nbr[i])
	{
		j = nbr[k++];
		if (j >= 97 && j <= 122)
			j -= 87;
		else if (j >= 65 && j <= 90)
			j -= 55;
		else
			j -= 48;
		num = num + (j * ft_power(baselen, i--));
	}
	return (num);
}

void	free2dchar(char **arr)
{
	int i = 0;
	while (arr[i])
		free(arr[i]);
	free(arr);
}

int	*convert_to_int_arr(t_flags *flags, char *str)
{
	int	*temp_arr;

	if (flags->from == 'c')
		temp_arr = convert_to_ascii(str);
	else
	{
		temp_arr = ft_split(str, ' ');
		
		if (!temp_arr)
			return (NULL);
	}
	
}

// problem now is that im trying to figure out a way to check if the arguments are correct
// int main(int ac, char **av)
// {
// 	t_flags	flags;

// 	if (!args_check(ac, av) || !get_flags(&flags, av))
// 		return (error(1));
	
// 	// trying figure out how to convert it smoothly
// }



int main(void)
{
	// char **data = malloc(6 * sizeof(char *));
	// data[0] = strdup("0001");
	// data[1] = strdup("0011");
	// data[2] = strdup("0010");
	// data[3] = strdup("0100");
	// data[4] = strdup("1000");
	// data[5] = NULL;
	// int *i = convert_from_binary(data);
	// int j = 0;
	// while (i[j])
	// 	printf("i[%d] = %d\n", j, i[j++]);

	int i = ft_int("0110", "01");
	printf("%d\n", i);
}