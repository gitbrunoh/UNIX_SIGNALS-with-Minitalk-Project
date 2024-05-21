/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:27:46 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/25 17:59:30 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*tmp;

	aux = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst -> content));
		if (!tmp)
		{
			ft_lstclear(&aux, del);
			return (NULL);
		}
		ft_lstadd_back(&aux, tmp);
		lst = lst -> next;
	}
	return (aux);
}

/*static	void	*print_content(void *content)
{
	printf("%s\n", (char *)content);
	return (content);
}

int     main()
{
        t_list  *root;
        t_list  *elem1;
        t_list  *elem2;
        t_list  *elem3;
	t_list	*newlist;

        root = ft_lstnew(ft_strdup("Content do root"));
        elem1 = ft_lstnew(ft_strdup("Content do elem1"));
        elem2 = ft_lstnew(ft_strdup("Content do elem2"));
        elem3 = ft_lstnew(ft_strdup("Content do elem3"));
        root->next = elem1;
        elem1->next = elem2;
        elem2->next = elem3;
        elem3->next = NULL;
        
	
        newlist = ft_lstmap(root, print_content, free);
        printf("\n");

	ft_lstclear(&root, free);
        ft_lstclear(&newlist, free);
        return (0);       
}*/
