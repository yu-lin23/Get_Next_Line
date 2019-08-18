gcc -Wall -Werror -Wextra get_next_line.c main.c libft/libft.a
#gcc -Wall -Werror -Wextra get_next_line.c main_stenner.c libft/libft.a
read -p 'What file do you want to run with GNL? :' filename
./a.out ${filename}
