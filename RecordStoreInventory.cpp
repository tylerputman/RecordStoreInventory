//Author: Clayton Putman
//Program: This program allows a record store to maintain an inventory of their
//product while also allowing a user to add, delete, modify, or view all records
//in their system.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct recordStore
{
    string albumArtist;
    string albumName;
    string albumGenre;
    int quantity;
    int year;
    int productCode;
    double albumPrice;
};

//Prototypes

void menu();
void addRecord(vector<recordStore>& inventory);
void deleteRecord(vector<recordStore>& inventory);
void modifyRecord(vector<recordStore>& inventory);
void printAllRecords(vector<recordStore>& inventory);
void quit();

int main()
{

vector<recordStore> inventory;

int menuChoice;

do
{
    menu();
    cout << "\n";
    cin >> menuChoice;
    cout << "\n";
    
    switch(menuChoice)
    {
        case 1:
            addRecord(inventory);
            break;
        
        case 2:
            deleteRecord(inventory);
            break;

        case 3:
            modifyRecord(inventory);
            break;
        
        case 4:
            printAllRecords(inventory);
            break;
        
        case 5:
            quit();
            break;
        
        default:
            cout << "User has selected invalid option. Please choose again." << endl;
            break;
    } 
} while(menuChoice != 5);

return 0;
}

void menu()
{
    cout << "|------------------------------------|" << endl;
    cout << "    Record Store Inventory System     " << endl;
    cout << "|------------------------------------|" << endl;
    cout << "\n";

    cout << "Please select a choice from the options below (1-5):";
    cout << "\n";

    cout << "1. Add a record to inventory" << endl;
    cout << "2. Delete a record from inventory" << endl;
    cout << "3. Modify a record from inventory" << endl;
    cout << "4. Print all records" << endl;
    cout << "5. Quit" << endl;
}

void addRecord(vector<recordStore>& inventory)
{
    recordStore newRecord;

    getline(cin, newRecord.albumArtist);
    cout << "Enter the artist name: ";
    getline(cin, newRecord.albumArtist);
    cout << "\n";
    cout << "Enter the album name: ";
    getline(cin, newRecord.albumName);
    cout << "\n";
    cout << "Enter the album genre: ";
    getline(cin, newRecord.albumGenre);
    cout << "\n";
    cout << "What year was the album released: ";
    cin >> newRecord.year;
    cout << "\n";
    cout << "What is the price of the item: ";
    cin >>  newRecord.albumPrice;
    cout << "\n";
    cout << "Quantity in inventory: ";
    cin >> newRecord.quantity;
    cout << "\n";
    cout << "Enter product code for this item (used to delete/edit items from inventory): ";
    cin >> newRecord.productCode;
    cout << "\n";

    inventory.push_back(newRecord);
    cout << "New item added to inventory." << endl;
    cout << "\n";
}

void deleteRecord(vector <recordStore>& inventory)
{
    if(inventory.empty())
    {
        cout << "Record deletion unsuccessful. Record does not exist in inventory." << endl;
        cout << "\n";
        return;
    }

    int deleteItem;
    cout << "Please enter product code of item to delete: " << endl;
    cin >> deleteItem;

    for(auto pc = inventory.begin(); pc != inventory.end(); pc++)
    {
        if(pc -> productCode == deleteItem)
        {
            inventory.erase(pc);
            cout << "Records deleted from inventory..." << endl;
            cout << "\n";
            return;
        }
    }

    cout << "Item not found. Deletion unsuccessful." << endl;
    cout << "\n";
}

void modifyRecord(vector<recordStore>& inventory)
{
    if(inventory.empty())
    {
        cout << "Record edit unsuccessful. Record does not exist in inventory." << endl;
        cout << "\n";
        return;
    }

    int editRecord;
    cout << "Please enter product code of item to edit: " << endl;
    cin >> editRecord;

    for(auto& record : inventory)
    {
        if(record.productCode == editRecord)
        {
            cout << "Enter new quantity: ";
            cin >> record.quantity;
            cout << "Enter new price: ";
            cin >> record.albumPrice;
            cout << "\n";
            cout << "Records updated..." << endl;
            cout << "\n";
            return;
        }
    }
    cout << "Item not found. Edit unsuccessful." << endl;
    cout << "\n";
}

void printAllRecords(vector<recordStore>& inventory)
{
    if(inventory.empty())
    {
        cout << "Record inventory is empty." << endl;
        cout << "\n";
        return;
    }

    cout << left << setw(15) << "Artist" << setw(25) << "Album Name" << setw(15) << "Genre" << setw(10) << "Year" 
    << setw(10) << "Price" << setw(10) << "Qty" << setw(15) << "Product Code" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;

    for(auto& record : inventory)
    {
        cout << left << setw(15) << record.albumArtist << setw(25) << record.albumName << setw(15) << record.albumGenre 
        << setw(10) << record.year << setw(10) << record.albumPrice << setw(10) << record.quantity 
        << setw(15) << record.productCode << endl;
    }

    cout << "\n";

    string saveChoice;
    cout << "Would you like to save this inventory to a text file (Yes/No): ";
    cin >> saveChoice;
    cout << "\n";

    if(saveChoice == "Yes" || "Y")
    {
        ofstream saveFile;
        saveFile.open("Record Inventory.txt");
        saveFile << left << setw(15) << "Artist" << setw(25) << "Album Name" << setw(15) << "Genre" << setw(10) << "Year" 
    << setw(10) << "Price" << setw(10) << "Qty" << setw(15) << "Product Code" << endl;
    saveFile << "--------------------------------------------------------------------------------------------" << endl;

    for(auto& record : inventory)
    {
        saveFile << left << setw(15) << record.albumArtist << setw(25) << record.albumName << setw(15) << record.albumGenre 
        << setw(10) << record.year << setw(10) << record.albumPrice << setw(10) << record.quantity 
        << setw(15) << record.productCode << endl;
    }
    }
    else
    {
        menu();
    }
}

void quit()
{
    exit(0);
}

