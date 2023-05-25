#include "shell.h"

/**
 * interactive - If the shell is in interactive mode, this function returns true
 * @info: address of a structure
 *
 * Return: If in interactive mode, 1; otherwise, 0
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - determines whether the character is a delimeter
 * @c: the character to be checked
 * @delim: the string of delimeters
 * Return: If true, 1 is returned; if false, 0 is returned.
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for the presence of an alphabetic character
 * @c: The input character
 * Return: If c is alphabetical, 1 is returned; otherwise, 0 is returned.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - transforms a string to an integer
 * @s: the string that will be transformed
 * Return: If there are no numbers in the string, return 0; otherwise, return the converted number.
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);

}
