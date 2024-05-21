/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:25:43 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/25 16:51:35 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*tmp;

	if (lst == NULL || del == NULL)
	{
		return ;
	}
	aux = *lst;
	while (aux)
	{
		tmp = aux -> next;
		(*del)(aux -> content);
		free(aux);
		aux = tmp;
	}
	*lst = NULL;
}

/*int     main()
{
        t_list  *root;
        t_list  *elem1;
        t_list  *elem2;
        t_list  *elem3;
        t_list  *aux;

        root = ft_lstnew(ft_strdup("Content do root"));
        elem1 = ft_lstnew(ft_strdup("Content do elem1"));
        elem2 = ft_lstnew(ft_strdup("Content do elem2"));
        elem3 = ft_lstnew(ft_strdup("Content do elem3"));
        root->next = elem1;
        elem1->next = elem2;
        elem2->next = elem3;
        elem3->next = NULL;
        
	ft_lstclear(&elem2, free);
       
        aux = root;
        while (aux != NULL)
        {
          printf("%s\n", (char *)aux->content);
          aux = aux->next;
        } 
        return (0);       
}*/
