/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_me42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:21:16 by yiwong            #+#    #+#             */
/*   Updated: 2023/05/20 20:20:11 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_ME42_H
# define LIB_ME42_H

# include <stdlib.h>

void	free_pointer(char *str);
void	free_ppointer(char **str);
int		min(int a, int b);
int		max(int a, int b);

#endif