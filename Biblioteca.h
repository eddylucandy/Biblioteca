#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definición de la clase "Libro"
class Libro {
public:
    string titulo;      // Título del libro
    string autor;       // Autor del libro
    string categoria;   // Categoría del libro
    bool disponible;    // Indica si el libro está disponible

    // Constructor por defecto
    Libro() : titulo(""), autor(""), categoria(""), disponible(true) {}

    // Constructor con parámetros
    Libro(string _titulo, string _autor, string _categoria) : titulo(_titulo), autor(_autor), categoria(_categoria), disponible(true) {}
};

// Definición de la clase "Usuario"
class Usuario {
public:
    string nombre;          // Nombre del usuario
    string apellidos;       // Apellidos del usuario
    string DNI;             // DNI del usuario
    Libro libroActual;      // Libro actualmente prestado por el usuario
    vector<Libro> historial;   // Historial de libros prestados por el usuario

    // Constructor con parámetros
    Usuario(string _nombre, string _apellidos, string _DNI) : nombre(_nombre), apellidos(_apellidos), DNI(_DNI) {}
};

// Definición de la clase "Biblioteca"
class Biblioteca {
public:
    vector<Libro> libros;   // Vector que almacena los libros de la biblioteca
    vector<Usuario> usuarios;  // Vector que almacena los usuarios de la biblioteca

    // Método para agregar un libro a la biblioteca
    void AgregarLibro(Libro libro) {
        libros.push_back(libro);
    }

    // Método para agregar un usuario a la biblioteca
    void AgregarUsuario(Usuario usuario) {
        usuarios.push_back(usuario);
    }


    //Metodo que Compruoba la disponibilidad de los libros .
    void ComprobarLibrosDisponibles() {
        //comentario de cabezera.
        cout << "Libros disponibles:\n";
    
        // Bucle que recorre cada elemento en el vector "libros".
        for (const Libro& libro : libros) {
            // Para cada libro, se verifica si está disponible.
            if (libro.disponible) {
                // Si el libro está disponible, se imprime su título y categoría.
                cout << libro.titulo << " - " << libro.categoria << "\n";
            }
        } 
    }



    void VerHistorialDeUsuario(string DNI) {
        for (Usuario& usuario : usuarios) {
            if (usuario.DNI == DNI) {
                cout << "Historial de libros para " << usuario.nombre << " " << usuario.apellidos << ":\n";
                for (const Libro& libro : usuario.historial) {
                    cout << libro.titulo << " - " << libro.categoria << "\n";
                }
                return;
            }
        }
        cout << "Usuario no encontrado.\n";
    }

    bool VerificarSiUsuarioTieneLibro(string DNI, string tituloLibro) {
        for (Usuario& usuario : usuarios) {
            if (usuario.DNI == DNI && usuario.libroActual.titulo == tituloLibro) {
                return true;
            }
        }
        return false;
    }

    void SacarLibro(string DNI, string tituloLibro) {
        for (Usuario& usuario : usuarios) {
            if (usuario.DNI == DNI && usuario.libroActual.titulo.empty()) {
                for (Libro& libro : libros) {
                    if (libro.titulo == tituloLibro && libro.disponible) {
                        libro.disponible = false;
                        usuario.libroActual = libro;
                        cout << "Libro sacado con éxito" << endl;
                        return;
                    }
                }
            }
        }
    }

    void DevolverLibro(string DNI, string tituloLibro) {
        for (Usuario& usuario : usuarios) {
            if (usuario.DNI == DNI && usuario.libroActual.titulo == tituloLibro) {
                for (Libro& libro : libros) {
                    if (libro.titulo == tituloLibro) {
                        libro.disponible = true;
                        usuario.historial.push_back(usuario.libroActual);
                        usuario.libroActual = Libro("", "", "");
                        cout << "Libro devuelto con éxito" << endl;
                        return;
                    }
                }
            }
        }
    }
};

#endif //