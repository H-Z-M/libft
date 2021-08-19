/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:09:31 by sudatsu           #+#    #+#             */
/*   Updated: 2021/07/21 18:54:26 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s + start);
	if (len > s_len)
		len = s_len;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
		while (i < len)
			sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
