#include "activitylist.h"
#include "tools.h"


//Constructor
Active_list::Active_list()
{
    cout << "Constructor called" << endl; 
    head = NULL;
    tail = NULL;
    count = 0;


  }
//Deconstructor
Active_list::~Active_list() // used to deleter the list and free up memory 
{
    Node *curr = head;
    while(curr)
    {
        head = curr->next;
        delete curr;
        curr = head;
    }
    tail = NULL;
  }
//METHODS
int &Active_list::getCount()
{
   return count;
}
void Active_list::Open(char fileName [])
{
  head = NULL;
  tail = NULL;
  count = 0;
  Activity tempActivity;
  ifstream input_stream;
  char Temp_name[51];
  char Temp_location[51];
  char Temp_level[51];
  int Temp_rating;
  int Temp_type;
  
  int size = 0;

  //-----Open--File----------------------------------------------------
   input_stream.open(fileName);

  while(!input_stream.is_open()){
    char file_name[51];
    cout << "Error: Unable to open file!" << endl;
    cout <<"Please Enter File name: ";
    cin.getline(file_name,51,'\n');
    input_stream.open(file_name);
    
}
  format_fun();
 

  
//-----Populate---List---------------------------------------------------
  input_stream.getline(Temp_name, 51, ';');
  while(!input_stream.eof() && size < 30 ) 
  {   
      input_stream.getline(Temp_location, 51,';');
      input_stream.getline(Temp_level, 51,';');
      input_stream>>Temp_rating;
      input_stream.ignore(5, ';');
    
   
      input_stream >>Temp_type;
      input_stream.ignore(5,'\n');
      tempActivity.setName(Temp_name);
      tempActivity.setLocation(Temp_location);
      tempActivity.setLevel(Temp_level);
      tempActivity.setRating(Temp_rating);
      tempActivity.setType(numtoType(Temp_type));
      addToList(tempActivity);
      input_stream.getline(Temp_name, 51,';');  
     
 }
  input_stream.close();
 
  }
void Active_list::addActivity()
{
  Activity newActivity;
  char Temp_name[51];
  char Temp_location[51];
  char Temp_level[51];
  int Temp_rating;
  int Temp_type;

      cin.ignore(50,'\n');
      cin.clear();
      
      cout << "Enter Activity Name: ";
      cin.getline(Temp_name, 51, '\n');
      newActivity.setName(Temp_name);
      cout << endl;
  
      cout << "Enter Activity Location: ";
      cin.getline(Temp_location, 51,'\n');
      newActivity.setLocation(Temp_location);
      cout << endl;

      cout << "Enter Activity Level(Easy,Intermidiate,Difficult): ";
      cin.getline(Temp_level, 51, '\n');
      
      newActivity.setLevel(Temp_level);
      cout << endl;

      cout << "Enter Activity Rating(1-10): ";
      cin>>Temp_rating;
      while(Temp_rating < 1 || Temp_rating > 10)
      {
        cin.clear();
        cin.ignore();
        cout << "Please enter a valid rating" << endl;
        cin>>Temp_rating;
      }
        newActivity.setRating(Temp_rating);
        cout<<endl;


      cout << "Enter Activity Type(ATHLETIC=0,FOOD=1,ART=2,GAMES=3, OTHER=4: ";
   cin>>Temp_type;
  
   while(Temp_type < 0 || Temp_type > 4)
   {

    cout << "Please enter a valid type" << endl;
    cin>>Temp_type;
   }
  newActivity.setType(numtoType(Temp_type));
  cout << endl;

  addToList(newActivity);
  
  format_fun();
  }
void Active_list::addToList(Activity &tempActivity) 
{

    Node *newNode = NULL; // create new block 
  
    Node *curr = NULL;
    Node *prev = NULL;
  
    char tempName1[51];
    char tempName2[51];

    newNode = new Node;
    newNode->list = tempActivity;
    newNode->next = NULL;
   
    if(!head)
    {
        head = newNode;
        tail = newNode;
        count++;
        return;
    }
   
    else
    {
        curr = head;
        curr->list.getName(tempName1);
        newNode->list.getName(tempName2);
        while(curr && lessThan(tempName1, tempName2))
        {
            prev = curr;
            curr = curr->next;
            if(curr)
            {
                curr->list.getName(tempName1);
            }
        }
        
        if(!curr)
        {
            tail->next = newNode;
            tail = newNode;
        }
        
        else if(prev)
        {
            newNode->next = curr;
            prev->next = newNode;
        }
       
        else
        {
            newNode->next = curr;
            head = newNode;
        }
    }
    count++;
}

