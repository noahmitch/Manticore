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
		std::ifstream is(file.c_str ());
		is.seekg(0, std::ios_base::end);
		std::size_t size=is.tellg();
		is.seekg(0, std::ios_base::beg);
		std::string v = "";
		v.reserve (size);
		// Load the data
		is.read((char*) &v[0], size);
		// Close the file
		is.close();

		return v;
	}

} /* namespace fs */
