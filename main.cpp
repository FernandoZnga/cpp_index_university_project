#include    <stdio.h>
#include    <string>
#include    <iostream>
#include    <fstream>
#include    <iomanip>
#include    "adminREGISTRO.h"
#include    "adminINDEX.h"


using namespace std;

string      toUPP (string&     str)  {
    for (int i = 0; i < str.length(); i++) {
        str[i]    =   toupper(str[i]);
    }
    return  str;
}
string      toLOW (string&     str)  {
    for (int i = 0; i < str.length(); i++) {
        str[i]    =   tolower(str[i]);
    }
    return str;
}

void    menuPRINCIPAL   ();
void    menuBUSCAR      ();
void    menuINDICES     ();
void    menuESPACIO     ();
void    listaREGISTROS  ();
void    listarIDX       (int);
void    crearIndice     (int, bool);
void    eliminarIDX     (int);
void    agregaREGISTRO  ();
void    actualizaREGISTRO();
void    eliminaREGISTRO ();
void    consultaREGISTRO();
void    buscarREGISTROS (int);

string  departamentos[18] = {"ATLANT","CHOLUT","COLON","COMAYA","COPAN","CORTES","ELPARA","FRANMO","GRADIO","INTIBU","ISLDLB","LAPAZ","LEMPIRA","OCOTEP","OLANCH","STABAR","VALLE","YORO"};

string  rutaFile=   "/Users/znga/Documents/UNITEC/C++/PROY_ESTRUC_2/File.txt";
string  rutaIxC =   "/Users/znga/Documents/UNITEC/C++/PROY_ESTRUC_2/indexP.txt";
string  rutaIxD =   "/Users/znga/Documents/UNITEC/C++/PROY_ESTRUC_2/indexS1.txt";
string  rutaIxA =   "/Users/znga/Documents/UNITEC/C++/PROY_ESTRUC_2/indexS2.txt";

adminREGISTRO   RG(rutaFile);
adminINDEX   idxCODIGO(rutaIxC,rutaFile);
adminINDEX   idxDEPTO(rutaIxD,rutaFile);
adminINDEX   idxAPELLIDO(rutaIxA,rutaFile);

int main() {
    std::cout << __VERSION__ << std::endl;
    menuPRINCIPAL();
    return 0;
}

void menuPRINCIPAL   ()  {
    int optionUSER;
    while   (true)  {
        cout    <<endl<<endl;
        cout    <<"\t**************************************************"<<endl;
        cout    <<"\t"<<"*"<<setw(17)<<""<<setw(14)<<"MENU PRINCIPAL"<<setw(17)<<""<<"*"<<endl;
        cout    <<"\t**************************************************"<<endl<<endl;
        cout    <<"\t"<<"OPCION"<<setw(40)<<"DESCRIPCION"<<endl;
        cout    <<"\t"<<setw(10)<<"----------"<<setw(40)<<"------------------------------"<<endl;

        cout    <<"\t"<<setw(10)<<"[1]"<<setw(40)<<"Listar REGISTROS"<<endl;
        cout    <<"\t"<<setw(10)<<"[2]"<<setw(40)<<"Agregar REGISTRO "<<endl;
        cout    <<"\t"<<setw(10)<<"[3]"<<setw(40)<<"Actualizar REGISTRO "<<endl;
        cout    <<"\t"<<setw(10)<<"[4]"<<setw(40)<<"Eliminar REGISTRO "<<endl;
        cout    <<"\t"<<setw(10)<<"[5]"<<setw(40)<<"Buscar REGISTRO "<<endl;
        cout    <<endl;
        cout    <<"\t"<<setw(10)<<"[6]"<<setw(40)<<"Seccion de INDICES "<<endl;
        cout    <<"\t"<<setw(10)<<"[7]"<<setw(40)<<"Liberar ESPACIO "<<endl;
        cout    <<endl;
        cout    <<"\t"<<setw(10)<<"[99]"<<setw(40)<<"SALIR DEL PROGRAMA "<<endl;
        cout    <<"\t"<<setw(10)<<"--->";
        cin     >>optionUSER;
        switch (optionUSER) {
            case 1:
                listaREGISTROS();
                break;
            case 2:
                agregaREGISTRO();
                break;
            case 3:
                actualizaREGISTRO();
                break;
            case 4:
                eliminaREGISTRO();
                break;
            case 5:
                menuBUSCAR();
                break;
            case 6:
                menuINDICES();
                break;
            case 7:
                menuESPACIO();
                break;
            default:
                if (optionUSER != 99)
                    cout    <<"\n\t[Seleccione una opcion valida]\n";
                else
                    cout    <<"\n\t[ADIOS!]\n";
                break;
        }
        if (optionUSER == 99)
            exit(0);
    }
}

