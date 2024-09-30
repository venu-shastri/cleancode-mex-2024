

#include <stdio.h>
#include <string.h>
#include <ctype.h> 

typedef int (*predicateStringFptr)(const char*);
typedef int (*predicateIntFptr)(const int);

//Separation
// function , Object
//pure function - functional programming
//testable ,predicatble , no sideeffects ,ideal for multi threading , performant
int startsWithB(const char* str) { return toupper(str[0]) == 'B'; } 
int startsWithC(const char* str) { return toupper(str[0]) == 'C'; } 
int isEven(int number){ return number % 2==0;}

            /* Parameterize Data*/  /* Parameterize function using function pointer*/
void queryStringArray(const char* source[],int size ,predicateStringFptr predicate){
    
     for (int i = 0; i < size; i++) { 
        if (predicate(source[i])) { 
            printf("%s\n", source[i]); 
            } 
     }
         
}
void queryIntegerArray(const int* source,int size ,predicateIntFptr predicate){
    
     for (int i = 0; i < size; i++) { 
        if (predicate(source[i])) { 
            printf("%d\n", source[i]); 
            } 
     }
         
}
void queryAnyTypeArray(const dataTypeParameter* source,int size , int(*PredicateFptr)(dataTypeParameter)){
    
     for (int i = 0; i < size; i++) { 
        if (PredicateFptr(source[i])) { 
            printf("%Type\n", source[i]); 
            } 
     }
         
}
 int main() {
     // Define an array of strings 
     const char* names[] = {"Bosch", "Bangalore", "Mexico", "Canada" ,"India"}; 
     const int numbners[]={2,4,5,6,67,7,8};
     int size = sizeof(names) / sizeof(names[0]); 
    // query(names,&startsWithB);
     queryStringArray(names,size,startsWithB);
       queryStringArray(names,size,startsWithC);
       queryIntegerArray(numbners,7,isEven);
            return 0; 
    } 
            
