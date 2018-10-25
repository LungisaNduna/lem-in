/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_things.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:25:38 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/30 15:49:28 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_rooms(t_room *rooms)
{
	ft_putendl("PRINTING ROOMS");
	while (rooms)
	{
		ft_putnbr(rooms->room_no);
		ft_putchar('\t');
		ft_putstr(rooms->room_name);
		ft_putstr(" at x = ");
		ft_putnbr(rooms->xpos);
		ft_putstr(" y = ");
		ft_putnbr(rooms->ypos);
		ft_putchar('\n');
		rooms = rooms->next;
	}
	ft_putendl("-----------------------------");
}

void	print_links(t_link *links)
{
	int index;
	int	index_inner;

	ft_putendl("PRINTING LINKS");
	index = 0;
	while (index < links->num_of_rooms)
	{
		ft_putnbr(index);
		ft_putstr("\t-> ");
		index_inner = 0;
		while (index_inner < links->num_of_rooms)
		{
			ft_putnbr(links->link_matrix[index][index_inner]);
			ft_putchar(' ');
			index_inner++;
		}
		ft_putchar('\n');
		index++;
	}
	ft_putendl("---------------------------------");
}

void	print_map(t_map *map)
{
	size_t	index;

	index = 0;
	ft_putendl("PRINTING MAP");
	ft_putstr("\twith ");
	ft_putnbr((int)(map->num_of_rooms));
	ft_putstr(" rooms\t");
	ft_putnbr((int)(map->num_of_routes));
	ft_putendl(" routes");
	while (map->map[index])
	{
		ft_putchar('\t');
		ft_putnbr((int)(index));
		ft_putstr("\t-> ");
		ft_putendl(map->map[index]);
		index++;
	}
	ft_putendl("-----------------------------------");
}

void	print_artifacts(t_room *rooms, t_link *links, t_map *map)
{
	if (rooms)
		print_rooms(rooms);
	if (links)
		print_links(links);
	if (map)
		print_map(map);
}
