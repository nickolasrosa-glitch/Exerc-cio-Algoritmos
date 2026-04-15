#include <iostream>
#include <string>
using namespace std;

float calcularMedia(float y, float x, float z) {
    return (y + x + z) / 3;
}

int main() {
    string nome[5];
    float m1[5], m2[5], m3[5], media[5];
    int i, quant;
   
    cout << "Quantos alunos gostaria de cadasttrar (No Maximo 5): ";
    cin >> quant;
   
    if(quant > 5) quant = 5;
    if(quant < 1) quant = 1;
   
    for(i = 0; i < quant; i++) {
        cout << "\nNome do aluno " << (i+1) << ": ";
        cin.ignore();                    
        getline(cin, nome[i]);
       
        cout << "Digite as 3 notas de " << nome[i] << ": ";
        cin >> m1[i] >> m2[i] >> m3[i];
       
        media[i] = calcularMedia(m1[i], m2[i], m3[i]);
    }
   
    cout << "\nALUNO          M1      M2      M3      MEDIA    Reprovado ou Aprovado\n";
    cout << "------------------------------------------------------------\n";
   
    for(i = 0; i < quant; i++) {
        cout << nome[i];
        if(nome[i].length() < 15) cout << string(15 - nome[i].length(), ' ');
       
        cout << m1[i] << "       " 
             << m2[i] << "       " 
             << m3[i] << "       " 
             << media[i] << "       ";
        
        if(media[i] >= 7) {
            cout << "Aprovado\n";
        } else {
            cout << "Reprovado\n";
        }
    }
   
    int maior = 0;
    for(i = 1; i < quant; i++) {
        if(media[i] > media[maior]) {
            maior = i;
        }
    }
   
    cout << "\nAluno com maior media: " << nome[maior]
         << " (" << media[maior] << ")\n";
   
    return 0;
}
