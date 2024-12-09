#include "Input.h"

namespace Input
{
    void clearInputStream()
    {
        std::cin.clear();                                                   // Clear any error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard input buffer
    }

    int getValidatedInt(const std::string &prompt, int minValue)
    {
        int value;

        while (true)
        {
            std::cout << prompt;
            if (std::cin >> value && value >= minValue)
            {
                clearInputStream();
                return value;
            }
            else
            {
                clearInputStream();
                std::cout << "Invalid input. Please enter an integer greater than or equal to " << minValue << ".\n";
            }
        }
    }

    double getValidatedDouble(const std::string &prompt, double minValue)
    {
        double value;
        while (true)
        {
            std::cout << prompt;
            if (std::cin >> value && value >= minValue)
            {
                clearInputStream();
                return value;
            }
            else
            {
                clearInputStream();
                std::cout << "Invalid input. Please enter a number greater than or equal to " << minValue << ".\n";
            }
        }
    }

    std::string getValidatedString(const std::string &prompt)
    {
        std::string value;
        while (true)
        {
            std::cout << prompt;
            std::getline(std::cin, value);
            if (!value.empty())
            {
                return value;
            }
            else
            {
                std::cout << "Input cannot be empty. Please try again.\n";
            }
        }
    }
}
