/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnumberofrooms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:03:28 by lnduna            #+#    #+#             */
/*   Updated: 2017/11/28 18:03:32 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t   getnumberofrooms(room_t *rooms)
{
	int		numberofrooms;
	room_t	temp;

	numberofrooms = 0;
	temp = rooms
	while (temp->next != NULL)
	{
		numberofrooms++;
		temp = temp->next;
	}
	return (numberofrooms);
}
