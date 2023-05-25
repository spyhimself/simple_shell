#include "shell.h"

/**
 * _eputs - outputs an input string
 * @str: the string that will be printed
 *
 * Return: Nothing
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - stderr is where the character c is written.
 * @c: The printed character
 *
 * Return: Regarding success 1.
 * On error,The value -1 is returned, and errno is suitably set.
 */

int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes the character c to the specified fd
 * @c: The printed figure
 * @fd: The file descriptor to which to write
 *
 * Return: Regarding success 1.
 * On error, The value -1 is returned, and errno is suitably set.
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - outputs an input string
 * @str: the string that will be printed
 * @fd: the file descriptor to which to write
 *
 * Return: the number of characters entered
 */

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);

}
