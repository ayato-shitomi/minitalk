/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:53:03 by ashitomi          #+#    #+#             */
/*   Updated: 2022/02/07 10:53:03 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <limits.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

# define STR_MAX_LEN 10000000000

int		ft_print_c(char *str);
void	ft_exit_c(char	*str, int n);
int		ft_atoi_c(const char *str);

int		ft_print_s(char *str);
void	ft_printnbr_s(int n);
void	*ft_memset_s(void *dst, int c, size_t n);

#endif
