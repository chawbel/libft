#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	int	in_word;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	ft_free(char **s, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static char	*ft_allocate_word(char const *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	strlcpy(word, s, len + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;

	i = 0;
	result = malloc((ft_count_words(s, c) + 1) * 8);
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[i] = ft_allocate_word(s, c);
			if (!result[i])
			{
				ft_free(result, i);
				return (NULL);
			}
			while (*s && *s != c)
				s++;
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}

int	main()
{
	char	*a = ("aibca baobcaob aobao aoibcsoi    ocaoi   abcoas  ");
	char	**s = ft_split(a, ' ');
	printf("%s", s[0]);
	//printf("%ld", ft_count_words(a, ' '));
	ft_free(s, ft_count_words(a, ' '));
}
