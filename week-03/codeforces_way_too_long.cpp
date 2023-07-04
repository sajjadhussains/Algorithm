#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string num_of_words[n];
    for(int i=0;i<n;i++){
        string word;
        cin>>word;
        num_of_words[i]=word;
    }
    for(int i=0;i<n;i++){
        string new_word = num_of_words[i];
        int length_of_the_word = new_word.length();
        if(length_of_the_word<=10){
            cout<<new_word<<endl;
        }
        else{
            cout<<new_word[0]<<length_of_the_word-2<<new_word[length_of_the_word-1]<<endl;
        }
    }

    return 0;
}