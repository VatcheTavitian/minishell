/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:27:24 by apanikov          #+#    #+#             */
/*   Updated: 2023/08/29 18:38:54 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_env_list_size(t_mhstruct *mh)
{
	int		i;
	t_env	*tmp;

	tmp = mh->env;
	i = 0;
	if (!mh->env)
		return (0);
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char	**get_env_array(t_mhstruct *mh)
{
	char	**out;
	int		i;
	t_env	*current_env;
	char	*tmp;

	tmp = NULL;
	current_env = mh->env;
	i = get_env_list_size(mh);
	out = (char **)malloc((i + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	i = 0;
	while (current_env != NULL)
	{
		tmp = ft_strdup(current_env->name);
		out[i] = ft_mhjoin(tmp, "=");
		tmp = ft_strdup(out[i]);
		free(out[i]);
		out[i] = ft_mhjoin(tmp, current_env->data);
		current_env = current_env->next;
		i++;
	}
	out[i] = NULL;
	return (out);
}

void	builtin_env(t_mhstruct *mh)
{
	t_env	*curr;

	curr = mh->env;
	while (curr != NULL)
	{
		if (curr->data != NULL)
		{
			printf("%s=", curr->name);
			printf("%s\n", curr->data);
		}
		curr = curr->next;
	}
}
