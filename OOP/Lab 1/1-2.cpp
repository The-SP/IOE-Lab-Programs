// Lab 1
// Question 2
// Write a program to find the position of the character 'C' in the sentence "idea without execution is worthless" using pointer and string.

#include <iostream>
using namespace std;

int main()
{
    const char *sentence = "idea without execution is worthless";
    const char *copy = sentence;

    while (*copy != '\0')
    {
        if (*copy == 'c')
            cout << "Position of the character 'c' = " << int(copy-sentence);
        copy++;
    }
    return 0;
}