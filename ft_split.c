/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudatsu <sudatsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:02:28 by sudatsu           #+#    #+#             */
/*   Updated: 2021/08/11 18:47:01 by sudatsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_cnt(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c && *(s + 1) == c)
			cnt++;
		s++;
	}
	return (++cnt);
}

static char	*ft_split_substr(char const *s, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = -1;
	while (++i < len)
		sub[i] = s[i];
	sub[i] = '\0';
	return (sub);
}

static void	ft_split_internal(char const *s, char c, char **split)
{
	size_t	idx;
	char	*chr;

	idx = 0;
	while (*s)
	{
		while ((*s == c) && *s)
			s++;
		if (*s)
		{
			chr = ft_strchr(s, c);
			if (!chr)
				split[idx] = ft_split_substr(s, ft_strlen(s));
			else
				split[idx] = ft_split_substr(s, chr - s);
		}
		while ((*s != c) && *s)
			s++;
		idx++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)ft_calloc((ft_split_cnt(s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	ft_split_internal(s, c, split);
	return (split);
}
