/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:54:39 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/03 16:51:17 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	send_len(pid_t pid, int length)
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

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	if (ac != 3)
		exit(0);
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
