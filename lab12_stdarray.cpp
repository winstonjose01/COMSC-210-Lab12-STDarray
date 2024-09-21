//Winston Jose

# include <iostream>
# include <array>
# include <algorithm>
# include <numeric>
# include <fstream>
# include <sstream>
# include <string>

using namespace std;

const int SIZE = 30; // Constant size for the

struct GroceryItem{
    string item;
    double prices;
};

//Function declaration
int openFile(fstream &, string);
void closeFile (fstream &);
bool sortbyItem (GroceryItem &, GroceryItem &);
bool sortbyPrice (GroceryItem &, GroceryItem &);



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
    cout << "\n3. Element 11 item and price: "<< list.at(11).item << " | $" << list.at(11).prices;
    cout << "\n4. Element 29 item and price: "<< list[29].item << " | $" << list[29].prices;
    cout << "\n5. Front item and price: "<< list.front().item<< " | $" << list.front().prices;
    cout << "\n6. Back item and price: "<< list.back().item<< " | $" << list.back().prices;
    cout << "\n7. Empty ? " << (list.empty() == 0? "False" : "True");
    cout << "\n8. Address? " << list.data();
    cout << "----------------------------------------------------\n";

    // Using iterators to sort
    sort(list.begin(), list.end(), sortbyItem); // Sort by item using a comparator function
    cout << "\n9.  Sorted by item :\n";
    for (GroceryItem val :  list) cout << "\t" << val.item << " | $" << val.prices << endl;
    cout << "----------------------------------------------------\n";
    sort(list.begin(), list.end(), sortbyPrice); // Sort by price using a comparator function
    cout << "\n10.  Sorted by price :\n";
    for (GroceryItem val :  list) cout << "\t" << val.item << " | $" << val.prices << endl;
    cout << "----------------------------------------------------\n";
    sort(list.begin(), list.end(), sortbyItem); // Sort by item using a comparator function
    cout << "\n11.  Reverse sorting by item :\n";
    sort(list.rbegin(), list.rend(), sortbyItem);
    for (GroceryItem val :  list) cout << "\t" << val.item << " | $" << val.prices << endl;
    cout << "----------------------------------------------------\n";

    // find max & min & sum
    cout << "12. Max: $" << max_element(list.begin(), list.end(),[](GroceryItem &a, GroceryItem &b)
         {return a.prices < b.prices;})->prices;
    cout << "\n13. Min: $" << max_element(list.begin(), list.end(),[](GroceryItem &a, GroceryItem &b)
         {return a.prices > b.prices;})->prices;
    cout << "\n13. Sum: $" << accumulate(list.begin(), list.end(),0.0,[](double sum, GroceryItem &b)
         {return sum + b.prices;});

    budgetfile.close();

    return 0;

}

bool sortbyItem(GroceryItem &a, GroceryItem&b){
    return (a.item < b.item);
}

bool sortbyPrice(GroceryItem &a, GroceryItem&b){
    return (a.prices < b.prices);
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
