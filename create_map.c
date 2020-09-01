/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:57:29 by arlaine           #+#    #+#             */
/*   Updated: 2018/12/20 14:23:56 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_dim(char **block, int i)
{
	int		j;

	j = 0;
	if (i == 1)
	{
		while (block[j])
			j++;
		return (j);
	}
	else if (i == 0)
	{
		while (block[i][j])
			j++;
		return (j);
	}
	return (0);
}

char	**create_map(int cote)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char **) * (unsigned long)cote + 1)))
		return (NULL);
	while (i < cote)
	{
		j = 0;
		if (!(map[i] = (char *)malloc(sizeof(char*) * (unsigned long)cote + 1)))
			return (NULL);
		while (j < cote)
			map[i][j++] = '.';
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

int		get_map_size(int nb_of_block)
{
	int		cote;

	cote = 2;
	while (cote * cote < nb_of_block * 4)
		cote++;
	return (cote);
}
