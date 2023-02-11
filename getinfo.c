#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);

																					if (info->argv)

																									{

																														info->argv[0] = _strdup(info->arg);

																																		info->argv[1] = NULL;

																																					}

																							}

													for (i = 0; info->argv && info->argv[i]; i++)

																	;

															info->argc = i;



																	replace_alias(info);

																			replace_vars(info);

																				}

}



/**
 *
 *  * free_info - frees info_t struct fields
 *
 *   * @info: struct address
 *
 *    * @all: true if freeing all fields
 *
 *     */

void free_info(info_t *info, int all)

{

		ffree(info->argv);

			info->argv = NULL;

				info->path = NULL;

					if (all)

							{

										if (!info->cmd_buf)

														free(info->arg);

												if (info->env)

																free_list(&(info->env));

														if (info->history)

																		free_list(&(info->history));

																if (info->alias)

																				free_list(&(info->alias));

																		ffree(info->environ);

																					info->environ = NULL;

																							bfree((void **)info->cmd_buf);

																									if (info->readfd > 2)

																													close(info->readfd);

																											_putchar(BUF_FLUSH);

																												}

}


