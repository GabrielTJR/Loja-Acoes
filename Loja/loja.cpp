#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

class Pessoa {
    string nome;
    int data_nascimento;
    string endereco;
public:
    Pessoa(){

    }
    Pessoa(string n, string ende, int data_nasc) { ///construtor
        nome = n;
        endereco = ende;
        data_nascimento = data_nasc;
    }

    string getnome() {
        return nome;
    }
    string getendereco() {
        return endereco;
    }
    int getDataNascimento() {
        return data_nascimento;
    }

};

class Carrinho{
    float total;
    string compra[100];
    int itens;
public:
    void ini_carrinho(){
        total=0;
        itens=0;
        for(int i=0; i <100; i++){
            compra[i]=" ";
        }
    }
    void setcompra(float valor, string item){
        total = total + valor;
        compra[itens] = item;
        itens++;
    }
    float gettotal(){
        return total;
    }
    void compras(){
        for(int i=0; i<=itens; i++){
            cout << "Item " << i+1 << ": " << compra[i] << endl;
        }
    }
    int getitens(){
        return itens;
    }
    void setitens(int num){
        itens = num;
    }
};

class Animal{
    int codigo_a, idade;
    string raca;
    bool vacina;
    string svacina;
public:
    Animal(){

    }
    Animal(int cod, int id, string rac, bool vac){
        codigo_a=cod;
        idade=id;
        raca=rac;
        vacina=vac;
    }

    string getraca() {
        return raca;
    }
    string getvacina() {
        if(vacina == true){
            svacina = "Sim";
        }
        else{
            svacina = "Não";
        }
        return svacina;
    }
    int getidade() {
        return idade;
    }
    int getcodigo_a() {
        return codigo_a;
    }
    void setcodigo_a(int cod){
        codigo_a = cod;
    }
};

struct LAnimal{
    Animal num[100];
    int tam;
};

class Venda{
    float valor;
public:
    Venda(){

    }
    Venda(float price){
        valor = price;
    }
    
    float getvalor() {
        return valor;
    }
};

class Produto: public Venda{
    string nome;
    int codigo_p;
public:
    Produto(){

    }
    Produto(string name, int cod, float valor) : Venda(valor){
        nome = name;
        codigo_p = cod;
    }
    int getcodigo_p() {
        return codigo_p;
    }
    string getnome() {
        return nome;
    }
    void setcodigo_p(int cod){
        codigo_p = cod;
    }
};

struct LProduto{
    Produto num[100];
    int tam;
};

class Servico: public Venda{
    string tipo;
    int codigo_s;
public:
    Servico(){

    }
    Servico(string tip, int cod, float valor) : Venda(valor){
        tipo = tip;
        codigo_s = cod;
    }
    int getcodigo_s() {
        return codigo_s;
    }
    string gettipo() {
        return tipo;
    }
    void setcodigo_s(int cod){
        codigo_s = cod;
    }
};

struct LServico{
    Servico num[100];
    int tam;
};

class Cliente : public Pessoa
{
    int codigo_c;
    int telefone;
public:
    Cliente(){

    }
    Cliente(int tel, int cod_c, string n, string ende, int data_nasc) : Pessoa(n, ende, data_nasc)   ///herança
    {
        telefone = tel;
        codigo_c = cod_c;
    }
    int getcodigo_c() {
        return codigo_c;
    }
    int gettelefone() {
        return telefone;
    }
    void setcodigo_c(int cod){
        codigo_c = cod;
    }
};

struct LClientes{
    Cliente num[100];
    int tam;
};

class Funcionario : public Pessoa {
private:
    int salario;
    int codigo_f;
    string cargo;
public:
    Funcionario(){
        
    }
    Funcionario(int s, int cod_f, string c, string n, string ende, int data_nasc) : Pessoa(n, ende, data_nasc) {
        salario = s;
        codigo_f = cod_f;
        cargo = c;
    }
    int getsalario() {
        return salario;
    }
    int getcodigo_f() {
        return codigo_f;
    }
    string getcargo() {
        return cargo;
    }
    void setcodigo_f(int cod){
        codigo_f=cod;
    }

