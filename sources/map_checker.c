/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:43:24 by hefernan          #+#    #+#             */
/*   Updated: 2022/03/14 15:03:52 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static  int map_is_rectangle(char **map_file)
{
    int i;

    i = 1;
    if (!map_file)
        return (0);
    while (map_file[i] != '\0')
    {
        if (ft_strlen(map_file[i]) != ft_strlen(map_file[0]))
            return (0);
        i++;
    }
    return (1);
}