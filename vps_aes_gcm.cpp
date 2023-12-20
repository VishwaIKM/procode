//Need to code as per NSE NNF DOC by Vishwa 19-dec-2023
#include <iostream> 
#include "vps_aes_gcm.h"

void vps_aes :: init_vps_context_aes(unsigned char *key,unsigned char *iv)
{
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    //tip
    if(!(vps_ctx = EVP_CIPHER_CTX_new())) handle_error();
    if(!(vps_ctx_dec = EVP_CIPHER_CTX_new())) handle_error();
    if(!EVP_DecryptInit_ex(vps_ctx_dec, EVP_aes_256_gcm(), NULL, key, iv)) handle_error();
    if(1 != EVP_EncryptInit_ex(vps_ctx, EVP_aes_256_gcm(), NULL, key, iv)) handle_error();

    
    
}
int vps_aes :: do_encrypt(unsigned char *plaintext, int plaintext_len,unsigned char *ciphertext)
{
    int len =0;
    if(1 != EVP_EncryptUpdate(vps_ctx, ciphertext, &len, plaintext, plaintext_len))
            handle_error();

    
    return len;
}
int vps_aes :: do_decrypt(unsigned char *ciphertext, int ciphertext_len,unsigned char *plaintext)
{
    int len =0;
    if(!EVP_DecryptUpdate(vps_ctx_dec, plaintext, &len, ciphertext, ciphertext_len))
            handle_error();

    return len;
}

void vps_aes :: handle_error(void)
{
    unsigned long err = ERR_get_error();
    std::cout<<" Logic Failed ...[vps_aes Handle Error Called]"<<std::endl;
    std::cout<< "err code :"<<err<<std::endl;
    std::cout<<"Core dump starting";
    abort();
}