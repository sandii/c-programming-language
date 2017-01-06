/*空格串替换为最小数目的空格和制表符*/  
#include<stdio.h>  
#define TABINC 8  //   每隔TABINC个位置就会出现一个制表符   
/*程序设计思想找出全部空格*/  
int main() {
  int c,nb,nt,pos;  
  nb = 0;   //替换空格串的最少空格数   
  nt = 0;   //替换空格串的最少制表符数   
  for (pos = 1; (c = getchar()) != EOF; pos++) {  
    if (c == ' ') {
      if(pos%TABINC!=0)  //如何理解   
        nb++;  
      else {                  
        nb = 0;      
        nt++;  
      }  
    } else {  
      for (; nt > 0; nt--) {
        putchar('\t');  
      }
      if (c == '\t')
        nb = 0;  
              else  
                  for(;nb>0;nb--)  
                  putchar(' ');  
            putchar(c);  
            if(c=='\n')  
               pos=0;  
            else if(c=='\t')  
               pos=pos+(TABINC-(pos-1)%TABINC-1);            
            }         
 }  