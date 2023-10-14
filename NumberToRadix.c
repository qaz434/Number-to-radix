#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
/*
*This function removes spaces in a string
*@param *str The string pointer of the expression
*/
void removeSpaces(char *str){
    char *end = str;
    //
    do{
        if(*end != ' ')
            *str++ = *end;
    }
    //termniatess when \0 is reached
    while(*end++ != '\0');
}
/*
*Evaluates the expression strictly left to right
*@param res The sum of the evaluation
*@param val The value of the digit in the string 
*@param *str The string pointer of the expression
*@return The result of the expression
*/
int evaluate(int res, int val, char *str){
   for (int i = 1; str[i] != '\0'; i += 2)
    {
        // if there is only one number, return the number
        if(str[1]=='\0'){
            return res;
        }
       char opr = str[i];
       //converts the character into a digit
       val=str[i+1]-'0';

        // Updates the results according to the operator
        if (opr == '+'){
            res += val;
        }       
        else if (opr == '-'){
            res -= val;
        }  
        else if (opr == '*'){
            res *= val;
        }
        else if (opr == '/'){
            res /= val;
        }
        else{
            printf("Cannot evaluate\n");fflush(stdout);
            str[i]='\0';
        }
    }
   return res;
}
/*
*This function reverses a string
*@param *str The string pointer of the conversion
*/
void strReverse(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length/2; i++)
    {
        char temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }
}
/*
*Converts the results from task#1 using the radix specified by the user
*@param num The result that is going to be converted
*@param r The user chosen radix
*/
void convert(int num, int r){
    char digit[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char convertedValue[100];
    int i,negative=0;
    //if the number is negative, it will turn positive
    if (num < 0 )
    {
        negative = 1;
        num *= -1;
    }
    // converts the number from the user's chosen radix
    if (num != 0)
    {
        for(i = 0 ; num > 0; i++)
        {
            int index = num % r;
            convertedValue[i] = digit [index];
             num = num / r;
        }
        convertedValue[i] = '\0';
    }
    //adds the negative symbol if the result was negative
    if (negative == 1 )
    {
        printf("-");
    }
    //reverses the results
    strReverse(convertedValue);
    //prints the value that is now converted from the radix
    printf("%s\n",convertedValue);fflush(stdout);
}

int main()
{
    char str[80];
    int val=0,res,radix;
    //user inputs expression
    printf("Enter a number: ");fflush(stdout);
     scanf("%[^\n]", str); 
     //calls function to remove spaces in the string
     removeSpaces(str);
     //Turns the first number in the string into an int
     res=atoi(str);
     //calls function to evaluate the expression and print the result
     printf("%i\n",evaluate(res, val, str));fflush(stdout);
     //user inputs radix
    printf("Enter radix ");fflush(stdout);
    scanf("%i", &radix); 
    //calls function to convert the number
    convert(evaluate(res, val, str), radix);
}
