#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
fstream myfile;
string s[100];
struct books {
    
    string name, authur, price;
    books *link;
    books() {
        link = NULL;
    }
};
class records {
    
    books *start, *cur, *temp;

    public:
    records() {
        start = NULL;
    }
    void create_file(string n, string a, string p) {
        
        if (start == NULL) {

            start = new books;
            start->link = NULL;
            start->name = n;
            start->authur = a;
            start->price = p;
            myfile.open("books library.txt", ios::out | ios::app);
            myfile << "Name_:_" << start->name << "__|__Authur:_" << start->authur << "__|__Price_:_" << start->price << endl;
            myfile.close();
        }
        else {

            cur = start;
            while (cur->link != NULL) {
                cur = cur->link;
            }
            temp = new books;
            temp->name = n;
            temp->authur = a;
            temp->price = p;
            temp->link = NULL;
            cur->link = temp;
            myfile.open("books library.txt", ios::out | ios::app);
            myfile << "Name_:_" << temp->name << "__|__Authur:_" << temp->authur << "__|__Price_:_" << temp->price << endl;
            myfile.close();
        }
    }
    void search(string n) {

        int i, k = 0;
        string ss;
        myfile.open("books library.txt", ios::in);
        while (!myfile.eof()) {

            myfile >> s[k];
            k++;
        }
        k--;
        myfile.close();
        for (i = 0; i < k; i++) {

            if (s[i].find(n) > 0 && s[i].find(n) < s[i].length()) {
                break;
            }
        }
        if (i != k) {
            cout << "\n\t\t\tBook is Available" << endl;
            cout << "\t\t\t" << s[i] << endl;
        }
        else {
            cout << "\n\t\t\tBook Not found " << endl;
        }
    }
    void print() {
        
        myfile.open("books library.txt", ios::in);
        int i = 0;
        while (!(myfile.eof())) {

            myfile >> s[i];
            cout << "\t\t\t" << s[i] << endl;
            i++;
        }
        myfile.close();
    }
};

inline void welcome() {

    system("cls");
    cout<<"\n\n\n\t\t\t\t\tWelcome to Book Store\n";
    cout<<"\t\t\t\t\t----------------------\n";
}

struct user_details {

    string name, emailID, pswrd;
    long long mobile_no;
};

class login{

