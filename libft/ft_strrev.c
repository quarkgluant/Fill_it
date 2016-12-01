/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 15:46:04 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/17 15:47:16 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		len;
	char	tmp;
	int		i;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	while (i < len / 2)
	{
		tmp = str[len - (i + 1)];
		str[len - (i + 1)] = str[i];
		str[i] = tmp;
		i++;
	}
	return (str);
}
