#include<iostream>
#include<string> 
#include<fstream>

#include"bibparser.h"
#include"database.h"


int main(int argc, char * argv[])
{


top:


	string filenm;
	int choice, sch,sch2,ech;
	string asearch, tsearch, ysearch;


	cout << "\n\n\n";
	cout << "WELCOME TO BIBTEX MANAGER" << endl;
	cout << "\n";
	cout << "PLEASE ENTER YOUR CHOICE:" << endl;
	cout << "PRESS 1.ADD A NEW BIBTEX TO THE DATABASE" << endl;
	cout << "PRESS 2.DISPLAY THE REFERENCE TABLE" << endl;
	cout << "PRESS 3.SEARCH FOR A REFERENCE FROM THE TABLE" << endl;
	cout << "PRESS 4.EXPORT REFERENCE" << endl;
	cout << "PRESS 5.QUIT" << endl;
	cin >> choice;


	if (choice == 1) //database entry
	{

		cout << "\nEnter the file name to be added in the database :";
		cin >> filenm;
		bibparser b;
		b.reader(filenm + ".txt");
		goto top;

	}
	else if (choice == 2) //display database 
	{
		cout << "CHOICE FOR DATABASE TO BE DISPLAYED" << endl;
		cout << "Press 1 for ARTICLE DATABASE" << endl;
		cout << "Press 2 for INPROCEEDING TABLE" << endl;
		cout << "Press 3 for BOOK TABLE" << endl;
		cout << "Press 4 for Export to a format" << endl;
		cout << "Press 5 to return to MAIN MENU" << endl;
		//cout << " Press 4 for all tables" << endl;
		cin >> sch;
		if (sch == 1)
		{
			cout << "	LIST OF ARTICLES" << endl;
			data::showarticletable();
			goto top;
		}
		else if (sch == 2)
		{
			cout << "	LIST OF INPROCEEDING" << endl;
			data::showinproceedingtable();
			goto top;

		}
		else if (sch == 3)
		{
			cout << "	LIST OF BOOKS" << endl;
			data::showbooktable();
			goto top;
		}
		else
			goto top;
	}
	else if (choice == 3) //search for a reference from the database
	{
		cout << "CHOICE FOR THE SEARCH TYPE:" << endl;
		cout << "Press 1 for search of AUTHOR" << endl;
		cout << "Press 2 for search of TITLE" << endl;
		cout << "Press 3 for search of YEAR of publication" << endl;
		cout << "Press 4 to go MAIN MENU" << endl;
		cin >> sch2;


		if (sch2 == 1)
		{
			cout << "Enter the author to search:" << endl;
			cin >> asearch;
			string aa = "author";
			data::searchdatabase(aa, asearch);
			goto top;

		}
		else if (sch2 == 2)
		{
			cout << "Enter the title to be search:" << endl;
			cin >> tsearch;
			string tt = "title";
			data::searchdatabase(tt, tsearch);
			goto top;
		}
		else if (sch2 == 3)
		{
			cout << "Enter the year of publication to be search" << endl;
			cin >> ysearch;
			string yy = "year";
			data::searchdatabase(yy, ysearch);
			goto top;
		}

		else
			goto top;
	}
	else if (choice == 4)
	{
		cout << "File export" << endl;
		cout << "PRESS 1 FOR APA FILE EXPORT"<<endl;
		cout << "PRESS 2 to go main menu" << endl;
		cin >> ech;

		if (ech == 1)
		{
			string filepath, titlename;
			cout << "Enter the title name to be exported" << endl;
			cin >> titlename;
			data::exportAPA(titlename);
		}
		else
			goto top;

	}

	else
		cout << "wrong coice" << endl;
	goto top;

	system("pause");

}