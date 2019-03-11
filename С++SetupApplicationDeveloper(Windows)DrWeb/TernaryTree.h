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
public:
    struct ExceptInitTernaryTree {};

private:
    TernaryTree<TKey, TValue>* left;
    TernaryTree<TKey, TValue>* right;
    TernaryTree<TKey, TValue>* middle;

    typename TKey::value_type split;
    TValue* value;

public:
    inline TernaryTree() noexcept;

    // Initialization of empty subtree.
    void Init(TKey const&, TValue const&,
              typename TKey::size_type i = 0);

    void Insert(TKey const&, TValue const&,
                typename TKey::size_type i = 0);
    
    const TValue Search(TKey const&) const;
};

template<class TKey, class TValue>
inline TernaryTree<TKey, TValue>::TernaryTree() noexcept
{
    // To initialize fields with zero.
}

template<class TKey, class TValue>
void TernaryTree<TKey, TValue>::Init(TKey const& k, TValue const& v,
                                     typename TKey::size_type i)
{
    split = k[i++];

    if (i < k.size() )
    {
        middle = new TernaryTree<TKey, TValue>{};
        middle->Init(k, v, i);
    }
    else
        value = new TValue{v};
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
        {
            left = new TernaryTree<TKey, TValue>{};
            left->Init(k, v);
        }
    }
    else if (k[i] > split)
    {
        if (right)
            right->Insert(k, v);
        else
        {
            right = new TernaryTree<TKey, TValue>{};
            right->Init(k, v);
        }
    }
    else
    {
        // Word root checking.
        if (++i == k.size() )
        {
            // Repeat entry protection, repetitions cause memory leaks.
            if (!value)
                value = new TValue{v};
        }
        else
        {
            if (middle)
                middle->Insert(k, v, i);
            else
            {
                middle = new TernaryTree<TKey, TValue>{};
                middle->Init(k, v, i);
            }
        }
    }
}

template<class TKey,class TValue>
inline const TValue TernaryTree<TKey,TValue>::Search(TKey const& k) const
{
    return TValue();
}

#endif