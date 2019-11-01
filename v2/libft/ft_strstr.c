/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <agoumihunter@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:22:04 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/29 13:53:54 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int a;
	int b;

	a = 0;
	if (to_find[a] == '\0')
		return ((char*)str);
	while (str[a] != '\0')
	{
		b = 0;
		if (str[a] == to_find[b])
		{
			while (to_find[b] != '\0' && to_find[b] == str[a + b])
				b++;
			if (to_find[b] == '\0')
				return ((char*)&str[a]);
		}
		a++;
	}
	return (0);
}
