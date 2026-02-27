/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:19:52 by komori            #+#    #+#             */
/*   Updated: 2026/02/22 21:11:03 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dict
{
	char	*key;
	char	*value;
}			t_dict;

int			print_unit_check(t_dict *dict, int magnitude);
int			check_3_digits(t_dict *dict, char *str);
int			check_number(t_dict *dict, char *number);

int			ft_strlen(char *str);
void		ft_putstr(char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strndup(char *src, int n);

int			print_1_digit(t_dict *dict, char c);
int			print_2_digits(t_dict *dict, char *str);
int			print_3_digits(t_dict *dict, char *str);
int			print_rest(t_dict *dict, char *number, int magnitude);
int			print_number(t_dict *dict, char *number);

char		*find_in_dict(t_dict *dict, char *number);
int			print_unit(t_dict *dict, int magnitude);

void		free_dict(t_dict *dict);
int			is_valid_input(char *number);
void		is_dict(int argc, char **argv, char **dict_file, char **number);
int			handle_display(t_dict *dict, char *number);

int			is_digit(char c);
int			is_valid_dict(int *has, char c);
char		*ft_strdup(char *src);
int			get_next_line(int fd, char *line);

int			count_entries(char *path);
int			set_entry(t_dict *entry, char *line);
t_dict		*parse_dict(char *file_path);

#endif
