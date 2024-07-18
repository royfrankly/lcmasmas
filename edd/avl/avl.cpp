#include <iostream>
using namespace std;
struct nodo{
    int inf,fe;
    nodo *izq,*der;
};
void inserta_AVL(nodo *&raiz,int dato,int &cen);
void buscar_AVL(nodo *raiz, int dato);
void elimina_AVL(nodo *&raiz,int &cen, int dato);
void preorden(nodo *raiz);
void inorden(nodo *raiz);
void postorden(nodo *raiz);

void borra(nodo *&aux,nodo *&q,int &cen);
void reestructura1(nodo *&raiz, int &cen);
void reestructura2(nodo *&raiz, int &cen);
int main(void){
    nodo *raiz=NULL;
    int op,dato;
    char opc;
    int cen2;
    system("cls");
    do{
        system("cls");
        std::cout<<"\t\t\tMENU - ARBOLES BINARIOS BALANCEADOS - AVL\n\n";
        std::cout<<"\t\t\t******************************************\n\n";
        std::cout<<"\t\t1. INSERCION\n\n";
        std::cout<<"\t\t2. ELIMINACION\n\n";
        std::cout<<"\t\t3. BUSQUEDA\n\n";
        std::cout<<"\t\t4. RECORRIDO PREORDEN\n\n";
        std::cout<<"\t\t5. RECORRIDO INORDEN\n\n";
        std::cout<<"\t\t6. RECORRIDO POSTORDEN\n";
        std::cout<<"\t\t\t\tS A L I R\n\n";
        std::cout<<"\t\t\t\tOPCION  ";
        std::cin>>op;
        system("cls");
        switch(op)
        {
        case 1:
            do
            {
                system("cls");
                std::cout << "\n\n INGRESE EL DATO A INSERTAR: ";
                std::cin >> dato;
                int cen1 = 0;
                inserta_AVL(raiz, dato, cen1);
                std::cout << "\n\t\t¿MAS DATOS? (S/N): ";
                std::cin >> opc;
            } while(opc == 's' || opc == 'S');
            system("pause");
            break;
        case 2:
            system("cls");
            cen2=1;
            std::cout << "\n\nINGRESE EL DATO A ELIMINAR: ";
            std::cin >> dato;
            
            elimina_AVL(raiz,cen2, dato);
            system("pause");
            break;
        case 3:
            system("cls");
            std::cout << "\n\nINGRESE EL DATO A BUSCAR: ";
            std::cin >> dato;
            buscar_AVL(raiz, dato);
            system("pause");
            break;
        case 4:
            system("cls");
            std::cout << "\n\tRECORRIDO PREORDEN";
            std::cout << "\n\t******************\n\n";
            preorden(raiz);
            system("pause");
            break;
        case 5:
            system("cls");
            std::cout << "\n\tRECORRIDO INORDEN";
            std::cout << "\n\t*******************\n\n";
            inorden(raiz);
            system("pause");
            break;
        case 6:
            system("cls");
            std::cout << "\n\tRECORRIDO INORDEN";
            std::cout << "\n\t*******************\n\n";
            postorden(raiz);
            system("pause");
            break;
        }
    }while(op<7);
    return 0;
}


void inserta_AVL(nodo *&raiz, int dato, int &cen){
    nodo *raiz1, *raiz2,*x;
    if(raiz!=NULL){
        if(dato<raiz->inf){
            inserta_AVL(raiz->izq,dato,cen);
            if(cen==1){
                switch(raiz->fe){
                    case 1: raiz->fe=0;cen = 0; break;
                    case 2: raiz->fe=-1;break;
                    case -1:
                            raiz1=raiz->izq;
                            if(raiz1->fe<=0){
                                raiz->izq=raiz1->der;
                                raiz1->der=raiz;
                                raiz->fe=0;
                                raiz=raiz1;
                            }else{
                                raiz2=raiz1->der;
                                raiz->izq=raiz2->der;
                                raiz2->der=raiz;
                                raiz1->der=raiz2->izq;
                                raiz2->izq=raiz1;
                                if(raiz2->fe==-1)
                                    raiz->fe=1;
                                else    
                                    raiz->fe=0;
                                if(raiz2->fe==1)
                                    raiz1->fe=-1;
                                else   
                                    raiz1->fe=0;
                                raiz=raiz2;
                            }
                            raiz->fe=0;
                            cen =0;
                            break;
                }
            }
        }else if(dato>raiz->inf){
            inserta_AVL(raiz->der,dato,cen);
            if(cen==1){
                switch(raiz->fe){
                    case -1:raiz->fe=0;cen=0;break;
                    case 0: raiz->fe=1;break;
                    case 1: 
                        raiz1=raiz->der;
                        if(raiz->fe>=0){
                            raiz->der=raiz1->izq;
                            raiz1->izq=raiz;
                            raiz->fe=0;
                            raiz=raiz1;
                        }else{
                            raiz2=raiz1->izq;
                            raiz->der=raiz2->izq;
                            raiz2->izq=raiz;
                            raiz1->izq=raiz2->der;
                            raiz2->der=raiz1;
                            if(raiz2->fe==1)
                                raiz->fe=-1;
                            else
                                raiz->fe=0;
                            if(raiz2->fe==-1)
                                raiz1->fe=1;
                            else
                                raiz1->fe=0;
                            raiz=raiz2;
                        }
                        raiz->fe=0;
                        cen=0;
                        break;
                }
            }
        }
        else
            std::cout<<"\nEL DATO YA EXISTE ... \n\n";
    }else{
        x=new nodo;
        x->inf=dato;
        x->izq=NULL;
        x->der=NULL;
        x->fe=0;
        raiz=x;
        cen=1;
    }
}
void buscar_AVL(nodo *raiz, int dato){
    if(dato<raiz->inf)
        if(raiz->izq==NULL)
            std::cout<<"\n\tEL DATO BUSCADO NO EXISTE.... \n\n";
        else 
            buscar_AVL(raiz->izq, dato);
    else
        if(dato>raiz->inf)
            if(raiz->der==NULL)
                std::cout<<"\n\tEL DATO BUSCADO NO EXISTE....\n\n";
            else
                buscar_AVL(raiz->der,dato);
        else
            std::cout<<"\n\tEL DATO BUSCADO SI EXISTE....\n\n";
}

