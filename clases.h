/*
Santiago Patricio Gómez Ochoa
A01735171
14/06/2024
Programación orientada a objetos
Situación Problema
*/

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <stdexcept>
#include <algorithm>
using namespace std;

// VIDEO
class Video{
protected:
    int ID;
    std::string nombre;
    int duracion;
    std::string genero;
    double calificacionP;
    double calificacionU;
    std::string video;

public:
    Video(int id, const std::string& name, int duration, const std::string& gen, double rateP, double rateUser = 0);
    virtual ~Video() {};
    int getID();
    string& getNombre(); //Retorna una referencia constante al objeto nombre.
    int getDuracion();
    string& getGenero(); //Retorna una referencia constante al objeto genero.
    double getCalificacionP() const;  //No se modifica su estado
    double getCalificacionUser() const; //No se modifica su estado
    void setCalificacionUser(double newRate);
    bool operator>(const Video& other) const;
    virtual void getInfo() const = 0; /*convierte 
    a la clase en una clase abstracta y obliga a las clases
    derivadas a proporcionar una implementación de esta
    función.
    */

    virtual void calificarTitulo(double calificacionUser) = 0;
    virtual std::string getType() const = 0;

};

// PELÍCULA
class Pelicula : public Video{
public:
    Pelicula(int id, const std::string& name, std::string type, int duration, const std::string& gen, double rateP, double rateUser);
    void getInfo() const override; /*La función no modifica 
    el estado de este objeto. Indica que el método está 
    sobrescribiendo un método virtual de la clase base. 
    Es una manera de asegurarse de que el método en la 
    clase derivada tiene la misma firma que el método 
    en la clase base que intenta sobrescribir.*/
    void calificarTitulo(double calificacionUser) override;
    std::string type;
    std::string getType() const override;
    

};

// EPISODIO
class Episodio {
private:
    std::string titulo;
    int duracion;
    int numEpisodio;

public:
    Episodio(const string& title, int duration);
    string getTituloEp() const;
    int getDuracionEp() const;
    void getInfo() const;
    int getNumEpisodio() const;

};

// TEMPORADA
class Temporada {
private:
    int numEpisodios;
    int numTemporada;
    int numeroTemporada;
    vector<Episodio*> episodios;

public:
    Temporada(int numeroTemporada, int numEpisodios);
    virtual ~Temporada();
    int getNumTemporada() const;
    void addEpisodio(Episodio* episodio);
    vector<Episodio*> getEpisodios() const;
    void getInfo() const;
};

// SERIE
class Serie : public Video {
private:
    vector<Temporada*> temporadas;

public:
    Serie(int id, const string& name, string type, const string& gen, double rateS, double rateUser, int numSeasons);
    ~Serie();
    void addTemporada(Temporada* temporada);
    vector<Temporada*> getTemporadas() const;
    void getInfo() const override; // Debe ser override para indicar que se está sobreescribiendo la función virtual
    void calificarTitulo(double calificacionUser) override;
    std::string type;
    std::string getType() const override;
};


