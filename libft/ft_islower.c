/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:02:57 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/19 17:04:42 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_islower(int c)
{
	if (97 <= c && c <= 122)
		return (1);
	return (0);
}
