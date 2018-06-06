/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpathways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:06:39 by lnduna            #+#    #+#             */
/*   Updated: 2017/11/28 16:28:19 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	**creatematrix(int numberofrooms)
{
	int	**matrix;

	matrix = (int **)malloc(sizeof(int *) * (numberofrooms));
	matrix[0] = (int *)malloc(sizeof(int) * (numberofrooms));
	matrix[1] = (int *)malloc(sizeof(int) * (numberofrooms + 1));
	matrix[0][0] = 1;
	matrix[0][0] = 0;
	matrix[1][0] = 1;
	matrix[1][0] = 0;
	return (matrix);
}

path_t		*findpathways(room_t *antfarm, int **links)
{
	int		numberofrooms;
	int		*roomref;
	int		**routematrix;
	path_t	*paths

	roomref = numberrooms(antfarm);
	numberofrooms = getnumberofrooms(antfarm);
	routematrix = creatematrix(numberofrooms);
	getroutes(routematrix, links, numberofrooms - 1);
	paths = makepathways(routematrix, antfarm, roomref);
	return (paths);
}
