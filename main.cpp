#include "headers.h"


int main() {

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
}
