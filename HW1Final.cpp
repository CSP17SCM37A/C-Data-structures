#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
template <typename T>
class SLList {

 private:
    struct node {
      node   *next, *prev;
      T      value;
    };

   node   *first; 
   node   *last;  
   unsigned length; 
   void createEmpty();
   void removeAll();
   void copyAll(const SLList &l);

   


 public:

        SLList();                                   // constructor
 	explicit   SLList(const SLList &lst2);        // copy constructor
	~SLList();                                      // destructor
   	 SLList &operator=(const SLList &rhs);           // assignment operator
                                     

   
 	int size() ;
 
  	void print() ; 
  	bool find(const T& val) ;
        bool isEmpty() const; 
 
	void add(const T& val);
	void insertFront(const T &val);
    void insertBack(const T &val);

    void remove(const T &val);
 	void removeFront();
    void removeBack();

       

   
   




};

template <typename T>
bool SLList<T>::find(const T &val) {
 
  node *head = first;
  while (head) {
    if(val== head->value )
        return 1;
    head = head->next;
  }
return 0;
}


    
template <typename T>
 void SLList<T>:: remove(const T& val) {
 
  node *iter= first;
  if (iter == NULL) {
        printf("not found\n");
        return;
    }

    if (iter->value == val) {
        printf("found in first element: %i\n", val);
            first = first->next;
        return;
    }

    while (iter->next != NULL) {
        if (iter->next->value == val) {
            printf("deleting element: %i\n", val);
            iter->next = iter->next->next;
            return;
        }

        iter = iter->next;
    }

    printf("not found\n");
}



template <typename T>
SLList<T>::SLList() {
  createEmpty();
}

template <typename T>
SLList<T>::SLList(const SLList &l) {
  createEmpty();
  copyAll(l);
  return;
}

template <typename T>
SLList<T>& SLList<T>::operator= (const SLList &rhs)
{
    if (this != &rhs) {
        removeAll();
        copyAll(rhs);
    }
    return *this;
}

template <typename T>
SLList<T>::~SLList() {
  removeAll();
}



template <typename T>
void SLList<T>::createEmpty() {
  first = NULL;
  last = NULL;
  length = 0;
}

template <typename T>
void  SLList<T>::removeAll() {
  while (!isEmpty()) {
    removeFront();
  }
}

template <typename T>
void SLList<T>::copyAll(const SLList &l) {
  node *iterator = l.first;
  while (iterator) {
    T obj = iterator->value;
    insertBack(obj);
    iterator = iterator->next;
  }
}

template <typename T>
int SLList<T>::size() {
  return length;
}

template <typename T>
bool SLList<T>::isEmpty() const{
  return (first == NULL && last == NULL);
}










template <typename T>
void SLList<T>::insertFront(const T &val) {
	 node *head = first;
  while (head)
   {
    if(val== head->value )
     {
	   cout<<val<< " Already Exist.";
        return ;}
    head = head->next;
  }

		
	
	
  length++;
  node *newNode = new node;
  new (&(newNode->value)) T(val);
  newNode->next = first;
  newNode->prev = NULL;
  if (isEmpty()) first = last = newNode;
  else {
    first->prev = newNode;
    first = newNode;
  }
}

template <typename T>
void SLList<T>::insertBack(const T &val) {
  node *head = first;
  while (head)
   {
    if(val== head->value )
     {
	   cout<<val<< " Already Exist.";
        return ;}
    head = head->next;
  }	
	
  length++;
  node *newNode = new node;
  new (&(newNode->value)) T(val);
  newNode->next = NULL;
  newNode->prev = last;
  if (isEmpty()) first = last = newNode;
  else {
    last->next = newNode;
    last = newNode;
  }
}







template <typename T>
void SLList<T>::removeFront() {
  if (isEmpty()) return;
  length--;
  node *removedNode = first;
  first = first->next;
  if (first) first->prev = NULL;
  else first = last = NULL;
  delete removedNode;
  return;
}

template <typename T>
void SLList<T>::removeBack() {
  if (isEmpty()) return;
  length--;
  node *removedNode = last;
  last = last->prev;
  if (last) last->next = NULL;
  else first = last = NULL;
  delete removedNode;
  return;
}



template <typename T>
void SLList<T>::print() {
  if (isEmpty()) {
    std::cout << "SLList is empty\n"; 
    return;
  }
  node *head = first;
  while (head) {
    std::cout << head->value << " ";
    head = head->next;
  }
  std::cout << "\n";
}
void menu(){

    cout<<"\n\t 1.Add";
    cout<<"\n\t 2.Remove";
    cout<<"\n\t 3.print";
    cout<<"\n\t 4.find";
    cout<<"\n\t 5.EXIT \n";
    cout<<"\n\t choose one option: \n";
}

int main (){
	int choice;
	SLList <int> ilist;
		SLList <string> ilist;
	
	while (choice != 11){
	menu();
	cin >> choice;
	
	if (choice == 1)
	{
		int value,p;
	
	cout<<"Enter 1 to insertfront !! 0 for endofthe linked list:";
	cin>>p;
	if(p=1)
	{
	cout <<"Enter a value: ";
	cin >> value;
	
	ilist.insertFront(value);
		
	}
	if(p=0)
	{
	cout <<"Enter a value: ";
	cin >> value;
	
	ilist.insertBack(value);
		}
		
		
	} 
	if (choice == 2){
		
		    int value;
			cout <<"Enter a value: ";
	        cin >> value;
			ilist.remove(value);
		
		
	
}
	if (choice == 3){
			ilist.print();
		
		}
	if (choice == 4){
		int value;
		cout << "Enter the value that want to find in the linked list: ";
		cin >> value;
		bool f = ilist.find(value);
		if (f == 1)
			cout <<"The value "<<value<<" was found in the list";
		else
			cout <<"The value was"<< value<<" not found in the list";
	}
	
	if (choice == 5)
	{
		exit (EXIT_FAILURE);
	}
	
    }
	
	

	
	
	return 0;
}