void crearIndice  (int    campo, bool integer)  {
    switch  (campo) {
        case 1:
            idxCODIGO.crearIDX(campo);
            idxCODIGO.burbuja(integer);
            idxCODIGO.write();

            break;
        case 2:
            idxAPELLIDO.crearIDX(campo);
            idxAPELLIDO.burbuja(integer);
            idxAPELLIDO.write();

            break;
        case 4:
            idxDEPTO.crearIDX(campo);
            idxDEPTO.burbuja(integer);
            idxDEPTO.write();

            break;
        default:
            break;
    }
}

void menuBUSCAR   ()  {
    int idxREGS;
    int idxRESP;
    int optionUSER;
    while   (true)  {
        cout    <<endl<<endl;
        cout    <<"\t\t**************************************************"<<endl;
        cout    <<"\t\t"<<"*"<<setw(18)<<""<<setw(11)<<"MENU BUSCAR"<<setw(19)<<""<<"*"<<endl;
        cout    <<"\t\t**************************************************"<<endl<<endl;
        cout    <<"\t\t"<<"OPCION"<<setw(40)<<"DESCRIPCION"<<endl;
        cout    <<"\t\t"<<setw(10)<<"----------"<<setw(40)<<"------------------------------"<<endl;

        cout    <<"\t\t"<<setw(10)<<"[1]"<<setw(40)<<"Buscar por        CODIGO"<<endl;
        cout    <<"\t\t"<<setw(10)<<"[2]"<<setw(40)<<"Buscar por  DEPARTAMENTO"<<endl;
        cout    <<"\t\t"<<setw(10)<<"[3]"<<setw(40)<<"Buscar por      APELLIDO"<<endl;
        cout    <<endl;
        cout    <<"\t\t"<<setw(10)<<"[99]"<<setw(40)<<"REGRESAR"<<endl;
        cout    <<"\t\t"<<setw(10)<<"--->";
        cin     >>optionUSER;
        switch (optionUSER) {
            case 1:
                idxREGS = 0;
                idxCODIGO.read();
                idxREGS =   idxCODIGO.getN();
                if (idxREGS == 0)    {
                    cout    <<endl;
                    cout    <<"\t\t[NO HAY INDICE PRINCIPAL]\n";
                    cout    <<"\t\t[DESEA CREARLO AHORA ?  ]\n";
                    cout    <<"\t\t[1 - SI]\n\t\t[2 - NO]\t-->";
                    cin     >>idxRESP;
                    idxRESP == 1 ? menuINDICES() : buscarREGISTROS(1);
                }
                else
                    buscarREGISTROS(1);
                break;
            case 2:
                idxREGS = 0;
                idxDEPTO.read();
                idxREGS =   idxDEPTO.getN();
                if (idxREGS == 0)    {
                    cout    <<endl;
                    cout    <<"\t\t[NO HAY INDICE xDEPARTAMENTO]\n";
                    cout    <<"\t\t[DESEA CREARLO AHORA ?      ]\n";
                    cout    <<"\t\t[1 - SI]\n\t\t[2 - NO]\t-->";
                    cin     >>idxRESP;
                    idxRESP == 1 ? menuINDICES() : buscarREGISTROS(2);
                }
                else
                    buscarREGISTROS(2);
                break;
            case 3:
                idxREGS = 0;
                idxAPELLIDO.read();
                idxREGS =   idxAPELLIDO.getN();
                if (idxREGS == 0)    {
                    cout    <<endl;
                    cout    <<"\t\t[NO HAY INDICE xAPELLIDO]\n";
                    cout    <<"\t\t[DESEA CREARLO AHORA ?      ]\n";
                    cout    <<"\t\t[1 - SI]\n\t\t[2 - NO]\t-->";
                    cin     >>idxRESP;
                    idxRESP == 1 ? menuINDICES() : buscarREGISTROS(3);
                }
                else
                    buscarREGISTROS(3);
                break;

            default:
                if (optionUSER != 99)
                    cout    <<"\n\t[Seleccione una opcion valida]\n";
                break;
        }
        if (optionUSER == 99)
            menuPRINCIPAL();
    }
}

