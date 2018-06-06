/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storeroom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:41:48 by lnduna            #+#    #+#             */
/*   Updated: 2017/11/28 16:12:37 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	fillinfo(struct room temp, char *line, int con)
{
	size_t index;

	index = 0;
	temp->roomno = ft_atoi(line);
	while (isspace(line[index]) == 0)
		index++;
	temp->xpos = ft_atoi(line + index);
	index++;
	while (isspace(line[index]) == 0)
		index++;
	temp->ypos = ft_atoi(line + index);
	if (con == 3 || con == 31)
		temp->dest = 1;
}

static void	linkup(struct room temp, struct room antfarm, int con)
{
	while (antfarm->next != NULL)
		antfarm = antfarm->next;
	if (con == 6 || con == 5)
	{
		temp->prev = antfarm->prev;
		antfarm->prev = temp;
		temp->next = antfarm;
	}
	else
	{
		antfarm->next = temp;
		temp->prev = antfarm;
		temp->next = NULL;
	}
}

void		storeroom(char *line, struct room *antfarm, int *con)
{
	struct room	*temp;

	if (*con == 2 || *con == 21)
		fillinfo(antfarm, line, *con);
	else
	{
		temp = (room_t *)malloc(sizeof(room_t));
		fillinfo(temp, line, *con);
		temp-ants = (int *)malloc(sizeof(int));
		linkup(temp, antfarm);
	}
}
