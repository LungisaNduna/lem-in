/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gruntworker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 03:39:21 by lnduna            #+#    #+#             */
/*   Updated: 2017/11/28 16:37:15 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t	getnumberofroutes(path_t *routes)
{
	size_t counter;
	path_t temp;

	counter = 0;
	temp = routes;
	while (temp->next != NULL)
	{
		counter++;
		temp = temp->next;
	}
	return (counter);
}

static void		printmove(int roomno, int antnumber);
{
	ft_putchar('L');
	ft_putnbr(antnumber);
	ft_putchar('-');
	ft_putnbr(roomno);
	ft_putchar(' ');
}

static void		moveants(room_t *antfarm, path_t *stack, size_t x)
{
	size_t	index;
	room_t	temp;

	index = 0;
	while (index < x)
	{
		if (stack[index]->prev == NULL && stack[index]->ants[0] == 0)
		{
			stack[index] = getantfromfarm(antfarm);
			printmove(stack[index]->roomno, stack[index]->ants[0]);
		}
		else if (stack[index]->prev != NULL)
		{
			temp = stack[index]->prev;
			stack[index]->ants[0] = temp->ants[0];
			stack[index] = temp;
			printmove(stack[index]->roomno, stack[index]->ants[0])
		}
		index++;
	}
	putchar('\n');
	free (temp);
}

int		gruntworker(room_t *antfarm, path_t **routes)
{
	size_t	numofroutes;
	size_t	index;
	room_t	*roomstack;

	numofroutes = getnumberofroutes(routes);
	index = 0;
	if (!roomstack = (struct room *)malloc(sizeof(struct room) * numofroutes))
		return (-9);
	while (routes->next != NULL)
	{
		roomstack[index] = routes->tail;
		index++;
		routes = routes->next;
	}
	moveants(antfarm, roomstack, numofroutes);
	free(roomstack);
	return (1);
}
