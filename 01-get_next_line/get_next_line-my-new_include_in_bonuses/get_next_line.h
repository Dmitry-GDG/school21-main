/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:43:31 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/21 08:32:16 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** Needed for malloc(), free() and write(). Also for typedef size_t and sizeof()
*/

# include <unistd.h>
# include <stdlib.h>

/*
** the max number of file descriptors available
** Find the max number of files:
** Mac: launchctl limit maxfiles
** ulimit -a
** Linux: ulimit -n
*/

# define MAX_FD 1025
# define MAX_LEN_STR 21474836

char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strchr(const char *s, int c);

#endif
