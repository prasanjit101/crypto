#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char m[100],k[26],k2[26],c;

//for encryption
    printf("\nENCRYPTION- \nEnter the key string of size 26 : ");
    scanf("%s", &k);
    printf("Enter the message: ");
    scanf("%s", &m);
    if (strlen(m) >100 || strlen(k)>26){
        perror("The message and the key has a size limit of 100 and 26 respectively");
        return 1;
    }

    for (int i = 0; i < strlen(m); i++){
        c=m[i];
        m[i] = k[m[i] - 'a'];
        k2[m[i]-'a']=c;
    }

//for decryption
    printf("\nThe Encrypted message :  %s\n", m);
    printf("\nDECRYPTION- \n");
    for (int i = 0; i < strlen(m); i++)
        m[i]=k2[m[i]-'a'];

    printf("The decrypted message: %s\n\n", m);
    return 0;
}