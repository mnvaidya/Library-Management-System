//this program use arrarys as a database
// no code written for Renewing the book

#include <bits/stdc++.h>
using namespace std;

string mlist[11][4];
int booksperid[11][2];
char borbooks[11][3];
int blistt[10]={1,0,1,2,1,1,1,0,1,2};

class Lib{
    public:
    int id=0;
    int bookid=1;
    int duedate;
    

    public:
        void bookstat(){
            cout<<"Enter the book id: ";
            cin>>bookid;
            if(blistt[bookid]==1) cout<<"Available\n"<<endl;
            else if(blistt[bookid]==2) cout<<"Book is Reserved\n"<<endl;
            else if(blistt[bookid]==0) cout<<"Book is unavailable\n"<<endl;
            
            if(blistt[bookid]>2) cout<<"This book is not available in library\n"<<endl;
        }

        void showbooks(){
        cout<<"These are the available books (-R for Reserved)"<<endl;
        cout<<"Books:  ";
        for(int i=0; i<10; i++){
            if(blistt[i]==1) cout<<"  "<<char(65+i)<<"  ";
            else if(blistt[i]==2) cout<<" " << char(65+i)<<"-R ";
            else cout<<" --- ";
        }
        cout<<endl;
        cout<<"ID:     ";
        for(int i=0; i<10; i++){
            cout<<"  "<<i<<"  ";
        }
        cout<<"\n"<<endl;
    }
   
};

class Accounts : public Lib{

    public:

    void showstatus(){
        cout<<"\nEnter the id: ";
        cin>>id;
        cout<<endl;
        
        cout<<"Name:           "<<mlist[id-1][0]<<endl;
        cout<<"Address:        "<<mlist[id-1][1]<<endl;
        cout<<"Mail:           "<<mlist[id-1][2]<<endl;
        cout<<"Contact:        "<<mlist[id-1][3]<<endl;
        cout<<"Borrowed Books: "<<booksperid[id-1][0]<<"  ";
        cout<<borbooks[id-1][0]<<" "<<borbooks[id-1][1]<<" "<<borbooks[id-1][2]<<endl;
        cout<<"Reserved Books: "<<booksperid[id-1][1]<<endl;

   }

};

class Librarian : public Accounts{
    protected:

    string name;
    string address;
    string email;
    string contact;

    public:
    void addmember(){
        if(id==10) cout<<"No more accounts can be added. "<<endl;
        else {cout<<"\nFill in the details below\n"<<endl;
        cout<<"Enter your name(one_word): ";
        cin>>name;
        mlist[id][0]=name;
        cout<<"Enter your city: ";
        cin>>address;
        mlist[id][1]=address;
        cout<<"Enter your mail address: ";
        cin>>email;
        mlist[id][2]=email; 
        cout<<"Enter your contact number: ";
        cin>>contact;
        mlist[id][3]=contact; 

        cout<<"\nNew account has been created successfully."<<endl;
        cout<<"Account ID is: "<<id+1<<endl;

        id++;}

    }

    void delmember(){
        cout<<"Enter id to be deleted: ";
        cin>>id;
        if(mlist[id-1][0]=="") cout<<"No Account detected for this id.";
        else{for(int i=id-1; i<=id-1; i++){
            for(int j=0; j<4; j++)
                mlist[i][j]="";
                    }
                borbooks[id-1][0]=0;
                borbooks[id-1][1]=0;
        cout<<"Member with id "<<id<<" is deleted."<<endl;
    }}

};

class Member: public Accounts{
    
    protected:
    int idd;

