/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:33:44 by komori            #+#    #+#             */
/*   Updated: 2026/02/24 18:43:02 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_dict(t_dict *dict)
{
	int	i;

	if (!dict)
		return ;
	i = 0;
	while (dict[i].key != NULL)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
	free(dict);
}

int	is_valid_input(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '\0')
		return (0);
	i = 0;
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			return (0);
		i++;
	}
	if (i > 39)
		return (0);
	return (1);
}

void	is_dict(int argc, char **argv, char **dict_file, char **number)
{
	if (argc == 2)
	{
		*dict_file = "numbers.dict";
		*number = argv[1];
	}
	else if (argc == 3)
	{
		*dict_file = argv[1];
		*number = argv[2];
	}
	else
	{
		write(1, "Error\n", 6);
	}
}

int	handle_display(t_dict *dict, char *number)
{
	if (ft_strcmp(number, "0") == 0)
	{
		if (!find_in_dict(dict, "0"))
			return (0);
		ft_putstr(find_in_dict(dict, "0"));
	}
	else
	{
		if (!check_number(dict, number))
			return (0);
		print_number(dict, number);
	}
	write(1, "\n", 1);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*dict_file;
	char	*number;
	t_dict	*dict;

	dict_file = 0;
	number = 0;
	if (argc < 2 || argc > 3)
		return (write(1, "Error\n", 6), 1);
	is_dict(argc, argv, &dict_file, &number);
	if (!is_valid_input(number))
		return (write(1, "Error\n", 6), 1);
	dict = parse_dict(dict_file);
	if (!dict)
		return (write(1, "Dict Error\n", 11), 1);
	while (*number == '0' && *(number + 1))
		number++;
	if (!handle_display(dict, number))
	{
		write(1, "Dict Error\n", 11);
		free_dict(dict);
		return (1);
	}
	free_dict(dict);
	return (0);
}
