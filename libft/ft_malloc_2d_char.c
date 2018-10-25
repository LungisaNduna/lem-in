/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_2d_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:37:34 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/30 16:09:24 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_malloc_2d_char(size_t size)
{
	char	**two_d_char_array;
	size_t	index;

	if (!(two_d_char_array = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	index = 0;
	while (index <= size)
	{
		two_d_char_array[index] = NULL;
		index++;
	}
	return (two_d_char_array);
}
