/*
 Lexer.cpp
 
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

#include "Lexer.h"

namespace Lexer
{
	Word::Word (std::string val, int line, int col)
	{
		this->text = val;
		this->line = line;
		this->col = col;
	}

	Lexer::Lexer ()
	{
		words = std::vector<Word> ();
		place = 0;
	}

	Lexer::~Lexer ()
	{

	}

	Word &Lexer::operator [] (int i)
	{
		if (i < words.size ())
			return words[i];
		else
		{
			Word a = Word ("\0");
			return a; // null symbol
		}
	}

	Word Lexer::get (int i)
	{
		if (i < words.size ())
			return words[i];
		else
			return Word ("\0"); // null symbol
	}

	void Lexer::add (std::string text)
	{
		int line = 1;
		int col = 0;

		for (int i = 0; i < text.size (); i++)
		{
			char c = text[i];
			if ((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >= '0' and c <= '9') or (c == '_') or (c == '.'))
			{
				std::string toks;
				toks += c;
				c = text[++i];
				col++;
				while (i < text.size ())
				{
					c = text[i++];
					if (!((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >= '0' and c <= '9') or (c == '_') or (c == '.')))
					{
						i-=2;
						break;
					}
					col++;
					toks += c;
				}
				words.push_back (Word (toks, line, col));
			}
			else if (c == '\n')
			{
				line++;
				col = 0;
			}
			else if (c == '\t')
			{
				col++;
			}
			else if (c == ' ')
			{
				col++;
			}
			else
			{
				std::string toks; toks += text[i];
				col++;
				words.push_back (Word (toks, line, col));
			}
		}
	}

} /* namespace Lexer */
