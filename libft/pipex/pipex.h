/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:16:09 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/10/26 12:32:20 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// Libraries added for the use of a variety of functions

# include <ctype.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <sys/wait.h>

// Definition of "macros" used to understand better pipe ends/starts

# define FD_READ_END	0
# define FD_WRITE_END	1

// Functions used to play with strings

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// Functions that play with execution, proccesses,
//	identifiers, file descriptors...

void	ft_error(int d1, char	*infile);
void	ft_child(int fd1, char	*arguments1,
			char	**enviroment1, int	*fds1);
void	ft_adult(int fd2, char	*arguments2,
			char	**enviroment2, int	*fds2);
char	*ft_path(char	**enviroment_path);
void	error(char	*error);

#endif