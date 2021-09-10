#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char m[100], k[100];
    //for encryption
    printf("\nENCRYPTION- \nEnter the key string : ");
    scanf("%s", &k);
    printf("Enter the message: ");
    scanf("%s", &m);
    if (strlen(m) > 100 || strlen(k) > 100)
    {
        perror("The message and the key has a size limit of 100 characters");
        return 1;
    }
    int b = strlen(k);
    for (int i = 0; i < strlen(m); i++)
        k[i] = k[i % b];

    for (int i = 0; i < strlen(m); i++)
        m[i] = (((m[i] - 'a') + (k[i] - 'a') + 1) % 26) + 'a';

    //for decryption
    printf("The Encrypted message :  %s\n", m);
    printf("\nDECRYPTION- \n");

    for (int i = 0; i < strlen(m); i++)
        m[i] = 'a' + ((m[i] - 'a') - (k[i] - 'a') + 25) % 26;
    printf("The decrypted message: %s\n", m);

    return 0;
}