    template <typename TIPO>
    void ini_lista(TIPO &lista){
        lista.tam=0;
    }

    Cliente cadastrarCliente(int &tam) {
    int tel, cod_c;
    string n, ende;
    int data_nasc;
    cout <<"Digite o Nome do cliente: ";
    cin >> n;
    cout <<"\nDigite o telefone do cliente: ";
    cin >> tel;
    cout << "\nDigite a data de nascimento do cliente: ";
    cin >> data_nasc;
    cout << "\nDigite o endereço do cliente: ";
    cin >> ende;
    cod_c = tam;
    cout << "\n\nCliente cadastrado com sucesso";
    Sleep(2000);
    system("cls");

    Cliente cliente(tel, cod_c, n, ende, data_nasc);
    return cliente;
    }

    Animal cadastrarAnimal(int &tam) {
    int idade, cod_a, n;
    string raca;
    bool vacina;
    cout <<"Digite a raça do animal: ";
    cin >> raca;
    cout <<"\nDigite a idade do animal: ";
    cin >> idade;
    cout << "\nO animal é vacinado?: 1)Sim  2)Não";
    cin >> n;
    if(n==1){
        vacina = true;
    }
    else{
        vacina = false;
    }
    cod_a = tam;
    cout << "\n\nAnimal cadastrado com sucesso";
    Sleep(2000);
    system("cls");

    Animal animal(cod_a, idade, raca, vacina);
    return animal;
    }

    Produto cadastrarProduto(int &tam) {
    int cod_p;
    string nome;
    float valor;
    cout <<"Digite o nome do produto: ";
    cin >> nome;
    cout <<"\nDigite o valor do produto: ";
    cin >> valor;
    cod_p = tam;
    cout << "\n\nProduto cadastrado com sucesso";
    Sleep(2000);
    system("cls");

    Produto produto(nome, cod_p, valor);
    return produto;
    }

    Servico cadastrarServico(int &tam) {
    int cod_s;
    string tipo;
    float valor;
    cout <<"Digite o tipo de serviço: ";
    cin >> tipo;
    cout <<"\nDigite o valor do serviço: ";
    cin >> valor;
    cod_s = tam;
    cout << "\n\nServiço cadastrado com sucesso";
    Sleep(2000);
    system("cls");

    Servico servico(tipo, cod_s, valor);
    return servico;
    }

    bool exclui_cliente(LClientes &lista){
        int pos;
        cout << "Qual codigo do cliente que deseja excluir? : ";
        cin >> pos;
        if(lista.tam < 100){
            for(int i=pos; i<lista.tam; i++){
                lista.num[i] = lista.num[i+1];
                lista.num[i].setcodigo_c(lista.num[i].getcodigo_c()-1);
            }
            lista.tam--;
            return true;
        }
        else{
            return false;
        }
        cout << "\n\nCliente excluido com sucesso";
        Sleep(2000);
        system("cls");
    }

    bool exclui_animal(LAnimal &lista){
        int pos;
        cout << "Qual codigo do animal que deseja excluir? : ";
        cin >> pos;
        if(lista.tam < 100){
            for(int i=pos; i<lista.tam; i++){
                lista.num[i] = lista.num[i+1];
                lista.num[i].setcodigo_a(lista.num[i].getcodigo_a()-1);
            }
            lista.tam--;
            return true;
        }
        else{
            return false;
        }
        cout << "\n\nAnimal excluido com sucesso";
        Sleep(2000);
        system("cls");
    }
    bool exclui_produto(LProduto &lista){
        int pos;
        cout << "Qual codigo do produto que deseja excluir? : ";
        cin >> pos;
        if(lista.tam < 100){
            for(int i=pos; i<lista.tam; i++){
                lista.num[i] = lista.num[i+1];
                lista.num[i].setcodigo_p(lista.num[i].getcodigo_p()-1);
            }
            lista.tam--;
            return true;
        }
        else{
            return false;
        }
        cout << "\n\nProduto excluido com sucesso";
        Sleep(2000);
        system("cls");
    }
    bool exclui_servico(LServico &lista){
        int pos;
        cout << "Qual codigo do serviço que deseja excluir? : ";
        cin >> pos;
        if(lista.tam < 100){
            for(int i=pos; i<lista.tam; i++){
                lista.num[i] = lista.num[i+1];
                lista.num[i].setcodigo_s(lista.num[i].getcodigo_s()-1);
            }
            lista.tam--;
            return true;
        }
        else{
            return false;
        }
        cout << "\n\nServiço excluido com sucesso";
        Sleep(2000);
        system("cls");
    }
};

