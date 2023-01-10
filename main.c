#include <readline/readline.h>
#include <readline/history.h>

int	main(int argc, char **argv)
{
	char	*prompt;

	prompt = NULL;
	while (1 && argc && argv)
		prompt = readline("Shootgun =>");
	return (0);
}
