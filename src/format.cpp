#include <string>
#include <sstream>
#include <iomanip>

#include "format.h"
using std::ostringstream;
using std::string;
using std::to_string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    // hours : minutes : seconds
    // Using output string stream and used setfill and setw to create the leading zero
    ostringstream time;
    time << std::setw( 2 ) << std::setfill( '0' ) << to_string((seconds / 60 / 60)) << ":" << std::setw( 2 ) << std::setfill( '0' ) << to_string((seconds / 60)% 60) <<":" << std::setw( 2 ) << std::setfill( '0' ) << to_string(seconds % 60);
    return time.str();
     }