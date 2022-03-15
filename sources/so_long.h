/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:34:53 by hefernan          #+#    #+#             */
/*   Updated: 2022/03/14 16:23:40 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_game
{
    void *mlx;
    void *mlx_win;
    char **map;
}              t_game;


char    **map_reader(char *map_file);



#endif