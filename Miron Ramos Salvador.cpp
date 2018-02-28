//
//  main.cpp
//  arbolTienda
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

// Estructura Arbol
struct arbol
{
    int dato,precio,estado; //  ID producto , precio
    char descripcion[40];   //articulo string
    char empaque[10];       // tipo de embase
    arbol *i,*d; // puntero Izquierda y Derecha tipo arbol

//elemento  , aux puntero que se usa como refencia al siguiente arbol
//cabecera Raíz del arbol ,NULL y se crea como arbol al insertar los primeros datos
//ant punteron como referencia al arbol anterior null
//aux2
}*elemento, *aux, *cabecera, *ant, *aux2, *ant2;

int dato,precio,estado;
char descripcion[40];
char empaque[10];

//Prototipos de Funcion
int buscar(void);
void insertar(void);
void acomodarMayorCab();
void acomodarMenor();
void eliminar(void);
void listar(arbol *aux);  // Muestra Arbol
void modificar(void);


// funcion principal Main
int main(int argc, char** argv )
{
    int opc;  // opcion entera para menu
    do        //bucle do
    {
        system("cls");        // limpia pantalla *** system("cls"); para windows
        cout<<"0 - Salir\n";
        cout<<"1 - Insertar\n";
        cout<<"2 - Buscar\n";
        cout<<"3 - Borrar\n";
        cout<<"4 - Listar\n";
        cout<<"5 - modificar\n";
        cout<<"Cual es su opcion: ";
        cin>>opc;               // recibe opcion menu
        system("cls");
        
        if(!cabecera &( opc > 1 ))  // validacion de la opcion y cabecera no Null
            printf(" No hay arbol");
        else{
            switch(opc)                 // estructura de seleccion para la opcion
            {
                case 0: break;                  // termina el Programa
                case 1: cout<<"\n\n\t Datos a insertar: "; // opcion 1
                    cout<<"\n\n Producto: ";
                    scanf("%i",&dato);          //ID del articulo a ingresar
                    cout<<"\n\n Descripcion: ";
                    scanf("%s",descripcion);    // articulo a ingresar
                    cout<<"\n\n Empaque: ";
                    scanf("%s",empaque);        //tipo de embase a ingresar
                    cout<<"\n\n Precio: ";
                    scanf("%i",&precio);        // precio de tipo entero a ingresar
                    cout<<("\n\n Estado (1 = activo, 0 = inactivo): ");
                    scanf("%i",&estado);
                    
                    
                    insertar();  //Funcion insertar los datos introducido
                    cout<<"\n*********************************";
                    cout<<"\n* Registro Ingresado Con Exito  *";
                    cout<<"\n*********************************";
                    break;
                case 2: cout<<"\n\nDato a buscar: ";
                    cin>>dato;
                    if(buscar()){
                        cout<<"\n\nDato existe";
                        cout<<"\n\n Producto Descripcion            empaque  precio\n\n ";
                        printf("%i\t%s\t\t\t%s\t%i\t%i\n", aux->dato , aux->descripcion, aux->empaque, aux->precio,aux->estado );
                    }else
                        cout<<"\n\nDato inexistente";
                    break;
                case 3: cout<<"\n\nDato a borrar: ";
                    cin>>dato;
                    eliminar();
                    break;
                case 4: cout<<"\n\n\t\tL i s t a d o   d e   d a t o s ";
                    cout<<"\n\n Producto Descripcion            empaque  precio  estado\n\n ";
                    listar(cabecera);
                    break;
                case 5: cout<<"\n\nDato a modificar: ";
                    cin>>dato;
                    modificar();
                    break;    
                default: cout<<"\n\nOpcion incorrecta";
            }
            
        }
        cout<<("\n");
        system("pause");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        
    }while(opc);
    return 0;
}


