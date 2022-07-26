#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: char
 * Return: string length
 */

int _strlen(char *s)
{
	int str = 0;

	while (*s++)
		str++;

	return (str);
}

/**
 * sighand - handles sigint
 * @sig: signal
 */

void sighand(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 5);
}


/**
* _getenv - prints environment to stdout
*/
void _getenv(void)
{
	unsigned int i, j;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
			_putchar(environ[i][j]);

		if (j != 0)
			_putchar(10);
	}
}
