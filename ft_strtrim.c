/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:56:55 by fleriche          #+#    #+#             */
/*   Updated: 2022/11/17 13:00:44 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	result_len(const char *str, const char *set, int *start)
{
	int	end;

	end = ft_strlen(str);
	while (str[*start] && ft_strchr(set, str[*start]))
		*start = *start + 1;
	while (end > *start && ft_strchr(set, str[end - 1]))
		end--;
	return (end - *start);
}

char	*ft_strtrim(const char *str, const char *set)
{
	char	*result;
	int		i;
	int		j;

	if (!str || !set)
		return (NULL);
	i = 0;
	j = result_len(str, set, &i);
	result = ft_substr(str, i, j);
	if (result == NULL)
		return (NULL);
	return (result);
}
