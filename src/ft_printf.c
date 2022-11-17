/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:13:09 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/17 16:13:42 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	init_token(t_token **token)
{
	*token = malloc(sizeof(t_token));
	if (!(*token))
		return (1);
	(*token)->type = 0;
	(*token)->asterisk = 0;
	(*token)->width_v = 0;
	(*token)->precision_v = 0;
	(*token)->dash = 0;
	(*token)->zero = 0;
	(*token)->dot = 0;
	(*token)->hash = 0;
	(*token)->space = 0;
	(*token)->plus = 0;
	return (0);
}

int	get_value_from_format(t_token *token, const char *format, va_list *op)
{
	int	value;

	if (*format == '*')
	{
		token->asterisk = 1;
		value = va_arg(*op, int);
	}
	else
		value = ft_atoi(format);
	if (token->dot == 0)
	{
		if (value < 0)
			token->dash = 1;
		token->width_v = ft_abs(value);
	}
	else
		token->precision_v = value;
	if (token->asterisk == 1)
		return (1);
	return (get_number_length(ft_abs(value), 10));
}

int	fill_token(t_token *token, const char *format, va_list *op)
{
	if (*format == '-')
		token->dash = 1;
	else if (*format == '0' && token->dot == 0)
		token->zero = 1;
	else if (*format == '.')
		token->dot = 1;
	else if (*format == '#')
		token->hash = 1;
	else if (*format == ' ')
		token->space = 1;
	else if (*format == '+')
		token->plus = 1;
	else if ((*format >= '1' && *format <= '9') || *format == '*')
		return (get_value_from_format(token, format, op));
	return (1);
}

int	print(t_token *token, va_list *op)
{
	if (token->type == 'd' || token->type == 'i')
		return (print_d(token, va_arg(*op, int)));
	else if (token->type == '%')
		return (print_percent(token));
	else if (token->type == 'c')
		return (print_c(token, va_arg(*op, int)));
	else if (token->type == 's')
		return (print_s(token, va_arg(*op, char *)));
	else if (token->type == 'p')
		return (print_p(token, va_arg(*op, unsigned long)));
	else if (token->type == 'u')
		return (print_u(token, va_arg(*op, unsigned int)));
	else if (token->type == 'x' || token->type == 'X')
		return (print_x(token, va_arg(*op, unsigned int)));
	return (0);
}

int	parse_and_print(const char **format, va_list *op)
{
	t_token	*token;
	int		count;

	(*format)++;
	token = NULL;
	if (init_token(&token))
		return (0);
	while (ft_strchr(TYPE, **format) == NULL)
		(*format) += fill_token(token, *format, op);
	token->type = **format;
	count = print(token, op);
	free(token);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	op;

	count = 0;
	va_start(op, (char *)format);
	while (*format != '\0')
	{
		if (*format == '%')
			count += parse_and_print(&format, &op);
		else
			count += write(STDOUT_FILENO, format, 1);
		format++;
	}
	return (count);
}
