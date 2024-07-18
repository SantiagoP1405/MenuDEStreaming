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
#include "clases.cpp"
using namespace std;

//Catalogo completo ------------------------------------------------------------
//ESTAS FUNCIONES SON PARA CUANDO EL CATÁLOGO INCUYE SERIES Y PELÍCULAS
void mostrarCatalogoCompleto(vector<Video*> catalogo) {
    cout << "---------- CATALOGO ----------" << endl;
    cout<< endl;
    cout << "--------- Peliculas ----------" << endl;
    for (auto& video : catalogo) { //ciclo for que recorre todo el vector. 
    //auto sirve para deducir que el tipo de variable es Video, y se le pone & para indicar que es una referencia. 

        if (video->getType() == "Pelicula") {
            cout << video->getID() << ". " << video->getNombre() << endl;
        }
    }
    cout << endl;
    cout << "----------- Series -----------" << endl;
    for (auto& video : catalogo) {
        if (video->getType() == "Serie") {
            cout << video->getID() << ". " << video->getNombre() << endl;
        }
    }
}

void ordenarPorCalificacionCompleto(const vector<Video*>& catalogo) {
    vector<Video*> peliculas = catalogo;
    vector<Video*> series = catalogo;

    // Separar películas y series
    for (auto element = peliculas.begin(); element != peliculas.end();) {
        if ((*element)->getType() != "Pelicula") {  //*element verifica si el elemento que apunta al iterador no es pelicula
            peliculas.erase(element); // .erase() se sua para eliminar el elemento de un vector
        } else {
            ++element;
        }
    }

    for (auto element = series.begin(); element != series.end();) {
        if ((*element)->getType() != "Serie") {
            series.erase(element);
        } else {
            ++element;
        }
    }

    // Ordenar películas y series por calificación
    sort(peliculas.begin(), peliculas.end(), [](const Video* a, const Video* b) { //Sort se usa para ordenar los elementos
    /*[]: Captura de variables externas.
(const Video* a, const Video* b): Parámetros de la lambda. Aquí se están pasando dos punteros a objetos Video.
{ return a->getCalificacionP() > b->getCalificacionP(); }: Cuerpo de la lambda. Compara las calificaciones de dos objetos Video.*/
        return a->getCalificacionP() > b->getCalificacionP();
    });

    sort(series.begin(), series.end(), [](const Video* a, const Video* b) {
        return a->getCalificacionP() > b->getCalificacionP();
    });

    // Imprimir las películas
    cout << "---------- Peliculas ----------" << endl;
    int currentCalificacion = -1; //para asegurar que la calificacion no sea menor a 0
    for (auto& video : peliculas) {
        int calificacion = static_cast<int>(video->getCalificacionP());
        if (calificacion != currentCalificacion) {
            cout << endl;
            cout << "Calificacion " << calificacion << ":" << endl;
            currentCalificacion = calificacion;
        }
        cout << video->getID() << ". " << video->getNombre() << " - Calificacion: " << video->getCalificacionP() << endl;
    }
    cout << endl;

    // Imprimir las series
    cout << "---------- Series ----------" << endl;
    for (auto& video : series) {
        int calificacion = static_cast<int>(video->getCalificacionP());
        if (calificacion != currentCalificacion) {
            cout << endl;
            cout << "Calificacion " << calificacion << ":" << endl;
            currentCalificacion = calificacion;
        }
        cout << video->getID() << ". " << video->getNombre() << " - Calificacion: " << video->getCalificacionP() << endl;
    }
    cout << endl;
}

