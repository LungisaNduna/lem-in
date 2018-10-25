/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_routes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:54:36 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/30 16:06:35 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

static void	remove_route(char **routes, size_t index)
{
	size_t	index_copy;

	ft_strdel(&routes[index]);
	index_copy = index + 1;
	while (routes[index_copy])
	{
		routes[index_copy - 1] = routes[index_copy];
		index_copy++;
	}
	routes[index_copy - 1] = NULL;
}

static void	order_routes_by_length(char **routes)
{
	char	*place_holder;
	size_t	index_o;
	size_t	index_i;

	index_o = 0;
	while (routes[index_o + 1])
	{
		index_i = index_o + 1;
		while (routes[index_i])
		{
			if (ft_strlen(routes[index_o]) > ft_strlen(routes[index_i]))
			{
				place_holder = routes[index_o];
				routes[index_o] = routes[index_i];
				routes[index_i] = place_holder;
			}
			index_i++;
		}
		index_o++;
	}
}

static void	remove_dead_end_routes(char **routes)
{
	size_t index;

	index = 0;
	while (routes[index])
	{
		if (routes[index][0] == '-')
			remove_route(routes, index);
		else
			index++;
	}
}

static void	remove_replica_choke_points(char **routes)
{
	int		rt;
	int		rm;
	int		l;

	rt = 0;
	while (routes[rt])
	{
		l = rt - 1;
		while (l >= 0 && l < rt)
		{
			rm = 2;
			while (routes[rt][rm + 1] != '\0')
			{
				if (ft_strchr(routes[l], routes[rt][rm]) && routes[rt][rm] != '-')
				{
					remove_route(routes, rt);
					rt--;
					break;
				}
				rm++;
			}
			l--;
		}
		rt++;
	}
}

t_map		*create_map(char **route_matrix, int num_of_rooms)
{
	t_map	*map;

	if (!route_matrix || !(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	remove_dead_end_routes(route_matrix);
	order_routes_by_length(route_matrix);
	remove_replica_choke_points(route_matrix);
	map->map = route_matrix;
	map->num_of_rooms = num_of_rooms;
	map->num_of_routes = ft_count_2dlines(route_matrix);
	return (map);
}
