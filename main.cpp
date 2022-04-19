#include "headers.h"

string generate(int max_length) {
    string possible_characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<> dist(0, possible_characters.size() - 1);
    string ret = "";
    for (int i = 0; i < max_length; i++) {
        int random_index = dist(engine); //get index between 0 and possible_characters.size()-1
        ret += possible_characters[random_index];
    }
    return ret;
}

int main() {

    if (Autotest() != 1) {
        cerr << "Error! Tests not passed!" << endl;
        return -1;
    }

    try {

        int lenght1 = 10000000;
        int lenght2 = 10000000;

        string str1 = generate(lenght1);
        string str2 = generate(lenght2);

        char* data1 = new char[lenght1];
        char* data2 = new char[lenght2];
        for (int i = 0; i < lenght1; i++) {
            data1[i] = str1[i];
        }
        for (int i = 0; i < lenght2; i++) {
            data2[i] = str2[i];
        }

        CString0 c1("out2_1.txt", data1, lenght1);
        CString1 c2("out2_2.txt", data2, lenght2);


        CString0 d;
        chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();

        d = c1 + c2;

        chrono::time_point<chrono::system_clock> end = chrono::system_clock::now();
        int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
        cout << "Addition operator runtime is " << elapsed_ms << " ms\n";


        



        cout << endl << "Done!" << endl;
        return 0;
    }

    catch (const exception& e) {
        cerr << "Error! " << e.what() << endl;
        return 1;
    }
}



/*int main() {

    if (Autotest() != 1) {
    	cerr << "Error! Tests not passed!" << endl;
    	return -1;
    }

    try {
        //string fileName = "file.txt";
        int s = 0; // Количество строк в файле
        string fileName = "test3.txt";
        // cout << "Enter fileName ... ";
        // cin >> fileName;

        ifstream inputFile(fileName);
        if (!inputFile) {
            cerr << "\nError: file not found!" << endl;
            return -1;
        }

        string line;
        while (getline(inputFile, line)) //Узнаем сколько строк в файле
            s ++ ;
        inputFile.close();

        vector<CString*> vec;
        map<string, Factory*> factoryMap;
        factoryMap["hori"] = new Factory_hori;
        factoryMap["vert"] = new Factory_vert;
        // CString** arr = (CString**)malloc(sizeof(CString*)*s);


        int i = 0;
        string inputString;

        inputFile.open(fileName);
        while (getline(inputFile, inputString)) {
            stringstream temp(inputString);
            string type;
            string outputFilename;
            string data;

            temp >> type >> outputFilename >> data;

            int dataSize = data.length();
            //char *cstr = new char[dataSize + 1];
            //strcpy_s(cstr, data.c_str());
            //for (int k = 0; k < dataSize; k++) {
             //   cstr[k] = data[k];
            //}

            auto Creator = factoryMap.find(type);
            if (Creator == factoryMap.end())
                throw runtime_error("There is no such class!");
            vec.push_back(Creator->second->create(outputFilename, data.c_str(), dataSize));


           // delete [] cstr;
            i++;
        }
        inputFile.close();
        
        CString0 d;
        std::chrono::time_point<std::chrono::system_clock> start =
            std::chrono::system_clock::now();
        for (auto i : vec) {
           d=d+(*i);
        }
        std::chrono::time_point<std::chrono::system_clock> end =
            std::chrono::system_clock::now();
        int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
        std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";


        //auto a = &vec[0];
        //auto b = &vec[1];
        //auto c = a + b;
        

        for (auto i : vec)
            delete i;

        cout << endl << "Done!" << endl;
        return 0;
    }

    catch (const exception& e) {
        cerr << "Error! " << e.what() << endl;
        return 1;
    }
}*/