struct LFuncionarios{
    Funcionario num[10];
    int tam;
};

class Chefe : public Funcionario{
    string nome = "Felski";
public:
    Funcionario cadastrarFuncionario(int &tam) {
    int s, cod_f;
    string c, n, ende;
    int data_nasc;

    cout <<"Digite o Nome do funcionario: ";
    cin >> n;
    cout <<"\nDigite o cargo do funcionario: ";
    cin >> c;
    cout <<"\nDigite o salario do funcionario: ";
    cin >> s;
    cout << "\nDigite a data de nascimento do funcionario: ";
    cin >> data_nasc;
    cout << "\nDigite o endereço do funcionario: ";
    cin >> ende;
    cod_f = tam;
    cout << "\n\nFuncionario cadastrado com sucesso";
    Sleep(2000);
    system("cls");

    Funcionario funcionario(s, cod_f, c, n, ende, data_nasc);
    return funcionario;
    }

    bool exclui_funcionario(LFuncionarios &lista){
        int pos;
        cout << "Qual codigo do funcionario que deseja excluir? : ";
        cin >> pos;
        if(lista.tam < 100){
            for(int i=pos; i<lista.tam; i++){
                lista.num[i] = lista.num[i+1];
                lista.num[i].setcodigo_f(lista.num[i].getcodigo_f()-1);
            }
            lista.tam--;
            cout << "\n\nFuncionario excluido com sucesso";
            Sleep(2000);
            system("cls");
            return true;
        }
        else{
            return false;
        }
    }
};

void cadastrarCompra(Carrinho &compras, LServico servico, LProduto produto) {
    int tipo, cod;
    float valor;
    string nome;
    cout <<"O que deseja adicionar?: 1)Serviço  2)Produto";
    cin >> tipo;
    cout <<"\nDigite o codigo do item que deseja: ";
    cin >> cod;
    if(tipo == 1){
        valor = servico.num[cod].getvalor();
        nome = servico.num[cod].gettipo();
    }else{
        valor = produto.num[cod].getvalor();
        nome = produto.num[cod].getnome();
    }
    compras.setcompra(valor,nome);
    cout << "\n\nItem adicionado com sucesso";
    Sleep(2000);
    system("cls");
}
void exclui_compras(Carrinho &compras){
    compras.ini_carrinho();
    cout << "\n\nCarrinho esvaziado com sucesso";
    Sleep(2000);
    system("cls");
}

void visualiza_cliente(LClientes lista){
    int pos;
    cout << "Qual codigo do cliente que deseja visulizar? : ";
    cin >> pos;
    system("cls");
    cout << "Codigo: " << lista.num[pos].getcodigo_c();
    cout << "\nNome: " << lista.num[pos].getnome();
    cout << "\nEndereço: " << lista.num[pos].getendereco();
    cout << "\nTelefone: " << lista.num[pos].gettelefone();
    cout << "\nData de nascimento: " << lista.num[pos].getDataNascimento();
    cout << "\n\n";
    system("pause");
}

void visualiza_funcionario(LFuncionarios lista){
    int pos;
    cout << "Qual codigo do funcionario que deseja visulizar? : ";
    cin >> pos;
    system("cls");
    cout << "Codigo: " << lista.num[pos].getcodigo_f();
    cout << "\nNome: " << lista.num[pos].getnome();
    cout << "\nEndereço: " << lista.num[pos].getendereco();
    cout << "\nCargo: " << lista.num[pos].getcargo();
    cout << "\nSalario: " << lista.num[pos].getsalario();
    cout << "\nData de nascimento: " << lista.num[pos].getDataNascimento();
    cout << "\n\n";
    system("pause");
}

