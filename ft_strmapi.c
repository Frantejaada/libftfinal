
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int i;
	char *result;

	i = 0;
	if (!s || !f)
		return (NULL);
	result = (char *)malloc(sizeof(char) * ft_strlen(s));
	if(!result)
		return NULL;
	while (s[i])
	{
		result[i] = (*f)(i, (char)(s[i]));
		i ++;
	}
	result[i] = '\0';
	return (result);
}