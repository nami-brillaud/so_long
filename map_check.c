/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:21:47 by nfujisak          #+#    #+#             */
/*   Updated: 2024/07/15 18:41:25 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Function to open and read the map file. Create some structure for maps later on
// int	open_map(char *map)
// {
// 	int	fd;
	
// 	if (!extension_check(map)) //if map has invalid extension
// 		return (0);
// 	fd = open(map, O_RDONLY); //opening ine for a test in read only
// 	if (fd == -1)
// 		return (0);
// 	// put other stuff regarding the game later on 
// 	close(fd);
// 	return (1);
// }

int	char_count(char *line, char c)
{
	int	count;

	count = 0;
	while (*line != '\0')
	{
		if (*line++ == c)
			count++;
	}
	return (count);
}

int	in_set(char *line, char *set)
{
	int	count;

	count = 0;
	while (*line)
	{
		if (ft_strchr(set, *line))
			count++;
		line++;
	}
	if (count != (int)ft_strlen(line))
		return (NO);
	return (OK);
}

// Function to check ber extension (works for only one file at a time and works for directory/file.ber)
int	ber_check(char *file)
{
    const char *extension = ft_strrchr(file, '.');
	if (!extension)
		return (NO);
    if (!ft_strcmp(extension, ".ber"))
        return (NO);
    return (OK);
}

// //Function to check is map is rectangular and contains 1 P,C, Eusing gnl
int	rect_pce_check(char	*file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	map->rows = 0;
	map->rcdiff = 0;
	line = get_next_line(fd);
	if (!line)
		return (NO);
	while (line && ++map->rows)
	{
		if (map->rows == 1)
			map->cols = ft_strlen(line);
		else if ((int)ft_strlen(line) != map->cols)
			map->rcdiff = 1;
		map->p += char_count(line, 'P');
		map->c += char_count(line, 'C');
		map->e += char_count(line, 'E');
		map->x += char_count(line, 'X');
		ft_printf("line number %d: %s\n", map->rows, line);
		ft_printf("number of e is %d\n", map->e);
		free(line);
		line = get_next_line(fd);
	}
	if (map->rcdiff == 1 || map->p != 1 || map->c < 1 || map->e != 1)
		return (NO);
	return (OK);
}

//Questions: ERROR CODES, DOES MAP COME FROM INIT GAME, WHERE TO CLOSE, WHERE TO FREE.
// what about file opening errors
//Initial checking function

int	map_error(int n)
{
	if (n == 2)
		ft_printf("Error: Invalid file! \n");
	if (n == 3)
		ft_printf("Error: Invalid map! \n");
	return (NO);
}

int	validate_map(char *file, t_map *map)
{
	int		fd;
	int		error;
	char	*line;
	int		i;

	error = 0;
	if (!file || ber_check(file))
		error = 2;
	if (rect_pce_check(file, map))
		error = 3;
	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line && ++i) //i is rows.
	{
		if ((i == 1 || i == map->rows) && !(in_set(line, "1")))
			error = 3;
		if (line[0] != '1' || line[map->cols - 1] != '1' || !in_set(line, "10CEPX"))
			error = 3;
		free(line);
		line = get_next_line(fd);
	}
	if (error > 0)
		return (map_error(error));
	return (OK);
}
// int	validate_map(char *file)
// {
// 	if (!ber_check)
// 		//return error with error code
// 	if (!rect_pce_check)
// 		//return error with error code

// }
//remaining :
//initial function  - if surrounded by walls + if all chars are either 10CEP with in set
// error messages (where?)
// -- where should i close the file ? (btw a close fd should be before a return))
//You need a function to exit and printf errors when the map has an issue (see pdf)
// but idk the expectations of that.

//We'll do the parsing later on.
//Valid map (entry - exit
//Collectibles all accessible

//We'll deal with the memory later on as we don't know why we need to handle it for the map

/* !!!!! Testing mains are here !!!!! */
int main ()
{
	char file[] = "./maps/valid/02_test.ber";
	t_game	*game = (t_game *)malloc(sizeof(t_game)); //dont forget to allocate memory to the pointer structure !!
	
	if (!game)
	{
		ft_printf("Malloc fail \n");
		return (NO);
	}
	init_game(game);
	if (validate_map(file, &game->map) == 0)
		ft_printf("Map is valid! \n");
	free (game);
	return (OK);
}



/* ber extension check */
// int main()
// {
	
// 	char 	*map;

// 	map = "ber.ber";
// 	if (extension_check(map) ==1)
// 		ft_printf("OK  %s\n", ft_strrchr(map, '.'));
// 	else
// 		ft_printf("Not ok %s\n", ft_strrchr(map, '.'));
// 	return (0);
// }