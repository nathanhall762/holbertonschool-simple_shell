#include "main.h"

/**
* builtins - checks if cmd tokens call builtin function
* @cmd: string of cmd[0] from main
*
* Return: 0 if no builtin is called, else 1
*/
int builtins(char *cmd)
{
	char *builtin_list[] = { "env", "exit", NULL};

	if (_strcmp(cmd, builtin_list[0]) == 0)
	{
		env();
		return (1);
	}
	if (_strcmp(cmd, builtin_list[1]) == 0)
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}

/**
 * env - prints the environment
 *
 * Return: Always 0.
 */
void env(void)
{
	unsigned int i = 0, j = 0;

	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
		{
			_putchar(environ[i][j]);
			j++;
		}

		if (j != 0)
			_putchar('\n');
		i++;
	}
}
