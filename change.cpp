#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

void help(){
    std::cout << "Use\n\tchangefile source_file distination_file\n";
    std::cout << " -L - to lower case\n";
    std::cout << " -U - to upper case\n";
    std::cout << " -G - to toggle case\n";
    std::cout << " -T - to title case\n";
}

void toggle_case(std::ifstream & inFile, std::ofstream & outFile){
    int ch;
    while ( (ch=inFile.get()) != EOF){
            if (ch>='a' && ch<='z'){
                ch= ch - 'a' + 'A';
            }
            else if(ch>='A' && ch <= 'Z'){
                ch = (ch - 'A') + 'a';
            }
            outFile.put(ch);
    }
}

void to_lower_case(std::ifstream & inFile, std::ofstream & outFile){
    int ch;
    while ( (ch=inFile.get()) != EOF){
            if(ch>='A' && ch <= 'Z'){
                ch = (ch - 'A') + 'a';
            }
            outFile.put(ch);
    }
}

void to_upper_case(std::ifstream & inFile, std::ofstream & outFile){
    int ch;
    while ( (ch=inFile.get()) != EOF){
            if (ch>='a' && ch<='z'){
                ch= ch - 'a' + 'A';
            }
            outFile.put(ch);
    }
}

void title_case(std::ifstream & inFile, std::ofstream & outFile){
    int ch;
    bool flag;
    ch= inFile.get();
    if (ch>='a' && ch<='z'){
        ch= ch - 'a' + 'A';
    }
    outFile.put(ch);
    while ( (ch=inFile.get()) != EOF){
        if(ch>='A' && ch <= 'Z'){
            ch = (ch - 'A') + 'a';
        }
        if (flag == 1){
            flag = 0;
            if (ch>='a' && ch<='z'){
                ch= ch - 'a' + 'A';
            }
        }
        else if ( ch == '\n' || ch == ' '){
            flag = 1;
        }
        outFile.put(ch);
    }
}

void random_case(std::ifstream & inFile, std::ofstream & outFile){
    int ch;
    bool n;
    while ( (ch=inFile.get()) != EOF){
        if ((ch>='a' && ch<='z')){
            n= rand() % 2;
            if (n == 0){
                ch= ch - 'a' + 'A';
            }
        }
        if ((ch>='A' && ch <= 'Z')){
            n= rand() % 2;
            if (n == 0){
                ch = (ch - 'A') + 'a';
            }
        }
        outFile.put(ch);
    }
}



int main(int argc, char* argv[]){
    if (argc != 4){
        help();
        return 0;
    }
    const char* inputfilename = argv[2];
    const char* outputfilename = argv[3];
    
    std::ifstream inFile;
    inFile.open(inputfilename, std::ios_base::binary);
    if (!inFile){ // Если файл не открылся
        std::cout << "Can not open file" << inputfilename << "\n";
        return 1;
    }
    std::ofstream outFile;
    outFile.open(outputfilename, std::ios_base::binary);
    if (!outFile){
        std::cout << "Can not open file" << outputfilename << "\n";
        inFile.close();
        return 2;
    }

    if (strcmp(argv[1], "-L") == 0){
        to_lower_case(inFile, outFile);
    }
    else if (strcmp(argv[1], "-U") == 0){
        to_upper_case(inFile, outFile);
    }
    else if (strcmp(argv[1], "-G") == 0){
        toggle_case(inFile, outFile);
    }
    else if(strcmp(argv[1], "-T") == 0){
        title_case(inFile, outFile);
    }
    else if(strcmp(argv[1], "-R") == 0){
        random_case(inFile, outFile);
    }
    else{
        help();
    }


    inFile.close();
    outFile.close();
    return 0;
}