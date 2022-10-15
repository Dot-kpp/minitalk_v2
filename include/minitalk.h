/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:50:49 by jpilotte          #+#    #+#             */
/*   Updated: 2022/10/15 13:54:14 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include	<signal.h>
# include	<unistd.h>
# include	"../libft/headers/libft.h"

typedef struct s_stack
{
	unsigned char	c;
	int				i;
}	t_stack;

void	pid_error(void);
void	client_input_error(void);
void	success(int sig);
void	signal_error(void);
void	server_input_error(void);

#endif
