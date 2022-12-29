#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "reservation.h"
#include <stdlib.h>
#include <stdio.h>
int no_of_digits(int num)
{
    int digit_count = 0;
    while(num > 0)
    {
        digit_count++;
        num /= 10;
    }
    return digit_count;
}
char *i_to_a(int num)
{
    char *str;
    int digit_count = 0;
    if(num < 0)
    {
        num = -1*num;
        digit_count++;
    }
    digit_count += no_of_digits(num);   
    str = malloc(sizeof(char)*(digit_count+1));
    str[digit_count] = '\0';
    while(num > 0)
    {
        str[digit_count-1] = num%10 + '0';
        num = num/10;
        digit_count--;
    }}

void enregistrer (Hotel h){
struct Hotel X;
FILE *A=fopen("Reshotel.bin","rb");
fread(&X,1,sizeof(Hotel),A);
if(feof(A))
    h.ID=0;
else{
    while(!feof(A)){
    fread(&X,1,sizeof(Hotel),A); }
    h.ID=X.ID+1;
    fclose(A);  }
FILE *f=fopen("reshotel.txt","a+");
FILE *d=fopen("Reshotel.bin","ab+");
fwrite(&h,sizeof(Hotel),1,d);
fclose(d);
if(f!=NULL){
fprintf(f,"%s %s %s %d %d %d %d %d %d %s %s %s\n",h.pseudo_client,h.destination,h.categorie,h.dt_d.jour,h.dt_d.mois,h.dt_d.annee,h.dt_f.jour,h.dt_f.mois,h.dt_f.annee,h.Nb_chambre,h.type_chambre,h.pension);
fclose(f); }
}

void enregistrere(Excursion e){
struct Excursion X;
FILE *f=fopen("resexcursion.txt","a+");
FILE *d=fopen("Resexcursion.bin","ab+");
fread(&X,1,sizeof(Excursion),d);
if(feof(d))
    e.ID=0;
else{
    while(!feof(d)){
    fread(&X,1,sizeof(Excursion),d); }
    e.ID=X.ID+1;
}
fwrite(&e,sizeof(Excursion),1,d);
fclose(d);
if(f!=NULL){
fprintf(f,"%s %d %s\n",e.pseudo_client,e.Nb_places,e.tel);
fclose(f); } 
 }
void enregistrerv(Vol v){
struct Vol X;
FILE *f=fopen("resvol.txt","a+");
FILE *d=fopen("Resvol.bin","ab+");
fread(&X,1,sizeof(Vol),d);

if(feof(d)){
    v.ID=0;
 }
else{
    while(!feof(d)){
    fread(&X,1,sizeof(Vol),d); }
    v.ID=X.ID+1;
    //fclose(d);  
}

fwrite(&v,sizeof(Vol),1,d);
fclose(d);
if(f!=NULL){
fprintf(f,"%s %s %s %s %d %s\n",v.pseudo_client,v.destination,v.companie,v.type_vol,v.Nb_billet,v.classe);
fclose(f); }
}
void enregistrert(Voiture t){
struct Voiture X;
FILE *f=fopen("resvoiture.txt","a+");
FILE *d=fopen("Resvoiture.bin","ab+");
fread(&X,1,sizeof(Voiture),d);
if(feof(d))
    t.ID=0;
else{
    while(!feof(d)){
    fread(&X,1,sizeof(Voiture),d); }
    t.ID=X.ID+1;
}
fwrite(&t,sizeof(Voiture),1,d);
fclose(d);
if(f!=NULL){
fprintf(f,"%s %d %d %d %d %d %d\n",t.pseudo_client,t.dt_dd.jour,t.dt_dd.mois,t.dt_dd.annee,t.dt_ff.jour,t.dt_ff.mois,t.dt_ff.annee);
fclose(f); } 
 }

