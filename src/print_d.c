/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:05:38 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/16 05:27:28 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_utils.h"
#include "../includes/ft_printf.h"

static int	write_with_width_field(t_token *token, char *to_print)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(to_print);
	if (token->dash == 1)
	{
		count += write(STDOUT_FILENO, to_print, len);
		while ((token->width_v-- - len) > 0)
			count += write(STDOUT_FILENO, " ", 1);
	}
	else
	{
		while ((token->width_v-- - len) > 0)
			count += write(STDOUT_FILENO, " ", 1);
		count += write(STDOUT_FILENO, to_print, len);
	}
	return (count);
}

int	print_with_zeros(t_token *token, char *value)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(value);
	if (value < 0)
		count += write(STDOUT_FILENO, "-", 1);
	if (token->precision_v > len)
	{
		while ((token->precision_v-- - len) > 0)
			count += write(STDOUT_FILENO, "0", len);
		count += write(STDOUT_FILENO, value, len);
	}
	else
	{
	}
	return (count);
}

int	print_d(t_token *token, int value)
{
	int		count;
	char	*to_print;

	count = 0;
	to_print = ft_itoa(value);
	if (!to_print)
		return (0);
	if (token->dot || token->zero)
		count += print_with_zeros(token, to_print);
	else if (token->width_v > 0)
		count += write_with_width_field(token, to_print);
	else
		count += write(STDOUT_FILENO, to_print, ft_strlen(to_print));
	free(to_print);
	return (count);
}
