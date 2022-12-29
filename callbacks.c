#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reservation.h"
#include <string.h>
Hotel Selected_Resv_Hotel;
Voiture Selected_Resv_Voiture;
Vol Selected_Resv_Vol;
Excursion Selected_Resv_Excursion;
void
on_but_resvoiture_clicked              (GtkWidget       *button, gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B, *liste;
A=lookup_widget(button,"menures");
gtk_widget_hide(A);
B=create_resvoiture();
gtk_widget_show(B);
liste=lookup_widget(B,"tree4");
affichervoiture(liste);
}
void
on_but_reshotel_clicked                (GtkWidget       *button,                                       gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B; 
GtkWidget *liste;
A=lookup_widget(button,"menures");
gtk_widget_hide(A);
B=create_reshotel();
gtk_widget_show(B);
liste=lookup_widget(B,"tree1");
afficher(liste);
}
void
on_but_confirmerexcursion_clicked      (GtkWidget       *button,                                       gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B;
GtkWidget *pseudoe;
GtkWidget *Nb_places;
GtkWidget *tel;
Excursion e;
A=lookup_widget(button,"ajexcursion");
pseudoe=lookup_widget(button, "pseudoe");
Nb_places=lookup_widget(button, "spinvoyageurs");
tel=lookup_widget(button, "telephone");
strcpy(e.pseudo_client,gtk_entry_get_text(GTK_ENTRY(pseudoe)));
e.Nb_places=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Nb_places));
strcpy(e.tel,gtk_entry_get_text(GTK_ENTRY(tel)));
enregistrere(e);
gtk_widget_hide(A);
B=create_Fac();
gtk_widget_show(B);
}

void
on_but_back2_clicked                   (GtkWidget       *button,                                       gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B,*liste;
A=lookup_widget(button,"ajhotel");
gtk_widget_hide(A);
B=create_reshotel();
gtk_widget_show(B);
liste=lookup_widget(B,"tree1");
afficher(liste);
}

void
on_but_back3_clicked                   (GtkWidget       *button,                                        gpointer user_data)
{
GtkWidget *A;
GtkWidget *B;
A=lookup_widget(button,"confirmhotel");
gtk_widget_hide(A);
B=create_ajhotel();
gtk_widget_show(B);
}

void
on_but_confirmerhotel_clicked          (GtkWidget       *button,                                       gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B;
A=lookup_widget(button,"confirmhotel");
gtk_widget_hide(A);
B=create_Fac();
gtk_widget_show(B);
}

void
on_but_back4_clicked                   (GtkWidget       *button,                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B,*liste;
A=lookup_widget(button,"ajvoiture");
gtk_widget_hide(A);
B=create_resvoiture();
gtk_widget_show(B);
liste=lookup_widget(B,"tree4");
affichervoiture(liste);
}

void
on_but_valider1_clicked                (GtkWidget       *button,                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B;
GtkWidget *pseudov;
GtkWidget *jour1;
GtkWidget *jour2;
GtkWidget *mois1;
GtkWidget *mois2;
GtkWidget *annee1;
GtkWidget *annee2;
Voiture t;
pseudov=lookup_widget(button, "entrypseudov");
jour1=lookup_widget(button, "spin1");
mois1=lookup_widget(button, "spin2");
annee1=lookup_widget(button, "spin3");
jour2=lookup_widget(button, "spin4");
mois2=lookup_widget(button, "spin5");
annee2=lookup_widget(button, "spin6");
strcpy(t.pseudo_client,gtk_entry_get_text(GTK_ENTRY(pseudov)));
t.dt_dd.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour1));
t.dt_dd.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois1));
t.dt_dd.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee1));
t.dt_ff.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour2));
t.dt_ff.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois2));
t.dt_ff.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee2));
enregistrert(t);
A=lookup_widget(button,"ajvoiture");
gtk_widget_hide(A);
B=create_confirmvoiture();
gtk_widget_show(B);
}

void
on_but_back5_clicked                   (GtkWidget       *button,                                       gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B;
A=lookup_widget(button,"confirmvoiture");
gtk_widget_hide(A);
B=create_ajvoiture();
gtk_widget_show(B);
}

void
on_but_confirmvoiture_clicked          (GtkWidget       *button,                                       gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B;
A=lookup_widget(button,"confirmvoiture");
gtk_widget_hide(A);
B=create_Fac();
gtk_widget_show(B);
}

void
on_but_back6_clicked                   (GtkWidget       *button,                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B,*liste;
A=lookup_widget(button,"ajvol");
gtk_widget_hide(A);
B=create_resvol();
gtk_widget_show(B);
liste=lookup_widget(B,"tree2");
affichervol(liste);
}


