//A2305220739_Sanjana
/*              BOILER PLATE
Name of the student : Sanjana
Enrollment Number : A2305220739 
Class & Section : 3CSE9-X
*/
#include<iostream>
#include<ctime>
using namespace std;
int car=0, truck=0, bus=0,mcycle=0, bcycle=0,scooter=0, other2=0, other4=0;
class info{
    public:
    static long int password;
    int day, mon, year, hr, min, tim;
    char name[30];
    long int vNo,mNo;
    int vtype, wayType, amount;
    
    //function to enter nd time
    void inputDateTime(){
        cout<<"\n\t\t\t\tEnter today's date (dd/mm/yyyy) : ";
        cin>>day>>mon>>year;
        cout<<"\n\t\t\t\tEnter time (hr:min) : ";
        cin>>hr>>min;
        cout<<"\n\t\t\t\tChoose-> ";
        cout<<"\t1. A.M.";
        cout<<"\t\t2. P.M.";
        cout<<"\n\t\t\t\tEnter your choice(1/2) : ";
        cin>>tim;
     }
     void pinfo(){
        cout<<"\n\t\t\t\tEnter name : ";
        cin>>name;
        cout<<"\n\t\t\t\tEnter vehicle number : ";
        cin>>vNo;
        cout<<"\n\t\t\t\tEnter mobile number : ";
        cin>>mNo;
     }
    
};
class vehicle : public info {
    public:
    char temp[10];
    int wtype2, wtype4;
    //function to add category and sub-category of vehicle
    void inputVehicle(){
        cout<<"\n\t\t\t\tEnter vehicle type : ";
        cout<<"\n\t\t\t\t\t1. 2-wheeler";
        cout<<"\n\t\t\t\t\t2. 4-wheeler";
        cout<<"\n\t\t\t\tEnter your choice(1-2) : ";
        cin>>vtype;
        switch(vtype) {
            case 1 :
                    cout<<"\n\t\t\t\tEnter subcategory of 2-wheeler : ";
                    cout<<"\n\t\t\t\t\t1. Scooter";
                    cout<<"\n\t\t\t\t\t2. Motorcycle";
                    cout<<"\n\t\t\t\t\t3. Bicycle";
                    cout<<"\n\t\t\t\t\t4. Other";
                    cout<<"\n\t\t\t\tEnter your choice(1-4) : ";
                    cin>>wtype2;
                    switch(wtype2){
                        case 1 : scooter++; break;
                        case 2 : mcycle++;  break;
                        case 3 : bcycle++;  break;
                        case 4 :cout<<"\n\t\t\t\tEnter 2-wheeler sub-category name : ";
                                cin>>temp;
                                other2++;
                                break;
                        default: cout<<"\n\t\t\t\tINVALID CHOICE!!!";
                    }
                    break;
            case 2 :
                    cout<<"\n\t\t\t\tEnter subcategory of 4-wheeler : ";
                    cout<<"\n\t\t\t\t\t1. Car";
                    cout<<"\n\t\t\t\t\t2. Truck";
                    cout<<"\n\t\t\t\t\t3. Bus";
                    cout<<"\n\t\t\t\t\t4. Other";
                    cout<<"\n\t\t\t\tEnter your choice(1-4) : ";
                    cin>>wtype4;
                    switch(wtype4){
                        case 1 : car++;  break;
                        case 2 : truck++;  break;
                        case 3 : bus++;  break;
                        case 4 : cout<<"\n\tEnter 4-wheeler sub-category name : ";
                                 cin>>temp;
                                 other4++;
                                 break;
                        default: cout<<"\n\t\t\t\tINVALID CHOICE!!!";
                    }
                    break;
            default:
                    cout<<"\n\t\t\t\tINVALID CHOICE !!!!";
        }
    }
    
    int payment() {
        cout<<"\n\t\t\t\tRegistering for ->";
        cout<<"\t1. One way";
        cout<<"\t\t2. Two way";
        cout<<"\n\t\t\t\tEnter your choice (1-2) : ";
        cin>>wayType;
        if(vtype==1){
            if(wayType==1){
                amount=200;
                cout<<"\n\t\t\t\tYou need to pay "<<amount<<" Rs for one way ";
            }
            else if(wayType==2){
                amount=350;
                cout<<"\n\t\t\t\tYou need to pay "<<amount<<" Rs for two way";
            }
            else 
                cout<<"\n\t\t\t\t\tINVALID CHOICE!!!";
        }
        else{
            if(wayType==1){
                amount=350;
                cout<<"\n\t\t\t\tYou need to pay "<<amount<<" Rs for one way ";
            }
            else if(wayType==2){
                amount=500;
                cout<<"\n\t\t\t\tYou need to pay "<<amount<<" Rs for two way";
            }
            else 
                cout<<"\n\t\t\t\t\tINVALID CHOICE!!!";
        }
        return amount;
    }
    
