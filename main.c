/*  This program will allow the user to choose an option from a menu to either call on a function
    that arranges their name (1-name function) or a function that verifies a password entered (2-password function).
    - The name function is called into the main function asking the user to enter their
    first, middle, and last name which will be stored into 3 separate c-strings.
    The function will then rearrange the user's name (last, first middle) and store it in another c-string array.
    Program will lastly display the new arrangement of their name.
    - The password function is also called into main asking the user to enter a password.
    Once a password is entered, the function will verify the password to ensure it meets the 6 criteria's.
    Each criteria that is unmet will display it's own error message to the user,
    if all criteria's are met the password has successfully been verified.
 */

#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "string.h"


// Function will ask user to enter first, middle, and last name. Once program reads in the typed in names
// It will store each name section into 3 separate c-string arrays. The arrays will then merge and be
// rearranged in a new order to be displayed back to the user
// rearrangement: ---lastName, firstName middleName---

void nameFunction()
{
    
    /* Defining the 3 separate c-string arrays
       to store the first, middle, and last name of user.
       Defining a c-string array that will store the first, middle, and last name merged
       together in a specific name arrangement:
       (lastName, firstName middleName)
    */
    
    char firstName[25], middleName[25], lastName[25];
    
    char nameArrange[80];
    
    
    // Asking user to enter first, middle, and last name
    printf("Enter your first name, middle name, and last name\n");
    
    // Program will read the names enterd by user
    scanf("%s %s %s", firstName, middleName, lastName);
    
    
    // To place the last name of user first in the name arrangement,
    // 'strcpy()' modification function will allow the lastName array to be copied into the nameArrange array
    strcpy(nameArrange, lastName);
    
    // A 'comma' and 'space' will then be added into the nameArrange array before placing the firstName.
    // This will be done using 'strcat()' to easily append the characters onto the lastName
    strcat(nameArrange, ", ");
    
    // 'strcat()' will also be used to append the firstName into the new name arrangement
    strcat(nameArrange, firstName);
    
    // Another 'space', using 'strcat()', after the firstName is added in the arrangement, before the middleName
    strcat(nameArrange, " ");
    
    // The middleName is now placed at the end of the arrangement, again using 'strcat()'
    strcat(nameArrange, middleName);
    
    // Displaying new name arrangement back to user
    printf("%s\n", nameArrange);
}



// Function will ask user to enter a password to verify that it meets specific criteria.
// Password entered will be tested to meet 6 criteria and for each unmet criteria the program will display
// an error message.
// If all criteria is met, password verification is successful

void passFunction()
{
    
    // Define a c-string array to contain or store the password entered by user

    char password[25];
    
    
    // Ask user to enter a password to be verfified
    printf("Enter a password to be verified\n");
    
    // Program will read password entered by user
    scanf ( "%s", password);
    
    // Define an integer value to find the number of characters in the password entered
    // Find the number of characters in the password entered by finding the length of the c-string
    long int passLength = strlen(password);
    
    // Password must atleast have 6 characters
    // If password is too short, an error message will display to the user
    if (passLength < 6)
    {
        printf("Password too short\n");
    }

    // Password must have no more than 14 characters
    // If password is too long, an error message will display to the user
    if (passLength > 14)
    {
        printf("Password too long\n");
    }
    
    // Define integer values to keep track of the lowercase, uppercase, digits, and punctuations
    // loop to find lowercase and uppercase letters, as well as, find digits and punctuations in the password entered
    int lower = 0;
    int upper = 0;
    int digit = 0;
    int punct = 0;
    
    // loop will contain integer value 'count' to count each loop that takes place until null terminator is found
    // at the end of the c-string which holds the password entered by user
    // integer values: lower, upper, digit, & punct will add 1 to their value if their characters
    // are found in the password entered until loop reaches to a stop
    for (int count = 0; password[count] != '\0'; count++)
    {
        // check for lowercase letters in password
        if (islower(password[count]) != 0)
        {
            lower++;
        }
        
        // check for uppercase letters in password
        if (isupper(password[count]) != 0)
        {
            upper++;
        }
        
        // check for digits in password
        if (isdigit(password[count]) != 0)
        {
            digit++;
        }
        
        // check for punctuation symbols in password
        if (ispunct(password[count]) != 0)
        {
            punct++;
        }
        
    }

    
    // Password must have atleast one lowercase letter
    // If password is missing lowercase letter, an error message will display to the user
    if (lower == 0)
    {
        printf("Password missing lowercase letter\n");
    }

    // Password must have atleast one uppercase letter
    // If password is missing uppercase letter, an error message will display to the user
    if (upper == 0)
    {
        printf("Password missing uppercase letter\n");
    }
 
    // Password must have atleast one digit
    // If password is missing a digit, an error message will display to the user
    if (digit == 0)
    {
        printf("Password missing digit\n");
    }
    
    // Password must have atleast one  punctuation symbol
    // If password is missing punctuation, an error message will display to the user
    if (punct == 0)
    {
        printf("Password missing punctuation\n");
    }
    
    // If password meets all criteria, the verification was successfull
    if ((passLength > 6) && (passLength < 14) && (lower > 0) && (upper > 0) && (digit > 0) && (punct > 0))
    {
        printf("Valid password\n");
    }
    
}




// main function will display menu system to user and allow user to choose which function to run
// function will read the character the user printed
// main will call on name function if user types in '1'
// main will call on password function if user types in '2'
// If user types invalid character (anything other than '1' or '2'), Error message will display to user

int main()
{
    // Define integer to be typed in by user
    int menu;
    
    // ask user to choose from menu
    printf("Enter the number of the function you'd like to run:\n");
    printf("1 - name function\n");
    printf("2 - password function\n");
    

    // Program will read the number entered by user
    scanf("%i", &menu);
    
    // If user typed the number 1, the name function will run
    // If user typed the number 2, the password function will run
    if (menu == 1)
    {
        nameFunction();
    }
    else if (menu == 2)
    {
        passFunction();
    }
    else
    {
        printf("Error\n");
    }
    
    
    return 0;
}
