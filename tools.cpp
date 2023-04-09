#include "activity.h"
#include "activitylist.h"
#include "tools.h"


void format_fun()
{
  cout << setw(65) << setfill('-') << " " << endl;
}
void intro()
{
  format_fun();
  cout << "Welcome to my Actvities List Editor" << endl;
  format_fun();
}
void print_menu()
{

  cout << "1. Add new activity" << endl;
  cout << "2. List Activities by name" << endl;
  cout << "3. List in Reverse Order" << endl;
  cout << "4. Print Last Element in List" << endl;
  cout << "5. Search Activities by type" << endl;
  cout << "6. Search by Activity name" << endl;
  cout << "7. Remove Activity" << endl;
  cout << "8. Quit" << endl;
  format_fun();
}
Type numtoType(int num)
{
 Type t;
  switch(num)
    {
    case 0:
    t = ATHLETIC;
    break;
    case 1:
    t = FOOD;
    break;
    case 2:
    t = ART;
    break;
    case 3:
    t = GAMES;
    break;
    case 4:
    t = OTHER;
    break;
    case 5:
    
    t = INVALID;
    break;
    
    default: 
    cout << "ERROR! Invalid input!" << endl;
   }
    
 return t;
}  
void menu(Active_list *newList)
{
 int user_input;
  print_menu();
  cout << "Make your menu selection: ";
  cin >> user_input; 
  format_fun();
  while(!cin || user_input < 1 || user_input > 8)
  {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Please try again" << endl;
        cout << "Enter Menu Selection: ";
        cin >> user_input;
        cout << endl;
        format_fun();
  }
  while(user_input != 99)
  {
     
    
    if(user_input == 1)
    {
      newList->addActivity();
    }

    else if(user_input == 2)
    {
      cout <<"Print by Name:"<<endl;
      cout <<"---------------" << endl;
      newList->Printlist();
      format_fun();
    }

    else if(user_input == 3)
    {
      int count = 0;
      count = newList->getCount();
      newList->printReverse(count);
     
      
    }

    else if(user_input == 4)
    {
      newList->printLast();
    }
      
    else if(user_input == 5)
    {
      newList->byType();
    }

    else if(user_input == 6)
    {
      newList->searchByName();

    }

    else if(user_input == 7)
    {
      cout<<"Remove Activity" <<endl;
      newList->Printlist();
      newList->remove();
    }

    else if(user_input == 8)
    {
      newList->readOut();
      return;
    }

    print_menu();
    cout << "Make your menu selection: ";
    cin >> user_input;
    format_fun();
    while(!cin || user_input < 1 || user_input > 8)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Please try again" << endl;
        cout << "Enter Menu Selection: ";
        cin >> user_input;
        cout << endl;
        format_fun();
    }
}
  
}