void
on_but_valider2_clicked                (GtkWidget    *button,                                        gpointer user_data)
{
GtkWidget *A;
GtkWidget *B;
GtkWidget *pseudol;
GtkWidget *dest;
GtkWidget *comp;
GtkWidget *typevol;
GtkWidget *voy;
GtkWidget *classe;
Vol v;
pseudol=lookup_widget(button, "pseudol");
dest=lookup_widget(button, "destination");
comp=lookup_widget(button, "companie");
typevol=lookup_widget(button, "typevo");
voy=lookup_widget(button, "spin10");
classe=lookup_widget(button, "classe");
strcpy(v.pseudo_client,gtk_entry_get_text(GTK_ENTRY(pseudol)));
strcpy(v.destination,gtk_entry_get_text(GTK_ENTRY(dest)));
strcpy(v.companie,gtk_combo_box_get_active_text(GTK_COMBO_BOX (comp)));
strcpy(v.type_vol,gtk_combo_box_get_active_text(GTK_COMBO_BOX (typevol)));
v.Nb_billet=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (voy));
strcpy(v.classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX (classe)));
enregistrerv(v);
A=lookup_widget(button,"ajvol");
gtk_widget_hide(A);
B=create_confirmvol();
gtk_widget_show(B);

}


void
on_but_back7_clicked                   (GtkWidget       *button,                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B;
A=lookup_widget(button,"confirmvol");
gtk_widget_hide(A);
B=create_ajvol();
gtk_widget_show(B);
}

void
on_but_confirmvol_clicked              (GtkWidget       *button,                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B;
A=lookup_widget(button,"confirmvol");
gtk_widget_hide(A);
B=create_Fac();
gtk_widget_show(B);
}

void
on_but_valider_clicked                 (GtkWidget       *button,                                       gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *jour1;
GtkWidget *mois1;
GtkWidget *annee1;
GtkWidget *pseudo_client;
GtkWidget *destination;
GtkWidget *categorie;
GtkWidget *Nb_chambre;
GtkWidget *type_chambre;
GtkWidget *pension;
Hotel h;
A=lookup_widget(button,"ajhotel");
jour=lookup_widget(button, "jour");
mois=lookup_widget(button, "mois");
annee=lookup_widget(button, "annee");
jour1=lookup_widget(button, "jour1");
mois1=lookup_widget(button, "mois1");
annee1=lookup_widget(button, "annee1");
pension=lookup_widget(button,"combopension");
destination=lookup_widget(button, "entrydestination");
categorie=lookup_widget(button, "combocategorie");
Nb_chambre=lookup_widget(button, "entrynbchambres");
type_chambre=lookup_widget(button, "combotypechambre");
pseudo_client=lookup_widget(button, "entrypseudo");
strcpy(h.pension,gtk_combo_box_get_active_text(GTK_COMBO_BOX(pension)));
h.dt_d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
h.dt_d.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
h.dt_d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
h.dt_f.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour1));
h.dt_f.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois1));
h.dt_f.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee1));
strcpy(h.pseudo_client,gtk_entry_get_text(GTK_ENTRY(pseudo_client)));
strcpy(h.destination,gtk_entry_get_text(GTK_ENTRY(destination)));
strcpy(h.categorie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(categorie)));
strcpy(h.Nb_chambre,gtk_entry_get_text(GTK_ENTRY(Nb_chambre)));
strcpy(h.type_chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type_chambre)));

enregistrer(h);
gtk_widget_hide(A);
B=create_confirmhotel();
gtk_widget_show(B);

}

void
on_but_back1_clicked                   (GtkWidget       *button,                                       gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B;
A=lookup_widget(button,"ajexcursion");
gtk_widget_hide(A);
B=create_rechexcursion();
gtk_widget_show(B);
}


void
on_but_back0_clicked                   (GtkWidget       *button,                                       gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B,*liste;
A=lookup_widget(button,"menures");
gtk_widget_hide(A);
B=create_window1();
gtk_widget_show(B);
}


void
on_but_ajouter_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B;
A=lookup_widget(button,"reshotel");
gtk_widget_hide(A);
B=create_ajhotel();
gtk_widget_show(B);
}


void
on_validerex_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B;
A=lookup_widget(button,"rechexcursion");
gtk_widget_hide(A);
B=create_ajexcursion();
gtk_widget_show(B);
}


void
on_but_confirmerres_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_button45_clicked                    (GtkWidget   *button,                                        gpointer    user_data)
{
GtkWidget *A;
GtkWidget *B, *liste;
A=lookup_widget(button,"rechexcursion");
gtk_widget_hide(A);
B=create_resexcursion();
gtk_widget_show(B);
liste=lookup_widget(B,"tree3");
afficherexcursion(liste);
}



void
on_buttree_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B;
A=lookup_widget(button,"window1");
gtk_widget_hide(A);
B=create_menures();
gtk_widget_show(B);

}


void
on_button59_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B,*liste;
A=lookup_widget(button,"reshotel");
gtk_widget_hide(A);
B=create_menures();
gtk_widget_show(B);
}


