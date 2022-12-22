# minitalk_v2


This is a program that, from the server side, receives and decodes messages transmitted through signals. It uses two signals, SIGUSR1 and SIGUSR2, to represent the two binary digits (bits) 1 and 0, respectively. The program sets up a signal handler, sig_handler, to handle these signals.

The sig_handler function is called when the program receives a SIGUSR1 or SIGUSR2 signal. It sets the corresponding bit in the c variable to 1 or 0, depending on the signal received. It then increments the i variable, which keeps track of the current bit position in the c variable. If i is equal to 8, it means that all 8 bits in the c variable have been set, and the function writes the character represented by the c variable to the standard output, resets i to 0, and resets c to 0. If i is less than 8, it shifts the bits in the c variable to the left by 1 position to make room for the next bit.

The main function sets up the signal handler for SIGUSR1 and SIGUSR2 using the sigaction function, and then enters an infinite loop where it waits for signals using the usleep function. If the program is called with more than one command line argument, it prints an error message and exits. Otherwise, it prints the process ID of the program using the print_pid function and enters the infinite loop.

From the client side , we send a  message to another the server through signals. It takes the target program's process ID and the message to be sent as command line arguments.

The check_input function checks the validity of the input arguments. It checks that the process ID is between 2 and 99998, and that the message is not empty. If either of these conditions is not met, it prints an error message and exits.

The send_sig function sends the message to the target program. It does this by iterating over the characters in the message, and sending a series of SIGUSR1 and SIGUSR2 signals to represent each character in binary form. It includes a delay using the usleep function between each signal to give the target program time to process each signal. After the message has been sent, it sends an additional series of SIGUSR2 signals to indicate the end of the message.

The main function checks the number of command line arguments and calls the check_input and send_sig functions with the command line arguments if the input is valid. It returns 0 upon completion.
