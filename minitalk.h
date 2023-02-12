#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void    str_to_ten(int  pid, char *string);
void    ten_to_bin(int pid, char c);
void    bin_to_send(int pid, int bit);
void    print_msg(char *msg);

#endif