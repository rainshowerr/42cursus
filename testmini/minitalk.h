#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	rec_putnbr(int nb, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

#endif