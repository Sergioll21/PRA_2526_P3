#include <iostream>
#include <string>

template <typename V>
class TableEntry {
public:
    std::string key;   
    V value;           

    // Métodos

    // Constructor con clave y valor
    TableEntry(std::string key, V value) : key(key), value(value) {}

    // Constructor con solo clave (valor por defecto para value)
    TableEntry(std::string key) : key(key), value(V()) {}

    // Constructor por defecto (clave vacía y valor por defecto)
    TableEntry() : key(""), value(V()) {}

    // Sobrecarga del operador ==
    friend bool operator==(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key == te2.key;
    }

    // Sobrecarga del operador !=
    friend bool operator!=(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key != te2.key;
    }

    // Sobrecarga del operador << para impresión
    friend std::ostream& operator<<(std::ostream& out, const TableEntry<V>& te) {
        out << "Key: " << te.key << ", Value: " << te.value;
        return out;
    }
  };
