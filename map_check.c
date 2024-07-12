/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:21:47 by nfujisak          #+#    #+#             */
/*   Updated: 2024/07/12 16:37:13 by nfujisak         ###   ########.fr       */
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
static int ber_check(char *file)
{
    const char *extension = ft_strrchr(file, '.');
	if (!extension)
		return (0);
    if (!ft_strcmp(extension, ".ber"))
        return (1);
    return (0);
}


// int	extension_check(char *map)
// {
// 	char	*extension;
// 	char	*file_extension;
	
// 	extension = ".ber";
// 	file_extension = ft_strrchr(map, '.');
// 	if (!file_extension || !ft_strcmp(file_extension, ""))
// 		return (0);
		
// 	else if (ft_strnstr(file_extension, "/", ft_strlen(file_extension)))
// 		return(0);
// 	else if (!ft_strcmp(file_extension, extension))
// 		return (1);
// 	return (0);
// }

//Function to check is map rectangular - TO DO 

//Function to check if 1 exit, 1 collectible and 1 position -> nope if one is incorrect - TO DO 

//We'll do the parsing later on.
//Valid map (entry - exit
//Collectibles all accessible

//We'll deal with the memory later on as we don't know why we need to handle it for the map

//Testing functions here
int main()
{
	
	char 	*map;

	map = "ber.ber";
	if (extension_check(map) ==1)
		ft_printf("OK  %s\n", ft_strrchr(map, '.'));
	else
		ft_printf("Not ok %s\n", ft_strrchr(map, '.'));
	return (0);
}