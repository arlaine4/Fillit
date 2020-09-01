/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 20:17:22 by lyhamrou          #+#    #+#             */
/*   Updated: 2018/12/19 16:25:23 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_pointer(char **bloc)
{
	int		i;

	i = 0;
	while (bloc[i])
		free(bloc[i++]);
	free(bloc);
	bloc = NULL;
}

char	**free_pointer_n(char **bloc)
{
	int		i;

	i = 0;
	if (bloc)
	{
		while (bloc[i])
			free(bloc[i++]);
		free(bloc);
		bloc = NULL;
	}
	return (NULL);
}

void	free_other_pointer(char ***bloc, char **tet)
{
	int		i;
	int		j;

	i = 0;
	while (bloc[i])
	{
		j = 0;
		while (bloc[i][j])
			free(bloc[i][j++]);
		free(bloc[i++]);
	}
	free(bloc);
	i = 0;
	while (tet[i])
		free(tet[i++]);
	free(tet);
	tet = NULL;
	bloc = NULL;
}

char	***free_other_pointer_n(char ***bloc, char **tet)
{
	int		i;
	int		j;

	i = 0;
	if (bloc)
	{
		while (bloc[i])
		{
			j = 0;
			while (bloc[i][j])
				free(bloc[i][j++]);
			free(bloc[i++]);
		}
	}
	free(bloc);
	i = 0;
	if (tet)
	{
		while (tet[i])
			free(tet[i++]);
		free(tet);
	}
	bloc = NULL;
	tet = NULL;
	return (NULL);
}
