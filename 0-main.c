#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	_printf("	Let's try to printf a simple sentence.\n");
	printf("Let's try to printf a simple sentence.\n");
	_printf("	Character:[%c]\n", 'H');
	_printf("	Character:[%c]\n", 'h');
	_printf("	Character:[%c]\n", '5');
	_printf("	Character:[%c]\n", '\0');
	_printf("	Character:[%c]\n");
	printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'h');
	printf("Character:[%c]\n", '5');
	printf("Character:[%c]\n", '\0');
	_printf("	String:[%s]\n", "I am a string !");
	_printf("	String:[%s]\n", "");
	printf("String:[%s]\n", "");
	_printf("	Percent:[%%]\n");
	printf("Percent:[%%]\n");
	_printf("	Unknown:[%r]\n");
	_printf("	Unknown:[%1]\n");
	_printf("	Unknown:[%-1]\n");
	_printf("	Unknown:[%a]\n");
	_printf("	Unknown:[%J]\n");
	_printf("	Unknown:[%Z]\n");
	_printf("	Unknown:[%;]\n");
	printf("Unknown:[%m]\n");
	return (0);
}
