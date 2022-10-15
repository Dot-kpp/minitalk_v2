/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:50:26 by jpilotte          #+#    #+#             */
/*   Updated: 2022/10/15 13:59:18 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	pid_error(void)
{
	write(1, "Incorrect PID", 13);
	exit(1);
}

void	client_input_error(void)
{
	write(1, "Enter a valid input: ./client [server-pid] [message]\n", 54);
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
