#include "minitalk.h"

static	int	conversion(char c, pid_t pid)
{
	int	num;
	int	a;

	a = 1;
	num = 128;
	while (num > 0)
	{
		if (num & c)
			a = kill(pid, SIGUSR2);
		else
			a = kill(pid, SIGUSR1);
		num = num >> 1;
		usleep(50);
	}
	return (a);
}

static	void	message(char *str, pid_t pid)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (str[i] != '\0')
	{
		a = conversion(str[i], pid);
		i += 1;
		if (a < 0)
			break ;
	}
	conversion('\0', pid);
	if (a < 0)
		ft_putstr("Error pid\n");
}

void	ft_exit(int signum, siginfo_t *siginfo, void *unused)
{
	(void)signum;
	(void)siginfo;
	(void)unused;
	ft_putstr("Signal received\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	catch;

	if (argc == 1)
	{
		ft_putstr("Not enough arguments\n");
		return (0);
	}
	catch.sa_flags = SA_SIGINFO;
	catch.sa_sigaction = ft_exit;
	sigaction(SIGUSR1, &catch, 0);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		ft_putstr("Error pid\n");
		return (0);
	}
	if (argc < 3)
		ft_putstr("Not enough arguments\n");
	else if (argc > 3)
		ft_putstr("A lot of agrumets\n");
	else
		message(argv[2], pid);
	return (0);
}
