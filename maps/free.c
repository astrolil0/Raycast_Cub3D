/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zumgenc <zumgenc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:57:14 by zumgenc           #+#    #+#             */
/*   Updated: 2024/05/10 13:57:16 by zumgenc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_array2d(char **str)
{
	char	**temp;

	temp = str;
	while (temp && *temp)
	{
		free(*temp);
		temp++;
	}
	free(str);
}