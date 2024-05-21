/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:21:36 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/23 16:35:16 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current -> next != NULL)
		current = current -> next;
	current -> next = new;
	return ;
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
        
	size = 0;
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
        newnode->content = "Content do newnode";

        ft_lstadd_back(&root, newnode);
        
        aux = root;
        while (aux != NULL)
        {
          printf("%s\n", (char *)aux->content);
          aux = aux->next;
        }
        size = ft_lstsize(root);
        printf("Tamanho da lista: %d\n", size);
        free(root);
        free(elem1);
        free(elem2);
        free(elem3);
        return (0);
}*/
