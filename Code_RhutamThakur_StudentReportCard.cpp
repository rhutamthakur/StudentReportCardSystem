#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
    private:
	string name;
	int roll;
	float english, history, geography, science, maths, average;
    public:


	int InsertData(string n, int r, float eng, float his, float geo, float sci, float math)
	{
		name = n;
		roll = r;
		english = eng;
		history = his;
		geography = geo;
		science = sci;
		maths = math;

		average = (english + history + geography + science + maths) / 5;
	}

	int GetRoll()
	{
		return roll;
	}

	int Report()
	{
		cout<<endl<<"STUDENT REPORT CARD"<<endl;
		cout<<"***********"<<endl<<endl;
		cout<<"NAME       : "<<name<<endl;
		cout<<"ROLL NUMBER: "<<roll<<endl;
		cout<<"ENGLISH    : "<<english<<endl;
		cout<<"SCIENCE    : "<<science<<endl;
		cout<<"MATHEMATICS: "<<maths<<endl;
		cout<<"HISTORY    : "<<history<<endl;
		cout<<"GEOGRAPHY  : "<<geography<<endl;
		cout<<"AVERAGE    : "<<average<<endl;
		cout<<"PERCENTAGE : "<<((english+science+maths+history+geography)/500)*100<<endl;
		if((((english+science+maths+history+geography)/500)*100)>90)
        cout<<"GRADE      : A"<<endl;
        else if((((english+science+maths+history+geography)/500)*100)>80)
        cout<<"GRADE      : B"<<endl;
        else if((((english+science+maths+history+geography)/500)*100)>75)
        cout<<"GRADE      : C"<<endl;
        else if((((english+science+maths+history+geography)/500)*100)>50)
        cout<<"GRADE      : D"<<endl;
        else
        cout<<"The Student has failed. Good Luck Next Year!"<<endl;
	}
};

//Vector is used instead of an array due to its flexibility in size extension

vector<Student> database;
int databaseSize;

void ResizeDatabase()
{
	database.resize(databaseSize);
}


int AddData()
{
	string name;
	int roll;
	float english, history, geography, science, maths;

	cout<<endl<<"ENTER THE DETAILS OF THE STUDENT:"<<endl;
	cout<<"NAME: ";
	cin.ignore();
	getline(cin, name);
	cout<<"ROLL: ";
	cin>>roll;
	cout<< "Marks In ENGLISH, SCIENCE, MATHS, HISTORY And GEOGRAPHY:"<<endl;
	cin>>english>>science>>maths>>history>>geography;
	cout<<"\nStudent Data Added To The Database."<<endl;

	databaseSize++;
	ResizeDatabase();
	database[databaseSize - 1].InsertData(name, roll, english, history, geography, science, maths);
}

void PrintReport(int roll)
{
    for (int i = 0; i < databaseSize; i++)
            if (database[i].GetRoll() == roll)
            {
                database[i].Report();
                return;
            }

    cout<<"\nThe Entered Roll Number("<<roll<<") Does Not Exist.\n"<<endl;
}


void DatabaseStats()
{
	if (databaseSize == 0)
	{
		cout<<"No Records Exist.\n"<<endl;
		return;
	}
    else
    {
        cout<<"\nSIZE: "<<databaseSize<<endl;
    }
    cout<<"\n\n"<<endl;
}


void Delete(int roll)
{
	for (int i = 0; i < databaseSize; i++)
		if (database[i].GetRoll() == roll)
		{
			database.erase(database.begin() + i);
			cout<<"\nStudent With Roll Number "<<roll<<" Has Been Removed From The Database\n"<<endl;
			databaseSize--;
			return;
		}

	cout<<"\nThe Entered Roll Number("<<roll<<") Does Not Exist In The Database.\n"<<endl;
}


int main()
{
	int choice, roll;
	cout<<"STUDENT RESULTS DATABASE"<<endl;
	cout<<"________________________"<<endl;

	do
	{
		cout <<endl<<"1. Add New Student" << endl;
		cout<<"2. Delete Student Data"<<endl;
		cout<<"3. Print Student Report Card"<<endl;
		cout<<"4. Database Statistics"<<endl;
		cout<<"0. Exit Program"<<endl;
		cout<<endl<<"YOUR CHOICE: ";
		cin>>choice;

		switch (choice)
		{
		case 1:
			AddData();
			break;

		case 2:
			cout<<"ROLL: ";
			cin>>roll;
			Delete(roll);
			break;

		case 3:
			cout<<"ROLL: ";
			cin>>roll;
			PrintReport(roll);
			break;

		case 4:
			DatabaseStats();
			break;

		case 0:
			break;

		default:
			cout<<"\nInavlid Respsonse. Please Try Again.\n"<<endl;
			break;
		}
	} while (choice);

	return 0;
}
