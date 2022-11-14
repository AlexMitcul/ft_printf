/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:06:46 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/13 23:09:46 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_utils.h"
#include "../includes/ft_printf.h"

int	print_percent(t_token *token)
{
	int	count;

	count = 0;
	if (token->dash == 1)
	{
		count += write(STDOUT_FILENO, "%", 1);
		while (token->width_v-- > 1)
			count += write(STDOUT_FILENO, " ", 1);
	}
	else
	{
		if (token->zero == 1)
			while (token->width_v-- > 1)
				count += write(STDOUT_FILENO, "0", 1);
		else
			while (token->width_v-- > 1)
				count += write(STDOUT_FILENO, " ", 1);
		count += write(STDOUT_FILENO, "%", 1);
	}
	return (count);
}
