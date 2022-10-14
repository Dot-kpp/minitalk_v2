#include "../include/minitalk.h"

void		print_pid(void)
{
	char	*tmp;

	tmp = ft_itoa(getpid());
	write(1, "Server pid: ", 12);
	write(1, tmp, ft_strlen(tmp));
	write(1, "\n", 1);
}

void server_handler (int signum, siginfo_t *s_info, void *content)
{
    (void)content;
    (void)s_info;
    t_stack t_stack;
    t_stack.c |= (signum == SIGUSR1);
    if (t_stack.i++ == 7)
    {
        t_stack.i = 0;
        write(1, &t_stack.c, 1);
        t_stack.c = 0;
    }
    else
        t_stack.c = t_stack.c << 1;

}

int main(int argc, char **argv)
{   
    (void)argv;
    struct sigaction    sa;

    if (argc > 1){
        server_input_error();
    }
    print_pid();
    sa.sa_sigaction = &server_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(1);
}