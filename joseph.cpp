#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 
#include <stdlib.h>


using namespace std;


template <typename Object>
class List
{
public:
  
  struct Node
  {
    Object data;
    Node *prev, *next;

    Node( const Object & d = Object( ), Node *p = NULL, Node *n = NULL )
      : data( d ), prev( p ), next( n ) { }
  };
 

public:  class const_iterator
  {
  public:
    const_iterator( ) : current( NULL ) { }

    // Overloaded operator* -- for dereferencing
   const Object & operator* ( ) const { return retrieve( ); }

    // Overloaded pre-increment operator++
    const_iterator & operator++ ( )
    {
      current = current->next;
      return *this;
    }

    // Overloaded post-increment operator++
    const_iterator operator++ ( int )
    {
      const_iterator old = *this;
      ++( *this );
      return old;
    }

    // Overloaded pre-decrement operator--
    const_iterator & operator-- ( )
    {
      current = current->prev;
      return *this;
    }

    // Overloaded post-decrement operator--
    const_iterator operator-- ( int )
    {
      const_iterator old = *this;
      --( *this );
      return old;
    }

    bool operator== ( const const_iterator & rhs ) const
      { return current == rhs.current; }
    bool operator!= ( const const_iterator & rhs ) const
      { return !( *this == rhs ); }

  //protected:
    Node *current;

    Object & retrieve( ) const { return current->data; }
    const_iterator( Node *p ) : current( p ) { }

    friend class List<Object>;
  };
  //--- end class const_iterator

  /*-------------------------------------------------------
   * Class iterator (as a nested class)
   * ----------------------------------
   * The non-const version of the iterator for List.
   * It is implemented as a derived class from const_iterator only so that
   * some members don't have to be duplicated from const_iterator.
   * Most functions are same as those in const_iterator, except
   * const_iterator is changed to iterator, and some 'const' are removed.
   *------------------------------------------------------*/
  class iterator : public const_iterator
  {
  public:
    iterator( ) { }
   // Object & operator* ( ) { return retrieve( ); }
    const Object & operator* ( ) const { return const_iterator::operator*( ); }

    const iterator & operator++ ( )
    { 
       
      this->current = this->current->next;
      return *this;
    }

    iterator operator++ ( int )
    {
      iterator old = *this;
      ++( *this );
      return old;
    }

    iterator & operator-- ( )
    {
      this->current = this->current->prev;
      return *this;
    }

    iterator operator-- ( int )
    {
      iterator old = *this;
      --( *this );
      return old;
    }

  protected:
    iterator( Node *p ) : const_iterator( p ) { }
    friend class List<Object>;
  };
  
public:
  List();
  List(const List & rhs);
  ~List();
  const List & operator=(const List & rhs);

  iterator begin() { return iterator(head->next); }
  const_iterator begin() const { return const_iterator(head->next); }
  iterator end() { return iterator(tail); }
  const_iterator end() const { return const_iterator(tail); }

  //
  // Additional functions which return an iterator to the (dummy) tail and head nodes
  //
  iterator rbegin() { return iterator(tail->prev); }
  const_iterator rbegin() const { return const_iterator(tail->prev); }
  iterator rend() { return iterator(head); }
  const_iterator rend() const { return const_iterator(head); }

  int size() const { return theSize; }
  bool empty() const { return size() == 0; }

  void clear()
  {
    while (!empty())
        pop_front();
  }

  Object & front( ) { return *begin( ); }
  const Object & front( ) const { return *begin( ); }
  Object & back( ) { return *--end( ); }
  const Object & back( ) const { return *--end( ); }

  void push_front( const Object & x ) { insert( begin( ), x ); }
  void push_back( const Object & x ) { insert( end( ), x ); }

  void pop_front( ) { erase( begin( ) ); }
  void pop_back( ) { erase( --end( ) ); }

  // Insert x before itr.
  iterator insert( iterator itr, const Object & x )
  {
    Node *p = itr.current;
    theSize++;
    return iterator( p->prev = p->prev->next = new Node( x, p->prev, p ) );
  }

  // Erase item/node at itr.
  iterator erase( iterator itr )
  {
    Node *p = itr.current;
    iterator retVal( p->next );
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    theSize--;

    return retVal;
  }

  iterator erase( iterator from, iterator to )
  {
    for( iterator itr = from; itr != to; )
      itr = erase( itr );

    return to;
  }

  //---------------------------------------------------------
  // Some additions from the class exercises
  //---------------------------------------------------------
  void splice(iterator position, List & lst)
  {
    Node* ptr = position.current;
    Node* lstHead = lst.head;
    Node* lstTail = lst.tail;

    ptr->prev->next = lstHead->next;
    lstHead->next->prev = ptr->prev;

    lstTail->prev->next = ptr;
    ptr->prev = lstTail->prev;

    lstHead->next = lstTail;
    lstTail->prev = lstHead;

    theSize += lst.theSize;
    lst.theSize = 0;
  }


