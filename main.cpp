#include <iostream>
using namespace std;

// mi estructura  con varibles
struct productos
{
    string nombre;
    float precio;

};

// funcion de carga de nombre y precio de producto.
void cargaDeProdcuto(productos lista[], int tamano){

    for (int i = 0; i < tamano; i++)
    {
        cout << "nombre de Prodcuto: ";
        cin >> lista[i].nombre;

        cout << "Precio de Prodcuto: ";
        cin >> lista[i].precio;

    }
}

// funcion de carga de matricez de dos dimensiones filas y colunmnas.
void CargaStock(int listaStock[][3], int filas){

    for (int i = 0; i < filas; i++)
    {
        // nombre de los depositos
        cout << "CARGA DE DEPOSITO: " << i + 1 << endl;

        for (int j = 0; j < 3; j++)
        {
            // ingreso de cantidad en las colunmnas
            cout << "Ingrese cantidad de producto " << j + 1 << " : ";
            cin >> listaStock[i][j];
        }

        // para saltar linea cual el for cambie
        cout << endl;
        
    }
}

// funcion de reporte financiero, que muestre todas las cantidades de los depositos y el total de la mercaderia.
void reporteFinaciero(productos lista[],int listaProducto[][3],int cantidad,int tamano){

    cout << "--REPORTE FINACINANCIERO--" << endl;
    

    // el for que vamos a utilizar es solo 1 con la letra j porque trabajamos con las cantidades de prodcuto que estan en las columnas.
        for (int j = 0; j < cantidad; j++)
        {
            // un acumulador para que vaya guardando y sumando las vueltas.
            int acumuladorstock = 0;

            for (int i = 0; i < tamano; i++)
            {
                 // aca sumamos lo que hay vaya acumulando el acumulador de las lista de productos.
                acumuladorstock += listaProducto[i][j];
            }

            // aca multiplicamos el total de la suma de cantidades por el precio de cada uno de los productos.
            float dineroInvertido = acumuladorstock * lista[j].precio;

            // mostramos la suma, cantidad, nombre del prodcuto y el precio por unidad.
            cout << "Producto: " << lista[j].nombre << " // Unidades Totales: " << acumuladorstock << endl;
            cout << "Total Dinero: $" << dineroInvertido << endl;
            cout << "Precio por unidad: $" << lista[j].precio << endl;
        }
    
}

// funcion para buscar un producto
void buscarProdcuto(productos lista[], int tamano)
{
    string nombre;
    cout << "Nombre a buscar: ";
    cin >> nombre;


    for (int i = 0; i < tamano; i++)
    {
        if (lista[i].nombre == nombre)
        {
            cout << "Producto Encontrado: " << lista[i].nombre << endl;
            cout << "Precio del producto: " << lista[i].precio << endl;

            return;
        }
        
    }

    cout << "El producto " << nombre << " No esta en el sistema";

}


int main(){

    const int f = 4;
    const int p = 3;
    bool productosCargado = false;
    // mi lista // vector
    productos listaDeproducto[p];
    int listaDeStock[f][p];

    

    // esto sirve para limpiar cualquier residuo del teclado antes de pedir la opcion.
   

    int opcion; // Variable para capturar la opción del menú

    do {
        cout << "\n========================================" << endl;
        cout << "   SISTEMA DE GESTION - SUPERMERCADO   " << endl;
        cout << "========================================" << endl;
        cout << "1. Cargar Productos" << endl;
        cout << "2. Cargar Stock de Depositos" << endl;
        cout << "3. Ver Reporte Financiero" << endl;
        cout << "4. Buscar un Producto" << endl;
        cout << "5. Salir del Sistema" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        // limpia los errores del cin
        cin.clear();
        // descarta los carateres sobrantes (como el enter anterior).
         cin.ignore(1000, '\n');

        switch(opcion) {
            case 1:
                cout << "\n--- CARGA DE PRODUCTOS ---" << endl;
                cargaDeProdcuto(listaDeproducto, p);
                // una bandera para saber si la carga esta hecha.
                productosCargado = true;
                break;
            
            case 2:
                cout << "\n--- CARGA DE STOCK ---" << endl;
                CargaStock(listaDeStock, f); // Asegúrate de pasar los parámetros como los definiste
                break;
                
            case 3:
                if (productosCargado == true)
                {
                    cout << "\n--- REPORTE FINANCIERO ---" << endl;
                    reporteFinaciero(listaDeproducto, listaDeStock, p, f);
                }
                else{
                    cout << "Primero tiene que cargar los datos de la opcion 1." << endl;
                }
                break;

                
            case 4:
                cout << "\n--- BUSCAR PRODUCTO ---" << endl;
                buscarProdcuto(listaDeproducto, p);
                break;
                
            case 5:
                cout << "\nSaliendo del sistema... ¡Buen descanso!" << endl;
                break;
                
            default:
                cout << "\n[ERROR] Opcion incorrecta. Ingresa un numero del 1 al 5." << endl;
                break;
        }

    } while(opcion != 5);

    return 0;
}
