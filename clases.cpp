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
#include "clases.h"
using namespace std;    

//VIDEO
Video::Video(int id, const string& name, int duration, const string& gen, double rateP, double rateUser) : ID(id), nombre(name), duracion(duration), genero(gen), calificacionP(rateP), calificacionU(rateUser){

}

int Video::getID(){
    return ID;
}

string& Video::getNombre(){
    return nombre;
}

int Video::getDuracion(){
    return duracion;
}

string& Video::getGenero(){
    return genero;
}

double Video::getCalificacionP() const{
    return calificacionP;
}

double Video::getCalificacionUser() const{
    if(calificacionU == 0){
        return 0;
    }
    else{
        return calificacionU;
    }
}

bool Video::operator>(const Video& other) const {
        return calificacionP > other.calificacionP;
    }

void Video::setCalificacionUser(double newRate){
    calificacionU = newRate;
}

//PELÍCULA
Pelicula::Pelicula(int id, const std::string& name, string type, int duration, const string& gen, double rateP, double rateUser) : Video(id, name, duration, gen, rateP, rateUser), type(type){

}


void Pelicula::getInfo() const {
    cout << "ID: " << ID << endl;
    cout << "Título: " << nombre << endl;
    cout << "Duración: " << duracion << " min" << endl;
    cout << "Género: " << genero << endl;
    cout << "Calificación IMDB: " << calificacionP << endl;

    double calificacionUsuario = getCalificacionUser();
    if (calificacionUsuario == 0){
        cout << "No has calificado este título" << endl;
    }

    else{
        cout << "Tu calificación: " << calificacionUsuario << endl;
    }
  
}

void Pelicula::calificarTitulo(double calificacionUser) {
    setCalificacionUser(calificacionUser);
}

std::string Pelicula::getType() const{
    return type;
}


//EPISODIO
Episodio::Episodio(const string& title, int duration) : titulo(title), duracion(duration) {}

string Episodio::getTituloEp() const{
    return titulo;
}

int Episodio::getDuracionEp() const{
    return duracion;
}

void Episodio::getInfo() const{
    cout << "   " << titulo << " -- " << duracion << " min" << endl;
}

int Episodio::getNumEpisodio() const{
    return numEpisodio;
}

//TEMPORADA
Temporada::Temporada(int numeroTemporada, int numEpisodios) : numeroTemporada(numeroTemporada), numEpisodios(numEpisodios) {

}

Temporada::~Temporada() {
    
}

int Temporada::getNumTemporada() const {
    return numTemporada;
}

void Temporada::addEpisodio(Episodio* episodio) {
    episodios.push_back(episodio);
}

vector<Episodio*> Temporada::getEpisodios() const{
    return episodios;
}

void Temporada::getInfo() const {
        cout << endl;
        cout << "Temporada " << numeroTemporada << ":" << endl;
        for (auto& episodio : episodios) {
            episodio->getInfo(); // Llama al método getInfo de cada objeto Episodio
        }
    }



//SERIE
Serie::Serie(int id, const string& name, string type, const string& gen, double rateS, double rateUser, int numSeasons) : Video(id, name, numSeasons, gen, rateS, rateUser) {

}

Serie::~Serie() {
    for (auto& temporada : temporadas) {
        delete temporada;
    }
}

void Serie::addTemporada(Temporada* temporada) {
    temporadas.push_back(temporada);
}

vector<Temporada*> Serie::getTemporadas() const {
    return temporadas;
}

void Serie::getInfo() const{
    cout << "ID: " << ID << endl;
    cout << "Título: " << nombre << endl;
    cout << "Género: " << genero << endl;
    cout << "Calificación IMDB: " << calificacionP << endl;
    
    double calificacionUsuario = getCalificacionUser();
    if (calificacionUsuario == 0){
        cout << "No has calificado este título" << endl;
    }

    else{
        cout << "Tu calificación: " << calificacionUsuario << endl;
    }
    cout << "Número de temporadas: " << temporadas.size() << endl;

    for (const auto& temporada : temporadas) {

        temporada->getInfo(); // Llama al método getInfo de cada objeto Temporada
    }
    cout << endl;
}

void Serie::calificarTitulo(double calificacionUser) {
    setCalificacionUser(calificacionUser);
}

std::string Serie::getType() const{
    return "Serie";
}