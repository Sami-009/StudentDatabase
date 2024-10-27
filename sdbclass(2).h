// Result Card - Using Classes - OOP
#define MAXST 60        // Max Students
#define MAXSUB 5        // Max Subjects

#define isValidNum(min,max,val) ((val>=min)&&(val<=max))
#define ageChecker(yyB,yyA) ((yyA - yyB) >= 17)
#define isLeapYear(year) ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
// Classes Declaration
struct myDate
{
    int dd,mm,yy;
};
class Student
{
    private:
        int rno;
        string name, fName;
        myDate DOB, DOA;
        int mks[MAXSUB], mobt;
        float perc;
        char grad;
    public:
        // Constructor
        Student():rno(0),name(""),fName(""),DOB({0,0,0}),DOA({0,0,0}),mobt(0),perc(0.0),grad('F')
        {} 
        // Member Functions
        void getter();
        void setter(int rr);
        int getRno();
        // Date Checker
        bool dateValid(myDate dateCheck);
};

// Member Function definitions
void Student::setter(int rr)
{
    int sum = 0;
    do{
        rno = rr;
        cout<<"Enter Data of Reg Num: "<<rno<<endl;
       
        cout << "Name: ";
        cin.ignore(30,'\n');
        getline(cin, name);

        cout << "Father Name: ";
        getline(cin, fName);
        
        do {
            cout<<"Enter the DOB of student:" << endl;
            do {
                cout<<"Date: ";
                cin>>DOB.dd;
                if (isValidNum(1,31,DOB.dd))
                    break;
                else
                    cout<<"InValid Number.....!\n";
            } while(true);
            do {
                cout<<"Month: ";
                cin>>DOB.mm;
                if (isValidNum(1,12,DOB.mm))
                    break;
                else
                    cout<<"InValid Number.....!\n";
            } while(true);
            do {
                cout<<"Year: ";
                cin>>DOB.yy;
                if (isValidNum(1000,9999,DOB.yy))
                    break;
                else
                    cout<<"InValid Number.....!\n";
            } while(true);
            if (dateValid(DOB))
                break;
            else
            {
                cout<<"Error...Your DOB("<<DOB.dd<<"."<<DOB.mm<<"."<<
                    DOB.yy<<") is Incorrect\n";
            }
        } while(true);

        do {
            cout<<"Enter the DOA of student:" << endl;
            do {
                cout<<"Date: ";
                cin>>DOA.dd;
                if (isValidNum(1,31,DOA.dd))
                    break;
                else
                    cout<<"InValid Number.....!\n";
            } while(true);
            do {
                cout<<"Month: ";
                cin>>DOA.mm;
                if (isValidNum(1,12,DOA.mm))
                    break;
                else
                    cout<<"InValid Number.....!\n";
            } while(true);
            do {
                cout<<"Year: ";
                cin>>DOA.yy;
                if (isValidNum(1000,9999,DOA.yy))
                    break;
                else
                    cout<<"InValid Number.....!\n";
            } while(true);
            if (dateValid(DOA))
                break;
            else
            {
                cout<<"Error...Your DOA("<<DOA.dd<<"."<<DOA.mm<<"."<<
                    DOA.yy<<") is Incorrect\n";
            }
        } while(true);

        if (!ageChecker(DOB.yy, DOA.yy))
        {
            cout<<"Admission Not possible! Student must be atleast 17 years old"<<endl;
        }
        else
            break;
    } while(true);

    sum = 0;
    cout << "Enter Marks [Max 100] of students:" << endl;
    for (int j=0; j < MAXSUB; j++)             // 5 subject marks
    {
        do {
            cout << "Enter Marks of Subject: " << j+1 << " : ";
            cin >> mks[j];
            if (isValidNum(0,100,mks[j]))
                break;
            else
                cout<<"InValid Number.....!\n";
            } while(true);
        sum += mks[j]; 
    }
    
    mobt = sum;                      // marks obtained

    // %age calculation
    perc = (mobt * 100.0) / 500.0;
    // Grage Assignment
    if (perc >= 80) grad = 'A';
    else if (perc >= 70) grad = 'B';
    else if (perc >= 60) grad = 'C';
    else if (perc >= 50) grad = 'D';
    else grad = 'F';
}  

void Student::getter()
{
    cout << rno << " - ";
    cout << name << " - ";
    cout << fName << " - ";
    cout << DOB.dd << "."
            << DOB.mm << "."
            << DOB.yy << " - ";
    cout << DOA.dd << "."
            << DOA.mm << "."
            << DOA.yy << " - ";
    for (int j = 0; j < MAXSUB; j++)
        cout << mks[j] << " - ";
    cout << mobt << " - " <<perc << " - " 
            << grad << endl;
}

