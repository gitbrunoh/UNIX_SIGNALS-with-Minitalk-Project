/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:16:27 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/23 16:25:13 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int     main()
{
        t_list  *root;
        t_list  *elem1;
        t_list  *elem2;
        t_list  *elem3;
        int size;
        t_list  *aux;
        t_list *newnode;
        
        root = malloc(sizeof(t_list));
        elem1 = malloc(sizeof(t_list));
        elem2 = malloc(sizeof(t_list));
        elem3 = malloc(sizeof(t_list));
        
        root->next = elem1;
        elem1->next = elem2;
        elem2->next = elem3;
        elem3->next = NULL;
        
        root->content = "Content do root";
        elem1->content = "Elem1 content";
        elem2->content = "Elem2 content";
        elem3->content = "Elem3 content";
        
        newnode = malloc(sizeof(t_list));
        newnode->content = "newnode content";

        ft_lstadd_front(&root, newnode);

        size = ft_lstsize(root);
        printf("Tamanho da lista: %d\n", size);
        
        aux = root;
        while (aux != NULL)
        {
          printf("%s\n", (char *)aux->content);
          aux = aux->next;
        }
        
        free(root);
        free(elem1);
        free(elem2);
        free(elem3);
        return (0);
}*/