void afficher(GtkWidget *liste){
  enum
{ID,
 pseudo_client,
 destination,
 categorie,
 dt_d,
 dt_f,
 Nb_chambre,
 type_chambre,
 pension,
 COLUMNS
};
  char sh[30];
  char sh1[30];
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
       store=NULL;
       struct Hotel h;
 FILE *f;
     store=gtk_tree_view_get_model(liste);
	
  if(store==NULL)
	{
	  renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("ID Reservation",renderer,"text",ID, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
		
          renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("Nom client",renderer,"text",pseudo_client, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          
	  renderer = gtk_cell_renderer_text_new();
          column =gtk_tree_view_column_new_with_attributes("Destination",renderer,"text",destination,NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("Categorie",renderer,"text",categorie, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          renderer = gtk_cell_renderer_text_new();
          column =gtk_tree_view_column_new_with_attributes("Date arrivée",renderer,"text",dt_d,NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new();
          column =gtk_tree_view_column_new_with_attributes("Date sortie",renderer,"text",dt_f,NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("Nombre de chambres",renderer,"text",Nb_chambre, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          
          renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("Type de chambres",renderer,"text",type_chambre, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          renderer = gtk_cell_renderer_text_new();
	  column =gtk_tree_view_column_new_with_attributes("Pension",renderer,"text",pension,NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          
}
store=gtk_list_store_new(COLUMNS,G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
     f= fopen("Reshotel.bin","rb");
      if(f==NULL)
        {
                return;
        }
     else 
       {  
        f=fopen("Reshotel.bin","rb");
        while(!(feof(f))){
       	fread(&h,sizeof(struct Hotel),1,f);
        
        sprintf(sh,"%d/%d/%d",h.dt_d.jour,h.dt_d.mois,h.dt_d.annee);
	sprintf(sh1,"%d/%d/%d",h.dt_f.jour,h.dt_f.mois,h.dt_f.annee);
       	
gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, ID,(int *)h.ID,pseudo_client, h.pseudo_client, destination,h.destination,categorie,h.categorie,Nb_chambre,h.Nb_chambre,type_chambre,h.type_chambre,pension,h.pension,dt_d,sh,dt_f,sh1,-1);
        }
	fclose(f);
       gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
       g_object_unref (store);
}   }
void affichervol(GtkWidget *liste){
  enum {
  ID,
  pseudo_client,
  destination,
  companie,
 type_vol,
 Nb_billet,
 classe,
 COLUMNS
};
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
       store=NULL;
       struct Vol v;
 FILE *f;
     store=gtk_tree_view_get_model(liste);
	
  if(store==NULL)
	{ renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("ID Reservation",renderer,"text",ID, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("Nom client",renderer,"text",pseudo_client, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          
	  renderer = gtk_cell_renderer_text_new();
          column =gtk_tree_view_column_new_with_attributes("Destination",renderer,"text",destination,NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("Companie",renderer,"text",companie, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          renderer = gtk_cell_renderer_text_new();
          column =gtk_tree_view_column_new_with_attributes("Type de vol",renderer,"text",type_vol,NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          renderer = gtk_cell_renderer_text_new();
          column =gtk_tree_view_column_new_with_attributes("Nombre de billet",renderer,"text",Nb_billet,NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("Classe",renderer,"text",classe, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);       }
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING);
     f= fopen("Resvol.bin","rb");
      if(f==NULL)
        {
                return;
        }
     else 
       {  
        f=fopen("Resvol.bin","rb");
        while(!(feof(f))){
       	fread(&v,sizeof(struct Vol),1,f);
    	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, ID,(int *)v.ID, pseudo_client, v.pseudo_client, destination,v.destination,companie,v.companie,type_vol,v.type_vol,Nb_billet,(int*)v.Nb_billet,classe,v.classe,-1);
 }
	fclose(f);
       gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
       g_object_unref (store);
}   }
void affichervoiture(GtkWidget *liste){
  enum
{
 ID,
 pseudo_client,
 dt_dd,
 dt_ff,
 COLUMNS
};
  char sh[30];
  char sh1[30];
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
       store=NULL;
       struct Voiture t;
 FILE *f;
     store=gtk_tree_view_get_model(liste);
	
  if(store==NULL)
	{  renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("ID Reservation",renderer,"text",ID, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("Nom client",renderer,"text",pseudo_client, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          column =gtk_tree_view_column_new_with_attributes("Date arrivée",renderer,"text",dt_dd,NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new();
          column =gtk_tree_view_column_new_with_attributes("Date sortie",renderer,"text",dt_ff,NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          
}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
     f= fopen("Resvoiture.bin","rb");
      if(f==NULL)
        {
                return;
        }
     else 
       {  
        f=fopen("Resvoiture.bin","rb");
        while(!(feof(f))){
       	fread(&t,sizeof(struct Voiture),1,f);
        
        sprintf(sh,"%d/%d/%d",t.dt_dd.jour,t.dt_dd.mois,t.dt_dd.annee);
	sprintf(sh1,"%d/%d/%d",t.dt_ff.jour,t.dt_ff.mois,t.dt_ff.annee);
       	
gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, ID,(int *)t.ID, pseudo_client, t.pseudo_client,dt_dd,sh,dt_ff,sh1,-1);
        }
	fclose(f);
       gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
       g_object_unref (store);
}   }
void afficherexcursion(GtkWidget *liste){
enum
{ ID,
 pseudo_client,
 Nb_places,
 tel,
 COLUMNS
};
  char sh[10];
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
       store=NULL;
       struct Excursion e;
 FILE *f;
     store=gtk_tree_view_get_model(liste);
	
  if(store==NULL)
	{  renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("ID Reservation",renderer,"text",ID, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          renderer = gtk_cell_renderer_text_new();
          column = gtk_tree_view_column_new_with_attributes("Nom client",renderer,"text",pseudo_client, NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          column =gtk_tree_view_column_new_with_attributes("Nombre de places",renderer,"text",Nb_places,NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
renderer = gtk_cell_renderer_text_new();
          column =gtk_tree_view_column_new_with_attributes("Telephone",renderer,"text",tel,NULL);
          gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
          
}
store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING);
     f= fopen("Resexcursion.bin","rb");
      if(f==NULL)
        {
                return;
        }
     else 
       {  
        f=fopen("Resexcursion.bin","rb");
        while(!(feof(f))){
       	fread(&e,sizeof(struct Excursion),1,f);
       	
gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, ID,(int *)e.ID, pseudo_client, e.pseudo_client,Nb_places,(int *)e.Nb_places,tel,e.tel,-1);
        }
	fclose(f);
       gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
       g_object_unref (store);
}   }

void supprimerhotel (int ID){
FILE *f=fopen("Reshotel.bin","rb");
FILE *d=fopen("Reshotel1.bin","wb");
fclose(d);
d=fopen("Reshotel1.bin","ab");

if((f!=NULL)&&(d!=NULL))
{
struct Hotel h;
while (!(feof(f)))
{ 
 fread(&h,1,sizeof(Hotel),f);
 
 if (h.ID!=ID)
{ 
fwrite(&h,sizeof(Hotel),1,d);

} } } 
fclose(f);
fclose(d);
remove("Reshotel.bin");
rename("Reshotel1.bin","Reshotel.bin");
}
void supprimervol (int ID){
FILE *f=fopen("Resvol.bin","rb");
FILE *d=fopen("Resvol1.bin","wb");
fclose(d);
d=fopen("Resvol1.bin","ab");

if((f!=NULL)&&(d!=NULL))
{
struct Vol v;
while (!(feof(f)))
{ 
 fread(&v,1,sizeof(Vol),f);
 
 if (v.ID!=ID)
{ 
fwrite(&v,sizeof(Vol),1,d);
} } } 
fclose(f);
fclose(d);
remove("Resvol.bin");
rename("Resvol1.bin","Resvol.bin");
}
void supprimervoiture (int ID){
FILE *f=fopen("Resvoiture.bin","rb");
FILE *d=fopen("Resvoiture1.bin","wb");
fclose(d);
d=fopen("Resvoiture1.bin","ab");
if((f!=NULL)&&(d!=NULL))
{
struct Voiture t;
while (!(feof(f)))
{ 
 fread(&t,1,sizeof(Voiture),f);
 
 if (t.ID!=ID)
{ 
fwrite(&t,sizeof(Voiture),1,d);
} } } 
fclose(f);
fclose(d);
remove("Resvoiture.bin");
rename("Resvoiture1.bin","Resvoiture.bin");
}
void supprimerexcursion (int ID){
FILE *f=fopen("Resexcursion.bin","rb");
FILE *d=fopen("Resexcursion1.bin","wb");
fclose(d);
d=fopen("Resexcursion1.bin","ab");
g_print("\n %d ID  ",ID);
if((f!=NULL)&&(d!=NULL))
{
struct Excursion e;
while (!(feof(f)))
{ 
 fread(&e,1,sizeof(Excursion),f);
 
 if(e.ID!=ID)
{ 
fwrite(&e,sizeof(Excursion),1,d);
} } } 
fclose(f);
fclose(d);
remove("Resexcursion.bin");
rename("Resexcursion1.bin","Resexcursion.bin");
}

















