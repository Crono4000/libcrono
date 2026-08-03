
void	putnbr_on_str(char *str, int index, unsigned long n)
{
	if (n >= 10)
		putnbr_on_str(str, index - 1, n / 10);
	str[index] = '0' + (n % 10);
}
