
//Codigo hecho por Jose Blanco Fleury ©

#include<iostream>
#include<unistd.h>

using namespace std;


void mostrarTablero(char tablero[6][7]){
    cout<<"\n0 1 2 3 4 5 6"<<endl;
    cout<<" | | | | | |"<<endl<<endl;
    
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            cout<<tablero[i][j]<<" ";
        }
        cout<<endl;
    }
}

//Funcion para ingresar la ficha X en la columna deseada por el usuario

void ingresarFichaX(char tablero[6][7]){
    cout << "Turno de la ficha 'X'" << endl;
    
    int contador=0;
    int columna;
    inicioFichaX:
    cout<<"Ingrese la columna donde desea colocar su ficha: ";
    if (!(cin >> columna)) { // Validar si el valor ingresado no es un número
        cout << "Debe ingresar un numero entero." << endl;
        cin.clear(); // Limpiar la bandera de error del cin
        cin.ignore(10000, '\n'); // Ignorar los caracteres no válidos ingresados por el usuario
        goto inicioFichaX; // Saltar al inicio del ciclo
    }

    if (columna < 0 || columna > 6) { // Validar si el valor ingresado está dentro del rango permitido
        cout << "Debe ingresar un numero entre 0 y 6." << endl;
        goto inicioFichaX; // Saltar al inicio del ciclo
    }

    for(int i=5;i>=0;i--){
        if(tablero[i][columna] == '#'){
            contador ++;
        }
    }

    if(contador == 0){
        cout<<"La columna esta llena, ingrese otra columna" << endl;
        goto inicioFichaX;
    }else{
        for(int i=5;i>=0;i--){
            if(tablero[i][columna] == '#'){
                tablero[i][columna]='X';
                break;
            }
        }
    }
}


//Funcion para ingresar la ficha O en la columna deseada por el usuario

void ingresarFichaO(char tablero[6][7]){
    cout << "Turno de la ficha 'O'" << endl;
    
    int contador=0;
    int columna;
    inicioFichaO:
    cout<<"Ingrese la columna donde desea colocar su ficha: ";
    if (!(cin >> columna)) {
        cout << "Debe ingresar un numero entero." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto inicioFichaO;
    }

    if (columna < 0 || columna > 6) {
        cout << "Debe ingresar un numero entre 0 y 6." << endl;
        goto inicioFichaO;
    }

    for(int i=5;i>=0;i--){
        if(tablero[i][columna] == '#'){
            contador ++;
        }
    }

    if(contador == 0){
        cout<<"La columna esta llena, ingrese otra columna" << endl;
        goto inicioFichaO;
    }else{
        for(int i=5;i>=0;i--){
            if(tablero[i][columna] == '#'){
                tablero[i][columna]='O';
                break;
            }
        }
    }
}


