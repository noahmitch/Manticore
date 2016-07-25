/*
 fs.cpp
 
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

#include "fs.h"

namespace fs
{

	std::string open (std::string file)
	{

		std::ifstream t(file.c_str ());
		return std::string ((std::istreambuf_iterator<char>(t)),
		                 std::istreambuf_iterator<char>());
	}

	bool exists (std::string file)
	{
		if (FILE *f = fopen (file.c_str (), "r"))
		{
				fclose(f);
				return true;
		}
		else
		{
			return false;
		}
	}

	std::string getFileExtension (std::string file)
	{
		std::vector<std::string> sections = std::vector<std::string> ();
		std::string toks;
		for (int i = 0; i < file.size (); i++)
		{
			if (file[i] == '/')
			{
				sections.push_back (toks);
				toks = "";
			}
			else if (i == file.size () - 1)
			{
				sections.push_back (toks + file[i]);
				toks = "";
			}
			else
			{
				toks += file[i];
			}
		}

		toks = "";
		bool started = false;
		// this is meant to skip the first period in the file's extension
		for (int i = 0; i < sections[sections.size () - 1].size (); i++)
		{
			if (started)
				toks += sections[sections.size () - 1][i];

			if (sections[sections.size () - 1][i] == '.')
			{
				started = true;
			}
		}

		return toks;
	}
} /* namespace fs */
