// Copyright © 2015, Battelle National Biodefense Institute (BNBI);
// all rights reserved. Authored by: Brian Ondov, Todd Treangen,
// Sergey Koren, and Adam Phillippy
//
// See the LICENSE.txt file included with this software for license information.

#ifndef sizeParameterSetup_h
#define sizeParameterSetup_h

#include "Command.h"
#include "Size.h"

namespace mash {

int sizeParameterSetup(Size::Parameters & parameters, const Command & command);
void warnKmerSize(const Size::Parameters & parameters, const Command & command, uint64_t lengthMax, const std::string & lengthMaxName, double randomChance, int kMin, int warningCount);

} // namespace mash

#endif
