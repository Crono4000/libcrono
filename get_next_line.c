
#include "libcrono.h"

void	trimbuffer(char *buffer, char *pattern)
{
	char	*newline;
	int		plen;

	plen = strlen(pattern);
	newline = strstr(buffer, pattern);
	if (newline)
		memmove(buffer, newline + plen, strlen(newline + plen) + 1);
	else
		strcpy(buffer, "");
}

size_t	special_strlen(const char *str, char *pattern)
{
	int	current;
	int	tt;
	int	plen;
	int	s2len;

	plen = strlen(pattern);
	s2len = strlen(str);
	tt = 0;
	current = 0;
	while (str[current])
	{
		if ((!tt && current + plen < s2len && strncmp(str + current, pattern, plen) == 0) || tt)
		{
			tt++;
			if (tt >= plen)
			{
				current++;
				break;
			}
		}
		current++;
	}
	return (current);
}

char	*special_strjoin(char *s1, char *s2, char *pattern, int free_s1)
{
	char	*str;
	int		index1;
	int		index2;
	int		s2len;
	int		plen;
	int		tt;

	tt = 0;
	s2len = strlen(s2);
	plen = strlen(pattern);
	str = malloc(sizeof(char) * (strlen(s1) + special_strlen(s2, pattern)));
	if (str == NULL && free_s1)
		return (free(s1), NULL);
	if (str == NULL)
		return (NULL);
	index1 = 0;
	index2 = 0;
	while (s1[index1])
	{
		str[index1] = s1[index1];
		index1++;
	}
	if (free_s1)
		free(s1);
	while (s2[index2])
	{
		str[index1 + index2] = s2[index2];
		if ((!tt && index2 + plen < s2len && strncmp(s2 + index2, pattern, plen) == 0) || tt)
		{
			tt++;
			if (tt >= plen)
			{
				index2++;
				break;
			}
		}
		index2++;
	}
	str[index1 + index2] = '\0';
	return (str);
}

char	*get_next_part(int fd, char *pattern)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes;
	char		*result;

	bytes = 1;
	trimbuffer(buffer, pattern);
	result = special_strjoin("", buffer, pattern, 0);
	if (result == NULL || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytes && !strstr(buffer, pattern))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(result), NULL);
		if (bytes)
		{
			buffer[bytes] = '\0';
			result = special_strjoin(result, buffer, pattern,  1);
			if (result == NULL)
				return (NULL);
		}
	}
	if (strlen(buffer) == 0)
		return (free(result), NULL);
	return (result);
}

char	*get_next_line(int fd)
{
	return (get_next_part(fd, "\n"));
}
