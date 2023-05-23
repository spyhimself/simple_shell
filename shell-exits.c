#include "shell.h"

/**
 **_strncpy - a string is copied
 *@dest: the string that will be copied to
 *@src: the source text
 *@n: the number of characters that must be copied
 *Return: the string that has been concatenated
 */
 
char *_strncpy(char *dest, char *src, int n)
{
	int i, f;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		f = i;
		while (f < n)
		{
			dest[f] = '\0';
			f++;
		}
	}
	return (s);
}

/**
 **_strncat - combines two strings
 *@dest: the first line
 *@src: the second line
 *@n: the maximum number of bytes to be utilized
 *Return: the string that has been concatenated
 */
 
char *_strncat(char *dest, char *src, int n)
{
	int i, f;
	char *s = dest;

	i = 0;
	f = 0;
	while (dest[i] != '\0')
		i++;
	while (src[f] != '\0' && f < n)
	{
		dest[i] = src[f];
		i++;
		f++;
	}
	if (f < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - finds a character within a string
 *@s: the string that will be parsed
 *@c: the person to seek out
 *Return: (s) a reference to the memory space s
 */
 
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
