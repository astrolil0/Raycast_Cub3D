/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zumgenc <zumgenc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:06:46 by zumgenc           #+#    #+#             */
/*   Updated: 2024/05/10 14:06:47 by zumgenc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	x;
	size_t	y;
	char	*str;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	x = ft_strlen(s1);
	y = ft_strlen(s2) + 1;
	str = (char *)malloc(x + y);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, x + 1);
	ft_strlcpy(str + x, s2, y);
	return (str);
}
