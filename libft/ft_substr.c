/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:40:02 by hiasano           #+#    #+#             */
/*   Updated: 2024/05/11 03:25:15 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*dest;

	i = 0;
	s_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_calloc(1, sizeof(char)));
	if (len < s_len - start)
		dest = malloc(len + 1);
	else
		dest = malloc(s_len - start + 1);
	if (dest == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main() {
//    const char *original = "Hello, world!";
//    char *substring;
//
//    //     substring = ft_substr(original, 0, 5);
//    if (substring == NULL) {
//        fprintf(stderr, "Failed to allocate memory.\n");
//        return (1);  
//    printf("Substring 1: %s\n", substring);
//    free(substring);  //
//    // "world"
//    substring = ft_substr(original, 7, 5);
//    if (substring == NULL) {
//        fprintf(stderr, "Failed to allocate memory.\n");
//        return (1);     }
//    printf("Substring 2: %s\n", substring);
//    free(substring);  
//
//    // substringを抽出："!"
//    substring = ft_substr(original, 12, 3);
//    if (substring == NULL) {
//        fprintf(stderr, "Failed to allocate memory.\n");
//        return (1);  
//    }
//    printf("Substring 3: %s\n", substring);
//    free(substring); 
//
//    return (0); 
//}
