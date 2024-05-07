/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:34:09 by jmakkone          #+#    #+#             */
/*   Updated: 2024/05/07 19:34:12 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* printf example */
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	void *ptr = NULL;
   printf ("Characters: %c %c \n", 'a', 65);
   printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %010d \n", 1977);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick: %*d \n", 5, 10);
   printf ("%s \n", "A string");

   printf ("%s \n", "############################## My printf ##############################");
   ft_printf ("Characters: %c %c \n", 'a', 65);
   ft_printf ("Strings: %s%c%s \n", "Hello", ' ', "World");
   ft_printf ("Digits: %d%d%d \n", 1, 33, 7);
   ft_printf ("Digits: %% \n");
   ft_printf ("Digits: %x%X \n", 42, 42);
   
   printf("\n\n");
   ft_printf("Return value check for strings. Should be %d, is %d\n", printf ("Strings: %s%c%s \n", "Hello", ' ', "World"), ft_printf ("Strings: %s%c%s \n", "Hello", ' ', "World"));
   printf("\n\n");
   ft_printf("Return value check for strings. Should be %d, is %d\n", printf ("Strings: %s%c%c%d%s \n", "Hello", ' ', ' ', 1, "World"), ft_printf ("Strings: %s%c%c%d%s \n", "Hello", ' ', ' ', 1, "World"));
   printf("\n\n");
   printf("Return value check for numbers. Original return value is %d\n", printf ("Digits: %d%d%d \n", 1, 33, 7));
   printf("Return value check for numbers. Ftprintf return value is %d\n", ft_printf ("Digits: %d%d%d \n", 1, 33, 7));

   printf("\n\n");
   ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("Digits: %d\n", 1234567));
   ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("Digits: %d\n", 1234567));
   printf("\n\n");
   ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%d\n", 1));
   ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%d\n", 1));
   printf("\n\n");
   ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%d%d\n", 1, 1));
   ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%d%d\n", 1, 1));
   printf("\n\n");
   ft_printf("Return value check for char. Original return value is '%d'\n", printf ("%c%c\n", 'a', 'a'));
   ft_printf("Return value check for char. Ftprintf return value is '%d'\n", ft_printf ("%c%c\n", 'a', 'a'));
   printf("\n\n");
   ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%x%x\n", 111111111, 111));
   ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%x%x\n", 111111111, 111));
   printf("\n\n");
   ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%X%X\n", -111111111, -111));
   ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%X%X\n", -111111111, -111));
   printf("\n\n");
   printf("Return value check for numbers. Original return value is '%d'\n", printf ("%u\n", 1));
   printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%u\n", 1));
   printf("\n\n");
   ft_printf("Return value check for &ptr addr. Original return value is '%d'\n", printf ("%p\n", &ptr));
   ft_printf("Return value check for &ptr addr. Ftprintf return value is '%d'\n", ft_printf ("%p\n", &ptr));
   printf("\n\n");
   ft_printf("Return value check for ptr addr. Original return value is '%d'\n", printf ("%p\n", ptr));
   ft_printf("Return value check for ptr addr. Ftprintf return value is '%d'\n", ft_printf ("%p\n", ptr));
   printf("\n\n");
   ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%i\n", -011));
   ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%i\n", -011));
   printf("\n\n");
   ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%i\n", -011));
   ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%i\n", -011));
  // printf("\n\n");
  // ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%5%"));
  // printf("\n\n");
  // ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%5%"));
  // printf("\n\n");
  // ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%10%"));
  // printf("\n\n");
  // ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%10%"));
   printf("\n\n");
   ft_printf("Return value check for numbers. Original return value is '%d'\n", printf ("%s\n", (char *)NULL));
   printf("\n\n");
   ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf ("%s\n", (char *)NULL));
   printf("\n\n");
   ft_printf("Return value check for numbers. Original return value is '%d'\n", printf("\001\002\007\v\010\f\r\n"));
   ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf("\001\002\007\v\010\f\r\n"));
   printf("\n\n");
   ft_printf("Return value check for numbers. Original return value is '%d'\n", printf("%%\n"));
   ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n", ft_printf("%%\n"));
   printf("\n\n");
   ft_printf("Return value check for numbers. Original return value is '%d'\n",  printf(" %c\n", 'x'));
   ft_printf("Return value check for numbers. Ftprintf return value is '%d'\n",  ft_printf(" %c\n", 'x'));
   printf("\n\n");
   ft_printf("Return value check for ptr addr and null char. Original return value is '%d'\n", printf ("%p\n", (char *)NULL));
   ft_printf("Return value check for ptr addr and null char. Ftprintf return value is '%d'\n", ft_printf ("%p\n", (char *)NULL));
   return 0;
}
