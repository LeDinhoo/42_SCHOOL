/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:00:11 by hdupuy            #+#    #+#             */
/*   Updated: 2023/01/10 10:45:55 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(void *s, int c, size_t n);
int		ft_memcmp(void *s1, void *s2, size_t n);
void	*ft_memcpy(void *dest, void *src, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(char *s, int c);
ssize_t	ft_strichr(char *s, int c);
size_t	ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
char	*ft_strrchr(char *s, int c);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strtrim(char *s1, char *set);
char	**ft_split(char *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);

#endif
