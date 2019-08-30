#include <iostream>
#include <vector>
using namespace std;

void longfactorial(int number){
    vector <int> res;
    res.push_back(1);

    for(int i = 1; i <= number; i++){
        vector <int> temp;
        for(int j = 0; j < res.size();j++){
            temp.push_back(i*res[j]);
        }

        for(int j = 0; j <  temp.size(); j++){
            int carry = temp[j]/10;
            temp[j] = temp[j]%10;
            if(j+1 < temp.size() && carry > 0){
                temp[j+1] = temp[j+1] + carry;
            }
            else if (j+1 >= temp.size() && carry > 0){
                    temp.push_back(carry);
                }
            }
        res.clear();
        res = temp;
    }
    cout<<number<<"! = ";
    for(int i = res.size()-1 ; i >= 0; i--){
        cout<<res[i];
    }
    if(res.size() > 10){
        cout<<endl<<endl<<"Scientific Notation : ";
        cout<<res[res.size()-1]<<"."<<res[res.size()-2]<<res[res.size()-3]<<res[res.size()-4]<<res[res.size()-5]<<res[res.size()-6]<<"e+"<<res.size()-1;
        cout<<endl<<endl;
    }
}

int main(){
    int n = 1;
    cout<<"\t\tFactorial of a Number\n\n";
    cout<<"Enter a num : ";
    cin>>n;
    longfactorial(n);
}
