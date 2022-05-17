/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:34:39 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:17:36 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			idx;

	idx = 0;
	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (idx < n && (*string1 == *string2))
	{
		string1++;
		string2++;
		idx++;
	}
	if (idx == n)
	{
		string1--;
		string2--;
	}
	return (*string1 - *string2);
}
