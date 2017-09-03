//
// Created by FernandoZuniga on 8/11/17.
//

#ifndef UNTITLED_REGISTRO_H
#define UNTITLED_REGISTRO_H

#include    <stdio.h>
#include    <string>
#include    <iomanip>
#include    <iostream>

using namespace std;

class registro {
private:

    int codigo;
    string  apellido;
    string  fecha;
    string  depto;
    string  monto;
    int     flag;
    string  campo;
    int     ln;

public:

    //constructores
    registro    ()  {
    }
    registro    (int codigo, string apellido,   string  fecha, string  depto, string monto)  {
        this    ->codigo  =   codigo;
        this    ->apellido=   apellido;
        this    ->fecha   =   fecha;
        this    ->depto   =   depto;
        this    ->monto   =   monto;
    }
    registro    (int codigo, string apellido,   string  fecha, string  depto, string monto, int   flag)  {
        this    ->codigo  =   codigo;
        this    ->apellido=   apellido;
        this    ->fecha   =   fecha;
        this    ->depto   =   depto;
        this    ->monto   =   monto;
        this    ->flag      =   flag;
    }
    registro    (int    ln, string campo, int   flag)  {
        this    ->ln        =   ln;
        this    ->campo     =   campo;
        this    ->flag      =   flag;
    }
    //acceso
    void    setCODIGO   (int codigo)  {
        this    ->codigo    =   codigo;
    }
    int     getCODIGO   ()  {
        return this ->codigo;
    }
    void    setAPELLIDO (string apellido)  {
        this    ->apellido  =   apellido;
    }
    string  getAPELLIDO ()  {
        return this ->apellido;
    }
    void    setFECHA    (string fecha)  {
        this    ->fecha =   fecha;
    }
    string  getFECHA    ()  {
        return  this    ->fecha;
    }
    void    setDEPTO    (string depto)  {
        this    ->depto =   depto;
    }
    string  getDEPTO    ()  {
        return  this    ->depto;
    }
    void    setMONTO    (string  monto)  {
        this    ->monto =   monto;
    }
    string  getMONTO    ()  {
        return  this    ->monto;
    }
    void    setFLAG     (int flag)  {
        this    ->flag  =   flag;
    }
    int     getFLAG     ()  {
        return  this    ->flag;
    }
    void    setLN       (int    ln)  {
        this    ->ln    =   ln;
    }
    int     getLN       ()  {
        return  this    ->ln;
    }
    void    setCAMPO    (string campo)  {
        this    ->campo =   campo;
    }
    string  getCAMPO    ()  {
        return  this    ->campo;
    }

    //administrativo
    void print  ()  {
        cout    <<setw(10)<<codigo<<setw(15)<<apellido<<setw(10)<<fecha<<setw(15)<<depto<<setw(15)<<monto<<setw(10)<<flag<<endl;
    }
    void printALL   ()  {
        cout    <<setw(10)<<codigo<<setw(15)<<apellido<<setw(10)<<fecha<<setw(15)<<depto<<setw(15)<<monto<<setw(10)<<flag<<endl;
    }
    void printINDEX ()  {
        cout    <<setw(10)<<ln<<setw(15)<<campo<<setw(10)<<flag<<endl;
    }

    //destructor
    ~registro() {
    };
};

#endif //UNTITLED_REGISTRO_H
