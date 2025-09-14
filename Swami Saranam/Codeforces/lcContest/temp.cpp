// #include <bits/stdc++.h>
// using namespace std;
// int maxFreqSum(string s) {
//     vector<int> hash(26);
//     for(auto &c :s){
//         hash[c-'a']++;
//     }
//     int con=0;
//     for(int i=0;i<26;i++){
//         if(i==4 ||i==0||i==8||i==14||i==21) continue;
//         con=max(con,hash[i]);
//     }
//     int vowel=max(hash[0],max(hash[4],max(hash[8],max(hash[14],hash[21]))));
//     return vowel+con;
// }
// int main(){
//     c
// }