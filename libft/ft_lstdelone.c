/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:26:47 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/23 18:51:05 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	(*del)(lst -> content);
	free(lst);
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
        
        aux = root;
        while (aux != NULL)
        {
          printf("%s\n", (char *)aux->content);
          aux = aux->next;
        }
        
        ft_lstdelone(elem2, free);
        
        free(root);
        free(elem1);
        free(elem3);
        return (0);       
}*/
