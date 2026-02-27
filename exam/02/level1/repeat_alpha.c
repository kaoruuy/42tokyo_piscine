#include <unistd.h>

int main(int argc, char *argv[])
{
	int	i;
	int	count;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (*argv[1])
	{
		if (*argv[1] >= 'a' && *argv[1] <= 'z')
		{
			count = *argv[1] - 'a';
			i = 0;
			while (i <= count)
			{
				write(1, argv[1], 1);
				i++;
			}
		}
		else
		{
			write(1, argv[1], 1);
		}
		argv[1]++;
	}
	return (0);
}
