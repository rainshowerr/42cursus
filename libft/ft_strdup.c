#include <stdlib.h>

size_t	ft_strlen(const char *src)
{
	size_t  i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}