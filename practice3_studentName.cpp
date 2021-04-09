#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

//Read id, score, Name and process

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

struct Student{
    int id;
    double score;
    string name;
};

int main(){
    ifstream inFile;
    openInputFile(inFile);
    vector<Student> vs;
    Student temp;

    while(inFile>>temp.id){

            inFile>>temp.score;
            inFile.ignore(9999,'\t');
            getline(inFile,temp.name);
            vs.push_back(temp);
    }

    cout<<"Students with test score over 90: "<<endl;
    for(Student s:vs)
    if(s.score >= 90){cout<<s.id<<'\t'<<s.score<<'\t'<<s.name<<endl;}



    return 0;
}
