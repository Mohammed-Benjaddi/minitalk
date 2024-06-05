/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:20:03 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/05 16:20:07 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	vars_init(t_data *data)
{
	data->bits = 31;
	data->index = 0;
	data->pid = getpid();
	data->length = 0;
	data->is_allocated = 0;
	data->clt_pid = 0;
	free(data->str);
	data->str = NULL;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putstr_fd("2147483648", 1);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(nbr * -1);
		return ;
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + '0');
	}
	else if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}
