#include<iostream>
using namespace std;

template<typename  T>
struct dnode {
    dnode<T>* prev;
    T data;
    dnode<T>* next;
};

template<typename  T>
class list {
private:
    dnode<T>* Front;
    dnode <T>* Back;
    int n;

public:
    list() {
        Front = Back = NULL;
        n = 0;
    }

    ~list() {
        clear();
    }

    void push_front(const T& val) {
        dnode<T>* tempnew;
        tempnew = new dnode<T>;

        if (tempnew == NULL) {
            throw("list overfalow ");
        }

        tempnew->data = val;
        tempnew->prev = NULL;

        if (Front == NULL) {
            Front = Back = tempnew;
            tempnew->next = NULL;
        }
        else {
            tempnew->next = Front;
            Front->prev = tempnew;
            Front = tempnew;
        }

        n++;
    }

    void push_back(const T& val) {
        dnode<T>* tempnew;
        tempnew = new dnode<T>;

        if (tempnew == NULL) {
            throw("list overfalow ");
        }

        tempnew->data = val;
        tempnew->next = NULL;

        if (Back == NULL) {
            Front = Back = tempnew;
            tempnew->prev = NULL;
        }
        else {
            tempnew->prev = Back;
            Back->next = tempnew;
            Back = tempnew;
        }

        n++;
    }

    T front() {
        if (Front == NULL) {
            throw("list underfalow");
        }

        return Front->data;
    }

    T back() {
        if (Back == NULL) {
            throw("list underfalow");
        }

        return Back->data;
    }

    void pop_front() {
        if (Front == NULL) {
            throw("List Underflow!");
        }

        if (Front == Back) {
            delete Front;
            Back = NULL;
        }
        else {
            Front = Front->next;
            delete Front->prev;
            Front->prev = NULL;
        }
    }

    void pop_back() {
        if (Front == NULL) {
            throw("List Underflow!");
        }

        if (Front == Back) {
            delete Back;
            Front = NULL;
        }
        else {
            Back = Back->prev;
            delete Back->next;
            Back->next = NULL;
        }
    }

    bool empty() const {
        if (Front == Back && Back == NULL)
            return true;
        else
            return false;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    class reverse_Iterator {
    private:
        dnode<T>* ptr;
        friend class list;

    public:
        bool operator!=(const reverse_Iterator& rhs) {
            return ptr != rhs.ptr;
        }

        bool operator==(const reverse_Iterator& rhs) {
            return ptr == rhs.ptr;
        }
        bool  operator=(const reverse_Iterator& rhs) {
            return ptr = rhs.ptr;
            
        }
        reverse_Iterator& operator++() {
            ptr = ptr->prev;
        }

        reverse_Iterator&  operator++(int) {
            reverse_Iterator old = *this;
            operator++();
            return old;
        }
        reverse_Iterator& operator --()
        {
            ptr = ptr->next;
        }
        reverse_Iterator& operator --(int)
        {
            reverse_Iterator old = *this;
            operator--();
            return old;

        }
        T* operator->() {
            return &(ptr->data);
        }

        
        T& operator*() {
            return ptr->data;
        }
    };

    reverse_Iterator rbegin() {
        reverse_Iterator i;
        i.ptr = Back;
        return i;
    }

    reverse_Iterator rend() {
        reverse_Iterator i;
        i.ptr = NULL;
        return i;
    }
};

int main() {
    return 0;
}
