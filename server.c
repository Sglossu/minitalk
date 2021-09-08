#include "minitalk.h"

void	sighandler(int signum, siginfo_t *siginfo, void *unused)
{
	static int	c = 0;
	static int	count = 0;

	(void)unused;
	if (signum == SIGUSR2)
		c += 0b00000001 << (7 - count);
	count += 1;
	if (count == 8)
	{
		ft_putchar(c);
		if (c == 0b00000000)
		{
			ft_putchar('\n');
			if (kill(siginfo->si_pid, SIGUSR1) < 0)
				ft_putstr("Error signal\n");
		}
		count = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	catch;

	(void)argv;
	if (argc > 1)
		ft_putstr("Error\n");
	else
	{
		write(1, "Server started\nPID: ", 21);
		ft_putnbr(getpid());
		write(1, "\n", 1);
		sigemptyset(&catch.sa_mask);
		sigaddset(&catch.sa_mask, SIGUSR1);
		sigaddset(&catch.sa_mask, SIGUSR2);
		catch.sa_flags = SA_SIGINFO;
		catch.sa_sigaction = sighandler;
		if ((sigaction(SIGUSR1, &catch, 0)) < 0)
			ft_putstr("Error sigaction\n");
		if ((sigaction(SIGUSR2, &catch, 0)) < 0)
			ft_putstr("Error sigaction\n");
		while (1)
			pause();
	}
	return (0);
}
