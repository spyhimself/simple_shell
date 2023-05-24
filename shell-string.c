#include "shell.h"

/**
 * _strlen - returns a string's length
 * @s: the string whose length should be checked
 *
 * Return: the string whose length should be checked
 */
 
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - compares two strangs lexicographically.
 * @s1: the first strangulation
 * @s2: the second strangulation
 *
 * Return: If s1 s2, it is negative; if s1 > s2, it is positive; and if s1 == s2 it is zero
 */
 
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - determines if the needle begins with haystack
 * @haystack: search string
 * @needle: the substring to be discovered
 *
 * Return: address of the next haystack char or NULL
 */
 
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - combines two strings
 * @dest: the final destination buffer
 * @src: the first buffer
 *
 * Return: destination buffer pointer
 */
 
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
