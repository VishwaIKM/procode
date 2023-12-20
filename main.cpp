#include <iostream>
#include "vps_aes_gcm.h"

using namespace std;

int main()
{
    vps_aes obj;

    unsigned char key[] = "0123456789012345678901234567898";
    unsigned char iv[] = "012345678901234";

    unsigned char plaintext[] = "I am doing my best to improve my self everyday.";
    unsigned char ciphertext[600];
    unsigned char decryptedtext[600];
    int decryptedtext_len = 0, ciphertext_len = 0;

    obj.init_vps_context_aes(key,iv);

    ciphertext_len = obj.do_encrypt(plaintext,sizeof(plaintext),ciphertext);

    printf("Ciphertext is:\n");
    BIO_dump_fp(stdout, ciphertext, ciphertext_len);

    decryptedtext_len = obj.do_decrypt(ciphertext,ciphertext_len,decryptedtext);
    
    if(decryptedtext_len < 0)
    {
        /* Verify error */
        printf("Decrypted text failed to verify\n");
    }
    else
    {
        /* Add a NULL terminator. We are expecting printable text */
        decryptedtext[decryptedtext_len] = '\0';

        /* Show the decrypted text */
        printf("Decrypted text is:\n");
        printf("%s\n", decryptedtext);
    }
    std::cout<<"=================================="<<std::endl;

    unsigned char plaintext1[] = "I am pro code.";
    unsigned char ciphertext1[600];
    unsigned char decryptedtext1[600];
    decryptedtext_len = 0, ciphertext_len = 0;


    ciphertext_len = obj.do_encrypt(plaintext1,sizeof(plaintext1),ciphertext1);

    printf("Ciphertext is:\n");
    BIO_dump_fp(stdout, ciphertext1, ciphertext_len);

    decryptedtext_len = obj.do_decrypt(ciphertext1,ciphertext_len,decryptedtext1);
    
    if(decryptedtext_len < 0)
    {
        /* Verify error */
        printf("Decrypted text failed to verify\n");
    }
    else
    {
        /* Add a NULL terminator. We are expecting printable text */
        decryptedtext1[decryptedtext_len] = '\0';

        /* Show the decrypted text */
        printf("Decrypted text is:\n");
        printf("%s\n", decryptedtext1);
    }

    return 0;
}