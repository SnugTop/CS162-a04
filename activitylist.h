#pragma once
#include "activity.h"


class Active_list
{

private:

struct Node {
Activity list;
Node *next;
};
Node *head;
Node *tail;
int count;


//------------------------
public:

//CONSTRUCTOR
Active_list();
//DESTRUCTOR
~Active_list();

//METHODS
void Open(char []);
void addActivity();
void addToList(Activity &);
void byLocation();
void byType();
void remove();
void searchByName();
void printLast();
void Backwards(Node*,int);
void printReverse(int);
void readOut();
bool lessThan(const char [],const char []);
int &getCount();
void Printlist();
};