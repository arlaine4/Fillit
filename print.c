/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:29:25 by lyhamrou          #+#    #+#             */
/*   Updated: 2018/12/23 14:03:58 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_usage(char **bloc)
{
	int		i;

	i = 0;
	if (bloc && bloc[i])
		free(bloc[i++]);
	free(bloc);
	bloc = NULL;
	ft_putstr("usage : ./fillit file_name\n");
	exit(0);
}

int		ft_error(char **block)
{
	int		i;

	i = 0;
	ft_putstr("error\n");
	if (block && block[i])
		free(block[i++]);
	if (block)
		free(block);
	block = NULL;
	exit(0);
}

void	print_result(char **block)
{
	int	i;

	i = 0;
	while (block[i])
		ft_putendl(block[i++]);
}
