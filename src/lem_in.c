/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:11:27 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/30 15:46:01 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	make_structures(t_room **af_add, t_link **l_add)
{
	t_room	*antfarm;
	t_link	*links;

	if (!(antfarm = (t_room *)malloc(sizeof(t_room))))
		return (0);
	else if (!(links = (t_link *)malloc(sizeof(t_room))))
		return (0);
	antfarm->ants = NULL;
	antfarm->next = NULL;
	links->link_matrix = NULL;
	*af_add = antfarm;
	*l_add = links;
	return (1);
}

int         main(void)
{
	int		errorno;
	t_link	*links;
	t_room	*antfarm;
	t_map	*map;

	errorno = 0;
	map = NULL;
	if (!(make_structures(&antfarm, &links)))
		return (endprog(-9, antfarm, links, map));
	if ((errorno = read_and_store(antfarm, links)) < 0)
		return (endprog(errorno, antfarm, links, map));
	if ((errorno = check_elements(antfarm, links)) < 0)
		return (endprog(errorno, antfarm, links, map));
	if (!(map = find_routes(links)))
		return (endprog(-9, antfarm, links, map));
	if (map->num_of_routes == 0)
		return (endprog(-8, antfarm, links, map));
	else
		move_ants(antfarm, map->map[0]);
	return (endprog(errorno, antfarm, links, map));
}
