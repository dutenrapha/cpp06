/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Value.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:59:26 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/05 19:57:06 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Value.hpp"

Value::Value(void)
{
	return ;
}

Value::Value(Value const & src)
{
	*this = src;
	return ;
}

Value::~Value(void)
{
	return ;
}

Value & Value::operator=(Value const & rhs)
{
	this->_string = rhs._string;
	this->_type = rhs._type;
	return *this;
}

Value::Value(char *string, int type) : _string(string), _type(type)
{
	return ;
}

void			Value::print(void) const
{
	if (this->_type == 0)
	{
		this->_printChar();
	}
	else if (this->_type == 4)
	{
		this->_printLiteral();
	}
}

std::ostream & operator<<(std::ostream & o, Value const & src)
{
	src.print();
	return(o);
}

void Value::_printChar(void) const
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "char: " << this->_string[0] << std::endl;
	std::cout << "int: " << static_cast<int>(this->_string[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(this->_string[0]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(this->_string[0]) << std::endl;
}

void 	Value::_printLiteral(void) const
{
	int i = 0;
	char *str;

	std::string pseudoLitral = this->_string;
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	if (pseudoLitral == "-inf" || pseudoLitral == "+inf" || pseudoLitral == "nan")
	{
		std::cout << "float: " << pseudoLitral << "f" << std::endl;
		std::cout << "double: " << pseudoLitral << std::endl;
		return ;
	}
	std::cout << "float: " << pseudoLitral << std::endl;
	str = this->_string;
	while (str[i + 1] != '\0')
	{
		i++;
	}
	str[i] = '\0';
	pseudoLitral = str;
	std::cout << "double: " << pseudoLitral << std::endl;
}

void 	Value::_printInt(void) const
{
	double checkValue = strtod(this->_string, NULL);
	if (checkValue < INT_MIN || checkValue > INT_MAX)
	{
		this->_printImpossible();
		return ;
	}
	this->_printIntChar(checkValue);

}

void Value::_printIntChar(double checkValue)
{
	std::cout << "char: ";
	if (checkValue < 0 || checkValue > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (c >= '!' && c <= '~')
			std::cout << "'" << static_cast<char>(atoi(this->_str)) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
}

	this->_int = atoi(this->_str);
	this->_char = ;
	this->_float = static_cast<float>(atoi(this->_str));
	this->_double = static_cast<double>(atoi(this->_str));

void Value::_printImpossible(void)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "impossible" << std::endl;
	std::cout << "double: " << "impossible" << std::endl;
}