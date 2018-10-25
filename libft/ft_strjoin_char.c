/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 18:00:46 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/06 16:32:15 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char *str, char character)
{
	char *char_as_str;
	char *joined_str;

	if (!(char_as_str = ft_strnew(1)))
		return (NULL);
	char_as_str[0] = character;
	joined_str = ft_strjoin(str, char_as_str);
	free(char_as_str);
	return (joined_str);
}
