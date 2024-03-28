#include <iostream>
#include <stdlib.h>
#include "Array.hpp"
#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    Array<std::string> strings(5);
    Array<char> chars(26);
    char a = 'a';
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    for (int i = 0; i < 26; i++, a++)
        chars[i] = a;
    for (int i = 0; i < 26; i++)
        std::cout << chars[i];
    std::cout << std::endl;
    strings[0] = "hello"; strings[1] = "how"; strings[2] = "are"; strings[3] = "you"; strings[4] = "?";
    for (int i = 0; i < 5; i++)
        std::cout << strings[i] << " ";
    std::cout << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        //check
        std::cout << tmp[11] << " must be equal to " << numbers[11] << std::endl;

        Array<int> test(tmp);
        //check
        std::cout << test[4] << " must be equal to " << tmp[4] << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "numbers[-2] " << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "numbers[MAX_VAL] " << e.what() << '\n';
    }
    try
    {
        strings[MAX_VAL] = "OutOfBounds?";
    }
    catch(const std::exception& e)
    {
        std::cerr << "strings[MAX_VAL] " << e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
