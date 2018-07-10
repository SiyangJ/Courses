#include "OurType.h"
#include "Multiset.h"
#include <iostream>
#include <cstdlib>
#include <type_traits>
#include <cassert>

using namespace std;
typedef OurType ItemType;

int OurType::m_count = 0;
int OurType::m_asstcopycount = 0;

inline int itemcount()
{
    return OurType::m_count;
}

inline int nasstcopys()
{
    return OurType::m_asstcopycount;
}

ItemType DUMMY = ItemType(123);
ItemType DEFAULT = ItemType(0);
ItemType ARRAY[7] = {
    ItemType(10), ItemType(20), ItemType(30), ItemType(40),
    ItemType(50), ItemType(60), ItemType(70)
};

void xxxtestone(int n)
{
    Multiset<ItemType> m;
    switch (n)
    {
        default: {
            cout << "Bad argument" << endl;
        } break; case  1: {
            assert((is_same<decltype(&Multiset<ItemType>::empty),
                    bool (Multiset<ItemType>::*)() const>::value));
        } break; case  2: {
            assert((is_same<decltype(&Multiset<ItemType>::size),
                    int (Multiset<ItemType>::*)() const>::value));
        } break; case  3: {
            assert((is_same<decltype(&Multiset<ItemType>::uniqueSize),
                    int (Multiset<ItemType>::*)() const>::value));
        } break; case  4: {
            assert((is_same<decltype(&Multiset<ItemType>::contains),
                    bool (Multiset<ItemType>::*)(const ItemType&) const>::value));
        } break; case  5: {
            assert((is_same<decltype(&Multiset<ItemType>::count),
                    int (Multiset<ItemType>::*)(const ItemType&) const>::value));
        } break; case  6: {
            assert((is_same<decltype(&Multiset<ItemType>::get),
                    int (Multiset<ItemType>::*)(int, ItemType&) const>::value));
        } break; case  7: {
            assert((is_same<decltype(&Multiset<ItemType>::getLeastFrequentValue),
                    bool (Multiset<ItemType>::*)(ItemType&) const>::value));
        } break; case  8: {
            assert((is_same<decltype(&Multiset<ItemType>::getSmallestValue),
                    bool (Multiset<ItemType>::*)(ItemType&) const>::value));
        } break; case  9: {
            assert((is_same<decltype(&Multiset<ItemType>::getSecondSmallestValue),
                    bool (Multiset<ItemType>::*)(ItemType&) const>::value));
        } break; case 10: {
            assert((is_same<decltype(&Multiset<ItemType>::countIf),
                    int (Multiset<ItemType>::*)(char, ItemType) const>::value));
        } break; case 11: {
            assert((is_same<decltype(&Multiset<ItemType>::copyIntoOtherMultiset),
                    void (Multiset<ItemType>::*)(Multiset<ItemType>&) const>::value));
        } break; case 12: {
            assert(m.empty());
        } break; case 13: {
            assert(m.size() == 0);
        } break; case 14: {
            assert(m.uniqueSize() == 0);
        } break; case 15: {
            assert(m.erase(DEFAULT) == 0  &&  m.size() == 0);
        } break; case 16: {
            assert(m.eraseAll(DEFAULT) == 0  &&  m.size() == 0);
        } break; case 17: {
            assert(!m.contains(DEFAULT));
        } break; case 18: {
            assert(m.count(DEFAULT) == 0);
        } break; case 19: {
            ItemType x = DUMMY;
            assert(m.get(0, x) == 0);
        } break; case 20: {
            ItemType x = DUMMY;
            m.get(0, x);
            assert(x == DUMMY);
        } break; case 21: {
            ItemType x = DUMMY;
            assert(!m.getLeastFrequentValue(x));
        } break; case 22: {
            ItemType x = DUMMY;
            m.getLeastFrequentValue(x);
            assert(x == DUMMY);
        } break; case 23: {
            ItemType x = DUMMY;
            assert(!m.getSmallestValue(x));
        } break; case 24: {
            ItemType x = DUMMY;
            m.getSmallestValue(x);
            assert(x == DUMMY);
        } break; case 25: {
            ItemType x = DUMMY;
            assert(!m.getSecondSmallestValue(x));
        } break; case 26: {
            ItemType x = DUMMY;
            m.getSecondSmallestValue(x);
            assert(x == DUMMY);
        } break; case 27: {
            assert(!m.replace(DEFAULT, ARRAY[0]));
        } break; case 28: {
            m.replace(DEFAULT, ARRAY[0]);
            ItemType x = DUMMY;
            m.get(0, x);
            assert(x == DUMMY);
        } break; case 29: {
            assert(m.countIf('@', DEFAULT) == -1);
        } break; case 30: {
            assert(m.countIf('=', DEFAULT) == 0);
        } break; case 31: {
            assert(m.insert(DUMMY));
        } break; case 32: {
            m.insert(DUMMY);
            assert(!m.empty());
        } break; case 33: {
            m.insert(DUMMY);
            assert(m.size() == 1);
        } break; case 34: {
            m.insert(DUMMY);
            assert(m.uniqueSize() == 1);
        } break; case 35: {
            m.insert(DUMMY);
            assert(m.contains(DUMMY));
        } break; case 36: {
            m.insert(DUMMY);
            assert(m.count(DUMMY) == 1);
        } break; case 37: {
            m.insert(ARRAY[0]);
            ItemType x = DUMMY;
            assert(m.get(0, x) == 1);
        } break; case 38: {
            m.insert(ARRAY[0]);
            ItemType x = DUMMY;
            m.get(0, x);
            assert(x == ARRAY[0]);
        } break; case 39: {
            m.insert(ARRAY[0]);
            ItemType x = DUMMY;
            assert(m.getLeastFrequentValue(x));
        } break; case 40: {
            m.insert(ARRAY[0]);
            ItemType x = DUMMY;
            m.getLeastFrequentValue(x);
            assert(x == ARRAY[0]);
        } break; case 41: {
            m.insert(ARRAY[0]);
            ItemType x = DUMMY;
            assert(m.getSmallestValue(x));
        } break; case 42: {
            m.insert(ARRAY[0]);
            ItemType x = DUMMY;
            m.getSmallestValue(x);
            assert(x == ARRAY[0]);
        } break; case 43: {
            m.insert(ARRAY[0]);
            ItemType x = DUMMY;
            assert(!m.getSecondSmallestValue(x));
        } break; case 44: {
            m.insert(ARRAY[0]);
            ItemType x = DUMMY;
            m.getSecondSmallestValue(x);
            assert(x == DUMMY);
        } break; case 45: {
            m.insert(ARRAY[0]);
            assert(!m.replace(ARRAY[1], ARRAY[2]));
            assert(m.size() == 1  &&  m.count(ARRAY[0]) == 1  &&  m.count(ARRAY[2]) == 0);
        } break; case 46: {
            m.insert(ARRAY[0]);
            assert(m.replace(ARRAY[0], ARRAY[1]));
            assert(m.size() == 1  &&  m.count(ARRAY[1]) == 1  &&  m.count(ARRAY[0]) == 0);
        } break; case 47: {
            m.insert(ARRAY[0]);
            assert(m.replace(ARRAY[0], ARRAY[0]));
            assert(m.size() == 1  &&  m.uniqueSize() == 1  &&  m.count(ARRAY[0]) == 1);
        } break; case 48: {
            m.insert(ARRAY[0]);
            assert(m.countIf('#', ARRAY[0]) == -1);
        } break; case 49: {
            m.insert(ARRAY[0]);
            assert(m.countIf('=', ARRAY[0]) == 1);
        } break; case 50: {
            m.insert(ARRAY[0]);
            assert(m.countIf('<', ARRAY[0]) == 0);
        } break; case 51: {
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            ItemType x = DUMMY;
            assert(m.getSecondSmallestValue(x));
        } break; case 52: {
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            ItemType x = DUMMY;
            m.getSmallestValue(x);
            assert(x == ARRAY[0]);
            m.getSecondSmallestValue(x);
            assert(x == ARRAY[1]);
        } break; case 53: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            ItemType x = DUMMY;
            m.getSmallestValue(x);
            assert(x == ARRAY[0]);
            m.getSecondSmallestValue(x);
            assert(x == ARRAY[1]);
        } break; case 54: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[0]);
            ItemType x = DUMMY;
            assert(m.getSmallestValue(x)  &&  x == ARRAY[0]);
            x = DUMMY;
            assert(!m.getSecondSmallestValue(x)  &&  x == DUMMY);
        } break; case 55: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            assert(!m.empty()   &&  m.size() == 2  &&  m.uniqueSize() == 2);
        } break; case 56: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            assert(m.contains(ARRAY[0])  &&  m.contains(ARRAY[1]));
        } break; case 57: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            assert(m.count(ARRAY[0]) == 1  &&  m.count(ARRAY[1]) == 1);
        } break; case 58: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            assert(m.size() == 3  &&  m.uniqueSize() == 2);
        } break; case 59: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            assert(m.contains(ARRAY[0])  &&  m.contains(ARRAY[1]));
        } break; case 60: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            assert(m.count(ARRAY[0]) == 2  &&  m.count(ARRAY[1]) == 1);
        } break; case 61: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            ItemType x = DUMMY;
            m.get(0, x);
            assert(x == ARRAY[0]  ||  x == ARRAY[1]);
        } break; case 62: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            ItemType x = DUMMY;
            m.get(0, x);
            ItemType y = DUMMY;
            m.get(0, y);
            assert(x == y  &&  x != DUMMY);
        } break; case 63: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            int n0 = 0;
            int n1 = 0;
            int nx = 0;
            ItemType x;
            for (int k = 0; k < 2; k++)
            {
                m.get(k, x);
                if (x == ARRAY[0])
                    n0++;
                else if (x == ARRAY[1])
                    n1++;
                else
                    nx++;
            }
            assert(m.get(2, x) == 0);
            assert(n0 == 1  &&  n1 == 1  &&  nx == 0);
        } break; case 64: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            int n[2] = { 0 };
            for (int k = 0; k < 2; k++)
            {
                ItemType x;
                int ct = m.get(k, x);
                bool found = false;
                for (int i = 0; i < 2; i++)
                {
                    if (x == ARRAY[i])
                    {
                        n[i] += ct;
                        found = true;
                        break;
                    }
                }
                assert(found);
            }
            assert(n[0] == 2  &&  n[1] == 1);
        } break; case 65: {
            m.insert(ARRAY[3]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[4]);
            assert(m.size() == 10  &&  m.uniqueSize() == 5);
            int counts[5] = { 1, 2, 1, 2, 4 };
            ItemType a[5] = { DUMMY, DUMMY, DUMMY, DUMMY, DUMMY };
            int n[5];
            for (int k = 0; k < 5; k++)
                n[k] = m.get(k, a[k]);
            for (int j = 0; j < 5; j++)
            {
                int k;
                for (k = 0; k < 5; k++)
                {
                    if (a[k] == ARRAY[j])
                    {
                        assert(n[k] == counts[j]);
                        break;
                    }
                }
                assert(k < 5);
            }
        } break; case 66: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            assert(m.eraseAll(ARRAY[0]) == 2);
        } break; case 67: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            m.eraseAll(ARRAY[0]);
            assert(!m.empty()  &&  m.size() == 1  &&  m.uniqueSize() == 1);
        } break; case 68: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            m.eraseAll(ARRAY[0]);
            assert(m.count(ARRAY[0]) == 0  &&  m.count(ARRAY[1]) == 1);
        } break; case 69: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            m.eraseAll(ARRAY[1]);
            assert(!m.empty()  &&  m.size() == 2  &&  m.uniqueSize() == 1);
            assert(m.count(ARRAY[0]) == 2  &&  m.count(ARRAY[1]) == 0);
        } break; case 70: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            m.eraseAll(ARRAY[0]);
            m.erase(ARRAY[1]);
            assert(m.count(ARRAY[0]) == 0  &&  m.count(ARRAY[1]) == 0);
        } break; case 71: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            m.eraseAll(ARRAY[0]);
            m.erase(ARRAY[1]);
            assert(m.size() == 0  &&  m.uniqueSize() == 0);
        } break; case 72: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            assert(m.erase(ARRAY[1]) == 1);
        } break; case 73: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            m.erase(ARRAY[1]);
            assert(m.count(ARRAY[1]) == 1  &&  m.uniqueSize() == 3);
        } break; case 74: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            m.erase(ARRAY[1]);
            m.erase(ARRAY[2]);
            m.erase(ARRAY[1]);
            m.insert(ARRAY[3]);
            assert(m.uniqueSize() == 2  &&  m.count(ARRAY[1]) == 0  &&
                   m.count(ARRAY[2]) == 0);
        } break; case 75: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            assert(m.erase(ARRAY[2]) == 0  &&  m.uniqueSize() == 2);
        } break; case 76: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            m.erase(ARRAY[0]);
            m.erase(ARRAY[0]);
            ItemType x;
            assert(m.get(0, x) == 1  &&  x == ARRAY[1]);
        } break; case 77: {
            m.insert(DEFAULT);
            assert(m.size() == 1  &&  m.uniqueSize() == 1  &&
                   m.contains(DEFAULT)  &&  m.count(DEFAULT) == 1);
        } break; case 78: {
            m.insert(DEFAULT);
            m.erase(DEFAULT);
            assert(m.size() == 0  &&  m.uniqueSize() == 0  &&
                   !m.contains(DEFAULT)  &&  m.count(DEFAULT) == 0);
        } break; case 79: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            ItemType x;
            assert(m.get(-1, x) == 0);
        } break; case 80: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            ItemType x = DUMMY;
            m.get(-1, x);
            assert(x == DUMMY);
        } break; case 81: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            ItemType x;
            assert(m.get(3, x) == 0);
        } break; case 82: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            ItemType x = DUMMY;
            m.get(3, x);
            assert(x == DUMMY);
        } break; case 83: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[1]);
            ItemType x = DUMMY;
            assert(m.getLeastFrequentValue(x));
        } break; case 84: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[1]);
            ItemType x = DUMMY;
            m.getLeastFrequentValue(x);
            assert(x == ARRAY[2]);
        } break; case 85: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[1]);
            ItemType x = DUMMY;
            assert(!m.getLeastFrequentValue(x));
        } break; case 86: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[1]);
            ItemType x = DUMMY;
            m.getLeastFrequentValue(x);
            assert(x == DUMMY);
        } break; case 87: {
            m.insert(ARRAY[1]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[3]);
            ItemType x = DUMMY;
            m.getSmallestValue(x);
            assert(x == ARRAY[0]);
        } break; case 88: {
            m.insert(ARRAY[2]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[0]);
            ItemType x = DUMMY;
            m.getSmallestValue(x);
            assert(x == ARRAY[0]);
        } break; case 89: {
            m.insert(ARRAY[2]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[0]);
            m.erase(ARRAY[1]);
            m.erase(ARRAY[0]);
            ItemType x = DUMMY;
            m.getSmallestValue(x);
            assert(x == ARRAY[2]);
        } break; case 90: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[3]);
            ItemType x = DUMMY;
            m.getSecondSmallestValue(x);
            assert(x == ARRAY[1]);
        } break; case 91: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[3]);
            ItemType x = DUMMY;
            m.getSecondSmallestValue(x);
            assert(x == ARRAY[1]);
        } break; case 92: {
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[3]);
            ItemType x = DUMMY;
            m.getSecondSmallestValue(x);
            assert(x == ARRAY[1]);
        } break; case 93: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[2]);
            ItemType x = DUMMY;
            m.getSecondSmallestValue(x);
            assert(x == ARRAY[1]);
        } break; case 94: {
            m.insert(ARRAY[2]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[0]);
            m.erase(ARRAY[1]);
            m.erase(ARRAY[0]);
            ItemType x = DUMMY;
            m.getSecondSmallestValue(x);
            assert(x == ARRAY[3]);
        } break; case 95: {
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            assert(!m.replace(ARRAY[2], ARRAY[4])  &&  m.uniqueSize() == 3  &&
                   m.size() == 3  &&  m.count(ARRAY[0]) == 1  &&
                   m.count(ARRAY[1]) == 1  &&  m.count(ARRAY[3]) == 1);
        } break; case 96: {
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            assert(m.replace(ARRAY[0], ARRAY[2]));
        } break; case 97: {
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            m.replace(ARRAY[0], ARRAY[2]);
            assert(m.uniqueSize() == 3  &&  m.size() == 3  &&
                   m.count(ARRAY[1]) == 1  &&  m.count(ARRAY[2]) == 1  &&
                   m.count(ARRAY[3]) == 1  &&  m.count(ARRAY[0]) == 0);
        } break; case 98: {
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[3]);
            m.replace(ARRAY[0], ARRAY[2]);
            assert(m.uniqueSize() == 3  &&  m.size() == 6  &&
                   m.count(ARRAY[1]) == 1  &&  m.count(ARRAY[2]) == 2  &&
                   m.count(ARRAY[3]) == 3  &&  m.count(ARRAY[0]) == 0);
        } break; case 99: {
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[3]);
            m.replace(ARRAY[0], ARRAY[3]);
            assert(m.uniqueSize() == 2  &&  m.size() == 6  &&
                   m.count(ARRAY[1]) == 1  &&  m.count(ARRAY[3]) == 5  &&
                   m.count(ARRAY[0]) == 0);
        } break; case 100: {
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[3]);
            m.replace(ARRAY[3], ARRAY[3]);
            assert(m.uniqueSize() == 3  &&  m.size() == 6  &&
                   m.count(ARRAY[0]) == 2  &&  m.count(ARRAY[1]) == 1  &&
                   m.count(ARRAY[3]) == 3);
        } break; case 101: {
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[3]);
            m.replace(ARRAY[0], DEFAULT);
            m.insert(ARRAY[4]);
            m.erase(ARRAY[2]);
            m.replace(DEFAULT, ARRAY[5]);
            assert(m.uniqueSize() == 4  &&  m.size() == 4  &&
                   m.count(ARRAY[0]) == 0  &&  m.count(ARRAY[1]) == 1  &&
                   m.count(ARRAY[2]) == 0  &&  m.count(ARRAY[3]) == 1  &&
                   m.count(ARRAY[4]) == 1  &&  m.count(ARRAY[5]) == 1  &&
                   m.count(DEFAULT) == 0);
        } break; case 102: {
            m.insert(ARRAY[3]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[4]);
            assert(m.countIf('$', ARRAY[2]) == -1);
        } break; case 103: {
            m.insert(ARRAY[3]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[4]);
            assert(m.countIf('=', ARRAY[2]) == 2);
        } break; case 104: {
            m.insert(ARRAY[3]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[4]);
            assert(m.countIf('<', ARRAY[2]) == 3);
        } break; case 105: {
            m.insert(ARRAY[3]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[4]);
            assert(m.countIf('>', ARRAY[2]) == 4);
        } break; case 106: {
            m.insert(ARRAY[3]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[4]);
            assert(m.countIf('>', ARRAY[4]) == 0);
        } break; case 107: {
            Multiset<ItemType> m2;
            m.copyIntoOtherMultiset(m2);
            assert(m2.uniqueSize() == 0  &&  m2.size() == 0);
        } break; case 108: {
            Multiset<ItemType> m2;
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[0]);
            m2.insert(ARRAY[1]);
            m.copyIntoOtherMultiset(m2);
            assert(m2.uniqueSize() == 2  &&  m2.size() == 3  &&
                   m2.count(ARRAY[0]) == 1  &&  m2.count(ARRAY[1]) == 2);
        } break; case 109: {
            Multiset<ItemType> m2;
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[0]);
            m2.insert(ARRAY[1]);
            m2.copyIntoOtherMultiset(m);
            assert(m.count(ARRAY[0]) == 1  &&  m.count(ARRAY[1]) == 2);
        } break; case 110: {
            Multiset<ItemType> m2;
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[0]);
            m2.insert(ARRAY[1]);
            m2.copyIntoOtherMultiset(m);
            assert(m.uniqueSize() == 2  &&  m.size() == 3);
        } break; case 111: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            Multiset<ItemType> m2;
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[0]);
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[2]);
            m.copyIntoOtherMultiset(m2);
            assert(m2.uniqueSize() == 3  &&
                   m2.count(ARRAY[0]) == 4  &&  m2.count(ARRAY[1]) == 3  &&
                   m2.count(ARRAY[2]) == 1);
        } break; case 112: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[3]);
            Multiset<ItemType> m2;
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[0]);
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[2]);
            m.copyIntoOtherMultiset(m2);
            assert(m2.count(ARRAY[0]) == 3  &&  m2.count(ARRAY[1]) == 2  &&
                   m2.count(ARRAY[2]) == 1  &&  m2.count(ARRAY[3]) == 2  &&
                   m2.count(ARRAY[4]) == 1);
        } break; case 113: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[3]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[3]);
            Multiset<ItemType> m2;
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[0]);
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[2]);
            m.copyIntoOtherMultiset(m2);
            assert(m2.uniqueSize() == 5  &&  m2.size() == 9);
        } break; case 114: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            {
                Multiset<ItemType> m2;
                m2.insert(ARRAY[2]);
                m2.insert(ARRAY[3]);
                m2.insert(ARRAY[1]);
                m2.insert(ARRAY[1]);
                m.swap(m2);
                assert(m.size() == 4  &&  m.uniqueSize() == 3);
            }
        } break; case 115: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            {
                Multiset<ItemType> m2;
                m2.insert(ARRAY[2]);
                m2.insert(ARRAY[3]);
                m2.insert(ARRAY[1]);
                m2.insert(ARRAY[1]);
                m.swap(m2);
                assert(m.count(ARRAY[1]) == 2  &&  m.count(ARRAY[2]) == 1  &&
                       m.count(ARRAY[3]) == 1  &&  m.count(ARRAY[0]) == 0);
            }
        } break; case 116: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            {
                Multiset<ItemType> m2;
                m2.insert(ARRAY[2]);
                m2.insert(ARRAY[3]);
                m2.insert(ARRAY[1]);
                m2.insert(ARRAY[1]);
                m.swap(m2);
                assert(m2.size() == 2  &&  m2.uniqueSize() == 2);
            }
        } break; case 117: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            {
                Multiset<ItemType> m2;
                m2.insert(ARRAY[2]);
                m2.insert(ARRAY[3]);
                m2.insert(ARRAY[1]);
                m2.insert(ARRAY[1]);
                m.swap(m2);
                assert(m2.count(ARRAY[0]) == 1  &&  m2.count(ARRAY[1]) == 1  &&
                       m2.count(ARRAY[2]) == 1  &&  m2.count(ARRAY[3]) == 0);
            }
        } break; case 118: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[3]);
            {
                Multiset<ItemType> m2;
                m2.insert(ARRAY[4]);
                m2.insert(ARRAY[5]);
                m2.insert(ARRAY[6]);
                int n = nasstcopys();
                m.swap(m2);
                int n2 = nasstcopys();
                assert(n2 >= n  &&  n2 <= n + 3);  // swapping head nodes OK
            }
        } break; case 119: {
            int before = itemcount();
            {
                Multiset<ItemType> m2;
                m2.insert(DUMMY);
                assert(itemcount() > before);
            }
            assert(itemcount() == before);
        } break; case 120: {
            {
                Multiset<ItemType> m2;
                m2.insert(ARRAY[0]);
                m2.insert(ARRAY[1]);
                m2.insert(ARRAY[2]);
                m2.erase(ARRAY[1]);
                m2.insert(ARRAY[3]);
                m2.erase(ARRAY[2]);
                m2.insert(ARRAY[1]);
                m2.erase(ARRAY[0]);
            }
            assert(true);  // no corruption so bad that destruction failed
        } break; case 121: {
            {
                Multiset<ItemType> m2;
                m2.insert(ARRAY[0]);
                m2.insert(ARRAY[1]);
                Multiset<ItemType> m3(m2);
                m3.insert(ARRAY[2]);
                m3.erase(ARRAY[1]);
                m3.insert(ARRAY[3]);
                m3.erase(ARRAY[2]);
                m3.insert(ARRAY[1]);
                m3.erase(ARRAY[0]);
            }
            assert(true);  // no corruption so bad that destruction failed
        } break; case 122: {
            int before = itemcount();
            {
                Multiset<ItemType> m2;
                m2.insert(ARRAY[0]);
                m2.insert(ARRAY[1]);
                m2.insert(ARRAY[2]);
                int n2 = itemcount() - before;
                Multiset<ItemType> m3(m2);
                int n3 = itemcount() - before;
                assert(n3 = 2*n2);
            }
        } break; case 123: {
            {
                Multiset<ItemType> m2(m);
                assert(m2.uniqueSize() == 0  &&  m2.size() == 0);
                m2.insert(ARRAY[0]);
                assert(m2.uniqueSize() == 1  &&  m2.size() == 1  &&
                       m2.count(ARRAY[0]) == 1);
                m2.erase(ARRAY[0]);
                assert(m2.uniqueSize() == 0  &&  m2.size() == 0  &&
                       m2.count(ARRAY[0]) == 0);
            }
        } break; case 124: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            {
                Multiset<ItemType> m2(m);
                m2.insert(ARRAY[3]);
                assert(m2.size() == m.size()+1  &&
                       m2.uniqueSize() == m.uniqueSize()+1);
            }
        } break; case 125: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            {
                Multiset<ItemType> m2(m);
                m2.insert(ARRAY[3]);
                assert(m2.uniqueSize() == 4  &&  m2.count(ARRAY[0]) == 1  &&
                       m2.count(ARRAY[1]) == 1  &&  m2.count(ARRAY[2]) == 1  &&
                       m2.count(ARRAY[3]) == 1);
            }
        } break; case 126: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            {
                Multiset<ItemType> m2(m);
                m2.insert(ARRAY[3]);
                assert(m.uniqueSize() == 3  &&  m.count(ARRAY[0]) == 1  &&
                       m.count(ARRAY[1]) == 1  &&  m.count(ARRAY[2]) == 1  &&
                       m.count(ARRAY[3]) == 0);
            }
        } break; case 127: {
            {
                Multiset<ItemType> m2;
                m2.insert(ARRAY[0]);
                m2.insert(ARRAY[1]);
                Multiset<ItemType> m3;
                m3.insert(ARRAY[3]);
                m3.insert(ARRAY[4]);
                m3 = m2;
                m3.insert(ARRAY[2]);
                m3.erase(ARRAY[1]);
                m3.insert(ARRAY[3]);
                m3.erase(ARRAY[2]);
                m3.insert(ARRAY[1]);
                m3.erase(ARRAY[0]);
            }
            assert(true);  // no corruption so bad that destruction failed
        } break; case 128: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            int before = itemcount();
            {
                Multiset<ItemType> m2;
                m2.insert(ARRAY[2]);
                m2.insert(ARRAY[3]);
                m2.insert(ARRAY[4]);
                int mid = itemcount();
                m2 = m;
                assert(itemcount() <= mid);
            }
            assert(itemcount() == before);
        } break; case 129: {
            int before = itemcount();
            {
                Multiset<ItemType> m2;
                m2.insert(ARRAY[0]);
                m2.insert(ARRAY[1]);
                m2.insert(ARRAY[2]);
                int n2 = itemcount() - before;
                Multiset<ItemType> m3;
                m3.insert(ARRAY[3]);
                m3.insert(ARRAY[4]);
                m3 = m2;
                int n3 = itemcount() - before;
                assert(n3 = 2*n2);
            }
        } break; case 130: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            {
                Multiset<ItemType> m2;
                m2.insert(ARRAY[2]);
                m2.insert(ARRAY[3]);
                m2.insert(ARRAY[4]);
                m2 = m;
                m2.insert(ARRAY[5]);
                assert(m2.size() == m.size()+1  &&
                       m2.uniqueSize() == m.uniqueSize()+1);
            }
        } break; case 131: {
            {
                Multiset<ItemType> m2;
                m2 = m;
                assert(m2.uniqueSize() == 0  &&  m2.size() == 0);
                m2.insert(ARRAY[0]);
                assert(m2.uniqueSize() == 1  &&  m2.size() == 1  &&
                       m2.count(ARRAY[0]) == 1);
                m2.erase(ARRAY[0]);
                assert(m2.uniqueSize() == 0  &&  m2.size() == 0  &&
                       m2.count(ARRAY[0]) == 0);
            }
        } break; case 132: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            {
                Multiset<ItemType> m2;
                m2.insert(ARRAY[3]);
                m2.insert(ARRAY[4]);
                m2.insert(ARRAY[5]);
                m2 = m;
                m2.insert(ARRAY[2]);
                assert(m2.uniqueSize() == 3  &&  m2.count(ARRAY[0]) == 1  &&
                       m2.count(ARRAY[1]) == 1  &&  m2.count(ARRAY[2]) == 1  &&
                       m2.count(ARRAY[3]) == 0);
            }
        } break; case 133: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            {
                Multiset<ItemType> m2;
                m2.insert(ARRAY[3]);
                m2.insert(ARRAY[4]);
                m2.insert(ARRAY[5]);
                m2 = m;
                m2.insert(ARRAY[2]);
                assert(m.uniqueSize() == 2  &&  m.count(ARRAY[0]) == 1  &&
                       m.count(ARRAY[1]) == 1  &&  m.count(ARRAY[2]) == 0  &&
                       m.count(ARRAY[3]) == 0);
            }
        } break; case 134: {
            {
                Multiset<ItemType> m2;
                m2.insert(ARRAY[1]);
                m2.insert(ARRAY[0]);
                m2.insert(ARRAY[2]);
                int n2 = itemcount();
                m2 = m2;
                assert(itemcount() == n2);
                assert(m2.uniqueSize() == 3  &&  m2.count(ARRAY[0]) == 1  &&
                       m2.count(ARRAY[1]) == 1  &&  m2.count(ARRAY[2]) == 1);
            }
            assert(true);  // no corruption so bad that destruction failed
        } break; case 135: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            Multiset<ItemType> m2;
            Multiset<ItemType> m3;
            combine(m,m2,m3);
            assert(m3.size() == 3  &&  m3.uniqueSize() == 2);
            assert(m3.count(ARRAY[0]) == 2  &&  m3.count(ARRAY[1]) == 1);
        } break; case 136: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            Multiset<ItemType> m2;
            Multiset<ItemType> m3;
            combine(m2,m,m3);
            assert(m3.size() == 3  &&  m3.uniqueSize() == 2);
            assert(m3.count(ARRAY[0]) == 2  &&  m3.count(ARRAY[1]) == 1);
        } break; case 137: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            Multiset<ItemType> m2;
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[2]);
            Multiset<ItemType> m3;
            combine(m,m2,m3);
            assert(m3.size() == 5  &&  m3.uniqueSize() == 3);
            assert(m3.count(ARRAY[0]) == 2  &&  m3.count(ARRAY[1]) == 2  &&
                   m3.count(ARRAY[2]) == 1);
        } break; case 138: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            Multiset<ItemType> m2;
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[2]);
            Multiset<ItemType> m3;
            m3.insert(ARRAY[3]);
            combine(m,m2,m3);
            assert(m3.size() == 5  &&  m3.uniqueSize() == 3);
            assert(m3.count(ARRAY[0]) == 2  &&  m3.count(ARRAY[1]) == 2  &&
                   m3.count(ARRAY[2]) == 1  &&  m3.count(ARRAY[3]) == 0);
        } break; case 139: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            Multiset<ItemType> m2;
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[2]);
            combine(m,m2,m);
            assert(m.size() == 5  &&  m.uniqueSize() == 3);
            assert(m.count(ARRAY[0]) == 2  &&  m.count(ARRAY[1]) == 2  &&
                   m.count(ARRAY[2]) == 1  &&  m.count(ARRAY[3]) == 0);
        } break; case 140: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            Multiset<ItemType> m2;
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[2]);
            combine(m2,m,m);
            assert(m.size() == 5  &&  m.uniqueSize() == 3);
            assert(m.count(ARRAY[0]) == 2  &&  m.count(ARRAY[1]) == 2  &&
                   m.count(ARRAY[2]) == 1  &&  m.count(ARRAY[3]) == 0);
        } break; case 141: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            Multiset<ItemType> m2;
            Multiset<ItemType> m3;
            subtract(m,m2,m3);
            assert(m3.size() == 3  &&  m3.uniqueSize() == 2);
            assert(m3.count(ARRAY[0]) == 2  &&  m3.count(ARRAY[1]) == 1);
        } break; case 142: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[0]);
            Multiset<ItemType> m2;
            Multiset<ItemType> m3;
            subtract(m2,m,m3);
            assert(m3.size() == 0  &&  m3.uniqueSize() == 0);
            assert(m3.count(ARRAY[0]) == 0  &&  m3.count(ARRAY[1]) == 0);
        } break; case 143: {
            m.insert(ARRAY[3]);
            m.insert(ARRAY[4]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            m.insert(ARRAY[5]);
            m.insert(ARRAY[0]);
            m.insert(ARRAY[2]);
            Multiset<ItemType> m2;
            m2.insert(ARRAY[0]);
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[0]);
            m2.insert(ARRAY[4]);
            m2.insert(ARRAY[6]);
            m2.insert(ARRAY[3]);
            m2.insert(ARRAY[3]);
            m2.insert(ARRAY[6]);
            Multiset<ItemType> m3;
            subtract(m,m2,m3);
            assert(m3.size() == 4  &&  m3.uniqueSize() == 3);
            assert(m3.count(ARRAY[0]) == 0  &&  m3.count(ARRAY[1]) == 1  &&
                   m3.count(ARRAY[2]) == 2  &&  m3.count(ARRAY[3]) == 0  &&
                   m3.count(ARRAY[4]) == 0  &&  m3.count(ARRAY[5]) == 1  &&
                   m3.count(ARRAY[6]) == 0);
        } break; case 144: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            Multiset<ItemType> m2;
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[2]);
            Multiset<ItemType> m3;
            m3.insert(ARRAY[3]);
            m3.insert(ARRAY[4]);
            subtract(m,m2,m3);
            assert(m3.size() == 1  &&  m3.uniqueSize() == 1);
            assert(m3.count(ARRAY[0]) == 1  &&  m3.count(ARRAY[1]) == 0  &&
                   m3.count(ARRAY[2]) == 0  &&  m3.count(ARRAY[3]) == 0  &&
                   m3.count(ARRAY[4]) == 0);
        } break; case 145: {
            m.insert(ARRAY[0]);
            m.insert(ARRAY[1]);
            Multiset<ItemType> m2;
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[2]);
            subtract(m,m2,m);
            assert(m.size() == 1  &&  m.uniqueSize() == 1);
            assert(m.count(ARRAY[0]) == 1  &&  m.count(ARRAY[1]) == 0  &&
                   m.count(ARRAY[2]) == 0);
        } break; case 146: {
            m.insert(ARRAY[1]);
            m.insert(ARRAY[2]);
            Multiset<ItemType> m2;
            m2.insert(ARRAY[1]);
            m2.insert(ARRAY[0]);
            subtract(m2,m,m);
            assert(m.size() == 1  &&  m.uniqueSize() == 1);
            assert(m.count(ARRAY[0]) == 1  &&  m.count(ARRAY[1]) == 0  &&
                   m.count(ARRAY[2]) == 0);
        } break; case 147: {
            const int NITEMS = 2000;
            for (int k = 0; k < NITEMS; k++)
                assert(m.insert(ItemType(k)));
            assert(m.size() == NITEMS);
        }
    }
}

int main()
{
    for (int i=0;i<148;i++)
    {
    xxxtestone(i);
    }
    cout << "Passed" << endl;
}