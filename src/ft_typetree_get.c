/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typetree_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:19:27 by cnatanae          #+#    #+#             */
/*   Updated: 2024/04/22 12:47:16 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_typetree_get.c
 * @brief This file contains the typetree_get function
 * @author @Chrystian-Natanael && @kellyhayd
 * @date 2024/04/19
*/

#include "garbage_collector.h"

t_typetree	*typetree_get(void)
{
	static t_typetree	typetree;

	return (&typetree);
}
