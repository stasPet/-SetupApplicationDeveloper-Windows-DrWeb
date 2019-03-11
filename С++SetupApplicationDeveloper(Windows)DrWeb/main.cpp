#include "TernaryTree.h"

int main()
{
    {
        TernaryTree<std::wstring, std::wstring> tree{L"abc", L"Petrov"};

        //tree.Insert(L"cd", L"Stas");
        tree.Insert(L"abc", L"Stas");
        /*tree.Insert(L"bac", L"Sanek");
        tree.Insert(L"a", L"Stas");
        tree.Insert(L"a", L"Stas");
        tree.Insert(L"Mama", L"Lina");*/

        const std::wstring* result = tree.Search(L"abc");
    }

    return 0;
}