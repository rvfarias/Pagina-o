#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

void pag_FIFO(const vector<int> &data_arq, int numQuadros){

    vector<int> paginas, ram;
    vector<int>::iterator it;
    
    int fail = 0;
    bool flag;

    for (int i = 0; i < data_arq.size(); i++){
        paginas.push_back(data_arq[i]);
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
}

void pag_OTM(){

}

void pag_LRU(){

}

int main(int argc, char const *argv[]){
    
    vector<int> paginas;   
    ifstream arq("file.txt");
    string c;
    
    int numQuadros;
    bool flag = true;
    
    while(getline(arq, c)){

        if (flag){
            numQuadros = stoi(c);
            flag = false;
            continue;
        }

        paginas.push_back(stoi(c));
        
    }

    arq.close();



    return 0;
}
