/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enders_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:31:16 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/30 15:39:09 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*	************************************	*
 *	frees a set of rooms linked together	*
 *	************************************	*/

static void	free_rooms(t_room *rooms)
{
	t_room *trash;

	if (rooms)
	{
		trash = rooms;
		rooms = rooms->next;
		free(trash->room_name);
		free(trash->ants);
		free(trash);
	}
}

/*	********************************************	*
 *	free any structure if and only if it exists.	*
 *	********************************************	*/

static void	free_everything(t_room *antfarm, t_link *links, t_map *map)
{
	int		index;

	if (antfarm)
		free_rooms(antfarm);
	if (links)
	{
		if (links->link_matrix)
		{
			index = links->num_of_rooms;
			while (index >= 0)
			{
				free(links->link_matrix[index]);
				index--;
			}
			free(links->link_matrix);
		}
		free(links);
	}
	if (map)
	{
		if (map->map)
			ft_freestrarr(map->map);
		free(map);
	}	
}

/*	********************************************	*
 *	if there is no error number nothing will be 	*
 *	printed else it will print the error message	*
 *	corresponding to the error no					*
 *	********************************************	*/
static void	printerror(int errorno)
{
	if (errorno < 0)
		ft_putstr("Error: ");
	if (errorno == -1)
		ft_putendl("Could not open the file");
	else if (errorno == -2)
		ft_putendl("Invalid file format: multiple start commands");
	else if (errorno == -3)
		ft_putendl("Invalid file format: multiple end commands");
	else if (errorno == -4)
		ft_putendl("Invalid file format: no ants given in the document");
	else if (errorno == -5)
		ft_putendl("Invalid file format: no rooms given in the document");
	else if (errorno == -6)
		ft_putendl("Invalid file format: no links given in the document");
	else if (errorno == -10)
		ft_putendl("Invalid file format: What are you going for?");
	else if (errorno == -8)
		ft_putendl("Invalid map : no routes found");
	else if (errorno == -9)
		ft_putendl("Whoops, could not finish the program");
}

/*	************************************************	*
 *	if there is an error it will be printed before		*
 *	freeing all our structures and information we 		*
 *	have saved											*
 *	************************************************	*/

int  		endprog(int errorno, t_room *rooms, t_link *links, t_map *map)
{
	printerror(errorno);
	free_everything(rooms, links, map);
	return (0);
}
