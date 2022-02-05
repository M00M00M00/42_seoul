/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:13:02 by mukim             #+#    #+#             */
/*   Updated: 2022/02/03 16:46:39 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_print_alphabet(void)
{
	char	a;

	a = 'a';
	while (1)
	{
		write(1, &a, 1);
		a++;
		if (a > 'z')
			break ;
	}
}