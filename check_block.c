/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:11:23 by lyhamrou          #+#    #+#             */
/*   Updated: 2018/12/23 13:50:47 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		nb_of_block(char **block)
{
	int i;

	i = 0;
	while (block[i])
		i++;
	if (i > 26)
		ft_error(block);
	return (i);
}

int		tetriminos_is_valid(char *block, int k)
{
	int		count;
	int		connec;

	count = 0;
	k = 0;
	connec = 0;
	while (block[k])
	{
		if (block[k] == '#')
		{
			count++;
			if (block[k - 1] == '#' && block[k - 1])
				connec++;
			if (block[k + 1] == '#' && block[k + 1])
				connec++;
			if (block[k - 5] == '#' && block[k - 5])
				connec++;
			if (block[k + 5] == '#' && block[k + 5])
				connec++;
		}
		k++;
	}
	if (count != 4 || (connec != 6 && connec != 8))
		return (0);
	return (1);
}

int		check_char_of_map(char *block)
{
	int		i;

	i = 0;
	if (block[20] == '.' || (ft_strlen(block) != 21 && ft_strlen(block) != 20))
		return (0);
	if ((block[4] != '\n' || block[9] != '\n' || block[14] != '\n'
				|| block[19] != '\n'))
		return (0);
	while (block[i])
	{
		if (block[i] != '.' && block[i] != '#' && block[i] != '\n')
			return (0);
		i++;
	}
	return (tetriminos_is_valid(block, 0) ? 1 : 0);
}

char	**read_tetriminos(int const fd, int i)
{
	char	*buffer;
	int		ret;
	char	**block;

	buffer = NULL;
	if (!(block = (char **)malloc(sizeof(char *) * 27)))
		return (NULL);
	*block = NULL;
	if (!(buffer = (char *)ft_memalloc(22)))
		return (NULL);
	while ((ret = (int)read(fd, buffer, 21)) > 0)
	{
		buffer[ret] = '\0';
		block[i] = ft_strdup(buffer);
		if (check_char_of_map(block[i]) == 0)
			ft_error(block);
		i++;
	}
	ft_strdel(&buffer);
	if (ret == -1 || !(*block) || (ret == 0 && block[i - 1][20] == '\n'))
		ft_error(block);
	block[i] = NULL;
	return (nb_of_block(block) <= 26 ? block : NULL);
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char	**block;
	char	***block3d;

	block = NULL;
	block3d = NULL;
	if ((fd = open(av[1], O_RDONLY)) < 0 && ac == 2)
		ft_error(block);
	if (ac != 2)
		ft_usage(block);
	else
	{
		block = read_tetriminos((const int)fd, 0);
		i = nb_of_block(block);
		if (!block)
			ft_error(block);
		block3d = cut_blocks(block);
		close(fd);
		fd = get_map_size(i);
		block = create_map(fd);
		ft_loop_clean(block, block3d, i, fd);
	}
	return (0);
}
