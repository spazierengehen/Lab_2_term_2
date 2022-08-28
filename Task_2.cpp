#include<fstream>
#include<iostream>
using namespace std;
class player {
    string name;
    int xp;
    int damage;

public:
    player() {};
    ~player() {};

    player(string x, int y, int z) {
        name=x;
        xp=y;
        damage=z;
    }

    string get_name()const{return name;}
    int get_xp()const{return xp;}
    int get_damage()const{return damage;}

    void set_name(string x){name=x;}
    void set_xp(int x){
        try
        {
        if (x<0){throw logic_error("\nFail! You can't set a negative parameter.");}
        xp=x;
        }
        catch(const exception &m){
            cout<<m.what()<<endl;
        }
    }
    void set_damage(int x)
    {
        try
        {
            if(x<0){throw logic_error("\nFail! You can't set a negative parameter.");}
            damage=x;
        }
        catch(const exception &m)
        {
            cout<<m.what()<<endl;
        }
    }

    virtual void info(){cout<<"\nName:"<<name<<"\nXP:"<<xp<<"\nDamage:"<<damage<<endl;}

    void damage_to_destroy ( const player &other){
        int i=0, k=other.get_xp();
        while(k>0){
         k=k-damage;
         i++;
        }
        cout<<"\n"<<get_name()<<" needs "<<i<<" shoots to destroy "<<other.get_name()<<"."<<endl;
    }

    virtual void sent_to_file()
        {
        string path;
    cout<<"\nEnter path to file: ";
    cin>>path;
    ifstream n;
    n.exceptions(ifstream::badbit|ifstream::failbit);
    try
    {
        n.open(path);
    }
    catch(const exception &n)
    {
        cout<<"Fail!\t"<<"Not found: "<<path<<"\n"<<n.what();
    }
    n.close();
    ofstream m;
    m.open(path,ofstream::app);
    m<<"Name: "<<get_name()<<"\n"<<"XP: "<<get_xp()<<"\n"<<"Damage: "<<get_damage()<<endl<<endl;
    m.close();}
};


class archer:public player{
    int distance;
    int accuracy;
public:

    archer(){};
    ~archer(){};

    archer(string name,int xp,int damage,int distance,int accuracy):player(name,xp,damage){
        this->distance=distance;
        this->accuracy=accuracy;
    }

    int get_distance()const{return distance;}
    int get_accuracy()const{return accuracy;}

    void set_distance(int x){
        try {
            if(x<0){throw logic_error("Fail! you can't set a negative parameter.");}
            distance=x;
        }
        catch (const exception &m) {
            cout<<m.what()<<endl;
        }
       }

    void set_accuracy(int x){
        try {
            if(x<0){throw logic_error("Fail! you can't set a negative parametr.");
                accuracy=x;}
        }
        catch (const exception &m) {
            cout<<m.what()<<endl;
        }
        }

    void info()override{
    player::info();
    cout<<"Distance:"<<distance<<"\nAccuracy:"<<accuracy;
    }

    void sent_to_file()override{
        string path;
        cout<<"\nEnter path to file: ";
        cin>>path;
        ifstream n;
        n.exceptions(ifstream::badbit|ifstream::failbit);
        try
        {
            n.open(path);
        }
        catch(const exception &n)
        {
            cout<<"Fail!\t"<<"Not found: "<<path<<"\n"<<n.what();
        }
        n.close();
        ofstream m;
        m.open(path,ofstream::app);
        m<<"Name: "<<get_name()<<"\n"<<"XP: "<<get_xp()<<"\n"<<"Damage: "<<get_damage()<<"\nDistance: "<<get_distance()<<"\nAccuracy: "<<get_accuracy()<<endl<<endl;
    m.close();
    }
};




int main(){
player a("Anthony",10,15);
archer b("Peter",100,10,15,5);
player c("Leonid",100,15);
b.set_distance(-23423);
a.sent_to_file();
b.sent_to_file();
return 0;
    };


