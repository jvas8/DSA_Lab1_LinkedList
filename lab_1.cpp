// Lab 1: Singly Linked List for Username/Password storage

// Goal: Implement a simple credential store using a singly linked list

// Instructions:
// 1) Search for "TODO" and implement each function.
// 2) Build & run:   g++ -std=c++17 -O2 -Wall linked_lists.cpp -o lab && ./lab
// 3) Do not change function signatures

// NOTE: In the real world, NEVER store plaintext passwords.


// ADD HEADER FILES HERE

#include <iostream>
#include <string>
using namespace std;


// -----------------------------
// Data Model
// -----------------------------
struct User {
    string username;
    string password; 
    User* next;
    
    User(string u, string p) {
        username = u;
        password = p;
        next = nullptr;
    }
};


int main() {
  
    // Write code here to test your implementation
    User* head = nullptr;

    // Insert a few users
    insertUser(head, "alice", "123");
    insertUser(head, "bob", "456");
    insertUser(head, "charlie", "789");
    printUsers(head);

    // test duplicate
    cout << (insertUser(head, "alice", "000") ? "Inserted" : "Duplicate not allowed") << endl;

    // Find and  Authenticate
    cout << (findUser(head, "bob") ? "bob found" : "bob not found") << endl;
    cout << (authenticate(head, "bob", "456") ? "Auth success" : "Auth failed") << endl;

    // remove a user
    removeByUsername(head, "charlie");
    printUsers(head);

    // clear all
    clearList(head);
    printUsers(head);
    return 0;
}

// -----------------------------
// Core API — implement these
// -----------------------------

// Inserts a new (username, password) at the END of the list.
// If username already exists, do NOT insert a duplicate; return false.
// Otherwise insert and return true.
bool insertUser(User*& head, const string& username, const string& password) {
    // TODO: implement
    User* current = head;
    while(current != nullptr){
      if(current->username == username){
        return false; 
      }
      current = current->next;
    }
    if(head == nullptr){
     head = new User(username, password);
     return true;
    }
    current = head;
    while(current->next != nullptr){
       current = current->next;
    }
    current->next = new User(username, password);
   
    return false;
}

// Returns pointer to the node with matching username; otherwise nullptr.
User* findUser(User* head, const string& username) {
    // TODO: implement
    User* current = head;
    while(current != nullptr){
      if(current->username == username){
        return current;
      }
      current = current-> next;
    }
    return nullptr;
}

// Returns true if (username, password) matches an existing node; false otherwise.
bool authenticate(User* head, const string& username, const string& password) {
    // TODO: implement
    User* current = head;
    while(current != nullptr){
     if(current->username == username && current->password == password){
       return true;
      }
     current = current->next;
    }
    return false;
}

// Deletes the FIRST node (head) and updates head. No-op if list is empty.
// Return true if a node was deleted, false otherwise.
bool removeFront(User*& head) {
    // TODO: implement
    if(head == nullptr){
     return false;
   }

    User* temp = head;
    head = head-> next;
    delete temp;
    return true;
}

// Deletes the node with matching username (first match only).
// Return true if a node was found & deleted; false if not found.
bool removeByUsername(User*& head, const string& username) {

    // TODO: implement
    if (head == nullptr) {
        return false;
    }

    if (head->username == username) {
        User* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    User* prev = head;
    User* current = head->next;

    while (current != nullptr) {
        if (current->username == username) {
            prev->next = current->next;
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}
// Deletes ALL nodes and sets head=nullptr. 
void clearList(User*& head) {
    // TODO: implement
    User* current = head;
    while(current != nullptr){
     User* temp = current;
     current = current-> next;
    delete temp;
    }
   head = nullptr;
}

// Returns number of nodes.
size_t size(User* head) {
    // TODO: implement
    User* current = head;
   size_t count = 0;
    while(current != nullptr){
     count++;
     current = current->next;
    }
    return count;
}

// Prints usernames in order, separated by " -> " then " -> NULL".
// Example: alice -> bob -> charlie -> NULL
void printUsers(User* head) {
    User* current = head;
    while (current != nullptr) {
        cout << current->username << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}
