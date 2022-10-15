/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:50:10 by jpilotte          #+#    #+#             */
/*   Updated: 2022/10/15 14:06:47 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_stack	g_stack;

void	print_pid(void)
{
	char	*tmp;

	tmp = ft_itoa(getpid());
	write(1, "Server pid: ", 12);
	write(1, tmp, ft_strlen(tmp));
	write(1, "\n", 1);
}

static	void	sig_handler(int signum, siginfo_t *s_info, void *content)
{
	(void) content;
	(void) s_info;
	g_stack.c |= (signum == SIGUSR1);
	if (g_stack.i++ == 7)
	{
		g_stack.i = 0;
		write(1, &g_stack.c, 1);
		g_stack.c = 0;
	}
	else
		g_stack.c = g_stack.c << 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void) argv;
	if (argc > 1)
	{
		server_input_error();
	}
	print_pid();
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(300);
}
