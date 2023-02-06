# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void bin_to_send(int pid, int bit)
{
    if (bit == 0)
    {
        printf("0");
        kill(pid, SIGUSR1);
    }
    else if (bit == 1)
    {
        printf("1");
        kill(pid, SIGUSR2);
    }
    usleep(100);
}

void ten_to_bin(int pid, int n, int cnt)
{
    if (n > 0)
    {
        ten_to_bin(pid, n / 2, cnt + 1);
        bin_to_send(pid, n % 2);
    }
    else if (n == 0)
    {
        while (cnt < 8)
        {
            bin_to_send(pid, 0);
            cnt++;
        }
    }
}

void    str_to_ten(int  pid, char *string)
{
    int i;
    int data;
    int bit_sh;

    i = 0;
    while (string[i])
    {
        data = (int)string[i];
        ten_to_bin(pid, data, 0);
        i++;
    }
}

int main(int ac, char **av)
{
    int plate;
    int i;

    i = 0;
    plate = 0;
    if (ac != 3)
        printf("usage : ./a.out [server's pid] [string]\n");
    else
    {
        plate = atoi(av[1]);
        str_to_ten(plate, av[2]);
    }
}