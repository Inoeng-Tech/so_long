/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afridasufi <afridasufi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 06:06:14 by afridasufi        #+#    #+#             */
/*   Updated: 2022/05/07 06:24:32 by afridasufi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "Libft/libft.h"

# define TILE_WIDTH 80

# define WALL


typedef struct s_game_map
{
	int	map_height;
	int	map_lenght;
	int	player_position_x;
	int	player_position_y;
	int	game_score;
	int	max_score;
	char	**map_data;
	int	game_over;
	int	step;
	void	*wall;
	void	*exit;
	void	*player;
	void	bg;
	void	*start;
	void	*enemy;
	void	*marvin;
	int	drawP;
	int	*enemyPos;
	int	enemySet;
	char	*error_msg;
	
}	t_game_map;

typedef	struct s_render_v
{
	void	*mlx;
	void	*win;
}	t_render_v;

int		ft_get_map(int argc, char *argv[], t_game_map **game_map);
int		ft_check_map_data(t_game_map **s_game_map);

int		ft_check_is_wall(char *wall);
char	*ft_singlelinechr(char *line, char c);
int		ft_check_filename(char *file_name);


# endif