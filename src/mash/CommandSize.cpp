// Copyright © 2015, Battelle National Biodefense Institute (BNBI);
// all rights reserved. Authored by: Brian Ondov, Todd Treangen,
// Sergey Koren, and Adam Phillippy
//
// See the LICENSE.txt file included with this software for license information.

#include "CommandSize.h"
#include "Size.h"
#include "sizeParameterSetup.h"
#include <iostream>

using std::cerr;
using std::endl;
using std::string;
using std::vector;

namespace mash {

CommandSize::CommandSize()
: Command()
{
    name = "size";
    summary = "Provide estimate of genome size.";
    description = "";
    argumentString = "<input>";
    
    useOption("help");
    // addOption("list", Option(Option::Boolean, "l", "Input", "List input. Lines in each <input> specify paths to sequence files, one per line.", ""));
    // addOption("prefix", Option(Option::File, "o", "Output", "Output prefix (first input file used if unspecified). The suffix '.msh' will be appended.", ""));
    // addOption("id", Option(Option::File, "I", "Sketch", "ID field for sketch of reads (instead of first sequence ID).", ""));
    // addOption("comment", Option(Option::File, "C", "Sketch", "Comment for a sketch of reads (instead of first sequence comment).", ""));
    useSketchOptions();
}

int CommandSize::run() const
{
    if ( arguments.size() == 0 || options.at("help").active )
    {
        print();
        return 0;
    }
    
    int verbosity = 1;//options.at("silent").active ? 0 : options.at("verbose").active ? 2 : 1;
    // bool list = options.at("list").active;
    
    Size::Parameters parameters;
    
    if ( sizeParameterSetup(parameters, *(Command *)this) )
    {
    	return 1;
    }
    
    Size size;
    
    
    // vector<string> files;
    
    // files.push_back(arguments[0]);
    
    size.estimateFromReads(arguments[0], parameters);
    
    return 0;
}

} // namespace mash
