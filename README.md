# 概要
このプロジェクトは、他のプロジェクトで使用できるCライブラリをコーディングすることを目的としています。  
- [ライブラリ wikipedia](https://ja.wikipedia.org/wiki/%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA)  
- [標準ライブラリ wikipedia](https://ja.wikipedia.org/wiki/%E6%A8%99%E6%BA%96%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA)  
- [標準Cライブラリ wikipedia](https://ja.wikipedia.org/wiki/%E6%A8%99%E6%BA%96C%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA)  
## はじめに
C言語のプログラミングは非常に便利な標準関数を利用できないと非常に退屈なものになってしまいます。このプロジェクトでは、これらの関数を書き直し、理解し、使いこなすことができます。このライブラリは今後のC言語プロジェクトのすべてに役立つでしょう。時間をかけてlibftを拡張してください。ただし、どの関数が許可されているかを必ず確認してください。

### Part 1 - Libc functions
この最初のパートではマニュアルで定義されているlibc関数を再コーディングする必要があります。あなたの関数はオリジナルと同じプロトタイプと動作を示す必要があります。関数名の前には、"ft_"を付けなければなりません。例えば、strlen は ft_strlen となります。
<details>
<summary>Part 1 - Libc functions</summary>

<details>
<summary>ft_atoi</summary>

#### description
ft_atoiは文字列を int 型整数に変換する。
#### return value
変換された値。
```
static int	ft_isspace(const char str)
{
	if (str == ' ' || str == '\f' || str == '\n'
		|| str == '\r' || str == '\t' || str == '\v')
		return (1);
	return (0);
}

static long	ft_isoverflow(int neg)
{
	if (neg)
		return (LONG_MIN);
	return (LONG_MAX);
}

static long	ft_strtol(const char *s, int neg, unsigned long cutoff, int cutlim)
{
	unsigned long	acc;
	int				any;
	int				c;

	acc = 0;
	any = 0;
	c = *s++;
	while (ft_isdigit(c))
	{
		c -= '0';
		if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
			any = -1;
		else
		{
			any = 1;
			acc = 10 * acc + c;
		}
		c = *s++;
	}
	if (any < 0)
		acc = ft_isoverflow(neg);
	else if (neg)
		acc = -acc;
	return (acc);
}

int	ft_atoi(const char *str)
{
	const char		*s = str;
	unsigned long	cutoff;
	int				cutlim;
	int				neg;

	neg = 0;
	//空白文字をスキップして、もしあれば先頭の+/-記号を拾います。
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
	{
		neg = 1;
		s++;
	}
	else if (*s == '+')
		s++;

	//cutoff値を計算します。
	//この値よりも大きい入力数字は、その後に入力文字が続く場合大きすぎることになります。
	//この値に等しいものは、最後の桁に基づいて有効か無効か判断します。
	//例えば、longの範囲が[-9223372036854775808..9223372036854775807]なので
	//cutoffは922337203685477580に、cutlimは7（neg==0）または8（neg==1）のいずれかに設定されます。
	//つまり、922337203685477580以上の値を累積した場合、
	//または同じ値であっても次の桁が7（または8）を超える場合は数値が大きすぎて範囲エラーが返されます。
	if (neg)
		cutoff = -(unsigned long)LONG_MIN;
	else
		cutoff = LONG_MAX;
	cutlim = cutoff % 10;
	cutoff /= 10;
	return ((int)ft_strtol(s, neg, cutoff, cutlim));
}
```
</details>

<details>
<summary>ft_bzero</summary>

### description
ft_bzeroはバイト列 s から始まる領域の先頭 n バイトを 数値ゼロ (値が '\0' のバイト)で埋める。
### return value

```
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
```
</details>

<details>
<summary>ft_calloc</summary>

### description
ft_callocは size バイトの要素 count個からなる配列にメモリを割り当て、割り当てられたメモリに対するポインタを返す。
メモリの内容は数値ゼロ (全ビットがゼロのバイト) にセットされる。
### return value
割り当てられたメモリーへのポインターを返す。 割り当てられたメモリーは、あらゆる組み込み型に対応できるようにアラインメントされる。
エラーの場合、これらの関数は NULL を返す。
```
void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	memory = malloc(count * size);
	if (!memory)
		return (NULL);
	else
		ft_bzero(memory, count * size);
	return (memory);
}
```
</details>

<details>
<summary>ft_isalnum</summary>

### description
ft_isalnumはft_isalphaまたはft_isdigitが真であるかをテストします。 引数の値は、unsigned charまたはEOFの値として表現可能でなければなりません。
### return value
文字テスト結果が偽のとき 0 を返し、文字テスト結果が真のとき 1 を返します。
```
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
```
</details>

<details>
<summary>ft_isalpha</summary>

### description
ft_isalphaはアルファベットであるかをテストします。 引数の値は、unsigned charまたはEOFの値として表現可能でなければなりません。
### return value
文字テスト結果が偽のとき 0 を返し、文字テスト結果が真のとき 1 を返します。
```
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
```
</details>

<details>
<summary>ft_ascii</summary>

### description
ft_isasciiはASCII文字（0～127の範囲）であるかをテストします。引数の値は、unsigned charまたはEOFの値として表現可能でなければなりません。
### return value
文字テスト結果が偽のとき 0 を返し、文字テスト結果が真のとき 1 を返します。
```
int	ft_isascii(int c)
{
	return ((c >= 0) && (c <= 127));
}
```
</details>

<details>
<summary>ft_isdigit</summary>

### description
ft_isdigitは数字 (0〜9) かどうかをテストします。引数の値は、unsigned charまたはEOFの値として表現可能でなければなりません。
### return value
文字テスト結果が偽のとき 0 を返し、文字テスト結果が真のとき 1 を返します。
```
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
```
</details>

<details>
<summary>ft_isprint</summary>

### description
ft_isprintは空白 (' ') を含む表示可能文字であるかをテストします。引数の値は、unsigned charまたはEOFの値として表現可能でなければなりません。
### return value
文字テスト結果が偽のとき 0 を返し、文字テスト結果が真のとき 1 を返します。
```
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
```
</details>

<details>
<summary>ft_memchr</summary>

### description
ft_memchrはポインタ s が指し示すメモリブロックの 先頭の n バイトから文字 c を探す。 最初に c (unsigned char と解釈される) が見つかった時点で動作が停止する。
### return value
一致する文字へのポインタを返し、もし文字が指定メモリ領域に現れない場合は NULL を返す。
```
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr = s;

	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
```
</details>

<details>
<summary>ft_memcmp</summary>

### description
ft_memcmpはメモリー領域 s1 とs2 の最初の n バイトを比較する (各バイトは unsigned char として解釈される)。
### return value
s1 の最初の n バイトが s2 の最初の n バイトよりも小さいか、同じか、あるいは大きいかによってそれぞれ負の整数、0、 正の整数を返す。
0 でない値の場合、 s1 と s2 で値が異なった最初のバイトの値の差で符号は決定される (バイトは unsigned char で解釈される)。
n が 0 の場合、返り値は 0 となる。
### information
'\177' と '\200'を比較する  
signed charの場合  
127 > -128  
unsigned charの場合  
127 < 128  
と結果が違ってしまう  
8進数の'\200' 16進数で '\x80'は符号の切り替わる文字コード  
```
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1 = s1;
	const unsigned char	*p2 = s2;

	while (n--)
	{
		if (*p1++ != *p2++)
			return (*--p1 - *--p2);
	}
	return (0);
}
```
</details>

<details>
<summary>ft_memcpy</summary>

### description
ft_memcpyはメモリー領域 src の先頭 n バイトを メモリー領域 dest にコピーする。コピー元の領域と コピー先の領域が重なってはならない。重なっている場合は ft_memmove を使うこと。
### return value
dest へのポインターを返す。
```
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = src;

	d = (unsigned char *)dst;
	if (!d && !s)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dst);
}
```
</details>

<details>
<summary>ft_memmove</summary>

### description
ft_memmoveはメモリー領域 src の先頭 n バイトを メモリー領域 dst にコピーする。コピー元
とコピー先の 領域が重なっていてもよい。 最初に src のバイトが src とも dest とも重ならない
一時的な配列にコピーされてから、一時的な配列から dst にバイトのコピーが行われたかのよう
にコピーが行われる。
### return value
dest へのポインターを返す。 
```
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;
	unsigned char		*lastd;
	unsigned const char	*lasts;

	s = (const unsigned char *)src;
	d = (unsigned char *)dst;
	if (!d && !s)
		return (NULL);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		lasts = s + (len - 1);
		lastd = d + (len - 1);
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dst);
}
```
</details>

<details>
<summary>ft_memset</summary>

### description
ft_memset b で示されるメモリー領域の先頭からlen バイトを c (unsigned char に変換)で埋める。
### return value
b へのポインターを返す。  
```
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	pc;

	ptr = (unsigned char *)b;
	pc = (unsigned char)c;
	while (len--)
		*ptr++ = pc;
	return (b);
}
```
</details>

<details>
<summary>ft_strchr</summary>

### description
ft_strchrは s によって指される文字列の中で最初に出会う文字 c を見つける。
### return value
一致した文字へのポインターを返し、もし 文字が見つからない場合は NULL を返す。終端のヌルバイトは文字列の一部とみなされ、cに'\0' が指定された場合には終端のヌルバイトへのポインターを返す。
```
char	*ft_strchr(const char *s, int c)
{
	char	p;

	p = (char)c;
	while (*s)
	{
		if (*s == p)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
```
</details>

<details>
<summary>ft_strdup</summary>

### description
ft_strdupは文字列 s1の複製である 新しい文字列へのポインターを返す。 新しい文字列のためのメモリーは malloc(3) で得ている。 そして、free(3) で解放することができる。
### return value
複製された文字列へのポインターを返す。 十分なメモリーが確保できなかった場合にはNULL を返す。
```
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s1) + 1;
	copy = (char *)malloc(len);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s1, len);
	return (copy);
}
```
</details>

<details>
<summary>ft_strlcat</summary>

### description
ft_strlcatはdst の終りに文字列 src を追加する。多くても
dstsize - strlen(dst) - 1 文字を追加する。
src と dst 文字列がオーバラップするなら振る舞いは不確定。
### return value
作成しようと試みる文字列の合計の長さを返す。つまりdst の初期値 + src の長さを意味する。
```
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dlen;

	d = dst;
	s = src;
	n = dstsize;
	while (n-- != 0 && *d)
		d++;
	dlen = d - dst;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
```
</details>

<details>
<summary>ft_strlcpy</summary>

### description
ft_strlcpyは文字列 src から dst まで size -1 文字までコピーする。
size が 0 でないなら結果はヌル文字で終了する。
### return value
作成しようと試みる文字列の合計の長さを返す。つまりsrc の長さを意味する。
```
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < dstsize)
		ft_memcpy(dst, src, srclen + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}
```
</details>

<details>
<summary>ft_strlen</summary>

### description
ft_strlenは s が指す文字列の長さを計算する。
### return value
s が指す文字列のバイト数を返す。
```
size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}
```
</details>

<details>
<summary>ft_strncmp</summary>

### description
ft_strncmpはs1 と s2 の最初の len バイトだけを比較する。
 ‘\200’ が ‘\0’ よりも大きくなるように、unsigned char を使って行いる。
### return value
s1 が s2 よりも大きいか、等しいか、あるいは小さいかに応じてそれぞれ 0 よりも大きい、0 に等しい、 あるいは 0 よりも小さい整数を返す。
### information
'\177' と '\200'を比較する  
signed charの場合  
127 > -128  
unsigned charの場合  
127 < 128  
と結果が違ってしまう  
8進数の'\200' 16進数で '\x80'は符号の切り替わる文字コード  
```
int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned char	u1;
	unsigned char	u2;

	while (len--)
	{
		u1 = (unsigned char)*s1++;
		u2 = (unsigned char)*s2++;
		if (u1 != u2)
			return (u1 - u2);
		if (u1 == '\0')
			return (0);
	}
	return (0);
}
```
</details>

<details>
<summary>ft_strnstr</summary>

### description
ft_strnstrは部分文字列 needle が文字列 haystack 中 で最初に現れる位置を見つける。len バイトだけを比較する。
### return value
見つかった部分文字列の開始を指すポインターを返し、 もし部分文字列が見つからない場合は NULL を返す。
```
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
```
</details>

<details>
<summary>ft_strrchr</summary>

### description
ft_strrchrは文字列 s 中に最後に文字 c が現れた位置へのポインターを返す。
### return value
一致した文字へのポインターを返し、もし 文字が見つからない場合は NULL を返す。終端のヌルバイトは文字列の一部と みなされ、c に '\0' が指定された場合には、終端のヌルバイトへのポインターを返す。
```
char	*ft_strrchr(const char *s, int c)
{
	char	*save;

	save = NULL;
	while (1)
	{
		if (*s == c)
			save = (char *)s;
		if (!*s)
			return (save);
		s++;
	}
}
```
</details>

<details>
<summary>ft_tolower</summary>

### description
ft_tolowerは大文字を小文字に変換する。
### return value
変換ができれば変換後の文字を返す。できなければ変換前の c を返す。  
```
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c |= (1 << 5);
	return (c);
}
```
</details>

<details>
<summary>ft_toupper</summary>

### description
ft_toupperは小文字を大文字に変換する。
### return value
変換ができれば変換後の文字を返す。できなければ変換前の c を返す。  
```
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c &= ~(1 << 5);
	return (c);
}
```
</details>

</details>

### Part 2 - Additional functions
この第2部ではlibcに含まれていないか、または別の形で含まれている関数のセットをコーディングする必要があります。
<details>
<summary>Part 2 - Additional functions</summary>

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

</details>


### Bonus part
メモリや文字列を操作する関数があると便利ですが、リストを操作する関数があるとさらに便利であることにすぐに気づくでしょう。  
以下の構造体を使ってリストの要素を表現します。この構造体はlibft.hファイルに追加する必要があります。
- content : その要素に含まれるデータ。void * は、あらゆる種類のデータを格納できます。
- next    : 次の要素のアドレス。最後の要素であればNULL。

```
typedef struct s_list
{
    void          *content;
    struct s_list *next;
}t_list;
```

<details>
<summary>Bonus part</summary>

<details>
<summary>ft_lstnew</summary>

### description
新しい要素を（malloc(3)で）確保して返す。変数 'content' は引数 'content' の値で初期化され、変数'next'はNULLで初期化される。
### return value
新しい要素を返す。
```
t_list	*ft_lstnew(void *content)
{
	t_list	*new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}
```
</details>

<details>
<summary>ft_lstadd_front</summary>

### description
要素'new'をリストの先頭に追加する。
### return value
```
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
```
</details>

<details>
<summary>ft_lstsize</summary>

### description
リストの要素数をカウントする。
### return value
要素数を返す。
```
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
```
</details>

<details>
<summary>ft_lstlast</summary>

### description
リストの最後の要素を返す。
### return value
リストの最後の要素を返す。
```
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}
```
</details>

<details>
<summary>ft_lstadd_back</summary>

### description
リストの最後に要素'new'を追加する。
### return value
```
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!new || !lst)
		return ;
	if (*lst)
	{
		ptr = *lst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	else
		*lst = new;
}
```
</details>

<details>
<summary>ft_lstdelone</summary>

### description
データを削除する関数delを使いlstのcontentのデータを削除する。
content削除後、リストをfreeする。
nextはfreeしてはいけない。
### return value
```
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}
```
</details>

<details>
<summary>ft_lstclear</summary>

### description
指定された要素すべてを削除する関数delを使用し、freeする。
最後にnextがさすポインタをNULLに設定する必要がある。
### return value
```
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
```
</details>

<details>
<summary>ft_lstiter</summary>

### description
lstの各contentへ関数fを適用する。
### return value
```
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	if (!lst || !f)
		return ;
	ptr = lst;
	while (ptr)
	{
		(*f)(ptr->content);
		ptr = ptr->next;
	}
}
```
</details>

<details>
<summary>ft_lstmap</summary>

### description
lstの名contentに関数「f」を適用し、新しいリストを作成する。
del関数は必要に応じて、コンテンツを削除する。
### return value
新しいリスト。割り当てが失敗した場合はNULL。
```
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*apply_elem;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		apply_elem = ft_lstnew((*f)(lst->content));
		if (!apply_elem)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, apply_elem);
		lst = lst->next;
	}
	return (new_lst);
}
```
</details>

</details>
