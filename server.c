#include "minitalk.h"

int ft_pow(int n, int i)
{
    int idx;
    int num;

    idx = 0;
    num = 1;
    while(idx < i)
    {
        num *= n;
        idx++;
    }
    return num;
}

int convert(int n) {
    int dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * ft_pow(2, i);
        i++;
    }
    return dec;
}

void    handler(int sig)
{
    static int cnt;
    static int temp;

    if (sig == SIGUSR1)
    {
        temp += 1;
        printf("sig1\n");
    }
    else if (sig == SIGUSR2)
    {
        temp += 0;
        printf("sig2\n");
    }
    cnt++;
    if (cnt != 8)
        temp *= 10;
    else
    {
        printf("8bit finish\n");
        printf("%c", convert(temp));
        temp = 0;
        cnt = 0;
    }
}

int	main(void)
{
	printf("server pid : %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}