#include <unistd.h>

int main(int argc, char *argv[])
{
	(void)argc;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (*argv[1] == ' ' || (*argv[1] >= 9 && *argv[1] <= 13))
		argv[1]++;
	while (!(*argv[1] == ' ' || (*argv[1] >= 9 && *argv[1] <= 13)))
	{
		write(1, argv[1], 1);
		argv[1]++;
	}
	return (0);
}