void Active_list::Backwards(Node* head, int num) //My attempt at recursion its a little wonky and need some work. I was having a hard time calling it correctly in my tools.cpp so that I could still print the index numbers. Any feedback on this would be appreciated.
{
  
  if (head == nullptr) // Bases Case
  {
    
    return;
  }
      
  else
  {
    
    Backwards(head->next,num-1);
    cout << num << ".";
    head->list.printActivity();
  
  }
  
}
void Active_list::printReverse(int listNum)
{ 
 
  cout << "Print In Reverse: "<<endl;
  cout << "----------------" << endl;
    
  Backwards(head,listNum);

  format_fun();
  }
  
    
void Active_list::byType()
{
    cout << "Search by Type: "<<endl;
    cout <<"----------------" << endl;
    int type_input;
    cout << "Enter Type of Activity (0=ATHLETIC, 1=FOOD, 2=ART, 3=GAMES, 4=OTHER): ";
    cin >> type_input;
    while(type_input < 0 || type_input > 4)
    {
        cout << "Please enter a valid type" << endl;
        cin >> type_input;
    }
    format_fun();
    for(Node *curr = head; curr; curr = curr->next)
    {
        if(curr->list.getType() == numtoType(type_input))
        {
            curr->list.printActivity();
        }
    }
    cout << endl;
    format_fun();
}
void Active_list::remove()
{if(count == 0){
    cout << "Nothing to remove!" << endl;
    return;
  }

  format_fun();
  int remove = 0;
  int num = 1;
  cout << "Select Item you would like to remove: ";
  cin >> remove;
  while(!cin || remove > count || remove < 1)
  {
    cin.clear();
    cin.ignore();
    cout <<"Invalid Entry! Please try again!" << endl;
    cin>>remove;
  } 

  Node *curr = head;
  Node *prev = NULL;

// while current is not null and num is lex than the index of the item to be removed travers through the list to find the node that needs to be removed.
  while(curr && num < remove ) 
  {
    prev = curr;
    curr = curr->next;
    num++;
  }
  
// if previous is null that means the node to be removed is the first node in the list.
  if(!prev)
  {
    head = curr->next;
  } 
    
//Check to see if the Node to be removed is the last node. if so re-assign tail to the new tail and remove the item. 
  else if(curr == tail)
  {
    prev->next = curr->next;
    tail = prev;
  } 

//If the node is not the head or the tail this function traverses through the list to remove the item. 
  else 
  {
    prev->next = curr->next;
  }
  delete curr;

  count--;
  format_fun();
}
void Active_list::searchByName()
{
  cout << "Search by Name: "<<endl;
  cout <<"----------------" << endl;
  char name_input[51];
  char nameCompare[51];
  bool found = false;
  
    cout << "Enter Name of Activity:";
    cin.ignore();
    cin.clear();
    cin.getline(name_input,50,'\n');
    format_fun();

    for(Node *curr = head; curr; curr = curr->next)
    {
        curr->list.getName(nameCompare);
        if(strstr(nameCompare, name_input) != NULL)
        {
            curr->list.printActivity();
            found = true;
        }
    }

    if (!found) {
        cout << "Your input: " << name_input << " Was not found in the list!" << endl;
    }

  
  cout << endl;
  format_fun();
}
void Active_list::printLast() 
{
  Node *curr = head;
    if (head == NULL)
    {
        cout << "ERROR! List is empty" << endl;
        format_fun();
        return;
    }
   else
  {
    cout << "Last element: " << endl;
    tail->list.printActivity(); 
    format_fun();
  }
  }
 
void Active_list::readOut()
{

  ofstream output_stream;
  output_stream.open("activities.txt");
  if(!output_stream.is_open())
  {
    cout << "Error! File not found!" << endl;
    exit(1);
  }   
  else
  {
   
  cout <<"You have chose to Quit!" << endl;
  cout <<"Thank you for using my program!" << endl;
  format_fun();
 
  Node *curr;
    for(curr = head; curr; curr = curr->next)
    {
      curr->list.writeFile(output_stream);
    }
    cout <<"Your file has been populated with the updated list!" 
    << endl;

    }
  }
void Active_list::Printlist()
{
  cout << "Activity List:" << endl;
  cout<<"count= " << count << endl;
  cout << "--------------"<< endl;
  int num = 1;
  Node *curr;
  for(curr = head; curr; curr = curr->next)
   {
       cout << num << ".";
       curr->list.printActivity();
       num++;
   }
}
bool Active_list::lessThan(const char name1[], const char name2[])
{
    if(strcmp(name1, name2) < 0)
        return true;
    return false;
}

