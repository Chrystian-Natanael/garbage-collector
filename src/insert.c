/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:17:42 by cnatanae          #+#    #+#             */
/*   Updated: 2024/06/10 15:57:16 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file insert.c
 * @brief This file contains the typetree_insert function
 * @author @Chrystian-Natanael && @kellyhayd
 * @date 2024/04/19
*/

#include "garbage_collector.h"

// the static function that is used for the insert function
static void	helper(t_typetree *typetree, void *address);

static void	helper(t_typetree *typetree, void *address)
{
	if (*typetree == NULL)
		*typetree = typetree_create(address);
	else if (address == (*typetree)->address)
		return ;
	else
	{
		if (address < (*typetree)->address)
			helper(&(*typetree)->ltree, address);
		else
			helper(&(*typetree)->rtree, address);
		typetree_rebalance(typetree);
	}
}

void	typetree_insert(void *address)
{
	t_typetree	*typetree;

	typetree = typetree_get();
	helper(typetree, address);
}

void	typetree_insert_matrix(void **matrix)
{
	int	i;

	i = 0;
	typetree_insert(matrix[i]);
	while (matrix[i])
	{
		typetree_insert(matrix[i]);
		i++;
	}
}
