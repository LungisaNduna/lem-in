/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 16:33:41 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/30 16:09:03 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_factorial(int n)
{
	int returnvalue;

	returnvalue = 0;
	while (n >= 0)
	{
		returnvalue += n;
		n--;
	}
	return (returnvalue);
}
