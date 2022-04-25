#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> file;
int numBuffer,recordsPerPage,numRecords;
void firstRun()
{
    for(int i=0;i<file.size();i+=numBuffer) {
        for (int j = i; j < min(i + numBuffer, (int) file.size()); j++)
            sort(file[j].begin(), file[j].end());
    }
}
void externalSort() {
    while(file.size()>1)
    {
        vector<vector<int> > tempFile;

        for (int i = 0; i < file.size(); i += numBuffer - 1) {
            int pageBrought;
            if (file.size() - i >= numBuffer - 1) {
                pageBrought = numBuffer - 1;
            } else
                pageBrought = file.size() - i;
            int arr[pageBrought];
            for (int j = 0; j < pageBrought; j++) {
                arr[j] = 0;
            }
            vector<int> temp;
            while (true) {
                int minimum = INT_MAX;
                int idx = -1;
                for (int j = i; j < i + pageBrought; j++) {
                    if (arr[j - i] < file[j].size()) {
                        if (file[j][arr[j - i]] < minimum) {
                            minimum = min(file[j][arr[j - i]], minimum);
                            idx = j - i;
//                            cout<<minimum<<" ";
                        }
                    }
                }
//                cout<<endl;
                if (idx == -1)
                    break;
                arr[idx]++;
                temp.push_back(minimum);
            }
            tempFile.push_back(temp);

        }
        file = tempFile;

    }
}
int main()
{
    cin>>numBuffer>>recordsPerPage>>numRecords;
    int i=0;
    vector<int> temp;
//    cout<<numRecords<<endl;
    while(i<numRecords)
    {
        int x;
        cin>>x;
        temp.push_back(x);
        i++;
        if(temp.size()==recordsPerPage)
        {
            file.push_back(temp);
            temp.clear();
        }
    }
    if(temp.size()>0)
        file.push_back(temp);
    firstRun();
    externalSort();
    for(auto x:file)
    {
        for(auto y:x)
            cout<<y<<endl;
    }
}