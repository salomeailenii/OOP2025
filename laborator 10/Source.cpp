#include <iostream>
#include <exception>
using namespace std;

class exceptie1 : public exception
{
    virtual const char* what() const throw()
    {
        return "Indexul este inafara domeniului!";
    }
};
class exceptie2 :public exception
{
    virtual const char* what() const throw()
    {
        return "Array-ul este gol!";
    }
};
class exceptie3 :public exception
{
    virtual const char* what() const throw()
    {
        return "Sortarea nu se poate efectua!";
    }
};

class Compare
{
public:
    virtual ~Compare() {}
    virtual int CompareElements(void* e1, void* e2) = 0;
};
class ObiectCompare : public Compare {
public:
    int CompareElements(void* e1, void* e2) {
        int* a = static_cast<int*>(e1);
        int* b = static_cast<int*>(e2);
        if (*a < *b) return -1;
        if (*a > *b) return 1;
        return 0;
    }
};

template<class T>
class ArrayIterator
{
private:
    int Current; // mai adaugati si alte date si functii necesare pentru iterator
    T** List;
    int Size;
public:
    ArrayIterator(T** list, int size) : List(list), Size(size), Current(0) {}
    ArrayIterator& operator ++ () {
        if (Current < Size)
            Current++;
        return *this;
    }
    ArrayIterator& operator -- () {
        if (Current > 0)
            --Current;
        return *this;
    }
    ArrayIterator<T>& operator= (const ArrayIterator<T>& other) {
        if (this != &other) {
            this->Current = other.Current;
            this->pArray = other.pArrey;
        }
        return *this;
    }
    bool operator!=(ArrayIterator<T>& other) {
        return !(*this == other);
    }
    T* GetElement() {
        return List[Current];
    }
};

