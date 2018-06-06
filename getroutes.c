/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getroutes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:10:16 by lnduna            #+#    #+#             */
/*   Updated: 2017/11/28 16:29:30 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	addroom(int **matrix, int *roomtoadd, int *index_p)
{
	size_t index;

	index = 2
	while (matrix[0][index] >= 1)
		index++;
	matrix[0][index] = *roomtoadd;
	index = 2;
	while (matrix[index_p][index] >= 1)
		index++;
	matrix[index_p][index] = *roomtoadd;
}

static void	addroomtonewroute(int **matrix, int *room, int *index_p)
{
	size_t index;

	index = 1;
	while (matrix[index_p + index] != NULL)
		index++;
	matrix[index_p + index] = (int *)(ft_memcpy(sizeof(matrix[index_p])));
	index_p = index_p + index;
	index = 2;
	while (matrix[index_p][index] > 0)
		index++;
	matrix[index_p][index - 1] = 0;
	addroom(matrix, room, index_p);
	
}

static int	roomfree(int *room, int *path)
{
	size_t index;

	index = 1;
	while (path[index])
	{
		if (path[index] == *room)
			return (0)
		index++;
	}
	return (1);
}

static void	checknextrooms(int **matrix, int **links, size_t *ind, int end)
{
	size_t index_r;
	size_t room;

	room = matrix[ind][matrix[ind][0]];
	if (links[room][end] == 1)
		matrix[*ind][matrix[*ind][0] + 1] = end;
	else
	{
		while (links[room][end] != 1 && end >= 0)
			end--;
		if (links[room][end] == 1 && roomfree(&end, matrix[0]) == 1)
		{
			matrix[ind][0]++;
			addroom (matrix, &end, &ind);
		}
		while (end <= 0)
		{
			if (links[room][end] == 1 && roomfree(&end, matrix[0]) == 1)
				addroomtonewroute(matrix, end, ind);
			end--;
		}
	}
}

void		getroutes(int **matrix, int **links, int end)
{
	size_t index_p;
	size_t index_r;

	while (matrix[0][0] <= end + 1)
	{
		index_p = 1;
		while (index_p <= end && matrix[index_p] != NULL)
		{
			if (matrix[index_p] == matrix[0][0])
				checknextrooms(matrix, links, &index_p, end);
			index_p++;
		}
		matrix[0][0]++;
	}
}
