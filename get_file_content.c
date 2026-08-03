
#include "libcrono.h"

char	*get_file_content(char *file)
{
	int		fd;
	long	size;
	int		content_indice;
	int		bytes_read;
	char	*content;

	content_indice = 0;
	size = get_file_length(file);
	if (size == -1)
		return (NULL);
	content = malloc(sizeof(char) * (size + 1));
	if (content == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (free(content), NULL);
	bytes_read = read(fd, content + content_indice, CPY_BUFFER);
	while (bytes_read == CPY_BUFFER)
	{
		content_indice += bytes_read;
		bytes_read = read(fd, content + content_indice, CPY_BUFFER);
	}
	if (bytes_read == -1)
		return (close(fd), free(content), NULL);
	if (bytes_read > 0)
		content_indice += bytes_read;
	(content)[content_indice] = '\0';
	close(fd);
	return (content);
}
