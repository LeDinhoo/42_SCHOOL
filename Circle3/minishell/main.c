/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:02:21 by hdupuy            #+#    #+#             */
/*   Updated: 2023/07/14 16:09:53 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*get_git_branch(void)
{
	char	branch[100];
	FILE	*git_branch;

	git_branch = popen("git rev-parse --abbrev-ref HEAD 2>/dev/null", "r");
	fgets(branch, sizeof(branch), git_branch);
	pclose(git_branch);
	if (strlen(branch) > 0 && branch[strlen(branch) - 1] == '\n')
		branch[strlen(branch) - 1] = '\0';
	return (strdup(branch));
}

char	*get_prompt_str(void)
{
	char		*user_home;
	char		*cwd;
	char		*directory;
	static char	prompt[PATH_MAX];
	char		*git_branch;

	git_branch = get_git_branch();
	user_home = getenv("HOME");
	cwd = getenv("PWD");
	if (!cwd)
		cwd = "/UNKNOWN";
	if (user_home && strcmp(cwd, user_home) == 0)
		directory = "~";
	else
	{
		directory = strrchr(cwd, '/');
		if (directory == NULL)
			directory = "UNKNOWN";
		else
			directory++;
	}
	memset(prompt, 0, sizeof(prompt));
	strcat(prompt, "\033[34mMiniShell\033[92m➜\033[0m \033[96m");
	strncat(prompt, directory, PATH_MAX - strlen(prompt) - 1);
	if (git_branch && strlen(git_branch) > 0 && strcmp(git_branch, "HEAD") != 0
		&& strcmp(git_branch, "o") != 0)
	{
		strcat(prompt, " ");
		strcat(prompt, "\033[34mgit:(\033[0m");
		strcat(prompt, "\033[31m");
		strcat(prompt, git_branch);
		strcat(prompt, "\033[34m)\033[0m");
		strcat(prompt, " \033[33m✗\033[0m");
	}
	strcat(prompt, "\033[33m\033[0m");
	free(git_branch);
	strcat(prompt, " ");
	return (prompt);
}

int	minishell_cd(char *path)
{
	char	*home;
	char	*cwd;

	if (path == NULL || strcmp(path, "") == 0)
	{
		home = getenv("HOME");
		if (home == NULL)
		{
			fprintf(stderr, "minishell: HOME environment variable not set\n");
			return (-1);
		}
		path = home;
	}
	if (chdir(path) != 0)
	{
		perror("minishell");
		return (-1);
	}
	cwd = malloc(PATH_MAX);
	if (cwd == NULL)
	{
		perror("malloc");
		return (-1);
	}
	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		perror("minishell");
		free(cwd);
		return (-1);
	}
	if (setenv("PWD", cwd, 1) != 0)
	{
		perror("minishell");
		free(cwd);
		return (-1);
	}
	free(cwd);
	return (0);
}

int	main(void)
{
	t_mini	mini;
	char	*prompt;
	t_token	*current_token;

	init_struct(&mini);
	while (1)
	{
		prompt = get_prompt_str();
		mini.input = readline(prompt);
		if (mini.input != NULL)
		{
			if (strcmp(mini.input, "exit") == 0)
				break ;
			add_history(mini.input);
			mini.start = split_string(mini.input);
			update_token_types(&mini);
			current_token = mini.start;
			if (current_token && current_token->str
				&& strcmp(current_token->str, "cd") == 0)
			{
				if (current_token->next)
					minishell_cd(current_token->next->str);
				else
					minishell_cd("");
			}
			else
			{
				print_list(mini.start);
			}
			free_list(mini.start);
			free(mini.input);
		}
	}
	free_env(&mini);
	return (0);
}

// int	main(void)
// {
// 	t_mini	mini;
// 	char	*prompt;

// 	init_struct(&mini);
// 	while (1)
// 	{
// 		prompt = get_prompt_str();
// 		mini.input = readline(prompt);
// 		if (mini.input != NULL)
// 		{
// 			if (strcmp(mini.input, "exit") == 0)
// 				break ;
// 			add_history(mini.input);
// 			mini.start = split_string(mini.input);
// 			update_token_types(&mini);
// 			print_list(mini.start);
// 			free_list(mini.start);
// 			free(mini.input);
// 		}
// 	}
// 	free_env(&mini);
// 	return (0);
// }
