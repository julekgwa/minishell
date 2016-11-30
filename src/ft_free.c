#include "minishell.h"

void	freecopy(char **copy)
{
	int	i;

	i = 0;
	while (copy[i])
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}

void	freesplit( char **split )
{
	free(split[0]);
	free(split);
}

void	ft_free_str(char *str, char *join)
{
	free(str);
	free(join);
}