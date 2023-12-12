/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isposix_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:35:53 by mjochum           #+#    #+#             */
/*   Updated: 2023/10/29 16:09:06 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*	To simplify conversion requirements, use the POSIX
	portable file name character set when naming your files:
		Uppercase A to Z
		Lowercase a to z
		Numbers 0 to 9
		Period (.)
		Underscore (_)
		Hyphen (-)
*/
int	ft_isposix_char(char c)
{
	if ((c >= 'A' && c <= 'Z')
		|| c == '.' || c == '_' || c == '-'
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
