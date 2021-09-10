#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char m[100];
    int k;
    printf("\nENCRYPTION- \nEnter the key number (it should be in range of 0 to 25): ");
    scanf("%d", &k);
    printf("Enter the message: ");
    scanf("%s", &m);
    for (int i = 0; i < strlen(m); i++)
    {
        m[i] = 'a' + (((m[i] - 'a') + k) % 26);
    }
    printf("The Encrypted message:  %s\n", m);
    printf("\nDECRYPTION- \n ");
    for (int i = 0; i < strlen(m); i++)
    {
        m[i] = 'a' + (((m[i] - 'a') - k + 26) % 26);
    }
    printf("The decrypted message: %s\n\n", m);
    return 0;
}