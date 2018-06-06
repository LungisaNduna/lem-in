/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storelinks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:40:36 by lnduna            #+#    #+#             */
/*   Updated: 2017/11/26 00:10:56 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		**creatlinkmatrix(int numberofrooms)
{
	int		**matrix;
	size_t	index;

	matrix = (int **)malloc(sizeof(int *) * numberofrooms);
	while (matrix[index])
	{
		matrix[index] = (int *)malloc(sizeof(int) * numberofrooms);
		index++;
	}
	return (matrix);
}

static int		matrixpos(int *roompos, int roomno, size_t numofrooms);
{
	int index;

	index = 0;
	while (index < numofrooms)
	{
		if (roompos[index] == roomno)
			return (index);
		index++;
	}
	return (-1);
}

void	storelinks(char *line, struct room *rooms, int ** links, int *con)
{
	size_t	numofrooms;
	int		*roompos;
	int		room1;
	int		room2;
	size_t	index;

	index = 0;
	numofrooms = getnumberofrooms(rooms);
	if (*con == 6)
	{
		roompos = numberrooms(rooms, numofrooms);
		linkmatrix = createlinkmatrix(numofrooms);
	}
	room1 = matrixpos(roompos, ft_atoi(line), numofrooms);
	while (line[index] != '-')
		index++;
	room2 = matrixpos(roompos, ft_atoi(line + index + 1), numofrooms);
	linkmatrix[room1][room2] = 1;
	linkmatrix[room2][room1] = 1;
}
