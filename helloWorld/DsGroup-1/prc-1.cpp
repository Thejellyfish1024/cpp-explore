#include <stdio.h>

int main()
{
    int size;
    scanf("%d", &size);
    if (size < 6)
    {
        printf("The size have to be at least 6");
    }
    else
    {
        char arr[size];
        int vowel = 0, consonent = 0;
        for (int i = 0; i < size; i++)
        {
            scanf("%c", &arr[i]);
            if ((arr[i] == 'a') || (arr[i] == 'e') || (arr[i] == 'i') || (arr[i] == 'o' )|| (arr[i] == 'u'))
            {
                vowel++;
            }
            else
                consonent++;
        }
        for (int i = 0; i < size; i++)
        {
            printf("%c", &arr[i]);
        
        }
        printf("\nvowel = %d \nConsonent = %d", vowel, consonent);
    }
}