void menuESPACIO   ()  {
    int idxREGS;
    int idxRESP;
    int optionUSER;
    while   (true)  {
        cout    <<endl<<endl;
        cout    <<"\t\t**************************************************"<<endl;
        cout    <<"\t\t"<<"*"<<setw(14)<<""<<setw(10)<<"MENU LIBERAR ESPACIO"<<setw(14)<<""<<"*"<<endl;
        cout    <<"\t\t**************************************************"<<endl<<endl;
        cout    <<"\t\t"<<"OPCION"<<setw(40)<<"DESCRIPCION"<<endl;
        cout    <<"\t\t"<<setw(10)<<"----------"<<setw(40)<<"------------------------------"<<endl;

        cout    <<"\t\t"<<setw(10)<<"[1]"<<setw(40)<<"Listar registros ELIMINADOS"<<endl;
        cout    <<"\t\t"<<setw(10)<<"[2]"<<setw(40)<<"ELIMINAR PERMANENTEMENTE"<<endl;
        cout    <<"\t\t"<<setw(10)<<"[3]"<<setw(40)<<"RESTAURAR REGISTRO ELIMINADO"<<endl;
        cout    <<endl;
        cout    <<"\t\t"<<setw(10)<<"[99]"<<setw(40)<<"REGRESAR"<<endl;
        cout    <<"\t\t"<<setw(10)<<"--->";
        cin     >>optionUSER;
        switch (optionUSER) {
            case 1:
                RG.read();
                RG.printHEAD();
                RG.printELIMINADOS();
                break;
            case 2:
                idxRESP = 0;
                while (true)    {
                    cout    <<endl;
                    cout    <<"\t\t[Esta operacion no se puede deshacer]"<<endl;
                    cout    <<"\t\t[Desea Continuar]\n\t\t(1)\tSI\n\t\t(2)\tNO\t-->";
                    cin     >>idxRESP;
                    switch (idxRESP)    {
                        case 1:
                            RG.read();
                            RG.delREGISTROSpermanente();
                            RG.write();
                            eliminarIDX(4);
                            crearIndice(1, true);
                            crearIndice(4, false);
                            crearIndice(2, false);
                            break;
                        case 2:
                            cout    <<endl;
                            cout    <<"\t\t[Operacion CANCELADA]"<<endl;
                            break;
                        default:
                            cout    <<endl;
                            cout    <<"\t\t[Opcion seleccionada invalida]"<<endl;
                    }
                    if (idxRESP  ==  2 || idxRESP == 1)
                        break;
                }
                break;
            case 3:
                RG.read();
                RG.restaurarREGISTROS();
                RG.write();
                eliminarIDX(4);
                crearIndice(1, true);
                crearIndice(4, false);
                crearIndice(2, false);
                break;
            default:
                if (optionUSER != 99)
                    cout    <<"\n\t[Seleccione una opcion valida]\n";
                break;
        }
        if (optionUSER == 99)
            menuPRINCIPAL();
    }
}


