/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <lyhamrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:06:00 by lyhamrou          #+#    #+#             */
/*   Updated: 2018/12/21 00:13:14 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*cpy;

	cpy = (char *)s;
	while (n > 0)
	{
		*cpy++ = (unsigned char)c;
		n--;
	}
	return (s);
}
