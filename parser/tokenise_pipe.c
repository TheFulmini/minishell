/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:19:00 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/07 13:36:41 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	tokenise_pipe(t_cmd_container *cmd_container)
{
	next_cmd(cmd_container);
	cmd_container->cmds[get_cmd_size(cmd_container) - 1]->piped = 1;
}
