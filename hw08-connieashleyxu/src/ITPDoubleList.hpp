// ITPDoubleList.hpp
// Defines and implements the ITPDoubleList collection

#pragma once
#include <ostream>
#include <sstream>
#include <stdexcept>

template <typename T>
class ITPDoubleList
{
private:
    // Node only used internally to list
    struct Node
    {
        // Data in this node
        T mData;
        // Link to previous node
        Node *mPrev;
        // Link to next node
        Node *mNext;
    };

    // Pointer to the head node
    Node *mHead;
    // Pointer to the tail node
    Node *mTail;
    // Number of nodes currently in the list
    unsigned mSize;

public:
    // Iterator helper class...
    class Iterator
    {
    private:
        Node *mCurr;

    public:
        // Needed for List access
        friend class ITPDoubleList;
        // Constructors
        Iterator() : mCurr(nullptr)
        {
        }

        Iterator(Node *inCurr) : mCurr(inCurr)
        {
        }

        Iterator(const Iterator &src) : mCurr(src.mCurr)
        {
        }

        // Assignment
        Iterator &operator=(const Iterator &src)
        {
            mCurr = src.mCurr;
            return *this;
        }

        // Incrementors / Decrementors
        // ++i
        Iterator &operator++()
        {
            if (mCurr)
            {
                mCurr = mCurr->mNext;
            }
            return *this;
        }

        // i++
        Iterator operator++(int)
        {
            Iterator temp(*this);
            ++(*this);
            return temp;
        }

        // --i
        Iterator &operator--()
        {
            if (mCurr)
            {
                mCurr = mCurr->mPrev;
            }
            return *this;
        }

        // i--
        Iterator operator--(int)
        {
            Iterator temp(*this);
            --(*this);
            return temp;
        }

        // Dereference
        T &operator*() const
        {
            if (mCurr)
            {
                return mCurr->mData;
            }
            throw std::runtime_error("Dereferencing a nullptr iterator.");
        }

        Node *operator->() const
        {
            return mCurr;
        }

        // Comparison
        bool operator==(const Iterator &rhs) const
        {
            return mCurr == rhs.mCurr;
        }

        bool operator!=(const Iterator &rhs) const
        {
            return mCurr != rhs.mCurr;
        }
    };

    // List functions...

    // Function: Default Constructor
    // Purpose: Initializes size to 0 and head/tail to null
    // Input: None
    // Returns: Nothing
    ITPDoubleList()
    {
        mSize = 0;
        mHead = nullptr;
        mTail = nullptr;
    }

    // Function: Copy Constructor
    // Purpose: Initializes this list as a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: Nothing
    ITPDoubleList(const ITPDoubleList &other)
    {
        mSize = 0;
        mHead = nullptr;
        mTail = nullptr;

        Node *otherCurrent = other.mHead;
        while (otherCurrent != nullptr)
        {
            push_back(otherCurrent->mData);
            otherCurrent = otherCurrent->mNext;
        }
    }

    // Function: Destructor
    // Purpose: Calls the clear function to delete the list
    // Input: None
    // Returns: Nothing
    ~ITPDoubleList()
    {
        clear();
    }

    // Function: clear
    // Purpose: Deletes every node in this list, sets size to 0, and head/tail to null
    // Input: None
    // Returns: Nothing
    void clear()
    {
        while (mHead != nullptr)
        {
            Node *temp = mHead;
            mHead = mHead->mNext;
            delete temp;
        }
        mSize = 0;
        mTail = nullptr;
    }

    // Assignment Operator
    // Function: Assignment Operator
    // Purpose: Clear this list, and then make a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: *this
    ITPDoubleList &operator=(const ITPDoubleList &other)
    {
        if (this != &other) // Check for self-assignment
        {
            clear(); // Clear the current list
            Node *otherCurrent = other.mHead;
            while (otherCurrent != nullptr)
            {
                push_back(otherCurrent->mData);
                otherCurrent = otherCurrent->mNext;
            }
        }
        return *this;
    }

    // Function: size
    // Purpose: Gets the current size of the linked list
    // Input: None
    // Returns: size of the list
    unsigned size() const
    {
        return mSize;
    }

    // Function: push_front
    // Purpose: Inserts a node at the front of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_front(const T &value)
    {
        Node *newNode = new Node{value, nullptr, mHead};
        if (mHead)
        {
            mHead->mPrev = newNode;
        }
        mHead = newNode;

        if (!mTail)
        {
            mTail = mHead;
        }

        mSize++;
    }

    // Function: front
    // Purpose: Gets the value of the node at the front of the list
    // Input: None
    // Returns: Value of the node at the front of the list
    T &front()
    {
        if (mHead)
        {
            return mHead->mData;
        }
        throw std::runtime_error("List is empty.");
    }

