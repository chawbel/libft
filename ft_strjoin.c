#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	strlcpy(s3, s1, (ft_strlen(s1) + ft_strlen(s2) + 1));
	strlcat(s3, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (s3);
}

int	main()
{
	char	*result = ft_strjoin("hello", "hi");
	printf("%s", result);
	free(result);	
}
