#ifndef DEFINE_MY_DICTIONARY
#define DEFINE_MY_DICTIONARY

#include "Dictionary.h"
#include "TernaryTree.h"

#include "MyNotFoundException.h"

template<class TKey, class TValue>
class MyDictionary: public Dictionary<TKey, TValue>
{
private:
    TernaryTree<TKey, TValue> ternaryTree;

public:
    virtual ~MyDictionary() = default;

    virtual const TValue& Get(const TKey& key) const override;
    virtual void Set(const TKey& key, const TValue& value) override;
    virtual bool IsSet(const TKey& key) const  override;
};

template<class TKey, class TValue>
const TValue& MyDictionary<TKey, TValue>::Get(const TKey& key) const
{
    const TValue* ret = ternaryTree.Search(key);
    if (!ret)
        throw MyNotFoundException<TKey>{key};

    return *ret;
}

template<class TKey, class TValue>
void MyDictionary<TKey, TValue>::Set(const TKey& key, const TValue& value)
{
    ternaryTree.Insert(key, value);
}

template<class TKey, class TValue>
bool MyDictionary<TKey, TValue>::IsSet(const TKey& key) const
{
    return ternaryTree.Search(key);
}

#endif