#include <iostream>
#include <string>
#include<ctime>
using namespace std;

string passwordGenerator(int size, int num = 0, int symb = 0)
{
    string resultPassword = "";
    string numbers = "1234567890";
    string alphabets = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    string symbols = "!~#$&_-=?/";

    while (size)
    {
        resultPassword += alphabets[rand() % alphabets.size()];
        size--;

        if (num && size)
        {
            resultPassword += numbers[rand() % numbers.size()];
            size--;
            num--;
        }

        if (symb && size)
        {
            resultPassword += symbols[rand() % symbols.size()];
            size--;
            symb--;
        }
    }
    return resultPassword;
}

int main()
{
    int size, num, symb;

    cout << "Enter the length of your total password : ";
    cin >> size;

    cout << "How many numbers you want to add from (0-9) ";
    cin >> num;

    cout << "How many symbols (!~#$&_-=?/) you want to include? ";
    cin >> symb;

   
    if (size <= 0)
    {
        cout << "Size must be > 0 \n";
        return 1;
    }
    if (num < 0 || symb < 0)
    {
        cout << "number and symbols cannot be negative \n";
        return 1;
    }
    if (num + symb > size)
    {
        cout << "Requested numbers and symbols exceed the password length. Adjusting values to fit.\n";
        
    }

    
    srand((unsigned)time(0));
    string pwd = passwordGenerator(size, num, symb);
    cout << "Your password: " << pwd << "\n";

    return 0;
}