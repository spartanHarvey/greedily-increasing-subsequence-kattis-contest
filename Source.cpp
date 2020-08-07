#include<iostream>
#include <string>
#include <vector>


using namespace std;
int compvar(const void* one, const void* two)
{
    int a = *((int*)one);
    int b = *((int*)two);
    if (a < b)
        return -1;
    if (a == b)
        return 0;
    return 1;

}
int singleNumber(vector<int>& nums) {
    int n = nums.back();
    int m;
    bool r = false;

    for ( int i = 0; i < nums.size()-1 ; i++) {

        m = nums[i];
      
        if (m == n ) {
            r = true;
            nums.pop_back();
            swap(nums.at(i), nums.back());
            nums.pop_back();
            n = nums.back();
            // singleNumber(nums); 
            i = -1;
        }
       
    }
     cout << n << endl;
     return n; 

   
}
vector<int> twoSum(vector<int>& nums, int target) {

    vector<int>result;
    for (int i = 0; i < nums.size() - 1; i++) {

        for (int j = i + 1; j <= nums.size()-1; j++) {

            if (nums.at(i) + nums.at(j) == target) {

                result.push_back(i);
                result.push_back(j + 1);
                return {i,j+1};
            }
        }
    }
}
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>>result;

    if (nums.size() == 0) { return result; }
    else {

        for (int i = 0; i <= nums.size() - 3; i++) {
            int c = nums.at(i);
            for (int j = i + 1; j <= nums.size() - 2; j++) {

                for (int k = j + 1; k <= nums.size() - 1; k++) {

                    if (nums.at(j) + c + nums.at(k) == 0) {


                        if(nums.at(j) < c + nums.at(j) <nums.at(k))

                        result.push_back({ c, nums.at(j),nums.at(k) });

                        //for (int i = result.size() - 1; i <= result.size() - 1; i++) {
                        //    for (int j = 0; j < result[i].size() - 1; j++) {
                        //        for (int k = j + 1; k <= result[i].size() - 1; k++) {

                        //            if (result[i][j] > result[i][k]) {
                        //                swap(result[i][j], result[i][k]);

                        //            }
                        //        }
                        //    }


                        //}
                    }
                    for (int i = 0; i <= result.size() - 1; i++) {
                        for (int j = i + 1; j <= result.size() - 1; j++) {
                            if (result.at(i) == result.at(j)) {
                                result.pop_back();
                            }
                        }
                    }

                }

            }

        }
    }

    return result;
}
bool isHappy(int n) {

    string happy = to_string(n);
    bool isHappy = false;
    int num1, num2, r=0, counter=0;
    vector<int>arr;

 
    for (int i = 0; i <= happy.length()-1 ; i++) {
       
            num1 = (int)happy.at(i) - '0';
            num2 = num1 * num1;
            arr.push_back(num2);
        
            if (i == happy.length()-1) {
                for (int j = arr.size() - 1; j >=0; j--) {
                    r += arr.at(j);
                    arr.pop_back();
                }
                if (r == 1) { return true; }
                else if (r > 1 ) {
                    happy = to_string(r);
                    r = 0;
                    i = -1;
                    counter++;
                }
                else if(counter ==5) {
                    return isHappy;
                }
            }

      
    }
    
}
int findLucky(vector<int>& arr) {

    int lucky=-1, next=0, value=arr.at(0);
    for (int i = next; i <= arr.size()-2; i++) {
        int counter = 1;
        for (int j = i + 1; j <= arr.size() - 1; j++) {
            if (arr.at(i) == arr.at(j)) {
                counter++;
            }
            else if (arr.at(i) < arr.at(j) && value < arr.at(j)) {
                next = j+4;
                value = arr.at(j);

            }
        }
       
        if (counter == arr.at(i) && arr.at(i) > lucky) {
            lucky = arr.at(i);
        }
        if (counter == arr.size()) { break; }
       
    }
    return lucky;
}
int myAtoi(string str) {

    signed int num = 0, j = 0;
    string temp = "", t = "";
    if (str.length() >= 1) {
        for (int i = 0; i <= str.length() - 1; i++) {

            if (isalpha(str.at(i)))
            {
                break;
            }
            else if (str.at(i) == '-' && temp.length() == 0||
                    str.at(i) == '+' && temp.length() == 0 || 
                    isdigit(str.at(i)))
            {
                temp += str.at(i);
            }
            else if (str.at(i) == '.') {
                break;
            }
            else if (str.at(i) == ' ' && temp.length() >= 1) {
                break;
            }


        }
        if (temp.length() > 0) {
            while (temp.length() - 1 >= j) {
                if (temp.at(j) != '0') {
                    t += temp.at(j);
                }
                else if (temp.at(j) == '0' && t.length() >= 1 && t.at(0) != '-' && t.at(0) !='+')  {
                    t += temp.at(j);
                }

                j++;
            }
        }

        if (t.length() > 10 && t.at(0) == '-') {
            num = -2147483648;
        }
        else if ((t.length() > 10 && isdigit(t.at(0))) ||
            (t.length() > 10 && t.at(0) == '+')) {
            num = 2147483647;
        }
        else if ((t.length() == 1 && t.at(0) == '+') ||
            (t.length() == 1 && t.at(0) == '-'))
        {
            num = 0;
        }
        else if (t.length() >= 1) {
            num = stoi(t);
        }
    } return num;
}
int jump(vector<int>& nums) {

    int j = nums.at(0), counter = 0;;

    for (int i = 0; i <= nums.size() - 1; i = i) {

        i = nums.at(i);
        counter++;
        if (i == nums.size() - 1) { break; }

    }

    return counter;
}

int main() {

    int nElements, num = 0, c = 0, l=1;
    string str;
    vector <int>arr;
    vector <int>ar;

    //isHappy(7);
   // myAtoi("+-2");
    cin >> nElements;

 
    

    for (int i = 0; i < nElements; i++) {

        cin >>num;

        
        arr.push_back(num);

    }
    jump(arr);
    //singleNumber(arr);
   // twoSum(arr, 26);
    // threeSum(arr);

    

    ar.push_back(arr.front());
    str = to_string(ar.back());

    for (int i = 1; i < nElements; i++) {
        c = ar.back();
      
        if (arr[i] > c ) {
            ar.push_back(arr.at(i));
            str += ' '+ to_string(ar.back());
            l++;
           
        }
        
    }
    cout << l << endl;
       cout << str<<endl;
   
        //delete arr;
    system("pause");
    return 0;
}

//vector<vector<int>> threeSum(vector<int>& nums) {
//
//    vector<vector<int>>result;
//    for (int i = 0; i <= nums.size() - 3; i++) {
//        int c = nums.at(i);
//        for (int j = i + 1; j <= nums.size() - 2; j++) {
//            if (nums.at(j) + c + nums.at(j + 1) == 0) {
//                result.push_back({ c, nums.at(j),nums.at(j + 1) });
//            }
//        }
//
//    }
//    return result;
//}