/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:34:21 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/30 15:49:03 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		store_ants(char *line, t_room *antfarm, int *con)
{
	int	no_of_ants;
	int	branding_iron;

	*con = 1;
	no_of_ants = ft_atoi(line);
	branding_iron = 1;
	antfarm->ants = ft_strnew(no_of_ants);
	while (branding_iron <= no_of_ants)
	{
		antfarm->ants[branding_iron - 1] = branding_iron + 48;
		branding_iron++;
	}
}

static int	get_room_index_by_name(t_room *rooms, char *line)
{
	int		index;
	char	*room_name;
	int		room_index;

	index = 0;
	room_index = 0;
	while (line[index] && line[index] != '-' && line[index] != ' ')
		index++;
	room_name = ft_strsub(line, 0, index);
	while (rooms && !ft_strequ(room_name, rooms->room_name))
	{
		room_index++;
		rooms = rooms->next;
	}
	ft_strdel(&room_name);
	return (room_index);
}

void		store_link(char *line, t_room *af, t_link *lnks, int *con)
{
	int		room1;
	int		room2;
	size_t	index;

	index = 0;
	if (*con == 6)
	{
		*con = 7;
		lnks->num_of_rooms = count_rooms(af);
		lnks->link_matrix = ft_create_int_matrix(lnks->num_of_rooms);
	}
	room1 = get_room_index_by_name(af, line);
	while (line[index] != '-')
		index++;
	room2 = get_room_index_by_name(af, line + index + 1);
	lnks->link_matrix[room1][room2] = 1;
	lnks->link_matrix[room2][room1] = 1;
}

static void	fill_info(t_room *room, char *line, int clear_ants)
{
	size_t index;

	index = 0;
	while (!ft_isspace(line[index]))
		index++;
	room->room_name = ft_strsub(line, 0, index);
	room->room_no = 0;
	room->xpos = ft_atoi(line + index);
	index++;
	while (ft_isspace(line[index]) == 0)
		index++;
	room->ypos = ft_atoi(line + index);
	if (clear_ants)
		room->ants = ft_strdup("-");
	room->next = NULL;
}

void		store_room(char *line, t_room *antfarm, int *con)
{
	t_room *temp;

	if (*con == 2 || *con == 21)
	{
		fill_info(antfarm, line, 0);
		*con = (*con == 2) ? 4 : 6;
	}
	else
	{
		temp = (t_room *)malloc(sizeof(t_room));
		fill_info(temp, line, 1);
		if (*con == 31 || *con == 3)
		{
			while (antfarm->next)
				antfarm = antfarm->next;
			antfarm->next = temp;
			*con = (*con == 3) ? 5 : 6;
		}
		else
		{
			temp->next = antfarm->next;
			antfarm->next = temp;
		}
	}
}
