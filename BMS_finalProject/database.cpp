#include"database.h"


using std::vector;
using data::articleRecord;
using data::inproceedingRecord;
using data::bookRecord;

vector <articleRecord>		adatabase;
vector <inproceedingRecord> inpdatabase;
vector <bookRecord>			bdatabase;


void data::addarticle(string title, string author, string journal, string volume, string number, string pages, string year, string publisher)
{
	articleRecord arecord = { title, author, journal, volume, number, pages, year, publisher };
	adatabase.push_back(arecord);
	cout << "Article Added to database" << endl;
}

void data::addinproceeding(string author, string booktitle, string title, string year, string volume, string number, string pages, string keywords, string doi, string ISSN, string month)
{
	inproceedingRecord precord = { author, booktitle, title, year, volume, number, pages, keywords, doi, ISSN, month };
	inpdatabase.push_back(precord);
	cout << "Inproceeding Added to database" << endl;

}

void data::addbook(string author, string title, string publisher, string year, string volume, string series, string address, string edition, string month, string note, string isbn)
{
	bookRecord brecord = { author, title, publisher, year, volume, series, address, edition, month, note, isbn };
	bdatabase.push_back(brecord);
	cout << "Book Added to database" << endl;
}



void data::showarticletable()
{
	cout << "ARTICLE DATABASE" << endl;
	cout << "title" << "\t" << "author" << "\t" << "journal" << "\t" << "volume" << "\t" << "number" << "\t" << "pages" << "\t" << "year" << "\t" << "publisher"<<endl;
	for (int i = 0; i < adatabase.size(); i++)
	{
		std::cout << adatabase[i].title << "\t" << adatabase[i].author << "\t" << adatabase[i].journal << "\t" << adatabase[i].volume << "\t" << adatabase[i].number << "\t" << adatabase[i].pages << "\t" << adatabase[i].year << "\t" << adatabase[i].publisher;
		return;
	}

}

void data::showinproceedingtable()
{
	cout << "INPROCEEDING DATABASE" << endl;
	for (int i = 0; i < inpdatabase.size(); i++)
	{
		cout << inpdatabase[i].author << "\t" << inpdatabase[i].booktitle << "\t" << inpdatabase[i].title << "\t" << inpdatabase[i].year << "\t" << inpdatabase[i].volume << "\t" << inpdatabase[i].number << "\t" << inpdatabase[i].pages << "\t" << inpdatabase[i].keyworks << "\t" << inpdatabase[i].doi << "\t" << inpdatabase[i].ISSN << "\t" << inpdatabase[i].month;
		return;
	}
}

void data::showbooktable()
{
	cout << "BOOK DATABASE" << endl;
	for (int i = 0; i < bdatabase.size(); i++)
	{
		cout << bdatabase[i].author << "\t" << bdatabase[i].title << "\t" << bdatabase[i].publisher << "\t" << bdatabase[i].year << "\t" << bdatabase[i].volume << "\t" << bdatabase[i].series << "\t" << bdatabase[i].address << "\t" << bdatabase[i].edition << "\t" << bdatabase[i].month << "\t" << bdatabase[i].note << "\t" << bdatabase[i].isbn;
		return;
	}
}




void data::searchdatabase(string tag, string S)
{
		data::searcharticletable(tag, S);
		data::searchinproceedingtable(tag, S);
		data::searchbooktable(tag, S);
		return;
}




void data::searcharticletable(string ta, string AS)
{
	if (ta == "author")
	{	
		string wholestring[20], findkey = " ";
		
		findkey = AS;

		
		for (int i = 0; i < adatabase.size(); i++)
		{
			wholestring[i] = adatabase[i].author;

			if(strstr(wholestring[i].c_str(),findkey.c_str()))
			//if(wholestring[i].find(findkey)!=string::npos)
			{
				cout << "\nAuthor found in Article table\n";
				std::cout << adatabase[i].title << "\t" << adatabase[i].author << "\t" << adatabase[i].journal << "\t" << adatabase[i].volume << "\t" << adatabase[i].number << "\t" << adatabase[i].pages << "\t" << adatabase[i].year << "\t" << adatabase[i].publisher;
			}
		}
		return;
	}
	else if (ta == "title")
	{
		for (int i = 0; i < adatabase.size(); i++)
		{
			if (adatabase[i].title == AS)
			{
				cout << "\nTitle found in Article table\n";
				std::cout << adatabase[i].title << "\t" << adatabase[i].author << "\t" << adatabase[i].journal << "\t" << adatabase[i].volume << "\t" << adatabase[i].number << "\t" << adatabase[i].pages << "\t" << adatabase[i].year << "\t" << adatabase[i].publisher;
			}
		}
		return;
	}
	else if (ta == "year")
	{
		for (int i = 0; i < adatabase.size(); i++)
		{
			if (adatabase[i].year == AS)
			{
				cout << "\nYear found in Article table\n";
				std::cout << adatabase[i].title << "\t" << adatabase[i].author << "\t" << adatabase[i].journal << "\t" << adatabase[i].volume << "\t" << adatabase[i].number << "\t" << adatabase[i].pages << "\t" << adatabase[i].year << "\t" << adatabase[i].publisher;
			}
		}
		return;
	}
	else
		cout << "\nNot found in article table" << endl;
}



