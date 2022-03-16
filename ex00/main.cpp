/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:02:55 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/16 20:18:06 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Value.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (0);
	}
	try
	{
		Value value(argv[1]);
		std::cout << value << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return(0);
}