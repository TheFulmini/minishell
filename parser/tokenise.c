/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 18:56:03 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/07 13:36:57 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	tokenise(t_cmd_container *cmd_container)
{
	size_t	length;

	if (!quotes_closed(cmd_container->line))
	{
		put_error("minishell", "error", "unclosed quotes");
		return (FALSE);
	}
	length = ft_strlen(cmd_container->line);
	while (cmd_container->read_index < length)
	{
		check_and_give_token(cmd_container,
			cmd_container->line[cmd_container->read_index]);
		cmd_container->read_index++;
	}
	next_token(cmd_container);
	if (cmd_container->tokens != NULL)
		next_cmd(cmd_container);
	if (!all_cmds_filled(cmd_container) || get_cmd_size(cmd_container) == 0)
	{
		destroy_cmd_container(cmd_container);
		return (FALSE);
	}
	return (TRUE);
}
