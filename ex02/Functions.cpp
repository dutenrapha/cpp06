/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:11:42 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/16 16:42:52 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

Base * generate(void)
{
	int randNum;
	
	Base *return_class;
	std::srand((unsigned int)time(NULL));
	randNum = rand()%3;
	if (randNum == 0)
	{
		return_class = new A();
		std::cout << "class A generated\n" << std::endl;
	}
	else if (randNum == 1)
	{
		return_class = new B();
		std::cout << "class B generated\n" << std::endl;
	}
	else
	{
		return_class = new C();
		std::cout << "class C generated\n" << std::endl;
	}
	return(return_class);
}
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A\n" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B\n" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C\n" << std::endl;
	}
}

void identify(Base& p)
{
	if (dynamic_cast<A*>(&p))
	{
		std::cout << "A\n" << std::endl;
	}
	else if (dynamic_cast<B*>(&p))
	{
		std::cout << "B\n" << std::endl;
	}
	else if (dynamic_cast<C*>(&p))
	{
		std::cout << "C\n" << std::endl;
	}
}