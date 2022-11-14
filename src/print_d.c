/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:05:38 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/13 03:09:17 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_utils.h"
#include "../includes/ft_printf.h"

// int	print_with_zeros(t_token *token, int value)
// {
// 	if (value < 0)
// 		count += write(STDOUT, "-", 1);

// }

int	print_d(t_token *token, int value)
{
	(void)token;
	(void)value;
	printf("value = %d\n", value);
	return (0);
}
