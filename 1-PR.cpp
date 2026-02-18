#include<iostream>
using namespace std;

class time
{
    public:
    int h=-1,m=-1,s=-1,temp=0,hh,mm,ss;
    void sec()
    {
        cout<<"Enter Seconds -> ";
        cin>>s;
        ss=s;
    }

    void sectohms(){
        if(s>=0){
            h=s/3600;
            m=s%3600;
            m=m/60;
            s=s%60;
            cout << "\nTime of "<<ss<<" is "<<h<<":"<<m<<":"<<s<<"\n\n";
        }
        else
            cout<<"Enter Positive number only \n\n";
    }

    void hms(){   
        do
        {
            cout<<"Enter Hour -> ";
            cin>>h;
     
            cout<<"Enter Minutes -> ";
            cin>>m;
     
            cout<<"Enter Seconds -> ";
            cin>>s;

            if(h<0||m<0||m>=60||s<0||s>=60){
                 cout<<"Invalid input\nEnter your input again \n";
            }
            cout<<endl;
        }
        while(m<0||m>=60||s<0||s>=60||h<0);
    }

    void hmstosec(){
        if(h>=0 && m>=0 && s>=0){
            mm=m*60;
            hh=h*60;
            hh=hh*60;
            temp=mm+hh+s;
            cout<<"\nTotal Seconds of "<<h<<":"<<m<<":"<<s<<" is -> "<<temp<<endl<<endl;

        }
        else
            cout<<"Enter Positive number only\n\n";

    }

};
int main(){
    int c=-1;
    time o;

    while(c!=0){
        cout<<"1 -> seconds to HH:MM:SS\n2 -> HH:MM:SS to seconds\n0 -> Exit \n\nEnter your choice => ";
        cin>>c;

        if(c==0){
            break;
        }
        else if(c==1){
            o.sec();
            o.sectohms();
        }
        else if(c==2){
            o.hms();
            o.hmstosec();
        }
        else{
            cout<<"Wrong Choice \n";
        }
    }       
}
/*
Output:-

1 -> seconds to HH:MM:SS
2 -> HH:MM:SS to seconds
0 -> Exit

Enter your choice => 1
Enter Seconds -> 3661

Time of 3661 is 1:1:1

1 -> seconds to HH:MM:SS
2 -> HH:MM:SS to seconds
0 -> Exit 

Enter your choice => 2
Enter Hour -> 1
Enter Minutes -> 1
Enter Seconds -> 1

Total Seconds of 1:1:1 is -> 3661

1 -> seconds to HH:MM:SS
2 -> HH:MM:SS to seconds
0 -> Exit 

Enter your choice => 0
*/