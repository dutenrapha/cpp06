/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:02:55 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/05 16:55:41 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Value.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Error" << std::endl;
	Value value(argv[1], 4);
	std::cout << value << std::endl;
	return(0);
}