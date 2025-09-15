#include<iostream>
#include<vector>

using namespace std;

vector<string> subSeq(string str, int idx){
    // base case
    if(idx == str.length()){
        vector<string> tempArr;
        tempArr.push_back("");
        return tempArr;
    }

    vector<string> finalAns;
    // recursive call
    vector<string> tempAns = subSeq(str, idx+1);
    // add idx element to each element of tempAns
    for(auto elem : tempAns)
        finalAns.push_back(str[idx] + elem);
    // no add
    for(auto elem : tempAns)
        finalAns.push_back(elem);

    return finalAns;
}

void subSeqBT(string str, int idx, string tempAns, vector<string> finalAns){
    if(idx == str.length()){
        finalAns.push_back(tempAns);
        return;
    }
    
    subSeqBT(str, idx+1, tempAns+str[idx], finalAns);
    subSeqBT(str, idx+1, tempAns, finalAns);
}

int main(){
    string str = "abc";
    int startingIdx = 0;
    vector<string> ans = subSeq(str, startingIdx);
    for(auto elem : ans)
        cout << elem << endl;
    return 0;
}