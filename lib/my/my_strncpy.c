/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** copy with n characters
*/

char *my_strncpy(char *dest, char const *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++) {
		dest[i] = src[i];
	}
	for (; i < n; i++) {
		dest[i] = '\0';
	}
	return (dest);
}
