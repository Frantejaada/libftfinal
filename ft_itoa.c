
#include "libft.h"

int	countdigits(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		n = -2147483647;
	if (n < 0)
		n = n * -1;
	while (n >= 10)
	{
		n = n / 10;
		count ++;
	}
	if (n >= 0 && n <= 9)
		count ++;
	return (count);
}

void	comunpart(char *cad, int n, int etapa)
{
	if (n == -2147483648)
	{
		cad[1] = '2';
		n = 147483648;
	}
	if (n < 10)
	{
		cad[etapa] = (n + 48);
		return ;
	}
	else
	{
		comunpart(cad, (n / 10), etapa - 1);
		comunpart(cad, (n % 10), etapa);
	}
}

char *ft_itoa(int n)
{
	int		count;
	char	*cad;

	count = countdigits(n);
	if (n < 0)
	{
		count ++;
		cad = (char *)malloc(sizeof(char) * (count + 1));
		if (!cad)
			return NULL;
		cad [0] = '-';
		comunpart(cad, (n * -1), (count - 1));
		cad[count] = '\0';
	}
	else
	{
		cad = (char *)malloc(sizeof(char) * (count + 1));
		if (!cad)
			return NULL;
		comunpart(cad, n, (count - 1));
		cad[count] = '\0';
	}
	return	(cad);
}
