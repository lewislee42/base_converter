
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



int	count_rows(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}



int	*convert_from_binary(char **arr)
{
	int	*r_arr = malloc((count_rows(arr) + 1) * sizeof(int));
	int	temp_int = 0;
	int	i = 0;
	int j;
	int	bit_shift;

	if (!r_arr)
		return (NULL);
	while (arr[i])
	{
		j = 0;
		bit_shift = 0;
		while (arr[i][j])
		{
			temp_int |= (arr[i][j] - 48 & 1) << bit_shift++;
			printf("temp = %d\n", temp_int);
			j++;
		}
		r_arr[i++] = temp_int;
	}
	r_arr[i] = NULL;
	return (r_arr);
}

int main(void)
{
	char **data = malloc(3 * sizeof(char *));
	data[0] = strdup("0001");
	data[1] = strdup("0010");
	data[2] = NULL;
	int *i = convert_from_binary(data);
	printf("i[0] = %d\n", i[0]);
}