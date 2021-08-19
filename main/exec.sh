rm cexe
make bonus -C ../

gcc -Wall -Wextra -Werror -o cexe ../libft.a atoi_main.c
./cexe
gcc -Wall -Wextra -Werror -o cexe ../libft.a bzero_main.c
./cexe
# gcc -Wall -Wextra -Werror -o cexe ../libft.a calloc_main.c
# ./cexe
gcc -Wall -Wextra -Werror -o cexe ../libft.a is_main.c
./cexe
gcc -Wall -Wextra -Werror -o cexe ../libft.a itoa_main.c
./cexe
gcc -Wall -Wextra -Werror -o cexe ../libft.a put_fd_main.c
./cexe
gcc -Wall -Wextra -Werror -o cexe ../libft.a split_main.c
./cexe
gcc -Wall -Wextra -Werror -o cexe ../libft.a substr_main.c
./cexe
gcc -Wall -Wextra -Werror -o cexe ../libft.a toupper_main.c
./cexe
gcc -Wall -Wextra -Werror -o cexe ../libft.a tolower_main.c
./cexe

for file in `\find . -name 'mem*'`; do
	gcc -Wall -Wextra -Werror -o cexe ../libft.a $file
	./cexe
done
for file in `\find . -name 'str*'`; do
	gcc -Wall -Wextra -Werror -o cexe ../libft.a $file
	./cexe
done

for file in `find . -name 'lst*'`; do
	gcc -Wall -Wextra -Werror -o cexe ../libft.a $file
	./cexe
done
make fclean -C ../
