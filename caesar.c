#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, string argv[])
{
    // Validate & convert command line input and get plaintext
    if (argc == 2)
    {
        int key = atoi(argv[1]);
        string text = GetString();
        
        // Encrypt plaintext
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            // Encrypt char if it is a letter
            int cipher;
            if (isalpha(text[i]))
            {
                if (isupper(text[i]))
                {
                    cipher = ((text[i] - 65 + key) % 26) + 65;
                }
                else 
                {
                    cipher = ((text[i] - 97 + key) % 26) + 97;
                }
            }            
            
            // Don't encrypt char if it's not a letter
            else
            {
                cipher = text[i];
            }
            
            // Print char of ciphertext
            printf("%c", cipher);      
        }
        
        printf("\n");
    
    }
    
    // Return an error if user input is not valid
    else
    {
        printf("Usage: ./caesar <key>\n");
        return 1;
    }
}
