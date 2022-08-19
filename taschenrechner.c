#include <gtk/gtk.h>

static void taste(GtkWidget *widget, gpointer data){
	int Rechnung[3];
	Rechnung[0]=data;
	printf("%i",Rechnung[0]);
}

int main(int argc, char *argv[]) {

GtkWidget *window;
GtkWidget *table;
GtkWidget *button;

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

int pos = 0;

	//for (int i=0; i < 4; i++) {
	//	for (int j=0; j < 4; j++) {
				button = gtk_button_new_with_label(values[pos]);
				gtk_table_attach_defaults(GTK_TABLE(table), button, 0, 1, 0,1 );
				g_signal_connect(button,"clicked",G_CALLBACK(taste),7);
				pos++;
				button = gtk_button_new_with_label(values[pos]);
				gtk_table_attach_defaults(GTK_TABLE(table), button, 1,2 ,0,1 );
				g_signal_connect(button,"clicked",G_CALLBACK(taste),8);
				pos++;
				button = gtk_button_new_with_label(values[pos]);
				gtk_table_attach_defaults(GTK_TABLE(table), button, 2,3 ,0,1 );
				g_signal_connect(button,"clicked",G_CALLBACK(taste),9);
				pos++;
				button = gtk_button_new_with_label(values[pos]);
				gtk_table_attach_defaults(GTK_TABLE(table), button, 3,4 ,0,1 );
				g_signal_connect(button,"clicked",G_CALLBACK(taste),/);
				pos++;
	//	}
	//}
	gtk_container_add(GTK_CONTAINER(window), table);
	g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);
	//g_signal_connect(button,"clicked",G_CALLBACK(taste),7);
	
	gtk_widget_show_all(window);
	gtk_main();
return 0;
}