#include "MyDictionary.h"
#include "NotFoundException.h"

template<class TKey, class TValue>
const TValue& MyDictionary<TKey, TValue>::Get(const TKey& key) const
{
    // ...

    return TValue{};
}

template<class TKey, class TValue>
void MyDictionary<TKey, TValue>::Set(const TKey& key, const TValue& value)
{
    // ...
}

template<class TKey, class TValue>
bool MyDictionary<TKey, TValue>::IsSet(const TKey& key) const
{
    // ...

    return false;
}