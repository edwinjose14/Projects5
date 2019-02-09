#include<iostream>
#include <windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<cstring>
#include <fstream>
using namespace std;
void gotoxy(int x,int y);
void marco(int x1, int y1, int x2, int y2,bool linea);
void captura();
void imprimir();
void buscar_nombre();
void buscar_telefono();
void actualizar();
void Eliminar();


struct agenda{
char cedula[25];
char nombre[25];
char apellido[25];
char sexo[25];
char telefono[25];
char direccion[35];
char correo[30];

}
p[25];

char sn[10];
int registro=0;
int tele;

int main(){
	
int op=0;
	do{
	   system("cls");	
	   system ("color 3A");	
	   marco(5,2,50,25,true);
   gotoxy(15,4);cout <<"AGENDA TELEFONICA";
   gotoxy(12,7);cout << "1. Anadir un contacto." ;
   gotoxy(12,9);cout << "2. ver contactos agregados.";
   gotoxy(12,11);cout << "3. buscar conctato por nombre.";
   gotoxy(12,13);cout << "4. buscar conctato por telefono.";
   gotoxy(12,15);cout << "5. actualizar contacto";
   gotoxy(12,17);cout << "6. eliminar contacto";
   gotoxy(12,19);cout << "7. Ver registro en Agenda.txt";
   gotoxy(12,21);cout << "8. Salir.";
   gotoxy(12,23);cout << "Numero de operacion a realizar:( ) ";
   gotoxy(44,23);cin >> op;
		switch(op){
			case 1:
					captura();
					break;
			case 2:
					imprimir();
					break;
			case 3:
					buscar_nombre();
					break;
			case 4:
					buscar_telefono();
					break;
            case 5:
				    actualizar();
					break;

            case 6:
				    Eliminar();
					break;
            case 7:
				    system("Agenda.txt");
				    main();
					break;
            case 8:

                    //exit(0);
                    break;

                    default:

                    cout<<"Operacion incorrecta. Escriba nuevamente la operacion a realizar";
                    main();
                    break;  
		}	
	}while(op!=8);
	
getche();
return 0;
}
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos); 

}
void captura(){
	 char op;
	 int i=0;
	 int cont;
	 system("cls");
	  

	 do{
	 	 system("cls");
	 	 //marco(5,2,50,25,true);
	 	 marco(0,0,117,25,true);
	 	 gotoxy(51,1);cout<<"AGENDA TELEFONICA";
	 	 gotoxy(37,4);cout<<" CAPTURA DE LOS DATOS DE LA PERSONA "<<endl<<endl; 
	 	gotoxy(2,5);cout<<"cedula";
        gotoxy(18,5);cout<<"Nombre";
        gotoxy(37,5);cout<<"Apellido";
        gotoxy(51,5);cout<<"sexo";
        gotoxy(60,5);cout<<"telefono";
        gotoxy(72,5);cout<<"correo electronico";
        gotoxy(102,5);cout<<"direccion";
	 	gotoxy(2,6);cin>>p[i].cedula; 
        gotoxy(18,6);cin>>p[i].nombre;
        gotoxy(37,6);cin>>p[i].apellido;
        gotoxy(51,6);cin>>p[i].sexo;
        gotoxy(60,6);cin>>p[i].telefono;
        gotoxy(72,6);cin>>p[i].correo;
        gotoxy(102,6);cin>>p[i].direccion;
	 	
	 	{
	 		ofstream archivo;

            archivo.open("Agenda.txt", ios::app);
            archivo<<"contacto"<<endl;
            archivo<< "cedula: "<< p[registro].cedula<<endl;
            archivo<< "Nombre: "<< p[registro].nombre<<endl;
            archivo<<"Apellido: "<< p[registro].apellido<<endl;
            archivo<<"sexo: "<< p[registro].sexo<<endl;
            archivo<<"telefono: "<< p[registro].telefono<<endl;
            archivo<<"correo: "<< p[registro].correo<<endl;
            archivo<<"direccion: "<< p[registro].direccion<<endl;
            archivo<<endl;
            archivo.close();
        registro++;
            cout << endl << "Contacto anadido." << endl;
		 }
		 i++;
	 	cout<<"Desea ingresar otra persona  ? s/n:  ";
	 	cin>>op;
	 }while(op=='s'||op=='S');
	
	main();
	
}

void imprimir(){
system("cls");
int i;
marco(0,0,117,25,true);
gotoxy(51,1);cout<<"AGENDA TELEFONICA";
gotoxy(37,4);cout<<"LOS DATOS GENERALES REGISTRADOS SON";
	    gotoxy(2,5);cout<<"cedula";
        gotoxy(18,5);cout<<"Nombre";
        gotoxy(37,5);cout<<"Apellido";
        gotoxy(51,5);cout<<"sexo";
        gotoxy(60,5);cout<<"telefono";
        gotoxy(72,5);cout<<"correo electronico";
        gotoxy(102,5);cout<<"direccion";

for(i = 0;i<registro;i++){
gotoxy(2,i+6);cout<<p[i].cedula; 
gotoxy(18,i+6);cout<<p[i].nombre;
gotoxy(37,i+6);cout<<p[i].apellido;
gotoxy(53,i+6);cout<<p[i].sexo;
gotoxy(60,i+6);cout<<p[i].telefono;
gotoxy(72,i+6);cout<<p[i].correo;
gotoxy(102,i+6);cout<<p[i].direccion;

}
cout<<endl;
system("pause");
main();	
}

