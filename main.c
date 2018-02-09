#include "print.h"
#include <unistd.h>
#include <locale.h>
#include <limits.h>

int main()
{
	//char	str[] = "hhh";
	//printf("stan %-10.6d\n", -123);
	//ft_printf("mymy %-10.6d\n", -123);
	//setlocale(LC_ALL, "");


	//printf("SIZES %d\n", printf("stan %#.3o\n", 1));
	//printf("SIZEM %d\n", ft_printf("mymy %#.3o\n", 1));


	//printf("SIZES %d\n", printf("stan %.4S\n", NULL));
	//printf("SIZEM %d\n", ft_printf("mymy %.4S\n", NULL));
	//printf("SIZES %d\n", printf("stan %.4S\n", L"我是一只猫。"));
	//printf("SIZEM %d\n", ft_printf("mymy %.4S\n", L"我是一只猫。"));
	//printf("SIZES2 %d\n", printf("stan %d %d %d %d gg!\n", 1, -2, 33, 42, 0));
	//printf("SIZEM2 %d\n", ft_printf("mymy %d %d %d %d gg!\n", 1, -2, 33, 42, 0));
	//printf("%*20d", 5, 23);



	//printf("SIZES %d\n", printf("stan {%05.*d}\n", -15, 42));
	//printf("SIZEM %d\n", ft_printf("mymy {%05.*d}\n", -15, 42));


	//printf("SIZES %d\n", printf("stan {%-13.6d}\n", 20));
	printf("SIZEM %d\n", ft_printf("mymy {red}%-13.6d\n{reset} hello {blue}%s{green}\n", 20, "here"));
	
	//printf("mymy %*20d\n", 5, 256);
	//printf("ret: %d\n", printf("stan %U\n", ULONG_MAX));
	//printf("ret: %d\n", ft_printf("mymy %U\n", ULONG_MAX));
	//printf("%#.X\n", 0);
	//printf("stan2 %d\n", printf("stan2 @moulitest: %.x %.0x\n", 0, 0));
	//printf("mymy2 %d\n", ft_printf("mymy2 @moulitest: %.x %.0x\n", 0, 0));
	//printf("stan3 %+020d\n", 123);
	//printf("hey %30s\n",  str);
	//ft_printf("hey %30s\n", str);
	//printf("%s\n", ft_realloc_cat("world", "hello"));
	return (1);
}


