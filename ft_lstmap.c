/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:30:08 by fleriche          #+#    #+#             */
/*   Updated: 2022/11/18 16:23:48 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tamp;

	if (!f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		tamp = ft_lstnew((*f)(lst->content));
		if (tamp)
		{
			ft_lstadd_back(&result, tamp);
			lst = lst->next;
		}
		else
			ft_lstclear(&result, del);
	}
	return (result);
}