void elimina_AVL(nodo *&raiz,int dato){

}
void preorden(nodo *raiz){
    if(raiz!=NULL){
        std::cout<<raiz->inf<<"\n\n";
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void inorden(nodo *raiz){
    if(raiz!=NULL){
        inorden(raiz->izq);
        std::cout<<raiz->inf<<"\n\n";
        inorden(raiz->der);
    }
}

void postorden(nodo *raiz){
    if(raiz!=NULL){
        postorden(raiz->izq);
        postorden(raiz->der);
        std::cout<<raiz->inf<<"\n\n";
    }
}

void elimina_AVL(nodo *&raiz,int &cen, int dato){
    if(raiz!= NULL){
        nodo *q;
        if(dato<raiz->inf){
            elimina_AVL(raiz->izq,cen,dato);
            reestructura1(raiz,cen);
        }else{
            if(dato>raiz->inf){
                elimina_AVL(raiz->der,cen,dato);
                reestructura2(raiz,cen);
            }else{
                q=raiz;
                if(q->der=NULL){
                    raiz=q->izq;
                    cen=1;
                }else{
                    if(q->izq=NULL){
                        raiz=q->der;
                        cen=1;
                    }else{
                        borra(raiz->izq,q,cen);
                        reestructura1(raiz,cen);
                    }
                    delete q;
                }
            }
        }
    }else{
        std::cout<<"el dato no existe"<<endl;
    }
}

void borra(nodo *&aux,nodo *&q, int &cen){
    if(aux->der!=NULL){
        borra(aux->der,q,cen);
        reestructura2(aux,cen);
    }else{
        q->inf=aux->inf;
        aux=aux->izq;
        cen=1;
    }
}

void reestructura1(nodo *&raiz,int &cen){
    if(cen==1){
        nodo *raiz1, *raiz2;
        switch(raiz->fe){
            case -1:
                raiz->fe=0;
                break;
            case 0:
                raiz->fe=1;
                cen=0;
            case 1:
                raiz1=raiz->der;
                if(raiz1->fe>= 0){
                    raiz->der=raiz1->izq;
                    raiz1->izq=raiz;
                    switch (raiz1->fe)
                    {
                    case 0:
                        raiz->fe=1;
                        raiz->fe=-1;
                        cen=0;
                        break;
                    case 1:
                        raiz->fe=0;
                        raiz1->fe=0;
                        break;
                    }
                    raiz=raiz1;
                }else{
                    raiz2=raiz1->izq;
                    raiz->der=raiz2->izq;
                    raiz2->izq=raiz;
                    raiz1->izq=raiz->der;
                    raiz2->der=raiz1;
                    if(raiz2->fe=1){
                        raiz->fe=-1;
                    }else{
                        raiz->fe=0;
                    }
                    if(raiz2->fe=-1){
                        raiz1->fe=1;
                    }else{
                        raiz1->fe=0;
                    }
                    raiz=raiz2;
                    raiz->fe=0;
                }
        }

    }
}

void reestructura2(nodo *&raiz, int &cen){
    if(cen =1){
        nodo *raiz1,*raiz2;
        switch(raiz->fe){
            case 1:
                raiz->fe=0;
            case 0:
                raiz->fe=-1;
                cen=0;
            case -1:
                raiz1=raiz->izq;
                if(raiz1->fe<=0){
                    raiz->izq=raiz1->der;
                    raiz1->der=raiz;
                    switch(raiz1->fe){
                        case 0:
                            raiz->fe=-1;
                            raiz1->fe=1;
                            cen=0;
                            break;
                        case 1:
                            raiz->fe=0;
                            raiz1->fe=0;
                            break;
                    }
                    raiz=raiz1;
                }else{
                    raiz2=raiz1->der;
                    raiz->izq=raiz2->der;
                    raiz2->der=raiz;
                    raiz1->der=raiz2->izq;
                    raiz2->izq=raiz1;
                    if(raiz2->fe=-1){
                        raiz->fe=1;
                    }else{
                        raiz->fe=0;
                    }
                    if(raiz2->fe=1){
                        raiz1->fe=-1;
                    }else{
                        raiz1->fe=0;
                    }
                    raiz=raiz2;
                    raiz2->fe=0;
                }
        }
    }

}

