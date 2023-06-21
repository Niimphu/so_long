/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:55:54 by yiwong            #+#    #+#             */
/*   Updated: 2023/06/21 18:07:29 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dep/so_long.h"

int	main(int argc, char **argv)
{
	int		error_code;
	t_vars	vars;

	ft_memset(&vars, 0, sizeof(vars));
	error_code = arg_check(argc, argv);
	if (error_code != OK)
		error(error_code);
	if (argc == 1)
		error_code = init(NULL, &vars);
	else
		error_code = init(argv[1], &vars);
	so_long(&vars);
	return (0);
}
