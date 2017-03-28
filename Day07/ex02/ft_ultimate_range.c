/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:37:31 by thabdoul          #+#    #+#             */
/*   Updated: 2017/03/21 21:16:33 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;

	i = 0;
	if ((max - min) <= 0)
		return (0);
	if ((range = (int**)malloc(sizeof(int) * (max - min))) == NULL)
		return (0);
	while (min < max)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (i);
}
