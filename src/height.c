/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:20:48 by cnatanae          #+#    #+#             */
/*   Updated: 2024/04/22 12:47:00 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file height.c
 * @brief This file contains func. to get and update the height of typetree node
 * @author @Chrystian-Natanael && @kellyhayd
 * @date 2024/04/19
*/

#include "garbage_collector.h"

int	typetree_get_height(t_typetree typetree)
{
	if (typetree == NULL)
		return (0);
	else
		return (typetree->height);
}

void	typetree_update_height(t_typetree typetree)
{
	int	lheight;
	int	rheight;

	lheight = typetree_get_height(typetree->ltree);
	rheight = typetree_get_height(typetree->rtree);
	if (lheight > rheight)
		typetree->height = 1 + lheight;
	else
		typetree->height = 1 + rheight;
}
