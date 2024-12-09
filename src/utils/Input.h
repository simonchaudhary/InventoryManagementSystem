#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <limits>

namespace Input
{
    void clearInputStream();

    int getValidatedInt(const std::string &prompt, int minValue);

    double getValidatedDouble(const std::string &prompt, double minValue);

    std::string getValidatedString(const std::string &prompt);
}

#endif // INPUT_H
