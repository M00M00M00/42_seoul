/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:24:20 by mukim             #+#    #+#             */
/*   Updated: 2022/03/24 13:51:03 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char   *n_s1;
    unsigned char   *n_s2;
    int             i;
    
    n_s1 = (unsigned char *) s1;
    n_s2 = (unsigned char *) s2;
    i = 0;
	while (i < n && (*n_s1 != '\0' || *n_s2 != '\0'))
	{
		if (*n_s1 != *n_s2)
			return (*n_s1 - *n_s2);
		n_s1++;
		n_s2++;
		i++;
	}
	if (i == n)
	    return (0);
	return (*n_s1 - *n_s2);
}
