#include "shell.h"

/**
 * **strtow - divides a string into words. Repeat separators are disregarded.
 * @str: the data string
 * @d: the string of delimeters
 * Return: a reference to a string array, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int i, f, k, l, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, f = 0; f < numwords; f++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		s[f] = malloc((k + 1) * sizeof(char));
		if (!s[f])
		{
			for (k = 0; k < f; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (l = 0; l < k; l++)
			s[f][l] = str[i++];
		s[f][l] = 0;
	}
	s[f] = NULL;
	return (s);
}

/**
 * **strtow2 - converts a string into words
 * @str: the data string
 * @d: the thermometer
 * Return: a reference to a string array, or NULL on failure
 */

char **strtow2(char *str, char d)
{
	int i, f, k, l, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, f = 0; f < numwords; f++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[f] = malloc((k + 1) * sizeof(char));
		if (!s[f])
		{
			for (k = 0; k < f; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (l = 0; l < k; l++)
			s[f][l] = str[i++];
		s[f][l] = 0;
	}
	s[f] = NULL;
	return (s);
}
