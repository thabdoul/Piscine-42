/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:02:42 by thabdoul          #+#    #+#             */
/*   Updated: 2017/03/21 21:17:03 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		maxilen;
	int		len;
	char	*str;

	maxilen = 0;
	i = 1;
	while (i != argc)
	{
		maxilen = maxilen + ft_strlen(argv[i]);
		i++;
	}
	str = (char*)malloc(sizeof(char) * (maxilen) + 1);
	i = 1;
	while (i < argc)
	{
		ft_strcat(str, argv[i]);
		if (i < argc - 1)
			ft_strcat(str, "\n");
		i++;
	}
	len = ft_strlen(str);
	str[len] = '\0';
	printf("%s", str);
	return (str);
}