void menuINDICES    ()  {
    int idxREGS;
    int idxRESP;
    int optionUSER;
    while   (true)  {
        cout    <<endl<<endl;
        cout    <<"\t\t**************************************************"<<endl;
        cout    <<"\t\t"<<"*"<<setw(17)<<""<<setw(13)<<"MENU INDICES"<<setw(18)<<""<<"*"<<endl;
        cout    <<"\t\t**************************************************"<<endl<<endl;
        cout    <<"\t\t"<<"OPCION"<<setw(40)<<"DESCRIPCION"<<endl;
        cout    <<"\t\t"<<setw(10)<<"----------"<<setw(40)<<"------------------------------"<<endl;

        cout    <<"\t\t"<<setw(10)<<"[1]"<<setw(40)<<"Mostrar INDICE PRIMARIO   [CODIGO      ]"<<endl;
        cout    <<"\t\t"<<setw(10)<<"[2]"<<setw(40)<<"Mostrar INDICE SECUNDARIO [DEPARTAMENTO]"<<endl;
        cout    <<"\t\t"<<setw(10)<<"[3]"<<setw(40)<<"Mostrar INDICE SECUNDARIO [APELLIDO    ]"<<endl;

        cout    <<"\t\t"<<setw(10)<<"[4]"<<setw(40)<<"Borrar  INDICE PRIMARIO   [CODIGO      ]"<<endl;
        cout    <<"\t\t"<<setw(10)<<"[5]"<<setw(40)<<"Borrar  INDICE SECUNDARIO [DEPARTAMENTO]"<<endl;
        cout    <<"\t\t"<<setw(10)<<"[6]"<<setw(40)<<"Borrar  INDICE SECUNDARIO [APELLIDO    ]"<<endl;
        cout    <<"\t\t"<<setw(10)<<"[7]"<<setw(40)<<"Borrar  TODOS LOS INDICES CREADOS [    ]"<<endl;

        cout    <<"\t\t"<<setw(10)<<"[8]"<<setw(40)<<"RE CONSTRUIR INDICES [                 ]"<<endl;
        cout    <<endl;
        cout    <<"\t\t"<<setw(10)<<"[99]"<<setw(40)<<"REGRESAR"<<endl;
        cout    <<"\t\t"<<setw(10)<<"--->";
        cin     >>optionUSER;
        switch (optionUSER) {
            case 1:
                idxREGS = 0;
                idxCODIGO.read();
                idxREGS =   idxCODIGO.getN();
                cout    <<idxREGS<<endl;
                if (idxREGS == 0)    {
                    cout    <<endl;
                    cout    <<"\t\t[NO HAY INDICE PRINCIPAL]\n";
                    cout    <<"\t\t[DESEA CREARLO AHORA ?  ]\n";
                    cout    <<"\t\t[1 - SI]\n\t\t[2 - NO]\t-->";
                    cin     >>idxRESP;
                    idxRESP == 1 ? crearIndice(1, true) : menuINDICES();
                }
                else
                    listarIDX(1);
                break;
            case 2:
                idxREGS = 0;
                idxDEPTO.read();
                idxREGS =   idxDEPTO.getN();
                if (idxREGS == 0)    {
                    cout    <<endl;
                    cout    <<"\t\t[NO HAY xDEPARTAMENTO]\n";
                    cout    <<"\t\t[DESEA CREARLO AHORA ?  ]\n";
                    cout    <<"\t\t[1 - SI]\n\t\t[2 - NO]\t-->";
                    cin     >>idxRESP;
                    idxRESP == 1 ? crearIndice(4, false) : menuINDICES();
                }
                else
                    listarIDX(2);
                break;
            case 3:
                idxREGS = 0;
                idxAPELLIDO.read();
                idxREGS =   idxAPELLIDO.getN();
                if (idxREGS == 0)    {
                    cout    <<endl;
                    cout    <<"\t\t[NO HAY xAPELLIDO]\n";
                    cout    <<"\t\t[DESEA CREARLO AHORA ?  ]\n";
                    cout    <<"\t\t[1 - SI]\n\t\t[2 - NO]\t-->";
                    cin     >>idxRESP;
                    idxRESP == 1 ? crearIndice(2, false) : menuINDICES();
                }
                else
                    listarIDX(3);
                break;
            case 4:
                eliminarIDX(1);
                break;
            case 5:
                eliminarIDX(2);
                break;
            case 6:
                eliminarIDX(3);
                break;
            case 7:
                eliminarIDX(4);
                break;
            case 8:
                eliminarIDX(4);
                crearIndice(1, true);
                crearIndice(4, false);
                crearIndice(2, false);
                break;
            default:
                if (optionUSER != 99)
                    cout    <<"\n\t[Seleccione una opcion valida]\n";
                break;
        }
        if (optionUSER == 99)
            menuPRINCIPAL();
    }
}

