#include "../include/minitalk.h"

void check_input(char *argv, int pid)
{
    if (pid < 2 || pid > 99998)
        pid_error();
    if (ft_strlen(&argv[2]) == 0)
        client_input_error();
}

void send_sig(int pid, char *str)
{
    int i;
    int bin;

    i = 0;
    while (str[i])
    {
        while(bin > 0)
        {
            bin = 128;
            if(bin && str[i])
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            bin /= 2;
            usleep(10);
        }
        i++;
    }
}

int main (int argc, char **argv)
{
    int pid;

    if (argc != 3)
    {
        client_input_error();
    }
    pid = ft_atoi(argv[1]);
    check_input(*argv, pid);
    send_sig(pid, argv[2]);
    return (0);
}