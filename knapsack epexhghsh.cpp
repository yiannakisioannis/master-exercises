
/*0-1 Knapsack problem */
#include<stdio.h> 
  
int max(int a, int b) { return (a > b)? a : b; } //  su8hkh h opoia epistrefei to MAX twn 2 akeraiwn
  
int knapSack(int W, int wt[], int val[], int n) //epistrefei thn megisth axia pou mporei na topo8eth8ei ston sako me varos W
{ 
   //Vasikh upou8esh toy provlimatos
   if (n == 0 || W == 0) //an sta dedomena moy pros8esw to miden kai valw varos 0 pragmati isxuei
       return 0; 
  
   // An to varos twn antikeimenwn einai perissotero apo oti xwraei o sakos me varos W tote den sumperilamvanete to antikeimeno ayto 
   if (wt[n-1] > W) 
       return knapSack(W, wt, val, n-1); 
  
   // epistrefei to megisto ari8mo apo tis 2 upo8eseis  
   // 1) otan perilamvanete to antikeimeno  
   // 2) otan den perilamvanetai
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), //an parw thn su8hkh ayth ta epi8umita apotelesmata
                    knapSack(W, wt, val, n-1) 
                  ); 
} 
  
//to kurios programma moy
int main() 
{ 
    int val[] = {0,10, 50, 100, 500}; 
    int wt[] = {0,50, 100, 500, 1000}; 
    int  W = 150; 
    int n = sizeof(val)/sizeof(val[0]); 
    printf("%d", knapSack(W, wt, val, n)); //akeraios(%d)
    return 0; 
} 