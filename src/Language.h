/*
 Language.h
 
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

#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#include <iostream>
#include <vector>
#include <dirent.h>

#include "Lexer.h"
#include "error.h"

namespace Language
{
	extern std::vector<std::string> defaultDefinitions;

	inline void initializeLanguage ()
	{
		defaultDefinitions = std::vector<std::string> ();
		#ifdef __linux__
			defaultDefinitions.push_back("__linux__");
		#elif _WIN32
			defaultDefinitions.push_back ("_WIN32");
		#endif
	}

	class Language
	{
		public:
			Language ();
			virtual ~Language ();

			void preprocess (Lexer::Lexer lexer, std::vector<std::string> definitions = defaultDefinitions);

			std::string name;
			std::vector<std::string> extensions;
	};

	extern std::vector<Language> languages;

	Language getLanguage (std::string extension);

} /* namespace Language */

#endif /* LANGUAGE_H_ */
