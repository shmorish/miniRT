/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 07:46:36 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 08:49:37 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_object	*object_list_head(void)
{
	t_object	*head;

	head = (t_object *)malloc(sizeof(t_object));
	if (!head)
		print_error_and_exit("malloc failed");
	head->next = NULL;
	head->type = HEAD_TYPE;
	head->object_data = NULL;
	return (head);
}

t_object	*object_list_new(t_object_type type, char *line)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	if (!new)
		print_error_and_exit("malloc failed");
	new->next = NULL;
	new->type = type;
	if (type == SPHERE_TYPE)
		new->object_data = (void *)sphere(line);
	else if (type == PLANE_TYPE)
		new->object_data = (void *)plane(line);
	else if (type == CYLINDER_TYPE)
		new->object_data = (void *)cylinder(line);
	else
		print_error_and_exit(ERR_UNKNOWN);
	return (new);
}

t_object	*object_list_last_node(t_object *head)
{
	t_object	*node;

	node = head;
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	object_list_addback(t_object *head, t_object *newnode)
{
	t_object	*lastnode;

	lastnode = object_list_last_node(head);
	lastnode->next = newnode;
	newnode->next = NULL;
}

void	free_object_list(t_object *head)
{
	t_object	*node;
	t_object	*tmp;

	node = head->next;
	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp->object_data);
		free(tmp);
	}
	free(head);
}

// void	objs_free(t_objs *head)
// {
// 	t_objs	*node;
// 	t_objs	*tmp;

// 	node = head->next;
// 	while (node != head)
// 	{
// 		tmp = node;
// 		node = node->next;
// 		free(tmp->obj);
// 		free(tmp);
// 	}
// 	free(head);
// }