  //********************************************************
  //
  // For HW#2 -- WRITE YOUR CODE HERE
  //
  //********************************************************

void printListForward(List & lst)
{
  iterator it = lst.begin();
  while (it != lst.end())
    cout << *it++ << " ";
  cout << endl;
}
void printListBackward(List & lst)
{
  iterator it = lst.rbegin();
  while (it != lst.rend())
    cout << *it-- << " ";
  cout << endl;
}




void splice(iterator  position, List & lst, iterator first, iterator last){
    Node* ptr = position.current;
    //iterator head=first;
     //iterator tail=last;
     
     
    Node* lstHead = lst.head;
    Node* lstTail = lst.tail;
    for( iterator itr = lst.begin() ; itr != lst.end()  ;itr++ )
	{
	   if(itr==first)
	   {
	   
	       lstHead=lstHead->next;
	       
           lst.theSize -= 1;
        }
    }
    
     for( iterator itr = lst.end() ; itr !=lst.begin()   ;itr-- )
	{
	   if(itr==last)
	   {
	   
	       lstTail=lstTail->prev;
	       
           lst.theSize -= 1;
        }
    }
    

    ptr->prev->next = lstHead->next;
    lstHead->next->prev = ptr->prev;

    lstTail->prev->next = ptr;
    ptr->prev = lstTail->prev;

    lstHead->next = lstTail;
    lstTail->prev = lstHead;

    theSize += lst.theSize;
   

}


void remove(const Object& val){
iterator itr = begin();
	for( iterator itr = begin() ; itr != end()  ;itr++ )
	{
	   if(itr.retrieve() ==val)
      { //cout<<itr.retrieve();
       erase( itr );
      }
    }
	

}

void game(const Object& value)
{
	 iterator x;
	 int g = atoi(value.c_str());
	 
	 iterator itr = begin();
	 while(1< size())
	 { 
	// cout<<itr.retrieve()<<size();
      x= josephu( itr, g);
      cout << *x <<" Eliminated"<<endl;
       itr=x;
      erase(x);
    
	  itr++;
     if(itr==end())
     { itr=begin();
	 }
      
      
    //  cout<<"next one"<<itr.retrieve();
    
     
     
        
     }
  
  return ;	
}


iterator josephu(iterator p,int m )
{ 
  int count=1;

cout<<"------"<<*p<<"---";
  //iterator q=p.current;
 // string i=q.retrieve();
  if(p==end())
     { p=begin();
       count++;
	 }
 
  while(count<=m)
   
  {      
	p++;
  
  	if (p == end() && count == 1) 
	{  
	 p = begin();					  
     p++;				
	}
	
	else if (p == end() && count > 1) //else, just reset it.
   {
		p = begin();
	}
  	
  	count++;
  	
  }
  
  
  return p;
  
		  
          
         
}
void reduce1(){
	
	iterator cur1 = begin();
	iterator temp=++cur1;
	iterator temp1=++temp;
	iterator temp2=++temp1;
	iterator temp3=++temp2;
	iterator temp4=++temp3;
	 
	    	 
    for(  iterator itr = temp4; itr != end()  ;itr++ )
	{
	
	      if( temp4.retrieve()==itr.retrieve())
		  {
	      	erase(itr );
	      	
	      }
    }
	
	    
}

void reduce(){
	
	iterator cur1 = begin();
	 iterator temp=++cur1;
	  
	 
   	 
    for( iterator itr = temp; itr != end()  ;itr++ )
	{
	
	      if(cur1.retrieve() ==itr.retrieve())
		  {
	      	erase(itr );
	      	
	      }
	  
	  
	}
	
	    
}
void unique()
{
	
	for(int i=1;i<=4;i++){
		reduce();}
	 iterator cur1 = begin();
	 iterator temp=++cur1;
	 iterator temp1=++temp;
	 iterator itr;
	for(  itr = temp; itr != end()  ;itr++ )
	{
	
	      if(cur1.retrieve() ==itr.retrieve())
		  {
	      	erase(itr );
	      	
	      }
	  
	  
	}
   	 
    for(  itr = ++temp; itr != end()  ;itr++ )
	{
	
	      if(temp1.retrieve() ==itr.retrieve())
		  {
	      	erase(itr );
	      	
	      }
	  
	  
	}
reduce1() ; 
	    
	    
	
}

	  
	







private:
  int theSize;
  Node *head, *tail;

  void init( );
};
// -- end class List

/*===========================================
 * member function definitions for class List
 *===========================================*/
template <typename Object>
List<Object>::List( ) { init( ); }

template <typename Object>
List<Object>::List( const List & rhs )
{
  init( );
  *this = rhs;
}

template <typename Object>
List<Object>::~List( )
{
  clear( );
  delete head;
  delete tail;
}

template <typename Object>
const List<Object> & List<Object>::operator= ( const List & rhs )
{
  if( this == &rhs )
    return *this;
  clear( );
  for( const_iterator itr = rhs.begin( ); itr != rhs.end( ); ++itr )
    push_back( *itr );
  return *this;
}

template <typename Object>
void List<Object>::init( )
{
  theSize = 0;
  head = new Node;
  tail = new Node;
  head->next = tail;
  tail->prev = head;
}

//#endif




List<string> iterator1;;

int main()
{
  
  
  List<string> slist1;

  
  	char data[100];
	int n;
	string fileName;



	cout<<"\n\tWrite precisely the name of the file and its extension: and #Number  \n\t of passes: ";
   //getline(cin, fileName);
    cout<<"\n\t";
    cin>> n;
	
	ifstream infile;
    infile.open("roster1.txt");//fileName.c_str()
    if(infile.fail())
    {
       cerr << "\n\tError Opening File" << endl;
       exit(1);
    }

   while (!infile.eof())
    {
	
	infile >> data;
   
	 slist1.push_back(data);	

  } 	
  infile.clear();//it serves to clean the file
  slist1.printListForward(slist1); cout << endl;
    int N=slist1.size();
  cout<<"\n\t M="<<n<<"      N="<<N<<"\n";
  string s;
stringstream convert; // stringstream used for the conversion
convert << n;//add the value of Number to the characters in the stream

 s = convert.str();


	slist1.game(s);	
	



  
  cout <<"\n\tAnd The Winner Is " ;
  slist1.printListBackward(slist1);
   cout<<"!!\n\t"<< endl;
 


  

  
  system("Pause");
  return 0;
}
