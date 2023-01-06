/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:07:28 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/28 13:52:28 by amitcul          ###   ########.fr       */
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
		while ((token->width_v--) - len > 0)
			count += write(STDOUT_FILENO, " ", 1);
	}
	else
	{
		while ((token->width_v--) - len > 0)
			count += write(STDOUT_FILENO, " ", 1);
		count += write(STDOUT_FILENO, to_print, len);
	}
	return (count);
}

int	print_s(t_token *token, char *value)
{
	int		count;
	char	*tmp;
	char	*to_print;

	count = 0;
	tmp = NULL;
	if (value == NULL)
		to_print = ft_strdup("(null)");
	else
		to_print = ft_strdup(value);
	if (token->precision_v < 0)
		token->precision_v = ft_strlen(to_print);
	if (token->dot == 1 && (token->precision_v < (int)ft_strlen(to_print)))
	{
		tmp = ft_calloc(token->precision_v + 1, sizeof(char));
		ft_strlcpy(tmp, to_print, token->precision_v + 1);
		free(to_print);
		to_print = tmp;
	}
	if (token->width_v > 0)
		count += write_with_width_field(token, to_print);
	else
		count += write(STDOUT_FILENO, to_print, ft_strlen(to_print));
	free(to_print);
	return (count);
}
