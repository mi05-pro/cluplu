#include <iostream>
using namespace std;

class List
{
public:
    List() : head(0), tail(0), theCount(0) {}
    virtual ~List();

    // Insert at the beginning of the list
    void insert(int value);

    // Append to the end of the list
    void append(int value);

    // Check if value is present in the list
    int is_present(int value) const;

    // Check if the list is empty
    int is_empty() const
    {
        return head == 0;
    }

    // Return the count of elements in the list
    int count() const { return theCount; }

    // Display the list (for debugging purposes)
    void display() const;

private:
    class ListCell
    {
    public:
        ListCell(int value, ListCell *cell = 0) : val(value), next(cell) {}
        int val;
        ListCell *next;
    };

    ListCell *head;
    ListCell *tail;
    int theCount;
};

// Destructor: clean up the list memory
List::~List()
{
    ListCell *current = head;
    while (current != nullptr)
    {
        ListCell *nextCell = current->next;
        delete current;
        current = nextCell;
    }
}

// Insert at the beginning of the list
void List::insert(int value)
{
    ListCell *newCell = new ListCell(value, head);
    head = newCell;
    if (tail == nullptr)  // If list was empty, tail should point to the new cell as well
    {
        tail = newCell;
    }
    theCount++;
}

// Append to the end of the list
void List::append(int value)
{
    ListCell *newCell = new ListCell(value);
    if (tail != nullptr)
    {
        tail->next = newCell;
        tail = newCell;
    }
    else
    {
        head = tail = newCell;  // If the list is empty, both head and tail should point to the new cell
    }
    theCount++;
}

// Check if value is present in the list
int List::is_present(int value) const
{
    ListCell *current = head;
    while (current != nullptr)
    {
        if (current->val == value)
        {
            return 1;  // Value is present
        }
        current = current->next;
    }
    return 0;  // Value not found
}

// Display the list (for debugging purposes)
void List::display() const
{
    ListCell *current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

// Main function for testing
int main()
{
    List myList;

    cout << "Is list empty? " << (myList.is_empty() ? "Yes" : "No") << endl;

    // Inserting values at the beginning
    myList.insert(10);
    myList.insert(20);
    myList.insert(30);
    cout << "After inserting 10, 20, 30 at the beginning: ";
    myList.display();

    // Appending values at the end
    myList.append(40);
    myList.append(50);
    cout << "After appending 40, 50: ";
    myList.display();

    // Check if a value is present
    cout << "Is 30 present? " << (myList.is_present(30) ? "Yes" : "No") << endl;
    cout << "Is 60 present? " << (myList.is_present(60) ? "Yes" : "No") << endl;

    // Output the count of elements in the list
    cout << "Count of elements: " << myList.count() << endl;

    return 0;
}