    void showInfo(){
        cout<<"\n\t\t\t\t\t\tInformation==>>";
        cout<<"\n\t\t\t\tDate = "<<day<<"/"<<mon<<"/"<<year;
        if(tim==1) 
            cout<<"\n\t\t\t\tTime = "<<hr<<" : "<<min<<" a.m. ";
        else if(tim==2)
            cout<<"\n\t\t\t\tTime = "<<hr<<" : "<<min<<" p.m. ";
        cout<<"\n\t\t\t\tName = "<<name;
        cout<<"\n\t\t\t\tVehicle number = "<<vNo;
        cout<<"\n\t\t\t\tMobile number = "<<mNo;
        cout<<"\n\t\t\t\tAmount paid = "<<amount;
    }
    //function to count number of 4 wheelers passed
    void count4Wheel(){
      cout<<"\n\t\t\t\tTotal number of 4- wheelers passed = "<<car+truck+bus+other4;
      cout<<"\n\t\t\t\tNumber of cars passed = "<<car;
      cout<<"\n\t\t\t\tNumber of trucks passed = "<<truck;
      cout<<"\n\t\t\t\tNumber of Buses passed = "<<bus;
      cout<<"\n\t\t\t\tNumber of other vehicles passed = "<<other4;
    }
    //function to count number of 2 wheelers passed
    void count2Wheel(){
      cout<<"\n\n\t\t\t\tTotal number of 2- wheelers passed = "<<scooter+mcycle+bcycle+other2;
      cout<<"\n\t\t\t\tNumber of scooter passed = "<<scooter;
      cout<<"\n\t\t\t\tNumber of motorcycle passed = "<<mcycle;
      cout<<"\n\t\t\t\tNumber of bicycle passed = "<<bcycle;
      cout<<"\n\t\t\t\tNumber of other vehicles passed = "<<other2;
    }
};


long int info::password=012345;
int main(){
    int choice1,choice2,tAmt=0,amt,j=0,k;
    info i[50];
    long int pass;
    vehicle v[50];
    char ch1='y', ch2='y', proceed;
    cout<<"\n\t\t\t**************************************************************";
    cout<<"\n\t\t\t**********WELCOME TO TOLL BOOTH DELHI TO JAIPUR***************";
    cout<<"\n\t\t\t**************************************************************";
    do{
    cout<<"\n\t\t\t\t\t\t\t\tMENU:";
    cout<<"\n\t\t\t\t\t\t1. For filling an entry";
    cout<<"\n\t\t\t\t\t\t2. Admin login";
    cout<<"\n\t\t\t\t\t\t3. Exit";
    cout<<"\n\t\t\t\t\t\tEnter your choice : ";
    cin>>choice1;
    fflush(stdin);
    
    switch(choice1) {
        case 1:
                cout<<"\n\t\t\t\t\t<<=Enter the following informations=>>";
                v[j].inputDateTime();
                fflush(stdin);
                v[j].pinfo();
                fflush(stdin);
                v[j].inputVehicle();
                amt=v[j].payment();
                cout<<"\n\t\t\t\tDo you want to proceed for payment (y/n) : ";
                cin>>proceed;
                tAmt=tAmt+amt;
                if(proceed=='y'){
                    cout<<"\n\t\t\t\tYour transaction is successfully completed";
                    cout<<"\n\t\t\t\t\t...THANKS FOR USING PAYBOOTH. HAVE A SAFE JOURNEY...";
                }
                else
                    cout<<"\n\t\t\t\tPayment is cancelled";
                    fflush(stdin);
                break;
        case 2: 
                cout<<"\n\t\t\t\tEnter the admin password : ";
                cin>>pass;
                if(pass=i[j].password){
                    cout<<"\n\t\t\t\t\t----------Login Successfull--------";
                    fflush(stdin);
                    do{
                        cout<<"\n\n\t\t\t\t\t\t\t\tMENU: ";
                        cout<<"\n\t\t\t\t1. Check details of vehicles in last 1 week";
                        cout<<"\n\t\t\t\t2. Check total amount generated in each";;
                        cout<<"\n\t\t\t\t3. Logout";
                        cout<<"\n\t\t\t\tEnter you choice (1-3) : ";
                        cin>>choice2;
                        switch(choice2) {
                            case 1: 
                                    cout<<"\n\n\t\t\t\tDetails of vehicles from 15-11-2021 to 22-11-2021=>";
                                    for(int k=0;k<j;k++){
                                        if(v[k].day>19&&v[k].day<26&&v[k].mon==11&&v[k].year==2021){
                                            v[k].showInfo();
                                        }
                                    }
                                    if(k==0)
                                            cout<<"\n\t\t\t\tNo car between the dates";
                                    break;
                            case 2: 
                                    fflush(stdin);
                                    for(k=0;k<j;k++){
                                        if(k==j-1) {
                                            v[k].count2Wheel();
                                            v[k].count4Wheel();
                                        }
                                    }
                                    cout<<"\n\n\t\t\t\tTotal amount is = "<<tAmt;
                                    break;
                            case 3: ch2='n';
                                    cout<<"\n\t\t\t\tLoging out from admin menu.....";
                                    break;
                            default: cout<<"\n\t\t\t\t\tINVALID CHOICE!!!";
                        }
                        if(choice2!=3) {
                            cout<<"\n\t\t\t\tDo you want to continue in admin menu? (y/n) : ";
                            cin>>ch2;
                        }
                    }while(ch2=='y');
                }
                else {
                    cout<<"\n\t\t\t\t!!!WRONG PASSWORD!!!TRY AGAIN";
                }
                break;
        case 3: ch1='n';
                cout<<"\n\t\t\t\tExiting from program.....";
                break;
        default: cout<<"\n\t\t\t\t\tINVALID CHOICE!!!";
                
    }
    if(choice1!=3) {
        cout<<"\n\n\t\t\t\tDo you want to continue in menu (y/n) : ";
        cin>>ch1;
    }
    j++;
    }while(ch1=='y');
    
    return 0;
}

