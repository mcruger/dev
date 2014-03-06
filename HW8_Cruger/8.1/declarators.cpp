//old but decent reference
//http://www.geocities.com/varunhostel/TechnicalArticles/PointerArticle/PointerArticle_Intro.html?reload_coolmenus
//http://www.codingunit.com/cplusplus-tutorial-pointers-reference-and-dereference-operators


#include<iostream>
#include<string>
#include<array>


class A {
public:
	int a_; //  _ means member var
	int returnIntFromA(int *b){
		return 0;
	}

	//int (A::*)(double (*)(float &))
	int returnAnotherInt(double(*)(float &)){
		return 0;
	}

};

int returnInt (){
	int i = 5;
	return i;
}

//char *(*)(char *, char*)
char* returnCharPtr(char *, char *){
	char c = 'c';
	char *cp = &c;
	return cp;
}

//void (*p[10])(void (*)());
void modifyArray(void (*)()){
	//not really needed since this does nothing
} 

int
main(){
	
	//used in problems
	int i = 5;
	char const ch = 'c';
	float fl = 3.234234234f;
	//char p = 'd';
	//char *ctwo = &p;

	//Problems start:
	//int *
	int *ptr = &i;

	//int &
	int &ref = *ptr;

	//double 
	double dbl = 5.0;

	//A * 
	A * a = new A;

	//char const *
	char const *pc = &ch;

	//char const &
	char const &rpc = *pc; 

	//long[7]
	long lngArray[7] = {(long) 324345345345, (long) 345345345, (long) 345345345345, (long) 345345345345345, (long) 345345345345, (long) 34534534534, (long) 345345345};
	
	//int **
	int **doubptr = &ptr; //pointer to a pointer

	//int *&
	int *&refptr = ptr; //pointer to a reference

	//float &  is this a trick question? Seems too easy...
	float &refflt = fl;

	//NOTE: functions and class defined above main for pointer function problems

	//int (*)() 
	int (*testfuncptr)() = returnInt;

	//int (*&)()
	int (*&refagain)() = testfuncptr;

	//char *(*)(char *, char*)
	char *(*returnCharPtr)(char *, char *) = returnCharPtr;

	//A::*
	int A::*aptr = &A::a_; //pointer to a member variable of A. 

	//int (A::*)(int*)
	int (A::*ptrRet)(int*) = &A::returnIntFromA; 

	//int (A::**)(int*)
	int (A::**ptrptrAfunc)(int*) = &ptrRet; //ptr to a ptr again

	//int (A::*&)(int *)
	int (A::*&refToAPtr)(int*) = *ptrptrAfunc; //ptr to a ref 

	//int (A::*)(double (*)(float &))
	int (A::*ptrAgain)(double (*)(float &)) = &A::returnAnotherInt; //same-ish as int problem, just different signature

	//void (*p[10])(void (*)());
	void (*p[10])(void (*)()) = {0,0,0,0,0,0,0,0,0,0}; //insane, this does nothing????

	return 0;
}
