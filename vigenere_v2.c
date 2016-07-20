#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
    
char keyAlpha(char x); 
char upConvert(char y); 
char downConvert(char z);  
                    
int main(int argc, char* argv[])
    {
          int count = 0;
          int clCount = 0;
          char* key = argv[1];
         
          /*checks for how many arguments there are (max 2 arguments)*/
          if(argc > 2){
            printf("Too many arguments, please try again.\n");
            return 1;
            }
            
          /*checks if there are any characters in the second argument*/
          if(argv[1] == NULL){  
            printf("No arguments, try again.\n");
            return 1;
            }
            
          /*checks that there are no characters in the key*/
           for(int k = 0; k<=10 ;k++)
           { 
            if (key[k]>=48 && key[k] <=57)
                {
                printf("no numbers in key\n");
                return 1; 
                }   
           }
          char word[50];
          scanf("%s",word);
          int keyLen = strlen(key);

              for(int i = 0, len = strlen(word); i <= len;i++)
              {

              ////////////////////////////////// In this section is where the error lies. once j-1 is executed, j=i again which throws it off.
                   int j = i; //j is the jth char in the key
                   
                                        // this section is the key to the whole damn thing.
                  if ( (word[i] <=64) || (word[i]>=91 && word[i]<=96) || (word[i]>122) ){  
                        count = count+1;
                        clCount = clCount+1; 
                        }
                  if(count>0){
                        j = i-clCount;// clCount should go up by the amount of spaces there are.. 1,2,3,4,5 etc
                        count++;     
                  }

           if(word[i]>=65 && word[i]<=90) //upper case
                {
                  int c = (((word[i]+keyAlpha(key[j%keyLen]))%26)+52);
                  c = upConvert(c);
                  printf("%c",c);           
                }
           else if(word[i]>=97 && word[i]<=122) // lowercase
                 {
                  int c = (((word[i]+keyAlpha(key[j%keyLen]))%26)+78);
                  c = downConvert(c);
                  printf("%c",c);   
                 }
                   
           else if(word[i] != 0) {
               printf("%c", word[i]);
               
                }else break;
          }  
              
              printf("\n"); 
              return 0;       
     }
    
        char keyAlpha(char x)
            {
               if (isupper(x))
                    {//uppercase - working returns the numeric value of a letter ie A = 0 B = 1
                      x = x%26-12;
                         if ( x<1 || x>26 )
                         { 
                             if (x<1)
                                  x = x+26;
                             if (x > 26)
                                  x = x-18;
                             return x-1;
                         }else return x-1;
                }
                
                else  if (islower(x))
                    {//lowercase -  working  returns the numeric value of a letter ie a = 0 b = 1
                      x = x%26-18 ;
                          if (x<1 || x>26)
                          { 
                              if (x<1)
                                  x = x+26;
                          if (x > 26)
                                  x = x-18;
                              return x-1;
                         }else return x-1;
                     }else return x;
              }
           
 char upConvert(char y){ //fixes uppercase out of range
    
     if (y<'A'){
         y = y+26;
         return y;
         }
     if (y > 'Z'){
         y = y-26;
         return y;
         }
    else return y;
    }      

char downConvert(char z){
   if (z<'a'){
         z = z+26;
         return z;
         }
     if (z > 'z'){
         z = z-26;
         return z;
         }
    else return z;
    }      

