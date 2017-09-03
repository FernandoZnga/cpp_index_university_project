//
// Created by FernandoZuniga on 8/12/17.
//

#ifndef UNTITLED_ADMININDEX_H
#define UNTITLED_ADMININDEX_H

#include    <iostream>
#include    <string>
#include    <fstream>
#include    <stdlib.h>
#include    <string.h>
#include    "registro.h"
#include    "index.h"

using namespace std;

class adminINDEX {

    registro *registros;
    int     n;
    string  ruta;
    string  rutaFile;
public:

    //constructores
    adminINDEX   (string ruta)  {
        this    ->ruta  =   ruta;
        registros  =   new registro[1500];
        n       =   0;
    }
    adminINDEX   (string ruta,  string  rutaFile)  {
        this    ->ruta  =   ruta;
        this    ->rutaFile= rutaFile;
        registros  =   new registro[1500];
        n       =   0;
    }

    //variables simples
    void    setRUTA (string ruta)  {
        this    ->ruta  =   ruta;
    }
    string  getRUTA ()  {
        return this ->ruta;
    }
    int     getN    ()  {
        return  this    ->n;
    }

    //manipulacipn de registros
    void    addREGISTROS     (registro   registros)  {
        this    ->  registros[n] =   registros;
        n++;
    }

    /*void    addREGISTROS   (registro    registros)  {
        if (n != 0) {
            for (int i = 0; i < n; ++i) {
                if (registros.getCAMPO() < this    ->registros[i].getCAMPO()) {
                    insertarREGISTROindice(registros,i);
                    break;
                }
            }
        }
        this    ->  registros[n] =   registros;
        n++;
    }
    void    insertarREGISTROindice    (registro    registros,  int    pos)  {
        if (pos >= 0 && pos < n) {
            registro *r;
            r  =   new registro[1500];
            for (int i = n; i > pos; --i) {
                this    ->registros[i] = this   ->registros[i-1];
            }
            this    ->registros[pos]    =   registros;
            n++;
        }
    }*/
//---------------------------------

    registro * getREGISTROS    ()  {
        return  this    ->  registros;
    }
    
    //marca (borrado logico) un registro para posteriormente ser elimiando permanentemente (fisico)
    void    delREGISTROS     (int    pos, int   op)  {
        //op = 0 <- elimina permanentemente
        //op = 1 <- elimina lógicamente

        if (op == 0)   {
            if (pos >= 0 && pos < n) {
                registro *r;
                r  =   new registro[1500];
                int     p   =   0;
                for (int i = 0; i < n; i++) {
                    if (pos != i) {
                        r[p]    =   registros[i];
                        p++;
                    }
                }
                registros   ->~registro();
                //delete  (registro);
                this    ->  registros    =   r;
                n--;
            }
        }
        else
            registros[pos].setFLAG(1);
    }
    
    void    setREGISTROS    (int    pos,    registro r)  {
        if (pos>=0  &&  pos<n)
            registros[pos]  =   r;
    }
    //destructor
    ~adminINDEX  ()  {

    }

    //funciones
    //ordena de forma ascendente el archivo
    void burbuja    (bool integer)  {
        int comparaciones,intercambios;
        registro *r;
        r  =   new registro;
        for(int z = 1; z < n; ++z) {
            for(int v = 0; v < (n - z); ++v) {
                //comparaciones++;
                if (integer)   {
                    if(stoi(registros[v].getCAMPO()) > stoi(registros[v + 1].getCAMPO())) {
                        r[0] = registros[v];
                        registros[v] = registros[v + 1];
                        registros[v + 1] = r[0];
                        //intercambios++;
                    }
                }
                else    {
                    if(registros[v].getCAMPO() > registros[v + 1].getCAMPO()) {
                        r[0] = registros[v];
                        registros[v] = registros[v + 1];
                        registros[v + 1] = r[0];
                        //intercambios++;
                    }
                }

            }
        }
        write();
        cout    <<"\t\t[INDICE ORDENADO POR CAMPO]"<<endl;
    }

    //limpia el archivo de indice
    void eliminarIDX    ()  {
        ofstream    wr;
        wr.open(ruta,ios::trunc);
        wr  <<"";
        wr.close();
    }

    //leer y escribir
    string token(string cadena, string divisor, int pos) {
        if(cadena.size() > 0){
            char    oracion[cadena.size()];
            for (int i = 0;i <= cadena.size();i++)  {
                oracion[i] =   cadena[i];
            }
            char    *ptrtoken;
            int     num =   1;
            const   char*   d   =   divisor.c_str();
            ptrtoken    =   strtok(oracion , d);
            while   (ptrtoken)  {
                if(num == pos)  {
                    return  ptrtoken;
                }
                ptrtoken    =   strtok(NULL, d);
                num++;
            }
            return  "";
        }else   {
            return    "";
        }
    }
    void read   () {
        ifstream rd;
        string  linea;
        n   =   0;
        rd.open(ruta);
        while (getline(rd, linea)) {
            //getline(rd, linea);
            addREGISTROS(registro(atoi(token(linea,",",1).c_str()),
                                  token(linea,",",2).c_str(),
                                  atoi(token(linea,",",3).c_str())
                         )
            );
        }
        rd.close();
    }

    void crearIDX   (int    campoIndice)  {
        ifstream rd;
        string  linea;
        n   =   0;
        rd.open(rutaFile);
        while (getline(rd, linea)) {
            //getline(rd, linea);
            addREGISTROS(registro(
            campoIndice == 1 ? n : atoi(token(linea, ",", 1).c_str()),
                                  token(linea,",",campoIndice).c_str(),
                                  atoi(token(linea,",",6).c_str())
                         )
            );
        }
        //cout    <<"\t\t[INFORMACION CARGADA A MEMORIA]"<<endl;
    }
    void write() {
        ofstream    wr;
        wr.open(ruta,ios::trunc);
        for (int i = 0; i < n; i++) {
            wr
                    <<registros[i].getLN()<<","
                    <<registros[i].getCAMPO()<<","
                    <<registros[i].getFLAG()<<"\n";
        }
        wr.close();
        //cout    <<"\t\t[REGISTROS ALMACENADOS EN DISCO]"<<endl;
    }

    //administradores
    void printHEAD  ()  {
        cout    <<setw(10)<<"LINEA"<<setw(15)<<"CAMPO"<<setw(10)<<"FLAG_E"<<endl;
    }
    void    print   ()  {
        int contador    =0;
        for (int i = 0; i < n; ++i) {
            if (registros[i].getFLAG() == 0) {
                registros[i].printINDEX();
                contador++;
            }
        }
        cout    <<endl<<"\t\t[Se encontraron "<<contador<<" registros]"<<endl;
    }
    void    printELIMINADOS   ()  {
        int contador    =0;
        for (int i = 0; i < n; ++i) {
            if (registros[i].getFLAG() == 1) {
                registros[i].printINDEX();
                contador++;
            }
        }
        cout    <<endl<<"\t\t[Se encontraron "<<contador<<" registros]"<<endl;
    }
    void    printLINE   (int    pos)  {
        cout    <<setw(10)<<pos;
        registros[pos].print();
    }
    void    printALL   ()  {
        int contador = 0;
        cout    <<setw(10)<<"LINEA"<<setw(10)<<"CAMPO"<<setw(10)<<"FLAG_E"<<endl;
        for (int i = 0; i < n; ++i) {
            cout    <<setw(10)<<i+1;
            registros[i].printALL();
            contador++;
        }
        cout    <<endl<<"\t\t[Se encontraron "<<contador<<" registros]"<<endl;
    }
};


#endif //UNTITLED_ADMININDEX_H