int Student::getRno()
{
    return rno;
}

// Date Checker Func Definition
bool Student::dateValid(myDate dateCheck)
{
    if ((dateCheck.mm >= 1)&&(dateCheck.mm <= 12))
    {
        switch (dateCheck.mm)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
            {
                if ((dateCheck.dd>=1)&&(dateCheck.dd<=31))
                    return true;
                else 
                    return false;
            }
        case 2:
            {
                if (isLeapYear(dateCheck.yy))
                {
                    if ((dateCheck.dd>=1)&&(dateCheck.dd<=29))
                        return true;
                    else 
                        return false;
                }
                else    
                {
                    if ((dateCheck.dd>=1)&&(dateCheck.dd<=28))
                        return true;
                    else 
                        return false;
                }
            }
        case 4: case 6: case 9: case 11:  
            {
                if ((dateCheck.dd>=1)&&(dateCheck.dd<=30))
                    return true;
                else 
                    return false;
            }
        default:
            return false;
        }
    }
    else 
        return false;    
}

class StudentDb {
    private:
        Student students[MAXST];
        int nn;
    public:
        void readFun();
        void appFun(int& nn);
        int searchFun(int s);
        void sortFun(int nn);
        void delFun(int& nn, int s);
        void updFun(int nn, int s);
        void dispFun();
};

// Function Definitions
void StudentDb::readFun()
{
    int rnum;
    do{
        cout << "Enter Number of Students in the class [Max 60]: ";
        cin >> nn;
        if (isValidNum(1, MAXST, nn))
            break;
        else
            cout<<"InValid Number...\n";
    } while(true);

    for (int i=0; i<nn; i++)
    {
        cout << "Enter Data for Student: " << i+1 << endl;
        do{
            do { 
                cout << "Reg#(4-digit): ";
                cin >> rnum;
                if (isValidNum(1000, 9999, rnum))
                    break;
                else
                    cout<<"InValid Number.....!\n";
                } while(true);
            do{
                if (searchFun(rnum) == -1)
                {
                    students[i].setter(rnum);
                    break;
                }
                else
                {
                    cout<<"\n Reg Number already exists...\n";
                    break;
                }
            }while(true);
        }while(true);
    }
}// end of readFun

void StudentDb::appFun(int& nn)
{
    int rnum;
    cout << "Enter Data for Student: " << nn+1 << endl;
    do{
            do { 
                cout << "Reg#(4-digit): ";
                cin >> rnum;
                if (isValidNum(1000, 9999, rnum))
                    break;
                else
                    cout<<"InValid Number.....!\n";
                } while(true);
            do{
                if (searchFun(rnum) == -1)
                {
                    students[nn].setter(rnum);
                    break;
                }
                else
                {
                    cout<<"\n Reg Number already exists...\n";
                    break;
                }
            }while(true);
        }while(true);
    nn++;
}// end of appFun

int StudentDb::searchFun(int s)
{
  int p = -1;
  for (int i = 0; i < nn; i++)
  {
    if (s == students[i].getRno())
    {
        p = i;
        break; 
    }
  }
  return p;  
}// end of searchFun

void StudentDb::sortFun(int nn)
{
    int nofpass = nn - 1;
    Student temp;
    for (int i=0; i<nofpass; i++)   // Selection Sort method
     for (int j=i+1; j<nn; j++)
      if (students[i].getRno() > students[j].getRno())
       {
            temp  = students[i];
            students[i] = students[j];
            students[j] = temp;
       }
    cout << "Data Sorted successfully..." << endl;
}// end of sortFun

void StudentDb::delFun(int& nn, int s)
{
    int p;
    p = searchFun(s);
    if (p != -1)           // student found in the list
    {
        for (int i = p; i < nn-1; i++)
            students[i] = students[i+1];
        
        nn--;
        cout << "Student deleted successfully..." << endl;
    }
    else
     cout << "Student Not found in the List, can't be deleted..." << endl;
}// end of delFun

void StudentDb::updFun(int nn,int s)
{
    int p;
    p = searchFun(s);
    if (p != -1)        // student found in the list
    {
        cout << "OLD RECORD" << endl;
        students[p].getter();        
        cout << "--------------------------------------------------" << endl;
        cout << "Now Enter New Data" << endl;
        students[p].setter(11);
        cout << "Student's Record Updated successfully..." << endl;
    }
    else
        cout << "Student Not found in the List, can't be updated..." << endl;
}// end of updFun

void StudentDb::dispFun()
{
    for (int i = 0; i < nn; i++)
    {
        students[i].getter();
    }
}// end of dispFun
