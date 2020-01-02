// Copyright © 2015, Battelle National Biodefense Institute (BNBI);
// all rights reserved. Authored by: Brian Ondov, Todd Treangen,
// Sergey Koren, and Adam Phillippy
//
// See the LICENSE.txt file included with this software for license information.

#ifndef INCLUDED_CommandSize
#define INCLUDED_CommandSize

#include "Command.h"

namespace mash {

class CommandSize : public Command
{
public:

    CommandSize();
    
    int run() const; // override
};

} // namespace mash

#endif
