#include <unistd.h>

int	main()
{
	int i;
	char c;
	i = 9;
	while (i >= 0)
	{
		c = i + '0';
		write(1, &c, 1);
		i--;
	}
	return (0);
}