# libft

このプロジェクトは、他のプロジェクトで使用できるCライブラリをコーディングすることを目的としています。
- [ライブラリ wikipedia](https://ja.wikipedia.org/wiki/%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA) 
- [標準ライブラリ wikipedia](https://ja.wikipedia.org/wiki/%E6%A8%99%E6%BA%96%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA) 
- [標準Cライブラリ wikipedia](https://ja.wikipedia.org/wiki/%E6%A8%99%E6%BA%96C%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA)


### Part 1 - Libc functions
**この最初のパートではマニュアルで定義されているlibc関数を再コーディングする必要がある。オリジナルと同じ動作を示し、関数名の前には"ft_"を付けなければならない。例えば、strlen は ft_strlen となる。**  
atoi bzero calloc isalnum isalpha isascii isdigit isprint memchr memcmp memcpy memmove memset strchr strdup strlcat strlcpy strlen strncmp strnstr strrchr tolower toupper

### Part 2 - Additional functions
**このPart2ではlibcに含まれていないか、または別の形で含まれている関数をコーディングする必要がある。**  
<details>
<summary>ft_substr</summary>

### description
文字列's'の複製を(malloc(3)を使って)確保して返す。
文字列はインデックス 'start' から始まり、最大サイズ 'len' である。
### return value
文字列's'の複製を確保して返す。 割り当てに失敗した場合はNULLを返す。
```
char	*ft_substr(char const *s, unsigned int start, size_t len);
```
</details>

<details>
<summary>ft_strjoin</summary>

### description
(malloc(3)を使って)'s1'と's2'を連結した新しい文字列を返す。
### return value
連結した新しい文字列を返します。割り当てに失敗した場合はNULLを返す。
```
char	*ft_strjoin(char const *s1, char const *s2);
```
</details>

<details>
<summary>ft_strtrim</summary>

### description
(malloc(3)を使って)'set'で指定された文字を文字列の最初と最後から削除した's1'のコピーを返す。
### return value
トリミングされた文字列を返す。
```
char	*ft_strtrim(char const *s1, char const *set);
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
char	**ft_split(char const *s, char c);
```
</details>

<details>
<summary>ft_itoa</summary>

### description
(malloc(3)を使って)引数として受け取った整数を文字列にして返す。負の数は処理しなければならない。
### return value
整数として受け取った'n'を文字列にして返す。割り当てに失敗した場合はNULLを返す。
```
char	*ft_itoa(int n);
```
</details>

<details>
<summary>ft_strmapi</summary>

### description
文字列's'の各文字に関数'f'を適用し、新しい文字列を作成する。（malloc(3)を使用）
### return value
関数f' を連続して適用して作成した文字列。 割り当てに失敗した場合はNULLを返す。
```
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
```
</details>

<details>
<summary>ft_striteri</summary>

### description
引数として渡された文字列に関数'f'を適用し、必要に応じて変更する。
```
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
```
</details>

<details>
<summary>ft_putchar_fd</summary>

### description
文字'c'を指定されたファイルディスクリプターに出力する。
```
void	ft_putchar_fd(char c, int fd);
```
</details>

<details>
<summary>ft_putstr_fd</summary>

### description
文字列's'を指定されたファイルディスクリプターに出力する。
```
void	ft_putstr_fd(char *s, int fd);
```
</details>

<details>
<summary>ft_putendl_fd</summary>

### description
文字列's'を指定されたファイルディスクリプターに出力する。その後に改行を入れる。
```
void	ft_putendl_fd(char *s, int fd);
```
</details>

<details>
<summary>ft_putnbr_fd</summary>

### description
整数'n'を指定されたファイルディスクリプターに出力する。
```
void	ft_putnbr_fd(int n, int fd);
```
</details>


### Bonus part
**以下の構造体を使ってリストの要素を表現する。この構造体はlibft.hファイルに追加する必要がある。**
- content	: その要素に含まれるデータ。
- next		: 次の要素のアドレス。最後の要素であればNULL。

```
typedef struct	s_list
{
    void          *content;
    struct s_list *next;
}	t_list;
```


<details>
<summary>ft_lstnew</summary>

### description
新しい要素を（malloc(3)で）確保して返す。変数 'content' は引数 'content' の値で初期化され、変数'next'はNULLで初期化される。
### return value
新しい要素を返す。
```
t_list	*ft_lstnew(void *content);
```
</details>

<details>
<summary>ft_lstadd_front</summary>

### description
要素'new'をリストの先頭に追加する。
```
void	ft_lstadd_front(t_list **lst, t_list *new);
```
</details>

<details>
<summary>ft_lstsize</summary>

### description
リストの要素数をカウントする。
### return value
要素数を返す。
```
int	ft_lstsize(t_list *lst);
```
</details>

<details>
<summary>ft_lstlast</summary>

### description
リストの最後の要素を返す。
### return value
リストの最後の要素を返す。
```
t_list	*ft_lstlast(t_list *lst);
```
</details>

<details>
<summary>ft_lstadd_back</summary>

### description
リストの最後に要素'new'を追加する。
```
void	ft_lstadd_back(t_list **lst, t_list *new);
```
</details>

<details>
<summary>ft_lstdelone</summary>

### description
データを削除する関数delを使いlstのcontentのデータを削除する。
content削除後、リストをfreeする。
nextはfreeしてはいけない。
```
void	ft_lstdelone(t_list *lst, void (*del)(void *));
```
</details>

<details>
<summary>ft_lstclear</summary>

### description
指定された要素すべてを削除する関数delを使用し、freeする。
最後にnextがさすポインタをNULLに設定する必要がある。
```
void	ft_lstclear(t_list **lst, void (*del)(void*));
```
</details>

<details>
<summary>ft_lstiter</summary>

### description
lstの各contentへ関数fを適用する。
```
void	ft_lstiter(t_list *lst, void (*f)(void *));
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
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```
</details>
