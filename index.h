//
// Created by FernandoZuniga on 8/12/17.
//

#ifndef UNTITLED_INDEX_H
#define UNTITLED_INDEX_H

#include    <stdio.h>
#include    "string"
#include    <iomanip>
#include    <iostream>

using namespace std;

class index {

    int ln;
    string  campo;
    string  flag;
public:

    //constructores
    index    ()  {
    }
    index    (int    ln, int campo)  {
        this    ->ln    =   ln;
        this    ->campo =   campo;
    }
    index    (int    ln, int campo, string  flag)  {
        this    ->ln    =   ln;
        this    ->campo =   campo;
        this    ->flag  =   flag;
    }

    //acceso
    void    setLN   (int    ln)  {
        this    ->ln    =   ln;
    }
    int     getLN   ()  {
        return  this    ->ln;
    }
    void    setCAMPO   (int    campo)  {
        this    ->campo =   campo;
    }
    string  getCAMPO    ()  {
        return  this    ->campo;
    }
    void    setFLAG (string flag)  {
        this    ->flag  =   flag;
    }
    string  getFLAG ()  {
        return  this    ->flag;
    }

    //administrativos
    void    print   ()  {
        cout    <<setw(10)<<ln<<setw(10)<<campo<<endl;
    }
};


#endif //UNTITLED_INDEX_H