    // Function: pop_front
    // Purpose: Removes the node at the front of the list
    // Input: None
    // Returns: None
    void pop_front()
    {
        if (mHead)
        {
            Node *temp = mHead;
            mHead = mHead->mNext;
            if (mHead)
            {
                mHead->mPrev = nullptr;
            }
            delete temp;
            mSize--;

            if (mSize == 0)
            {
                mTail = nullptr;
            }
        }
        else
        {
            throw std::runtime_error("List is empty.");
        }
    }

    // Function: push_back
    // Purpose: Inserts a node at the end of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_back(const T &value)
    {
        Node *newNode = new Node{value, mTail, nullptr};
        if (mTail)
        {
            mTail->mNext = newNode;
        }
        mTail = newNode;

        if (!mHead)
        {
            mHead = mTail;
        }

        mSize++;
    }

    // Function: front
    // Purpose: Gets the value of the node at the front of the list
    // Input: None
    // Returns: Value of the node at the front of the list
    T &back()
    {
        if (mTail)
        {
            return mTail->mData;
        }
        throw std::runtime_error("List is empty.");
    }

    // Function: pop_back
    // Purpose: Removes the node at the end of the list
    // Input: None
    // Returns: None
    void pop_back()
    {
        if (mTail)
        {
            Node *temp = mTail;
            mTail = mTail->mPrev;
            if (mTail)
            {
                mTail->mNext = nullptr;
            }
            delete temp;
            mSize--;

            if (mSize == 0)
            {
                mHead = nullptr;
            }
        }
        else
        {
            throw std::runtime_error("List is empty.");
        }
    }

    // Function: begin
    // Purpose: Gets an iterator for the start of the list
    // Input: None
    // Returns: Iterator pointing to beginning of list
    Iterator begin() const
    {
        return Iterator(mHead);
    }

    // Function: end
    // Purpose: Gets an iterator for the end of the list
    // Input: None
    // Returns: Iterator pointing to end of list
    Iterator end() const
    {
        return Iterator(nullptr);
    }

    // Function: erase
    // Purpose: Removes the item at the node pointed to by i
    // Input: Iterator pointing to a valid node to remove before
    // Returns: A new iterator pointing to the node after the removed item
    Iterator erase(Iterator &i)
    {
        if (i.mCurr)
        {
            Node *curr = i.mCurr;
            Node *prev = curr->mPrev;
            Node *next = curr->mNext;

            if (prev)
            {
                prev->mNext = next;
            }
            else
            {
                mHead = next;
            }

            if (next)
            {
                next->mPrev = prev;
            }
            else
            {
                mTail = prev;
            }

            delete curr;
            mSize--;

            return Iterator(next);
        }
        throw std::runtime_error("Invalid iterator.");
    }

    // Function: insert
    // Purpose: Inserts a list item before node pointed to by i
    // Input: Iterator pointing to a valid node to insert before
    // Returns: A new iterator pointing to the inserted value
    Iterator insert(Iterator &i, const T &val)
    {
        if (i.mCurr)
        {
            Node *curr = i.mCurr;
            Node *prev = curr->mPrev;
            Node *newNode = new Node{val, prev, curr};

            if (prev)
            {
                prev->mNext = newNode;
            }
            else
            {
                mHead = newNode;
            }

            curr->mPrev = newNode;
            mSize++;

            return Iterator(newNode);
        }
        throw std::runtime_error("Invalid iterator.");
    }

public:
    // Function: Output Stream Operator
    // Purpose: Prints the contents of the list to the provided stream
    // Written in the format of {x, y, ..., z}
    // Input: Stream to write to, list to write
    // Output: Stream after values are written
    friend std::ostream &operator<<(std::ostream &os, const ITPDoubleList<T> &list)
    {
        os << "{";
        Node *current = list.mHead;
        while (current != nullptr)
        {
            os << current->mData;
            current = current->mNext;
            if (current != nullptr)
            {
                os << ", ";
            }
        }
        os << "}";
        return os;
    }

    // Function: toString
    // Purpose: Converts list to a string
    // Input: None
    // Output: String (in the format as the ostream)
    std::string toString() const
    {
        std::ostringstream oss;
        oss << "{";
        Node *current = mHead;
        while (current != nullptr)
        {
            oss << current->mData;
            current = current->mNext;
            if (current != nullptr)
            {
                oss << ", ";
            }
        }
        oss << "}";
        return oss.str();
    }

    // Function: toReverseString
    // Purpose: Outputs the list in reverse
    // Input: None
    // Output: String in reverse
    std::string toReverseString() const
    {
        std::ostringstream oss;
        oss << "{";
        Node *current = mTail;
        while (current != nullptr)
        {
            oss << current->mData;
            current = current->mPrev;
            if (current != nullptr)
            {
                oss << ", ";
            }
        }
        oss << "}";
        return oss.str();
    }
};
