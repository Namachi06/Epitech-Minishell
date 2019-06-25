/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** Print a number type int
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
	int int_divider = 1000000000;
	int number_to_divide = nb;
	int number_to_print;
	char digit_already_printed = 'N';

	if (number_to_divide < 0) {
		my_putchar('-');
		number_to_divide *= -1;
	}
	do {
		number_to_print = number_to_divide / int_divider;
		if (number_to_print > 0 || int_divider == 1 ||
			digit_already_printed == 'Y') {
			my_putchar(number_to_print + 48);
			digit_already_printed = 'Y';
			number_to_divide %= int_divider;
		}
		int_divider /= 10;
	} while (int_divider >= 1);
	return (0);
}
