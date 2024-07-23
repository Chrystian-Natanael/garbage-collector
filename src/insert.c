/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:17:42 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/23 08:31:51 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file insert.c
 * @brief This file contains the insert function
 * @author @Chrystian-Natanael
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

void	insert(void *address)
{
	t_typetree	*typetree;

	typetree = typetree_get();
	helper(typetree, address);
}

void	typetree_insert_matrix(void **matrix)
{
	int	i;

	i = 0;
	insert(matrix[i]);
	while (matrix[i])
	{
		insert(matrix[i]);
		i++;
	}
}
