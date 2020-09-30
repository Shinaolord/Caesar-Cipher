#include <iostream>
#include<conio.h>
using namespace std;

string caesarencrypt(string ptext, int shift)
{
	string ctext= "";
    for(int i=0;i<ptext.length();i++)
	{
		if(islower(ptext[i]))
		{
            ptext[i]=toupper(ptext[i]);		 /* turns everything into uppercase letters, which ASCII vary from 65 to 65+25=90 */
        }
        if(ptext[i]==' ')
		{
            ctext+=' ';
        }
    	else
		{
            if(shift<0)
			{
				shift=shift+26;
			}
			ctext += char(int( ptext [i] + shift - 65) % 26 + 65 );		/* take each letter, add the shift, subtract the value that makes it ASCII (65), take mod 26, then add the ASCII value again */
        }
    }
    return ctext;
}
int main()
{
    int shiftval;
    string ptxt;
    cout<< "Please input the shift value, then the message, separated by a space ..."<<endl<<"(to decrypt, set shift with (-)ve sign)"<<endl<<"Type Here : "<<endl;
	cin>>shiftval;
	getline(cin,ptxt);			/* to decrypt, set shift= -shift, ie., if shift was 5 to encrypt, to decrypt, set shift= -5*/
    cout << "Plaintext:" << ptxt <<"\n";
    cout <<"Ciphertext:" << caesarencrypt(ptxt,shiftval);
    getch();
    return 0;
}
