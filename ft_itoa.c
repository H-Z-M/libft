/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:53:23 by sudatsu           #+#    #+#             */
/*   Updated: 2021/07/29 14:12:20 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_itoa_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	size_t			len;
	unsigned int	nbr;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_itoa_len(n);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	nbr = n;
	if (n < 0)
		nbr = -n;
	while (nbr > 0)
	{
		ptr[--len] = '0' + (nbr % 10);
		nbr /= 10;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}
