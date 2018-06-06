/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storeants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:41:36 by lnduna            #+#    #+#             */
/*   Updated: 2017/11/28 16:05:47 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	storeants(char *line, struct room *antfarm, int *con)
{
	int no_of_ants;
	int antnamer;

	if (*con == 0)
		*con = 1;
	no_of_ants = ft_atoi(line);
	antnamer = 1;
	antfarm->ants = (int *)malloc(sizeof(int) * no_of_ants);
	while (antnamer <= no_of_ants)
	{
		ants[antnamer - 1] = antnamer;
		antnamer++;
	}
}
