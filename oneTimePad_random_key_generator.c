#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp, *plain, *keyfile, *enc; 
    plain = fopen("message.txt", "r+");
    unsigned char ch, ch2;
    //read from urandom
    int i = 0, ch1, len;
    for (i = 0; (ch1 = getc(plain) != EOF); i++)
        ;
    fclose(plain);
    len = i;
    fp = fopen("/dev/urandom", "r+");
    keyfile = fopen("key.txt", "w+");
    for (i = 0; i < len; i++)
    {
        fscanf(fp, "%c", &ch);
        fprintf(keyfile, "%02X", ch);
    }
    fclose(fp);
    fclose(keyfile);
    printf("\nEncrypting... :\n");
    keyfile = fopen("key.txt", "r+");
    plain = fopen("message.txt", "r+");
    enc = fopen("enc.txt", "w+");
    ///the key can be found in key.txt
    printf("\nEncrypted Message:\n");
    for (i = 0; i < len; i++)
    {
        fscanf(plain, "%c", &ch1);
        fscanf(keyfile, "%c", &ch2);
        fprintf(enc, "%c", ch1 ^ ch2);
        printf("%x", ch1 ^ ch2);
    }
    printf("\n");
    fclose(keyfile);
    fclose(plain);
    fclose(enc);
    keyfile = fopen("key.txt", "r+");
    enc = fopen("enc.txt", "r+");
    ///the key can be found in key.txt
    printf("\nDecrypted Message:\n");
    for (i = 0; i < len; i++)
    {
        fscanf(enc, "%c", &ch1);
        fscanf(keyfile, "%c", &ch2);
        printf("%x", ch1 ^ ch2);
    }
    printf("\n");
    fclose(keyfile);
    fclose(enc);
    
    return 0;
}