/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:41:14 by lnduna            #+#    #+#             */
/*   Updated: 2017/11/28 16:01:16 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft/libft.h"
#include <stdlib.h>

typedef struct room
{
	int			*roomno;
	int			*ants;
	int			xpos;
	int			ypos;
	struct room	*next;
	struct room	*prev;
} room_t;

typedef struct path
{
	struct room	*head;
	struct room	*tail;
	struct path	*next;
} path_t;
