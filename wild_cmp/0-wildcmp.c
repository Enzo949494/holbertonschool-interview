#include "holberton.h"

/**
 * wildcmp - compares two strings, s2 can contain '*' wildcards
 * @s1: the string to compare
 * @s2: the pattern, may contain '*' which matches any sequence
 *
 * Return: 1 if s1 matches s2, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0')
		return (*s1 == '\0');

	if (*s2 == '*')
	{
		if (wildcmp(s1, s2 + 1))
			return (1);
		if (*s1 != '\0')
			return (wildcmp(s1 + 1, s2));
		return (0);
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
