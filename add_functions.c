#include "minitalk.h"

void	ft_putnbr(int n)
{
	int	x;

	x = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		x = n % 10 + '0';
		write(1, &x, 1);
	}
	else
	{
		x = n + '0';
		write(1, &x, 1);
	}
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

static int	number(char *str, int i, long int nb, int minus)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb * minus > 2147483647)
			return (-1);
		if (nb * minus < -2147483648)
			return (0);
		i++;
	}
	return (nb);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			minus;
	int			nb;

	i = 0;
	minus = 1;
	nb = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((str[i] == 45) || (str[i] == 43))
	{
		if (str[i++] == 45)
			minus = -1;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		nb = number((char *)str, i, nb, minus);
		if (nb == -1)
			return (-1);
		if (nb == 0)
			return (0);
	}
	return ((pid_t)nb * minus);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}
