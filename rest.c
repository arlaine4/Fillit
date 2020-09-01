/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:16:15 by lyhamrou          #+#    #+#             */
/*   Updated: 2018/12/23 14:06:22 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**take_part_of_map(char **map, char **bloc, int x, int y)
{
	char	**tmp;
	int		i;

	i = 0;
	if (!(tmp = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	while (bloc[i])
	{
		tmp[i] = ft_strsub(map[x++], (unsigned int)y, ft_strlen(bloc[i]));
		++i;
	}
	tmp[i] = NULL;
	return (tmp);
}

char	***delete_first_line(char ***bloc)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (bloc[i])
	{
		while (ft_strchr(bloc[i][0], '#') == NULL)
		{
			tmp = bloc[i][0];
			bloc[i][0] = bloc[i][1];
			bloc[i][1] = bloc[i][2];
			bloc[i][2] = bloc[i][3];
			bloc[i][3] = NULL;
			free(tmp);
		}
		++i;
	}
	return (bloc);
}

void	ft_loop_clean(char **block, char ***block3d, int i, int fd)
{
	while (!(solver2(block3d, block, i)))
	{
		free_pointer(block);
		block = create_map(++fd);
	}
	print_result(block);
	free_other_pointer(block3d, block);
}

char	**rewrite_new_columns(char **bloc, int cpt, int pos)
{
	char	*tmp;
	int		j;

	j = -1;
	tmp = NULL;
	while (bloc[++j])
	{
		tmp = bloc[j];
		bloc[j] = ft_strsub(tmp, pos - cpt + 1, cpt);
		free(tmp);
	}
	return (bloc);
}
