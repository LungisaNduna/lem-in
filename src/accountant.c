/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accountant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:32:22 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/30 15:38:35 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*	************************************	*
 *	returns the total number of rooms 		*
 *	linked together in a line				*
 *	************************************	*/

int		count_rooms(t_room *antfarm)
{
	int	counter;

	counter = 0;
	while (antfarm)
	{
		antfarm = antfarm->next;
		counter++;
	}
	return (counter);
}

int		count_routes(char **route_matrix)
{
	size_t counter;

	counter = 0;
	while (route_matrix[counter] != NULL)
		counter++;
	return (counter);
}
