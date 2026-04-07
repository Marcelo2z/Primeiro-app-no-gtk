#include <gtk/gtk.h>

static GtkWidget* status_label = NULL;

//Função on

static void on_led(GtkButton* btn, gpointer user_data) { //função que será chamada logo apos o botão ser clicado;
    gtk_label_set_text(GTK_LABEL(status_label), "LED Ligado");
}

static void off_led(GtkButton* btn, gpointer user_data) {
    gtk_label_set_text(GTK_LABEL(status_label), "LED Desligado");
}

static void activate(GtkApplication* app, gpointer user_data){ //Função Ativa apos iniciar o app;
    GtkWidget* window = gtk_application_window_new(app); //criação de uma janela;
    gtk_window_set_title(GTK_WINDOW(window), "Controle do Arduino");//nome da janela;
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 350);//tamanho da janela;

    //criação de boxes ou containers;

    GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10); //orientação das boxes e espaçamento entre elas
    
    //espaçamento ao redor das boxes;
    gtk_widget_set_margin_top(box, 20);
    gtk_widget_set_margin_bottom(box, 20);
    gtk_widget_set_margin_start(box, 20);
    gtk_widget_set_margin_end(box, 20);

    GtkWidget* title = gtk_label_new("Interface para Arduino"); // Variavel privada
    status_label = gtk_label_new("Status: aguardando comando"); // Variavel global
    
    GtkWidget* btn_ligar = gtk_button_new_with_label("Ligar LED"); //criação do botão de ligar;
    GtkWidget* btn_desligar = gtk_button_new_with_label("Desligar LLED"); //criação do botão de desligar;

    //chamada das funções quando os botões são clicados;

    g_signal_connect(btn_ligar, "clicked", G_CALLBACK(on_led), NULL); 
    g_signal_connect(btn_desligar, "clicked", G_CALLBACK(off_led), NULL);

    //organização dos botões e tituulos no box
    gtk_box_append(GTK_BOX(box), title);
    gtk_box_append(GTK_BOX(box), status_label);
    gtk_box_append(GTK_BOX(box), btn_ligar);
    gtk_box_append(GTK_BOX(box), btn_desligar);
   
    

    gtk_window_set_child(GTK_WINDOW(window), box);
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char** argv){
    GtkApplication* app = gtk_application_new("org.example.arduinoapp", G_APPLICATION_DEFAULT_FLAGS); //função da biblioteca;
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}