
#include "libft.h"

int	countpalabras(char const *s, char c)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while(s[i] == c)
			i++;
		if (s[i] != c)
			count ++;
		while(s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

void hazsplit(char **cad, char const *s, char c)
{
	int i;
	int	count;
	int	countword;

	countword = 0;
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i ++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			count ++;
		}
		if (s[i] == c || count > 0)
		{
			cad[countword] = ft_substr((s + i) - count, 0, count);
			countword ++;
			count = 0;
		}
	}
	cad[countword] = NULL;
}

char **ft_split(char const *s, char c)
{
	char	**cad;
	int		count;
	if(!s)
		return (NULL);
	count = countpalabras(s, c);
	cad = (char **)malloc(sizeof(char*) * (count + 1));
	if (!cad)
		return (NULL);
	hazsplit(cad, s, c);
	return (cad);
}
