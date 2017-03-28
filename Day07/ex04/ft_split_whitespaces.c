/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:50:53 by thabdoul          #+#    #+#             */
/*   Updated: 2017/03/21 18:32:31 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_words_count(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		count++;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == '\n')
		{
			i++;
			count++;
		}
		i++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int		i;

	i = 0;
	while (src[i] != '\0' && n > 0)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	while (n > 0)
	{
		dest[i] = '\0';
		i++;
		n--;
	}
	return (dest);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	tab = (char **)malloc(sizeof(char*) * (ft_words_count(str) + 1));
	while (str[i] != '\0')
	{
		j = i;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			i++;
			j++;
		}
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		tab[k] = (char*)malloc(sizeof(char) * (i - j + 1));
		ft_strncpy(tab[k], str + j, i - j);
		k++;
	}
	tab[k] = 0;
	return (tab);
}
