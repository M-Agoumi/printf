#include "libftprintf.h"

int		ft_count_num(char *p)
{
	int i;

	i = 0;
	while (*(p + i) >= '0' && *(p + i) <= '9')
		i++;
	return (i);
}

int		ft_count_flags(char *p)
{
	int i;

	i = 0;
	while (*(p + i) == '+' || *(p + i) == '-' || *(p + i) == ' '
		|| *(p + i) == '#' || *(p + i) == '0' || *(p + i) == '*')
		i++;
	return (i);
}
