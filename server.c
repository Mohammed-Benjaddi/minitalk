/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:54:22 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/06 16:35:22 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	catch_data(int signal)
{
	if (signal == SIGUSR1)
		g_data.character |= (1 << g_data.bits_char);
	g_data.bits_char--;
	if (g_data.bits_char < 0)
	{
		g_data.bits_char = 8;
		g_data.str[g_data.index] = g_data.character;
		g_data.index++;
		g_data.character = 0;
	}
	if (g_data.length == g_data.index)
	{
		g_data.str[g_data.index] = '\0';
		ft_putstr_fd(g_data.str, 1);
		vars_init(&g_data);
	}
}

void	allocate_len(void)
{
	g_data.str = malloc(g_data.length + 1);
	if (!g_data.str)
	{
		vars_init(&g_data);
		ft_error();
	}
	g_data.is_allocated = 1;
}

void	handler(int signal, siginfo_t *sip, void *notused)
{
	(void)notused;
	if (g_data.clt_pid != sip->si_pid)
	{
		vars_init(&g_data);
		g_data.clt_pid = sip->si_pid;
	}
	if (g_data.bits >= 0 && g_data.is_allocated == 0)
	{
		if (signal == SIGUSR1 && g_data.is_allocated == 0)
			g_data.length |= (1 << g_data.bits);
		g_data.bits--;
	}
	else
	{
		if (g_data.is_allocated == 0 && g_data.length >= 0)
			allocate_len();
		catch_data(signal);
	}
}

int	main(void)
{
	struct sigaction	sa;

	vars_init(&g_data);
	g_data.clt_pid = 0;
	g_data.pid = getpid();
	ft_putnbr(g_data.pid);
	ft_putchar('\n');
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		continue ;
	return (0);
}
