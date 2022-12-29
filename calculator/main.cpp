#include <iostream>
#include <typeinfo>
#include <string>
#include <string.h>
#include <algorithm>

int main (int argc, char* argv[])
{
    if (argc == 1)
    {
        std::cout << "Calculator v1.0\nPrint this message without any argument\nUse 'calc -o mult numbers' or 'calc -o div numbers' where 'numbers' is a placeholder for 2, 3 or 4 numbers\nExample: calc -o div 8 2 2 2" << std::endl;
        return 0;
    }
    bool hasOption;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-o") == 0)
        {
            hasOption = true;
        }
    }
    if (!hasOption)
    {
        std::cout << "there's no option '-o'" << std::endl;
        return 0;
    }
    if (hasOption and strcmp(argv[1], "-o") != 0)
    {
        std::cout << "option has to be the first argument" << std::endl;
        return 0;
    }
    if (argc < 5)
    {
        std::cout << "not enough arguments";
        return 0;
    }
    if (argc > 7)
    {
        std::cout << "too many arguments";
        return 0;
    }
    if (strcmp(argv[2], "mult") == 0)
    {
        for (int i = 4; i < argc; i++)
        {
            try
            {
                std::stof(argv[i]);
            }
            catch(std::invalid_argument& e)
            {
                std::cout << "can only receive numbers";
                return 0;
            }
        }
        float res = std::stof(argv[3]);
        for (int i = 4; i < argc; i++)
        {
            res = res * std::stof(argv[i]);
        }
        std::cout << res << std::endl;
    }
    else if (strcmp(argv[2], "div") == 0)
    {
        for (int i = 4; i < argc; i++)
        {
            float num;
            try
            {
                num = std::stof(argv[i]);
            }
            catch(std::invalid_argument& e)
            {
                std::cout << "can only receive numbers";
                return 0;
            }
            if (num == 0)
            {
                std::cout << "division by zero" << std::endl;
                return 0;
            }
        }
        float res = std::stof(argv[3]);
        for (int i = 4; i < argc; i++)
        {
            res = res / std::stof(argv[i]);
        }
        std::cout << res << std::endl;
    }
    else
    {
        std::cout << "wrong option" << std::endl;
        return 0;
    }
    return 0;
}