#include <iostream>
using namespace std;
class Fueltank{
    private:
        int m_FueltankCapacity;
        int m_Gas_grade;
    public:
        Fueltank(int FueltankCapacity=3000, int Gas = 98){
            m_FueltankCapacity=FueltankCapacity;
            m_Gas_grade=Gas;
        }
        int fuel_up(int v,int gas){
            if (v<=m_FueltankCapacity&&gas==m_Gas_grade)
                cout<<"fuel_up : "<<v<<" Gas_grade : "<<gas<<endl;
            else if(v<=m_FueltankCapacity&&gas!=m_Gas_grade)
                cout<<"Error : Gas_grade : "<<gas<<" Correct Gas_grade : "<<m_Gas_grade<<endl;
            else if (v>m_FueltankCapacity&&gas==m_Gas_grade){
                cout<<"Error : FueltankCapacity : "<<m_FueltankCapacity<<" but fuel up : "<<v<<endl;
                cout<<"fuel_up : "<<v<<" Gas_grade : "<<gas<<endl; 
            }
            else if (v>m_FueltankCapacity&&gas!=m_Gas_grade){
                cout<<"Error : FueltankCapacity : "<<m_FueltankCapacity<<" but fuel up : "<<v<<endl;
                cout<<"Error : Gas_grade : "<<gas<<" Correct Gas_grade : "<<m_Gas_grade<<endl;
            }
            return 0;
            
        }
        int set_Gas_grade(int Gas_grade){
            m_Gas_grade=Gas_grade;
            
            return m_Gas_grade;
        }
        int get_Gas_grade(){
            return m_Gas_grade;
        };
};
class Car{
    private:

        Fueltank m_Fueltank;
        int m_MaxSeating;
        int m_price;
        int m_base;
        string m_brand;
        string m_model;
        int m_year;
        void M_UpdatePrice(int base=500000){
            
            
        }
    public:
        Car(string x, string y, int z, int s){
            m_brand=x;
            m_model=y;
            m_year=z;
            m_MaxSeating=s;    
        }
        int get_MaxSeating(){
            return m_MaxSeating;
        }
        int get_Price(){
            return m_price;
        }
        void set_base(int n){
            m_base=n;
        }
        string get_brand(){
            return m_brand;
        }
        int get_Gas_grade(){
            return m_Fueltank.get_Gas_grade();
        }
        int set_Gas_grade(int gas=98){
            return m_Fueltank.set_Gas_grade(gas);
        }
        int fuel_up(int v, int gas=98){
             return m_Fueltank.fuel_up(v,gas);
        }
};
class AUDI_Car : public Car{
    private:
        string m_DriveMode;
    public:
        AUDI_Car(string y,int z,int s):Car("AUDI",y,z,s){
            cout<<"Constructing AUDI_Car\n";
        }
};
int main(){
    AUDI_Car car_2("A1",2021,2);
    cout<<car_2.get_brand()<<" : Gas_grade = "<<car_2.get_Gas_grade()<< endl;
    car_2.set_Gas_grade(95);
    cout<<car_2.get_brand()<<" : Gas_grade = "<<car_2.get_Gas_grade()<< endl;
    car_2.fuel_up(300,95);
}
