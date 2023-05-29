#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

//Implementação do FIFO
void pag_FIFO(const vector<int> &data_arq, int numQuadros){

    //Declaracao de variaveis
    vector<int> paginas, ram;
    vector<int>::iterator it;
    
    int fail = 0;
    bool flag;

    //Copiando dados do arquivo para poder manipular
    for (int i = 0; i < data_arq.size(); i++){
        paginas.push_back(data_arq[i]);
    }
    
    //Loop de execucao
    while (paginas.size()){

        // cout <<"Restante: " << paginas.size() << endl;
        flag = false;
        
        //Verificando se a página já está na ram
        for (int i = 0; i < ram.size(); i++){
            //Se estiver seta a flag pra true
            if (paginas[0] == ram[i]){
                flag = true;
                break;
            }
        }
        
        //Caso a página não esteja na ram
        if (!flag){
            //E ainda tiver espaço livre 
            if (ram.size() < numQuadros){
                //Adiciona a pagina na ram e apaga a mesma do array de paginas 
                ram.push_back(paginas[0]);
                paginas.erase(paginas.begin());

            }else{
                //Se não tiver espaço tira o primeiro elemento da ram e adiciona o novo elemento no final do array
                ram.erase(ram.begin());
                ram.push_back(paginas[0]);
                paginas.erase(paginas.begin());
            }

            //Incrementa o numero de falhas 
            fail++;

        }else{
            //Se a página estiver na ram,apenas apagamos ela do array de páginas 
            paginas.erase(paginas.begin());
        }
        
    }

    //Printa o numero de falhas
    cout << "FIFO "<< fail << endl;

}

//Implementação do OTM
void pag_OTM(const vector<int> &data_arq, int numQuadros){

    //Declaracao de variaveis
    vector<int> paginas, ram;
    vector<int>::iterator it;

    int aux1, aux2;
    int fail = 0;
    bool flag;

    //Copiando dados do arquivo para poder manipular
    for (int i = 0; i < data_arq.size(); i++){
        paginas.push_back(data_arq[i]);
    }

    //Loop de execucao
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

                if (paginas.size() <= ram.size()){

                    for (int i = 0; i < ram.size(); i++){     
                        flag = false;
                        for (int j = 0; j < paginas.size(); j++){
                            if (ram[i] == paginas[j]){
                                flag =true;
                            }
                            
                        }

                        if (!flag){
                            aux2 = i;
                            break;
                        }
                        
                    }
                
                }else{

                    aux1 = -1;
                    for (int i = 0; i < ram.size(); i++){                
                        for (int j = 0; j < paginas.size(); j++){
                            if (ram[i] == paginas[j] && aux1 < j){
                                // cout << "old: " << aux2 << endl; 

                                aux1 = j;
                                aux2 = i;
                                // cout << "new: " << aux2 << endl;
                                break;
                            }
                            
                        }
                    }
                    // cout << "troca: " << ram[aux2] << " por " << paginas[0] << endl; 
                }
                
                

                
                ram.erase(ram.begin()+ aux2);
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

    cout << "OTM "<< fail << endl;

    
}

//Implementação do LRU
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

    pag_FIFO(paginas, numQuadros);

    return 0;
}
