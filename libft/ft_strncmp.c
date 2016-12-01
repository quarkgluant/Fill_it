/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:50:20 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/20 21:30:13 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				k;
	unsigned int	j;

	k = 0;
	j = 1;
	if (n == 0)
		return (0);
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2 && j < n)
	{
		s1++;
		s2++;
		j++;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
