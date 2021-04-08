#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

//Read number from txt file then average it.

void openInputFile(ifstream& openFile)
{
    string fileName;
    cout<<"Please input filename: ";
    cin>>fileName;
    openFile.open(fileName);

    while(!openFile)
    {
        cout<<"Wrong filename!"<<endl;
        cout<<"Print again: ";
        cin>>fileName;
        openFile.clear();
        openFile.open(fileName);
    }
}

int main(){
    ifstream openFile;
    openInputFile(openFile);
    vector<int> v;
    int temp;

    while(openFile>>temp){
        v.push_back(temp);
    }

    int sum = 0;
    for(int i:v)
        sum += i;

        cout<<sum/v.size();

    return 0;
}
