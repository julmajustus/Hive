/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:24:49 by corellan          #+#    #+#             */
/*   Updated: 2024/04/17 09:19:58 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <errno.h>
#include <limits.h>
#include <cstdlib>
extern "C"
{
	#define new testi
	#include "libft.h"
	#undef testi
}

int	main(void)
{
	int			n_atoi;
	int 		n_ft_atoi;
	long		n_strtol;
	int			n_strtol_t;
	int			errno_val;
	std::string	number;

	number.clear();
	std::cout << "TESTING POSITIVE NUMBERS" << std::endl;
	for (size_t i = 0; i < 200; i++)
	{
		if (!i)
			number.append("+1");
		else
			number.push_back('0');
		errno = 0;
		n_atoi = atoi(number.data());
		errno_val = errno;
		n_ft_atoi = ft_atoi(number.data());
		n_strtol = strtol(number.data(), (char **)NULL, 10);
		n_strtol_t = (int)strtol(number.data(), (char **)NULL, 10);
		std::cout << "cycle " << i << ": atoi: " << n_atoi << ", ft_atoi: " << n_ft_atoi << ", strtol: " << n_strtol << ", (int)strtol: " << n_strtol_t << ", errno: " << errno_val << ".";
		if (n_atoi == n_ft_atoi)
			std::cout << "\033[0;32m" << "OK";
		else
			std::cout << "\033[0;31m" << "KO";
		std::cout << "\033[0m" << "." << std::endl;
		usleep(50000);
	}
	number.clear();
	std::cout << "TESTING NEGATIVE NUMBERS" << std::endl;
	for (size_t i = 0; i < 200; i++)
	{
		if (!i)
			number.append("-1");
		else
			number.push_back('0');
		errno = 0;
		n_atoi = atoi(number.data());
		errno_val = errno;
		n_ft_atoi = ft_atoi(number.data());
		n_strtol = strtol(number.data(), (char **)NULL, 10);
		n_strtol_t = (int)strtol(number.data(), (char **)NULL, 10);
		std::cout << "cycle " << i << ": atoi: " << n_atoi << ", ft_atoi: " << n_ft_atoi << ", strtol: " << n_strtol << ", (int)strtol: " << n_strtol_t << ", errno: " << errno_val << ".";
		if (n_atoi == n_ft_atoi)
			std::cout << "\033[0;32m" << "OK";
		else
			std::cout << "\033[0;31m" << "KO";
		std::cout << "\033[0m" << "." << std::endl;
		usleep(50000);
	}
	number.clear();
	std::cout << "Testing not well written numbers" << std::endl;
	number.append("+ 10");
	errno = 0;
	n_atoi = atoi(number.data());
	errno_val = errno;
	n_ft_atoi = ft_atoi(number.data());
	n_strtol = strtol(number.data(), (char **)NULL, 10);
	n_strtol_t = (int)strtol(number.data(), (char **)NULL, 10);
	std::cout << "STR: " << number << std::endl;
	std::cout << "cycle " << 1 << ": atoi: " << n_atoi << ", ft_atoi: " << n_ft_atoi << ", strtol: " << n_strtol << ", (int)strtol: " << n_strtol_t << ", errno: " << errno_val << ".";
	if (n_atoi == n_ft_atoi)
		std::cout << "\033[0;32m" << "OK";
	else
		std::cout << "\033[0;31m" << "KO";
	std::cout << "\033[0m" << "." << std::endl;
	usleep(50000);
	number.clear();
	number.append("+1 0");
	errno = 0;
	n_atoi = atoi(number.data());
	errno_val = errno;
	n_ft_atoi = ft_atoi(number.data());
	n_strtol = strtol(number.data(), (char **)NULL, 10);
	n_strtol_t = (int)strtol(number.data(), (char **)NULL, 10);
	std::cout << "STR: " << number << std::endl;
	std::cout << "cycle " << 2 << ": atoi: " << n_atoi << ", ft_atoi: " << n_ft_atoi << ", strtol: " << n_strtol << ", (int)strtol: " << n_strtol_t << ", errno: " << errno_val << ".";
	if (n_atoi == n_ft_atoi)
		std::cout << "\033[0;32m" << "OK";
	else
		std::cout << "\033[0;31m" << "KO";
	std::cout << "\033[0m" << "." << std::endl;
	usleep(50000);
	number.clear();
	number.append(" +1a0");
	errno = 0;
	n_atoi = atoi(number.data());
	errno_val = errno;
	n_ft_atoi = ft_atoi(number.data());
	n_strtol = strtol(number.data(), (char **)NULL, 10);
	n_strtol_t = (int)strtol(number.data(), (char **)NULL, 10);
	std::cout << "STR: " << number << std::endl;
	std::cout << "cycle " << 3 << ": atoi: " << n_atoi << ", ft_atoi: " << n_ft_atoi << ", strtol: " << n_strtol << ", (int)strtol: " << n_strtol_t << ", errno: " << errno_val << ".";
	if (n_atoi == n_ft_atoi)
		std::cout << "\033[0;32m" << "OK";
	else
		std::cout << "\033[0;31m" << "KO";
	std::cout << "\033[0m" << "." << std::endl;
	usleep(50000);
	number.clear();
	number.append(std::to_string(INT_MAX));
	errno = 0;
	n_atoi = atoi(number.data());
	errno_val = errno;
	n_ft_atoi = ft_atoi(number.data());
	n_strtol = strtol(number.data(), (char **)NULL, 10);
	n_strtol_t = (int)strtol(number.data(), (char **)NULL, 10);
	std::cout << "STR: " << "INT_MAX" << std::endl;
	std::cout << "cycle " << 4 << ": atoi: " << n_atoi << ", ft_atoi: " << n_ft_atoi << ", strtol: " << n_strtol << ", (int)strtol: " << n_strtol_t << ", errno: " << errno_val << ".";
	if (n_atoi == n_ft_atoi)
		std::cout << "\033[0;32m" << "OK";
	else
		std::cout << "\033[0;31m" << "KO";
	std::cout << "\033[0m" << "." << std::endl;
	usleep(50000);
	number.clear();
	number.append(std::to_string(INT_MAX + 1));
	errno = 0;
	n_atoi = atoi(number.data());
	errno_val = errno;
	n_ft_atoi = ft_atoi(number.data());
	n_strtol = strtol(number.data(), (char **)NULL, 10);
	n_strtol_t = (int)strtol(number.data(), (char **)NULL, 10);
	std::cout << "STR: " << "INT_MAX + 1" << std::endl;
	std::cout << "cycle " << 5 << ": atoi: " << n_atoi << ", ft_atoi: " << n_ft_atoi << ", strtol: " << n_strtol << ", (int)strtol: " << n_strtol_t << ", errno: " << errno_val << ".";
	if (n_atoi == n_ft_atoi)
		std::cout << "\033[0;32m" << "OK";
	else
		std::cout << "\033[0;31m" << "KO";
	std::cout << "\033[0m" << "." << std::endl;
	usleep(50000);
	number.clear();
	number.append(std::to_string(INT_MIN));
	errno = 0;
	n_atoi = atoi(number.data());
	errno_val = errno;
	n_ft_atoi = ft_atoi(number.data());
	n_strtol = strtol(number.data(), (char **)NULL, 10);
	n_strtol_t = (int)strtol(number.data(), (char **)NULL, 10);
	std::cout << "STR: " << "INT_MIN" << std::endl;
	std::cout << "cycle " << 6 << ": atoi: " << n_atoi << ", ft_atoi: " << n_ft_atoi << ", strtol: " << n_strtol << ", (int)strtol: " << n_strtol_t << ", errno: " << errno_val << ".";
	if (n_atoi == n_ft_atoi)
		std::cout << "\033[0;32m" << "OK";
	else
		std::cout << "\033[0;31m" << "KO";
	std::cout << "\033[0m" << "." << std::endl;
	usleep(50000);
	number.clear();
	number.append(std::to_string(INT_MIN - 1));
	errno = 0;
	n_atoi = atoi(number.data());
	errno_val = errno;
	n_ft_atoi = ft_atoi(number.data());
	n_strtol = strtol(number.data(), (char **)NULL, 10);
	n_strtol_t = (int)strtol(number.data(), (char **)NULL, 10);
	std::cout << "STR: " << "INT_MIN - 1" << std::endl;
	std::cout << "cycle " << 7 << ": atoi: " << n_atoi << ", ft_atoi: " << n_ft_atoi << ", strtol: " << n_strtol << ", (int)strtol: " << n_strtol_t << ", errno: " << errno_val << ".";
	if (n_atoi == n_ft_atoi)
		std::cout << "\033[0;32m" << "OK";
	else
		std::cout << "\033[0;31m" << "KO";
	std::cout << "\033[0m" << "." << std::endl;
	usleep(50000);
	number.clear();
	number.append(std::to_string(LONG_MAX));
	errno = 0;
	n_atoi = atoi(number.data());
	errno_val = errno;
	n_ft_atoi = ft_atoi(number.data());
	n_strtol = strtol(number.data(), (char **)NULL, 10);
	n_strtol_t = (int)strtol(number.data(), (char **)NULL, 10);
	std::cout << "STR: " << "LONG_MAX" << std::endl;
	std::cout << "cycle " << 8 << ": atoi: " << n_atoi << ", ft_atoi: " << n_ft_atoi << ", strtol: " << n_strtol << ", (int)strtol: " << n_strtol_t << ", errno: " << errno_val << ".";
	if (n_atoi == n_ft_atoi)
		std::cout << "\033[0;32m" << "OK";
	else
		std::cout << "\033[0;31m" << "KO";
	std::cout << "\033[0m" << "." << std::endl;
	usleep(50000);
	number.clear();
	number.append(std::to_string(LONG_MAX + 1));
	errno = 0;
	n_atoi = atoi(number.data());
	errno_val = errno;
	n_ft_atoi = ft_atoi(number.data());
	n_strtol = strtol(number.data(), (char **)NULL, 10);
	n_strtol_t = (int)strtol(number.data(), (char **)NULL, 10);
	std::cout << "STR: " << "LONG_MAX + 1" << std::endl;
	std::cout << "cycle " << 9 << ": atoi: " << n_atoi << ", ft_atoi: " << n_ft_atoi << ", strtol: " << n_strtol << ", (int)strtol: " << n_strtol_t << ", errno: " << errno_val << ".";
	if (n_atoi == n_ft_atoi)
		std::cout << "\033[0;32m" << "OK";
	else
		std::cout << "\033[0;31m" << "KO";
	std::cout << "\033[0m" << "." << std::endl;
	usleep(50000);
	number.clear();
	number.append(std::to_string(LONG_MIN));
	errno = 0;
	n_atoi = atoi(number.data());
	errno_val = errno;
	n_ft_atoi = ft_atoi(number.data());
	n_strtol = strtol(number.data(), (char **)NULL, 10);
	n_strtol_t = (int)strtol(number.data(), (char **)NULL, 10);
	std::cout << "STR: " << "LONG_MIN" << std::endl;
	std::cout << "cycle " << 10 << ": atoi: " << n_atoi << ", ft_atoi: " << n_ft_atoi << ", strtol: " << n_strtol << ", (int)strtol: " << n_strtol_t << ", errno: " << errno_val << ".";
	if (n_atoi == n_ft_atoi)
		std::cout << "\033[0;32m" << "OK";
	else
		std::cout << "\033[0;31m" << "KO";
	std::cout << "\033[0m" << "." << std::endl;
	usleep(50000);
	number.clear();
	number.append(std::to_string(LONG_MIN - 1));
	errno = 0;
	n_atoi = atoi(number.data());
	errno_val = errno;
	n_ft_atoi = ft_atoi(number.data());
	n_strtol = strtol(number.data(), (char **)NULL, 10);
	n_strtol_t = (int)strtol(number.data(), (char **)NULL, 10);
	std::cout << "STR: " << "LONG_MIN - 1" << std::endl;
	std::cout << "cycle " << 11 << ": atoi: " << n_atoi << ", ft_atoi: " << n_ft_atoi << ", strtol: " << n_strtol << ", (int)strtol: " << n_strtol_t << ", errno: " << errno_val << ".";
	if (n_atoi == n_ft_atoi)
		std::cout << "\033[0;32m" << "OK";
	else
		std::cout << "\033[0;31m" << "KO";
	std::cout << "\033[0m" << "." << std::endl;
	usleep(50000);
	return (0);
}
