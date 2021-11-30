#include <iostream>
using namespace std;

struct nodo{
    int numero;
    struct nodo *siguiente;
};

struct cola{
    nodo *frente;
    nodo *atras;
};

void encolar(struct cola &q, int valor){
    struct nodo *aux = new(struct nodo);

    aux->numero = valor;
    aux->siguiente = NULL;

    if(q.frente == NULL)
        q.frente = aux;
    else
        (q.atras)->siguiente = aux;

    q.atras = aux;
}

int desencolar(struct cola &q){
    int num;
    struct nodo *aux;

    aux = q.frente;
    num = aux->numero;
    q.frente = (q.frente)->siguiente;
    delete(aux);

    return num;
}

void frente(struct cola q){
    struct nodo *aux;

    aux = q.frente;

    cout<<"\nEl numero al frente de la queue es: "<<aux->numero<<"\n";
}
void imprimirCola(struct cola q){
    struct nodo *aux;

    aux = q.frente;

    while(aux != NULL)
    {
        cout<<"  "<<aux->numero;
        aux = aux->siguiente;
    }
}

void menu(){
    cout<<"\n\t\tPractica 4. Colas (Queues)"<<endl<<endl;
    cout<<"Que operacion desea realizar?"<<endl<<endl
        <<"1.- Vacia"<<endl
        <<"2.- Llena"<<endl
        <<"3.- Encolar (Enqueue)"<<endl
        <<"4.- Desencolar (Dequeue)"<<endl
        <<"5.- Mostrar Frente"<<endl
        <<"6.- Imprimir Queue"<<endl
        <<"7.- Salir"<<endl<<endl
        <<"Seleccione una opcion: "<<endl;
}

int main(){
    struct cola q;

    q.frente = NULL;
    q.atras = NULL;

    int dato;
    int op;
    int x;
    int iterador = 0;

    do{
        menu();
        cin>>op;

        switch(op){
            case 1:
                cout<<"\t\tVACIA"<<endl<<endl;
                if(q.frente == NULL)
                    cout<<"\tLa cola esta VACIA\n";
                else
                    cout<<"\tLa cola NO esta VACIA\n";
            break;
            case 2:
                cout<<"\t\tLLENA"<<endl<<endl;
                if(iterador ==5){
                	cout<<"\tLa cola esta LLENA\n";
				}
				else{
					cout<<"\tLa cola NO esta LLENA\n";
				}
            break;
            case 3:
                cout<<"\n\t\tENCOLAR (ENQUEUE)"<<endl<<endl;
                if(iterador <5){
	                cout<<"Ingrese un numero: ";
	                cin>>dato;
	                encolar(q, dato);
	                cout<<"\nEl numero "<<dato<<" fue ingresado a la queue\n";
	                iterador++;
            	}
            	else{
            		cout<<"\tLa cola esta LLENA\n";
				}
            break;
            case 4:
                cout<<"\n\t\tDESENCOLAR (UNQUEUE)"<<endl<<endl;
                x = desencolar(q);  
                cout<<"Numero fuera de la queue: "<<x<<"\n";
                iterador--;
            break;
            case 5:
                cout<<"\n\t\tMOSTRAR FRENTE"<<endl<<endl;
                frente(q);
            break;
            case 6:
                cout<<"\n\t\tIMPRIMIR QUEUE"<<endl<<endl;
                cout<<"Los numeros en la queue son: "<<endl;
                if(q.frente != NULL) imprimirCola(q);
                else
                    cout<<"\tLa cola esta VACIA\n"<<endl;
				cout<<"\n";
            break;
            case 7:
                cout<<"\t\tSalir"<<endl<<endl;
                cout<<"\tSaldra del programa.Adios\n";
                return 0;
            break;
            default:
                cout<<"\t\tOpcion invalida. Ingrese una opcion correcta"<<endl<<endl;
            break;
        }
    }while(op !=7);
}
