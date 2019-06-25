/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** length of string
*/

int my_strlen(char const *str)
{
	int iteration = 0;

	while (str[iteration] != '\0') {
		iteration += 1;
	}
	return (iteration);
}
