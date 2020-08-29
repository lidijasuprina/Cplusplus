#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define N 8

using namespace std;

int OZNAKA_CEKANJA[N];
int PRIORITET[N];
int TEKUCI_PRIORITET;

void obrada_prekida(int j)
{
   cout<<endl;
   cout<<"Poceo obradu prekida: "<<j<<endl<<endl;
   for(int i=1; i<=5; i++){
        cout<<"Obrada prekida "<<j<<": "<<i<<"/5"<<endl;
        sleep(1);
}
   cout<<endl;
   cout<<"Zavrsio obradu prekida: "<<j<<endl<<endl;
}

void prekidna_rutina (int sig)
{
   int i,x;
   time_t t;

   time(&t);
   cout<<endl;
   cout<<"Prekidna rutina pozvana u: "<<ctime(&t)<<endl;

   cout<<("Upisi razinu prekida: ");
   cin>>i;

   OZNAKA_CEKANJA[i]=1;
   
   do{
        x=0;
        for(int j=TEKUCI_PRIORITET+1; j<N; j++){
                if(OZNAKA_CEKANJA[j]!=0){
                        x=j;
                }
        }

        if(x>0){
                OZNAKA_CEKANJA[x]=0;
                PRIORITET[x]=TEKUCI_PRIORITET;
                TEKUCI_PRIORITET=x;
                sigrelse(SIGINT);
                obrada_prekida(x);
                sighold(SIGINT);
                TEKUCI_PRIORITET=PRIORITET[x];
        }

   }while (x>0);
}

int main (void)
{
   sigset (SIGINT, prekidna_rutina);

   cout<<"Poceo osnovni program"<<endl<<endl;

   for(int i=1; i<=10; i++){
        cout<<"Glavni program: "<<i<<"/10"<<endl;
        sleep(1);
   }

   cout<<"Zavrsio osnovni program"<<endl<<endl;

   return 0;
}

