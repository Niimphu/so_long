/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:46:59 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/28 16:47:39 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

t_ent	*add_enemy(t_vars *vars, int i, int j);
t_ent	*new_enemy_node(t_vars *vars, int i, int j);

t_ent	*create_enemy_list(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (ft_strchr("HhVv", vars->map[i][j]))
				vars->enemies = add_enemy(vars, i, j);
			j++;
		}
		i++;
	}
	return (vars->enemies);
}

void	free_list(t_ent *list)
{
	t_ent	*next;

	if (!list)
		return ;
	while (list)
	{
		next = list->next;
		free(list);
		list = NULL;
		list = next;
	}
}

t_ent	*add_enemy(t_vars *vars, int i, int j)
{
	t_ent *list;

	if (!vars->enemies)
		return (new_enemy_node(vars, i, j));
	list = vars->enemies;
	while (list->next)
		list = list->next;
	list->next = new_enemy_node(vars, i, j);
	return (vars->enemies);
}

t_ent	*new_enemy_node(t_vars *vars, int i, int j)
{
	t_ent	*node;

	node = malloc(sizeof(t_ent));
	if (!node)
		return (NULL);
	node->id = vars->map[i][j];
	node->coords[X] = j;
	node->coords[Y] = i;
	node->next = NULL;
	return (node);
}

void	print_list(t_ent *list)
{
	if (!list)
		return ;
	ft_printf("----ENEMIES----\n");
	while (list)
	{
		ft_printf("Enemy: %c Location: %i, %i.\n",
				  list->id, list->coords[X], list->coords[Y]);
		list = list->next;
	}
	ft_printf("---------------\n\n");
}
