#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*s_ptr;
	size_t	i;

	i = 0;
	s_ptr = (unsigned char *) s;
	while (i < len)
	{
		s_ptr[i] = 0;
		i++;
	}
}

void  *ft_calloc(size_t nmemb, size_t size)
{
  size_t  total;
  char *ptr;

  if (nmemb != 0 && nmemb > ((size_t) - 1) / size)
    return (NULL);
  total = nmemb * size;
  ptr = malloc(total);
  if (!ptr)
    return (NULL);
  ft_bzero(ptr, total);
  return (ptr);
}

int	main()
{
  char *a = ft_calloc(2, 8);
  if (a)
  {
    for (int i = 0; i < 16; i++)
        printf("%d ", a[i]); // should all be 0
    free(a);
  }
}
