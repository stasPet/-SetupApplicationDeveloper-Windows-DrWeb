#include "TernaryTree.h"

int main()
{
    TernaryTree<std::wstring, std::wstring> tree;

    tree.Init(L"abc", L"Petrov");
    //tree.Insert(L"cd", L"Stas");
    tree.Insert(L"ab", L"Stas");
    tree.Insert(L"a", L"Stas");
    tree.Insert(L"a", L"Stas");


    return 0;
}