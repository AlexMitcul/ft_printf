/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:05:38 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/17 15:00:18 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_utils.h"
#include "../includes/ft_printf.h"

void	add_sign(char **to_print, char sign)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*to_print);
	tmp = malloc(sizeof(char) * (len + 2));
	tmp[0] = sign;
	tmp[len + 1] = '\0';
	ft_strlcpy(tmp + 1, *to_print, len + 1);
	free(*to_print);
	*to_print = tmp;
}

static void	build_right_size(char **to_print, int length)
{
	int		len;
	char	*res;

	len = ft_strlen(*to_print);
	if (length <= len)
	{
		add_sign(to_print, '-');
		return ;
	}
	res = ft_memset(malloc(sizeof(char) * (length + 2)), (int) '0',
			length + 1);
	res[0] = '-';
	res[length + 1] = '\0';
	ft_strlcpy(res + length - len + 1, *to_print, len + 1);
	free(*to_print);
	*to_print = res;
}

static int	handle_negative_number(t_token *token, char *to_print)
{
	int		count;

	count = 0;
	if (token->dot)
		build_right_size(&to_print, token->precision_v);
	else if (token->dot == 0 && token->dash == 0 && token->zero)
		build_right_size(&to_print, token->width_v - 1);
	else
		add_sign(&to_print, '-');
	if (token->dash)
		count += ft_printf("%-*s", token->width_v, to_print);
	else
		count += ft_printf("%*s", token->width_v, to_print);
	free(to_print);
	return (count);
}

int	print_d(t_token *token, int value)
{
	int		count;
	char	*to_print;

	count = 0;
	if (value >= 0)
		return (print_u(token, value));
	to_print = ft_itoa(((long)value) * -1);
	count += handle_negative_number(token, to_print);
	return (count);
}