    public:
    void Customer_portal() {
        user_details obj;
        welcome();
        cout << "\n\t\t\t\t\t1. login";
        cout << "\n\t\t\t\t\t2. SignUp";
        cout << "\n\n\t\t\t\t\tEnter your option: ";
        int opt;
        cin>>opt;

        if(opt==1) {

            welcome();
            string id;
            bool m=false;
            cout << "\n\t\t\t\t\tID :";
            cin >> id;
            fflush(stdin);
            cout << "\n\t\t\t\t\tPassword :";
            char pwd[100] = { 0 };
            int i;
            for (i = 0;;i++) {

                pwd[i] = _getch(); 
                if(pwd[i]==8) {
                    cout << "\b \b";
                    i=i-2;
                    continue;
                }
                cout << "*";
                if (pwd[i] == 13) {
                    pwd[i]='\0';
                    break;
                }
            }
            fflush(stdin);
            ofstream fout;
            fout.open("./User_Data/" + id + ".txt",ios::app);
            ifstream fin("./User_Data/" + id + ".txt",ios::in);
            while(!fin.eof()) {

                getline(fin,obj.name);
                fin>>obj.emailID>>obj.mobile_no>>obj.pswrd;
                if(id==obj.emailID && pwd==obj.pswrd) {
                    m=true;
                    book_details();
                    break;
                }
            }
            if(m==false) {
                cout<<"\n\t\t\t\t\tYou are not a Registered user or you entered wrong id,pswrd! First Sign-up or enter correct details please !" << endl;
                cout << "\t\t\t\t\tPress any key to continue";
                getch();
                Customer_portal();
            }
            fin.close();
        }
        else if(opt==2){

            welcome();
            cout << "\n\t\t\t\t\tName :";
            fflush(stdin);
            getline(cin,obj.name);
            cout << "\n\t\t\t\t\tEmail id :"; 
            cin>>obj.emailID;
            cout << "\n\t\t\t\t\tMobile no. :"; 
            cin >> obj.mobile_no;
            cout << "\n\t\t\t\t\tPassword :"; 
            cin >> obj.pswrd;
            ofstream fout;
            fout.open("./User_Data/" + obj.emailID + ".txt");
            fout << obj.name << endl << obj.emailID << endl << obj.mobile_no << endl << obj.pswrd;
            fout.close();
            cout << "\n\t\t\t\t\tSigned-Up Successfully!" << endl;
            cout << "\t\t\t\t\tPress any key to continue";
            getch();
            Customer_portal();
        }
        else {
            cout << "\n\t\t\t\t\tYou Entered wrong Choice! Please select the correct one!(Press any key)";
            getch();
            Customer_portal();
        }
    }
    void book_details() {
        records l1;
        int nooffiles, i, p, ch, k, j;
        string n, an, prc;

        do {

            welcome();
            cout << "\n\t\t\t\t\t1-Purchase a Book" << endl;
            cout << "\t\t\t\t\t2-Donate a Book" << endl;
            cout << "\t\t\t\t\t3-Search any Book" << endl;
            cout << "\t\t\t\t\t4-See All Available Books" << endl;
            cout << "\t\t\t\t\t5-Read online books " << endl;
            cout << "\t\t\t\t\t6-Log Out\n" << endl;
            cout<<"\n\t\t\t\t\tEnter your choice: ";
            cin >> ch;
            system("CLS");
            switch (ch) {

                case 1:
                    welcome();
                    cout << "\n\t\t============================Purchase Book===============================\n\n";

                    myfile.open("books library.txt", ios::in);
                    k = 0;
                    int del;
                    while (myfile.good())
                    {
                        myfile >> s[k];
                        cout << "\t\t\t" << k + 1 << " :- " << s[k] << endl;
                        k++;
                    }
                    myfile.close();
                    cout << "\033[F\t\t\t0 :- Go back" << endl;
                    cout << "\t\t\tWhich Book data you want to purchase ..? ";
                    cin >> del;
                    if(del==0) 
                        book_details();
                    s[del - 1] = "";
                    
                    cout << "\n\t\t\tBook has been purchased.Be ready to make cash payment to our delivery partner..\n\t\t\tThank you for shopping!" << endl;
                
                    myfile.open("books library.txt", ios::out);
                    for (j = 0; j < k; j++)
                        myfile << s[j] << endl;
                    myfile << endl;
                    myfile.close();
                    cout << "\t\t\tPress any key to continue";
                    getch();
                    break;
                case 2:
                    welcome();
                    cout << "\n\t\t============================Donate a Book===============================\n\n";
                    cout << "\t\t\tEnter Book Data to Donate in our store" << endl;

                    cout << "\n\t\t\tEnter Book Name \t";
                    cin >> n;
                    cout << "\n\t\t\tEnter Authur name \t";
                    cin >> an;
                    cout << "\t\t\tEnter Price(Sailing) \tRs.";
                    cin >> prc;
                    l1.create_file(n, an, prc);
                    cout << "\n\t\t\tBook " << n << " has been Saved in our Book Store " << endl;
                    cout << "\t\t\tPress any key to continue";
                    getch();
                    break;
                case 3:
                    welcome();
                    cout << "\n\t\t==========================SEARCH BOOK data==============================\n\n";
                    cout << "\t\t\tEnter NAME of Book to search it from Library\t";
                    cin >> n;
                    l1.search(n);
                    cout << "\t\t\tPress any key to continue";
                    getch();
                    break;
                case 4:
                    welcome();
                    cout << "\n\t\t=========================PRINTING ALL BOOKS=============================\n\n";
                    l1.print();
                    cout << "\t\t\tPress any key to continue";
                    getch();
                    break;
                case 5:
                    welcome();
                    cout << "\n\t\t=========================SEARCH BOOK ONLINE=============================\n\n";
                    system("cmd/c start https://books.google.com/");
                    cout << "\t\t\tPress any key to continue";
                    getch();
                    break;
                case 6:
                    welcome();
                    cout << "\n\t\t\tLogging Out" << endl;
                    cout << "\n\t\t\tTHANK YOU!" << endl;
                    cout << "\t\t\tPress any key to continue";
                    getch();
                    Customer_portal();
                    break;
                default:
                    cout << "\t\t----------Invalid----------" << endl;
            }
        } while (ch > 0 && ch < 6);
        cout << "\t\t\tPress any key to continue";
        getch();
    }
    void Donation_portal() {

        welcome();
        string n,an,prc="";
        cout << "\n\t\t\t\tWant To Donate Anonymously? Now you can!" << endl;
        cout << "\t\t\t\tEnter Book Data to Donate in our store" << endl;
        cout << "\n\t\t\t\t\tEnter Book Name \t";
        //getline(cin,n);
        cin >> n;
        cout << "\t\t\t\t\tEnter Authur name \t";
        cin >> an;
        records l1;
        l1.create_file(n, an, prc);
        cout << "\n\t\t\t\t\tBook " << n << " has been Saved in our Book Store " << endl;
        cout << "\t\t\t\t\tPress any key to continue";
        getch();
        Customer_portal();
    }
};

int main() {
    
    system("color 8f");
    welcome();
    cout << "\n\t\t\t\t\t1. Customer Portal\n";
    cout << "\t\t\t\t\t2. Donation Portal\n";
    cout << "\n\t\t\t\t\tEnter your choice: ";
    int ch;
    cin >> ch;
    switch(ch) {

        case 1: login l1;
                l1.Customer_portal();
                break;
        case 2: login ano;
                ano.Donation_portal();
                break;
        default :cout<<"\n\t\t\t\t\tYou Entered wrong Choice! Please select the correct one!";
                getch();
                main();
    }
    return 0;
}