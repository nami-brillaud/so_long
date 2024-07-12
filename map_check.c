/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:21:47 by nfujisak          #+#    #+#             */
/*   Updated: 2024/07/12 19:07:23 by nfujisak         ###   ########.fr       */
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

// Function to check ber extension (works for only one file at a time and works for directory/file.ber)
int	ber_check(char *file)
{
    const char *extension = ft_strrchr(file, '.');
	if (!extension)
		return (0);
    if (!ft_strcmp(extension, ".ber"))
        return (1);
    return (0);
}

// //Function to check is map is rectangular using gnl
int	rectangular_check(char	*file)
{
	int		fd;
	char	*line;
	t_map	map;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	map.rcdiff = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line && ++i)
	{
		if (i == 1)
			map.columns = ft_strlen(line);
		else if ((int)ft_strlen(line) != map.columns)
			map.rcdiff = 1;
		ft_printf("map columns %d\n", map.columns);
		ft_printf("line length %d\n", ft_strlen(line));
		free(line); //grouping the free
		line = get_next_line(fd);
	}
	if (map.rcdiff == 1)
		return (0);
	return (1);
}


// my old code
// 	line = get_next_line(fd);
// 	if (!line)
// 		return (0);
// 	i = 1;
// 	map.width = ft_strlen(line);
// 	while (line)
// 	{
// 		if (map.width != (int)ft_strlen(line))
// 		{
// 			free(line);
// 			ft_printf("map width is %d\n", map.width);
// 			ft_printf("current line length is is %d\n", (int)ft_strlen(line));
// 			return (0);
// 		}
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 		ft_printf("i is %d\n", i);
// 	}
// 	return (1);
// }

// int	ecp_check(char *file) to do here, its the same logic 
// where should i close the file ? (btw a close fd should be before a return !!)

// you need to check somewhere if there are more or equal than 3 rows (or else its not a rectangle)

//Function to check if 1 exit, 1 collectible and 1 position -> nope if one is incorrect - TO DO 

//You need a function to exit and printf errors when the map has an issue (see pdf). use perror and sterror

//We'll do the parsing later on.
//Valid map (entry - exit
//Collectibles all accessible

//We'll deal with the memory later on as we don't know why we need to handle it for the map

/* !!!!! Testing mains are here !!!!! */
int main ()
{
	char *map = "./maps/valid/02_test.ber";
	if (!rectangular_check(map))
		ft_printf("Map invalid\n");
	else
		ft_printf("Map is totally valid \n");
	return (0);
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