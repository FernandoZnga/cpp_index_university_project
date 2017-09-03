//
// Created by FernandoZuniga on 8/11/17.
//
#include    <iostream>
#include    <iomanip>
#include    <stdio.h>
#include    <string>
#include    <fstream>
#include    <stdlib.h>
#include    <string.h>
#include    "registro.h"


#ifndef UNTITLED_ADMINREGISTRO_H
#define UNTITLED_ADMINREGISTRO_H

class adminREGISTRO {

private:

    registro *registros;
    int     n;
    string  ruta;
public:

    //constructor
    adminREGISTRO   (string ruta)  {
        this    ->ruta  =   ruta;
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

    //funciones
    bool     existREGISTRO   (int    codREG)  {
        for (int i = 0; i < n; ++i) {
            if (registros[i].getCODIGO() == codREG)
                return true;
        }
        return false;
    }
    
    int     nextCODIGO  ()  {
        int nextCODE = 0;
        for (int i = 0; i < n; ++i) {
            if (nextCODE < registros[i].getCODIGO()) {
                nextCODE = registros[i].getCODIGO();
            }
        }
        return nextCODE+1;
    }
    
    int buscar (string campo, int  tipoBUSQUEDA)  {
        //tipoBUSQUEDA = 1 <- codigo
        //tipoBUSQUEDA = 2 <- apellido
        //tipoBUSQUEDA = 3 <- departamento
        int regEncontrados   =   0;
        for (int i = 0; i < n; ++i) {
            switch (tipoBUSQUEDA)   {
                case 1:
                    if (stoi(campo) == registros[i].getCODIGO()) {
                        if (regEncontrados == 0)
                            printHEAD();
                        printLINE(i + 1);
                        regEncontrados++;
                    }
                    break;
                case 2:
                    if (campo == registros[i].getAPELLIDO())  {
                        if (regEncontrados == 0)
                            printHEAD();
                        printLINE(i+1);
                        regEncontrados++;
                    }
                    break;
                case 3:
                    if (campo == registros[i].getDEPTO())  {
                        if (regEncontrados == 0)
                            printHEAD();
                        printLINE(i+1);
                        regEncontrados++;
                    }
                    break;
                default:
                    break;
            }
        }
        cout    <<"\t[Se encontraron "<<regEncontrados<<" registro/s coincidente/s]";
        return regEncontrados;
    }

    //manipulacipn de registros
    //agrega registros al arreglo de tipo 'registro'
    void    addREGISTROS     (registro   registros)  {
        this    ->  registros[n] =   registros;
        n++;
    }
    
    registro * getREGISTROS    ()  {
        return  this    ->  registros;
    }
    
    //borra logicamente o fisicamente, depediendo la variable op
    void    delREGISTROS     (int    pos, int   op)  {
        //op = 0 <- elimina permanentemente
        //op = 1 < elimina lógicamente

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
    
    //eliminar permanentemente un registro marcado como borrado logicamente
    void    delREGISTROSpermanente  ()  {
        registro *r;
        r  =   new registro[1500];
        int     p   =   0;
        for (int i = 0; i < n; i++) {
            if (registros[i].getFLAG() != 1) {
                r[p]    =   registros[i];
                p++;
            }
        }
        registros   ->~registro();
        //delete  (registro);
        this    ->  registros    =   r;
        cout    <<endl<<"\t\t["<<n-p<<" registros fueron ELIMINADOS permanentemente]"<<endl;
        n = p;
    }

    //restaura los registros que estaban eliminados logicamente
    void    restaurarREGISTROS  ()  {
        int p   =   0;
        for (int i = 0; i < n; ++i) {
            if (registros[i].getFLAG() == 1)  {
                registros[i].setFLAG(0);
                p++;
            }
        }
        cout    <<endl<<"\t\t["<<p<<" registros fueron RESTURADOS]"<<endl;
    }

    void    setREGISTROS    (int    pos,    registro r)  {
        if (pos>=0  &&  pos<n)
            registros[pos]  =   r;
    }
    //destructor
    ~adminREGISTRO  ()  {

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
    void read() {
        ifstream rd;
        string  linea;
        rd.open(ruta);
        n   =   0;
        while (getline(rd, linea)) {
            //getline(rd, linea);
            //cout    <<linea<<endl;
            addREGISTROS(registro
                                 (atoi(token(linea,",",1).c_str()),
                                  token(linea,",",2).c_str(),
                                  token(linea,",",3).c_str(),
                                  token(linea,",",4).c_str(),
                                  token(linea,",",5).c_str(),
                                  atoi(token(linea,",",6).c_str())
                                 )
                );
        }
        rd.close();
    }
    void write() {
        ofstream    wr;
        wr.open(ruta,ios::trunc);
        for (int i = 0; i < n; i++) {
            wr
                    <<registros[i].getCODIGO()<<","
                    <<registros[i].getAPELLIDO()<<","
                    <<registros[i].getFECHA()<<","
                    <<registros[i].getDEPTO()<<","
                    <<registros[i].getMONTO()<<","
                    <<registros[i].getFLAG()<<"\n";
        }
        wr.close();
    }

    //administrativos
    void printHEAD  ()  {
        cout    <<setw(10)<<"LINEA"<<setw(10)<<"CODIGO"<<setw(15)<<"APELLIDO"<<setw(10)<<"FECHA"<<setw(15)<<"DEPARTAMENTO"<<setw(15)<<"MONTO"<<setw(10)<<"FLAG"<<endl;
    }
    void    print   ()  {
        int contador = 0;
        for (int i = 0; i < n; ++i) {
            if (registros[i].getFLAG() == 0) {
                cout << setw(10) << i + 1;
                registros[i].print();
                contador++;
            }
        }
        cout    <<endl<<"\t\t[Se encontraron "<<contador<<" registros]"<<endl;
    }
    void    printELIMINADOS   ()  {
        int contador = 0;
        for (int i = 0; i < n; ++i) {
            if (registros[i].getFLAG() == 1) {
                cout << setw(10) << i + 1;
                registros[i].print();
                contador++;
            }
        }
        cout    <<endl<<"\t\t[Se encontraron "<<contador<<" registros]"<<endl;
    }
    void    printLINE   (int    pos)  {
        cout    <<setw(10)<<pos+1;
        registros[pos].print();
    }
    void    printALL   ()  {
        int contador = 0;
        cout    <<setw(10)<<"LINEA"<<setw(10)<<"CODIGO"<<setw(15)<<"APELLIDO"<<setw(10)<<"FECHA"<<setw(15)<<"DEPARTAMENTO"<<setw(15)<<"MONTO"<<setw(10)<<"FLAG_E"<<endl;
        for (int i = 0; i < n; ++i) {
            cout    <<setw(10)<<i+1;
            registros[i].printALL();
            contador++;
        }
        cout    <<endl<<"\t\t[Se encontraron "<<contador<<" registros]"<<endl;
    }
};


#endif //UNTITLED_ADMINREGISTRO_H
