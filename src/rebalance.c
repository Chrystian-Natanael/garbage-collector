/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebalance.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:15:44 by cnatanae          #+#    #+#             */
/*   Updated: 2024/04/22 12:45:27 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file rebalance.c
 * @brief This file contains the functions to rebalance the typetree node
 * @author @Chrystian-Natanael && @kellyhayd
 * @date 2024/04/19
*/

#include "garbage_collector.h"

// the static functions that are used for the rebalance function
static void	left_rotate(t_typetree *typetree);
static void	right_rotate(t_typetree *typetree);
static void	rebalance_left(t_typetree *typetree);
static void	rebalance_right(t_typetree *typetree);

static void	left_rotate(t_typetree *typetree)
{
	t_typetree	x;
	t_typetree	y;
	t_typetree	z;

	y = *typetree;
	x = y->rtree;
	z = x->ltree;
	y->rtree = z;
	x->ltree = y;
	*typetree = x;
	typetree_update_height((*typetree)->ltree);
	typetree_update_height(*typetree);
}

static void	right_rotate(t_typetree *typetree)
{
	t_typetree	x;
	t_typetree	y;
	t_typetree	z;

	y = *typetree;
	x = y->ltree;
	z = x->rtree;
	y->ltree = z;
	x->rtree = y;
	*typetree = x;
	typetree_update_height((*typetree)->rtree);
	typetree_update_height(*typetree);
}

static void	rebalance_left(t_typetree *typetree)
{
	int	lheight;
	int	rheight;

	lheight = typetree_get_height((*typetree)->ltree->ltree);
	rheight = typetree_get_height((*typetree)->ltree->rtree);
	if (lheight >= rheight)
		right_rotate(typetree);
	else
	{
		left_rotate(&((*typetree)->ltree));
		right_rotate(typetree);
	}
}

static void	rebalance_right(t_typetree *typetree)
{
	int	lheight;
	int	rheight;

	lheight = typetree_get_height((*typetree)->rtree->ltree);
	rheight = typetree_get_height((*typetree)->rtree->rtree);
	if (rheight >= lheight)
		left_rotate(typetree);
	else
	{
		right_rotate(&((*typetree)->rtree));
		left_rotate(typetree);
	}
}

void	typetree_rebalance(t_typetree *typetree)
{
	int	lheight;
	int	rheight;

	if ((*typetree) == NULL)
		return ;
	lheight = typetree_get_height((*typetree)->ltree);
	rheight = typetree_get_height((*typetree)->rtree);
	if (lheight - rheight > 1)
		rebalance_left(typetree);
	else if (rheight - lheight > 1)
		rebalance_right(typetree);
	typetree_update_height(*typetree);
}
