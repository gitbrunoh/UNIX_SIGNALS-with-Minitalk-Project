/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:27:35 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/25 17:56:57 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst -> content);
		lst = lst -> next;
	}
	return ;
}

/*static	void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int     main()
{
        t_list  *root;
        t_list  *elem1;
        t_list  *elem2;
        t_list  *elem3;

        root = ft_lstnew(ft_strdup("Content do root"));
        elem1 = ft_lstnew(ft_strdup("Content do elem1"));
        elem2 = ft_lstnew(ft_strdup("Content do elem2"));
        elem3 = ft_lstnew(ft_strdup("Content do elem3"));
        root->next = elem1;
        elem1->next = elem2;
        elem2->next = elem3;
        elem3->next = NULL;
        
        ft_lstiter(root, print_content);
        printf("\n");

	ft_lstclear(&root, free);
        
        return (0);       
}*/
