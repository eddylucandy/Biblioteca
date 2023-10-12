#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Libro {
public:
    string titulo;
    string autor;
    string categoria;
    bool disponible;

    Libro() : titulo(""), autor(""), categoria(""), disponible(true) {}

    Libro(string _titulo, string _autor, string _categoria) : titulo(_titulo), autor(_autor), categoria(_categoria), disponible(true) {}
};

class Usuario {
public:
    string nombre;
    string apellidos;
    string DNI;
    Libro libroActual;
    vector<Libro> historial;

    Usuario(string _nombre, string _apellidos, string _DNI) : nombre(_nombre), apellidos(_apellidos), DNI(_DNI) {}
};

class Biblioteca {
public:
    vector<Libro> libros;
    vector<Usuario> usuarios;
    void AgregarLibro(Libro libro) {
        libros.push_back(libro);
    }

    void AgregarUsuario(Usuario usuario) {
        usuarios.push_back(usuario);
    }

    void ComprobarLibrosDisponibles() {
        cout << "Libros disponibles:\n";
        for (const Libro& libro : libros) {
            if (libro.disponible) {
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