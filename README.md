# libft

このプロジェクトは、他のプロジェクトで使用できるCライブラリをコーディングすることを目的としています。
- [ライブラリ wikipedia](https://ja.wikipedia.org/wiki/%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA) 
- [標準ライブラリ wikipedia](https://ja.wikipedia.org/wiki/%E6%A8%99%E6%BA%96%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA) 
- [標準Cライブラリ wikipedia](https://ja.wikipedia.org/wiki/%E6%A8%99%E6%BA%96C%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA)


### Part 1 - Libc functions
**この最初のパートではマニュアルで定義されているlibc関数を再コーディングする必要がある。**  
**オリジナルと同じ動作を示し、関数名の前には、"ft_"を付けなければならない。例えば、strlen は ft_strlen となる。**  
atoi bzero calloc isalnum isalpha ascii isdigit isprint memchr memcmp memcpy memmove memset strchr strdup strlcat strlcpy strlen strncmp strnstr strrchr tolower toupper

### Part 2 - Additional functions
**このPart2ではlibcに含まれていないか、または別の形で含まれている関数をコーディングする必要がある。**  
- ft_substr  
<details>
<summary>ft_substr</summary>

### description
文字列's'の複製を(malloc(3)を使って)確保して返す。
文字列はインデックス 'start' から始まり、最大サイズ 'len' である。
### return value
文字列's'の複製を確保して返す。 割り当てに失敗した場合はNULLを返す。
```
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
```
</details>

<details>
<summary>ft_strjoin</summary>

### description
(malloc(3)を使って)'s1'と's2'を連結した新しい文字列を返す。
### return value
連結した新しい文字列を返します。割り当てに失敗した場合はNULLを返す。
```
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*top;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	top = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (top);
}
```
</details>

<details>
<summary>ft_strtrim</summary>

### description
(malloc(3)を使って)'set'で指定された文字を文字列の最初と最後から削除した's1'のコピーを返す。
### return value
トリミングされた文字列を返す。
```
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	trimmed = ft_substr(s1, 0, len + 1);
	return (trimmed);
}
```
</details>

<details>
<summary>ft_split</summary>

### description
(malloc(3)を使って)文字'c'を区切り文字として's'を分割して得られる文字列の配列を確保して返す。
配列の最後には NULL ポインタで終了しなければならない。
### return value
分割された新しい文字列の配列。分割に失敗した場合は NULLを返す。
```
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
```
</details>

<details>
<summary>ft_itoa</summary>

### description
(malloc(3)を使って)引数として受け取った整数を文字列にして返す。負の数は処理しなければならない。
### return value
整数として受け取った'n'を文字列にして返す。割り当てに失敗した場合はNULLを返す。
```
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
```
</details>

<details>
<summary>ft_strmapi</summary>

### description
文字列's'の各文字に関数'f'を適用し、新しい文字列を作成します。（malloc(3)を使用）
### return value
関数f' を連続して適用して作成した文字列。 割り当てに失敗した場合はNULLを返す。
```
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
```
</details>

<details>
<summary>ft_striteri</summary>

### description
引数として渡された文字列に関数'f'を適用し、必要に応じて変更する。
### return value
```
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
```
</details>

<details>
<summary>ft_putchar_fd</summary>

### description
文字'c'を指定されたファイルディスクリプターに出力する。
### return value
```
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
```
</details>

<details>
<summary>ft_putstr_fd</summary>

### description
文字列's'を指定されたファイルディスクリプターに出力する。
### return value
```
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
```
</details>

<details>
<summary>ft_putendl_fd</summary>

### description
文字列's'を指定されたファイルディスクリプターに出力する。その後に改行を入れる。
### return value
```
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
```
</details>

<details>
<summary>ft_putnbr_fd</summary>

### description
整数'n'を指定されたファイルディスクリプターに出力する。
### return value
```
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * (-1);
		nbr = (unsigned int)n;
	}
	else
		nbr = (unsigned int)n;
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}
```
</details>
