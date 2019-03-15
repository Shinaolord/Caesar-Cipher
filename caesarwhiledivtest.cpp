#include <iostream>
#include<cstdlib>

std::string caesarencrypt(std::string ptext, int shift){
    std::string ctext= "";

    for(int i=0;i<ptext.length();i++){

            if(islower(ptext[i])){
                ptext[i]=toupper(ptext[i]);
            } /* turns everything into uppercase letters, which ASCII vary from 65 to 65+25=90 */
            if(ptext[i]==' '){
                ctext+=' ';
            }
            else{
                    if(shift<0){shift=shift+26;};
                    div_t division= div(ptext[i]+shift-65,26);
                    int rem= division.rem;
                    ctext += (char)(rem+65); /* take each letter, add the shift, subtract the value that makes it ASCII (65), take mod 26, then add the ASCII value again */
            }



    }
    return ctext;
}
/* to decrypt, set shift= -shift, ie., if shift was 5 to encrypt, to decdrypt, set shift= -5*/
int main(){
    int shiftval;
    std::string ptxt;
    std::cout<< "Please input the shift value, then the plaintext, separated by a space"<<std::endl;
    while(std::cin>>shiftval && std::getline(std::cin,ptxt)){
        std::cout << "Plaintext:" << ptxt <<"\n";
        std::cout <<"Ciphertext:" << caesarencrypt(ptxt,shiftval)<<std::endl;
    }

    return 0;
}
