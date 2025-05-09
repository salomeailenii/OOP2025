#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string.h>

template<typename K, typename V>

class Map {
private:
    struct Entry {
        K key;
        V value;
    };

    Entry items[100];
    int count = 0;

public:
    V& operator[](K key) {
        for (int i = 0;i < count;i++) {
            if (items[i].key == key)
                return items[i].value;
        }
        items[count].key = key;
        count++;
        return items[count - 1].value;
    }

    void Set(const K key, V value) {
        for (int i = 0; i < count; i++) {
            if (items[i].key == key) {
                items[i].value = value;
                return;
            }
        }
        items[count].key = key;
        items[count].value = value;
        count++;
    }

    bool Get(const K& key, V& value) {
        for (int i = 0; i < count; i++) {
            if (items[i].key == key) {
                value = items[i].value;
                return true;
            }
        }
        return false;
    }
    int Count() {
        return count;
    };
    void Clear() {
        count = 0;
    }
    bool Delete(const K& key) {
        for (int i = 0; i < count; i++) {
            if (items[i].key == key) {
                for (int j = i; j < count - 1; j++)
                    items[j] = items[j + 1];
                count--;
                return true;
            }
        }
        return false;
    }
    bool Includes(const Map<K, V>& map) {
        for (int i = 0;i < map.count;i++) {
            bool ok = false;
            for (int j = 0;j < count;j++) {
                if (map.items[i].key == items[j].key) {
                    ok = true;
                    break;
                }
            }
            if (!ok)
                return false;
        }
        return true;
    }
    struct Iter {
        K* key;
        V* value;
        int index;
    };

    class MyIterator {
    private:
        Entry* p;
        int i;
    public:
        MyIterator(Entry* item, int index) {
            p = item;
            i = index;
        }
        Iter operator*() {
            Iter op;
            op.key = &p[i].key;
            op.value = &p[i].value;
            op.index = i;
            return op;
        }
        MyIterator& operator++() {
            i++;
            return *this;
        }
        bool operator!=(const MyIterator& ultim) {
            if (this->i != ultim.i)
                return true;
            else
                return false;
        }
    };
    MyIterator begin() {
        return MyIterator(items, 0);
    }
    MyIterator end() {
        return MyIterator(items, count);
    }



};

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, *key, *value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, *key, *value);
    }

    return 0;

}
