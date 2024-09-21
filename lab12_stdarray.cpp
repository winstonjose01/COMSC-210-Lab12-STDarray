//Winston Jose

# include <iostream>
# include <array>
# include <algorithm>
# include <numeric>
# include <fstream>
# include <sstream>
# include <string>

using namespace std;

const int SIZE = 30;

//Function declaration
int openFile(fstream &, string);
void closeFile (fstream &);

struct GroceryItem{
    string item;
    double prices;
};

int main(){

    fstream budgetfile;
    string filename = "budget.csv";
    int fstat;
    string line;
    array<GroceryItem, SIZE> list; // Array of structs
 

    fstat = openFile(budgetfile,filename);
    if (fstat < 0){
        exit(-1);
    }
    int i = 0;
    while (getline(budgetfile, line) && i < SIZE){
        stringstream ss(line);
        string priceStr;

        getline(ss, list[i].item,',');
        getline(ss,priceStr);//{
        if (!priceStr.empty())
            try{
            list[i].prices = stod(priceStr);
            }
            catch(const invalid_argument &e){
            cout << "Invalid price " << priceStr << endl;
            }
        i++;
    }

    // Report the size of each array
    cout << "1. Size of Grocery list: " << list.size() << endl;
    cout << "----------------------------------------------------\n";

    // Values of array of struct 
    cout << "2. Accessing value of the Grocery list:\n";
    for (GroceryItem val :  list) cout << "\t" << val.item << " | $" << val.prices << endl;
     cout << "----------------------------------------------------\n";
    
    // Accessing individual elements: 
    cout << "\nElement 11 item and price: "<< list.at(11).item << " | $" << list.at(11).prices;
    cout << "\nElement 29 item and price: "<< list[29].item << " | $" << list[29].prices;
    cout << "\nFront item and price: "<< list.front().item<< " | $" << list.front().prices;
    cout << "\nBack item and price: "<< list.back().item<< " | $" << list.back().prices;
    


    return 0;


}

int openFile(fstream &f, string fname){
    f.open(fname.data(), ios::in);
    if(!f){
        cout << "Error opening file. Program aborting\n";
        return 0;
    }
    else{
        return 1;    
    }
}
