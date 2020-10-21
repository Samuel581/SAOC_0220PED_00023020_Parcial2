#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct producto{
    string nombre;
    float precio_unitario;
};

struct pedido{
    string apellido;
    vector<producto> lista_comida;
};

queue<pedido> dona;
queue<pedido> platos_fuertes;

float totalVentaDonas, totalVentaPlatos, montoTotalDonas(struct pedido auxiliar), montoTotalPlatos(struct pedido auxiliar);;
struct producto venta(float precio, string tipo);
void donas(), platosFuertes(), pedidos(); 

int main(){
    bool estado=true;
    int opcion=0;
    while(estado){
        cout << "- - - - - - - - - MENU - - - - - - - - - " << endl;
        cout <<"1. Atender pedido" << endl;
        cout <<"2. Calcular ventas totales por donas" << endl;
        cout <<"3. Calcular ganancias por venbta de platos fuertes" << endl;
        cout <<"4. Salir" << endl;
        cout << ">>>> ";
        cin >> opcion;
        switch (opcion){
        case 1:
            pedidos();
            break;
        case 2: 
            cout << "Las ganancias actuales de venta de donas son: $" << totalVentaDonas << endl;
            break;
        case 3:
            cout << "Las ganancias actuales de venta de platos principales son: $" << totalVentaPlatos << endl;
            break;
        case 4:
            estado = false; break;
        
        default:
            break;
        }
    }
}

void pedidos(){
    bool estado = true;
    int opcion;
    while (estado)
    {
        cout << "----¿Que comprara el cliente?---" << endl;
        cout << "1. Comprar donas" << endl;
        cout << "2. Comprar platos fuertes" << endl;
        cout << ">>>";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            donas(); estado = false; break;
        
        case 2:
            platosFuertes(); estado = false; break;
        default:
            cout<<"Seleccione una opcion valida!" << endl; break;
        }
    }
}

void donas(){
    struct pedido datosPedido;
    struct producto datosProducto; cin.ignore();
    cout<<"Ingrese su apellido: "; 
    getline(cin, datosPedido.apellido);
    bool estado = true;
    int opcion;
    string esp;
    while (estado)
    {
        cout<<"------MENU DONAS------"<<endl;
        cout<<"1. Sencilla $1"<<endl;
        cout<<"2. Rellena de leche $1.25"<<endl;
        cout<<"3. Sabores especiales (moca, caramelo) $1.50"<<endl;
        cout<<"4. Finalizar pedido"<<endl;
        cout<<">>>>> ";
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            datosProducto = venta(1,"Sencilla");
            datosPedido.lista_comida.push_back(datosProducto);
            break;
        
        case 2:
            datosProducto = venta(1.25,"Rellena de leche");
            datosPedido.lista_comida.push_back(datosProducto);
            break;

        case 3:
            cout<<"Ingrese sabor de dona especial: ";
            cin.ignore();
            getline(cin,esp);
            datosProducto = venta(1.50,esp);
            datosPedido.lista_comida.push_back(datosProducto);
            break;

        case 4:
            if (!datosPedido.lista_comida.empty())
            {
                estado = false;
                cout<<"El total a pagar por su pedido es de: $"<<montoTotalDonas(datosPedido)<<endl;
                cout<<"!Gracias por su compra!"<<endl;
                dona.push(datosPedido);
            }
            else
            {
                cout<<"No ha realizado ninguna orden"<<endl;
            }
            break;

        default:
            cout<<"Selecione una opcion valida!"<<endl;
            break;
        }
        cout<<"Desea algo mas: "<<endl; 
    }
    
};

void platosFuertes(){
    struct pedido datosPedido;
    struct producto datosProducto;
    cin.ignore();
    cout<<"Ingrese su apellido: "; 
    getline(cin, datosPedido.apellido);
    bool estado = true;
    int opcion;
    string esp;
    while (estado)
    {
        cout<<"-------MENU PLATOS FUERTES-------"<<endl;
        cout<<"1. Desayuno $2.50"<<endl;
        cout<<"2. Almuerzo $5"<<endl;
        cout<<"3. Cena $3.50"<<endl;
        cout<<"4. Finalizar pedido"<<endl;
        cout<<">>>> ";
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            datosProducto = venta(2.50,"Desayuno");
            datosPedido.lista_comida.push_back(datosProducto);
            break;
        
        case 2:
            datosProducto = venta(5,"Almuerzo");
            datosPedido.lista_comida.push_back(datosProducto);
            break;

        case 3:
            datosProducto = venta(3.50,"Cena");
            datosPedido.lista_comida.push_back(datosProducto);
            break;

        case 4:
            if (!datosPedido.lista_comida.empty())
            {
                estado = false;
                cout<<"El total a pagar por su pedido es de: $"<<montoTotalPlatos(datosPedido)<<endl;
                cout<<"!Gracias por su compra!"<<endl;
                platos_fuertes.push(datosPedido);
            }
            else
            {
                cout<<"No ha realizado ninguna orden"<<endl;
            }
            break;

        default:
            cout<<"Opcion no valida!"<<endl;
            break;
        }
        cout<<"Desea algo mas: "<<endl;  
    }
    
}

struct producto venta(float precio, string tipo){
    struct producto auxiliar;
    auxiliar.nombre=tipo;
    auxiliar.precio_unitario = precio;
    return auxiliar;
}

float montoTotalDonas(struct pedido auxiliar){
    int size = auxiliar.lista_comida.size();
    struct producto precio;
    float t = 0;
    for (int i = 0; i < size; i++)
    {
        precio= auxiliar.lista_comida.at(i);
        t+=precio.precio_unitario;
    }
    totalVentaDonas+=t;
    return t;
}

float montoTotalPlatos(struct pedido auxiliar){
    int size = auxiliar.lista_comida.size();
    struct producto precio;
    float t = 0;
    for (int i = 0; i < size; i++)
    {
        precio= auxiliar.lista_comida.at(i);
        t+=precio.precio_unitario;
    }
    totalVentaPlatos+=t;
    return t;
}