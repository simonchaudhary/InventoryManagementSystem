#include "Input.h"

namespace Input
{
    void clearInputStream()
    {
        std::cin.clear();                                                   // Clear any error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard input buffer
    }
}
