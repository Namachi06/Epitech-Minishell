/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** 	Convert an integer to a string
*/

int my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != 0) {
		i++;
	}
	return (i);
}

int my_getnbr(char const *str)
{
	int length = my_strlen(str);
	int result = 0;
	int number;
	char found_number = 0;
	char negative_number = 0;

	for (int i = 0; i < length; i++) {
		number = str[i] - 48;
		if (number >= 0 && number <= 9) {
			found_number = 1;
			if (result == 0 && i > 0 && str[i - 1] == '-') {
				negative_number = 1;
			}
			if (result * 10l > 2147483647) {
				result = 0;
				break;
			}
			result = (result * 10) + number;
		} else if (found_number == 1) {
			break;
		}
	}
	return (negative_number == 1 ? result * -1 : result);
}