    public:
    Member(int idd){
        this->idd=idd;
    }
    void checkout(int idd){
            cout<<"Enter the book id to checkout: ";
            cin>>bookid;
      
            if(booksperid[idd-1][0]<3 and blistt[bookid]==1){

                    blistt[bookid]=0;
                    int cur=booksperid[idd-1][0]++;
                    
                    borbooks[idd-1][--cur]=(char)65+bookid;
                    cout<<"\nSuccessful! You borrowed this book. Enjoy reading..."<<endl;
                    cout<<"Duedate : 30th Sept" <<endl;
                    cout<<"If you miss the due or lose the book, you'll have to pay fine.\n"<<endl;}

            else if(booksperid[idd-1][0]>2 ) cout<<"Sorry, you can't borrow more than 3 books."<<endl;
            else if(blistt[bookid]==2) cout<<"This book is reserved by someone else."<<endl;
            else cout<<"Book is not available."<<endl; 
        }

    void returnbook(int idd){
        cout<<"Enter the book id you want to return: ";
        cin>>bookid;
        blistt[bookid]=1;
        booksperid[idd-1][0]--;
        cout<<"Check out the other available books"<<endl;
    }

    void reserve(int idd){
        cout<<"Enter the book id you want to reserve: ";
        cin>>bookid;

        if(blistt[bookid]==1) {
            cout<<"Book is already available, want to borrow? (y/n): ";
            char yesno;
            cin>>yesno;
            if(yesno=='y') checkout(idd);
            else cout<<"Check out other books."<<endl;
        }
        else if(blistt[bookid]==2) cout<<"Book is already been reserved by someone else."<<endl;
        else {
            booksperid[idd-1][1]++;
            cout<<"Book has been reserved for your id.\n You'll be notified once it is available."<<endl;
        }
    }

};

char libstart(){
    Librarian acc;
    char yesno;
    Another:
    cout<<"\nEnter a number: ";
    int b; cin>>b;
    if(b==1) acc.addmember();
    else if(b==2) acc.delmember();
    else if(b==3) acc.showstatus();
    else if(b==27) {
        cout<<"Session ended for Librarian"<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<"\nAnother session?(y/n): ";
        cin>>yesno;
        return yesno;}
    else {
        cout<<"You can only modify the database of members."<<endl;}

    goto Another;   
}

int main(){

    cout<<"\t\tWelcome to The World Library\n"<<endl;
       
    LIB:
    cout<<"Librarian or user? (l/u): ";
    char person; cin>>person;
    if(person=='l') {
        cout<<"\nSession for Librarian\n"<<endl;
        cout<<" 1 ---> Add new Account      2 ---> Cancel Membership     3 ---> Show status of member"<<endl;
        char ans=libstart();
        if(ans=='y') goto LIB;
        else {//cout<<"\nSession ended for Librarian"<<endl;
              cout<<"---------------------------------------------"<<endl;
            return 0;}}   
        

    Start:
    cout<<"\nMember ID: ";
    int memid; cin>>memid;
    if(mlist[memid-1][0]==""){
        cout<<"\nNo account exist for this ID."<<endl;
        goto LIB;
    }

    cout<<"\nSession started for ID-"<<memid<<"\n"<<endl;
    cout<<" 3 ---> Show member account  4 ---> Check-out Book      5 ---> Renew Book"<<endl;
    cout<<" 6 ---> Return Book          7 ---> Reserve Book        8 ---> Show available Books"<<endl;
    cout<<" 9 ---> Show Book Status "<<endl;
    
    Startmid:
    Member obj(memid);

    cout<<"\nEnter a number: ";
    int a; cin>>a;
    cout<<endl;
    if(a==1 or a==2) cout<<"You don't have access to accounts"<<endl;
    if(a==3) obj.showstatus();
    else if(a==4) obj.checkout(memid);
    else if(a==6) obj.returnbook(memid);
    else if(a==7) obj.reserve(memid);
    else if(a==8) obj.showbooks();
    else if(a==9) obj.bookstat();
    else if(a==27) {
        cout<<"Session ended for ID-"<<memid<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"\nAnother session?(y/n): ";
        char yesno; cin>>yesno;
        if(yesno=='y')goto LIB;
        else {
            cout<<"\nThank You for visiting our library...\n"<<endl;
            return 0;}
        }
    goto Startmid;

    return 0;
    
}