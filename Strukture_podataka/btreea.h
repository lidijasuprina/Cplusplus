#ifndef MAXB
#define MAXB 1000
#endif

#include <iostream>
#include <cstdlib>
#define lambdab 0
struct elem {
       nodetypeb label;
       bool used;
};

typedef elem btree[MAXB+1];
typedef int nodeb;

void InitB(btree &B, nodetypeb x) {
     B[1].label = x;
     B[1].used = true;
     for (int i = 2; i <= MAXB; i++)
         B[i].used = false;
}

void InitB(btree &B) {
	 for (int i = 1; i <= MAXB; i++)
	     B[i].used = false;
}

bool IsEmptyB(btree B) {
	 return !B[1].used;
}

nodeb LabelB(btree &B, nodeb n) {
     if (n == lambdab) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else
         return B[n].label;
}

nodeb RootB(btree &B) {
      if (!B[1].used) {
         std::cout << "Stablo je prazno"
                   << std::endl;
         exit(EXIT_FAILURE);
      }
      else 
          return 1;
}

nodeb ParentB(btree &B, nodeb n) {
      if (n == lambdab) {
         std::cout << "Nepostojeci cvor"
                   << std::endl;
         exit(EXIT_FAILURE);
      }
      else 
          return n/2;
}

nodeb LeftChildB(btree &B, nodeb n) {
      if (n == lambdab) {
         std::cout << "Nepostojeci cvor"
                   << std::endl;
         exit(EXIT_FAILURE);
      }
      else 
          if (2*n <= MAXB && B[2*n].used)
             return 2*n;
          else
              return lambdab;
}

nodeb RightChildB(btree &B, nodeb n) {
      if (n == lambdab) {
         std::cout << "Nepostojeci cvor"
                   << std::endl;
         exit(EXIT_FAILURE);
      }
      else 
          if (2*n+1 <= MAXB && B[2*n+1].used)
             return 2*n+1;
          else
              return lambdab;
}

void ChangeLabelB(btree &B, nodeb n, nodetypeb x) {
     if (n == lambdab) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else 
         B[n].label = x; 
}

void CreateRootB(btree &B, nodetypeb x) {
     if (B[1].used) {
        std::cout << "Stablo nije prazno"
                 << std::endl;
        exit(EXIT_FAILURE);
     }
     else {
          B[1].used = true;
          B[1].label = x;
     }
}

void CreateLeftChildB(btree &B, nodeb n, nodetypeb x) {
     if (n == lambdab) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else 
         if (2*n > MAXB) {
            std::cout << "Cvor je izvan dosega"
                      << std::endl;
            exit(EXIT_FAILURE);
         }
         else 
             if (B[2*n].used) {
                std::cout << "Cvor vec ima "
                          << "lijevo dijete"
                          << std::endl;
                exit(EXIT_FAILURE);
             }
             else {
                  B[2*n].used = true;
                  B[2*n].label = x;
             } 
}

void CreateRightChildB(btree &B, nodeb n,
                       nodetypeb x) {
     if (n == lambdab) {
        std::cout << "Nepostojeci cvor "
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else 
         if (2*n+1 > MAXB) {
            std::cout << "Cvor je izvan dosega"
                      << std::endl;
            exit(EXIT_FAILURE);
         }
         else 
             if (B[2*n+1].used) {
                std::cout << "Cvor vec ima " 
                          << "desno dijete"
                          << std::endl;
                exit(EXIT_FAILURE);
             }
             else {
                  B[2*n+1].used = true;
                  B[2*n+1].label = x;
             } 
}

void DelB(btree &B, nodeb n) {
     if (2*n <= MAXB && B[2*n].used)
        DelB(B,2*n);
     if (2*n+1 <= MAXB && B[2*n+1].used)
        DelB(B, 2*n+1); 
     B[n].used = false;
}

void DeleteB(btree &B, nodeb n) {
     if (n == lambdab) {
        std::cout << "Nepostojeci cvor"
                  << std::endl;
        exit(EXIT_FAILURE);
     }
     else
         DelB(B, n);
}


void DisposeB(btree &B) {
}
