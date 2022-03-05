/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Value.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:58:07 by rdutenke          #+#    #+#             */
/*   Updated: 2022/03/05 19:56:51 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUE_H
#define VALUE_H
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <stdlib.h> 

class Value
{	
	public:
		Value(void);
		Value(Value const & src);
		~Value(void);
		Value & operator=(Value const & rhs);

		Value(char *string, int type);
		void	print(void) const;

	private:
		void 	_printChar(void) const;
		void 	_printLiteral(void) const;
		void 	_printInt(void) const;
		void 	_printImpossible(void);
		void 	_printIntChar(double checkValue);
		char 	*_string;
		int		_type;
};

std::ostream & operator<<(std::ostream & o, Value const & src);

#endif