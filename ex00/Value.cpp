/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Value.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:59:26 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/16 13:21:42 by rdutenke         ###   ########.fr       */
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

Value::Value(char *string)
{
	this->_string = string;
	this->_detectType();
	return ;
}


void Value::_detectType()
{
	if (_isDisplayableNANChar(this->_string))
	{
		this->_type = 0;
	}
	else if (_isInt(this->_string))
	{
		this->_type = 1;
	}
	else if (_isFloat(this->_string))
	{
		this->_type = 2;
	}
	else if (_isDouble(this->_string))
	{
		this->_type = 3;
	}
	else if (_isPseudoLiteral(this->_string))
	{
		this->_type = 4;
	}
	else
	{
		throw Value::TypeNotFound();
	}
}

bool Value::_isDisplayableNANChar(char *str)
{
	if ((str[0] >= '!' && str[0] < '0') && str[1] == '\0')
	{
		return (true);
	}
	if ((str[0] > '9' && str[0] <= '~') && str[1] == '\0')
	{
		return (true);
	}
	return (false);
}

bool Value::_isInt(char *str)
{
	int i = 0;
	if (str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (false);
		}
		i++;
	}
	return (true);
}

bool Value::_isFloat(char *str)
{
	int i = 0;
	bool point = false;
	if (str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != 'f')
		{
			return (false);
		}
		if (str[i] == '.' && point == true)
		{
			return (false);
		}
		if (str[i] == 'f' && (str[i + 1] != '\0' || !point))
		{
			return (false);
		}
		if (str[i] == '.')
		{
			point = true;
		}
		i++;
	}
	if (str[i - 1] == 'f')
	{
		return (true);
	}
	return (false);
}

bool Value::_isDouble(char *str)
{
	int i = 0;
	bool point = false;
	if (str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
		{
			return (false);
		}
		if (str[i] == '.' && point == true)
		{
			return (false);
		}
		if (str[i] == '.')
		{
			point = true;
		}
		i++;
	}
	return (true);
}

bool Value::_isPseudoLiteral(char *str)
{
	std::string arg = str;
	if (_isFloatPseudoLiteral(arg) || _isDoublePseudoLiteral(arg))
	{
		return (true);
	}
	return (false);
}

bool Value::_isFloatPseudoLiteral(std::string arg)
{
	if (arg == "-inff" || arg == "+inff" || arg == "nanf")
	{
		return (true);
	}
	return (false);
}

bool Value::_isDoublePseudoLiteral(std::string arg)
{
	if (arg == "-inf" || arg == "+inf" || arg == "nan")
	{
		return (true);
	}
	return (false);
}


void			Value::print(void) const
{
	if (this->_type == 0)
	{
		this->_printChar();
	}
	else if (this->_type == 1)
	{
		this->_printInt();
	}
	else if (this->_type == 2)
	{
		this->_printFloat();
	}
	else if (this->_type == 3)
	{
		this->_printDouble();
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
	int		i;
	char	c;
	
	double checkValue = strtod(this->_string, NULL);
	if (checkValue < INT_MIN || checkValue > INT_MAX)
	{
		this->_printImpossible();
		return ;
	}
	i = atoi(this->_string);
	c = static_cast<char>(i);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "char: ";
	if (checkValue < 0 || checkValue > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (c >= '!' && c <= '~')
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (checkValue < INT_MIN || checkValue > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
	std::cout << "float: ";
	if (checkValue < -FLT_MAX|| checkValue > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}


void 	Value::_printFloat(void) const
{
	float	f;
	char	c;
	
	double checkValue = strtod(this->_string, NULL);
	if (checkValue < -FLT_MAX|| checkValue > FLT_MAX)
	{
		this->_printImpossible();
		return ;
	}
	f = atof(this->_string);
	c = static_cast<char>(f);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "char: ";
	if (checkValue < 0 || checkValue > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (c >= '!' && c <= '~')
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (checkValue < INT_MIN || checkValue > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	std::cout << "float: ";
	if (checkValue < -FLT_MAX|| checkValue > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void 	Value::_printDouble(void) const
{
	char	c;
	
	double checkValue = strtod(this->_string, NULL);
	if (checkValue < -DBL_MAX || checkValue > DBL_MAX)
	{
		this->_printImpossible();
		return ;
	}
	c = static_cast<char>(checkValue);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "char: ";
	if (checkValue < 0 || checkValue > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (c >= '!' && c <= '~')
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (checkValue < INT_MIN || checkValue > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(checkValue) << std::endl;
	std::cout << "float: ";
	if (checkValue < -FLT_MAX|| checkValue > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(checkValue) << "f" << std::endl;
	std::cout << "double: " << checkValue << std::endl;
}

void Value::_printImpossible(void) const
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "impossible" << std::endl;
	std::cout << "double: " << "impossible" << std::endl;
}