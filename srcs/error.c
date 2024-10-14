/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 04:13:54 by eonoh             #+#    #+#             */
/*   Updated: 2024/10/14 00:18:06 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ms_test.h"

void	print_error_and_exit(char *s)
{
	if (errno == 0)
		write(2, s, ft_strlen(s));
	else
		perror(s);
	exit(EXIT_FAILURE);
}

void	exit_error(char *s)
{
	size_t	len;

	len = ft_strlen(": numeric argument required\n");
	write(2, "exit: ", ft_strlen("exit: "));
	write(2, s, ft_strlen(s));
	write(2, ": numeric argument required\n", len);
	exit(255);
}
