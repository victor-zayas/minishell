#include <readline/readline.h>
#include <readline/history.h>

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		while (1)
			readline(argv[1]);
		return (0);
	}
}