void buscar_nombre(){
	int i,j,op;
	system("cls");
	char nom[25];
	int encontrado=0;
//	cout<<endl<<endl;
marco(0,0,117,25,true);
            gotoxy(51,1);cout<<"AGENDA TELEFONICA";
			gotoxy(2,4);cout<<"INGRESE EL NOMBRE DEL CONTACTO QUE DESEA BUSCAR:[            ]";
				gotoxy(51,4);cin>>nom;
				for(i=0;i<registro;i++){
				if(strcmp(p[i].nombre,nom)==0){
					
					if(p[i].telefono!=0){
					
                 	    gotoxy(2,5);cout<<"cedula";
                        gotoxy(18,5);cout<<"Nombre";
                        gotoxy(37,5);cout<<"Apellido";
                        gotoxy(51,5);cout<<"sexo";
                        gotoxy(60,5);cout<<"telefono";
                        gotoxy(72,5);cout<<"correo electronico";
                        gotoxy(102,5);cout<<"direccion";
						gotoxy(2,6);cout<<p[i].cedula; 
                        gotoxy(18,6);cout<<p[i].nombre;
                        gotoxy(37,6);cout<<p[i].apellido;
                        gotoxy(53,6);cout<<p[i].sexo;
                        gotoxy(60,6);cout<<p[i].telefono;
                        gotoxy(72,6);cout<<p[i].correo;
                        gotoxy(102,6);cout<<p[i].direccion;
						cout<<endl;
						j=1;
						system("pause");
						system("cls");
					}
					
				}
				}
				if(j!=1){
					gotoxy(2,5);cout<<"no esxiste esa persona en la lista de contacto."<<endl;
					system("pause");
					system("cls");
				}
}

void buscar_telefono(){
	int i,j,op;
	system("cls");
	char tele[25];
	int encontrado=0;
	cout<<endl<<endl;
	marco(0,0,117,25,true);
	gotoxy(51,1);cout<<"AGENDA TELEFONICA";
			gotoxy(3,4);cout<<"INGRESE EL TELEFONO DEL CONTACTO QUE DESEA BUSCAR:[           ]";
				gotoxy(54,4);cin>>tele;
				for(i=0;i<registro;i++){
				if(strcmp(p[i].telefono,tele)==0){
					
					if(p[i].telefono!=0){
						gotoxy(2,5);cout<<"cedula";
                        gotoxy(18,5);cout<<"Nombre";
                        gotoxy(37,5);cout<<"Apellido";
                        gotoxy(51,5);cout<<"sexo";
                        gotoxy(60,5);cout<<"telefono";
                        gotoxy(72,5);cout<<"correo electronico";
                        gotoxy(102,5);cout<<"direccion";
						gotoxy(2,6);cout<<p[i].cedula; 
                        gotoxy(18,6);cout<<p[i].nombre;
                        gotoxy(37,6);cout<<p[i].apellido;
                        gotoxy(53,6);cout<<p[i].sexo;
                        gotoxy(60,6);cout<<p[i].telefono;
                        gotoxy(72,6);cout<<p[i].correo;
                        gotoxy(102,6);cout<<p[i].direccion;
						cout<<endl;
						j=1;
						system("pause");
						system("cls");
					}
					
				}
				}
				if(j!=1){
					gotoxy(2,5);cout<<"no esxiste ese telefono en la lista de contacto."<<endl;
					system("pause");
					system("cls");
				}
}

