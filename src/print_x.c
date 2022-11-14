/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:59:03 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/13 23:05:47 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_utils.h"
#include "../includes/ft_printf.h"

char	*to_hex(long long value)
{
	int		len;
	char	*res;

	len = get_number_length((long long) value, 16);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	len--;
	while (len >= 0)
	{
		res[len] = "0123456789abcdef"[ft_abs(value % 16)];
		value = value / 16;
		len--;
	}
	return (res);
}

static void	to_upper_case(char **str)
{
	char	*p;

	p = *str;
	while (*p != '\0')
	{
		if (*p >= 'a' && *p <= 'z')
			*p -= 32;
		p++;
	}
}

static int	print_with_zeros(t_token *token, char *to_print)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(to_print);
	if (token->hash == 1 && token->type == 'x' && to_print[0] != '0')
		count += write(STDOUT_FILENO, "0x", 2);
	else if (token->hash == 1 && token->type == 'X' && to_print[0] != '0')
		count += write(STDOUT_FILENO, "0X", 2);
	if (token->hash == 1)
		token->width_v -= 2;
	if (token->zero == 1 && token->dot == 0)
		while ((token->width_v-- - len) > 0)
			count += write(STDOUT_FILENO, "0", 1);
	else
		while ((token->width_v-- - len) > 0)
			count += write(STDOUT_FILENO, " ", 1);
	count += write(STDOUT_FILENO, to_print, ft_strlen(to_print));
	return (count);
}

static int	write_with_width_field(t_token *token, char *to_print)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(to_print);
	if (token->hash == 1 && to_print[0] != '0')
		len += 2;
	if (token->dash == 1)
	{
		if (token->hash == 1 && token->type == 'X')
			count += write(STDOUT_FILENO, "0X", 2);
		else if (token->hash == 1 && token->type == 'x')
			count += write(STDOUT_FILENO, "0x", 2);
		if (token->hash == 1)
			count += write(STDOUT_FILENO, to_print, len - 2);
		else
			count += write(STDOUT_FILENO, to_print, len);
		while ((token->width_v--) - len > 0)
			count += write(STDOUT_FILENO , " ", 1);
	}
	else
		return (print_with_zeros(token, to_print));
	return (count);
}


int	print_x(t_token *token, unsigned int value)
{
	int		count;
	char	*hex;
	char	*tmp;

	count = 0;
	hex = to_hex(value);
	if (!hex)
		return (0);
	if (token->type == 'X')
		to_upper_case(&hex);
	if (token->dot == 1 && (token->precision_v > (int)ft_strlen(hex) || token->precision_v == 0))
	{
		tmp = ft_memset(malloc(sizeof(char) * (token->precision_v + 1)), '0', token->precision_v);
		tmp[token->precision_v + 1] = '\0';
		strlcpy(tmp + (token->precision_v - ft_strlen(hex)), hex, ft_strlen(hex) + 1);
		free(hex);
		hex = tmp;

	}
	if (token->width_v >= 0)
		count += write_with_width_field(token, hex);
	else
		count += write(STDOUT_FILENO, hex, ft_strlen(hex));
	free(hex);
	return (count);
}
