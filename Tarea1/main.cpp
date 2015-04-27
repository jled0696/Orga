#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Alumno {
   char nombre[25];
   int cuenta;
   char carrera[25];
   char fecha[25];
   char universidad[25];
};

int main() {
   Alumno write;
   Alumno read;
   ofstream escribe("archivo.dat",ios::out | ios::binary);

   strcpy(write.nombre, "Jose Espinoza");
   write.cuenta = 1;
   strcpy(write.carrera, "Ingeneria en Sistemas");
   strcpy(write.fecha, "26 de abril de 2014");
   strcpy(write.universidad, "UNITEC");

   escribe.write(reinterpret_cast<char *>(&write), sizeof(Alumno));
   escribe.close();

   ifstream lee("archivo.dat", ios::in | ios::binary);

   lee.read(reinterpret_cast<char *>(&read), sizeof(Alumno));
   cout << read.nombre << endl;
   cout << read.cuenta << endl;
   cout << read.carrera << endl;
   cout << read.fecha << endl;
   cout << read.universidad << endl;
   lee.close();

   return 0;
}
