#include "includes/libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void *space;
    if (!(space = malloc(nmemb * sizeof(size))))
        return (0);
    return (space);
}