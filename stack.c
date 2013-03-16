#include<iostream>
#include<string>
#define STACK
using namespace std;

template <class T>
class stack{
	
	int top;
	public:
		T *mystack;
		stack<T>(){
			mystack= new T[5];
			top =-1;
		}
		T pop();
		T peek();
		void push(T item);
		int getTop();
	private:
		void resize();
		int size();
	};

template <class T>
T stack<T>::pop(){
	T temp =mystack[top];
	//mystack[top]=NULL;
	top--;
	return temp;
}
template <class T>
T stack<T>::peek(){
	return mystack[top];
}
template <class T>
int stack<T>::getTop(){
	return top;
}
template <class T>
void stack<T>::push(T thi){
	if(top==size()-1)
		resize();
	top+=1;
	mystack[top]=thi;
	}
template <class T>
void stack<T>::resize(){
	T *temp= new T[size()+10];
	for(int k=0;k<=top;k++)
		temp[k]=mystack[k];
	mystack=temp;
}
template<class T>
int stack<T>::size(){
	return( sizeof mystack/ (sizeof mystack[0]));
}
template<class T>
std::ostream &operator<< (ostream &strm, stack<T> h){
	if(h.getTop()>-1)
	{
		strm<<"["<<h.mystack[0];
		for(int k=1;k<=h.getTop();k++)
			strm<<", "<<h.mystack[k];
		strm<<"]";
	}
	else
	strm<<"[]"<<"\0";
}

/*int main(){
	stack<string> fish;
	fish.push("5");
	cout<<fish.pop();
	fish.push("65");
	fish.push("54");
	cout<< fish <<endl;
	return 0;
}*/


	