//funcion buscar
//regresa 1 o 0 estados binarios
int buscar(void)
{
    ant=NULL;                   // anterior
    aux=cabecera;               // auxiliar se pone como cabeza
        while(aux){             // mientras existan nodos
            if (dato == aux->dato){ // se comprar el dato a buscar si es igual
                return(1);      // regresa 1 como estado binario
            }else{              //si no es
                ant=aux;        // anterior se iguala a auxiliar
                if (dato > aux->dato) // condicional de recorrido  o camino de busqueda
                    aux = aux->d; // si es mayor , derecha se iguala a uxiliar
                else
                    aux = aux->i; // si es menor , aux apunta a izquierda
            }
        }
    return(0);                // si no encuentra nada 0 como estado binario
}


// funcio insertar
void insertar(void)
{
    if(!cabecera) // si cabecera esta vacia
    {
        cabecera=new(arbol); // cabera se crea con arbol raiz
         // se iguala la cabecera con los datos
        cabecera->dato=dato;
        strcpy(cabecera->descripcion , descripcion);
        strcpy(cabecera->empaque , empaque);
        cabecera->precio=precio;
        cabecera->estado=estado;
        cabecera->d=NULL;  // derecha como Null
        cabecera->i=NULL; //izquierda como null
        return; // termina funcion
    }
    if (!buscar()){ // buscar lugar para el nuevo nodo
        aux=new(arbol); // crea el nodo auxiliar se queda apuntador al ultimo null
        aux->dato=dato;
        strcpy(aux->descripcion , descripcion);
        strcpy(aux->empaque , empaque);
        aux->precio=precio;
        aux->estado=estado;
        // este nodo es hoja hasta que se demuestre lo contrario XD })(son caritas Xp )
        aux->i=NULL;
        aux->d=NULL;
        // condicional para actualizar puntero si es mayor derecha else izquierda
        if(dato > ant->dato)
            ant->d=aux;  // puntero apunta al nuevo nodo hoja
        else
            ant->i=aux;
    }
    else
        cout<<"\n\nDato existente";  // si la funcion buscar encuentra el dato evita que se repita
}

//funcion
void acomodaNodos(void){
    
    
    if (aux->i !=NULL && aux->d !=NULL && (ant->dato != cabecera->dato )) { // si tiene las dos raices
        aux2 = aux->i;                    // auxiliar2 almacena puntero a lado derecho
        while (aux2->d) {       // recorre en busca del mas pequeño
            aux2 = aux2->d;
            ant2 = aux2;
        }
        aux2->d = aux->d;  // aux2 =
        ant->i = aux->i;
        aux=NULL;
        cout<<"Producto eliminado ";
    }else{
        
    }
    
}


void eliminar(void){
    if(buscar()){
        
        // elimina cabecera si es el unico dato
        if (aux->i ==NULL && aux->d == NULL && ant == NULL && aux->dato == dato) { // si el dato es la cabecera y es el unico dato
            cabecera = NULL;
            cout<<"Producto eliminado ";
            return;
        }
        if (aux->i ==NULL && aux->d != NULL && ant == NULL && aux->dato == dato) { // si cabecera tiene unico hijo derecho
            cabecera = NULL;
            cabecera = aux->d;
            cout<<"Producto eliminado ";
            return;
        }
        if (aux->i !=NULL && aux->d == NULL && ant == NULL && aux->dato == dato) { // si cabecera tiene unico  hijo izquierdo
            cabecera = NULL;
            cabecera = aux->i;
            cout<<"Producto eliminado ";
            return;
        }
        if(aux->i !=NULL && aux->d != NULL && ant == NULL && aux->dato == dato){ // si cabecera tiene los dos hijos y es el dato a borrar
            cabecera = NULL;
            cabecera = aux->d; // hijo de cabza derecha para a cabecera
            aux2 = aux->i; // hijo izquierado alamacenadoen auxiciliar 2
            acomodarMayorCab();
            return;
        }
        if(aux->i == NULL && aux->d == NULL && ant != NULL && aux->dato == dato){ // si es hoja
            if (ant->dato >aux->dato) {
                ant->i=NULL;
                aux=NULL;
            } else {
                ant->d=NULL;
                aux=NULL;
            }
            cout<<"Producto Eliminado ";
            return;
        }
        if(aux->i != NULL && aux->d != NULL && ant != NULL && aux->dato == dato){ // si es rama y tiene ambos hijos
            if (ant->dato >aux->dato) {  // si es rama izq
                ant->i=aux->d;
                aux2 = aux->i;
                aux=NULL;
                aux= ant->i;
                acomodarMenor(); //acomoda arbol de mayor a menor
                
            } else {                // si es rama der
                ant->d=aux->d;
                aux2 = aux->i;
                aux=NULL;
                aux= ant->d;
                acomodarMenor(); //acomoda arbol de mayor a menor
            }
            cout<<"Producto Eliminado ";
            return;
        }
        if(aux->i != NULL && aux->d == NULL && ant != NULL && aux->dato == dato){ // si rama solo tiene un hijo de lado izq
            if (ant->dato >aux->dato) {
                ant->i=aux->i;
                aux=NULL;
            } else {
                ant->d=aux->i;
                aux=NULL;
            }
            cout<<"Producto Eliminado ";
            return;
        }
        if(aux->i == NULL && aux->d != NULL && ant != NULL && aux->dato == dato){ // si rama solo tiene un hijo de lado der
            if (ant->dato >aux->dato) {
                ant->i=aux->d;
                aux=NULL;
            } else {
                ant->d=aux->d;
                aux=NULL;
            }
            cout<<"Producto Eliminado ";
            return;
        }
        
    }{
        cout<<"Producto No Encontrado ";
    }
    
}

