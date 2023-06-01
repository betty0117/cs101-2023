#include<iostream>
#include<fstream>

using namespace std;

class myString{
    private:
        string m_str;
    public:
        myString(string s){
            m_str = s;
        }
};

//class ReadClass{
//    myString(class);
    
//}

int main(){
    ifstream in;
    string line;
    string str1="class";
    in.open("main.cpp");
    int a;
    if(in.fail()){
        cout<<"Error opening a file"<<endl;
        in.close();
    }
    
    while(getline(in,line)){
       // cout<<line<<endl;
    //}
    
    
 //   while(!in.eof()){
 //       getline(in,line);  //getline讀檔(會讀空格)，但是不會讀"\n"
      //  for(int i=0;i<line.size();i++){
         //   {
        if(line[0]==str1[0]&&line[1]==str1[1]&&line[2]==str1[2]&&line[3]==str1[3]&&line[4]==str1[4]){
                a=a+1;
                
            }
        //}
            
      //  }
    }
    
   /* int a=0;
    string b="class";
    if(getline(in,line)=b){
        a++;
    }*/
    cout<<a<<endl;
    
    in.close();

}