void ordenarPorGeneroCompleto(const vector<Video*>& catalogo) {
    // Arreglo de vectores para almacenar los videos por género y tipo
    vector<Video*> accionPeliculas;
    vector<Video*> misterioPeliculas;
    vector<Video*> dramaPeliculas;
    vector<Video*> terrorPeliculas;
    vector<Video*> accionSeries;
    vector<Video*> misterioSeries;
    vector<Video*> dramaSeries;
    vector<Video*> terrorSeries;

    // Agrupar los videos según su género y tipo
    for (auto& video : catalogo) {
        string genero = video->getGenero();
        if (video->getType() == "Pelicula") {
            if (genero == "Acción") {
                accionPeliculas.push_back(video);
            } else if (genero == "Misterio") {
                misterioPeliculas.push_back(video);
            } else if (genero == "Drama") {
                dramaPeliculas.push_back(video);
            } else if (genero == "Terror") {
                terrorPeliculas.push_back(video);
            }
        } else if (video->getType() == "Serie") {
            if (genero == "Acción") {
                accionSeries.push_back(video);
            } else if (genero == "Misterio") {
                misterioSeries.push_back(video);
            } else if (genero == "Drama") {
                dramaSeries.push_back(video);
            } else if (genero == "Terror") {
                terrorSeries.push_back(video);
            }
        }
    }

    cout << "---------- CATALOGO -----------" << endl;
    cout << endl;
    // Imprimir las películas

    cout << "----------- Peliculas -----------" << endl;
    if (!accionPeliculas.empty()) { //verifica si este vector no está vacío
        cout << "Género Acción:" << endl;
        for (auto& video : accionPeliculas) {
            cout << video->getID() << ". " << video->getNombre() << endl;
        }
        cout << endl;
    }

    if (!misterioPeliculas.empty()) {
        cout << "Género Misterio:" << endl;
        for (auto& video : misterioPeliculas) {
            cout << video->getID() << ". " << video->getNombre() << endl;
        }
        cout << endl;
    }

    if (!dramaPeliculas.empty()) {
        cout << "Género Drama:" << endl;
        for (auto& video : dramaPeliculas) {
            cout << video->getID() << ". " << video->getNombre() << endl;
        }
        cout << endl;
    }

    if (!terrorPeliculas.empty()) {
        cout << "Género Terror:" << endl;
        for (auto& video : terrorPeliculas) {
            cout << video->getID() << ". " << video->getNombre() << endl;
        }
        cout << endl;
    }

    // Imprimir las series
    cout << "----------- Series ----------" << endl;
    if (!accionSeries.empty()) {
        cout << "Género Acción:" << endl;
        for (auto& video : accionSeries) {
            cout << video->getID() << ". " << video->getNombre() << endl;
        }
        cout << endl;
    }

    if (!misterioSeries.empty()) {
        cout << "Género Misterio:" << endl;
        for (auto& video : misterioSeries) {
            cout << video->getID() << ". " << video->getNombre() << endl;
        }
        cout << endl;
    }

    if (!dramaSeries.empty()) {
        cout << "Género Drama:" << endl;
        for (auto& video : dramaSeries) {
            cout << video->getID() << ". " << video->getNombre() << endl;
        }
        cout << endl;
    }

    if (!terrorSeries.empty()) {
        cout << "Género Terror:" << endl;
        for (auto& video : terrorSeries) {
            cout << video->getID() << ". " << video->getNombre() << endl;
        }
        cout << endl;
    }
}

//------------------------------------------------------------------------------

void mostrarDetallesVideos(const vector<Video*>& catalogo, int id) {
    for (auto& video : catalogo) {
        if (video->getID() == id) {
            video->getInfo(); // Llamada a la función para mostrar la información del video
            return; // Salir de la función una vez que encontramos e imprimimos el video
        }
    }
    // Si no encontramos el video, mostramos un mensaje de error
    cout << "ID no encontrado. Por favor, ingrese un ID válido." << endl;
}



//Catálogo por tipo -----------------------------------------------------------
//Estas funciones son para cuando solo se quieren las películas o las series
void mostrarCatalogo(vector<Video*> catalogo) {
    cout << "---------- Catálogo ----------" << endl;
    for (auto& video : catalogo) {
        cout << video->getID() << ". " << video->getNombre() << endl;
    }
}

void ordenarPorCalificacion(const vector<Video*>& catalogo, const string& tipo) {
    vector<Video*> videos = catalogo;

    // Filtrar videos por tipo
    videos.erase(remove_if(videos.begin(), videos.end(), [tipo](const Video* video) {
        return video->getType()!= tipo;
    }), videos.end());

    // Ordenar videos por calificación
    sort(videos.begin(), videos.end(), [](const Video* a, const Video* b) {
        return a->getCalificacionP() > b->getCalificacionP();
    });

    // Imprimir los videos
    cout << "---------- " << tipo << " ----------" << endl;
    int currentCalificacion = -1;
    for (auto& video : videos) {
        int calificacion = static_cast<int>(video->getCalificacionP());
        if (calificacion!= currentCalificacion) {
            cout << endl;
            cout << "Calificacion " << calificacion << ":" << endl;
            currentCalificacion = calificacion;
        }
        cout << video->getID() << ". " << video->getNombre() << " - Calificacion: " << video->getCalificacionP() << endl;
    }
    cout << endl;
}
void ordenarPorGenero(const vector<Video*>& catalogo) {
    // Crear un arreglo de vectores para almacenar los videos por género
    vector<Video*> accion;
    vector<Video*> misterio;
    vector<Video*> drama;
    vector<Video*> terror;

    // Agrupar los videos según su género
    for (auto& video : catalogo) {
        string genero = video->getGenero();
        if (genero == "Acción") {
            accion.push_back(video);
        } else if (genero == "Misterio") {
            misterio.push_back(video);
        } else if (genero == "Drama") {
            drama.push_back(video);
        } else if (genero == "Terror") {
            terror.push_back(video);
        }
    }

    cout << "Géneros:" << endl;
    if (!accion.empty()) {
        cout << "Acción:" << endl;
        for (auto& video : accion) {
            cout << video->getID() << ". " << video->getNombre() << endl;
        }
        cout << endl;
    }

    if (!misterio.empty()) {
        cout << "Misterio:" << endl;
        for (auto& video : misterio) {
            cout << video->getID() << ". " << video->getNombre() << endl;
        }
        cout << endl;
    }

    if (!drama.empty()) {
        cout << "Drama:" << endl;
        for (auto& video : drama) {
            cout << video->getID() << ". " << video->getNombre() << endl;
        }
        cout << endl;
    }

    if (!terror.empty()) {
        cout << "Terror:" << endl;
        for (auto& video : terror) {
            cout << video->getID() << ". " << video->getNombre() << endl;
        }
        cout << endl;
    }
}

