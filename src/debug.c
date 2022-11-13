/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:29:33 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/13 02:42:02 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_token(t_token *token)
{
	if (!token)
		return ;

	printf("%-15s%c\n", "type", token->type);
	printf("%-15s%5d\n", "asterisk", token->asterisk);
	printf("%-15s%5d\n", "width_v", token->width_v);
	printf("%-15s%5d\n", "precision_v", token->precision_v);
	printf("%-15s%5d\n", "dash", token->dash);
	printf("%-15s%5d\n", "zero", token->zero);
	printf("%-15s%5d\n", "dot", token->dot);
	printf("%-15s%5d\n", "hash", token->hash);
	printf("%-15s%5d\n", "space", token->space);
	printf("%-15s%5d\n", "plus", token->plus);
}
