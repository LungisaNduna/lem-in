/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_int_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 18:23:43 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/30 16:08:21 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_with_zeros(int *row, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		row[index] = 0;
		index++;
	}
}

int		**ft_create_int_matrix(size_t size)
{
	int		**matrix;
	size_t	index;

	if (!(matrix = (int **)malloc(sizeof(int *) * (size + 1))))
		return (NULL);
	index = 0;
	while (index < size)
	{
		if (!(matrix[index] = (int *)malloc(sizeof(int) * size)))
		{
			while (index)
			{
				free(matrix[index]);
				index--;
			}
			free (matrix);
			return (NULL);
		}
		fill_with_zeros(matrix[index], size);
		index++;
	}
	matrix[size] = NULL;
	return (matrix);
}
