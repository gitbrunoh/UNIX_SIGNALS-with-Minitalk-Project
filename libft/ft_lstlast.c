/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:20:43 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/23 16:54:42 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

/*int     main()
{
        t_list  *root;
        t_list  *elem1;
        t_list  *elem2;
        t_list  *elem3;
        int size;
        t_list  *aux;
        t_list  *last;

        root = ft_lstnew("Content do root");
        elem1 = ft_lstnew("Content do elem1");
        elem2 = ft_lstnew("Content do elem2");
        elem3 = ft_lstnew("Content do elem3");
        
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
        size = ft_lstsize(root);
        printf("Tamanho da lista: %d\n", size);
        printf("\n");
        
        last = ft_lstlast(root);
        printf("%s", (char *)last->content);
        
        free(root);
        free(elem1);
        free(elem2);
        free(elem3);
        return (0);       
}*/
