/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:53:03 by ashitomi          #+#    #+#             */
/*   Updated: 2022/02/07 10:53:03 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	put_pid(pid_t pid)
{
	ft_print_s(" > This server's PID is '");
	ft_printnbr_s(pid);
	ft_print_s("'\n");
}

static void	sig_handler(int sig)
{
	static char	buf[STR_MAX_LEN] = {'\0', };
	static int	bit = 7;
	static int	i = 0;

	if (sig == SIGUSR1)
		buf[i] |= (1 << bit);
	if (sig == SIGUSR2)
		buf[i] &= ~(1 << bit);
	bit--;
	if (bit == -1)
	{
		bit = 7;
		if (buf[i] == '\0')
		{
			ft_print_s(buf);
			ft_print_s("\n");
			ft_memset_s(buf, '\0', STR_MAX_LEN);
			i = 0;
		}
		else
			i++;
	}
}

int	main(void)
{
	put_pid(getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
