#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * check_window - checks if substring s[start..start+window_len] is a valid
 *                concatenation of all words exactly once
 * @s: the string
 * @start: starting index
 * @words: array of words
 * @nb_words: number of words
 * @word_len: length of each word
 *
 * Return: 1 if valid, 0 otherwise
 */
static int check_window(char const *s, int start, char const **words,
			int nb_words, int word_len)
{
	int *used;
	int i;
	int j;
	int found;
	char const *chunk;

	used = calloc(nb_words, sizeof(int));
	if (!used)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		chunk = s + start + i * word_len;
		found = -1;
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] && strncmp(chunk, words[j], word_len) == 0)
			{
				found = j;
				break;
			}
		}
		if (found == -1)
		{
			free(used);
			return (0);
		}
		used[found] = 1;
	}
	free(used);
	return (1);
}

/**
 * find_substring - finds all starting indices of substrings that are
 *                  concatenations of all words exactly once
 * @s: the string to scan
 * @words: array of words
 * @nb_words: number of words
 * @n: address to store the number of results
 *
 * Return: allocated array of indices, or NULL if none found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len;
	int word_len;
	int window_len;
	int *result;
	int count;
	int i;

	*n = 0;
	if (!s || !words || nb_words <= 0)
		return (NULL);

	s_len = strlen(s);
	word_len = strlen(words[0]);
	window_len = word_len * nb_words;

	if (s_len < window_len)
		return (NULL);

	result = malloc(s_len * sizeof(int));
	if (!result)
		return (NULL);

	count = 0;
	for (i = 0; i <= s_len - window_len; i++)
	{
		if (check_window(s, i, words, nb_words, word_len))
			result[count++] = i;
	}

	*n = count;
	if (count == 0)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
