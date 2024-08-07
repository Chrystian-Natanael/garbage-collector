/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:28:04 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/23 08:31:51 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_allocate.c
 * @brief This file contains the allocate function
 * @author @Chrystian-Natanael
 * @date 2024/04/19
*/

#include "garbage_collector.h"

void	*allocate(unsigned int size)
{
	void			*address;
	unsigned int	idx;

	address = malloc(size);
	if (address == NULL)
	{
		typetree_destroy();
		exit (1);
	}
	idx = -1;
	while (++idx < size)
		((unsigned char *)address)[idx] = '\0';
	insert(address);
	return (address);
}
