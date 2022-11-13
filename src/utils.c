/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:20:17 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/13 03:08:00 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_number_length(long long value)
{
	int	length;

	if (value == 0)
		return (1);
	length = 0;
	while (value > 0)
	{
		length += 1;
		value = value / 10;
	}
	return (length);
}
