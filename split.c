

#include "libcrono.h"

int	count_split(const char *str, char to_find)
{
	int	count;
	int	yy;

	yy = 0;
	count = 1;
	if (str == NULL)
		return (0);
	while (str[yy])
	{
		if (str[yy] != to_find && (yy == 0 || str[yy - 1] == to_find))
			count++;
		yy++;
	}
	return (count);
}

void	free_split(char **ptr)
{
	int	ind;

	ind = 0;
	while (ptr[ind])
	{
		free(ptr[ind]);
		ind++;
	}
	free(ptr);
}

char	**split(const char *str, char c)
{
	char	**result;
	int		ptr;
	int		ind1;
	int		ind2;
	int		count;

	ind2 = 0;
	ptr = 0;
	count = count_split(str, c);
	result = (char **)malloc(count * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result[count - 1] = NULL;
	while (str[ind2++])
	{
		if (str[ind2 - 1] != c && (ind2 - 1 == 0 || str[ind2 - 2] == c))
			ind1 = ind2 - 1;
		if (str[ind2 - 1] == c && (ind2 - 1 != 0 && str[ind2 - 2] != c))
		{
			result[ptr] = substr(str, ind1, ind2 - 1 - ind1);
			if (!result[ptr++])
				return (free_split(result), NULL);
		}
	}
	if (ind2 - 1 != 0 && str[ind2 - 2] != c)
	{
		result[ptr] = substr(str, ind1, ind2 - 1 - ind1);
		if (!result[ptr++])
			return (free_split(result), NULL);
	}
	return (result);
}