bool verificarGanadorX(char tablero[6][7]){
    //Verificar si hay 4 fichas consecutivas en horizontal
    for(int i=0;i<6;i++){
        for(int j=0;j<4;j++){
            if(tablero[i][j] == 'X' && tablero[i][j+1] == 'X' && tablero[i][j+2] == 'X' && tablero[i][j+3] == 'X'){
                return true;
            }
        }
    }

    //Verificar si hay 4 fichas consecutivas en vertical
    for(int i=0;i<3;i++){
        for(int j=0;j<7;j++){
            if(tablero[i][j] == 'X' && tablero[i+1][j] == 'X' && tablero[i+2][j] == 'X' && tablero[i+3][j] == 'X'){
                return true;
            }
        }
    }

    //Verificar si hay 4 en diagonal derecha a izquierda
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(tablero[i][j] == 'X' && tablero[i+1][j+1] == 'X' && tablero[i+2][j+2] == 'X' && tablero[i+3][j+3] == 'X'){
                return true;
            }
        }
    }

    //Verificar si hay 4 fichas en diagonal izquierda a derecha
    for(int i=0;i<3;i++){
        for(int j=3;j<7;j++){
            if(tablero[i][j] == 'X' && tablero[i+1][j-1] == 'X' && tablero[i+2][j-2] == 'X' && tablero[i+3][j-3] == 'X'){
                return true;
            }
        }
    }

    return false;
}
bool verificarGanadorO(char tablero[6][7]){
    //Verificar si hay 4 fichas consecutivas en horizontal
    for(int i=0;i<6;i++){
        for(int j=0;j<4;j++){
            if(tablero[i][j] == 'O' && tablero[i][j+1] == 'O' && tablero[i][j+2] == 'O' && tablero[i][j+3] == 'O'){
                return true;
            }
        }
    }

    //Verificar si hay 4 fichas consecutivas en vertical
    for(int i=0;i<3;i++){
        for(int j=0;j<7;j++){
            if(tablero[i][j] == 'O' && tablero[i+1][j] == 'O' && tablero[i+2][j] == 'O' && tablero[i+3][j] == 'O'){
                return true;
            }
        }
    }

    //Verificar si hay 4 fichas en diagonal de derecha a izquierda
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(tablero[i][j] == 'O' && tablero[i+1][j+1] == 'O' && tablero[i+2][j+2] == 'O' && tablero[i+3][j+3] == 'O'){
                return true;
            }
        }
    }

    //Verificar si hay 4 fichas en diagonal izquierda a derecha
    for(int i=0;i<3;i++){
        for(int j=3;j<7;j++){
            if(tablero[i][j] == 'O' && tablero[i+1][j-1] == 'O' && tablero[i+2][j-2] == 'O' && tablero[i+3][j-3] == 'O'){
                return true;
            }
        }
    }

    return false;
}




int main(){
    char tablero[6][7];

    cout<<"    ###                                        ###       ##"<<endl;
    cout<<"   ####                                         ##"<<endl;
    cout<<"  ## ##             ####    #####               ##      ###     #####     ####     ####"<<endl;
    cout<<" ##  ##            ##  ##   ##  ##              ##       ##     ##  ##   ##  ##       ##"<<endl;
    cout<<" #######           ######   ##  ##              ##       ##     ##  ##   ######    #####"<<endl;
    cout<<"     ##            ##       ##  ##              ##       ##     ##  ##   ##       ##  ##"<<endl;
    cout<<"     ##             #####   ##  ##             ####     ####    ##  ##    #####    #####"<<endl<<endl;


    cout<<"Bienvenido al juego de 4 en linea!"<<endl;
    cout<<"----------------------------------"<<endl<<endl;

    cout<<"Gana el jugador que logre colocar 4 fichas en linea horizontal, vertical o diagonal."<<endl;
    cout<<"En caso de empate, el juego termina."<<endl<<endl;

    int empezar;
    cout<<"[1] Para comenzar"<<endl;
    cout<<"[2] Para salir"<<endl;
    cout<<">>";cin>>empezar;
    if (empezar == 2){
        cout<<"Saliendo...";
        sleep(1);
        return 0;
    }

    cout<<"Comenzando el juego..."<<endl<<endl;
    sleep(1);

    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            tablero[i][j]='#';
        }
    }
    
    
    mostrarTablero(tablero);

    while(true){
        //Verificar si el tablero esta lleno
        int contador=0;
        for(int i=0;i<6;i++){
            for(int j=0;j<7;j++){
                if(tablero[i][j] == '#'){
                    contador++;
                }
            }
        }
        if(contador == 0){
            cout<<"Empate!"<<endl;
            break;
        }else{
            ingresarFichaX(tablero);
            mostrarTablero(tablero);
            
            if(verificarGanadorX(tablero)){
                cout<<"Jugador X ganador!"<<endl;
                break;
            }

            ingresarFichaO(tablero);
            mostrarTablero(tablero);
            
            if(verificarGanadorO(tablero)){
                cout<<"Jugador O ganador!"<<endl;
                break;
            }
        }
 
        
    }
    return 0;
}
