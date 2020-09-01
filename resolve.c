/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:41:19 by arlaine           #+#    #+#             */
/*   Updated: 2018/12/20 15:00:35 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	last_tet(char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = 'A';
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] > c)
				c = map[i][j++];
			else
				j++;
		}
		i++;
	}
	return (c);
}

int		remove_tet(char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	c = last_tet(map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (1);
}

int		is_it_possible_to_put_bloc(char **map, char **bloc, int x, int y)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = NULL;
	i = 0;
	if ((tmp = take_part_of_map(map, bloc, x, y)) == NULL)
		return (0);
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j] != '\0' && bloc[i][j] != '\0')
		{
			if (bloc[i][j] != '.' && tmp[i][j] != '.')
			{
				free_pointer(tmp);
				return (0);
			}
			++j;
		}
		++i;
	}
	free_pointer(tmp);
	return (1);
}

int		placeable(char **bloc, char **map, int x, int y)
{
	int		i;
	int		j;
	int		pos;

	i = 0;
	if (is_it_possible_to_put_bloc(map, bloc, x, y) == 1)
	{
		while (bloc[i])
		{
			pos = 0;
			j = y;
			while (bloc[i][pos])
			{
				if (bloc[i][pos] == '.' && map[x + i][j] != '.')
					;
				else if (bloc[i][pos] != '.')
					map[x + i][j] = bloc[i][pos];
				j++;
				pos++;
			}
			i++;
		}
		return (1);
	}
	return (0);
}

int		solver2(char ***bloc, char **map, int i_tet)
{
	int		i;
	int		j;

	i = 0;
	if (i_tet == 0)
		return (1);
	while (ft_dim(map, 1) >= ft_dim(*bloc, 1) && map[i + ft_dim(*bloc, 1) - 1])
	{
		j = 0;
		while (map[i][j + ft_dim(*bloc, 0) - 1])
		{
			if (placeable(*bloc, map, i, j))
			{
				if (solver2(bloc + 1, map, i_tet - 1))
					return (1);
				remove_tet(map);
			}
			j++;
		}
		i++;
	}
	return (0);
}