void
on_button74_clicked                    (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B,*liste;
A=lookup_widget(button,"resvol");
gtk_widget_hide(A);
B=create_ajvol();
gtk_widget_show(B);
}


void
on_button76_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B,*liste;
A=lookup_widget(button,"resvol");
gtk_widget_hide(A);
B=create_menures();
gtk_widget_show(B);
}


void
on_but_resvol_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B, *liste;
A=lookup_widget(button,"menures");
gtk_widget_hide(A);
B=create_resvol();
gtk_widget_show(B);
liste=lookup_widget(B,"tree2");
affichervol(liste);
}


void
on_but_resexcursion_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B,*liste;
A=lookup_widget(button,"menures");
gtk_widget_hide(A);
B=create_resexcursion();
gtk_widget_show(B);
liste=lookup_widget(B,"tree3");
afficherexcursion(liste);
}


void
on_button68_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B,*liste;
A=lookup_widget(button,"resexcursion");
gtk_widget_hide(A);
B=create_rechexcursion();
gtk_widget_show(B);
}


void
on_button70_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B,*liste;
A=lookup_widget(button,"resexcursion");
gtk_widget_hide(A);
B=create_menures();
gtk_widget_show(B);
}

void
on_button80_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B,*liste;
A=lookup_widget(button,"resvoiture");
gtk_widget_hide(A);
B=create_ajvoiture();
gtk_widget_show(B);
}


void
on_button82_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *A;
GtkWidget *B,*liste;
A=lookup_widget(button,"resvoiture");
gtk_widget_hide(A);
B=create_menures();
gtk_widget_show(B);
}


void
on_tree1_row_activated                 (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

gchar *str_data;
GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter   iter;
  if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path))//
  { 
  gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 0, &str_data, -1);//namlo cpy lil continue te3 collone loula (0) fi str_data 
  }

Selected_Resv_Hotel.ID=str_data; 
FILE *f;
f=fopen("Reshotel.bin","rb");
if(f!=NULL)
	{
	struct Hotel A;
	while(!(feof(f)))
		{
		fread(&A,sizeof(Hotel),1,f);
		if(Selected_Resv_Hotel.ID==A.ID)
                Selected_Resv_Hotel=A;
		}}
}


void
on_tree2_row_activated                 (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *str_data;
GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter   iter;
  if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path))//
  { 
  gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 0, &str_data, -1);//namlo cpy lil continue te3 collone loula (0) fi str_data 
  }
Selected_Resv_Vol.ID=str_data; 
FILE *f;
f=fopen("Resvol.bin","rb");
if(f!=NULL)
	{
	struct Vol A;
	while(!(feof(f)))
		{
		fread(&A,sizeof(Vol),1,f);
		if(Selected_Resv_Vol.ID==A.ID)
                Selected_Resv_Vol=A;
		}}
}

void
on_tree3_row_activated                 (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *str_data;
GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter   iter;
  if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path))//
  { 
  gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 0, &str_data, -1);//namlo cpy lil continue te3 collone loula (0) fi str_data 
  }

Selected_Resv_Excursion.ID=str_data; 

FILE *f;
f=fopen("Resexcursion.bin","rb");
if(f!=NULL)
	{
	struct Excursion A;
	while(!(feof(f)))
		{  
		fread(&A,sizeof(Excursion),1,f);
		if(Selected_Resv_Excursion.ID==A.ID)
                Selected_Resv_Excursion=A;
		}}

}


void
on_tree4_row_activated                 (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *str_data;
GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter   iter;
  if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path))//
  { 
  gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 0, &str_data, -1);//namlo cpy lil continue te3 collone loula (0) fi str_data 
  }

Selected_Resv_Voiture.ID=str_data; 
FILE *f;
f=fopen("Resvoiture.bin","rb");
if(f!=NULL)
	{
	struct Voiture A;
	while(!(feof(f)))
		{
		fread(&A,sizeof(Voiture),1,f);
		if(Selected_Resv_Voiture.ID==A.ID)
                Selected_Resv_Voiture=A;
		}} 
}


void
on_supphotel_clicked                   (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *liste;
liste=lookup_widget(button,"tree1");
supprimerhotel (Selected_Resv_Hotel.ID);
afficher(liste);
}


void
on_supprimervol_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *liste;
liste=lookup_widget(button,"tree2");
supprimervol (Selected_Resv_Vol.ID);
affichervol(liste);
}


void
on_supprimerexcursion_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *liste;
liste=lookup_widget(button,"tree3");
supprimerexcursion(Selected_Resv_Excursion.ID);
g_print("\nID = %d",Selected_Resv_Excursion.ID);
afficherexcursion(liste);
}


void
on_supprimervoiture_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *liste;
liste=lookup_widget(button,"tree4");
supprimervoiture (Selected_Resv_Voiture.ID);
affichervoiture(liste);
}

