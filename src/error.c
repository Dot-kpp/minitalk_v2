#include "../include/minitalk.h"

void	pid_error(void)
{
	write(1, "Incorrect PID", 13);
	exit(1);
}

void	client_input_error(void)
{
	write(1, "Please enter a valid input: ./client [server-pid] [message]\n", 59);
	exit(1);
}

void	server_input_error(void)
{
	write(1, "Please enter a valid input: ./server\n", 38);
	exit(1);
}

void	signal_error(void)
{
	write(1, "Signal error\n", 13);
	exit(0);
}

void	success(int sig)
{
	(void)sig;
	write(1, "Received!\n", 10);
}