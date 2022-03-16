/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:07:06 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/16 16:32:23 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <stdint.h>
#include <iostream>

int main(void)
{
	Base *random = generate();
	Base &random_reference = *random;
	std::cout <<"Identidy with pointer" << std::endl;
	identify(random);
	std::cout <<"Identidy with reference" << std::endl;
	identify(random_reference);
	delete random;
}