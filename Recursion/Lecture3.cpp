 #include<iostream>
 #include<vector>

 using namespace std;
 
vector<vector<int>> permute(vector<int>& nums, vector<bool>& visited) {  
    bool allVisited = true;
    for(auto vis : visited){
        allVisited &= vis;
    }
    if(allVisited){
        return {{}};
    }
    vector<vector<int>> answer;
    for(int idx = 0; idx < nums.size(); idx++){
        if(!visited[idx]){
            visited[idx] = true;
            vector<vector<int>> tempAns = permute(nums, visited);
            for(auto ans : tempAns){
                ans.push_back(nums[idx]);
                answer.push_back(ans);
            }
            visited[idx] = false;
        }
    }
    return answer;
}

vector<vector<int>> permute2(vector<int>& nums) {
    bool allVisited = true;
    for(auto elem : nums){
        if(elem != 11){
            allVisited = false;
            break;
        }
    }
    if(allVisited){
        return {{}};
    }
    vector<vector<int>> answer;
    for(int idx = 0; idx < nums.size(); idx++){
        if(nums[idx] != 11){
            int temp = nums[idx];
            nums[idx] = 11;
            vector<vector<int>> tempAns = permute2(nums);
            for(auto ans : tempAns){
                ans.push_back(temp);
                answer.push_back(ans);
            }
            nums[idx] = temp;
        }
    }
    return answer;
}

int infyCoinsPermutations(vector<int>& coins, int target, string ans, vector<string>& finalAns){
    // base case
    if(target == 0){
        finalAns.push_back(ans);
        return 1;
    }

    int count = 0;
    for(int i = 0; i < coins.size(); i++){
        if(target - coins[i] >= 0)
            count += infyCoinsPermutations(coins, target - coins[i], ans + to_string(coins[i]), finalAns);
    }
    return count;
}

int main(){
    // vector<int> nums = { 1,2,3 };
    // vector<bool> visited(3, false);
    // vector<vector<int>> answer = permute(nums, visited);
    // for(auto ans : answer){
    //     for(auto elem : ans){
    //         cout << elem << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> coins = {2,3,5,7};
    int target = 10;
    vector<string> finalAns;
    int count = infyCoinsPermutations(coins, target, "", finalAns);

    for(auto ans : finalAns){
        cout << ans << endl;
    }
    cout << "Total Permutations : "<<count;
    return 0;
}