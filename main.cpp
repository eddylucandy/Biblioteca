#include <iostream>
#include <list>

using namespace std;

// clase Libro
class Book
{
public:
    // parametros
    string id, title;
    bool isAvailable;
    string category;

public:
    // constructor
    Book(){};
    Book(string id, string category, string title)
    {
        this->id = id;
        this->title = title;
        this->isAvailable = true;
        this->category = category;
    }
    // metodo get-set para declarar si esta disponible
    void setAvailable(bool isAvailable)
    {
        this->isAvailable = isAvailable;
    }
    bool getAvailable()
    {
        return this->isAvailable;
    }
    string getId()
    {
        return this->id;
    }
    string to_string()
    {
        return "LIBRO: ID: " + this->id + "| TITULO: " + this->title + "| CATEGORIA: " + this->category;
    }
};
// Clase Usuario
class User
{
private:
    // parametros
    string nombre, apellidos, DNI;
    Book libroActual;
    list<Book> historial;

public:
    // constructor
    User(string nombre, string apellidos, string DNI)
    {
        this->nombre = nombre;
        this->apellidos = apellidos;
        this->DNI = DNI;
        this->libroActual = Book("", "", "");
    }
    // metodo get-set para declarar que libro tiene prestado ahora
    Book getLibroActual()
    {
        return this->libroActual;
    }
    void setLibroActual(Book l)
    {
        this->libroActual = l;
        this->historial.push_back(this->libroActual);
    }
    // metodos
    list<Book> getHistorial()
    {
        return this->historial;
    }
    void vaciarLibroActual()
    {
        this->libroActual = Book("", "", "");
    }
    string getDni()
    {
        return this->DNI;
    }
    string to_string()
    {
        return "USUARIO: NOMBRE: " + this->nombre + "| APELLIDOS: " + this->apellidos + "| DNI: " + this->DNI;
    }
};


// clase biblioteca
class Biblioteca
{
private:
    // array de libros
    list<Book> libros;
    list<User> usuarios;

public:
    Biblioteca(list<Book> librosInciales, list<User> usuarios)
    {

        this->libros = librosInciales;
        this->usuarios = usuarios;
    }
    // comprobar que libros hay disponibles
    void imprimirLibrosDisponibles()
    {
        int contador = 0;
        cout << endl
             << "*** - - -  LISTADO DE LIBROS DISPONIBLES - - - ***" << endl
             << endl;
        for (Book &libro : this->libros)
        {
            if (libro.getAvailable())
            {
                contador++;
                cout << endl
                     << "DISPONIBLE: " << libro.to_string() << endl;
            }
        }
        if (contador == 0)
        {
            cout << endl
                 << "- - - - - - NO HAY LIBROS DISPONIBLES - - - - - -" << endl;
        }
        cout << endl << endl 
             << "***********************************************" << endl
             << endl;
    }

     // imprimir libros disponibles y prestados

    void reviseAveilableBooks()
    {
        imprimirLibrosDisponibles();
        //imprimirLibrosPrestados();
    }
        // imprimir historial de usuario

    void reviseHistorialFromUser(User u)
    {
        cout << endl
             << "***  HISTORIAL DE LIBROS DEL USUARIO  (" << u.getHistorial().size() << ") ***" << endl;
        cout << u.to_string() << endl
             << endl;
        for (Book &libro : u.getHistorial())
        {
            cout << "Prestado a usuario: " << libro.to_string() << endl;
        }
    }


    list<Book> getLibros()
    {
        return this->libros;
    }
    list<User> getUsuarios()
    {
        return this->usuarios;
    }
    void setLibros(list<Book> libros)
    {
        this->libros = libros;
    }
    void setUsuarios(list<User> usuarios)
    {
        this->usuarios = usuarios;
    }


    //agregar libro 
void agregarLibro(const Book& libro) {
        this->libros.push_back(libro);
    }
//agregar usuario
    void agregarUsuario(const User& usuario) {
        this->usuarios.push_back(usuario);
    }

};


//Libros disponibles 
void mostrarLibrosDisponibles(Biblioteca &b){
    b.reviseAveilableBooks();
}


void libro(Biblioteca &b){
    string id, category, title;
    cout << "Ingrese el ID del libro: ";
    cin >> id;
    cout << "Ingrese la categoría del libro: ";
    cin >> category;
    cout << "Ingrese el título del libro: ";
    cin >> title;

    Book nuevoLibro(id, category, title);
    b.agregarLibro(nuevoLibro);
}

void usuario(Biblioteca &b){
    string nombre, apellidos, DNI;
    cout << "Ingrese el nombre del usuario: ";
    cin >> nombre;
    cout << "Ingrese los apellidos del usuario: ";
    cin >> apellidos;
    cout << "Ingrese el DNI del usuario: ";
    cin >> DNI;

    User nuevoUsuario(nombre, apellidos, DNI);
    b.agregarUsuario(nuevoUsuario);
}




void mostrarMenu() {
    cout << endl
         << endl
         << "---------------- M E N U ----------------" << endl;
    cout << "¦                                       ¦" << endl;
    cout << "¦  1. Libros disponibles                ¦" << endl;
    cout << "¦                                       ¦" << endl;
    cout << "¦  2. Historial de un usuario           ¦" << endl;
    cout << "¦                                       ¦" << endl;
    cout << "¦  3. Prestar libro                     ¦" << endl;
    cout << "¦                                       ¦" << endl;
    cout << "¦  4. Devolver libro                    ¦" << endl;
    cout << "¦                                       ¦" << endl;
    cout << "¦  5. Consulta de libros prestado       ¦" << endl;
    cout << "¦                                       ¦" << endl;
    cout << "¦  6. Consulta de libros prestado       ¦" << endl;
    cout << "¦                                       ¦" << endl;
    cout << "¦  7. Consulta de libros prestado       ¦" << endl;
    cout << "¦                                       ¦" << endl;
    cout << "¦  8. Salir                             ¦" << endl;
    cout << "¦                                       ¦" << endl;
    cout << "-----------------------------------------*" << endl
         << endl;
}

int main() {
    std::cout << "Hola mi gente" << std::endl;
    return 0;
}
