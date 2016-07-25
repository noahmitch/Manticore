/*
 fs.h
 
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

#ifndef FS_H_
#define FS_H_

#include <string>
#include <vector>
#include <fstream>

namespace fs
{
	std::string open (std::string file);
	bool exists (std::string file);

	std::string getFileExtension (std::string file);
} /* namespace fs */

#endif /* FS_H_ */
