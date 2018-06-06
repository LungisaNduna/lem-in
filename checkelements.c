/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkelements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:46:27 by lnduna            #+#    #+#             */
/*   Updated: 2017/11/28 16:26:31 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_no_of_links(int no_of_rooms, int **linkgraph)
{
	size_t index;
	size_t index2;
	size_t counter;

	index = 0;
	counter = 0;
	while (index < no_of_rooms)
	{
		index2 = 0;
		while (index2 < no_of_rooms)
		{
			if (linkgraph[index][index2] == 1)
				counter++;
			index2++;
		}
		index++;
	}
	return (counter);
}

static int	nooverlapping(room_t *antfarm)
{
	room_t	*temp0;
	room_t	*temp1;

	temp0 = antfarm;
	while (temp0->next != NULL)
	{
		temp1 = antfarm;
		while (temp1->next != NULL)
		{
			if (temp1->ypos == temp0->ypos && temp1->xpos == temp0->xpos)
				return (0);
			temp1 = temp1->next;
		}
		temp0 = temp0->next;
	}
	return (1);
}

int			checkelements(room_t *antfarm, int **linkgraph)
{
	size_t no_of_rooms;
	size_t index;
	size_t index2;

	no_of_rooms = 0;
	index = 0;
	if (no_of_rooms = getnumberofrooms(antfarm) == 0)
		return (-5);
	no_of_links = check_no_of_links(no_of_rooms, linkgraph);
	if (no_of_links = 0)
		return (-6);
	if (nooverlapping(antfarm) == 0)
		return (-1);
	return (0);
}