template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array(){
        List = nullptr;
        Capacity = 0;
        Size = 0;
    } // Lista nu e alocata, Capacity si Size = 0
    ~Array() { // destructor
        for (int i = 0;i < Capacity;i++)
            List[i] = nullptr;
    }
    Array(int capacity){
        if (capacity > MAX_CAPACITY)
            throw exceptie3();
        List = new T * [capacity];
        Capacity = capacity;
        Size = 0;
    } // Lista e alocata cu 'capacity' elemente
    Array(const Array<T>& otherArray) { // constructor de copiere
        for (int i = 0;i < Capacity;i++)
            List[i] = nullptr;
        for (int i = 0;i < Size;i++)
            List[i] = new T(*(otherArray.List[i]));
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
    }
    T& operator[] (int index) { // arunca exceptie daca index este out of range
        if (Size == 0)
            throw exceptie2();
        if (index < 0 || index >= Size)
            throw exceptie1();
        return* List[index];
    }
    const Array<T>& operator+=(const T& newElem) { // adauga un element de tipul T la sfarsitul listei si returneaza this
        if (Size == Capacity) {
            if (Capacity == 0)
                Capacity = 1;
            else
                Capacity *= 2;
            T** newList = new T * [Capacity];
            for (int i = 0;i < Size;i++)
                newList[i] = List[i];
            for (int i = Size;i < Capacity;i++)
                newList[i] = nullptr;
            delete[] List;
            List = newList;
        }
        List[Size] = new T(newElem);
        Size++;
        return *this;
    }
    
    const Array<T>& Insert(int index, const T& newElem){ // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
        if (index < 0 || index>Size)
            throw exceptie1();
        if (Size == Capacity) {
            if (Capacity == 0)
                Capacity = 1;
            else
                Capacity *= 2;
            T** newList = new T * [Capacity];
            for (int i = 0;i < Size;i++)
                newList[i] = List[i];
            for (int i = Size;i < Capacity;i++)
                newList[i] = nullptr;
            delete[] List;
            List = newList;
        }
        for (int i = Size - 1;i >= index;i--)
            List[i + 1] = List[i];
        List[index] = new T(newElem);
        Size++;
        return *this;
    }
    
    const Array<T>& Insert(int index, const Array<T> otherArray) { // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
        if (index <0 || index>Size)
            throw exceptie1();
        int otherSize = otherArray.Size;
        if (otherSize == 0)
            return *this;
        if (Size + otherSize > Capacity) {
            int newCapacity;
            if (Capacity == 0)
                newCapacity = 1;
            else
                newCapacity = Capacity;
            while(newCapacity<Size+otherSize)
                 newCapacity *= 2;
            T** newList = new T * [newCapacity];
            for (int i = 0;i < index;i++)
                newList[i] = List[i];
            for (int i = 0;i < otherSize;i++)
                newList[index + i] = new T(*otherArray.List[i]);
            for (int i = index; i < Size;i++)
                newList[i + otherSize] = List[i];
            for (int i = Size + otherSize;i < newCapacity;i++)
                newList[i] = nullptr;
            delete[] List;
            List = newList;
            Capacity = newCapacity;
        }
        else {
            for (int i = Size - 1;i >= index;i--)
                List[i + otherSize] = List[i];
            for (int i = 0;i < otherSize;i++)
                List[index + i] = new T(*otherArray.List[i]);
        }
        Size += otherSize;
        return *this;
    }
    const Array<T>& Delete(int index) { // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
        if (index < 0 || index >= Size)
            throw exceptie1();
        delete List[index];
        for (int i = index;i < Size - 1;i++)
            List[i] = List[i + 1];
        
        List[Size-1] = nullptr;
        Size--;
        return *this;
    }
    bool operator=(const Array<T>& otherArray) {
        if (this == &otherArray)
            return true;
        for (int i = 0;i < Size;i++)
            delete List[i];
        delete[] List;
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i=0;i < Size;i++)
            List[i] = new T(*otherArray.List[i]);
        for (int i = Size;i < Capacity;i++)
            List[i] = nullptr;
        return true;
    }
    
    void Sort() { // sorteaza folosind comparatia intre elementele din T
        sort(List, List + Size);
    }
    void Sort(int(*compare)(const T&, const T&)) { // sorteaza folosind o functie de comparatie
        sort(List, List + Size, compare);
    }
    void Sort(Compare* comparator) { // sorteaza folosind un obiect de comparatie
        if (Size <= 1)
            throw exceptie3();
        for (int i = 0;i < Size - 1;i++) {
            for (int j = i + 1;j < Size;j++) {
                if (comparator->CompareElements(List[i], List[j]) > 0) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }
    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) { // cauta un element folosind binary search in Array
        int left = 0;
        int right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (*List[mid] == elem)
                return mid;
            else
                if (*List[mid] < elem)
                    left = mid + 1;
                else
                    right = mid - 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {//  cauta un element folosind binary search si o functie de comparatie
        int left = 0;
        int right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int comp = compare(*List[mid], elem);
            if (comp == 0)
                return mid;
            else
                if (comp < 0)
                    left = mid + 1;
                else
                    right = mid - 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, Compare* comparator) {//  cauta un element folosind binary search si un comparator
        int left = 0;
        int right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int comp = comparator->CompareElements(List[mid], &elem);
            if (comp == 0)
                return mid;
            else
                if (comp < 0)
                    left = mid + 1;
                else
                    right = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem) { // cauta un element in Array
        for (int i = 0;i < Size;i++)
            if (*List[i] == elem)
                return i;
        return -1;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&)) {//  cauta un element folosind o functie de comparatie
        for (int i = 0;i < Size;i++)
            if (compare(*List[i], elem) == 0)
                return i;
        return -1;
    }
    int Find(const T& elem, Compare* comparator) {//  cauta un element folosind un comparator
        for (int i = 0;i < Size;i++)
            if (comparator->CompareElements(List[i], &elem) == 0)
                return i;
        return -1;
    }
    
    int GetSize() {
        return Size; 
    }
    int GetCapacity() {
        return Capacity;
    }
   
    ArrayIterator<T> GetBeginIterator() {
        ArrayIterator<T> it;
        it.Current = 0;
        return it;
    }
    ArrayIterator<T> GetEndIterator() {
        ArrayIterator<T> it;
        it.Current = Size;
        return it;
    }
    void Print() const {
        for (int i = 0; i < Size; i++)
            cout << *List[i] << " ";
        cout << endl;
    }
};

int main() {
    try {
        Array<int> arr(3);
        arr += 1;
        arr += 2;
        arr += 3;
        arr.Print();
        cout << endl;
        arr.Insert(-1, 100);
        arr.Print();
        cout << endl;
        
    }
    catch (const exception& e) {
        cout << "Exceptie prinsa: " << e.what() << endl;
    }
    try {
        Array<int> arr;
        cout << arr[0];
    }
    catch (const exception& e) {
        cout << "Exceptie prinsa: " << e.what() << endl;
    }
    try {
        Array<int> arr(2);
        arr += 2;
        ObiectCompare comp;
        arr.Sort(&comp);
    }
    catch (const exception& e) {
        cout << "Exceptie prinsa: " << e.what() << endl;
    }
    return 0;
}
