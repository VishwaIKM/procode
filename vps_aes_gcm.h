#pragma once

//open ssl vps_aes code  by Vishwa 20-dec-2023
#include <openssl/err.h>
#include <openssl/aes.h>
#include <openssl/evp.h>

class vps_aes
{
    private:
        //var & point
        EVP_CIPHER_CTX *vps_ctx = NULL;
        EVP_CIPHER_CTX *vps_ctx_dec = NULL;
        //function
        
        void handle_error(void);
       
    public:
        void init_vps_context_aes(unsigned char *key,unsigned char *iv);
        int do_encrypt(unsigned char *plaintext, int plaintext_len,unsigned char *ciphertext);
        int do_decrypt(unsigned char *ciphertext, int ciphertext_len,unsigned char *plaintext);


};