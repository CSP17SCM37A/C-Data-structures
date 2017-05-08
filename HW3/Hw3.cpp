#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <class T>
struct Node
{
  T data;
  Node * next;
  Node(T data) : data(data), next(NULL) {}
};

template <class T>
class CircularLinkedList
{
public:
	int size=0;
  CircularLinkedList() : head(NULL) {}
  ~CircularLinkedList();
  void addNode(T data);
  void deleteNode(T data);
  
  void josephu(int);
  template <class U>
  friend std::ostream & operator<<(std::ostream & os, const CircularLinkedList<U> & cll);
private:
  Node<T> * head;
  
};

template <class T>
CircularLinkedList<T>::~CircularLinkedList()
{
  if (head)
    {
      Node<T> * tmp = head;
      while (tmp->next != head)
        {
          Node<T> * t = tmp;
          tmp = tmp->next;
          size--;
          delete(t);
        }
      delete tmp;
      head = NULL;
    }
}

template <class T>
void CircularLinkedList<T>::addNode(T data)
{
  Node<T> * t = new Node<T>(data);

  if (head == NULL)
    {
      t->next = t;
      head = t;
      size++;
      return;
    }

  Node<T> * tmp = head;
  while (tmp->next !=  head)
    {
      tmp = tmp->next;
    }

  tmp->next = t;
  t->next = head;
  size++;
}

template <class T>
void CircularLinkedList<T>::josephu(int m)
{
	
   if(size==1)
   return;
  
   int N=size;
   int p=0;
   	
  Node<T> * tmp = head;
  Node<T> * prev = NULL;
  
   int y=size;
  while (tmp->next != NULL)
    {
    	
    	 if(size==1)
    	 {
		   return;
         }
    	  
    	while(p<m)
    	{
		 tmp = tmp->next;
		 p++;
		//cout<<"p is "<<p;
        }
    	if(p==m)
        {
         string h=tmp->data;
         	 //cout<<h; 
          deleteNode(h);
		 cout<<"\n\t--Person  "<<h<<" elimininated \n\t" ;     
        }
        
    
        p=0;
        tmp = tmp->next;
   }
   
  
     
   	

   	
	
}

template <class T>
void CircularLinkedList<T>::deleteNode(T data)
{
  Node<T> * tmp = head;
  Node<T> * prev = NULL;
  while (tmp->next !=  head)
    {
      if (tmp->data == data) break;
      prev = tmp;
      tmp = tmp->next;
      
    }

  if (tmp == head)
    {
      while (tmp->next != head)
        {
          tmp = tmp->next;
        }
      tmp->next = head->next;
      delete head;
      head = tmp->next;
      size--;
    }
  else
    {
      prev->next = tmp->next;
           delete tmp;
           size--;
    }
}

template <class U>
std::ostream & operator<<(std::ostream & os, const CircularLinkedList<U> & cll)
{
  Node<U> * head = cll.head;
  if (head)
    {
      Node<U> * tmp = head;
      while (tmp->next != head)
        {
          os << tmp->data << " ";
          tmp = tmp->next;
        }
      os << tmp->data;
    }
  return os;
}





int main()
{
	 CircularLinkedList<string> cll;

     
    //List<string> slist1;
  
  	char data[100];
	int n;
	string fileName;



	cout<<"\n\tWrite precisely the name of the file and its extension: and #Number  \n\t of passes: ";
   getline(cin, fileName);
    cout<<"\n\t";
    cin>> n;
	
	ifstream infile;
    infile.open(fileName.c_str());//fileName.c_str()
    if(infile.fail())
    {
       cerr << "\n\tError Opening File" << endl;
       exit(1);
    }

   while (!infile.eof())
    {
	
	infile >> data;
    cll.addNode(data);
		

  } 	
  infile.clear();//it serves to clean the file
  
 // cout  <<cll;
  
    int N=cll.size;
  cout<<"\n\t M="<<n<<"      N="<<N<<"\n";
  
   cll.josephu(n);
  

  
  
  
 
  cout <<"\n\tAnd The Winner Is " <<cll <<"!!\n\t"<< endl;
 


  system("Pause");
  return 0;
}

//#endif
