#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]){
    
    vector<int> paginas, pag_usadas,ram;
    vector<int>::iterator it, it2;
    
    int numQuadros, aux1, aux2, fail = 0;
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
                
                if (!pag_usadas.size()){

                   for (int  i = 0; i <= paginas[0]; i++)
                        pag_usadas.push_back(0);

                   pag_usadas[paginas[0]]++;

                }else{

                    if (paginas[0] > pag_usadas.size()){
                        for (int  i = pag_usadas.size(); i < paginas[0]; i++)
                            pag_usadas.push_back(0);

                        pag_usadas[paginas[0]]++;    
                    }

                    else if (paginas[0] < pag_usadas.size()){
                        pag_usadas[paginas[0]]++;
                    
                    }else{
                        pag_usadas.push_back(0);
                        pag_usadas[paginas[0]]++;

                    }
                }
                
                paginas.erase(paginas.begin());

            }else{
                
                aux1 = pag_usadas[ram[0]];
                aux2 = 0;
                for (int i = 1; i < ram.size(); i++){                
                    
                    if (pag_usadas[ram[i]] < aux1){
        
                        aux1 = pag_usadas[ram[i]];
                        aux2 = i;
                    }

                }
                cout << "troca: " << ram[aux2] << " por " << paginas[0] << endl; 

                ram.erase(ram.begin()+ aux2);
                ram.push_back(paginas[0]);

                if (paginas[0] > pag_usadas.size()){
                    for (int  i = pag_usadas.size(); i < paginas[0]; i++)
                        pag_usadas.push_back(0);
                        pag_usadas[paginas[0]]++;    
                    }

                else if (paginas[0] < pag_usadas.size()){
                    pag_usadas[paginas[0]]++;
                    
                }else{

                    pag_usadas.push_back(0);
                    pag_usadas[paginas[0]]++;

                }
                
                paginas.erase(paginas.begin());
            }
            
            fail++;

        }else{

            pag_usadas[paginas[0]]++;            
            paginas.erase(paginas.begin());
        }
        
        // for (it = ram.begin(); it < ram.end(); it++){

        //     cout << "quadro: " << *it << endl;

        // }
        // aux1 = 0;
        // for (it2 = pag_usadas.begin(); it2 < pag_usadas.end(); it2++){

        //     cout << "pag_usadas: " << aux1 << " quant " << *it2 << endl;
        //     aux1++;
        // }

    }

    cout << "LRU "<< fail << endl;

    // cout << numQuadros << endl;
    // for (it = paginas.begin(); it < paginas.end(); it++)
    // {
    //     cout << *it << endl;
    // }
    

    return 0;
}
