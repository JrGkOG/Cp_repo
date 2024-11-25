#include<iostream>
using namespace std;
bool checkDis(string name,int i){
  for(int j=i+1;j<name.length();j++){
    if(name[j]==name[i]){
      return false;
    }
  }
  return true;
}
int main(){
  string name;
  cin>>name;
  int dis=0;
  for(int i=0;i<name.length();i++){
    if(checkDis(name,i)==true){
      dis++;
    }
  }
  if(dis%2==0){
    cout<<"CHAT WITH HER!"<<endl;
  }
  else{
    cout<<"IGNORE HIM!"<<endl;
  }
  return 0;
}