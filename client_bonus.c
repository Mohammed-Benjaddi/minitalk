/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:54:39 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/05 15:38:43 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_char(pid_t pid, char character)
{
	int	i;

	i = 8;
	while (i >= 0)
	{
		if (character & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

void	send_len(int pid, int length)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (length & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

void	handle_receievd_msg(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("message has been received successfully", 1);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac != 3)
		exit(0);
	signal(SIGUSR1, handle_receievd_msg);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		ft_error();
	i = 0;
	send_len(pid, ft_strlen(av[2]) + 1);
	while (av[2][i])
	{
		send_char(pid, av[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
