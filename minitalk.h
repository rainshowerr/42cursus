#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void    str_to_ten(int  pid, char *string);
void    ten_to_bin(int pid, char c);
void    bin_to_send(int pid, int bit);
void    print_msg(char *msg);
int     ft_atoi(const char *str);
void    print_num(long num);
size_t ft_strlen(char *str);

#endif