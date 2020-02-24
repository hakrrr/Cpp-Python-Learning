#include "pch.h"
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

//int main() 
//{
//	//ifstream ifs("../TestInput/Input01.txt");		//../previous directory
//	//	if(ifs.fail())
//	//	{
//	//		printf("Failed to open file");
//	//		return 0;
//	//	}
//
//	//string input;
//	//getline(ifs, input);
//
//	//Init curl = currentline
//	string preamble, curl;
//	int n, q;
//	map<string, string> DB;
//
//	//Read N, Q
//	scanf_s("%d%d%*[\n]", &n, &q);
//
//	//N
//	for (size_t i = 0; i < n; i++)
//	{
//		//for each line store into curl
//		getline(cin, curl);
//		
//		//delete brackets >
//		curl.erase(curl.end() - 1);
//
//		//Now input is in form e.g. tag01 name1 = "1", name2 = "asd" || /tag1
//
//		//iterate through the words in curl
//		stringstream ss(curl);
//		string word;
//		getline(ss, word, ' ');		//Could be important
//
//		//branch into open/close tag
//		//case: open tag
//		if (word[1] != '/') 
//		{
//			//e.g. <tag01 name1 = "1", name2 = "asd" || <tag01
//			//Get Tagname
//			if (word[0] == '<')
//			{
//				word.erase(word.begin());
//				preamble.append(word + ".");
//				//check for attributes now (Form: name1 = "1" name2 = "a") and store them
//				while (getline(ss, word, ' ')) 
//				{
//					//name1 = "1"
//					string name = word;
//					//= "1"
//					getline(ss, word, ' ');
//					//"1" -> 1
//					getline(ss, word, ' ');
//					string value = word.substr(1, word.size() - 2);
//
//					string preamble_tag = preamble.substr(0, preamble.size() - 1);
//
//					//DB[preamble_tag + "~" + name] = value;
//					DB.insert({ preamble_tag + "~" + name , value });
//				}
//			}
//		}
//		//case: close tag
//		else
//		{
//		//Form e.g </tag01
//		//remove the .tagname from the preamble pos = size - word size - 1
//			int pos = preamble.size() - (word.size() - 1);
//			preamble.erase(pos, string::npos);
//		}
//
//	}
//
//	//Q
//	for (size_t i = 0; i < q; i++)
//	{
//		getline(cin, curl);
//		
//		if (DB.find(curl) != DB.end())
//			printf("%s\n", DB[curl].c_str());
//		else printf("Not Found!\n");
//	}
//	return 0;
//}