//------------------------------------------------------------------------------
int main(){

//Catálogo completo (Series y películas)
    vector<Video*> catalogoCompleto;

//Catálogo solo de películas
vector<Video*> catalogoPeliculas;  
{
    Pelicula* batman = new Pelicula(1, "El Caballero de la Noche", "Pelicula", 152, "Acción", 4.6, 0);
    catalogoCompleto.push_back(batman);
    catalogoPeliculas.push_back(batman);

    Pelicula* bvs = new Pelicula(2, "Batman v Superman: El origen de la Justicia", "Pelicula", 153, "Acción", 3.7, 0);
    catalogoCompleto.push_back(bvs);
    catalogoPeliculas.push_back(bvs);

    Pelicula* rebelMoon = new Pelicula(3, "Rebel Moon - Parte 1: La niña del fuego", "Pelicula", 135, "Acción", 3.3, 0);
    catalogoCompleto.push_back(rebelMoon);
    catalogoPeliculas.push_back(rebelMoon);

    Pelicula* seven = new Pelicula(4, "Seven", "Pelicula", 130, "Misterio", 4.5, 0);
    catalogoCompleto.push_back(seven);
    catalogoPeliculas.push_back(seven);

    Pelicula* train = new Pelicula(5, "La chica del tren", "Pelicula", 112, "Misterio", 3.5, 0);
    catalogoCompleto.push_back(train);
    catalogoPeliculas.push_back(train);

    Pelicula* snowman = new Pelicula(6, "El muñeco de nieve", "Pelicula", 119, "Misterio", 2, 0);
    catalogoCompleto.push_back(snowman);
    catalogoPeliculas.push_back(snowman);

    Pelicula* schindler = new Pelicula(7, "La Lista de Schindler", "Pelicula", 195, "Drama", 5, 0);
    catalogoCompleto.push_back(schindler);
    catalogoPeliculas.push_back(schindler);

    Pelicula* climax = new Pelicula(8, "Climax", "Pelicula", 93, "Drama", 3.7, 0);
    catalogoCompleto.push_back(climax);
    catalogoPeliculas.push_back(climax);

    Pelicula* incidente = new Pelicula(9, "El incidente", "Pelicula", 91, "Drama", 2.3, 0);
    catalogoCompleto.push_back(incidente);
    catalogoPeliculas.push_back(incidente);

    Pelicula* basterds = new Pelicula(10, "Bastardos sin Gloria", "Pelicula", 153, "Drama", 5, 0);
    catalogoCompleto.push_back(basterds);
    catalogoPeliculas.push_back(basterds);

    Pelicula* mean1 = new Pelicula(11, "The Mean One", "Pelicula", 91, "Terror", 1, 0);
    catalogoCompleto.push_back(mean1);
    catalogoPeliculas.push_back(mean1);    
}

//Catálogo sólo de series
vector<Video*> catalogoSeries;
//Serie Arcane ----------------------------------------------------------------
{
    Temporada* temporada1Arcane = new Temporada(1, 9);
    temporada1Arcane->addEpisodio(new Episodio("1. ¡Bienvenidos!", 43));
    temporada1Arcane->addEpisodio(new Episodio("2. Algunos misterios están mejor sin resolver", 40));
    temporada1Arcane->addEpisodio(new Episodio("3. La violencia bruta es necesaria para el cambio", 44));
    temporada1Arcane->addEpisodio(new Episodio("4. ¡Feliz dia del progreso!", 40));
    temporada1Arcane->addEpisodio(new Episodio("5. Todo el mundo quiere ser mi enemigo", 40));
    temporada1Arcane->addEpisodio(new Episodio("6. Cuando caigan estos muros", 42));
    temporada1Arcane->addEpisodio(new Episodio("7. El salvador", 40));
    temporada1Arcane->addEpisodio(new Episodio("8. Agua y aceite", 40));
    temporada1Arcane->addEpisodio(new Episodio("9. El monstruo que creaste", 41));

    Serie* arcane = new Serie(12, "Arcane", "Serie", "Acción", 4.5, 0, 1);
    arcane->addTemporada(temporada1Arcane);
    catalogoCompleto.push_back(arcane); //La serie Arcane se añade al catálogo completo
    catalogoSeries.push_back(arcane); //La serie Arcane se añade al catálogo de series
}
//-----------------------------------------------------------------------------

//Serie Invencible ------------------------------------------------------------
{
    //Primera temporada
    Temporada* temporada1Invencible = new Temporada(1, 8);
    temporada1Invencible->addEpisodio(new Episodio("1. Ya era hora", 51));
    temporada1Invencible->addEpisodio(new Episodio("2. Aquí vamos", 48));
    temporada1Invencible->addEpisodio(new Episodio("3. ¿A quién llamas feo?", 45));
    temporada1Invencible->addEpisodio(new Episodio("4. Neil Armstrong, muérete de envidia", 48));
    temporada1Invencible->addEpisodio(new Episodio("5. Eso me dolió", 50));
    temporada1Invencible->addEpisodio(new Episodio("6. Te ves casi muerto", 48));
    temporada1Invencible->addEpisodio(new Episodio("7. Tenemos que hablar", 52));
    temporada1Invencible->addEpisodio(new Episodio("8. Mi verdadero origen", 48));

    //Segunda temporada
    Temporada* temporada2Invencible = new Temporada(2, 8);
    temporada2Invencible->addEpisodio(new Episodio("1. Una lección para tu próxima vida", 49));
    temporada2Invencible->addEpisodio(new Episodio("2. En seis horas...", 50));
    temporada2Invencible->addEpisodio(new Episodio("3. Esta misiva, esta maquinación", 49));
    temporada2Invencible->addEpisodio(new Episodio("4. Hace mucho que no nos vemos", 47));
    temporada2Invencible->addEpisodio(new Episodio("5. Esto te va a sorprender", 51));
    temporada2Invencible->addEpisodio(new Episodio("6. No es así de sencillo", 50));
    temporada2Invencible->addEpisodio(new Episodio("7. No voy a ningún lado", 52));
    temporada2Invencible->addEpisodio(new Episodio("8. Creí que eras más fuerte", 54));


    Serie* invencible = new Serie(13, "Invencible", "Serie", "Acción", 4.4, 0, 2);
    invencible -> addTemporada(temporada1Invencible);
    invencible -> addTemporada(temporada2Invencible);
    catalogoCompleto.push_back(invencible); //La serie Invencible se añade al catálogo completo
    catalogoSeries.push_back(invencible); //La serie Invencible se añade al catálogo de series
}
//-----------------------------------------------------------------------------

//Serie La maldición de Hill House --------------------------------------------
{
    Temporada* temporadaHillHouse = new Temporada(1, 10);
    temporadaHillHouse->addEpisodio(new Episodio("1. Steven ve a un fantasma", 60));
    temporadaHillHouse->addEpisodio(new Episodio("2. Ataúd abierto", 51));
    temporadaHillHouse->addEpisodio(new Episodio("3. El Toque", 53));
    temporadaHillHouse->addEpisodio(new Episodio("4. Cosa de gemelos", 53));
    temporadaHillHouse->addEpisodio(new Episodio("5. La mujer del cuello roto", 70));
    temporadaHillHouse->addEpisodio(new Episodio("6. Dos tormentas", 56));
    temporadaHillHouse->addEpisodio(new Episodio("7. Panegírico", 60));
    temporadaHillHouse->addEpisodio(new Episodio("8. Marcas Testigo", 43));
    temporadaHillHouse->addEpisodio(new Episodio("9. Pesadillas Horribles", 57));
    temporadaHillHouse->addEpisodio(new Episodio("10. El silencio oprime incesante", 71));

    Serie* hillHouse = new Serie(14, "La Maldición de Hill House", "Serie", "Terror", 4.3, 0, 1);
    hillHouse -> addTemporada(temporadaHillHouse);
    catalogoCompleto.push_back(hillHouse); //La serie La Maldición de Hill House se añade al catálogo completo
    catalogoSeries.push_back(hillHouse); //La serie La Maldición de Hill House se añade al catálogo de series
}
//-----------------------------------------------------------------------------

//Serie The I-Land ------------------------------------------------------------
{
    Temporada* temporadaIland = new Temporada(1, 7);
    temporadaIland->addEpisodio(new Episodio("1. Magnífico nuevo mundo", 42));
    temporadaIland->addEpisodio(new Episodio("2. Espléndidos palacios", 43));
    temporadaIland->addEpisodio(new Episodio("3. Tramoya Instrumental", 39));
    temporadaIland->addEpisodio(new Episodio("4. Cuántas criaturashermosas", 41));
    temporadaIland->addEpisodio(new Episodio("5. Torres orladas de nubes", 41));
    temporadaIland->addEpisodio(new Episodio("6. El mismísimo globo", 37));
    temporadaIland->addEpisodio(new Episodio("7. El abismo oscuro del pasado", 38));

    Serie* iLand = new Serie(15, "The I-Land", "Serie", "Drama", 2.2, 0, 1);
    iLand -> addTemporada(temporadaIland);
    catalogoCompleto.push_back(iLand); //La serie The I-Land se añade al catálogo completo
    catalogoSeries.push_back(iLand); //La serie The I-Land se añade al catálogo de series
}    
//-----------------------------------------------------------------------------

    
//Serie Breaking Bad-----------------------------------------------------------
{
    //Primera temporada
    Temporada* temp1BB = new Temporada(1, 7);
    temp1BB->addEpisodio(new Episodio("1. Principio del fin", 58));
    temp1BB->addEpisodio(new Episodio("2. El gato en la bolsa", 48));
    temp1BB->addEpisodio(new Episodio("3. Y la bolsa en el río", 48));
    temp1BB->addEpisodio(new Episodio("4. Cáncer", 48));
    temp1BB->addEpisodio(new Episodio("5. Materia Gris", 48));
    temp1BB->addEpisodio(new Episodio("6. Un loco puñado de nada", 48));
    temp1BB->addEpisodio(new Episodio("7. Acuerdo no violento", 47));

    //Segunda temporada
    Temporada* temp2BB = new Temporada(2, 10);
    temp2BB->addEpisodio(new Episodio("1. Siete con treinta y siete", 47));
    temp2BB->addEpisodio(new Episodio("2. A las brasas", 48));
    temp2BB->addEpisodio(new Episodio("3. Picadura de una abeja muerta", 47));
    temp2BB->addEpisodio(new Episodio("4. Abajo", 47));
    temp2BB->addEpisodio(new Episodio("5. Rotura", 47));
    temp2BB->addEpisodio(new Episodio("6. Cucú", 47));
    temp2BB->addEpisodio(new Episodio("7. Negro y azul", 47));
    temp2BB->addEpisodio(new Episodio("8. ¡Llama a Saul!", 47));
    temp2BB->addEpisodio(new Episodio("9. Cuatro días afuera", 47));
    temp2BB->addEpisodio(new Episodio("10. Terminado", 47));

    Serie* bBad = new Serie(16, "Breaking Bad", "Serie", "Drama", 4.5, 0, 2);
    bBad -> addTemporada(temp1BB);
    bBad -> addTemporada(temp2BB);
    catalogoCompleto.push_back(bBad); //La serie Breaking Bad se añade al catálogo de completo
    catalogoSeries.push_back(bBad); //La serie Breaking Bad se añade al catálogo de series    
}
//-----------------------------------------------------------------------------

//Serie La Niebla -------------------------------------------------------------
{
    Temporada* tNiebla = new Temporada(1,10);
    tNiebla->addEpisodio(new Episodio("1. Piloto", 48));
    tNiebla->addEpisodio(new Episodio("2. Abstinencia", 38));
    tNiebla->addEpisodio(new Episodio("3. Exposición", 43));
    tNiebla->addEpisodio(new Episodio("4. Pequod", 42));
    tNiebla->addEpisodio(new Episodio("5. La sala de espera", 42));
    tNiebla->addEpisodio(new Episodio("6. Malo conocido", 42));
    tNiebla->addEpisodio(new Episodio("7. Revelaciones", 42));
    tNiebla->addEpisodio(new Episodio("8. La ley natural", 42));
    tNiebla->addEpisodio(new Episodio("9. Encuentros", 42));
    tNiebla->addEpisodio(new Episodio("10. La décima comida", 41));

    Serie* niebla = new Serie(17, "La Niebla", "Serie", "Misterio", 1, 0, 1);
    niebla -> addTemporada(tNiebla);
    catalogoCompleto.push_back(niebla); //La serie La Niebla se añade al catálogo completo
    catalogoSeries.push_back(niebla); //La serie La Niebla se añade al catálogo de series
}
//-----------------------------------------------------------------------------

    char choice;
    cout << "---------- Bienvenido ----------" << endl;
    cout << "Selecciona una de las opciones del menú" << endl;
    cout << endl;
    do{
        cout << "---------- MENÚ ----------" << endl;
        cout << "1. Mostrar todos los videos" << endl;
        cout << "2. Mostrar Películas" << endl;
        cout << "3. Mostrar Series" << endl;
        cout << "0. Salir" << endl;
        cout << endl;
        cout << "Seleccione una opción: ";
        cin >> choice;
        cout << endl;

    

        switch (choice) {
            
            //OPCION 1. Mostrar todos los videos
            case '1': {
                char choiceCase1;
                do {
                    cout << "Pulsa la tecla <D> para ver el catálogo en general" << endl;
                    cout << "Pulsa la tecla <C> para ver el catálogo ordenado por calificación de IMDB" << endl;    
                    cout << "Pulsa la tecla <G> para ver el catálogo ordenado por género" << endl;
                    cout << "Pulsa la tecla <Q> para regresar al menú principal" << endl;

                    cin >> choiceCase1;
                    choiceCase1 = toupper(choiceCase1);
                    switch (choiceCase1) {
                        int idCase1;
                        case 'D':
                            
                            cout << endl;
                            mostrarCatalogoCompleto(catalogoCompleto);
                            cout << endl;
                            cout << "Ingresa el ID de algún video para ver su información o 0 para regresar: ";
                            cin >> idCase1;
                            
                            if (idCase1 > 0) {
                                cout << endl;
                                mostrarDetallesVideos(catalogoCompleto, idCase1);
                                cout << endl;
                                int rate1;
                                cout << "¿Desea calificar este título?" << endl;
                                cout << "Pulse < 1 > para confirmar" << endl;
                                cout << "Pulse < 0 > para regresar" << endl;
                                cin >> rate1;
                                cout << endl;

                                switch (rate1){
                                    case 1:{
                                        if (idCase1 > 0) {
                                            for (auto& video : catalogoCompleto) {
                                                if (video->getID() == idCase1) {
                                                    double calificacionVideo;
                                                    cout << "Ingresa tu calificación (de 0 a 5): ";
                                                    cin >> calificacionVideo;

                                                    if (calificacionVideo >= 0 && calificacionVideo <= 5) {
                                                        video->calificarTitulo(calificacionVideo);
                                                        cout << "Calificación guardada correctamente." << endl;

                                                        cout << endl;
                                                        mostrarDetallesVideos(catalogoCompleto, idCase1);
                                                        cout << endl;
                                                    }

                                                    else {
                                                        cout << "La calificación debe ser un número entre 0 y 5." << endl;
                                                        cout << endl;
                                                    }

                                                }
                                            }
                                        }

                                        break;
                                    }

                                    case 0:{

                                        break;
                                    }

                                }
                            }

                            break;

                        case 'C':

                            cout << endl;
                            ordenarPorCalificacionCompleto(catalogoCompleto);
                            cout << "Ingresa el ID de algún video para ver su información o 0 para regresar: ";
                            cin >> idCase1;
                            
                            if (idCase1 > 0) {
                                cout << endl;
                                mostrarDetallesVideos(catalogoCompleto, idCase1);
                                cout << endl;
                                int rate1;
                                cout << "¿Desea calificar este título?" << endl;
                                cout << "Pulse < 1 > para confirmar" << endl;
                                cout << "Pulse < 0 > para regresar" << endl;
                                cin >> rate1;
                                cout << endl;

                                switch (rate1){
                                    case 1:{
                                        if (idCase1 > 0) {
                                            for (auto& video : catalogoCompleto) {
                                                if (video->getID() == idCase1) {
                                                    double calificacionVideo;
                                                    cout << "Ingresa tu calificación (de 0 a 5): ";
                                                    cin >> calificacionVideo;

                                                    if (calificacionVideo >= 0 && calificacionVideo <= 5) {
                                                        video->calificarTitulo(calificacionVideo);
                                                        cout << "Calificación guardada correctamente." << endl;

                                                        cout << endl;
                                                        mostrarDetallesVideos(catalogoCompleto, idCase1);
                                                        cout << endl;
                                                    }

                                                    else {
                                                        cout << "La calificación debe ser un número entre 0 y 5." << endl;
                                                        cout << endl;
                                                    }

                                                }
                                            }
                                        }

                                        break;
                                    }

                                    case 0:{

                                        break;
                                    }

                                }
                            }

                            break;

                        case 'G':
                        
                            cout << endl;
                            ordenarPorGeneroCompleto(catalogoCompleto);
                            cout << endl;
                            cout << "Ingresa el ID de algún video para ver su información o 0 para regresar: ";
                            cin >> idCase1;
                           
                            if (idCase1 > 0) {
                                cout << endl;
                                mostrarDetallesVideos(catalogoCompleto, idCase1);
                                cout << endl;
                                int rate1;
                                cout << "¿Desea calificar este título?" << endl;
                                cout << "Pulse < 1 > para confirmar" << endl;
                                cout << "Pulse < 0 > para regresar" << endl;
                                cin >> rate1;
                                cout << endl;

                                switch (rate1){
                                    case 1:{
                                        if (idCase1 > 0) {
                                            for (auto& video : catalogoCompleto) {
                                                if (video->getID() == idCase1) {
                                                    double calificacionVideo;
                                                    cout << "Ingresa tu calificación (de 0 a 5): ";
                                                    cin >> calificacionVideo;

                                                    if (calificacionVideo >= 0 && calificacionVideo <= 5) {
                                                        video->calificarTitulo(calificacionVideo);
                                                        cout << "Calificación guardada correctamente." << endl;

                                                        cout << endl;
                                                        mostrarDetallesVideos(catalogoCompleto, idCase1);
                                                        cout << endl;
                                                    }

                                                    else {
                                                        cout << "La calificación debe ser un número entre 0 y 5." << endl;
                                                        cout << endl;
                                                        cin >> calificacionVideo;
                                                    }

                                                }
                                            }
                                        }

                                        break;
                                    }

                                    case 0:{

                                        break;
                                    }

                                }
                            }

                            break;

                        case 'Q':
                            break;

                        default:
                            cout << "Opcion no válida, intente nuevamente" << endl;
                    }       
                } while (choiceCase1 != 'Q');
            }

                break;
            //OPCION 2. Mostrar Películas
            case '2':{
                char choiceCase2;
                do {
                    cout << "Pulsa la tecla <D> para ver todo el catálogo de películas" << endl;
                    cout << "Pulsa la tecla <C> para ver el catálogo de películas ordenado por calificación de IMDB" << endl;    
                    cout << "Pulsa la tecla <G> para ver el catálogo de películas ordenado por género" << endl;
                    cout << "Pulsa la tecla <Q> para regresar al menú principal" << endl;

                    cin >> choiceCase2;
                    choiceCase2 = toupper(choiceCase2);
                    switch (choiceCase2) {
                        int idCase2;
                        case 'D':
                            
                            cout << endl;
                            mostrarCatalogo(catalogoPeliculas);
                            cout << endl;
                            cout << "Ingresa el ID de alguna película para ver su información o 0 para regresar: ";
                            cin >> idCase2;
                            
                            if (idCase2 > 0) {
                                cout << endl;
                                mostrarDetallesVideos(catalogoPeliculas, idCase2);
                                cout << endl;
                                int rate2;
                                cout << "¿Desea calificar este título?" << endl;
                                cout << "Pulse < 1 > para confirmar" << endl;
                                cout << "Pulse < 0 > para regresar" << endl;
                                cin >> rate2;
                                cout << endl;

                                switch (rate2){
                                    case 1:{
                                        if (idCase2 > 0) {
                                            for (auto& video : catalogoPeliculas) {
                                                if (video->getID() == idCase2) {
                                                    double calificacionPelicula;
                                                    cout << "Ingresa tu calificación (de 0 a 5): ";
                                                    cin >> calificacionPelicula;

                                                    if (calificacionPelicula >= 0 && calificacionPelicula <= 5) {
                                                        video->calificarTitulo(calificacionPelicula);
                                                        cout << "Calificación guardada correctamente." << endl;

                                                        cout << endl;
                                                        mostrarDetallesVideos(catalogoPeliculas, idCase2);
                                                        cout << endl;
                                                    }

                                                    else {
                                                        cout << "La calificación debe ser un número entre 0 y 5." << endl;
                                                        cout << endl;
                                                        cin >> calificacionPelicula;
                                                    }

                                                }
                                            }
                                        }

                                        break;
                                    }

                                    case 0:{

                                        break;
                                    }

                                }
                            }

                            break;

                        case 'C':

                            cout << endl;
                            ordenarPorCalificacion(catalogoPeliculas, "Pelicula");
                            cout << "Ingresa el ID de algo para una película para ver su información o 0 para regresar: ";
                            cin >> idCase2;
                            
                            if (idCase2 > 0) {
                                cout << endl;
                                mostrarDetallesVideos(catalogoPeliculas, idCase2);
                                cout << endl;
                                int rate2;
                                cout << "¿Desea calificar este título?" << endl;
                                cout << "Pulse < 1 > para confirmar" << endl;
                                cout << "Pulse < 0 > para regresar" << endl;
                                cin >> rate2;
                                cout << endl;

                                switch (rate2){
                                    case 1:{
                                        if (idCase2 > 0) {
                                            for (auto& video : catalogoPeliculas) {
                                                if (video->getID() == idCase2) {
                                                    double calificacionPelicula;
                                                    cout << "Ingresa tu calificación (de 0 a 5): ";
                                                    cin >> calificacionPelicula;

                                                    if (calificacionPelicula >= 0 && calificacionPelicula <= 5) {
                                                        video->calificarTitulo(calificacionPelicula);
                                                        cout << "Calificación guardada correctamente." << endl;

                                                        cout << endl;
                                                        mostrarDetallesVideos(catalogoPeliculas, idCase2);
                                                        cout << endl;
                                                    }

                                                    else {
                                                        cout << "La calificación debe ser un número entre 0 y 5." << endl;
                                                        cout << endl;
                                                    }

                                                }
                                            }
                                        }

                                        break;
                                    }

                                    case 0:{

                                        break;
                                    }

                                }
                            }
                            break;

                        case 'G':
                        
                            cout << endl;
                            ordenarPorGenero(catalogoPeliculas);
                            cout << endl;
                            cout << "Ingresa el ID de alguna película para ver su información o 0 para regresar: ";
                            cin >> idCase2;
                           
                            if (idCase2 > 0) {
                                cout << endl;
                                mostrarDetallesVideos(catalogoPeliculas, idCase2);
                                cout << endl;
                                int rate2;
                                cout << "¿Desea calificar este título?" << endl;
                                cout << "Pulse < 1 > para confirmar" << endl;
                                cout << "Pulse < 0 > para regresar" << endl;
                                cin >> rate2;
                                cout << endl;

                                switch (rate2){
                                    case 1:{
                                        if (idCase2 > 0) {
                                            for (auto& video : catalogoPeliculas) {
                                                if (video->getID() == idCase2) {
                                                    double calificacionPelicula;
                                                    cout << "Ingresa tu calificación (de 0 a 5): ";
                                                    cin >> calificacionPelicula;

                                                    if (calificacionPelicula >= 0 && calificacionPelicula <= 5) {
                                                        video->calificarTitulo(calificacionPelicula);
                                                        cout << "Calificación guardada correctamente." << endl;

                                                        cout << endl;
                                                        mostrarDetallesVideos(catalogoPeliculas, idCase2);
                                                        cout << endl;
                                                    }

                                                    else {
                                                        cout << "La calificación debe ser un número entre 0 y 5." << endl;
                                                        cout << endl;
                                                    }

                                                }
                                            }
                                        }

                                        break;
                                    }

                                    case 0:{

                                        break;
                                    }

                                }
                            }

                            break;

                        case 'Q':
                            break;
                    }       
                } while (choiceCase2 != 'Q');

            }
            
                break;
            
            // OPCION 3. Mostrar Series
            case '3':{
                char choiceCase3;
                do {
                    cout << "Pulsa la tecla <D> para ver todo el catálogo de series" << endl;
                    cout << "Pulsa la tecla <C> para ver el catálogo de series ordenado por calificación de IMDB" << endl;    
                    cout << "Pulsa la tecla <G> para ver el catálogo de series ordenado por género" << endl;
                    cout << "Pulsa la tecla <Q> para regresar al menú principal" << endl;

                    cin >> choiceCase3;
                    choiceCase3 = toupper(choiceCase3);
                    switch (choiceCase3) {
                        int idCase3;
                        case 'D':
                            
                            cout << endl;
                            mostrarCatalogo(catalogoSeries);
                            cout << endl;
                            cout << "Ingresa el ID de alguna serie para ver su información o 0 para regresar: ";
                            cin >> idCase3;
                            
                            if (idCase3 > 0) {
                                cout << endl;
                                mostrarDetallesVideos(catalogoSeries, idCase3);
                                cout << endl;
                                int rate3;
                                cout << "¿Desea calificar este título?" << endl;
                                cout << "Pulse < 1 > para confirmar" << endl;
                                cout << "Pulse < 0 > para regresar" << endl;
                                cin >> rate3;
                                cout << endl;

                                switch (rate3){
                                    case 1:{
                                        if (idCase3 > 0) {
                                            for (auto& video : catalogoSeries) {
                                                if (video->getID() == idCase3) {
                                                    double calificacionSerie;
                                                    cout << "Ingresa tu calificación (de 0 a 5): ";
                                                    cin >> calificacionSerie;

                                                    if (calificacionSerie >= 0 && calificacionSerie <= 5) {
                                                        video->calificarTitulo(calificacionSerie);
                                                        cout << "Calificación guardada correctamente." << endl;

                                                        cout << endl;
                                                        mostrarDetallesVideos(catalogoSeries, idCase3);
                                                        cout << endl;
                                                    }

                                                    else {
                                                        cout << "La calificación debe ser un número entre 0 y 5." << endl;
                                                        cout << endl;
                                                        cin >> calificacionSerie;
                                                    }

                                                }
                                            }
                                        }

                                        break;
                                    }

                                    case 0:{

                                        break;
                                    }

                                }
                            }

                            break;

                        case 'C':

                            cout << endl;
                            ordenarPorCalificacion(catalogoSeries, "Serie");
                            cout << "Ingresa el ID de alguna serie para ver su información o 0 para regresar: ";
                            cin >> idCase3;
                            
                            if (idCase3 > 0) {
                                cout << endl;
                                mostrarDetallesVideos(catalogoSeries, idCase3);
                                cout << endl;
                                int rate3;
                                cout << "¿Desea calificar este título?" << endl;
                                cout << "Pulse < 1 > para confirmar" << endl;
                                cout << "Pulse < 0 > para regresar" << endl;
                                cin >> rate3;
                                cout << endl;

                                switch (rate3){
                                    case 1:{
                                        if (idCase3 > 0) {
                                            for (auto& video : catalogoSeries) {
                                                if (video->getID() == idCase3) {
                                                    double calificacionSerie;
                                                    cout << "Ingresa tu calificación (de 0 a 5): ";
                                                    cin >> calificacionSerie;

                                                    if (calificacionSerie >= 0 && calificacionSerie <= 5) {
                                                        video->calificarTitulo(calificacionSerie);
                                                        cout << "Calificación guardada correctamente." << endl;

                                                        cout << endl;
                                                        mostrarDetallesVideos(catalogoSeries, idCase3);
                                                        cout << endl;
                                                    }

                                                    else {
                                                        cout << "La calificación debe ser un número entre 0 y 5." << endl;
                                                        cout << endl;
                                                    }

                                                }
                                            }
                                        }

                                        break;
                                    }

                                    case 0:{

                                        break;
                                    }

                                }
                            }
                            break;

                        case 'G':
                        
                            cout << endl;
                            ordenarPorGenero(catalogoSeries);
                            cout << endl;
                            cout << "Ingresa el ID de alguna película para ver su información o 0 para regresar: ";
                            cin >> idCase3;
                           
                            if (idCase3 > 0) {
                                cout << endl;
                                mostrarDetallesVideos(catalogoSeries, idCase3);
                                cout << endl;
                                int rate3;
                                cout << "¿Desea calificar este título?" << endl;
                                cout << "Pulse < 1 > para confirmar" << endl;
                                cout << "Pulse < 0 > para regresar" << endl;
                                cin >> rate3;
                                cout << endl;

                                switch (rate3){
                                    case 1:{
                                        if (idCase3 > 0) {
                                            for (auto& video : catalogoSeries) {
                                                if (video->getID() == idCase3) {
                                                    double calificacionSerie;
                                                    cout << "Ingresa tu calificación (de 0 a 5): ";
                                                    cin >> calificacionSerie;

                                                    if (calificacionSerie >= 0 && calificacionSerie <= 5) {
                                                        video->calificarTitulo(calificacionSerie);
                                                        cout << "Calificación guardada correctamente." << endl;

                                                        cout << endl;
                                                        mostrarDetallesVideos(catalogoSeries, idCase3);
                                                        cout << endl;
                                                    }

                                                    else {
                                                        cout << "La calificación debe ser un número entre 0 y 5." << endl;
                                                        cout << endl;
                                                    }

                                                }
                                            }
                                        }

                                        break;
                                    }

                                    case 0:{

                                        break;
                                    }

                                }
                            }

                            break;

                        case 'Q':
                            break;
                    }       
                } while (choiceCase3 != 'Q');



            }
                
                break;

            case '0':
                cout << "Cerrando sesión..." << endl;
                break;
            
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }

        
    } while (choice != '0');

    // Liberar memoria
    for (auto& video : catalogoCompleto) {
        delete video;
    }

    for (auto& video : catalogoPeliculas) {
        delete video;
    }

    for (auto& video : catalogoSeries) {
        delete video;
    }

    return 0;

}