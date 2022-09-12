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

int	ft_print_s(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (0);
}

void	ft_printnbr_s(int n)
{
	char	str;

	if (n == -2147483648)
		ft_print_s("-2147483648");
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_printnbr_s(-n);
	}
	else
	{
		if (9 < n)
			ft_printnbr_s(n / 10);
		str = '0' + n % 10;
		write(1, &str, 1);
	}
}

void	*ft_memset_s(void *dst, int c, size_t n)
{
	size_t			count;
	unsigned char	*str;

	count = 0;
	str = (unsigned char *)dst;
	while (count < n)
	{
		str[count] = (unsigned char)c;
		count++;
	}
	return (dst);
}
