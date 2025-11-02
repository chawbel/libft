#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return (strdup(""));
	if (*set == '\0')
		return strdup(s1);
	start = 0;
	while (is_in_set(s1[start], set))
		start++;
	end = start;
	while (s1[end] && !is_in_set(s1[end], set))
		end++;
	result = malloc((end - start) + 1);
	if (!result)
		return (NULL);
	strlcpy(result, s1 + start, (end - start) + 1);
	return (result);
}

int	main()
{

	char	*result = ft_strtrim("", "");		
	//printf("%s", ft_strtrim("xxxhelloxxx", "a"));
	printf("%s", result);
	free(result);
}
