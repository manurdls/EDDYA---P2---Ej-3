#include <iostream>
#include <stdlib.h>
using namespace std;
class DosPilas{
	private:
		int *arr;
		int indexTopP1;
		int indexTopP2;
		int maxSize;
	public:
		DosPilas(int maxSize = 10); //si no se pasa como parámetro la cantidad maxima de elementos, por defecto son 10
		int sizeP1() const;	//devuelve la cantidad actual de elementos
		int sizeP2() const;
		bool emptyP1() const; //devuelve True si la pila está vacia
		bool emptyP2() const;
		int topP1() const;	//devuelve el valor del ultimo elemento agregado
		int topP2() const;
		void pushP1(int dat); //agrega un elemento a la pila
		void pushP2(int dat);
		void popP1();			//elimina el elemento que está en la posición top de nuestra pila
		void popP2();
		~DosPilas();			//es el destructor
};

DosPilas::DosPilas(int max){
	indexTopP1 = -1;
	indexTopP2 = max;
	maxSize = max;
	arr = new int[max];
	
}

int DosPilas::sizeP1() const{
	return indexTopP1 + 1;
}

int DosPilas::sizeP2() const{
	return maxSize - indexTopP2;
}

bool DosPilas::emptyP1() const{
	return (indexTopP1 == -1);
}

bool DosPilas::emptyP2() const{
	return (indexTopP2 == maxSize);
}

int DosPilas::topP1() const{
	return arr[indexTopP1];
}

int DosPilas::topP2() const{
	return arr[indexTopP2];
}

void DosPilas::pushP1(int dat){
	if(indexTopP1 + 1 < indexTopP2)
		arr[++indexTopP1] = dat;
}

void DosPilas::pushP2(int dat){
	if(indexTopP2 - 1 > indexTopP1)
		arr[--indexTopP2] = dat;
}

void DosPilas::popP1(){
	if(!emptyP1())
		indexTopP1--;
}

void DosPilas::popP2(){
	if(!emptyP2())
		indexTopP2++;
}
DosPilas::~DosPilas(){
	delete[]arr;
}

int main(){
	DosPilas pilas(4);
	pilas.pushP1(10);
	pilas.pushP1(20);
	pilas.pushP1(30);
	pilas.pushP2(80);
	pilas.pushP1(50);
	pilas.pushP2(70);
	//pilas.popP1();
	//pilas.popP2();
	cout<<"Cantidad elementos Pila 1: "<<pilas.sizeP1()<<endl;
	if (!pilas.emptyP1()){
		cout<<"Ultimo elemento Pila 1: "<<pilas.topP1()<<"\n"<<endl;
	}
	else{
		cout<<"(Pila 1 vacia)\n"<<endl;
	}
	cout<<"Cantidad elementos Pila 2: "<<pilas.sizeP2()<<endl;
	if (!pilas.emptyP2()){
		cout<<"Ultimo elemento Pila 2: "<<pilas.topP2()<<"\n"<<endl;
	}
	else{
		cout<<"(Pila 2 vacia)\n"<<endl;
	}
}
