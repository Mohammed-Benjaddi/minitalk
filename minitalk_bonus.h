/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:44:55 by mben-jad          #+#    #+#             */
/*   Updated: 2024/06/05 16:37:41 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		pid;
	size_t	length;
	int		bits;
	size_t	index;
	char	*str;
	int		is_allocated;
	char	character;
	int		clt_pid;
}			t_data;

void		ft_putstr_fd(char *str, int fd);
int			ft_atoi(char *str);
int			ft_strlen(char *str);
void		ft_error(void);
void		vars_init(t_data *data);
void		ft_putchar(char c);
void		ft_putnbr(int nbr);

#endif