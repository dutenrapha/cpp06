/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:49:00 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/16 15:56:57 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <stdint.h>
#include <iostream>

int main(void)
{
	Data *test = new Data();
	uintptr_t serialized_test;
	Data *deserialize_test;

	test->var1 = "New test";
	test->var2 = 42;
	test->var3 = 42.0f;
	
	std::cout << "----- Original data: -----" << std::endl;
	std::cout	<< "var1: "		
				<< test->var1 << std::endl
				<< "var2: "	
				<< test->var2 << std::endl
				<< "var3: "	
				<< test->var3 << std::endl;
			
	std::cout << "--- After serialization: ---" << std::endl;
	serialized_test = serialize(test);
	std::cout << serialized_test << std::endl;

	std::cout << "-- After deserialization: --" << std::endl;
	deserialize_test = deserialize(serialized_test);
	std::cout	<< "var1: "		
			<< deserialize_test->var1 << std::endl
			<< "var2: "	
			<< deserialize_test->var2 << std::endl
			<< "var3: "	
			<< deserialize_test->var3 << std::endl;
	delete test;
}