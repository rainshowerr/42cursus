#include <stdlib.h>

size_t	ft_strlen(const char	*src)
{
	size_t	k;

	k = 0;
	while (src[k] != '\0')
		k++;
	return (k);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    size_t i;
    size_t j;

    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    i = 0;
    while(i < ft_strlen(s1))
    {
        str[i] = s1[i];
        i++;
    }
    j = 0;
    while(j < ft_strlen(s2))
    {
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return (str);
}

#include <stdio.h>
int main(){
    char* s1 = "seo";
    char* s2 = "shin";
    printf("%s", ft_strjoin(s1, s2));
}