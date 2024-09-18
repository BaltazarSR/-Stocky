#include <iostream>
#include <string>
using namespace std;

class Producto{

    private:
        string nombre;
        int unidades;
        double precio;

    public:
        //constructores
        Producto(){
            //cout << endl << "Constructor vacio" << endl;
            nombre = "N/A";
            unidades = 0;
            precio = 0.0;
        }
        Producto(string newNombre, int newUnidades, double newPrecio){
            //cout << endl << "Constructor con dos parametros" << endl;
            nombre = newNombre;
            unidades = newUnidades;
            precio = newPrecio;
        }

        //setters
        void setNombre(string newName){
            nombre = newName;
        }
        void setUnidades(int newUnidades){
            unidades = newUnidades;
        }
        void setPrecio(double newPrecio){
            precio = newPrecio;
        }

        //getters
        string getNombre(){
            return nombre;
        }
        int getUnidades(){
            return unidades;
        }
        double getPrecio(){
            return precio;
        }

        //Métodos
        void imprimeProducto(){
            //cout << endl;
            cout << "---------------------------------------------" << endl << endl;
            cout << "\t Producto: " << nombre << endl;
            cout << "\t Precio: $" << precio << endl;
            cout << "\t Unidades disponibles: " << unidades << endl;
            //cout << endl;
        } 

        double calcularPrecio(int venta){
            double ganancia = (precio*venta);
            return ganancia;
        }

        //Destructores
        ~Producto(){
            //cout << endl << "Dentro de destructor" << endl;
        }

};

class Direccion{

    private:
        string nombre;
        string calle;
        int numero;
        string ciudad;
        int postal;
    public:
        //constructores
        Direccion(){
            //cout << endl << "Constructor vacio" << endl;
            nombre = "N/A";
            calle = "N/A";
            numero = 0;
            ciudad = "N/A";
            postal = 0;
        }
        Direccion(string newNombre, string newCalle, int newNumero, string newCiudad, int newPostal){
            //cout << endl << "Constructor con 5 parametros" << endl;
            nombre = newNombre;
            calle = newCalle;
            numero = newNumero;
            ciudad = newCiudad;
            postal = newPostal;
        }
        //setters
        void setNombre(string newNombre){
            nombre = newNombre;
        }
        void setCalle(string newCalle){
            calle = newCalle;
        }
        void setNumero(int newNumero){
            numero = newNumero;
        }
        void setCiudad(string newCiudad){
            ciudad = newCiudad;
        }
        void setPostal(int newPostal){
            postal = newPostal;
        }
        
        //getters
        string getNombre(){
            return nombre;
        }
        string getCalle(){
            return calle;
        }
        int getNumero(){
            return numero;
        }
        string getCiudad(){
            return ciudad;
        }
        int getPostal(){
            return postal;
        }

        //metodos
        void imprimeInfo(){

            cout << endl;

            cout << endl << "Direccion de entrega" << endl;
            cout << endl << "\tNombre del destinatario: " << nombre << endl;
            cout << endl << "\tCalle: " << calle << endl;
            cout << endl << "\tNumero: " << numero << endl;
            cout << endl << "\tCiudad: " << ciudad << endl;
            cout << endl << "\tCodigo Postal: " << postal << endl;

            cout << endl;

        }
        
        //destructores
        ~Direccion(){
            //cout << endl << "Dentro de destructor" << endl;
        }    
};

class Negocio{

    private:
        string nombre;
        Producto productos[10];
        int contador = 0;
    public:
        //Constructores
        Negocio(){
            //cout << endl << "Contructor vacio" << endl;
            nombre = "N/A";
        }
        Negocio(string newNombre){
            //cout << endl << "Constructor con un parametro" << endl;
            nombre = newNombre;
        }

        //setters
        void setNombre(string newNombre){
            nombre = newNombre;
        }
        void setProducto(Producto newProducto){
            if(contador <= 10){
                productos[contador] = newProducto;
                contador++;
            }
            else{
                cout << "Ya no se pueden agregar productos" << endl;
            }
        }

