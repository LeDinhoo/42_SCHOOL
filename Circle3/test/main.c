
// #include <fcntl.h>
// #include <readline/history.h>
// #include <readline/readline.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/wait.h>

// #define EMPTY 0
// #define CMD 1
// #define ARG 2
// #define TRUNC 3
// #define APPEND 4
// #define INPUT 5
// #define PIPE 6
// #define END 7
// #define HEREDOC 8

// typedef struct s_split
// {
// 	int				start;
// 	int				end;
// 	int				length;
// 	int				in_quotes;
// 	int				tokenlength;
// }					t_split;

// typedef struct s_token
// {
// 	char			*str;
// 	int				type;
// 	struct s_token	*prev;
// 	struct s_token	*next;
// }					t_token;

// typedef struct s_parser
// {
// 	t_token			*head;
// 	int				start;
// 	size_t			end;
// 	int				in_quotes;
// }					t_parser;

// void	add_node(t_token **head, char *str, int type)
// {
// 	t_token	*node;
// 	t_token	*current;

// 	node = malloc(sizeof(t_token));
// 	node->str = strdup(str);
// 	node->type = type;
// 	node->next = NULL;
// 	node->prev = NULL;
// 	if (*head == NULL)
// 	{
// 		*head = node;
// 	}
// 	else
// 	{
// 		current = *head;
// 		while (current->next != NULL)
// 		{
// 			current = current->next;
// 		}
// 		current->next = node;
// 		node->prev = current;
// 	}
// }

// int	determine_token_type(const char *str)
// {
// 	if (strcmp(str, "") == 0)
// 		return (EMPTY);
// 	else if (strcmp(str, ";") == 0)
// 		return (END);
// 	else if (strcmp(str, "|") == 0)
// 		return (PIPE);
// 	else if (strcmp(str, "<") == 0)
// 		return (INPUT);
// 	else if (strcmp(str, ">") == 0)
// 		return (TRUNC);
// 	else if (strcmp(str, ">>") == 0)
// 		return (APPEND);
// 	else if (strcmp(str, "<<") == 0)
// 		return (HEREDOC);
// 	else
// 	{
// 		if (*str == '\0' || *str == '|' || *str == ';')
// 			return (CMD);
// 		else
// 			return (ARG);
// 	}
// }

// char	*substitute_variable_value(const char *token)
// {
// 	char	*substitutedtoken;
// 	char	*variablevalue;
// 	char	*variablename;

// 	substitutedtoken = NULL;
// 	if (token[0] == '$')
// 	{
// 		variablename = strdup(token + 1);
// 		variablevalue = getenv(variablename);
// 		free(variablename);
// 		if (variablevalue != NULL)
// 			substitutedtoken = strdup(variablevalue);
// 	}
// 	if (substitutedtoken == NULL)
// 		substitutedtoken = strdup(token);
// 	return (substitutedtoken);
// }

// void	add_token_to_list(t_token **head, const char *start, int tokenLength)
// {
// 	char	*token;
// 	char	*substituted_token;

// 	token = malloc(tokenLength + 1);
// 	strncpy(token, start, tokenLength);
// 	token[tokenLength] = '\0';
// 	if (token[0] == '\'' && token[tokenLength - 1] == '\'')
// 	{
// 		add_node(head, token, determine_token_type(token));
// 	}
// 	else
// 	{
// 		substituted_token = substitute_variable_value(token);
// 		add_node(head, substituted_token,
// 			determine_token_type(substituted_token));
// 		free(substituted_token);
// 	}
// 	free(token);
// }

// t_token	*split_string(const char *str)
// {
// 	t_token	*head;
// 	t_split	*tkn;

