/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:57:35 by sudatsu           #+#    #+#             */
/*   Updated: 2021/07/29 14:22:24 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*ptr;

	ptr = lst;
	cnt = 0;
	while (ptr)
	{
		ptr = ptr->next;
		cnt++;
	}
	return (cnt);
}
