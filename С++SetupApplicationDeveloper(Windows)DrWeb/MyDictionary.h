#ifndef DEFINE_MY_DICTIONARY
#define DEFINE_MY_DICTIONARY

#include "Dictionary.h"
#include "MyNotFoundException.h"

template<class TKey, class TValue>
class MyDictionary: public Dictionary<TKey, TValue>
{
private:
    MyDictionary<TKey, TValue>* left;
    MyDictionary<TKey, TValue>* right;
    MyDictionary<TKey, TValue>* middle;

    typename TKey::value_type split;
    TValue value;

    const TValue& MyGet(const TKey& key,
        typename TKey::size_type i = 0) const;

    
    void MySet(const TKey& key, const TValue& value,
        typename TKey::size_type i = 0);

    bool MyIsSet(const TKey& key,
        typename TKey::size_type i = 0) const;

public:
    inline MyDictionary() noexcept;

    // Initialization of empty subtree.
    MyDictionary(TKey const&, TValue const&,
              typename TKey::size_type i = 0);

    ~MyDictionary();

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

    virtual const TValue& Get(const TKey& key) const override;
    virtual void Set(const TKey& key, const TValue& value) override;
    virtual bool IsSet(const TKey& key) const  override;
};

template<class TKey, class TValue>
inline MyDictionary<TKey, TValue>::MyDictionary() noexcept:
    left{nullptr}, right{nullptr}, middle{nullptr}
{
    // To initialize fields with zero.
}

template<class TKey, class TValue>
MyDictionary<TKey, TValue>::MyDictionary(TKey const& k, TValue const& v,
    typename TKey::size_type i)
{
    split = k[i++];

    if (i < k.size() )
        middle = new MyDictionary<TKey, TValue>{k, v, i};
    else
        value = v;
}

template<class TKey, class TValue>
MyDictionary<TKey, TValue>::~MyDictionary()
{
    delete left;
    delete right;
    delete middle;
}

template<class TKey, class TValue>
const TValue& MyDictionary<TKey, TValue>::Get(const TKey& key) const
{
    return MyGet(key);
}

template<class TKey, class TValue>
void MyDictionary<TKey, TValue>::Set(const TKey& key, const TValue& value)
{
    MySet(key, value);
}

template<class TKey, class TValue>
bool MyDictionary<TKey, TValue>::IsSet(const TKey& key) const
{
    return MyIsSet(key);
}

template<class TKey, class TValue>
void MyDictionary<TKey, TValue>::MySet(TKey const& k, TValue const& v,
    typename TKey::size_type i)
{
    if (k[i] < split)
    {
        if (left)
            left->MySet(k, v);
        else
            left = new MyDictionary<TKey, TValue>{k, v};
    }
    else if (k[i] > split)
    {
        if (right)
            right->MySet(k, v);
        else
            right = new MyDictionary<TKey, TValue>{k, v};
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
                middle->MySet(k, v, i);
            else
                middle = new MyDictionary<TKey, TValue>{k, v, i};
        }
    }
}

template<class TKey,class TValue>
const TValue& MyDictionary<TKey,TValue>::MyGet(TKey const& k,
    typename TKey::size_type i) const
{
    if (k[i] < split)
    {
        if (left)
            return left->MyGet(k, i);
    }
    else if (k[i] > split)
    {
        if (right)
            return right->MyGet(k, i);
    }
    else
    {
        if (++i == k.size() )
        {
            if (!value.empty() )
                return value;
        }
        else
        {
            if (middle)
                return middle->MyGet(k, i);
        }
    }

    throw MyNotFoundException<TKey>{k};
}

template<class TKey,class TValue>
inline bool MyDictionary<TKey,TValue>::MyIsSet(TKey const& k,
    typename TKey::size_type i) const
{
    if (k[i] < split)
    {
        if (left)
            return left->MyIsSet(k, i);
    }
    else if (k[i] > split)
    {
        if (right)
            return right->MyIsSet(k, i);
    }
    else
    {
        if (++i == k.size() )
        {
            if (!value.empty() )
                return true;
        }
        else
        {
            if (middle)
                return middle->MyIsSet(k, i);
        }
    }

    return false;
}

#endif