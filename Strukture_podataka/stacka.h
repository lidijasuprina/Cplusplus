#ifndef MAXS
#define MAXS 1000
#endif

#include <iostream>
#include <cstdlib>

struct stack {
       elementtypes el[MAXS];
       int top;
};

typedef int elements;

void InitS(stack &S) {
     S.top = MAXS - 1;
}

bool IsEmptyS(stack &S) {
     return S.top == MAXS - 1;
}

elementtypes TopS(stack &S) {
             if (S.top == MAXS-1) {
                std::cout << "Stog je prazan"  
                          << std::endl;
                exit(EXIT_FAILURE); 
             }
             else
                 return S.el[S.top+1];
}

void PushS(stack &S, elementtypes x) {
     if (S.top == -1) {
        std::cout << "Stog je prepunjen"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else 
          S.el[S.top--] = x;
}

void PopS(stack &S) {
     if (S.top == MAXS-1) {
          std::cout << "Stog je prazan" 
                    << std::endl;
          exit(EXIT_FAILURE);
     }
     else 
         S.top++;
}

void DisposeS(stack &S) {
}
