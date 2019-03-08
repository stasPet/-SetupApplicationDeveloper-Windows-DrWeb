#ifndef DEFINE_MY_DICTIONARY
#define DEFINE_MY_DICTIONARY

#include "Dictionary.h"

template<class TKey, class TValue>
class MyDictionary: public Dictionary
{
private:


public:
    virtual ~MyDictionary() = default;

    virtual const TValue& Get(const TKey& key) const override;
    virtual void Set(const TKey& key, const TValue& value) override;
    virtual bool IsSet(const TKey& key) const  override;
};

#endif