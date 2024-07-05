/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:16:38 by cnatanae          #+#    #+#             */
/*   Updated: 2024/04/22 12:36:45 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file create.c
 * @brief This file contains the typetree_create function
 * @author @Chrystian-Natanael && @kellyhayd
 * @date 2024/04/19
*/

#include "garbage_collector.h"

t_typetree	typetree_create(void *address)
{
	t_typetree	typetree;

	typetree = malloc(sizeof(struct s_typetree));
	if (typetree == NULL)
	{
		typetree_destroy();
		return (NULL);
	}
	typetree->address = address;
	typetree->ltree = NULL;
	typetree->rtree = NULL;
	typetree->height = 1;
	return (typetree);
}
