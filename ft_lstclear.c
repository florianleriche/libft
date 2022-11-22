/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:29:58 by fleriche          #+#    #+#             */
/*   Updated: 2022/11/18 16:22:51 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tamp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tamp = *lst;
		ft_lstdelone(*lst, del);
		*lst = tamp->next;
	}
	lst = NULL;
}
