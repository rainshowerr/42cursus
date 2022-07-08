#include <stdlib.h>

void *ft_calloc(size_t nmemb, size_t size)
{
    void *space;
    space = malloc(nmemb * sizeof(size));
    if (!space)
        return (0);
    return (space);
}