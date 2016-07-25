/*
 Language.cpp
 
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

#include "Language.h"

namespace Language
{
	std::vector<std::string> defaultDefinitions;

	std::vector<Language> languages = std::vector<Language> ();

	Language::Language ()
	{
		extensions = std::vector<std::string> ();
	}

	Language::~Language ()
	{

	}

	void Language::preprocess (Lexer::Lexer lexer, std::vector<std::string> definitions)
	{
		std::cout << definitions.size () << std::endl;
	}


	Language getLanguage (std::string extension)
	{
		for (int i = 0; i < languages.size (); i++)
		{
			for (int j = 0; j < languages[i].extensions.size (); j++)
			{
				if (languages[i].extensions[j] == extension)
					return languages[i];
			}
		}
		// no language s available
		error::fatalError ("No support for file type '" + extension + "' yet...");
	}

} /* namespace Language */
