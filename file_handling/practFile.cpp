#include<iostream>
#include<fstream>
using namespace std;

struct tool{
        int record;
        char name[150];
        double price;
        int quantitiy;
    };

fstream file("hardware.dat", ios::binary | ios::in | ios::out);
int main(){
    // we have to be making a binary file and then making 100 empty records
    
    tool emptyStruct= {0,"", 0,0};
    for(int i=0; i<100 ;i++){
        file.write(reinterpret_cast<char *> (&emptyStruct), sizeof(tool));
        // now the file is having empty records
    }
    cout<<"..The file hardware.dat is having 100 empty records.."<< endl;

    option();
    return 0;
}

void option(){


    int num;
    cout<<"Select a option: "<<endl;
    while(true){
        int choice;
        cout<<"1.Add data\n2.Update\n3.Delete\n0.Exit"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 0:
            return;
            break;
        
        case 1:
            tool rec;
            add(rec);
            break;

        case 2:
            update();
            break;

        case 3:
            del();
            break;

        }


    }

}

void add(tool rec){
    cout<<"----Add a record: ---";
    cout<<"Write the record num of the tool: "<<endl;
    cin>>rec.record;
    cout<<"Write the name of the tool: "<<endl;
    cin.ignore();
    cin.getline(rec.name, 100);
    cout<<"Write the price of the tool: "<<endl;
    cin>>rec.price;

    cout<<"Write the quantity of the tool: "<<endl;
    cin>>rec.quantitiy;

    file.seekp((rec.record-1)*sizeof(tool));
    file.write(reinterpret_cast<char*>(&rec),sizeof(tool));
    file.seekp(0);
}

void update(){

    int num;
    cout<<"Enter the record number that you want to update: "<<endl;
    cin>>num;
    file.seekp((num-1) *sizeof(tool));
    tool rec;
    add(rec);
    file.write(reinterpret_cast<char*>(&rec),sizeof(tool));

}

void del(){



    
}