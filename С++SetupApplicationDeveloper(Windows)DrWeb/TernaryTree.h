#ifndef DEFINE_TERNARY_TREE
#define DEFINE_TERNARY_TREE

#include <cstddef>
#include <string>

/*
    TKey and TValue must be compatible with the type basic_string
*/

template<class TKey, class TValue>
class TernaryTree
{
private:
    TernaryTree<TKey, TValue>* left;
    TernaryTree<TKey, TValue>* right;
    TernaryTree<TKey, TValue>* middle;

    typename TKey::value_type split;
    TValue value;

public:
    inline TernaryTree() noexcept;

    // Initialization of empty subtree.
    TernaryTree(TKey const&, TValue const&,
              typename TKey::size_type i = 0);

    ~TernaryTree();

    /*
        On development stage.

        TernaryTree(TernaryTree&);
        TernaryTree(const TernaryTree&&);

        TernaryTree& operator=(TernaryTree const&);
        TernaryTree& operator=(TernaryTree&&);

        void Swap(TernaryTree&);

        PartialMatchSearch ???
        PeighbourSearch ???
    */

    void Insert(TKey const&, TValue const&,
        typename TKey::size_type i = 0);
    
    const TValue* Search(TKey const&,
        typename TKey::size_type i = 0) const;

};

template<class TKey, class TValue>
inline TernaryTree<TKey, TValue>::TernaryTree() noexcept:
    left{nullptr}, right{nullptr}, middle{nullptr}
{
    // To initialize fields with zero.
}

template<class TKey, class TValue>
TernaryTree<TKey, TValue>::TernaryTree(TKey const& k, TValue const& v,
    typename TKey::size_type i)
{
    split = k[i++];

    if (i < k.size() )
        middle = new TernaryTree<TKey, TValue>{k, v, i};
    else
        value = v;
}

template<class TKey, class TValue>
TernaryTree<TKey, TValue>::~TernaryTree()
{
    delete left;
    delete right;
    delete middle;
}

template<class TKey, class TValue>
void TernaryTree<TKey, TValue>::Insert(TKey const& k, TValue const& v,
    typename TKey::size_type i)
{
    if (k[i] < split)
    {
        if (left)
            left->Insert(k, v);
        else
            left = new TernaryTree<TKey, TValue>{k, v};
    }
    else if (k[i] > split)
    {
        if (right)
            right->Insert(k, v);
        else
            right = new TernaryTree<TKey, TValue>{k, v};
    }
    else
    {
        // Word root checking.
        if (++i == k.size() )
        {
            if (value != v)
                value = v;
        }
        else
        {
            if (middle)
                middle->Insert(k, v, i);
            else
                middle = new TernaryTree<TKey, TValue>{k, v, i};
        }
    }
}

template<class TKey,class TValue>
inline const TValue* TernaryTree<TKey,TValue>::Search(TKey const& k,
    typename TKey::size_type i) const
{
    if (k[i] < split)
    {
        if (left)
            return left->Search(k, i);
    }
    else if (k[i] > split)
    {
        if (right)
            return right->Search(k, i);
    }
    else
    {
        if (++i == k.size() )
        {
            if (!value.empty() )
                return &value;
        }
        else
        {
            if (middle)
                return middle->Search(k, i);
        }
    }

    return nullptr;
}

#endif