// 	head = NULL;
// 	tkn = malloc(sizeof(t_split));
// 	if (tkn == NULL)
// 		return (NULL);
// 	tkn->start = 0;
// 	tkn->end = 0;
// 	tkn->length = strlen(str);
// 	tkn->in_quotes = 0;
// 	while (tkn->end <= tkn->length)
// 	{
// 		if (str[tkn->end] == '\'')
// 		{
// 			// if (str[tkn->end] == '\'' && str[tkn->end + 1] == '\'')
// 			// 	break ;
// 			if (tkn->in_quotes == '\'')
// 			{
// 				tkn->in_quotes = 0;
// 				if (tkn->end - tkn->start > 0)
// 				{
// 					add_token_to_list(&head, &str[tkn->start], tkn->end
// 						- tkn->start);
// 					tkn->start = tkn->end + 1;
// 				}
// 			}
// 			else if (!tkn->in_quotes)
// 			{
// 				tkn->in_quotes = '\'';
// 				tkn->start = tkn->end + 1;
// 			}
// 		}
// 		else if (str[tkn->end] == '\"')
// 		{
// 			// if (str[tkn->end] == '\"' && str[tkn->end + 1] == '\"')
// 			// 	break ;
// 			if (tkn->in_quotes == '\"')
// 			{
// 				tkn->in_quotes = 0;
// 				if (tkn->end - tkn->start > 0)
// 				{
// 					printf("%d/n", (tkn->end - tkn->start));
// 					add_token_to_list(&head, &str[tkn->start], tkn->end
// 						- tkn->start);
// 					tkn->start = tkn->end + 1;
// 				}
// 			}
// 			else if (!tkn->in_quotes)
// 			{
// 				tkn->in_quotes = '\"';
// 				tkn->start = tkn->end + 1;
// 			}
// 		}
// 		else if (tkn->in_quotes == '\'' && str[tkn->end] != '\0')
// 		{
// 			printf("OK");
// 			while (tkn->end <= tkn->length && str[tkn->end] != '\'')
// 				tkn->end++;
// 			if (tkn->end <= tkn->length)
// 				tkn->end--;
// 		}
// 		else if (tkn->in_quotes == '\"' && str[tkn->end] != '\0')
// 		{
// 			while (tkn->end <= tkn->length && str[tkn->end] != '\"')
// 				tkn->end++;
// 			if (tkn->end <= tkn->length)
// 				tkn->end--;
// 		}
// 		else if (str[tkn->end] == '<' || str[tkn->end] == '>')
// 		{
// 			if (tkn->end - tkn->start > 0)
// 			{
// 				add_token_to_list(&head, &str[tkn->start], tkn->end
// 					- tkn->start);
// 			}
// 			if (str[tkn->end + 1] == ' ')
// 			{
// 				add_token_to_list(&head, &str[tkn->end], 1);
// 			}
// 			else
// 			{
// 				tkn->tokenlength = 1;
// 				if (str[tkn->end + 1] == str[tkn->end])
// 					tkn->tokenlength = 2;
// 				add_token_to_list(&head, &str[tkn->end], tkn->tokenlength);
// 				tkn->end++;
// 			}
// 			tkn->start = tkn->end + 1;
// 		}
// 		else if (str[tkn->end] == ';' || str[tkn->end] == '|')
// 		{
// 			if (tkn->end - tkn->start > 0)
// 			{
// 				add_token_to_list(&head, &str[tkn->start], tkn->end
// 					- tkn->start);
// 			}
// 			add_token_to_list(&head, &str[tkn->end], 1);
// 			tkn->start = tkn->end + 1;
// 		}
// 		else if (str[tkn->end] == ' ')
// 		{
// 			if (tkn->end - tkn->start > 0)
// 			{
// 				add_token_to_list(&head, &str[tkn->start], tkn->end
// 					- tkn->start);
// 			}
// 			tkn->start = tkn->end + 1;
// 		}
// 		else if (str[tkn->end] == ' ' || str[tkn->end] == '\0')
// 		{

// 			if (tkn->end - tkn->start > 0)
// 			{
// 				add_token_to_list(&head, &str[tkn->start], tkn->end
// 					- tkn->start);
// 				tkn->start = tkn->end + 1;
// 			}
// 		}
// 		tkn->end++;
// 	}
// 	if (tkn->in_quotes && tkn->end - tkn->start > 0)
// 	{
// 		printf("OK");
// 		add_token_to_list(&head, &str[tkn->start], tkn->end - tkn->start);
// 	}
// 	free(tkn);
// 	return (head);
// }

// int	main(void)
// {
// 	t_token	*tokens;
// 	t_token	*current;
// 	t_token	*next;

// 	// On définit un tableau de commandes à tester
// 	const char *commands[] = {
// 		"\"\"",
// 		"''",
// 		"echo $HOME",
// 		"gcc -o program program.c",
// 		"'command with spaces'",
// 		"ceci est une chaine sans guillemets",
// 		"\"\\\"Ceci est une 'chaîne' avec des guillemets imbriqués\\\"\"",
// 		"Ceci est une chaîne avec des \\ caractères d'échappement",
// 		"Ceci est une chaîne avec des caractères spéciaux : !@#$%^&*()_+",
// 		"$(ls -la)",
// 		"$HOME",
// 		"> fichier",
// 		"ls | grep txt",
// 	};
// 	// On boucle sur chaque commande
// 	for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
// 	{
// 		printf("\nProcessing command: %s\n", commands[i]);
// 		// On divise la commande en tokens et on les imprime
// 		tokens = split_string(commands[i]);
// 		current = tokens;
// 		while (current != NULL)
// 		{
// 			printf("Token: %s, Type: %d\n", current->str, current->type);
// 			current = current->next;
// 		}
// 		// On libère la mémoire utilisée par les tokens
// 		current = tokens;
// 		while (current != NULL)
// 		{
// 			next = current->next;
// 			free(current->str);
// 			free(current);
// 			current = next;
// 		}
// 	}
// 	return (0);
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * replaceSubstring(char * string, const char * sub, const char * new_sub) {
    size_t string_len = strlen(string);
    size_t sub_len = strlen(sub);
    size_t new_sub_len = strlen(new_sub);
    char * result = malloc(string_len + 1);

    if (new_sub_len > sub_len) {
        // On doit allouer plus d'espace si la nouvelle sous-chaîne est plus longue que l'ancienne
        size_t count = 0;
        for (const char * ptr = string; (ptr = strstr(ptr, sub)); ptr += sub_len)
            ++count;
        result = realloc(result, string_len + count * (new_sub_len - sub_len) + 1);
    }

    char * copy_to = result;
    while (1) {
        char * found_sub = strstr(string, sub);
        if (found_sub == NULL) {
            strcpy(copy_to, string);
            break;
        }
        size_t prefix_len = found_sub - string;
        strncpy(copy_to, string, prefix_len);
        copy_to += prefix_len;
        strcpy(copy_to, new_sub);
        copy_to += new_sub_len;
        string = found_sub + sub_len;
    }

    return result;
}

int main() {
    char string[100] = "Bonjour, Je suis OpenAI";
    char * replaced_string = replaceSubstring(string, "OpenAI", "GPT-4");
    printf("%s\n", replaced_string);
    free(replaced_string);
    return 0;
}

