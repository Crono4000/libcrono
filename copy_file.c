
#include "libcrono.h"

int	copy_file(char *file1, char *file2)
{
	char	buffer[CPY_BUFFER];
	int		fd1;
	int		fd2;
	int		bytes_read;
	int		write_return;

	fd1 = open(file1, O_RDONLY);
	if (fd1 == -1)
		return (3);
	fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd2 == -1)
		return (close(fd1), 3);
	bytes_read = read(fd1, buffer, sizeof(buffer));
	while (bytes_read == sizeof(buffer))
	{
		write_return = write(fd2, buffer, bytes_read);
		if (write_return == -1)
			return (close(fd1), close(fd2), 1);
		bytes_read = read(fd1, buffer, sizeof(buffer));
	}
	if (bytes_read == -1)
		return (close(fd1), close(fd2), 2);
	if (bytes_read > 0)
	{
		write_return = write(fd2, buffer, bytes_read);
		if (write_return == -1)
			return (close(fd1), close(fd2), 1);
	}
	return (0);
}