void data::searchinproceedingtable(string ta, string AS)
{
	if (ta == "author")
	{
		string wholestring[20], findkey = " ";

		findkey = AS;


		for (int i = 0; i < inpdatabase.size(); i++)
		{
			wholestring[i] = inpdatabase[i].author;

			if (strstr(wholestring[i].c_str(), findkey.c_str()))
			{
				cout << "\nAuthor found in Article table\n";
				cout << inpdatabase[i].author << "\t" << inpdatabase[i].booktitle << "\t" << inpdatabase[i].title << "\t" << inpdatabase[i].year << "\t" << inpdatabase[i].volume << "\t" << inpdatabase[i].number << "\t" << inpdatabase[i].pages << "\t" << inpdatabase[i].keyworks << "\t" << inpdatabase[i].doi << "\t" << inpdatabase[i].ISSN << "\t" << inpdatabase[i].month;
			}
		}
	}
	else if (ta == "title")
	{
		for (int i = 0; i < inpdatabase.size(); i++)
		{
			if (inpdatabase[i].title == AS)
			{
				cout << "\nTitle found in Inproceeding table\n";
				cout << inpdatabase[i].author << "\t" << inpdatabase[i].booktitle << "\t" << inpdatabase[i].title << "\t" << inpdatabase[i].year << "\t" << inpdatabase[i].volume << "\t" << inpdatabase[i].number << "\t" << inpdatabase[i].pages << "\t" << inpdatabase[i].keyworks << "\t" << inpdatabase[i].doi << "\t" << inpdatabase[i].ISSN << "\t" << inpdatabase[i].month;
			}
		}
	}
	else if (ta == "author")
	{
		for (int i = 0; i < inpdatabase.size(); i++)
		{
			if (inpdatabase[i].year == AS)
			{
				cout << "\nYear found in Inproceeding table\n";
				cout << inpdatabase[i].author << "\t" << inpdatabase[i].booktitle << "\t" << inpdatabase[i].title << "\t" << inpdatabase[i].year << "\t" << inpdatabase[i].volume << "\t" << inpdatabase[i].number << "\t" << inpdatabase[i].pages << "\t" << inpdatabase[i].keyworks << "\t" << inpdatabase[i].doi << "\t" << inpdatabase[i].ISSN << "\t" << inpdatabase[i].month;
			}
		}
	}
	else
		cout << "\nNot found in inproceeding table" << endl;
}




void data::searchbooktable(string ta, string AS)
{
	if (ta == "author")
	{
		string wholestring[20], findkey = " ";

		findkey = AS;


		for (int i = 0; i < bdatabase.size(); i++)
		{
			wholestring[i] = bdatabase[i].author;

			if (strstr(wholestring[i].c_str(), findkey.c_str()))
			{
				cout << "\nAuthor found in Book table\n";
				cout << bdatabase[i].author << "\t" << bdatabase[i].title << "\t" << bdatabase[i].publisher << "\t" << bdatabase[i].year << "\t" << bdatabase[i].volume << "\t" << bdatabase[i].series << "\t" << bdatabase[i].address << "\t" << bdatabase[i].edition << "\t" << bdatabase[i].month << "\t" << bdatabase[i].note << "\t" << bdatabase[i].isbn;

			}
		}
	}
	else if (ta == "title")
	{
		for (int i = 0; i < bdatabase.size(); i++)
		{
			if (bdatabase[i].title == AS)
			{
				cout << "\nTitle found in book table\n";
				cout << bdatabase[i].author << "\t" << bdatabase[i].title << "\t" << bdatabase[i].publisher << "\t" << bdatabase[i].year << "\t" << bdatabase[i].volume << "\t" << bdatabase[i].series << "\t" << bdatabase[i].address << "\t" << bdatabase[i].edition << "\t" << bdatabase[i].month << "\t" << bdatabase[i].note << "\t" << bdatabase[i].isbn;
			}
		}
	}
	else if (ta == "author")
	{
		for (int i = 0; i < bdatabase.size(); i++)
		{
			if (bdatabase[i].year == AS)
			{
				cout << "\nYear found in book table\n";
				cout << bdatabase[i].author << "\t" << bdatabase[i].title << "\t" << bdatabase[i].publisher << "\t" << bdatabase[i].year << "\t" << bdatabase[i].volume << "\t" << bdatabase[i].series << "\t" << bdatabase[i].address << "\t" << bdatabase[i].edition << "\t" << bdatabase[i].month << "\t" << bdatabase[i].note << "\t" << bdatabase[i].isbn;
			}
		}
	}
	else
		cout << "\nNot found in book table" << endl;
}


void data::exportAPA(string tx)
{
	
	string current=" ";
	
	for (int i = 0; i < adatabase.size(); i++) 
	{
		if (adatabase[i].title == tx)
		{
			current = adatabase[i].author + ". (" + adatabase[i].year + "). " + adatabase[i].title + "." + adatabase[i].journal + "," + adatabase[i].volume + "(" + adatabase[i].number + "), " + adatabase[i].pages;
		}
	}
	/*	for (int i=0;i< inpdatabase.size();i++)
			if (inpdatabase[i].title == tx)
			{

			}
		for (int i = 0; i < bdatabase.size(); i++)
		{

		}
		*/
	cout <<"current" <<current;
	std::ofstream outFile("saveAPA.txt");
	//outFile.open(filepath);
	outFile << current << endl;
	outFile.close();
	cout << "Saved database to file.\n";
	return;
}

