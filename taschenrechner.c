#include <gtk/gtk.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int zaehler=0,minus2=0,plus2=0,div2=0,multi2=0,erstezahl,zweitezahl,durchlaufen=0;
char Rechnung[9]={0,0,0,0,0,0,0,0,0,0};

static void divi(GtkWidget *widget, gpointer data){
int i = atoi(Rechnung);
erstezahl=i;
zaehler=0;
div2=1;
for (int i=0;i<10;i++){
	Rechnung[i] = 0;}
}
static void multi(GtkWidget *widget, gpointer data){
int i = atoi(Rechnung);
erstezahl=i;
zaehler=0;
multi2=1;
for (int i=0;i<10;i++){
	Rechnung[i] = 0;}
}
static void plus(GtkWidget *widget, gpointer data){
int i = atoi(Rechnung);
erstezahl=i;
	zaehler=0;
	plus2=1;
	for (int i=0;i<10;i++){
		Rechnung[i] = 0;}
}
static void minus(GtkWidget *widget, gpointer data){
int i = atoi(Rechnung);
erstezahl=i;

zaehler=0;
minus2=1;
	for (int i=0;i<10;i++){
	                    Rechnung[i] = 0;}
}
static void taste(GtkWidget *widget, gpointer data){
	
	Rechnung[zaehler]=data;
	zaehler++;
	int i2=atoi(Rechnung);
	zweitezahl=i2;
			}

int main(int argc, char *argv[]) {
int ergebnis;
GtkWidget *window;
GtkWidget *table;
GtkWidget *button;
	for (int i=0;i<10;i++){
                   Rechnung[i] = 0;
		}
gchar *values[16] = { "7", "8", "9", "/"," 4", "5", "6", "*","1", "2", "3", "-","0", ".", "=", "+"};

gtk_init(&argc, &argv);
window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
gtk_window_set_default_size(GTK_WINDOW(window), 250, 180);
gtk_window_set_title(GTK_WINDOW(window), "GtkTable");
gtk_container_set_border_width(GTK_CONTAINER(window), 5);
table = gtk_table_new(4, 4, TRUE);
gtk_table_set_row_spacings(GTK_TABLE(table), 2);
gtk_table_set_col_spacings(GTK_TABLE(table), 2);

int pos =0;
				button = gtk_button_new_with_label(values[pos]);
				gtk_table_attach_defaults(GTK_TABLE(table), button, 0, 1, 0,1 );
				g_signal_connect(button,"clicked",G_CALLBACK(taste),'7');
				pos++;
				button = gtk_button_new_with_label(values[pos]);
				gtk_table_attach_defaults(GTK_TABLE(table), button, 1,2 ,0,1 );
				g_signal_connect(button,"clicked",G_CALLBACK(taste),'8');
				pos++;
				button = gtk_button_new_with_label(values[pos]);
				gtk_table_attach_defaults(GTK_TABLE(table), button, 2,3 ,0,1 );
				g_signal_connect(button,"clicked",G_CALLBACK(taste),'9');
				pos++;
				button = gtk_button_new_with_label(values[pos]);
				gtk_table_attach_defaults(GTK_TABLE(table), button, 3,4 ,0,1 );
				g_signal_connect(button,"clicked",G_CALLBACK(divi),'/');
				pos++;
				button = gtk_button_new_with_label(values[pos]);
                                gtk_table_attach_defaults(GTK_TABLE(table), button, 0,1 ,1,2 );
                                g_signal_connect(button,"clicked",G_CALLBACK(taste),'4');
                                pos++;
				button = gtk_button_new_with_label(values[pos]);
                                gtk_table_attach_defaults(GTK_TABLE(table), button, 1,2 ,1,2 );
                                g_signal_connect(button,"clicked",G_CALLBACK(taste),'5');
                                pos++;
				button = gtk_button_new_with_label(values[pos]);
                                gtk_table_attach_defaults(GTK_TABLE(table), button, 2,3 ,1,2 );
                                g_signal_connect(button,"clicked",G_CALLBACK(taste),'6');
                                pos++;
				button = gtk_button_new_with_label(values[pos]);
                                gtk_table_attach_defaults(GTK_TABLE(table), button, 3,4 ,1,2 );
                                g_signal_connect(button,"clicked",G_CALLBACK(multi),'*');
                                pos++;
				button = gtk_button_new_with_label(values[pos]);
                                gtk_table_attach_defaults(GTK_TABLE(table), button, 0,1 ,2,3 );
                                g_signal_connect(button,"clicked",G_CALLBACK(taste),'1');
                                pos++;
                                button = gtk_button_new_with_label(values[pos]);
                                gtk_table_attach_defaults(GTK_TABLE(table), button, 1,2 ,2,3 );
                                g_signal_connect(button,"clicked",G_CALLBACK(taste),'2');
                                pos++;
				button = gtk_button_new_with_label(values[pos]);
                                gtk_table_attach_defaults(GTK_TABLE(table), button, 2,3 ,2,3 );
                                g_signal_connect(button,"clicked",G_CALLBACK(taste),'3');
                                pos++;
				button = gtk_button_new_with_label(values[pos]);
                                gtk_table_attach_defaults(GTK_TABLE(table), button, 3,4 ,2,3 );
                                g_signal_connect(button,"clicked",G_CALLBACK(minus),'-');
                                pos++;
				button = gtk_button_new_with_label(values[pos]);
                                gtk_table_attach_defaults(GTK_TABLE(table), button, 0,1 ,3,4 );
                                g_signal_connect(button,"clicked",G_CALLBACK(taste),'0');
                                pos++;
				button = gtk_button_new_with_label(values[pos]);
                                gtk_table_attach_defaults(GTK_TABLE(table), button, 1,2 ,3,4 );
                                g_signal_connect(button,"clicked",G_CALLBACK(taste),'.');
                                pos++;
				button = gtk_button_new_with_label(values[pos]);
                                gtk_table_attach_defaults(GTK_TABLE(table), button, 2,3 ,3,4 );
                                g_signal_connect(button,"clicked",G_CALLBACK(gtk_main_quit), NULL);
				pos++;
				button = gtk_button_new_with_label(values[pos]);
	                        gtk_table_attach_defaults(GTK_TABLE(table), button, 3,4 ,3,4 );
	                        g_signal_connect(button,"clicked",G_CALLBACK(plus),'+');
	                        pos++;

	gtk_container_add(GTK_CONTAINER(window), table);
	g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all(window);
	gtk_main();
	
	if(minus2==1){
	ergebnis=erstezahl-zweitezahl;
	printf("%i-%i = %i\n" ,erstezahl,zweitezahl,ergebnis);
	minus2=0;
	zaehler=0;
	}
	if(plus2==1){
        ergebnis=erstezahl+zweitezahl;
	printf("%i+%i = %i\n" ,erstezahl,zweitezahl,ergebnis);
	plus2=0;
	zaehler=0;
        }
	if(multi2==1){
	ergebnis=erstezahl*zweitezahl;
	printf("%i*%i = %i\n" ,erstezahl,zweitezahl,ergebnis);
	multi2=0;
	zaehler=0;
	}
	if(div2==1){
	ergebnis=erstezahl/zweitezahl;
	printf("%i/%i = %i\n" ,erstezahl,zweitezahl,ergebnis);
	div2=0;
	zaehler=0;
	}
return 0;
}
