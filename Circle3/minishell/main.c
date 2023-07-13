/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:02:21 by hdupuy            #+#    #+#             */
/*   Updated: 2023/07/13 10:26:57 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

// void	builtin(t_token *head)
// {
// 	t_token	*current;

// 	current = head;
// 	while (current)
// 	{
// 		current
// 	}
// }

int	main(void)
{
	t_mini	mini;

	init_struct(&mini);
	while (1)
	{
		mini.input = readline("MiniShell> ");
		if (mini.input != NULL)
		{
			if (strcmp(mini.input, "exit") == 0)
				break ;
			add_history(mini.input);
			mini.start = split_string(mini.input);
			update_token_types(&mini);
			// builtin(mini.start);
			print_list(mini.start);
			free_list(mini.start);
			free(mini.input);
		}
	}
	free_env(&mini);
	return (0);
}
