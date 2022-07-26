#include "main.h"

/**
* main - entry point
* @ac: number of args
* @av: array of args
*
* Return: 0
*/
int main(int ac, char **av)
{
	int exe;
	char *buffer = NULL;
	size_t bufsize = 0;

	(void)ac;
	(void)av;
	(void)exe;
	cmd = NULL;

	while (1) /* while loop always happens */
	{
		signal(SIGINT, sighand); /* make sure SIGINT doesn't terminate loop */
		prompt(); /* getline in func returns str and assigns to buffer */
		if (getline(&buffer, &bufsize, stdin) == -1)
		{
			if (isatty(0))
				write(0, "\n", 1);
			break;
		}
		if (!buffer || !buffer[0])
		{
			free(buffer);
			continue;
		}

		cmd = split_string(buffer); /* returns arr of str pointers & assigns to av */

		if (cmd)
			exe = execute(cmd);
	}

	free(buffer);
	free(cmd);
	return (0);
}

/**
* prompt - prints $ to stdout and gets input from user
*
* Return: string entered by user
*/
int prompt(void)
{
	char *ps = "($) ";

	if (isatty(0))
		write(1, ps, _strlen(ps));

	return (0);
}

/**
* split_string - splits string into tokens
* @str: string to split
*
* Return: array of tokens
*/
char **split_string(char *str)
{
	char *token;
	unsigned int i, numTokens = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
			numTokens++;

	}

	cmd = malloc(sizeof(cmd) * (numTokens + 2));
	if (!cmd)
	{
		perror("arg malloc Error");
		return (NULL);
	}

	token = strtok(str, " \n ");
	for (i = 0; i < (numTokens + 1); i++)
	{
		cmd[i] = token;
		token = strtok(NULL, " \n ");
	}
	cmd[i] = NULL;

	if (!cmd[0])
	{
		free(cmd);
		cmd = NULL;
	}

	return (cmd);
}

/**
* execute - executes array of command tokens
* @cmd: array of cmd tokens
*
* Return: 0 if success, -1 on fail
*/
int execute(char **cmd)
{
	int x;
	pid_t child = fork();

	if (child == 0)
		execve(cmd[0], cmd, environ);

	if (child == -1)
		perror("Fork Failure");

	waitpid(child, &x, 0);
	x = WEXITSTATUS(x);
	return (x);
}
