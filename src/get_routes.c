/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_routes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:23:52 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/30 15:59:56 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static char	*close_off_route(char *route, int end_room)
{
	char	*finished_route;
	char	*trash;
	char	*end_room_as_str;

	trash = ft_itoa(end_room);
	end_room_as_str = ft_strjoin("-", trash);
	finished_route = ft_strjoin(route, end_room_as_str);
	finished_route[0] = '+';
	free(route);
	free(trash);
	free(end_room_as_str);
	return (finished_route);
}

static char	*add_room(char *route, int room_no, size_t *replicate)
{
	char	*updated_route;
	char	*trash;
	char	*new_room_no_as_str;
	size_t	replicate_room;

	replicate_room = *replicate;
	if (replicate_room == 1)
	{
		route = ft_strsub(route, 0, ft_strlen(route) - 2);
	}
	else
		replicate_room = 1;
	trash = ft_itoa(room_no);
	new_room_no_as_str = ft_strjoin("-", trash);
	updated_route = ft_strjoin(route, new_room_no_as_str);
	free(route);
	free(new_room_no_as_str);
	*replicate = replicate_room;
	return (updated_route);
}

static int	already_used(char *route, int room, int end_room)
{
	size_t index_rooms;

	end_room++;
	index_rooms = 0;
	while (route[index_rooms])
	{
		if (route[index_rooms] == room + 48)
			return (1);
		index_rooms++;
	}
	return (0);
}

static void	update_route_matrix(char **r_m, size_t cur, t_link *links)
{
	int		l_ind;
	size_t	rep;
	int		last_room;

	rep = 0;
	last_room = (ft_strrchr(r_m[cur], '-')) ?
		ft_atoi(ft_strrchr(r_m[cur], '-')) * -1 : ft_atoi(r_m[cur]);
	l_ind = links->num_of_rooms - 1;
	if (links->link_matrix[last_room][l_ind])
		r_m[cur] = close_off_route(r_m[cur], l_ind);
	else
	{
		while (l_ind >= 0)
		{
			if (links->link_matrix[last_room][l_ind] == 1 && !rep &&
					!already_used(r_m[cur], l_ind, links->num_of_rooms - 1))
				r_m[cur] = add_room(r_m[cur], l_ind, &rep);
			else if (links->link_matrix[last_room][l_ind] == 1 && rep &&
					count_routes(r_m) < links->num_of_rooms &&
					!already_used(r_m[cur], l_ind, links->num_of_rooms))
				r_m[count_routes(r_m)] = add_room(r_m[cur], l_ind, &rep);
			l_ind--;
		}
	}
	r_m[cur][0] = (rep == 0 && r_m[cur][0] != '+') ? '-' : r_m[cur][0];
}

t_map		*find_routes(t_link *links)
{
	char	**route_matrix;
	size_t	index;
	size_t	num_of_routes;
	int		finished;

	if (!(route_matrix = ft_malloc_2d_char(ft_factorial(links->num_of_rooms))))
		return (NULL);
	route_matrix[0] = ft_strdup(" 0");
	finished = 0;
	while (!finished)
	{
		finished = 1;
		index = 0;
		num_of_routes = count_routes(route_matrix);
		while (route_matrix[index] && index < num_of_routes)
		{
			if (route_matrix[index][0] == ' ')
				update_route_matrix(route_matrix, index, links);
			if (route_matrix[index][0] == ' ')
				finished = 0;
			index++;
		}
	}
	return (create_map(route_matrix, links->num_of_rooms));
}
