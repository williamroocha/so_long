/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:02:02 by wiferrei          #+#    #+#             */
/*   Updated: 2023/09/20 19:39:40 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexa(unsigned int nbr, long int *chr_total, int loworup)
{
	if (nbr >= 16)
		ft_puthexa(nbr / 16, chr_total, loworup);
	if (loworup)
		ft_putchar(HEX_UPPER[nbr % 16], chr_total);
	else
		ft_putchar(HEX_LOWER[nbr % 16], chr_total);
}
