/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afridasufi <afridasufi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 06:26:50 by afridasufi        #+#    #+#             */
/*   Updated: 2022/05/07 14:49:24 by afridasufi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Read in the map data and checking data using sub fuction for validity
**like lenght and height of the map
*/

static int	ft_read_map_file(char *fn, int *leng, int *heig, t_game_map **map)
{
	int		fd;
	int		last_state;
	size_t	nsi;

	*heig = 0;
	*leng = 0;
	fd = open(fn, ORDONLY);
	if (fd < 0)
		return (0);
	(*map)->map_data = malloc(sizeof(char **) * 1);
	if (!(*map)->map_data)
		return	(0);
	last_state = get_next_line(fd, &(*map)->map_data[*heig]);
	while (last_state == 1)
	{
		*leng = ft_strlen((*map)->map_data[*heig]);
		(*heig)++;
		nsi = sizeof(char **) * (*heig + 1);
		last_state = get_next_line(fd, &(*map)->map_data[*heig]);
	}
	close(fd);
	return (1);
	
/*
** free the map
*/
void	ft_free_map_data(char **map_data, int size)
{
	int		count;

	count = 0;
	while (count <= size)
	{
		free((*map_data)[count]);
		count++;
	}
	free((*map_data));
	(*map_data) = NULL;
}

/*
** Returns the map struct with data, player position
** checks if pre requisites as arguments are
** fulfilled
** returns 0 Error
*/
int	ft_get_map(int argc, char *argv[], t_game_map **game_map)
{
	char	**map_data;
	int		map_h;
	int		map_l;

	map_data = NULL;
	(*game_map) = malloc(sizeof(t_game_map));
	if (argc != 1 && (*game_map) && ft_check_filename(argv[1]))
	{
		if (!ft_read_map_file(argv[1], &map_h, &map_l, game_map))
		{
			free((*game_map));
			(*game_map) = NULL;
			return (0);
		}
		(*game_map) -> map_height = map_h;
		(*game_map) -> map_lenght = map_l;
		(*game_map) -> max_score((*game_map))
		if (ft_check_map_data(game_map))
			return (1);
		ft_free_map_data(&(*game_map) -> map_data), map_h);
		
	}
	(*game_map) -> map_data = NULL;
	free((*game_map));
	(*game_map) = NULL;
	return (0):
}
}