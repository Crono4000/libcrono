
#include "libcrono.h"

char	*ltoa(long n)
{
	char	*result;
	int		size;
	int		negative;

	negative = 0;
	if (n < 0)
	{
		n *= -1;
		negative = 1;
	}
	size = 0;
	while (lpower(10, size) < n)
		size++;
	result = (char *) malloc(sizeof(char) * (size + 1 + negative));
	if (result != NULL)
	{
		putnbr_on_str(result, size + negative - 1, (unsigned long) n);
		result[size] = '\0';
		if (negative)
			result[0] = '-';
	}
	return (result);
}
