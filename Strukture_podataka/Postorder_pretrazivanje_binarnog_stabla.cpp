//#define MAXB 1000
#define MAXS 1000
typedef int nodetypeb;
#include "btreea.h"
typedef nodeb elementtypes;
#include "stacka.h"
#include <iostream>
#include <cstdlib>


int main () {
	btree B;
	InitB(B,4);
	nodeb n = RootB(B);
	CreateLeftChildB(B,n,7);
	n = LeftChildB(B,n);
	CreateLeftChildB(B,n,2);
	n = LeftChildB(B,n);
	CreateRightChildB(B,n,3);
	n = ParentB(B,n);	
	CreateRightChildB(B,n,8);
	n = RightChildB(B,n);
	CreateLeftChildB(B,n,1);
	n = RootB(B);
	CreateRightChildB(B,n,6);
	n = RightChildB(B,n);
	CreateLeftChildB(B,n,5);
	n = LeftChildB(B,n);
	CreateLeftChildB(B,n,9);
	CreateRightChildB(B,n,2);
	
	stack S;
    int a = 0;
    InitS(S);
    PushS(S,LabelB(B,RootB(B)));
    a++;
    nodeb m = RootB(B);
    PushS(S,LabelB(B,RightChildB(B,m)));
    a++;
	m = RightChildB(B,m);
	PushS(S,LabelB(B,LeftChildB(B,m)));
    a++;
	m = LeftChildB(B,m);
    PushS(S,LabelB(B,RightChildB(B,m)));
    a++;
	PushS(S,LabelB(B,LeftChildB(B,m)));
    a++;
	m = RootB(B);
    PushS(S,LabelB(B,LeftChildB(B,m))); 
    a++;
	m = LeftChildB(B,m);
    PushS(S,LabelB(B,RightChildB(B,m))); 
    a++;
	m = RightChildB(B,m);
    PushS(S,LabelB(B,LeftChildB(B,m)));
    a++;
	m = ParentB(B,m);
    PushS(S,LabelB(B,LeftChildB(B,m)));
    a++;
	m = LeftChildB(B,m);
    PushS(S,LabelB(B,RightChildB(B,m)));
    a++;
    for(int i=0;i<a;i++){
    	std::cout<<TopS(S)<<" ";
    	PopS(S);
	}

	DisposeB(B);
	DisposeS(S);	
}
