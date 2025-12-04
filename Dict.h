#ifndef DICT_H
#define DICT_H
#include <iostream>
#include <string>
#include <stdexcept>

template <typename V>
class Diccionario {
private:
    struct ParClaveValor {
        std::string clave;
        V valor;
    };

    std::vector<ParClaveValor> datos;

public:
    // Insertar un par key->value
    void insert(const std::string& key, V value) {
        // Comprobar si la clave ya existe
        for (const auto& par : datos) {
            if (par.clave == key) {
                throw std::runtime_error("La clave ya existe en el diccionario.");
            }
        }
        // Si no existe, agregar el nuevo par
        datos.push_back({key, value});
    }

    // Buscar el valor correspondiente a una clave
    V search(const std::string& key) {
        for (const auto& par : datos) {
            if (par.clave == key) {
                return par.valor;
            }
        }
        throw std::runtime_error("La clave no se encuentra en el diccionario.");
    }

    // Eliminar un par key->value
    V remove(const std::string& key) {
        for (auto it = datos.begin(); it != datos.end(); ++it) {
            if (it->clave == key) {
                V valor = it->valor;
                datos.erase(it); // Eliminar el par
                return valor;
            }
        }
        throw std::runtime_error("La clave no se encuentra en el diccionario.");
    }

    // Obtener el número de elementos en el diccionario
    int entries() const {
        return datos.size();
    }
};

int main() {
    try {
        Diccionario<int> diccionario;

        diccionario.insert("uno", 1);
        diccionario.insert("dos", 2);

        std::cout << "Valor asociado con 'uno': " << diccionario.search("uno") << std::endl;
        std::cout << "Número de entradas: " << diccionario.entries() << std::endl;

        diccionario.remove("uno");
        std::cout << "Número de entradas después de eliminar 'uno': " << diccionario.entries() << std::endl;

        // Intentar buscar una clave eliminada
        diccionario.search("uno");  // Esto lanzará una excepción

    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