void visualiza_animal(LAnimal lista){
    int pos;
    cout << "Qual codigo do animal que deseja visulizar? : ";
    cin >> pos;
    system("cls");
    cout << "Codigo: " << lista.num[pos].getcodigo_a();
    cout << "\nRaça: " << lista.num[pos].getraca();
    cout << "\nIdade: " << lista.num[pos].getidade();
    cout << "\nVacinado: " << lista.num[pos].getvacina();
    system("pause");
}

void visualiza_produto(LProduto lista){
    int pos;
    cout << "Qual codigo do produto que deseja visulizar? : ";
    cin >> pos;
    system("cls");
    cout << "Codigo: " << lista.num[pos].getcodigo_p();
    cout << "\nNome: " << lista.num[pos].getnome();
    cout << "\nValor: " << lista.num[pos].getvalor();
    cout << "\n\n";
    system("pause");
}

void visualiza_servico(LServico lista){
    int pos;
    cout << "Qual codigo do serviço que deseja visulizar? : ";
    cin >> pos;
    system("cls");
    cout << "Codigo: " << lista.num[pos].getcodigo_s();
    cout << "\nTipo: " << lista.num[pos].gettipo();
    cout << "\nValor: " << lista.num[pos].getvalor();
    cout << "\n\n";
    system("pause");
}

void visualiza_carrinho(Carrinho compras){
    cout << "Itens e valor total do carrinho : \n\n";
    cout << "Valor: " << compras.gettotal();
    compras.getitens();
    cout << "\n\n";
    system("pause");
}

int main()
{
    int escolha, escolha2, escolhaF;
    Chefe Felski;
    LClientes listaC;
    LProduto listaP;
    LServico listaS;
    LAnimal listaA;
    LFuncionarios listaF;
    Funcionario fun;
    Carrinho compras;
    compras.ini_carrinho();
    fun.ini_lista(listaF);
    fun.ini_lista(listaA);
    fun.ini_lista(listaC);
    fun.ini_lista(listaS);
    fun.ini_lista(listaP);
    while(true){
    cout <<"LOJA LAGANES:\n\n1)Adicionar\n2)Remover\n3)Visualizar\n\nEscolha: ";
    cin >> escolha;
    system("cls");
    cout <<"LOJA LAGANES:\n\n1)Cliente\n2)Funcionario\n3)Produtos\n4)Serviços\n5)Animal\n6)Pedidos\n\nEscolha: ";
    cin>> escolha2;
    system("cls");
    escolhaF = escolha*10 + escolha2;
    switch(escolhaF){
        case 11:
            listaC.num[listaC.tam] = fun.cadastrarCliente(listaC.tam);
            listaC.tam++;
            break;
        case 12:
            listaF.num[listaF.tam] = Felski.cadastrarFuncionario(listaF.tam);
            listaF.tam++;
            break;
        case 13:
            listaP.num[listaP.tam] = fun.cadastrarProduto(listaP.tam);
            listaP.tam++;
            break;
        case 14:
            listaS.num[listaS.tam] = fun.cadastrarServico(listaS.tam);
            listaS.tam++;
            break;
        case 15:
            listaA.num[listaA.tam] = fun.cadastrarAnimal(listaA.tam);
            listaA.tam++;
            break;
        case 16:
            cadastrarCompra(compras, listaS, listaP);
            break;
        case 21:
            fun.exclui_cliente(listaC);
            break;
        case 22:
            Felski.exclui_funcionario(listaF);
            break;
        case 23:
            fun.exclui_produto(listaP);
            break;
        case 24:
            fun.exclui_servico(listaS);
            break;
        case 25:
            fun.exclui_animal(listaA);
            break;
        case 26:
            exclui_compras(compras);
            break;
        case 31:
            visualiza_cliente(listaC);
            break;
        case 32:
            visualiza_funcionario(listaF);
            break;
        case 33:
            visualiza_produto(listaP);
            break;
        case 34:
            visualiza_servico(listaS);
            break;
        case 35:
            visualiza_animal(listaA);
            break;
        case 36:
            visualiza_carrinho(compras);
            break;
    }
    
    }
    return 0;
}