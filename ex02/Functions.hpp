/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:07:25 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/16 16:37:15 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream> 
#include <cstdlib> 

class Base
{ 
	public: 
		virtual ~Base(void){}
};
class A : public Base {};

class B : public Base {};

class C : public Base {};

Base * generate(void);

void identify(Base* p);

void identify(Base& p);

#endif