void actualizar(){
system("cls");
fflush(stdin);
int i = 0;
int pos = 0;
char encontro = 'n';
char op;
char id[20];
char seguir = 's';
marco(0,0,117,25,true);
gotoxy(51,1);cout<<"AGENDA TELEFONICA";
gotoxy(3,4);cout<<"INGRESA LA CEDULA DE LA PERSONA A MODIFICAR:[           ]"<<endl;
gotoxy(49,4);cin>>id;
while(i<=registro){
if(strcmp(p[i].cedula,id)==0){
	gotoxy(2,5);cout<<"cedula";
      gotoxy(18,5);cout<<"Nombre";
        gotoxy(37,5);cout<<"Apellido";
         gotoxy(51,5);cout<<"sexo";
        gotoxy(60,5);cout<<"telefono";
       gotoxy(72,5);cout<<"correo electronico";
      gotoxy(102,5);cout<<"direccion";
		gotoxy(2,6);cout<<p[i].cedula; 
         gotoxy(18,6);cout<<p[i].nombre;
          gotoxy(37,6);cout<<p[i].apellido;
             gotoxy(53,6);cout<<p[i].sexo;
          gotoxy(60,6);cout<<p[i].telefono;
             gotoxy(72,6);cout<<p[i].correo;
               gotoxy(102,6);cout<<p[i].direccion;       
encontro = 's';
pos = i;
}        
i++;



if(encontro == 's'){
gotoxy(3,8);cout<<"desea modificar los datos de este contacto s/n:  ";
cin>>op;
while(op=='s'||op=='S') {
gotoxy(3,9);cout<<"Ingrese los datos corregidos "<<endl;        
gotoxy(2,11);cout<<"cedula";
        gotoxy(18,11);cout<<"Nombre";
        gotoxy(37,11);cout<<"Apellido";
        gotoxy(51,11);cout<<"sexo";
        gotoxy(60,11);cout<<"telefono";
        gotoxy(72,11);cout<<"correo electronico";
        gotoxy(102,11);cout<<"direccion";
	 	gotoxy(2,12);cin>>p[pos].cedula; 
        gotoxy(18,12);cin>>p[pos].nombre;
        gotoxy(37,12);cin>>p[pos].apellido;
        gotoxy(51,12);cin>>p[pos].sexo;
        gotoxy(60,12);cin>>p[pos].telefono;
        gotoxy(72,12);cin>>p[pos].correo;
        gotoxy(102,12);cin>>p[pos].direccion;
cout<<endl;  
gotoxy(3,12);cout<<"contacto actualizado...."<<endl;
system("pause");
main();
}


main();
}
else{
cout<<"la cedula ingresada no coincide base de datos..."<<endl;        
system("pause");
main();       
        
}

cout<<" presione una tecla para ir al menu principal";
system("pause");
main();

}
}

void Eliminar(){
system("cls");
char ce[20];
char seguro ;
int pos = 0;
char seguir = 's';
char encontro ='n';
int i=0;
marco(0,0,117,25,true);
gotoxy(51,1);cout<<"AGENDA TELEFONICA";
while(seguir == 's'||seguir=='S'){
gotoxy(3,4);cout<<"INGRESE LA CEDULA DE LA PERSONA QUE DESEA ELIMINAR:[              ]";
gotoxy(55,4);cin>>ce;
while(i<=registro && encontro == 'n'){
if(strcmp(p[i].cedula,ce)==0){
gotoxy(2,5);cout<<"Datos de la persona encontrados"<<endl;
	gotoxy(2,6);cout<<"cedula";
      gotoxy(18,6);cout<<"Nombre";
        gotoxy(37,6);cout<<"Apellido";
         gotoxy(51,6);cout<<"sexo";
        gotoxy(60,6);cout<<"telefono";
       gotoxy(72,6);cout<<"correo electronico";
      gotoxy(102,6);cout<<"direccion";
		gotoxy(2,7);cout<<p[i].cedula; 
         gotoxy(18,7);cout<<p[i].nombre;
          gotoxy(37,7);cout<<p[i].apellido;
             gotoxy(53,7);cout<<p[i].sexo;
          gotoxy(60,7);cout<<p[i].telefono;
             gotoxy(72,7);cout<<p[i].correo;
               gotoxy(102,7);cout<<p[i].direccion;       
encontro = 's';
pos = i;
}else{
i=i+1;
}
}
if(encontro=='n'){
cout<<"No se encontro persona coincidente para eliminar"<<endl;
        
}  else{
 cout<<endl;       
gotoxy(3,7);cout<<"Esta seguro que desea eliminar la persona s/n:[    ] "<<endl;
gotoxy(50,7);cin>>seguro;
if(seguro=='s'||seguro=='S'){
if(pos==registro){
registro=registro-1;
                        
 }else{                   
 for(int i = pos + 1 ;i<=registro;i++){
 p[i-1]=p[i];
                                
 }
 registro = registro -1;
 }
                
}
        
}
gotoxy(3,8);cout<<"contacto eliminado"<<endl;
        
gotoxy(3,9);cout<<"Desea eliminar otra persona s/n:[   ]"<<endl;
gotoxy(36,9);cin>>seguir;
        
}
}
void marco(int x1, int y1, int x2, int y2, bool linea){
int i;
// getchar();
for (i=x1;i<=x2;i++){
gotoxy(i,y1);cout<<"*";
}
//linea adicional
if (linea){
for (i=x1;i<=x2;i++){
gotoxy(i,y1+3);cout<<"*";
}
}
// fin linea
// getchar();
for (i=x1;i<=x2;i++){
gotoxy(i,y2);cout<<"*";
}
// getchar();
for (i=y1;i<=y2;i++){
gotoxy(x1,i);cout<<"*";
}
// getchar();
for (i=y1;i<=y2;i++){
gotoxy(x2,i);cout<<"*";
}
}
