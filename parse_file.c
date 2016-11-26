/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <pcadiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:26:21 by pcadiot           #+#    #+#             */
/*   Updated: 2016/11/23 15:26:25 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_list		*parse_file(char *path)
{
	t_list	*begin_list;
	int		pos;
	int		fd;
	char	car;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(-1);
	read(fd, &car, 1);
	begin_list = ft_create_elem(car);
	while ((pos = read(fd, &car, 1)))
	{
		ft_list_push_back(begin_list, car);
	}
	return (begin_list);
}