//acomoda la cabecera cuando es el primer dato y tiene ambos hijos
void acomodarMayorCab(){
    aux = cabecera;
    while (aux->i) {       // recorre en busca del mas pequeño
        aux = aux->i;
        ant2 = aux;
    }
    aux->i = aux2;
    cout<<"Producto eliminado ";
    return;
}
//acomoda la cabecera cuando es el primer dato y tiene ambos hijos
void acomodarMenor(){
    
    while (aux->i) {       // recorre en busca del mas pequeño
        aux = aux->i;
        ant2 = aux;
    }
    aux->i = aux2;
    return;
}

// Funcion listar arbol
// @param : puntero tipo Arbol
void listar(arbol *aux)
{
    if (aux != NULL) {
        
        if(aux->estado==1)
        {
        	printf("%i\t%s\t\t\t%s\t%i\t%i\n", aux->dato , aux->descripcion, aux->empaque, aux->precio ,aux->estado);
		}
		listar(aux->i);
        listar(aux->d);   
    }  
}

void modificar(void)
{	
	int cen=0,op;  
	if(buscar())
	{
		dato=aux->dato;
		strcpy(descripcion , aux->descripcion);
        strcpy(empaque , aux->empaque);
		precio=aux->precio;
		estado=aux->estado;		
		eliminar();
		
		while(cen==0)
		{
			system("cls");
			cout<<"\n\n 1-Producto 2-Descripcion            3-empaque  4-precio  5-Estado    6-Terminar\n\n ";
            printf("%i\t%s\t\t\t%s\t%i\t%i\n", dato , descripcion, empaque, precio,estado );
			scanf("%i",&op); 
			switch(op)
			{
				case 1:
	                cout<<"\n\n Producto: ";
	                scanf("%i",&dato);          //ID del articulo a ingresar
	                break;
	            case 2:    
	                cout<<"\n\n Descripcion: ";
	                scanf("%s",descripcion);    // articulo a ingresar
	                break;
	            case 3:    
	                cout<<"\n\n Empaque: ";
	                scanf("%s",empaque);        //tipo de embase a ingresar
	                break;
	            case 4:
	                cout<<"\n\n Precio: ";
	                scanf("%i",&precio);        // precio de tipo entero a ingresar
	                break;
	            case 5:
	                cout<<("\n\n Estado (1 = activo, 0 = inactivo): ");
	                scanf("%i",&estado);
	                break;
	            case 6:
	            	cen=1;
	            	break;
	            default:
	            	cout<<("opcion incorrecta");
	            	system("pause");
			}
		}
		insertar();
	}
}


