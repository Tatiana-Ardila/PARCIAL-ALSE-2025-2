#include <iostream>
#include <vector>
#include <fstream>
#include "Producto.h"

int main() {
    std::vector<Producto> inventario;

    // Crear productos iniciales
    inventario.emplace_back("Celular", 1200.0f, 10, 5);
    inventario.emplace_back("Portátil", 3200.0f, 5, 10);
    inventario.emplace_back("Audífonos", 250.0f, 20, 15);
    inventario.emplace_back("Mouse", 80.0f, 30, 0);

    // Simular operaciones
    std::cout << "\n=== Simulación de Tienda en Línea ===\n";
    inventario[0].vender(2);         // vender 2 celulares
    inventario[1].reabastecer(3);    // reabastecer portátiles
    inventario[2].actualizarPrecio(230.0f); // cambio de precio
    inventario[3].vender(10);        // vender 10 mouse

    // Mostrar resumen de todos los productos
    float totalInventario = 0.0f;
    std::cout << "\n=== Resumen de Inventario ===\n";
    for (auto &p : inventario) {
        p.resumenProducto();
        totalInventario += p.consultarValorInventario();
    }

    std::cout << "Valor total del inventario: $" << totalInventario << "\n";

    // BONO: generar reporte en .txt
    std::ofstream reporte("reporte.txt");
    if (reporte.is_open()) {
        reporte << "=== Reporte de Inventario ===\n";
        for (auto &p : inventario) {
            reporte << p.getNombre() << " - Precio: $" << p.getPrecio()
                    << " - Valor Inventario: $" << p.consultarValorInventario() << "\n";
        }
        reporte << "\nValor total del inventario: $" << totalInventario << "\n";
        reporte.close();
        std::cout << "\nReporte generado exitosamente en 'reporte.txt'.\n";
    } else {
        std::cout << "Error al crear el reporte.\n";
    }

    return 0;
}
