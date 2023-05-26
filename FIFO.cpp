#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]){
    
    vector<int> paginas, ram;
    vector<int>::iterator it;
    
    int numQuadros, fail = 0;
    bool flag = true;
    string c;
    ifstream arq("file.txt");
    
    while(getline(arq, c)){

        if (flag){
            numQuadros = stoi(c);
            flag = false;
            continue;
        }

        paginas.push_back(stoi(c));
        
    }

    while (paginas.size()){

        // cout <<"Restante: " << paginas.size() << endl;
        flag = false;

        for (int i = 0; i < ram.size(); i++){

            if (paginas[0] == ram[i]){
                flag = true;
                break;
            }
        }
        
        if (!flag){
            if (ram.size() < numQuadros){

                ram.push_back(paginas[0]);
                paginas.erase(paginas.begin());

            }else{

                ram.erase(ram.begin());
                ram.push_back(paginas[0]);
                paginas.erase(paginas.begin());
            }
            
            fail++;

        }else{

            paginas.erase(paginas.begin());
        }
        
        // for (it = ram.begin(); it < ram.end(); it++){

        //     cout << "quadro: " << *it << endl;

        // }

    }

    cout << "FIFO "<< fail << endl;

    // cout << numQuadros << endl;
    // for (it = paginas.begin(); it < paginas.end(); it++)
    // {
    //     cout << *it << endl;
    // }
    

    return 0;
}
