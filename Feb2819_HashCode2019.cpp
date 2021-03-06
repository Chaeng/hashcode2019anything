// Feb2819_HashCode2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Picture.h"
#include "Slide.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
	using namespace std;
	char str[256];
	ifstream test;
	test.open("a_example.txt");

	test.getline(str, 1024);
	int size = atoi(str);

	vector<Picture> picArr;

	int index = 0;
	while (test.getline(str, 1024))
	{
		istringstream iss(str);

		string type;
		string numTags;

		iss >> type;
		Picture pic(index, type);

		iss >> numTags;
		int num_tags = stoi(numTags);		
		pic.addNumTags(num_tags);

		while (iss) {
			string tag;
			iss >> tag;
			pic.addTag(tag);
		}
		picArr.push_back(pic);
		index++;
	}

	vector<Slide> slideList;

	int curSlideID = 0;
	for (int i = 0; i < picArr.size(); i++) {

		if (picArr[i].getType() == "H") {
			
			Slide slide(curSlideID);
			slide.addPicture(picArr[i]);

			cout << "Hi! I am " << slide.getID() << "size " << slide.getTagsListSize() <<endl;
			//for(int i = 0; i < slide.getTagsListSize())
		}
		else {
			//cout << "Yo! I am " << picArr[i].getID() << endl;
			Slide slide(curSlideID);
			slide.addPicture(picArr[i]);
			slide.addPicture(picArr[i]);
			cout << "Yo! I am " << slide.getID() << "size " << slide.getTagsListSize() << endl;
			i++;
		}

		curSlideID++;
	}


	//cout << "tags : ";
	//Tags tags = pic.getTags();
	//for (int i = 0; i < tags.list.size(); i++) {
	//	cout << tags.list[i] << " ";
	//}
	//cout << endl;

	test.close();
	cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
