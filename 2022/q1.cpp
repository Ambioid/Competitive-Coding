#include <iostream>
#include <string>

using namespace std;

string decrypt(string str2) {
    char n;
    for (int i = str2.length()-1; i > 0 ; i--){
        n = str2[i]-str2[i-1] + 64;

        if (n < 65){
            n += 26;
            }
        // cout << n << endl;
        str2[i] = n;

    }
    return str2;
}
string encrypt(string str) {
    char n;
    for (int i = 1; i < str.length(); i++){
        n = str[i]+str[i-1] - 64;

        if (n > 90){
            n -= 26;
            }
        // cout << n << endl;
        str[i] = n;

        
    }
    // cout << str << endl;
    return str;
}

int iterations_for_original(){
    string str = "OLYMPIAD";
    string str2 = str;
    cout << endl;
    
    str2 = encrypt(str2);
    int i = 1;
    while (str != str2){
        i++;
        str2 = encrypt(str2);
    }
    cout << str << ", " << str2 << ", " << i << endl;
    return i;
}

int how_many_strings(){
    int count = 0;
    for (int i = 65; i < 91; i++)
    {
        str[0] = i;
        for (int u = 65; u < 91; u++)
        {
            str[1] = u;
            for (int o = 65; o < 91; o++)
            {
                str[2] = o;

                string str2 = str;

                str2 = encrypt(str2);
                int encryption_count = 1;

                while (str != str2)
                {
                    encryption_count++;
                    str2 = encrypt(str2);
                }
                // cout << str << ", " << str2 << ", " << encryption_count << endl;

                if (999999999999 % encryption_count == 0)
                {
                    count++;
                    cout << str << ", " << encryption_count << ", " << count << endl;
                }
            }
        }
        cout << count << endl;
    }
    return count;
}

int main()
{
    string str = "AAA";

    cout << "Enter string to decrypt please" << endl;;
    cin >> str;

    cout << decrypt(str) << endl;
    
    
    
}

