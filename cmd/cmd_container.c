/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_container.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:11:15 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/07 13:34:09 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_container(t_cmd_container *cmd_container)
{
	cmd_container->line = NULL;
	cmd_container->read_index = 0;
	cmd_container->cmds = NULL;
	cmd_container->token = NULL;
	cmd_container->tokens = NULL;
}

void	*destroy_cmd_container(t_cmd_container *cmd_container)
{
	size_t	i;

	if (cmd_container != NULL)
	{
		free(cmd_container->line);
		cmd_container->line = NULL;
		cmd_container->read_index = 0;
		i = 0;
		while (i < get_cmd_size(cmd_container))
		{
			destroy_cmd(cmd_container->cmds[i]);
			i++;
		}
		free(cmd_container->cmds);
		cmd_container->cmds = NULL;
		cmd_container->tokens = ft_destroy_strarray(&cmd_container->tokens);
		free(cmd_container->token);
		cmd_container->token = NULL;
	}
	return (NULL);
}
