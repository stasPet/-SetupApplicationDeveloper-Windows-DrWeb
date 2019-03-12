#include <iostream>
#include <string>

#include "MyDictionary.h"

int main()
{
    try
    {
        MyDictionary<std::wstring, std::wstring> dictionary;

        dictionary.Set(L"abc", L"1");
        dictionary.Set(L"cba", L"2");
        dictionary.Set(L"ab", L"3");
        dictionary.Set(L"bc", L"4");
        dictionary.Set(L"c", L"5");

        std::wcout << dictionary.Get(L"c") << std::endl;
        std::wcout << dictionary.Get(L"ab") << std::endl;
        std::wcout << dictionary.Get(L"bc") << std::endl;
        std::wcout << dictionary.Get(L"abc") << std::endl;
        std::wcout << dictionary.Get(L"cba") << std::endl;

        std::cout << std::boolalpha << dictionary.IsSet(L"b") << std::endl;
        std::wcout << dictionary.Get(L"b") << std::endl;
    }
    catch(const MyNotFoundException<std::wstring>& exception)
    {
        std::wcout << "Key: " << exception.GetKey() << " not found"
            << std::endl;
    }

    return 0;
}