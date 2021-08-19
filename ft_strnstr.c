/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:08:08 by sudatsu           #+#    #+#             */
/*   Updated: 2021/07/27 14:17:41 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		needle_len;
	const char	*top;

	needle_len = ft_strlen(needle);
	if (needle_len == 0
		|| (len == needle_len && !ft_strncmp(haystack, needle, needle_len)))
		return ((char *)haystack);
	top = haystack;
	while (*top && top <= haystack + len - needle_len)
	{
		if (*top == *needle
			&& !ft_strncmp(top + 1, needle + 1, needle_len - 1))
			return ((char *)top);
		top++;
	}
	return (NULL);
}
