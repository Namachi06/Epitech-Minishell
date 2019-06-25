/*
** EPITECH PROJECT, 2017
** my_str_to_int
** File description:
** 	Convert str to number
*/

int my_str_to_int(char *str)
{
	int nb = 0;
	int res = 0;
	int i = 0;

	while (str[i] != ' ' && str[i] != '\0') {
		nb = str[i] - '0';
		res *= 10;
		res += nb;
		i++;
	}
	return (res);
}
