/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <lyhamrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:14:49 by lyhamrou          #+#    #+#             */
/*   Updated: 2018/12/18 17:40:42 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned long	words(char const *s, char c)
{
	unsigned long	i;
	unsigned long	cpt;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c)
			cpt++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (cpt);
}

static unsigned int		letter(char const *s, unsigned int start, char c)
{
	unsigned int	i;

	i = 0;
	while (s[start] != c && s[start])
	{
		start++;
		i++;
	}
	return (i);
}

char					**ft_strsplit(char const *s, char c)
{
	char			**wds;
	unsigned int	i;
	unsigned int	x;

	i = 0;
	x = 0;
	if (!s || !c || !(wds = (char **)malloc(sizeof(char *) * words(s, c) + 1)))
		return (NULL);
	while (s[x])
	{
		while (s[x] == c && s[x])
			x++;
		if (s[x])
		{
			if (!(wds[i] = ft_strsub(s, x, letter(s, x, c))))
				return (free_pointer_n(wds));
			while (s[x] != c && s[x])
				x++;
			i++;
		}
	}
	wds[i] = NULL;
	return (wds);
}
