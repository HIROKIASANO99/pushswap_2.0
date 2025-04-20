/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:37:52 by hiasano           #+#    #+#             */
/*   Updated: 2025/04/14 18:59:56 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_str(char const *s, char c)
{
	int	i;
	int	count_str;

	i = 0;
	count_str = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count_str++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count_str);
}

static int	ft_count_char(char *org_str, char c, char **res_char)
{
	int	i;
	int	start;
	int	end;

	start = 0;
	end = 0;
	i = 0;
	if (!org_str && !res_char)
		return (0);
	while (org_str[i] == c && org_str[i])
	{
		start++;
		i++;
	}
	end = start;
	while (org_str[i] != c && org_str[i])
	{
		end++;
		i++;
	}
	*res_char = (char *)malloc(end - start + 1);
	if (res_char == NULL)
		return (0);
	return (end);
}

static void	add_char_to_string(char *ss, char **result, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (ss[i] == c)
		i++;
	while (ss[i])
	{
		k = 0;
		while (ss[i] && ss[i] != c)
			result[j][k++] = ss[i++];
		result[j++][k] = '\0';
		if (!ss[i])
			break ;
		while (ss[i] == c)
			i++;
	}
	result[j] = NULL;
}

char	**result_free(char const *s, char c, char **result, int count_str)
{
	int	i;
	int	n_str;

	i = 0;
	n_str = 0;
	result = (char **)malloc((count_str + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (i < count_str)
	{
		n_str = n_str + ft_count_char((char *)s + n_str, c, &result[i]);
		if (result[i] == NULL)
		{
			while (--i >= 0)
				free(result[i]);
			free(result);
		}
		i++;
	}
	add_char_to_string((char *)s, result, c);
	return (result);
}

char	**ft_split(char const *s, char c ,int *get_count_str)
{
	int		count_str;
	char	**result;
	char	**buf;

	result = NULL;
	if (!s)
		return (NULL);
	if (*s == '\0')
	{
		buf = (char **)malloc(sizeof(char *) * 1);
		buf[0] = NULL;
		return (buf);
	}
	count_str = ft_count_str((char *)s, c);
	*get_count_str = count_str;
	return (result_free(s, c, result, count_str));
}
/*
int	main(int argc, char **argv)
{
	const char	s[] = "";
	char		c;
	char		**result;
	char		*str;
	char		set;
	char		**ret;
	int			i;

	c = ' ';
	result=ft_split(s ,c);
	printf("%s\n",result[0]);
	printf("%s\n",result[1]);
	printf("%s\n",result[2]);
	printf("%s\n",result[3]);
		return(0);
	str = argv[1];
	set = argv[2][0];
	ret = ft_split(str, set);
	i = 0;
	printf("size: %d\n", ft_count_str(str, set));
	while (ret[i])
	{
		printf("%s\n", ret[i]);
		i++;
	}
	printf("%s\n", ret[i]);
}
*/
