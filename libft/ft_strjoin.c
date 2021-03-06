/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:49:01 by afulmini          #+#    #+#             */
/*   Updated: 2022/01/22 11:18:01 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	idx_1;
	size_t	idx_2;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	idx_1 = 0;
	str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	while (*(s1 + idx_1))
	{
		*(str + idx_1) = *(s1 + idx_1);
		idx_1++;
	}
	idx_2 = 0;
	while (*(s2 + idx_2))
	{
		*(str + idx_1) = *(s2 + idx_2);
		idx_1++;
		idx_2++;
	}
	return (str);
}
