/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:30:02 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/13 03:09:59 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

/**
 * Debug includes
*/

# include <stdio.h>

/**
 * Defines
*/

# define TYPE "%cspdiuxX"

/**
 * Structs
*/

typedef struct s_token
{
	char	type;

	int		asterisk;
	int		width_v;
	int		precision_v;
	int		dash;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;

}				t_token;

/**
 * utils.c
*/
int	get_number_length(long long value);


/**
 * debug.c
*/
void	print_token(t_token *token);

/**
 * print_percent.c
*/
int	print_percent(t_token *token);

/**
 * print_c.c
*/
int	print_c(t_token *token, int value);

/**
 * print_s.c
*/
int	print_s(t_token *token, char *value);

/**
 * print_p.c
*/
int	print_p(t_token *token, unsigned int value);

/**
 * print_d.c
*/
int	print_d(t_token *token, int value);

/**
 * print_u.c
*/
int	print_u(t_token *token, unsigned int value);

/**
 * print_x.c
*/
int	print_x(t_token *token, unsigned int value);

#endif
