/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Value.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:58:07 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/16 13:28:09 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUE_H
#define VALUE_H
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <stdlib.h> 
#include <float.h>

class Value
{	
	class TypeNotFound : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("O valor passado não é nenhum dos seguintes tipos: int, float, double or printable char");
			}
	};
	
	public:
		Value(void);
		Value(Value const & src);
		~Value(void);
		Value & operator=(Value const & rhs);

		Value(char *string);
		void	print(void) const;

	private:

		void		_detectType(void);
		static bool	_isDisplayableNANChar(char *str);
		static bool	_isInt(char *str);
		static bool	_isFloat(char *str);
		static bool	_isDouble(char *str);
		static bool	_isPseudoLiteral(char *str);
		static bool	_isFloatPseudoLiteral(std::string arg);
		static bool	_isDoublePseudoLiteral(std::string arg);
	
		void 	_printChar(void) const;
		void 	_printLiteral(void) const;
		void 	_printInt(void) const;
		void 	_printFloat(void) const;
		void 	_printDouble(void) const;
		void 	_printImpossible(void) const;
		char 	*_string;
		int		_type;
};

std::ostream & operator<<(std::ostream & o, Value const & src);

#endif