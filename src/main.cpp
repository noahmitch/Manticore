/*
  main.cpp

    Created on: Jul 23, 2016
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

#include <iostream>
#include <vector>

#include "fs.h"
#include "error.h"
#include "Language.h"
#include "C.h"
#include "Lexer.h"

void init ()
{
	Language::initializeLanguage ();
	Language::C clang = Language::C ();
	Language::languages.push_back(clang);
}

int main (int argc, char **args)
{
	if (argc == 1)
		error::fatalError ("I need input");

	init ();

	std::vector<std::string> files = std::vector<std::string> ();

	for (int i = 1; i < argc; i++)
	{
		std::string arg = args[i];
		if (fs::exists (arg))
		{
			files.push_back (arg);
		}
	}

	for (int i = 0; i < files.size (); i++)
	{
		std::string text = fs::open (files[i]);
		std::string extension = fs::getFileExtension (files[i]);

		Language::Language lang = Language::getLanguage (extension);

		Lexer::Lexer lexer = Lexer::Lexer ();

		lexer.add (text);
		//lexer.print ();
		lang.preprocess (lexer);
	}

	return 0;
}
