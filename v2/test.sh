clear
echo "------ making -------"
make
gcc libftprintf.a main.c -o test
echo "----- running test -------"
./test | cat -e
