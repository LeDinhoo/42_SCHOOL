/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dupuy <dupuy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:01:13 by hdupuy            #+#    #+#             */
/*   Updated: 2023/05/29 10:08:08 by dupuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == ' ' || num[0] == '+')
		i++;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_repeat(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	process_arguments(char ***argv, int *argc, int *is_modified)
{
	if (*argc == 2)
	{
		*is_modified = 1;
		*argv = ft_split((*argv)[1], ' ');
		if (!**argv)
			error_msg("Error", *argv, *is_modified);
	}
	else
		*is_modified = 0;
}

void	validate_argument(char **argv, int i, int is_modified)
{
	long	tmp;

	tmp = ft_atoi(argv[i]);
	if (!ft_isnum(argv[i]) || ft_is_repeat(tmp, argv, i))
		error_msg("Error", argv, is_modified);
	tmp = ft_atol(argv[i]);
	if (tmp < -2147483648 || tmp > 2147483647)
		error_msg("Error", argv, is_modified);
}

void	ft_check_arg(char **argv, int argc)
{
	int	i;
	int	is_modified;

	process_arguments(&argv, &argc, &is_modified);
	if (is_modified)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		validate_argument(argv, i, is_modified);
		i++;
	}
	if (is_modified)
		ft_free(argv);
}

// void	ft_check_arg(char **argv, int argc)
// {
// 	int		i;
// 	long	tmp;
// 	int		is_modified;

// 	is_modified = 0;
// 	i = 0;
// 	if (argc == 2)
// 	{
// 		is_modified = 1;
// 		argv = ft_split(argv[1], ' ');
// 		if (!*argv)
// 			error_msg("Error", argv, is_modified);
// 	}
// 	else
// 		i = 1;
// 	while (argv[i])
// 	{
// 		tmp = ft_atoi(argv[i]);
// 		if (!ft_isnum(argv[i]) || ft_is_repeat(tmp, argv, i))
// 			error_msg("Error", argv, is_modified);
// 		tmp = ft_atol(argv[i]);
// 		if (tmp < -2147483648 || tmp > 2147483647)
// 			error_msg("Error", argv, is_modified);
// 		i++;
// 	}
// 	if (argc == 2)
// 		ft_free(argv);
// }
