/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:55:59 by fleriche          #+#    #+#             */
/*   Updated: 2022/11/22 10:21:25 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsplitdup(char *src, int min, int max)
{
	char	*str;
	int		i;

	i = max - min;
	str = malloc(sizeof(char) * i + 1);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (min < max)
	{
		str[i] = src[min];
		i++;
		min++;
	}
	str[i] = '\0';
	return (str);
}

int	ischarset(char c, char charset)
{
	if (charset != '\0')
	{
		if (c == charset)
			return (1);
	}
	return (0);
}

int	count_word(char *str, char charset)
{
	int		i;
	int		mot;

	i = 0;
	mot = 0;
	while (str[i])
	{
		while (ischarset(str[i], charset) && str[i])
			i++;
		if (str[i])
			mot++;
		while (!ischarset(str[i], charset) && str[i])
			i++;
	}
	return (mot);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_word((char *)s, c) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (ischarset(s[i], c) && s[i])
			i++;
		start = i;
		while (!ischarset(s[i], c) && s[i])
			i++;
		if (start != i)
			tab[j++] = ft_strsplitdup((char *)s, start, i);
	}
	tab[j] = 0;
	return (tab);
}
