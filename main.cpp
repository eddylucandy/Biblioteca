#include <iostream>

#include "Biblioteca.h"

#include <list>

using namespace std;


int main() {
    Biblioteca biblioteca;
    string DNI,titulo, autor, apellido, nombre, categoria;
    // Agregar libros a la biblioteca
    biblioteca.AgregarLibro(Libro("Cien años de soledad", "Gabriel García Márquez", "Realismo mágico"));
    biblioteca.AgregarLibro(Libro("Moby Dick", "Herman Melville", "Aventura"));
    biblioteca.AgregarLibro(Libro("1984", "George Orwell", "Distopía"));
    biblioteca.AgregarLibro(Libro("La Odisea", "Homero", "Épica"));
    biblioteca.AgregarLibro(Libro("Matar un ruiseñor", "Harper Lee", "Drama"));
    biblioteca.AgregarLibro(Libro("Don Quijote", "Miguel de Cervantes", "Novela"));
    biblioteca.AgregarLibro(Libro("Drácula", "Bram Stoker", "Terror"));
    biblioteca.AgregarLibro(Libro("La Divina Comedia", "Dante Alighieri", "Poesía épica"));
    biblioteca.AgregarLibro(Libro("El retrato de Dorian Gray", "Oscar Wilde", "Novela gótica"));
    biblioteca.AgregarLibro(Libro("Crimen y castigo", "Fiodor Dostoievski", "Novela psicológica"));
    biblioteca.AgregarLibro(Libro("Mujercitas", "Louisa May Alcott", "Novela juvenil"));
    biblioteca.AgregarLibro(Libro("Mujer en punto cero", "Nawal El Saadawi", "Ficción social"));
    biblioteca.AgregarLibro(Libro("Las uvas de la ira", "John Steinbeck", "Novela social"));
    biblioteca.AgregarLibro(Libro("El Extranjero", "Albert Camus", "Filosofía"));
    biblioteca.AgregarLibro(Libro("Anna Karenina", "León Tolstói", "Realismo"));
    biblioteca.AgregarLibro(Libro("El guardián entre el centeno", "J.D. Salinger", "Novela iniciática"));
    biblioteca.AgregarLibro(Libro("La metamorfosis", "Franz Kafka", "Novela corta"));
    biblioteca.AgregarLibro(Libro("El corazón de las tinieblas", "Joseph Conrad", "Novela corta"));
    biblioteca.AgregarLibro(Libro("El proceso", "Franz Kafka", "Novela"));
    biblioteca.AgregarLibro(Libro("El gran Gatsby", "F. Scott Fitzgerald", "Novela"));

    // Agregar usuarios
    biblioteca.AgregarUsuario(Usuario("Carlos", "Gómez", "54321"));
    biblioteca.AgregarUsuario(Usuario("Laura", "Hernández", "09876"));
    biblioteca.AgregarUsuario(Usuario("Luis", "Martínez", "13579"));
    biblioteca.AgregarUsuario(Usuario("Ana", "Sánchez", "24680"));
    biblioteca.AgregarUsuario(Usuario("Pedro", "López", "98765"));
    biblioteca.AgregarUsuario(Usuario("Sofía", "Rodríguez", "56789"));
    biblioteca.AgregarUsuario(Usuario("Diego", "Díaz", "65432"));
    biblioteca.AgregarUsuario(Usuario("Marta", "Ruiz", "32146"));
    biblioteca.AgregarUsuario(Usuario("Javier", "García", "78901"));
    biblioteca.AgregarUsuario(Usuario("Elena", "Fernández", "43210"));
    biblioteca.AgregarUsuario(Usuario("Mario", "Pérez", "34567"));
    biblioteca.AgregarUsuario(Usuario("Carolina", "González", "01234"));
    biblioteca.AgregarUsuario(Usuario("Raúl", "Martínez", "67891"));
    biblioteca.AgregarUsuario(Usuario("Cristina", "Sánchez", "89012"));
    biblioteca.AgregarUsuario(Usuario("David", "López", "34561"));
    biblioteca.AgregarUsuario(Usuario("Lorena", "Rodríguez", "78901"));
    biblioteca.AgregarUsuario(Usuario("Oscar", "Díaz", "23456"));
    biblioteca.AgregarUsuario(Usuario("Natalia", "Ruiz", "67890"));
    biblioteca.AgregarUsuario(Usuario("Miguel", "García", "12345"));
    biblioteca.AgregarUsuario(Usuario("Julia", "Fernández", "67890"));

    int opcion;

    do {
        cout << endl
             << "---------------- M E N U ----------------" << endl;
        cout << "¦                                       ¦" << endl;
        cout << "¦  1. Libros disponibles                ¦" << endl;
        cout << "¦                                       ¦" << endl;
        cout << "¦  2. Agregar libro                     ¦" << endl;
        cout << "¦                                       ¦" << endl;
        cout << "¦  3. Agregar Usuario                   ¦" << endl;
        cout << "¦                                       ¦" << endl;
        cout << "¦  4. Historial de un usuario           ¦" << endl;
        cout << "¦                                       ¦" << endl;
        cout << "¦  5. Consulta de libros prestado       ¦" << endl;
        cout << "¦                                       ¦" << endl;
        cout << "¦  6. Sacar libro                       ¦" << endl;
        cout << "¦                                       ¦" << endl;
        cout << "¦  7. Devolver libro                    ¦" << endl;
        cout << "¦                                       ¦" << endl;
        cout << "¦  8. Salir                             ¦" << endl;
        cout << "¦                                       ¦" << endl;
        cout << "-----------------------------------------*" << endl
        << endl;

        cin >> opcion;

        switch (opcion) {
        case 1:
            biblioteca.ComprobarLibrosDisponibles();
            break;
        case 2:
            cout << "Que libro desea anadir? ";
            cin >> titulo;
            cout << "Cual es su autor?";
            cin >> autor;
            cout << "Por Ultimo cual es su categoria? ";
            cin >> categoria;
            biblioteca.AgregarLibro(Libro(titulo, autor, categoria));
            break;
        case 3:
            cout << "Cual es su Nombre?";
            cin >> nombre;
            cout << "Cual es su Apellido?";
            cin >> apellido;
            cout << "Cual es su DNI?";
            cin >> DNI;
            biblioteca.AgregarUsuario(Usuario(nombre, apellido, DNI));
            break;
        case 4:
            cout << "De que usuario desea ver el historial(Escriba su DNI):  ";
            cin >> DNI;
            biblioteca.VerHistorialDeUsuario(DNI);    
            break;
        case 5:
            cout << "De que usuario desea ver si tiene ese libro(Escriba su DNI):  ";
            cin >> DNI;
            cout << "Cual es el título del libro:";
            cin >> titulo;
            if (biblioteca.VerificarSiUsuarioTieneLibro(DNI, titulo))
            {
                cout << "Si lo tiene" << endl;
            }
            else
            {
                cout << "No lo tiene" << endl;
            }
            break;
        case 6:
            // Aquí puedes solicitar al usuario que ingrese el DNI y el título del libro y luego sacar el libro.
            cout << "Quien es usted : ";
            cin >> DNI;
            cout << "Que libro desea sacar: ";
            cin >> titulo;
            biblioteca.SacarLibro(DNI, titulo);
            break;
        case 7:
            cout << "Quien es usted : ";
            cin >> DNI;
            cout << "Que libro desea devolver: ";
            cin >> titulo;
            biblioteca.DevolverLibro(DNI, titulo);
           
            break;
        case 8:
            // Salir del programa
            break;
        default:
            cout << "Opción no válida. Intente de nuevo.\n";
            break;
        }

    } while (opcion != 8);
 

    return 0;
}