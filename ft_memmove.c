/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:33:20 by fleriche          #+#    #+#             */
/*   Updated: 2022/11/14 11:50:24 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*char_dst;
	unsigned char	*char_src;

	char_dst = ((unsigned char *)dst);
	char_src = ((unsigned char *)src);
	i = 0;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		while (i < len)
		{
			char_dst[len - 1 - i] = char_src[len - 1 - i];
			i++;
		}
	}
	else
	{
		while (i++ < len)
			char_dst[i - 1] = char_src[i - 1];
	}
	return (dst);
}
