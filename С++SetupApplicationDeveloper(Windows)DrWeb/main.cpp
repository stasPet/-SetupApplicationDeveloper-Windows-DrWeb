#include "TernaryTree.h"

int main()
{
    {
        TernaryTree<std::wstring, std::wstring> tree{L"abc", L"Petrov"};

        //tree.Insert(L"cd", L"Stas");
        tree.Insert(L"ab", L"Stas");
        tree.Insert(L"bac", L"Sanek");
        tree.Insert(L"a", L"Stas");
        tree.Insert(L"a", L"Stas");
        tree.Insert(L"Mama", L"Lina");

        std::wstring result;
        result = tree.Search(L"ab");
    }

    return 0;
}