/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:07:31 by sudatsu           #+#    #+#             */
/*   Updated: 2021/08/18 18:53:51 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*buf;

	if (!s || !f)
		return (NULL);
	i = 0;
	buf = (char *)malloc(ft_strlen(s) + 1);
	if (!buf)
		return (NULL);
	while (s[i])
	{
		buf[i] = (*f)(i, s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
