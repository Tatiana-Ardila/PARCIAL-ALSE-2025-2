#include "Producto.h"
#include <iostream>

Producto::Producto(std::string nombre, float precio, int stock, int descuento)
    : nombre(nombre), precio(precio), stock(stock), descuento(descuento) {}

void Producto::actualizarPrecio(float nuevoPrecio) {
    precio = nuevoPrecio;
}

void Producto::resumenProducto() const {
    std::cout << "Producto: " << nombre
              << "\nPrecio: $" << precio
              << "\nStock: " << stock
              << "\nDescuento: " << descuento << "%"
              << "\nValor total inventario: $" << consultarValorInventario()
              << "\n-----------------------------\n";
}

float Producto::vender(int cantidad) {
    if (cantidad > stock) {
        std::cout << "No hay suficiente stock de " << nombre << ".\n";
        return 0.0f;
    }
    stock -= cantidad;
    float precioConDescuento = precio * (1 - descuento / 100.0f);
    return cantidad * precioConDescuento;
}

void Producto::reabastecer(int cantidad) {
    stock += cantidad;
}

float Producto::consultarValorInventario() const {
    return precio * stock;
}

std::string Producto::getNombre() const { return nombre; }
float Producto::getPrecio() const { return precio; }
int Producto::getStock() const { return stock; }
int Producto::getDescuento() const { return descuento; }