void listaREGISTROS ()  {
    RG.read();
    RG.printHEAD();
    RG.print();
}

void agregaREGISTRO ()  {
    RG.read();
    int     codREG;
    int     depNUM = -1;
    string  apeREG;
    string  mmmREG,dddREG,yyyREG;
    string  depREG;
    string  monREG;

    cout    <<"\n\t[Seccion para Agregar registros]\n\n";
    cout    <<"\tIngrese el Apellido:\t->";
    cin     >>apeREG;
    cout    <<"\tIngrese el DIA (dd):\t->";
    cin     >>dddREG;
    cout    <<"\tIngrese el MES (mm):\t->";
    cin     >>mmmREG;
    cout    <<"\tIngrese el AÑO (yyyy):\t->";
    cin     >>yyyREG;
    cout    <<"\tSeleccione el Departamento:\n";
    for (int i = 0; i < 18; ++i) {
        cout << "\t(" << i + 1 << ")\t" << departamentos[i] << endl;
    }
    while (depNUM <0 || depNUM >18)    {
        cout    <<"\t\tIngrese su opción-->";
        cin     >>depNUM;
        if (depNUM <0 || depNUM >18)
            cout    <<"\t[Error, debe seleccionar uno de la lista ingresando el numero]\n";
    }
    depREG  =   departamentos[depNUM-1];
    cout    <<"\tIngrese el monto:\t->";
    cin     >>monREG;
    codREG  =   RG.nextCODIGO();


    registro r;
    r  =   registro(codREG,toUPP(apeREG),(mmmREG+"/"+dddREG+"/"+yyyREG),depREG,monREG,0);
    RG.addREGISTROS(r);
    RG.write();

    eliminarIDX(4);
    crearIndice(1, true);
    crearIndice(4, false);
    crearIndice(2, false);
    cout    <<"\t[Registro AGREGADO con Exito!]\n\n";
}

