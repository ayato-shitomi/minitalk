/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:53:03 by ashitomi          #+#    #+#             */
/*   Updated: 2022/02/07 10:53:03 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_print_c(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (0);
}

void	ft_exit_c(char	*str, int n)
{
	if (n == 0)
	{
		ft_print_c(str);
		exit(1);
	}
	else if (n == 1)
	{
		ft_print_c(str);
		ft_print_c("Usage\n\t./client [server_pid] [message]\n\n");
		ft_print_c("\t[server_pid] is server's PID.\n");
		ft_print_c("\t[message] is message you want to sent.");
		ft_print_c(" Ascii No.32 to 126 and ENTER only.\n");
		exit(0);
	}
}

static int	ft_so_long_atoi(int bool_ng)
{
	if (bool_ng == -1)
		return (0);
	return (-1);
}

int	ft_atoi_c(const char *str)
{
	int			bool_ng;
	int			i;
	long int	num;

	i = 0;
	bool_ng = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			bool_ng = bool_ng * -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
		if ('0' <= str[i] && str[i] <= '9'
			&& (num * 10 + (str[i] - 48)) / 10 != num && str[i])
			return (ft_so_long_atoi(bool_ng));
	}
	return (num * bool_ng);
}
