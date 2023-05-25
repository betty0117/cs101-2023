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
            getline(in,str);  //getline讀檔(會讀空格)，但是不會讀"\n"
            for(int i=0;i<str.size();i++){
                if(str[i]==a[0]&&str[i+1]==a[1]){
                    str.replace(str.begin()+i,str.begin()+i+2,b);//用b字串替換從i位置開始的2個字元
                }
    
                
            }
            out<<str<<endl;
        }
        }
};

int main()
{

    ReplaceMyString my;
    my.replaceString("IU","IU is best");

    return 0;
}
