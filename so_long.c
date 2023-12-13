/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:06:50 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/13 16:45:25 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    void *mlx_ptr;

    mlx_ptr = mlx_init();
    ft_printf("Inicialized\n");
    if (mlx_ptr == NULL)
        return (1);

    mlx_destroy_display(mlx_ptr);
    ft_printf("Destroyed\n");
    free(mlx_ptr);
    ft_printf("Free\n");
}