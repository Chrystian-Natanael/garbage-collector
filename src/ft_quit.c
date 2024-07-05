/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:05:04 by cnatanae          #+#    #+#             */
/*   Updated: 2024/04/22 12:42:00 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_quit.c
 * @brief This file contains the quit function
 * @author @Chrystian-Natanael && @kellyhayd
 * @date 2024/04/22
*/

#include "garbage_collector.h"

// the static function that is used recursive to destroy the typetree
static void	helper(t_typetree typetree);

void	quit(int code)
{
	typetree_destroy();
	exit(code);
}

void	typetree_destroy(void)
{
	t_typetree	*typetree;

	typetree = typetree_get();
	helper(*typetree);
}

static void	helper(t_typetree typetree)
{
	if (typetree == NULL)
		return ;
	helper(typetree->ltree);
	helper(typetree->rtree);
	if (typetree->address)
	{
		free(typetree->address);
		typetree->address = NULL;
	}
	if (typetree)
	{
		free(typetree);
		typetree = NULL;
	}
}
