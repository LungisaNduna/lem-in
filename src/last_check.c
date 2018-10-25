/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 18:41:59 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/30 15:45:50 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	count_links(int **linkgraph, int num_of_rooms)
{
	int	index1;
	int	index2;
	int	link_counter;

	index1 = 0;
	link_counter = 0;
	while (index1 < num_of_rooms)
	{
		index2 = 0;
		while (index2 < num_of_rooms)
		{
			if (linkgraph[index1][index2])
				link_counter++;
			index2++;
		}
		index1++;
	}
	return (link_counter / 2);
}

static int	check_for_overlapping_rooms(t_room *antfarm)
{
	t_room *temp1;
	t_room *temp2;

	temp1 = antfarm;
	while (temp1->next)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->xpos == temp2->xpos && temp1->ypos == temp2->ypos)
				return (1);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (0);
}

static void	index_rooms_in_order(t_room *antfarm)
{
	t_room	*room;
	int		index;

	index = 0;
	room = antfarm;
	while (room)
	{
		room->room_no = index;
		room = room->next;
		index++;
	}
}

static int	no_links_to_end_or_start(t_link *links)
{
	int index;
	int total_links_to_start;
	int total_links_to_end;

	index = 0;
	total_links_to_start = 0;
	while (index < links->num_of_rooms)
	{
		total_links_to_start += links->link_matrix[0][index];
		index++;
	}
	index = 0;
	total_links_to_end = 0;
	while (index < links->num_of_rooms)
	{
		total_links_to_end += links->link_matrix[0][index];
		index++;
	}
	return (total_links_to_start < 0 && total_links_to_end < 0);
}

int			check_elements(t_room *antfarm, t_link *links)
{
	if (no_links_to_end_or_start(links))
		return (-8);
	else if (links->num_of_rooms < 1)
		return (-5);
	else if (count_links(links->link_matrix, links->num_of_rooms) == 0)
		return (-6);
	else if (check_for_overlapping_rooms(antfarm))
	{
		ft_putstr("Non-fatal Error : ");
		ft_putendl("two rooms are occupying the same space.\n");
	}
	index_rooms_in_order(antfarm);
	return (0);
}
