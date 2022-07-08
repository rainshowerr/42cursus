#include <stdlib.h>
void ft_bzero(void *s, size_t n)
{
    size_t i;
    unsigned char *ss;
    
    ss = (unsigned char *)s;
    i = 0;
    while(i < n)
    {
        ss[i] = 0;
        i++;
    }
}