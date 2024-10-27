#include"sdbclass(2).h"
#include<iostream>
using namespace std;
int main()
{
    //declarations    
    StudentDb sdb;
    int n;      // number of students sitting in he class
    int sinfo, pos;
    int choice;
    
    // Menu
    do{
        cout << "**** MENU ****" << endl
            << " 1. Read & Store Data " << endl
            << " 2. Append new record " << endl
            << " 3. Search a record " << endl
            << " 4. Sort Data " << endl
            << " 5. Delete a record " << endl
            << " 6. Update a record " << endl
            << " 7. Display Result Card " << endl
            << " 8. Exit " << endl;
            
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1: 
                //cout << "Read and Store the Data...\n";
                sdb.readFun();
                break;
            case 2: 
                //cout << "Append New Record...\n";
                if (n < MAXST)
                    sdb.appFun(n);
                else
                    cout << "ARRAY is Full...\n";
                break;
            case 3:
                //cout << "Search a Record...\n";
                if (n != 0)
                {
                    cout << "Enter Reg# of the student to be searched: ";
                    cin >> sinfo;
                    pos = sdb.searchFun(sinfo);
                    if (pos == -1)
                        cout << "Student ID: " << sinfo << " not exists" <<endl;
                    else
                        cout << "Student ID: " << sinfo << " exists at Position No. " << pos+1 << endl;
                }
                else
                    cout << "First, store data using Option-1...\n";
                break;
            case 4: 
                //cout << "Sort Data with respect to reg. num...\n";
                if (n != 0)
                {
                    sdb.sortFun(n);
                }
                 else
                    cout << "First, store data using Option-1...\n";
                break;
            case 5: 
                //cout << "Delete a Record...\n";
                if (n != 0)
                {   cout << "Enter Reg# of the student to be deleted: ";
                    cin >> sinfo;
                    sdb.delFun(n, sinfo); 
                }
                 else
                    cout << "First, store data using Option-1...\n";    
                break;
            case 6: 
                //cout << "Update a Record...\n";
                if (n != 0)
                {
                    cout << "Enter Reg# of the student to be updated: ";
                    cin >> sinfo;
                    sdb.updFun(n, sinfo);
                }
                 else
                    cout << "First, store data using Option-1...\n";    
                break;
            case 7: 
                //cout << "Display the Record...\n";
                if (n != 0)
                {
                    sdb.dispFun();
                }
                 else
                    cout << "First, store data using Option-1...\n";    
                break;
            case 8: exit(-1);
            default:
                cout << "Invalid Choice...\n";
        }// end of switch
    }while(true);
    system("pause");
    return 0;
}// end of main
