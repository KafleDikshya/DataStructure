#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const int INITIAL_LIST_CAPACITY = 10;

void build_wordlist (string* &word_list, int& capacity, string filename) {

    ifstream words;
    string word;
    int size = 0;

    word_list = new string[INITIAL_LIST_CAPACITY];
    capacity = INITIAL_LIST_CAPACITY;

   
    words.open (filename.c_str());

    if (!words) {
        cerr << "Could not open " << filename << endl;
        exit(EXIT_FAILURE);
    }

    words >> word;
    while (! words.eof()) {


        if (size > (capacity - 1)) {

      
            string *new_word_list = new string[2 * capacity];

           
            for (int index = 0; (index < capacity); index++) {
                new_word_list[index] = word_list[index];
            }

            delete [] word_list;
            word_list = new_word_list;

            capacity *= 2;
        }

        word_list[size] = word;
        size++;

       
        words >> word;
    }

    words.close();
}

int main (int argc, char *argv[]) {

   
    string *word_list = 0;
    int capacity = 0;

   
    build_wordlist (word_list, capacity, "words.txt");


    for (int index = 0; (index < capacity) && (word_list[index] != "");
            index++) {
        cout << word_list[index] << endl;
    }

    return EXIT_SUCCESS;
}
