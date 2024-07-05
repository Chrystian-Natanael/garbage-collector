/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:22:18 by cnatanae          #+#    #+#             */
/*   Updated: 2024/06/10 15:58:03 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

/**
 * @file garbage_collector.h
 * @brief This file contains the garbage collector functions
 * @author @Chrystian-Natanael && @kellyhayd
 * @date 2024/04/19
*/

/*For use exit()*/
# include <stdlib.h>

/*define t_typetree as pointer of struct s_typetree*/
typedef struct s_typetree	*t_typetree;

/**
 * @brief struct s_typetree
 * @details struct s_typetree is a binary tree that stores the addresses
 *  of the allocated memory
 * @param ltree is the left node of the binary tree
 * @param rtree is the right node of the binary tree
 * @param address is the address of the allocated memory
 * @param height is the height of the binary tree
*/
struct s_typetree {
	t_typetree		ltree;
	t_typetree		rtree;
	void			*address;
	int				height;
};

/**
 * @brief allocate
 * @details allocate memory
 * @param size is the size of the memory to be allocated
 * @return void* is the address of the allocated memory
*/
void		*allocate(unsigned int size);

/**
 * @brief deallocate
 * @details deallocate specific memory address and your children
 * @param address is the address of the memory to be deallocated
*/
void		deallocate(void *address);

/**
 * @brief quit
 * @details destoy the binary tree and exit the program with the exit code
 * @param code is the exit code
*/
void		quit(int code);

/**
 * @brief typetree_create
 * @details create a new binary tree node
 * @param address is the address of the allocated memory to be stored in
 * the binary tree
 * @return t_typetree is the new binary tree node
*/
t_typetree	typetree_create(void *address);

/**
 * @brief typetree_get_height
 * @details get the height of the binary tree node
 * @param typetree is the binary tree node
 * @return int is the height of the binary tree node
*/
int			typetree_get_height(t_typetree typetree);

/**
 * @brief typetree_update_height
 * @details update the height of the binary tree node
 * @param typetree is the binary tree node to be updated
*/
void		typetree_update_height(t_typetree typetree);

/**
 * @brief typetree_insert
 * @details insert a address in the binary tree
 * @param address is the address of the allocated memory to be stored in
 * the binary tree
*/
void		typetree_insert(void *address);

/**
 * @brief typetree_insert_matrix
 * @details insert a matrix of addresses in the binary tree
 * @param matrix is the matrix of address of the allocated mem to be stored in
 * the binary tree
*/
void		typetree_insert_matrix(void **matrix);

/**
 * @brief typetree_rebalance
 * @details rebalance the binary tree
 * @param typetree is the binary tree
*/
void		typetree_rebalance(t_typetree *typetree);

/**
 * @brief typetree_get
 * @details get the root binary tree
 * @return t_typetree is the root binary tree
*/
t_typetree	*typetree_get(void);

/**
 * @brief typetree_delete
 * @details delete a address in the binary tree
 * @param address is the address of the allocated memory to be deleted in
 * the binary tree
*/
void		typetree_delete(void *address);

/**
 * @brief typetree_destroy
 * @details destroy all binary tree
*/
void		typetree_destroy(void);

#endif