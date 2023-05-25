#include <iostream>
#include<fstream>
#include<string>

using namespace std;
class ReplaceMyString{
    public:
        void replaceString(string a,string b){
        string str;
        ifstream in("main.cpp");
        ofstream out("remain.cpp");
        while(!in.eof()){
            getline(in,str);
            
            
            for(int i=0;i<str.size();i++){
                if(str[i]==a[0]&&str[i+1]==a[1]){
                    str.replace(str.begin()+i,str.begin()+i+2,b);
                }
                
            }
            out<<str<<endl;
            }
        }
};

int main()
{

    ReplaceMyString my;
    my.replaceString("IU is best","IU is best is best");

    return 0;
}

