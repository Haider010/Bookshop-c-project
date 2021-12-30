#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class bookshop{
    int id;
    char book_name[20];
    char Arthur_name[20];
    int no_copies;
    public:
    void get_data();
    void showdata();
    void writ_recrd();
    void read_data();
    void srch_book();
    void del_book();
    void updat_details();

};
void bookshop::get_data(){
cout<<"Enter Book id : ";cin>>id;
cout<<"Enter book name : ";cin>>book_name;
cout<<"Enter arthur name : ";cin>>Arthur_name;
cout<<"Enter no of copies : ";cin>>no_copies;
}
void bookshop::showdata(){
    cout<<"Book id : "<<id<<endl;
    cout<<"Book name : "<<book_name<<endl;
    cout<<"Arthur name : "<<Arthur_name<<endl;
    cout<<"No of copies : "<<no_copies<<endl;
    cout<<endl;
}
void bookshop::writ_recrd(){
    ofstream book;
    int a;
    cout<<"How much books you want to add : ";cin>>a;
    book.open("shop.txt",ios::app|ios::binary);
    for(int i =0;i<a;i++){
    get_data();
    book.write((char*)(this),sizeof(*this));
    }
book.close();
}
void bookshop::read_data(){
   
    int n=0;
    ifstream book;
    book.open("shop.txt",ios::in|ios::binary);
    if(!book){
        cout<<"*****ERROR****"<<endl;
        cout<<endl;
        cout<<"File not found"<<endl;
        return;
    }
    cout<<"\n***************SHOWING ALL BOOKS***************\n\n"<<endl;
    
    book.read((char*)(this),sizeof(*this));
    while(!book.eof()){
    showdata();
    book.read((char*)(this),sizeof(*this));
    n++;
    }
    if(n==0){
        cout<<"*****BOOK IS NOT AVAILABLE*****"<<endl;
    }
}
void bookshop::srch_book(){
    int n,num=0;
    ifstream book;
    cout<<"Enter Bok id : ";cin>>n;
    cout<<endl;
    book.open("shop.txt",ios::in|ios::binary);
    book.read((char*)(this),sizeof(*this));
    while (!book.eof())
    {
        if(n==id){
            showdata();
            break;
        }
        book.read((char*)(this),sizeof(*this));
        num++;
    }   
    if(num==0){
        cout<<"*****BOOK IS NOT AVAILABLE*****"<<endl;
    }
}
void bookshop::del_book(){
    int n,count=0;
    ifstream book;ofstream book1;
    book.open("shop.txt",ios::in|ios::binary);
       if(!book){
        cout<<"*****ERROR****"<<endl;
        cout<<endl;
        cout<<"File not found"<<endl;
        return;
    }
    book1.open("shop1.txt",ios::out|ios::binary);
    cout<<"Enter book id to delete : ";cin>>n;
    book.read((char*)(this),sizeof(*this));
    while(!book.eof()){
     if(n!=id)
     book1.write((char*)this,sizeof(*this));
     book.read((char*)(this),sizeof(*this));
     count++;
    }
        if (count==0){
        cout<<"*****BOOK IS NOT AVAILABLE*****"<<endl;
    }
    book.close();
    book1.close();
    remove("shop.txt");
    rename("shop1.txt","shop.txt");
}
void bookshop::updat_details(){
      int n,count=0;
      fstream book;
      book.open("shop.txt",ios::in|ios::out|ios::binary|ios::ate);
   if(!book){
        cout<<"*****ERROR****"<<endl;
        cout<<endl;
        cout<<"File not found"<<endl;
        return;
    }
    book.seekg(0);
    cout<<"Enter book id to modify details : ";cin>>n;
      book.read((char*)this,sizeof(*this));

     while (!book.eof())
     {
         if (n==id)
         {
            get_data();
            int a=book.tellp();
            book.seekp((a)-(sizeof(*this)));
            book.write((char*)this,sizeof(*this));
         }
          book.read((char*)this,sizeof(*this));
          count++;
     }
     if(count==0){
        cout<<"*****BOOK IS NOT AVAILABLE*****"<<endl;
     }
    }
int main(){
    bookshop b;
    int choice;
    cout<<"*****BOOKSHOP MANAGEMENT*****\n"<<endl;
    cout<<"1=> Add book to record"<<endl;
    cout<<"2=> Show all books"<<endl;
    cout<<"3=> Search book from record"<<endl;
    cout<<"4=> Modify book details"<<endl;
    cout<<"5=> Delete book record"<<endl;
    cout<<"6=> Exit"<<endl;
    cout<<"Enter your choice : ";cin>>choice;
    switch(choice){
        case 1:
        b.writ_recrd();
        break;
        case 2:
        b.read_data();
        break;
        case 3:
        b.srch_book();
        break;
        case 4:
        b.updat_details();
        break;
        case 5:
        b.del_book();
        break;
        case 6:
        exit(0);
        default:
        cout<<"Invalid Choice"<<endl;
    }
    
     return 0;
}