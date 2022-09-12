/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:53:03 by ashitomi          #+#    #+#             */
/*   Updated: 2022/02/07 10:53:03 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_signal(pid_t pid, char c)
{
	int	bit;
	int	err;

	bit = 7;
	while (bit != -1)
	{
		if (c & (1 << bit))
			err = kill(pid, SIGUSR1);
		else
			err = kill(pid, SIGUSR2);
		if (err == -1)
			ft_exit_c(" > BAD PID\n", 0);
		bit--;
		usleep(100);
	}
}

static void	send_str(pid_t pid, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		send_signal(pid, str[i]);
		i++;
	}
	send_signal(pid, '\0');
}

static int	str_check(char *str)
{
	size_t	n;

	n = 0;
	while (str[n])
	{
		if ((' ' <= str[n] && str[n] <= '~') || str[n] == '\n')
			n++;
		else
			return (1);
	}
	return (0);
}

static	int	pid_check(char *pid)
{
	size_t	n;

	n = 0;
	while (pid[n])
	{
		if ('0' <= pid[n] && pid[n] <= '9')
			n++;
		else
			return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
		ft_exit_c(" > WRONG ARG\n", 1);
	if (pid_check(argv[1]) == 1)
		ft_exit_c(" > BAD PID\n", 0);
	pid = ft_atoi_c(argv[1]);
	if (pid < 100 || 99998 < pid)
		ft_exit_c(" > BAD PID\n", 0);
	str = argv[2];
	if (str_check(str) == 1)
		ft_exit_c(" > BAD STRING\n", 1);
	send_str(pid, str);
	ft_print_c(" > ");
	ft_print_c(argv[2]);
	ft_print_c("\n");
	return (0);
}