void actualizaREGISTRO () {
    RG.read();
    RG.printHEAD();
    RG.print();
    int     codREG,depNUM = -1,numLINE = -1;
    string  apeREG;
    string  mmmREG,dddREG,yyyREG;
    string  depREG;
    string  monREG;
    int  yes_no;
    bool true_false = false;

    while (true) {
        cout << "\tCual registro desea modificar?:\n";
        while (numLINE <=0 || numLINE > RG.getN()) {
            cout << "\tIngrese el Numero de la Linea:\t->";
            cin >> numLINE;
            if (numLINE <=0 || numLINE > RG.getN())
                cout << "\t[Error, Valor ingresado Fuera del Rango!]\n";
        }
        cout << "\tHa Seleccionado:\n";
        RG.printHEAD();
        RG.printLINE(numLINE);
        cout    <<"\n\tES CORRECTO?\n";
        cout    <<"\t\t1 = SI\n\t\t2 = NO\t->";
        cin >> yes_no;
        if (yes_no == 1) {
            cout << "\tIngrese el Apellido:\t->";
            cin >> apeREG;
            cout << "\tIngrese el DIA (dd):\t->";
            cin >> dddREG;
            cout << "\tIngrese el MES (mm):\t->";
            cin >> mmmREG;
            cout << "\tIngrese el AÑO (yyyy):\t->";
            cin >> yyyREG;
            cout << "\tSeleccione el Departamento:\n";

            for (int i = 0; i < 18; ++i) {
                cout << "\t(" << i + 1 << ")\t" << departamentos[i] << endl;
            }

            while (depNUM < 0 || depNUM > 18) {
                cout << "\t\tIngrese su opción-->";
                cin >> depNUM;
                if (depNUM < 0 || depNUM > 18)
                    cout << "\t[Error, debe seleccionar uno de la lista ingresando el numero]\n";
            }

            depREG = departamentos[depNUM-1];
            cout << "\tIngrese el monto:\t->";
            cin >> monREG;
            RG.setREGISTROS(numLINE-1,registro(codREG, toUPP(apeREG), (mmmREG + "/" + dddREG + "/" + yyyREG), depREG, monREG));
            RG.write();

            eliminarIDX(4);
            crearIndice(1, true);
            crearIndice(4, false);
            crearIndice(2, false);
            cout << "\t[Registro ACTUALIZADO con Exito!]\n\n";
            break;
        } else
            break;
    }
}

void eliminaREGISTRO ()  {
    RG.read();
    RG.printHEAD();
    RG.print();
    int     codREG,depNUM = -1,numLINE = -1;
    string  apeREG;
    string  mmmREG,dddREG,yyyREG;
    string  depREG;
    string  monREG;
    int  yes_no;
    bool true_false = false;

    while (true) {
        cout << "\tCual registro desea ELIMINAR?:\n";
        while (numLINE <=0 || numLINE > RG.getN()) {
            cout << "\tIngrese el Numero de la Linea:\t->";
            cin >> numLINE;
            if (numLINE <=0 || numLINE > RG.getN())
                cout << "\t[Error, Valor ingresado Fuera del Rango!]\n";
        }
        cout << "\tHa Seleccionado:\n";
        RG.printHEAD();
        RG.printLINE(numLINE-1);
        cout    <<"\n\tES CORRECTO?\n";
        cout    <<"\t\t1 = SI\n\t\t2 = NO\t->";
        cin >> yes_no;
        if (yes_no == 1) {
            RG.delREGISTROS(numLINE-1,1);
            RG.write();

            eliminarIDX(4);
            crearIndice(1, true);
            crearIndice(4, false);
            crearIndice(2, false);
            cout << "\t[Registro ELIMINADO con Exito!]\n\n";
            break;
        } else
            break;
    }
}

void consultaREGISTRO ()  {
    RG.read();
    RG.printHEAD();
    RG.print();
    int     codREG,depNUM = -1,numLINE = -1;
    string  apeREG;
    string  mmmREG,dddREG,yyyREG;
    string  depREG;
    string  monREG;
    int  yes_no;
    bool true_false = false;

    while (true) {
        cout << "\tCual registro desea CONSULTAR?:\n";
        while (numLINE <=0 || numLINE > RG.getN()) {
            cout << "\tIngrese el Numero de la Linea:\t->";
            cin >> numLINE;
            if (numLINE <=0 || numLINE > RG.getN())
                cout << "\t[Error, Valor ingresado Fuera del Rango!]\n";
        }
        cout    <<endl<<endl;
        cout    <<"\t\tCODIGO ->\t:"<<RG.getREGISTROS()[numLINE-1].getCODIGO()<<endl;
        cout    <<"\t\tAPELLIDO ->\t:"<<RG.getREGISTROS()[numLINE-1].getAPELLIDO()<<endl;
        cout    <<"\t\tFECHA ->\t:"<<RG.getREGISTROS()[numLINE-1].getFECHA()<<endl;
        cout    <<"\t\tDEPTO ->\t:"<<RG.getREGISTROS()[numLINE-1].getDEPTO()<<endl;
        cout    <<"\t\tMONTO ->\t:"<<RG.getREGISTROS()[numLINE-1].getMONTO()<<endl<<endl;
        break;

    }
}