        //getters
        string getNombre(){
            return nombre;
        }
        Producto getProducto(int indice){
            return productos[indice];
        }
        int getContador(){
            return contador;
        }

        //metodos
        void imprimeInfo(){
            cout << endl;

            cout << endl << "Inventario de " << nombre << endl;
            for(int i = 0; i < contador; i++){
                //cout << "\t";
                productos[i].imprimeProducto();
                cout << endl;
            }

            cout << endl;
        }

        void borrarInventario(){
            contador = 0;
        }

        void reemplazarProducto(Producto newProducto, int indice){
            productos[indice-1] = newProducto;
        }

        //destructores
        ~Negocio(){
            //cout << endl << "Dentro de destructor" << endl;
        }

};

int main(){

    Negocio n1;

    while(true){

        system("clear");
        cout << endl;
        int resp1 = 0;

        cout << endl << "Bienvenido a Stocky" << endl;
        cout << endl << "\t 1.- Crear inventario" << endl;
        cout << endl << "\t 2.- Revisar inventario" << endl;
        cout << endl << "\t 3.- Vender" << endl;
        cout << endl << "\t 4.- Salir" << endl;
        cout << endl << "Escoja una opcion: ";
        cin >> resp1;

        if(resp1 == 1){
            system("clear");
            string nombre = "";
            n1.borrarInventario();

            cout << endl;

            cout << endl << "Ingrese el nombre de su negocio: ";
            cin >> nombre;
            cout << endl;

            system("clear");

            n1.setNombre(nombre);

            while(true){

                system("clear");
                int resp2 = 0;

                n1.imprimeInfo();

                cout << endl;

                cout << endl << "¿Agregar productos?" << endl;
                cout << endl << "\t 1.- Si" << endl;
                cout << endl << "\t 2.- No" << endl;
                cout << endl << "Escoja una opcion: ";
                cin >> resp2;

                if(resp2 == 1 & n1.getContador() < 10){
                    string nombreProducto = "";
                    int unidadesProducto = 0;
                    double precioProducto = 0.0;

                    system("clear");

                    cout << endl;

                    cout << endl << "Ingrese el nombre de su producto: ";
                    cin >> nombreProducto;
                    cout << endl;
                    cout << endl << "Ingrese el numero de unidades de su producto: ";
                    cin >> unidadesProducto;
                    cout << endl;
                    cout << endl << "Ingrese el precio de su producto: ";
                    cin >> precioProducto;
                    cout << endl;

                    Producto p1(nombreProducto, unidadesProducto, precioProducto);

                    n1.setProducto(p1);

                    cout << endl;

                    continue;
                }
                else if(resp2 == 1 & n1.getContador() >= 10){
                    string back1 = "";
                    system("clear");
                    cout << endl;

                    cout << endl << "El inventario ya esta lleno" << endl;
                    cout << endl << "Presione cualquier tecla para regresar a la pantalla principal: ";
                    cin >> back1;
                    cout << endl;

                    break;
                }
                else if(resp2 == 2){
                    break;
                }

                cout << endl;
                        
            }

            cout << endl;
            
        }
        else if(resp1 == 2){
            int resp3 = 0;

            while(true){
                system("clear");

                cout << endl;

                n1.imprimeInfo();

                cout << endl;

                cout << endl << "¿Desea modificar el inventario?" << endl;
                cout << endl << "\t 1.- Si" << endl;
                cout << endl << "\t 2.- No" << endl;
                cout << endl << "Escoja una opcion: ";
                cin >> resp3;

                if(resp3 == 1){

                    int mod1 = 0;
                    system("clear");
                    cout << endl;
                    n1.imprimeInfo();
                    cout << endl << "Hay " << n1.getContador() << " productos en su inventario, escoja uno a modificar: ";
                    cin >> mod1;
                    cout << endl;

                    if(mod1 > 0 && mod1 <= n1.getContador()){

                        system("clear");
                        string newNombre = "";
                        int newUnidades = 0;
                        double newPrecio = 0.0;

                        cout << endl;

                        cout << endl << "Ingrese el nombre del nuevo producto: ";
                        cin >> newNombre;
                        cout << endl;

                        cout << endl << "Ingrese las unidades disponibles del nuevo producto: ";
                        cin >> newUnidades;
                        cout << endl;

                        cout << endl << "Ingrese el precio del nuevo producto: ";
                        cin >> newPrecio;
                        cout << endl;

                        Producto p1(newNombre, newUnidades, newPrecio);

                        n1.reemplazarProducto(p1,mod1);

                        cout << endl;

                        continue;

                    }
                    else{

                        string aux1 = "";
                        system("clear");
                        cout << endl;
                        cout << endl << "El numero de producto es invalido, presione cualquier tecla para volver: ";
                        cin >> aux1;
                        cout << endl;

                        continue;

                    }
                
                }
                else if(resp3 == 2){
                    break;
                }

                cout << endl;

            }

        }
        else if(resp1 == 3){
            
            string newNombre = "";
            string newCalle = "";
            int newNumero = 0;
            string newCiudad = "";
            int newPostal = 0; 
            int elec = 0;
            system("clear");
            
            cout << endl;

            cout << endl << "Datos de el destino" << endl;
            cout << endl << "Escriba el nombre del destinatario sin espacios: ";
            cin >> newNombre;
            cout << endl;

            cout << endl << "Escriba la calle del destino sin espacios: ";
            cin >> newCalle;
            cout << endl;

            cout << endl << "Escriba el numero del destino: ";
            cin >> newNumero;
            cout << endl;

            cout << endl << "Escriba la ciudad de destino sin espacios: ";
            cin >> newCiudad;
            cout << endl;

            cout << endl << "Escriba el codigo postal del destino: ";
            cin >> newPostal;
            cout << endl;

            Direccion d1(newNombre, newCalle, newNumero, newCiudad, newPostal);

            cout << endl;

            system("clear");

            cout << endl;

            d1.imprimeInfo();

            cout << endl;

            n1.imprimeInfo();

            cout << endl << "Tiene " << n1.getContador() << " productos para enviar, escoja uno: ";
            cin >> elec;

            if(elec > 0 && elec <= n1.getContador()){

                int vent = 0;
                system("clear");
                cout << endl;
            
                n1.getProducto(elec-1).imprimeProducto();

                cout << endl << "Cuantas unidades quiere vender: ";
                cin >> vent;
                cout << endl;

                if(vent > 0 && vent <= n1.getProducto(elec-1).getUnidades()){
                    system("clear");
                    string aux3 = "";

                    cout << endl;

                    cout << endl << "Detalles de venta" << endl;
                    cout << endl << "\t Unidades vendidas: " << vent << endl;
                    cout << endl << "\t Ganancias: $" << n1.getProducto(elec-1).calcularPrecio(vent) << endl;

                    int total = n1.getProducto(elec-1).getUnidades();
                    int restante = total - vent;
                    string nom = n1.getProducto(elec-1).getNombre();
                    double pre = n1.getProducto(elec-1).getPrecio();
                    Producto p1(nom, restante, pre);

                    n1.reemplazarProducto(p1,elec);

                    cout << endl << "Producto restante: " << endl;

                    n1.getProducto(elec-1).imprimeProducto();

                    cout << endl << "Presione cualquier tecla para volver: ";
                    cin >> aux3;
                    continue;

                }
                else{
                    system("clear");
                    string aux2 = "";
                    cout << endl;

                    cout << endl << "Las unidades introducidas no son validas, presiona cualquier tecla para volver: ";
                    cin >> aux2;
                    cout << endl;

                    cout << endl;

                    continue;
                }

                cout << endl;

            }
            else{

                string aux4 = "";
                system("clear");
                cout << endl;
                cout << endl << "El numero de producto es invalido, presione cualquier tecla para volver: ";
                cin >> aux4;
                cout << endl;

                continue;

            }

            cout << endl;

        }
        else if(resp1 == 4){
            break;
        }

        cout << endl;

    }

}

//Baltazar Servin Riveroll - A01643496
