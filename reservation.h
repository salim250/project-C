#include <gtk/gtk.h>

struct Date{
 int  jour;
 int  mois;
 int  annee;
} ;
typedef struct Date Date;

struct Excursion{
 char pseudo_client[10];
 int  Nb_places;
 char  tel[20];
 int  ID;
} ;
typedef struct Excursion Excursion;

struct Vol{
 char pseudo_client[10];
 char destination[20];
 char companie[20];
 char type_vol[20];
 int  Nb_billet;
 char classe[20];
 int ID;
};
typedef struct Vol Vol;

struct Hotel{
 char pseudo_client[10];
 char destination [20];
 char categorie[20];
 Date dt_d;
 Date dt_f;
 char  Nb_chambre[20];
 char type_chambre[50];
 char pension[20];
 int ID;
} ;

typedef struct Hotel Hotel;

struct Voiture{
 char pseudo_client[10];
 Date dt_dd;
 Date dt_ff;
 int ID;
};
typedef struct Voiture Voiture;
void enregistrer(Hotel h);
void enregistrere(Excursion e);
void enregistrerv(Vol v);
void enregistrert(Voiture t);
void afficher(GtkWidget *liste);
void affichervol(GtkWidget *liste);
void affichervoiture(GtkWidget *liste);
void afficherexcursion(GtkWidget *liste);
void supprimerhotel (int ID);
void supprimervol (int ID);
void supprimervoiture (int ID);
void supprimerexcursion (int ID);

