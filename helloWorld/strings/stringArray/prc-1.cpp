#include <iostream>
#include <ctype.h>

int main()
{
    int size;
    printf("Enter the number of inputs (at least 6): ");
    scanf("%d", &size);

    if (size < 6)
    {
        printf("The size has to be at least 6\n");
        return 1;
    }
    char arr[size];
    int vowel = 0, consonant = 0;
    
    printf("Enter %d characters: ", size);
    
    for (int i = 0; i < size; i++)
    {
        scanf(" %c", &arr[i]);
        char ch = tolower(arr[i]);
        
        if ((ch >= 'a' && ch <= 'z')) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowel++;
            }
            else
            {
                consonant++;
            }
        }
    }
    
    printf("Inputs entered: ");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    
    printf("\nVowels = %d \nConsonants = %d\n", vowel, consonant);

    return 0;
}
