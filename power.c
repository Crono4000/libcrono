
long	lpower(long b, int p)
{
	if (p == 0)
		return (1);
	return (b * lpower(b, p - 1));
}

int		ipower(int b, int p)
{
	if (p == 0)
		return (1);
	return (b * ipower(b, p - 1));
}
