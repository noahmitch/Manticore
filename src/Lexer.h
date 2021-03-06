/*
 Lexer.h
 
 Created on: Jul 24, 2016
 Author: Noah B. Mitchell

 
 Copyright (C) 2016-(Current Year)  Noah B. Mitchell

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along
 with this program; if not, write to the Free Software Foundation, Inc.,
 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef LEXER_H_
#define LEXER_H_

#include <iostream>
#include <vector>

namespace Lexer
{
	class Word
	{
		public:
			Word (std::string val, int line=-1, int col=-1);

			std::string text;
			int line;
			int col;
	};

	class Lexer
	{
		public:
			Lexer ();
			virtual ~Lexer ();

			Word &operator[] (int i);

			std::vector<Word> words;
			Word get (int i);
			void add (std::string text);
			void print ();

			int place;
	};

} /* namespace Lexer */

#endif /* LEXER_H_ */
