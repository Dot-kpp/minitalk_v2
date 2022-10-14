#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include "../libft/headers/libft.h"

typedef struct s_stack
{
    unsigned char c;
    int i;
}   t_stack;

void	pid_error(void);
void	client_input_error(void);
void	success(int sig);
void	signal_error(void);
void	server_input_error(void);


#endif