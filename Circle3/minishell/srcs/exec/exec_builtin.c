/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:05:18 by hdupuy            #+#    #+#             */
/*   Updated: 2023/07/18 13:14:15 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	builtin_exec(t_mini *mini)
{
	t_token *current;

	current = mini->start;
	if (ft_strcmp(current->str, "cd") == 0)
		cd_build(mini);
	if (ft_strcmp(current->str, "echo") == 0)
		echo_build(mini->start);
}