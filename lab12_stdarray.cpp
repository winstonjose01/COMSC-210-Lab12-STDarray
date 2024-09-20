//Winston Jose

# include <iostream>
# include <array>
# include <algorithm>
# include <numeric>
# include <fstream>
using namespace std;


int openFile(fstream &, string);
void closeFile (fstream &);

int main(){

fstream budgetfile;
string filename = "budget.txt";
int fstat;
fstat = openFile(budgetfile,filename);
if (fstat < 0){
    exit(-1);
}

return 0;


}

int openFile(fstream &f, string fname){
    f.open(fname.data(), ios::in);
    if(!f){
        cout << "Error opening file. Program aborting\n";
        return -1;
    }
    else{
        return 1;    
    }
}
