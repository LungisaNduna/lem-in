/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numberroom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:03:11 by lnduna            #+#    #+#             */
/*   Updated: 2017/11/28 18:03:13 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	*numberrooms(room_t *rooms, size_t numberofrooms)
{
	int		*roompos;
	size_t	index;
	room_t	temp;

	temp = rooms;
	index = 0;
	roompos = (int *)malloc(sizeof(int) * numberofrooms);
	while (temp->next != NULL)
	{
		roompos[index] = temp->roomno;
		index++;
		temp = temp->next;
	}
	return (roompos);
}

