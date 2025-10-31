#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

/**
 * @brief Clase que representa un producto dentro de una tienda en línea.
 * @author 
 * @date 2025
 */
class Producto {
private:
    std::string nombre;  ///< Nombre del producto
    float precio;        ///< Precio unitario del producto
    int stock;           ///< Unidades disponibles en inventario
    int descuento;       ///< Descuento en porcentaje (%)

public:
    /**
     * @brief Constructor que inicializa todos los atributos del producto.
     * @param nombre Nombre del producto.
     * @param precio Precio unitario.
     * @param stock Cantidad disponible.
     * @param descuento Descuento aplicado (porcentaje).
     */
    Producto(std::string nombre, float precio, int stock, int descuento);

    /**
     * @brief Actualiza el precio del producto.
     * @param nuevoPrecio Nuevo valor del precio.
     */
    void actualizarPrecio(float nuevoPrecio);

    /**
     * @brief Muestra un resumen con las características del producto.
     */
    void resumenProducto() const;

    /**
     * @brief Realiza una venta si hay suficiente stock.
     * @param cantidad Número de unidades a vender.
     * @return Valor total de la venta con descuento aplicado.
     */
    float vender(int cantidad);

    /**
     * @brief Incrementa el stock del producto.
     * @param cantidad Número de unidades a agregar al inventario.
     */
    void reabastecer(int cantidad);

    /**
     * @brief Calcula el valor total del inventario del producto.
     * @return Valor total (precio × stock).
     */
    float consultarValorInventario() const;

    /// Métodos “get” básicos
    std::string getNombre() const;
    float getPrecio() const;
    int getStock() const;
    int getDescuento() const;
};

#endif
