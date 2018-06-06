#include "lem_in.h"

static size_t	getshortestroute(int **matrix, size_t numofrooms)
{
	size_t index;
	size_t r_index;

	index = 0;
	r_index = 0;
	while (matrix[index] != NULL && index < numofrooms)
	{
		if (0 < matrix[index][0] &&(matrix[index][0] < r_index ||
					r_index == 0))
			r_index = index;
		index++;
	}
	return (r_index);
}

static void	addroom(room_t *rooms, int roomno, room_t *antfarm)
{
	room_t *tempaf;
	room_t *tempr;
	room_t *tempafnext;

	tempaf = antfarm;
	tempafnext = tempaf->next;
	tempr = rooms;
	while (tempr->next != NULL)
		tempr = tempr->next;
	while (tempafnext->roomno != roomno)
	{
		tempaf = tempafnext;
		tempafnext = tempaf->next
	}
	tempaf->next = tempafnext->next;
	tempr->next = tempafnext;
	tempafnext->next = NULL;
}

static room_t	addlastroom(room_t *antfarm, int roomno)
{
	room_t *dest
	room_t *destcpy;

	destcpy = (room_t)malloc(sizeof(room_t));
	dest = findroom(roomno, antfarm);
	destcpy->roomno = dest->roomno;
	destcpy->ants = (int *)malloc(sizeof(int));
	return (destcpy);
}

static room_t	*fillrooms(int *route, room_t antfarm, int * ref, size_t end)
{
	size_t	index;
	room_t	*rooms;

	index = 1;
	rooms = addlastroom(antfarm, ref[end]);
	while (route[index] != end)
		index++;
	while (route[index] != 0)
	{
		addroom(rooms,ref[route[index]] antfarm);
		index--;
	}
	return (rooms);
}

path_t		*makepathways(int **matrix, room_t *antfarm, int *roomref)
{
	size_t	index;
	size_t	numofrooms;
	path_t	*route;
	path_t	temp;

	route = NULL;
	numofrooms = getnumberofrooms(antfarm);
	while (index = getshortestroute(matrix, numofrooms) != 0)
	{
		temp = (path_t *)malloc(sizeof(path_t));
		temp->tail = fillrooms(matrix[index], antfarm, roomref, numofrooms - 1);
		
	}
	return (route);
}
