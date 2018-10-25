/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:53:25 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/30 15:44:03 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*	********************************************	*
 *	find the room that corresponds with the room	*
 *	name or index.									*
 *	********************************************	*/

t_room	*return_room_by_name(t_room *room, char *room_to_find)
{
	while (room)
	{
		if (ft_strequ(room->room_name, room_to_find))
			return (room);
		room = room->next;
	}
	return (NULL);
}

t_room	*return_room_by_index(t_room *room, int room_to_find)
{
	while (room)
	{
		if (room->room_no == room_to_find)
			return (room);
		room = room->next;
	}
	return (NULL);
}

/*	************************************************	*
 *	check that the room by name or number and return	*
 *	return a 1 if it exists 0 if it doesn't				*
 *	************************************************	*/

int		check_room_by_name(t_room *room, char *room_to_find)
{
	while (room)
	{
		if (ft_strequ(room->room_name, room_to_find))
		{
			free(room_to_find);
			return (1);
		}
		room = room->next;
	}
	free(room_to_find);
	return (0);
}

int		check_room_by_index(t_room *room, int room_to_find)
{
	while (room)
	{
		if (room->room_no == room_to_find)
			return (1);
		room = room->next;
	}
	return (0);
}

char	*get_room_name_by_index(t_room *antfarm, int room_index)
{
	while (antfarm)
	{
		if (antfarm->room_no == room_index)
			return (antfarm->room_name);
		antfarm = antfarm->next;
	}
	return (NULL);
}
