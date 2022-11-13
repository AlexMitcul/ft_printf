/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:30:02 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/13 20:44:37 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

/**
 * Debug includes
*/

# include <stdio.h>
# include <string.h>

/**
 * Defines
*/

# define TYPE "%cspdiuxX"

# define MAX 1000000

/**
 * Colors
*/

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define DEFAULT "\033[0m"
# define YELLOW "\033[0;33m"

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
int	get_number_length(long long value, int base);
int	ft_abs(int x);

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
int	print_c(t_token *token, unsigned char value);

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
