/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:02:40 by jmakkone          #+#    #+#             */
/*   Updated: 2024/04/29 09:40:29 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Includes */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include "../libft-git/libft.h"

/* Function refrences */

/* Base functions */
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);

/* Additional functions */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* Bonus functions */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* Some needed helper functions */

char strmapi_f(unsigned int i, char str)
{
	printf("String index = %d and %c\n", i, str);
	return (0);
}

void striteri_f(unsigned int i, char *str)
{
	printf("String index = %d, content of pointer %c, pointer addr %p\n", i, *str, str);
}

void print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char*)lst->content);
		lst = lst->next;
	}
}

void del(void *content)
{
	if (content)
		free(content);
}

void *add_character(void *content)
{
	char *str = (char *)content;
	int len = ft_strlen(str);
	str[len] = '!';
	str[len + 1] = '\0';
	return content;
}

/* Testing main loop */

int	main(void)
{


	/* ########### Libc functions ############### */	
	/* ft_isalpha */
	printf("################## Test ft_isalpha ##################\n\n");
	unsigned char isalpha_char = 'o';
	unsigned char isalpha_char2 = '1';
	printf("Is '%c' an alphabetic char 1: YES 0: NO; Original isalpha(): %d\n", isalpha_char, isalpha(isalpha_char));
	printf("Is '%c' an alphabetic char 1: YES 0: NO; My ft_isalpha:      %d\n", isalpha_char, ft_isalpha(isalpha_char));
	printf("Is '%c' an alphabetic char 1: YES 0: NO; Original isalpha(): %d\n", isalpha_char2, isalpha(isalpha_char2));
	printf("Is '%c' an alphabetic char 1: YES 0: NO; My ft_isalpha:      %d\n", isalpha_char2, ft_isalpha(isalpha_char2));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	/* ft_isdigit */
	printf("################## Test ft_isdigit ##################\n\n");
	unsigned char isdigit_char = 'o';
	unsigned char isdigit_char2 = '1';
	printf("Is '%c' a digit 1: YES 0: NO; Original isdigit(): %d\n", isdigit_char, isdigit(isdigit_char));
	printf("Is '%c' a digit 1: YES 0: NO; My ft_isdigit:      %d\n", isdigit_char, ft_isdigit(isdigit_char));
	printf("Is '%c' a digit 1: YES 0: NO; Original isdigit(): %d\n", isdigit_char2, isdigit(isdigit_char2));
	printf("Is '%c' a digit 1: YES 0: NO; My ft_isdigit:      %d\n", isdigit_char2, ft_isdigit(isdigit_char2));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_isalnum ##################\n\n");
	unsigned char isalnum_char = 'o';
	unsigned char isalnum_char2 = '\0';
	printf("Is '%c' alphabetic char or a digit 1: YES 0: NO; Original isalnum(): %d\n", isalnum_char, isalnum(isalnum_char));
	printf("Is '%c' alphabetic char or a digit 1: YES 0: NO; My ft_isalnum:      %d\n", isalnum_char, ft_isalnum(isalnum_char));
	printf("Is '%c' alphabetic char or a digit 1: YES 0: NO; Original isalnum(): %d\n", isalnum_char2, isalnum(isalnum_char2));
	printf("Is '%c' alphabetic char or a digit 1: YES 0: NO; My ft_isalnum:      %d\n", isalnum_char2, ft_isalnum(isalnum_char2));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_isascii ##################\n\n");
	unsigned char isascii_char = 'o';
	unsigned char isascii_char2 = '\0';
	printf("Is '%c' part of ascii charset  1: YES 0: NO; Original isascii(): %d\n", isascii_char, isascii(isascii_char));
	printf("Is '%c' part of ascii charset  1: YES 0: NO; My ft_isascii:      %d\n", isascii_char, ft_isascii(isascii_char));
	printf("Is '%c' part of ascii charset  1: YES 0: NO; Original isascii(): %d\n", isascii_char2, isascii(isascii_char2));
	printf("Is '%c' part of ascii charset  1: YES 0: NO; My ft_isascii:      %d\n", isascii_char2, ft_isascii(isascii_char2));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_isprint ##################\n\n");
	unsigned char isprint_char = 'o';
	unsigned char isprint_char2 = '\0';
	printf("Is '%c' a printable character 1: YES 0: NO; Original isprint(): %d\n", isprint_char, isprint(isprint_char));
	printf("Is '%c' a printable character 1: YES 0: NO; My ft_isprint:      %d\n", isprint_char, ft_isprint(isprint_char));
	printf("Is '%c' a printable character 1: YES 0: NO; Original isprint(): %d\n", isprint_char2, isprint(isprint_char2));
	printf("Is '%c' a printable character 1: YES 0: NO; My ft_isprint:      %d\n", isprint_char2, ft_isprint(isprint_char2));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_strlen ##################\n\n");
	char *strlen_char = "1234";
	char *strlen_char2 = "\0";
	printf("String lenght of '%s' with Original strlen(): %zu\n", strlen_char, strlen(strlen_char));
	printf("String lenght of '%s' with My ft_strlen:      %zu\n", strlen_char, ft_strlen(strlen_char));
	printf("String lenght of '%s' with Original strlen(): %zu\n", strlen_char2, strlen(strlen_char2));
	printf("String lenght of '%s' with My ft_strlen:      %zu\n", strlen_char2, ft_strlen(strlen_char2));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_memset ##################\n\n");
	char msstr[66] = "This is memset string.h library function test string";
	char emptyteststring[66] = "thisisjustjunkdata";
	char msmystr[66] = "This is ft_memset libft.h library function test string";
	printf("%s\n", msstr);
	memset(msstr,'$',66);
	printf("After memset\n");
	printf("%s\n", msstr);
	ft_bzero(emptyteststring, 66);
	printf("%s\n", msmystr);
	ft_memset(msmystr,'$',66);
	printf("After ft_memset\n");
	printf("%s\n", msmystr);
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_bzero ##################\n\n");
	char bzstr[65];
	char bzmystr[65];
	int	bzlen1;
	int	bzlen2;
	strcpy(bzstr,"This is bzero string.h library function test string");
	puts(bzstr);
	bzlen1 = strlen(bzstr);
	printf("After bzero\n");
	bzero(bzstr,7);
	for (int i = 0; i < bzlen1; i++)
		printf("%c", bzstr[i]);
	printf("\n\n");
	strcpy(bzmystr,"This is ft_bzero libft library function test string");
	puts(bzmystr);
	bzlen2 = strlen(bzmystr);
	printf("After mybzero\n");
	ft_bzero(bzmystr,7);
	for (int i = 0; i < bzlen2; i++)
		printf("%c", bzstr[i]);
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_memcpy ##################\n\n");
	//size_t len2 = 12;
	char mcstr1[6] = "test";
	char mcstr2[] = "";
	size_t mclen = ft_strlen(mcstr1);
	int numbers[] = {1, 2, 3, 4, 5};
	int nbuf[6];
	printf("Before memcpy function Str1 is: '%s' & Str2 is: '%s'\n\n", mcstr1, mcstr2);
	memcpy(mcstr1, mcstr2, mclen);
	printf("After orig memcpy Str1 is:      '%s' & Str2 is: '%s'\n", mcstr1, mcstr2);
	ft_memcpy(mcstr1, mcstr2, mclen);
	printf("After my memcpy Str1 is:        '%s' & Str2 is: '%s'\n\n", mcstr1, mcstr2);

	for (size_t i = 0; i < 5; i++)
	{
		printf("Numbers in orig array %d\n",numbers[i]);
	}
	ft_memcpy(nbuf, numbers, 5* sizeof(int));
	for (size_t i = 0; i < 5; i++)
	{
		printf("Numbers in copy array after ft_memcpy %d\n",nbuf[i]);
	}
	memcpy(nbuf, numbers, 5* sizeof(int));
	for (size_t i = 0; i < 5; i++)
	{
		printf("Numbers in copy array after memcpy %d\n",nbuf[i]);
	}
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");


	printf("################## Test ft_memmove ##################\n\n");
	char mmdest[10] = "hello";
	const char mmsrc[10]  = "world";
	char mmdest2[10] = "hello";
	const char mmsrc2[10]  = "world";

	printf("Before orginal memmove mmdest = '%s', mmsrc = '%s'\n", mmdest, mmsrc);
	memmove(mmdest, mmsrc, 4);
	printf("After original memmove mmdest = '%s', mmsrc = '%s'\n\n\n", mmdest, mmsrc);

	printf("Before my memmove mmdest = '%s', mmsrc = '%s'\n", mmdest2, mmsrc2);
	ft_memmove(mmdest2, mmsrc2, 4);
	printf("After my memmove mmdest =  '%s', mmsrc = '%s'\n\n", mmdest2, mmsrc2);

	char mmbuf[] = "Hello, World";
	char mmbuf2[] = "Hello, World";
	printf("Content before ft_memmove of mmbuf is: '%s'\n", mmbuf);
	ft_memmove(mmbuf, mmbuf + 7, sizeof(mmbuf) - 7);
	printf("Content after ft_memmove + 7 bits is:  '%s'\n\n", mmbuf);
	printf("Content before memmove of mmbuf is: '%s'\n", mmbuf2);
	ft_memmove(mmbuf2, mmbuf2 + 7, sizeof(mmbuf2) - 7);
	printf("Content after memmove + 7 bits is:  '%s'\n", mmbuf2);

	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");


	printf("################## Test ft_strlcat ##################\n\n");
	size_t strlcat_bufsize = 11;
	char strlcat_buf1[55] = "Hello";
	char strlcat_buf2[] = "World";
	char strlcat_buf3[55] = "Hello";
	char strlcat_buf4[] = "World";

	printf("buf1 is '%s' and buf2 is '%s'\n", strlcat_buf1, strlcat_buf2);
	strlcat(strlcat_buf1, strlcat_buf2, strlcat_bufsize);
	printf("Orig strlcat return: %lu\n", strlcat(strlcat_buf1, strlcat_buf2, strlcat_bufsize));
	printf("buf1 after strlcat is '%s' and buf2 is '%s'\n\n", strlcat_buf1, strlcat_buf2);

	printf("buf1 is '%s' and buf2 is '%s'\n", strlcat_buf3, strlcat_buf4);
	ft_strlcat(strlcat_buf3, strlcat_buf4, strlcat_bufsize);
	printf("My strlcat return: %lu\n", ft_strlcat(strlcat_buf1, strlcat_buf2, strlcat_bufsize));
	printf("buf1 after my strlcat is '%s' and buf2 is '%s'\n\n", strlcat_buf3, strlcat_buf4);

	char strlcat_dest1[50] = "";
	char strlcat_dest2[50] = "";
	printf("Return value with zero strlcat_dest size my strlcat '%zu'\n", ft_strlcat(strlcat_dest1, "lorem ipsum dolor sit amet", 0));
	printf("Return value with zero strlcat_dest size orig strlcat '%zu'\n", strlcat(strlcat_dest2, "lorem ipsum dolor sit amet", 0));
	printf("\n");
	printf("Content of dest after my strlcat is:   '%s'\n",strlcat_dest1);
	printf("Content of dest after orig strlcat is: '%s'\n",strlcat_dest2);
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");


	printf("################## Test ft_toupper ##################\n\n");
	char tou_a = 'a';
	char tou_a2 = 'a';
	printf("Char a is '%c'\n", tou_a);
	printf("Char a after my toupper() is:   %c\n", ft_toupper(tou_a));
	printf("Char a is '%c'\n", tou_a2);
	printf("Char a after orig toupper() is: %c\n", toupper(tou_a2));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_tolower ##################\n\n");
	char tol_a = 'A';
	char tol_a2 = 'A';
	printf("Char a is '%c'\n", tol_a);
	printf("Char a after my tolower() is:   %c\n", ft_tolower(tol_a));
	printf("Char a is '%c'\n", tol_a2);
	printf("Char a after orig tolower() is: %c\n", tolower(tol_a2));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_strchr ##################\n\n");
	char strchr_a = 'e';
	char strchr_str[] = "Hello";
	char strchr_str2[] = "teste";
	printf("Char '%c' out of the String '%s' is found '%s'\n", strchr_a, strchr_str, ft_strchr(strchr_str, strchr_a));

	printf("Pointer addr of the find with my strchr is   '%p'\n", ft_strchr(strchr_str, strchr_a));
	printf("Pointer addr of the find with orig strchr is '%p'\n\n", strchr(strchr_str, strchr_a));

	printf("Pointer addr of the NULL character with my strchr is   '%p'\n", ft_strchr(strchr_str, '\0'));
	printf("Pointer addr of the NULL character with orig strchr is '%p'\n\n", strchr(strchr_str, '\0'));

	printf("Pointer addr of the find with my strchr is   '%p'\n", ft_strchr(strchr_str2, 't' + 256));
	printf("Pointer addr of the find with orig strchr is '%p'\n\n", strchr(strchr_str2, 't' + 256));

	printf("Pointer addr of the find with my strchr is   '%p'\n", ft_strchr("teste", 'e'));
	printf("Pointer addr of the find with orig strchr is '%p'\n\n", strchr("teste", 'e'));

	printf("Pointer addr of the find with my strchr is   '%p'\n", ft_strchr("teste", '\0'));
	printf("Pointer addr of the find with orig strchr is '%p'\n", strchr("teste", '\0'));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_strrchr ##################\n\n");
	char strrchr_a = '1';
	char strrchr_str[] = "1234561";
	printf("Char '%c' out of the String '%s' is found '%s'\n", strrchr_a, strrchr_str, ft_strrchr(strrchr_str, strrchr_a));
	printf("Pointer addr of the find with my strchr is   '%p'\n", ft_strrchr(strrchr_str, strrchr_a));
	printf("Pointer addr of the find with orig strchr is '%p'\n", strrchr(strrchr_str, strrchr_a));

	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_strncmp ##################\n\n");
	size_t strncmp_n = 3;
	char strncmp_s1[] = "test";
	char strncmp_s2[] = "teut";
	printf("Difference between strings '%s' and '%s' in decimal with my strncmp()   '%d'\n", strncmp_s1, strncmp_s2, ft_strncmp(strncmp_s1, strncmp_s2, strncmp_n));
	printf("Difference between strings '%s' and '%s' in decimal with orig strncmp() '%d'\n", strncmp_s1, strncmp_s2, strncmp(strncmp_s1, strncmp_s2, strncmp_n));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_memchr ##################\n\n");
	size_t memchr_n = 2;
	char memchr_c = 'e';
	char memchr_s1[] = "Hello";

	printf("Pointer addr with orig memchr() is '%p'\n", memchr(memchr_s1, memchr_c, memchr_n)); 
	printf("Pointer addr with my memchr() is   '%p'\n", ft_memchr(memchr_s1, memchr_c, memchr_n)); 
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_memcmp ##################\n\n");
	size_t memcmp_n = 4;
	char memcmp_s1[] = "t4st";
	char memcmp_s2[] = "test";
	printf("Difference between strings '%s' and '%s' in decimal with my memcmp()   '%d'\n", memcmp_s1, memcmp_s2, ft_memcmp(memcmp_s1, memcmp_s2, memcmp_n));
	printf("Difference between strings '%s' and '%s' in decimal with orig memcmp() '%d'\n", memcmp_s1, memcmp_s2, memcmp(memcmp_s1, memcmp_s2, memcmp_n));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_strnstr ##################\n\n");
	const char *haystack1 = "Foo Bar Baz";
	const char *needle1 = "oo";
	const char *haystack2 = "This Test is The Test ultimate Test Test Test!";
	const char *needle2 = "Test";
	const char *haystack3 = "123456789112233445566778899123456789";
	const char *needle3 = "55";

//	printf("Haystack is '%s' and the needle is '%s' return value of strnstr is    '%s'\n", haystack1, needle1, strnstr(haystack1, needle1, 2));
	printf("Haystack is '%s' and the needle is '%s' return value of ft_strnstr is '%s'\n\n", haystack1, needle1, ft_strnstr(haystack1, needle1, 2));

//	printf("Haystack is '%s' and the needle is '%s' return value of strnstr is    '%s'\n", haystack2, needle2, strnstr(haystack2, needle2, ft_strlen(haystack2)));
	printf("Haystack is '%s' and the needle is '%s' return value of ft_strnstr is '%s'\n\n", haystack2, needle2, ft_strnstr(haystack2, needle2, ft_strlen(haystack2)));

//	printf("Haystack is '%s' and the needle is '%s' return value of strnstr is    '%s'\n", haystack3, needle3, strnstr(haystack3, needle3, ft_strlen(haystack3)));
	printf("Haystack is '%s' and the needle is '%s' return value of ft_strnstr is '%s'\n\n", haystack3, needle3, ft_strnstr(haystack3, needle3, ft_strlen(haystack3)));
	char *strnstr_s1 = "oh no not the empty string !";
	char *strnstr_s2 = "";
	size_t strnstr_max = strlen(strnstr_s1);
//	printf("Orig strnstr with empty str is '%s'\n", strnstr(strnstr_s1, strnstr_s2, strnstr_max));
	printf("My strnstr with empty str is   '%s'\n\n\n", ft_strnstr(strnstr_s1, strnstr_s2, strnstr_max));

//	printf("Orig strnstr with zero len is '%s'\n", strnstr(strnstr_s1, strnstr_s2, strnstr_max));
	printf("My strnstr with zero len is   '%s'\n", ft_strnstr(strnstr_s1, strnstr_s2, strnstr_max));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_atoi ##################\n\n");
	printf("This should be a char string in numerical form with my atoi       '%d'\n", ft_atoi("   -+4334sdfbsbd12    3"));
	printf("This should be a char string in numerical form with original atoi '%d'\n", atoi("   -+4334sdfbsbd12    3"));
	printf("\n");
	printf("This should be a char string in numerical form with my atoi       '%d'\n", ft_atoi("   +4334sdfbsbd12    3"));
	printf("This should be a char string in numerical form with original atoi '%d'\n", atoi("   +4334sdfbsbd12    3"));
	printf("\n");
	printf("This should be a char string in numerical form with my atoi       '%d'\n", ft_atoi("   -4334sdfbsbd12    3"));
	printf("This should be a char string in numerical form with original atoi '%d'\n", atoi("   -4334sdfbsbd12    3"));
	printf("\n");
	printf("This should be a char string in numerical form with my atoi       '%d'\n", ft_atoi("346346363463636346346346346"));
	printf("This should be a char string in numerical form with original atoi '%d'\n", atoi("346346363463636346346346346"));
	printf("\n");
	printf("This should be a char string in numerical form with my atoi       '%d'\n", ft_atoi("-346346363463636346346346346"));
	printf("This should be a char string in numerical form with original atoi '%d'\n", atoi("-346346363463636346346346346"));
	printf("\n");
	printf("This should be a char string in numerical form with my atoi       '%d'\n", ft_atoi("99999999999999999999"));
	printf("This should be a char string in numerical form with original atoi '%d'\n", atoi("99999999999999999999"));
	printf("\n");
	printf("This should be a char string in numerical form with my atoi       '%d'\n", ft_atoi("-99999999999999999999"));
	printf("This should be a char string in numerical form with original atoi '%d'\n", atoi("-99999999999999999999"));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_calloc ##################\n\n");
	int *calloc_numbers = ft_calloc(5, sizeof(int));
	char *calloc_buffer = ft_calloc(10, sizeof(char));
	int *calloc_empty_array = ft_calloc(0, sizeof(int));

	printf("Buf content after my calloc should be zeros %ls\n", calloc_numbers);
	printf("Buf content after my calloc should be zeros %s\n", calloc_buffer);
	printf("Buf content after my calloc should be zeros %ls\n\n", calloc_empty_array);
	int *calloc_numbers2 = calloc(5, sizeof(int));
	char *calloc_buffer2 = calloc(10, sizeof(char));
	int *calloc_empty_array2 = calloc(0, sizeof(int));

	printf("Buf content after original calloc should be zeros %ls\n", calloc_numbers2);
	printf("Buf content after original calloc should be zeros %s\n", calloc_buffer2);
	printf("Buf content after original calloc should be zeros %ls\n", calloc_empty_array2);
	char *calloc_buffer3 = ft_calloc(SIZE_MAX, SIZE_MAX);
	char *calloc_buffer4 = calloc(SIZE_MAX, SIZE_MAX);
	printf("Buf content after my calloc should be NULL %s\n", calloc_buffer3);
	printf("Buf content after original calloc should be NULL %s\n", calloc_buffer4);
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_strdup ##################\n\n");
	char *strdup_str1 = "hello";
	printf("Mem addr of str1 is '%p'\n", &strdup_str1); 
	printf("Mem addr of str1 after my strdup is '%p'\n", ft_strdup(strdup_str1));

	printf("Content of str1 is '%s'\n", strdup_str1); 
	printf("Content of str1 after my strdup is '%s'\n", ft_strdup(strdup_str1));
	char *strdup_str2 = "hello";
	printf("Mem addr of str1 is '%p'\n", &strdup_str2);
	printf("Mem addr of str2 after orig strdup is '%p'\n", strdup(strdup_str2));
	printf("Content of str2 is '%s'\n", strdup_str2); 
	printf("Content of str2 after orig strdup is '%s'\n", strdup(strdup_str2));
	char *strdup_str;
	char *strdup_tmp = "I malloc so I am.";

	strdup_str = ft_strdup(strdup_tmp);
	printf("Lets see the dup '%s'\n", strdup_str);
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");



	/* ########### Additional functions ############### */	

	printf("################## Test ft_substr ##################\n\n");
	char *substr_lonkstr = "thisisquitelongstr";
	printf("This is the orig str '%s' and this is my substr() '%s'\n", substr_lonkstr, ft_substr(substr_lonkstr, 6,5));
	printf("Test when substr request is longer than source '%s'\n", ft_substr("test", 2, 3));
	printf("Test when substr len is longer than source '%s'\n", ft_substr("test", 0, 5));
	//printf("Test when substr start and len is longer than source '%s'\n", ft_substr("hola", 4294967295, 18446744073709551615));
	printf("Test when substr start and len is longer than source '%s'\n", ft_substr("hola", 2, 3));
	printf("Test when substr start and len is longer than source '%s'\n",ft_substr("hola", 2, 30));
	printf("Test when substr start and len is longer than source '%s'\n", ft_substr("hola", 3, 2));
	printf("Test when substr start and len is longer than source '%s'\n", ft_substr("hola", 4, 1));
	printf("Test when substr start and len is longer than source '%s'\n", ft_substr("hola", 4, 20));





	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_strjoin ##################\n\n");
	char *strjoin_s1 = "my favorite animal is";
	char *strjoin_s2 = " ";
	char *strjoin_s3 = "the nyancat";
	char *strjoin_tmp = ft_strjoin(strjoin_s1, strjoin_s2);
	printf("My strjoin test '%s'\n",  ft_strjoin(strjoin_tmp, strjoin_s3));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_strtrim ##################\n\n");
	char	*strtrim_s1 = "acbHello,Worldacb";
	char	*strtrim_set ="abc";

	printf("Trim '%s' out of '%s' is '%s'\n", strtrim_set, strtrim_s1, ft_strtrim(strtrim_s1, strtrim_set));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_split ##################\n\n");
	char const	*split_str = "HelloWorld";
	char		split_split = 'W';
	char		**split_splitstr;
	split_splitstr = ft_split(split_str, split_split);
	printf("String '%s' splitted with '%c' is\n'%s'\n'%s'\n",split_str , split_split, split_splitstr[0], split_splitstr[1]);
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_itoa ##################\n\n");
	printf("ItoA '%s'\n", ft_itoa(1));
	printf("ItoA '%s'\n", ft_itoa(0));
	printf("ItoA '%s'\n", ft_itoa(-0));
	printf("ItoA '%s'\n", ft_itoa(123));
	printf("ItoA '%s'\n", ft_itoa(-123));
	printf("ItoA '%s'\n", ft_itoa(INT_MIN));
	printf("ItoA '%s'\n", ft_itoa(INT_MAX));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_strmapi ##################\n\n");

	char *strmapi_str = "hello.";
	printf("The original string is '%s'\n", strmapi_str);
	ft_strmapi(strmapi_str, strmapi_f);
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_striteri ##################\n\n");
	char *striteri_str = "hello.";
	printf("The original string is' %s'\n", striteri_str);
	ft_striteri(striteri_str, striteri_f);
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_putchar_fd ##################\n\n");
	char putcharfd_character;

	putcharfd_character = 'A';
	ft_putchar_fd(putcharfd_character, 1);

	putcharfd_character = 'B';
	ft_putchar_fd(putcharfd_character, 2);

	putcharfd_character = 'C';
	int putcharfd_custom_fd = open("putcharfd_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd(putcharfd_character, putcharfd_custom_fd);
	close(putcharfd_custom_fd);
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_putstr_fd ##################\n\n");
	char *putstrfd_str = "dlrowolleh";
	ft_putstr_fd("dlrowolleh_STDOUT", 1);
	ft_putstr_fd("dlrowolleh_STDERR", 2);

	int putstrfd_custom_fd = open("putstrfd_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd(putstrfd_str, putstrfd_custom_fd);
	close(putstrfd_custom_fd);
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_putendl_fd ##################\n\n");
	char *putendlfd_str = "dlrowolleh";
	ft_putendl_fd("dlrowolleh_STDOUT", 1);
	ft_putendl_fd("dlrowolleh_STDERR", 2);

	int putendlfd_custom_fd = open("putendlfd_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd(putendlfd_str, putendlfd_custom_fd);
	close(putendlfd_custom_fd);
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_putnbr_fd ##################\n\n");
	int	putnbrfd_nbr = 12345;
	ft_putnbr_fd(1234567890, 1);
	ft_putnbr_fd(987654321, 2);

	int putnbrfd_custom_fd = open("putnbrfd_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(putnbrfd_nbr, putnbrfd_custom_fd);
	close(putnbrfd_custom_fd);
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	/* ########### BONUS functions ############### */	

	printf("################## Test ft_lstnew ##################\n\n");
	t_list *lstnew_list = NULL;
	t_list *lstnew_new_element = ft_lstnew("Hello, World!");
	ft_lstadd_back(&lstnew_list, lstnew_new_element); 
	print_list(lstnew_list); 
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_lstadd_front ##################\n\n");
	t_list *lstadd_front_lst = ft_lstnew("Hello");
	t_list *lstadd_front_new = ft_lstnew("World");
	printf("List before lstadd_front\n");
	print_list(lstadd_front_lst); 
	printf("List after lstadd_front\n");
	ft_lstadd_front(&lstadd_front_lst, lstadd_front_new);
	print_list(lstadd_front_lst); 
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_lstsize ##################\n\n");
	t_list *lstsize_lst = ft_lstnew("Hello");
	t_list *lstsize_lst1 = ft_lstnew("test1");
	ft_lstadd_front(&lstsize_lst, lstsize_lst1);
	t_list *lstsize_lst2 = ft_lstnew("test2");
	ft_lstadd_front(&lstsize_lst, lstsize_lst2);
	t_list *lstsize_new = ft_lstnew("World");
	ft_lstadd_front(&lstsize_lst, lstsize_new);
	print_list(lstsize_lst); 
	printf("List lenght via my lstsize() is: '%d'", ft_lstsize(lstsize_lst));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_lstlast ##################\n\n");
	t_list *lstlast_lst = ft_lstnew("Hello");
	t_list *lstlast_new = ft_lstnew("World");
	ft_lstadd_front(&lstlast_lst, lstlast_new);

	print_list(lstlast_lst); 
	printf("\n");
	printf("Print the last node of list\n");
	printf("\n");
	print_list(ft_lstlast(lstlast_lst)); 
	printf("List lenght via my lstsize() is: %d", ft_lstsize(lstlast_lst));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_lstadd_back ##################\n\n");
	t_list *lstadd_back_lst = ft_lstnew("Hello");
	t_list *lstadd_back_new = ft_lstnew("World");
	ft_lstadd_back(&lstadd_back_lst, lstadd_back_new);

	print_list(lstadd_back_lst); 
	printf("\n");
	printf("Print the last node of list\n");
	printf("\n");
	print_list(ft_lstlast(lstadd_back_lst)); 
	printf("List lenght via my lstsize() is: %d", ft_lstsize(lstadd_back_lst));
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_lstdelone ##################\n\n");
	// Create a linked list with some nodes
	t_list *lstdelone_lst = ft_lstnew(ft_strdup("Hello"));
	t_list *lstdelone_node1 = ft_lstnew(ft_strdup("World"));
	t_list *lstdelone_node2 = ft_lstnew(ft_strdup("Test"));
	ft_lstadd_back(&lstdelone_lst, lstdelone_node1);
	ft_lstadd_back(&lstdelone_lst, lstdelone_node2);

	// Print the initial list
	printf("Initial list:\n");
	print_list(lstdelone_lst);

	// Delete the second node using ft_lstdelone
	printf("\nDeleting node 'World':\n");
	ft_lstdelone(lstdelone_lst->next, del);
	lstdelone_lst->next = lstdelone_node2;

	// Print the updated list
	printf("\nUpdated list:\n");
	print_list(lstdelone_lst);
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_lstclear ##################\n\n");
	t_list *lstclear_lst = ft_lstnew(ft_strdup("Hello"));
	t_list *lstclear_node1 = ft_lstnew(ft_strdup("World"));
	t_list *lstclear_node2 = ft_lstnew(ft_strdup("Test"));
	ft_lstadd_back(&lstclear_lst, lstclear_node1);
	ft_lstadd_back(&lstclear_lst, lstclear_node2);

	// Print the initial list
	printf("Initial list:\n");
	print_list(lstclear_lst);

	// Clear list using ft_lstclear
	printf("\nClear the list:\n");
	ft_lstclear(&lstclear_lst, del);

	// Print the updated list
	printf("\nUpdated list:\n");
	print_list(lstclear_lst);
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_lstiter ##################\n\n");
	t_list *lstiter_lst = ft_lstnew(ft_strdup("Hello"));
	t_list *lstiter_node1 = ft_lstnew(ft_strdup("World"));
	t_list *lstiter_node2 = ft_lstnew(ft_strdup("Test"));
	ft_lstadd_back(&lstiter_lst, lstiter_node1);
	ft_lstadd_back(&lstiter_lst, lstiter_node2);

	// Print the initial list
	printf("Initial list:\n");
	print_list(lstiter_lst);

	// Clear list using ft_lstclear
	printf("\nClear the list:\n");
	ft_lstiter(lstiter_lst, del);

	// Print the updated list
	printf("\nUpdated list:\n");
	print_list(lstiter_lst);
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");

	printf("################## Test ft_lstmap ##################\n\n");
	// Create a linked list with some nodes
	t_list *lstmap_lst = ft_lstnew(ft_strdup("Hello")); 
	t_list *lstmap_node1 = ft_lstnew(ft_strdup("World"));
	t_list *lstmap_node2 = ft_lstnew(ft_strdup("Test"));
	ft_lstadd_back(&lstmap_lst, lstmap_node1);
	ft_lstadd_back(&lstmap_lst, lstmap_node2);

	// Print the initial list
	printf("Initial list:\n");
	print_list(lstmap_lst);

	// Create a new list by applying a function to each node using ft_lstmap
	printf("\nCreate a new list by applying a 'f' function to each node:\n");
	t_list *lstmap_new_lst = ft_lstmap(lstmap_lst, &add_character, &del);

	// Print the new list
	printf("\nNew list:\n");
	print_list(lstmap_new_lst);

	// Free the new list
	printf("\nFreeing the new list:\n");
	ft_lstclear(&lstmap_new_lst, del);	
	printf("\n\n");
	printf("¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n\n");
}
