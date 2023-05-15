/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:02:52 by dylan             #+#    #+#             */
/*   Updated: 2023/05/11 16:59:31 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Libft memset: set void pointer memory to a determined size
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pstr;
	size_t			i;

	pstr = (unsigned char *)s;
	i = 0;
	while (n)
	{
		pstr[i] = c;
		i++;
		n--;
	}
	return (s);
}
