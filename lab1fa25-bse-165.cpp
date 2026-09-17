// i have to create a program where Write down a program that find ∑X2
//  , where input for X and starting and stopping value is entered by 
// the user

#include <iostream>
using namespace std;

int main(){
    int start;
    int stop;

    cout<<"Enter the start value: "<<endl;
    cin>> start;

    cout<<"Enter the stop value: "<<endl;
    cin>>stop;

    int num = start;

    int sum = 0;

    for(int i = 0; i<stop; i++){
        sum += num*num;
        num++;
    }

    cout<<"The summation is: "<<sum<<endl;


    return 0;
}