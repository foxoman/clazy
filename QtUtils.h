/*
   This file is part of the clazy static checker.

  Copyright (C) 2015 Sergio Martins <smartins@kde.org>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Library General Public
  License as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Library General Public License for more details.

  You should have received a copy of the GNU Library General Public License
  along with this library; see the file COPYING.LIB.  If not, write to
  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
  Boston, MA 02110-1301, USA.
*/

#ifndef CLAZY_QT_UTILS_H
#define CLAZY_QT_UTILS_H

#include <string>
#include <vector>

namespace clang {
class CXXRecordDecl;
class CompilerInstance;
}

namespace QtUtils
{

/**
 * Returns true if the class is a Qt class which can be iterated with foreach.
 * Which means all containers and also stuff like QAssociativeIterable.
 */
bool isQtIterableClass(clang::CXXRecordDecl *record);

/**
 * Overload.
 */
bool isQtIterableClass(const std::string &className);

/**
 * Returns true if the class is a Qt class which is an associative container (QHash, QMap, QSet)
 */
bool isQtAssociativeContainer(clang::CXXRecordDecl *record);

/**
 * Overload.
 */
bool isQtAssociativeContainer(const std::string &className);

/**
 * Returns a list of Qt containers.
 */
const std::vector<std::string> & qtContainers();

/**
 * Returns true if -DQT_BOOTSTRAPPED was passed to the compiler
 */
bool isBootstrapping(const clang::CompilerInstance &);

}

#endif
