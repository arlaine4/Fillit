/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:58:05 by arlaine           #+#    #+#             */
/*   Updated: 2018/12/23 13:50:35 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_usage(char **bloc);
char	**read_tetriminos(const int fd, int i);
int		check_char_of_map(char *block);
int		tetriminos_is_valid(char *block, int k);
int		ft_error(char **block);
int		nb_of_block(char **block);
char	***cut_blocks(char **block);
char	***create_3d_block(char **block);
char	***cut_columns(char ***block, int i, int j, int k);
char	***cut_lines(char ***block, int i, int j);
char	***put_letter(char ***block, int i, int j, int k);
int		solver2(char ***block, char **map, int i_tet);
int		get_map_size(int i);
char	**create_map(int cote);
int		remove_tet(char **map);
int		ft_dim(char **block, int i);
int		is_it_possible_to_put_bloc(char **map, char **bloc, int x, int y);
int		placeable(char **bloc, char **map, int x, int y);
char	last_tet(char **map);
void	print_result(char **map);
void	ft_loop_clean(char **block, char ***block3d, int i, int fd);
void	free_pointer(char **bloc);
char	**free_pointer_n(char **bloc);
void	free_other_pointer(char ***block, char **bloc);
char	***free_other_pointer_n(char ***block, char **bloc);
char	**take_part_of_map(char **map, char **bloc, int x, int y);
char	***delete_first_line(char ***bloc);
char	**rewrite_new_columns(char **bloc, int cpt, int pos);
size_t	ft_strlen(char const *s);
void	ft_putstr(char const *s);
char	*ft_strchr(char const *s, int c);
void	*ft_memchr(void const *s, int c, size_t n);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_strsplit(char const *s, char c);
void	ft_strdel(char **as);
char	*ft_strnew(size_t size);
void	ft_putendl(char const *s);
char	*ft_strdup(char const *str);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strcpy(char *dest, char const *src);

#endif
