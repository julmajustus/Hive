 #include <stdio.h>

 int main ()
 {
 	char *str = "-46844394449394946994646";

 	while (*str)
 	{
 		printf("%d\n", ft_atoi(str));
 		printf("%d\n\n", atoi(str));
 		str++;
 	}
 	return (0);
 }
