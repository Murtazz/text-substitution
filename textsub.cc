#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void replaceString(string &sent, const string &temp, const string &replacement) {
	size_t posFound = sent.find(temp);  // find the position where the find/temp starts
	int tmpSize = temp.length();   // length of temp string
	int rSize = replacement.length();
	while (!(posFound == string::npos)) {
		if (tmpSize == 0) break; 
		if (posFound >= 1) {
			if (sent[posFound-1] != ' ' && sent[posFound-1] != '\n' && sent[posFound-1] != '	')  { // check if the dictionary word is apart of another word
				break;
			}
		}
		if (sent[posFound+tmpSize] != ' ' && sent[posFound+tmpSize] != '\n' && sent[posFound+tmpSize] != '	' && (posFound+tmpSize) < sent.length()) { // check if the dictionary word is apart of another word
                        cout << posFound << endl;        
			break;
                }
		sent.replace(posFound, tmpSize, replacement); // replace the dic word with replacement
		posFound = sent.find(temp, posFound + rSize); // update the position
	}
}

void stringAssign(string &replace) {  // get the replacement word
        getline(cin, replace);
        replace.erase(0, 2);
}

int main() {
	string s, sentence; 
	string tmp1, rep1;
	string tmp2, rep2;
	string tmp3, rep3;
	string tmp4, rep4;
	string tmp5, rep5;
	string tmp6, rep6;
	string tmp7, rep7;
	string tmp8, rep8;
	string tmp9, rep9;
	string tmp10, rep10;  // up to 10 words
	while (true) {
		if (!(cin >> s)) {
			if (cin.eof()) break; // reached EOF
		}
		if (s == "-") {
			getline(cin, s);
			while (getline(cin, s)) { // get sentences with spaces
				sentence += s;   // add to the string 
				if (!(cin.peek() == EOF)) {
					sentence += "\n";  // add new line if there is more words on the next line
				} else {
					break;  // EOF so break
				}
			}
			replaceString(sentence, tmp1, rep1);  // run replaceString on the max 10 strings
			replaceString(sentence, tmp2, rep2);
			replaceString(sentence, tmp3, rep3);
			replaceString(sentence, tmp4, rep4);
			replaceString(sentence, tmp5, rep5);
			replaceString(sentence, tmp6, rep6);
			replaceString(sentence, tmp7, rep7);
			replaceString(sentence, tmp8, rep8);
			replaceString(sentence, tmp9, rep9);
			replaceString(sentence, tmp10, rep10);
		} else if (tmp1.empty()) { // assign the dictionary find and replace words
			tmp1 = s;
			stringAssign(rep1);
		} else if (tmp2.empty()) {
                        tmp2 = s;
                        stringAssign(rep2);
		} else if (tmp3.empty()) {
                        tmp3 = s;
                        stringAssign(rep3);
                } else if (tmp4.empty()) {
                        tmp4 = s;
                        stringAssign(rep4);
                } else if (tmp5.empty()) {
                        tmp5 = s;
                        stringAssign(rep5);
                } else if (tmp6.empty()) {
                        tmp6 = s;
                        stringAssign(rep6);
                } else if (tmp7.empty()) {
                        tmp7 = s;
                        stringAssign(rep7);
                } else if (tmp8.empty()) {
                        tmp8 = s;
                        stringAssign(rep8);
                } else if (tmp9.empty()) {
                        tmp9 = s;
                        stringAssign(rep9);
                } else if (tmp10.empty()) {
                        tmp10 = s;
                        stringAssign(rep10);
                } else {
			continue; // will not take more than 10 dictionary words
		}
	}
	cout << sentence << endl; // print the changed 
}
