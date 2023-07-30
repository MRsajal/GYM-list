#include<iostream>
#include<conio.h>
using namespace std;
struct member{
    string name;
    int id;
    float height;
    float weight;
    bool exist;
};
struct member m[10000];
int total=-1;
int manu(){
    int op;
    system("cls");
    cout<<"********** Main Manu **********\n";
    cout<<"1. Add Member\n";
    cout<<"2. Update Member\n";
    cout<<"3. Remove Member\n";
    cout<<"4. Max height and weight\n";
    cout<<"5. Min height and weight\n";
    cout<<"6. Avg. height and weight\n";
    cout<<"7. BMI classification\n";
    cout<<"8. Display\n";
    cout<<"9. Sort According to height\n";
    cout<<"10. Sort According to weight\n";
    cout<<"11. Unremove  member\n";
    cout<<"0. Exit\n";
    cout<<"Enter your choice(1-8): ";
    cin>>op;
    return op;
}
int searchmember(int x){
    int flag =-1;
    for(int i=0;i<=total;i++){
        if(m[i].id==x){
            flag=i;
        }
    }
    return flag;
    getch();
}
void addmember(){
    int d=0;
    cout<<"You are inside addmember()"<<endl;
    total++;
    cout<<"Enter name: ";
    cin>>m[total].name;
    cout<<"Enter ID: ";
    cin>>m[total].id;
    for(int i=0;i<total;i++){
        if(m[total].id==m[i].id){
            d++;
        }
    }
    if(d==0){
        cout<<"Enter height: ";
        cin>>m[total].height;
        cout<<"Enter weight: ";
        cin>>m[total].weight;
        m[total].exist=true;
    }
    else{
        cout<<"This ID already exist!!\n";
    }
    getch();
}
void updatedmember(){
    cout<<"Welcome to update section\n";
    int n,idx;
    float nh,nw;
    cout<<"Enter ID no: ";
    cin>>n;
    cout<<"Enter new height: ";
    cin>>nh;
    cout<<"Enter new weight: ";
    cin>>nw;
    idx=searchmember(n);
    if(idx==-1){
        cout<<"ID not found!!!\n";
    }
    else{
        m[idx].height=nh;
        m[idx].weight=nw;
    }
    getch();
}
void removemember(){
    cout<<"Enter ID: ";
    int nid,idx;
    cin>>nid;
    idx=searchmember(nid);
    if(idx==-1){
        cout<<"ID not found!!!\n";
    }
    else{
        cout<<"Member to be removed"<<endl;
        cout<<m[idx].id<<' '<<m[idx].height<<' '<<m[idx].weight<<endl;
        m[idx].exist=false;
    }
    getch();
}
void maximum(){
    float maxh=m[0].height,maxw=m[0].weight;
    for(int i=0;i<=total;i++){
        if(m[i].height>maxh){
            maxh=m[i].height;
        }
        if(m[i].weight>maxw){
            maxw=m[i].weight;
        }
    }
    cout<<"Maximum height is: "<<maxh<<endl;
    cout<<"Maximum weight is: "<<maxw<<endl;
    getch();
}
void minimum(){
    float minh=m[0].height,minw=m[0].weight;
    for(int i=0;i<=total;i++){
        if(m[i].height<minh){
            minh=m[i].height;
        }
        if(m[i].weight<minw){
            minw=m[i].weight;
        }
    }
    cout<<"Minimum height is: "<<minh<<endl;
    cout<<"Minimum weight is: "<<minw<<endl;
    getch();
}
void average(){
    float sh=0,sw=0;
    for(int i=0;i<=total;i++){
        sh=sh+m[i].height;
        sw=sw+m[i].weight;
    }
    cout<<"Average height is: "<<sh/total<<endl;
    cout<<"Average weight is: "<<sw/total<<endl;
    getch();
}
void BMIclassification(){
    float bmi;
    int id;
    cout<<"Enter ID no: ";
    cin>>id;
    int x=searchmember(id);
    if(x==-1){
        cout<<"Sorry id not found!!\n";
    }
    else{
        bmi=m[x].weight/(m[x].height*m[x].height);
        if(bmi<16){
            cout<<"Severe Thinness\n";
        }
        else if(bmi>=16 && bmi<17){
            cout<<"Moderate Thinness\n";
        }
        else if(bmi>=17 && bmi<18.5){
            cout<<"Mid Thinness\n";
        }
        else if(bmi>=18.5 && bmi<25){
            cout<<"Normal\n";
        }
        else if(bmi>=25 && bmi<30){
            cout<<"Overweight\n";
        }
        else if(bmi>=30 && bmi<35){
            cout<<"Obese Class 1\n";
        }
        else if(bmi>=35 && bmi<40){
            cout<<"Obese Class 2\n";
        }
        else{
            cout<<"Obese Class 3\n";
        }
    }
    getch();
}
void sortheight(){
    int tempid;
    float temph,tempw;
    for(int i=0;i<=total-1;i++){
        if(m[i+1].height>m[i].height){
            tempid=m[i].id;
            m[i].id=m[i+1].id;
            m[i+1].id=tempid;
            temph=m[i].height;
            m[i].height=m[i+1].height;
            m[i+1].height=temph;
            tempw=m[i].weight;
            m[i].weight=m[i+1].weight;
            m[i+1].weight=tempw;
        }
    }
    getch();
}
void sortweight(){
    int tempid;
    float temph,tempw;
    for(int i=0;i<=total-1;i++){
        if(m[i+1].weight>m[i].weight){
            tempid=m[i].id;
            m[i].id=m[i+1].id;
            m[i+1].id=tempid;
            temph=m[i].height;
            m[i].height=m[i+1].height;
            m[i+1].height=temph;
            tempw=m[i].weight;
            m[i].weight=m[i+1].weight;
            m[i+1].weight=tempw;
        }
    }
    getch();
}
void unremove(){
    cout<<"Enter ID: ";
    int nid,idx;
    cin>>nid;
    idx=searchmember(nid);
    if(idx==-1){
        cout<<"ID not found!!!\n";
    }
    else{
        cout<<"Member to be unremoved"<<endl;
        cout<<m[idx].id<<' '<<m[idx].height<<' '<<m[idx].weight<<endl;
        m[idx].exist=true;
    }
    getch();
}
void displayall(){
    cout<<"NAME-ID-height-weight"<<endl;
    int i;
    for(i=0;i<=total;i++){
        if(m[i].exist==true){
            cout<<m[i].name<<'-'<<m[i].id<<'-'<<m[i].height<<'-'<<m[i].weight<<endl;
        }
    }
    getch();
}
int main(){
    int option;
    for(;;){
        option=manu();
        cout<<"in manu() option = "<<option<<endl;
        if(option == 0){
            cout<<"Thank You\n";
            break;
        }
        switch(option){
            case 1:addmember();break;
            case 2:updatedmember();break;
            case 3:removemember();break;
            case 4:maximum();break;
            case 5:minimum();break;
            case 6:average();break;
            case 7:BMIclassification();break;
            case 8:displayall();break;
            case 9:sortheight();break;
            case 10:sortweight();break;
            case 11:unremove();break;
        }
    }
    getch();
}