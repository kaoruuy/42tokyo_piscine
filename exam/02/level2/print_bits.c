#include <unistd.h>

void	print_bits(unsigned char octet)
{
	char	bits[8];
	int	nb;
	int	i;
	char	c;

	nb = octet;
	i = 0;
	while (i < 8)
	{
		bits[i] = nb % 2;
		nb = nb / 2;
		i++;
	}
	while (i - 1 >= 0)
	{
		c = bits[i - 1] + '0';
		write(1, &c, 1);
		i--;
	}
}
