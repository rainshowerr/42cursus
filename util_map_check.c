/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:53:32 by seoshin           #+#    #+#             */
/*   Updated: 2022/10/19 20:57:01 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 지도가 몇줄인지 체크하면서 직사각형 모양이 아닌지 확인!
void	map_square_check(t_game	*game)
{
	int 	fd;
	char	*line;

	fd = open("./map.ber", O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		destroy_map();
	if (line[ft_strlen(line) - 1] == '\n')
		game->col = ft_strlen(line) - 1;
	else
		game->col = ft_strlen(line);
	free(line);
	while(line)
	{
		game->row++;
		line = get_next_line(fd);
		if (line)
		{
			if (line[ft_strlen(line) - 1] == '\n' && (int)ft_strlen(line) != game->col + 1)
			{
				free(line);
				destroy_map();
			}
			else if (line[ft_strlen(line) - 1] != '\n' && (int)ft_strlen(line) != game->col)
			{
				free(line);
				destroy_map();
			}
		}
		free(line);
	}
	close(fd);
}

// 벽, 출구, 물고기, 시작지점 체크
void	map_error_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while(i < game->row)
	{
		j = 0;
		while(j < game->col)
		{
			if ((i == 0 || j == 0 || i == game->row - 1 || j == game->col - 1) && (game->map[i][j] != '1'))
				destroy_map();
			check_char(game, game->map[i][j]);
			j++;
		}
		i++;
	}
	if (game->collectible < 1 || game->exit < 1 || game->start != 1)
		destroy_map();
}

void	check_char(t_game *game, char c)
{
	if (c ==  'C')
		game->collectible++;
	else if (c == 'E')
		game->exit++;
	else if (c == 'P')
		game->start++;
	else if (c != '0' && c != '1' && c != 'K')
		destroy_map();
}

char	**read_map(t_game *game, char *fname)
{
	int		fd;
	char	*line;
	char	**map;
	int		idx;

	map_square_check(game);
	fd = open(fname, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * game->row);
	idx = 0;
	while(idx < game->row)
	{
		map[idx] = (char *)malloc(game->col + 1);
		line = get_next_line(fd);
		strcpy(map[idx], line);
		idx++;
	}
	close(fd);
	return (map);
}