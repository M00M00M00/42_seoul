/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:34:30 by mukim             #+#    #+#             */
/*   Updated: 2022/02/16 15:34:14 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# define EVEN(X) X % 2 == 0

typedef enum _bool
{
	FALSE = 0,
	TRUE = 1
}t_bool;

# define	EVEN_MSG "I have an even number of arguments."
# define	ODD_MSG "I have an odd number of arguments."
# define SUCCESS 1
#endif