void    buscarREGISTROS  (int tipoBUSQUEDA)  {
    //RG.read();
    //RG.printHEAD();
    //RG.print();
    int     codREG,depNUM = -1,numLINE = -1;
    string  apeREG;
    string  mmmREG,dddREG,yyyREG;
    string  depREG;
    string  monREG;
    int  yes_no;
    bool true_false = false;

    switch (tipoBUSQUEDA)   {
        //tipoBUSQUEDA = 1 <- codigo
        //tipoBUSQUEDA = 2 <- departamento
        //tipoBUSQUEDA = 3 <- apellido
        case    1:
            idxCODIGO.read();
            cout    <<"\t\tINGRESE el CODIGO:\n";
            cin     >>codREG;
            RG.printHEAD();
            for (int i = 0; i < idxCODIGO.getN(); ++i) {
                if (to_string(codREG) == idxCODIGO.getREGISTROS()[i].getCAMPO() &&
                    idxCODIGO.getREGISTROS()[i].getFLAG() != 1)   {
                    RG.read();
                    RG.printLINE(idxCODIGO.getREGISTROS()[i].getLN());
                    //break;
                }
            }
            //RG.buscar(to_string(codREG),1);
            break;
        case    2:
            idxDEPTO.read();
            cout    <<"\t\tINGRESE el DEPARTAMENTO:\n";
            cin     >>apeREG;
            RG.printHEAD();
            for (int i = 0; i < idxCODIGO.getN(); ++i) {
                if (to_string(codREG) == idxDEPTO.getREGISTROS()[i].getCAMPO() &&
                    idxDEPTO.getREGISTROS()[i].getFLAG() != 1)   {
                    RG.read();
                    RG.printLINE(idxDEPTO.getREGISTROS()[i].getLN());
                    //break;
                }
            }
            //RG.buscar(toUPP(apeREG),2);
            break;
        case    3:
            cout    <<"\t\tINGRESE el APELLIDO:\n";
            cin     >>depREG;
            RG.printHEAD();
            for (int i = 0; i < idxAPELLIDO.getN(); ++i) {
                if (to_string(codREG) == idxAPELLIDO.getREGISTROS()[i].getCAMPO() &&
                    idxAPELLIDO.getREGISTROS()[i].getFLAG() != 1)   {
                    RG.read();
                    RG.printLINE(idxAPELLIDO.getREGISTROS()[i].getLN());
                    //break;
                }
            }
            //RG.buscar(toUPP(depREG),3);
            break;
        default:
            break;
    }
}

void    listarIDX (int  indice)  {
    //indice = 1 <- codigo
    //indice = 2 <- departamento
    //indice = 3 <- apellido
    switch (indice) {
        case 1:
            idxCODIGO.read();
            idxCODIGO.printHEAD();
            idxCODIGO.print();
            break;
        case 2:
            idxDEPTO.read();
            idxDEPTO.printHEAD();
            idxDEPTO.print();
            break;
        case 3:
            idxAPELLIDO.read();
            idxAPELLIDO.printHEAD();
            idxAPELLIDO.print();
            break;
        default:
            break;
    }
}

void    eliminarIDX (int    indice)  {
    //indice = 1 <- codigo
    //indice = 2 <- departamento
    //indice = 3 <- apellido
    switch (indice) {
        case 1:
            idxCODIGO.eliminarIDX();
            break;
        case 2:
            idxDEPTO.eliminarIDX();
            break;
        case 3:
            idxAPELLIDO.eliminarIDX();
            break;
        default:
            idxCODIGO.eliminarIDX();
            idxDEPTO.eliminarIDX();
            idxAPELLIDO.eliminarIDX();
            break;
    }
}
