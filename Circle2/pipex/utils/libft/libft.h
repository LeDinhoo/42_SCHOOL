/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <dupuy@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:00:11 by hdupuy            #+#    #+#             */
/*   Updated: 2023/06/23 17:44:11 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				**ft_split(const char *s, char c);
char				*ft_itoa(int n);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strmapi(char *s, char (*f)(unsigned int, char));
char				*ft_strnstr(char *haystack, char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char *s1, char *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_memcmp(void *s1, void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long long			ft_atol(const char *str);
size_t				ft_strlcat(char *dst, char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
ssize_t				ft_strichr(char *s, int c);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memchr(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_isspace(int c);
char				*ft_strcpy(char *destination, const char *source);
int					ft_strcmp(const char *s1, const char *s2);

#endif
