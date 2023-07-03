/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:55:54 by yiwong            #+#    #+#             */
/*   Updated: 2023/07/03 15:40:17 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long_bonus.h"

int	main(int argc, char **argv)
{
	int		error_code;
	t_bvars	vars;

	ft_memset(&vars, 0, sizeof(vars));
	error_code = arg_check(argc, argv);
	if (error_code != OK)
		error_exit(error_code);
	if (argc == 1)
		initialise(NULL, &vars);
	else
		initialise(argv[1], &vars);
	so_long(&vars);
	return (0);
}
