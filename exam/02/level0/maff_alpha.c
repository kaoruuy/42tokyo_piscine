#include <unistd.h>

int main()
{
	int i;
	char c;
	char d;
	i = 0;
	c = 'a';
	while (c >= 'a' && c <= 'z')
	{
		if (i % 2 == 0)
			d = c;
		else
			d = c - 'a' + 'A';
		write(1, &d, 1);
		i++;
		c++;
	}
	return (0);
}