/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_blocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:19:26 by lyhamrou          #+#    #+#             */
/*   Updated: 2018/12/19 15:37:04 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		***put_letter(char ***block, int i, int j, int k)
{
	char c;

	c = 'A';
	while (block[i])
	{
		j = 0;
		while (block[i][j])
		{
			k = 0;
			while (block[i][j][k])
			{
				if (block[i][j][k] == '#')
					block[i][j][k] = c;
				++k;
			}
			++j;
		}
		++c;
		++i;
	}
	return (block);
}

char		***create_3d_block(char **block)
{
	char	***block3d;
	int		i;

	i = 0;
	block3d = NULL;
	if (!(block3d = (char ***)malloc(sizeof(char **) * (unsigned long)
					nb_of_block(block) + 1)))
	{
		free_pointer(block);
		return (NULL);
	}
	while (block[i])
	{
		if (!(block3d[i] = ft_strsplit(block[i], '\n')))
			return (free_other_pointer_n(block3d, block));
		++i;
	}
	block3d[i] = NULL;
	free_pointer(block);
	return (block3d);
}

char		***cut_columns(char ***block, int i, int j, int k)
{
	unsigned int		cpt;
	unsigned int		pos;
	char				*tmp;

	pos = 0;
	tmp = NULL;
	while (block[i])
	{
		cpt = 0;
		j = 0;
		k = 0;
		while (block[i][j][k])
		{
			if (block[i][0][k] == '#' || block[i][1][k] == '#'
					|| block[i][2][k] == '#' || block[i][3][k] == '#')
			{
				pos = (unsigned int)k;
				++cpt;
			}
			++k;
		}
		block[i] = rewrite_new_columns(block[i], cpt, pos);
		++i;
	}
	return (block);
}

char		***cut_lines(char ***block, int i, int j)
{
	block = delete_first_line(block);
	while (block[++i])
	{
		j = 3;
		while (!block[i][j])
			j--;
		while (!(ft_strchr(block[i][j], '#')))
		{
			free(block[i][j]);
			block[i][j--] = NULL;
		}
	}
	return (block);
}

char		***cut_blocks(char **block)
{
	char	***block3d;

	block3d = NULL;
	block3d = create_3d_block(block);
	block3d = cut_columns(block3d, 0, 0, 0);
	block3d = cut_lines(block3d, -1, 0);
	block3d = put_letter(block3d, 0, 0, 0);
	return (block3d);
}
