# libft

このプロジェクトは、他のプロジェクトで使用できるCライブラリをコーディングすることを目的としています。
- [ライブラリ wikipedia](https://ja.wikipedia.org/wiki/%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA) 
- [標準ライブラリ wikipedia](https://ja.wikipedia.org/wiki/%E6%A8%99%E6%BA%96%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA) 
- [標準Cライブラリ wikipedia](https://ja.wikipedia.org/wiki/%E6%A8%99%E6%BA%96C%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA)


### Part 1 - Libc functions
**この最初のパートではマニュアルで定義されているlibc関数を再コーディングする必要がある。オリジナルと同じ動作を示し、関数名の前には、"ft_"を付けなければならない。例えば、strlen は ft_strlen となる。**
ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_ascii ft_isdigit ft_isprint ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset ft_strchr ft_strdup ft_strlcat ft_strlcpy ft_strlen ft_strncmp ft_strnstr ft_strrchr ft_tolower ft_toupper

### Part 2 - Additional functions
このPart2ではlibcに含まれていないか、または別の形で含まれている関数をコーディングする必要がある。  
- ft_substr  
文字列's'の複製を(malloc(3)を使って)確保して返す。 文字列はインデックス 'start' から始まり、最大サイズ 'len' である。
		char *ft_substr(char const *s, unsigned int start, size_t len);

ft_strjoin
ft_strtrim
ft_split
ft_itoa
ft_strmapi
ft_striteri
ft_putchar_fd
ft_putstr_fd
ft_putendl_fd
ft_putnbr_fd
