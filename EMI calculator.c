#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gtk/gtk.h>

int period, months, year, month, status;
long int principle;
long double ROI, EMI, monthly_ROI, factor, value;
GtkWidget *amount_label, *ROI_label, *months_label, *result_label;
GtkWidget *amount_entry, *ROI_entry, *months_entry, *result_entry;
const gchar *principle_str, *ROI_str, *months_str;
char EMI_str[10];

void ldtoa(long double num, char *res, int afterpoint)
{
	char temp;
	int index = 0;
	long int intpart;
	intpart = (long int)num;
	*(res + 0) = '3';
	*(res + 1) = '.';
	*(res + 2) = '2';
	*(res + 3) = '\0';
	//while(intpart)
	//{
		//temp = (char)(intpart%10);
		//*(res + index++) = temp + 0x30;
		//intpart /= 10;
	//}
}

void print_msg(GtkWidget *widget, gpointer window)
{
	//char principle_str[10], ROI_string[10];
	principle_str = gtk_entry_get_text(GTK_ENTRY(amount_entry));
	ROI_str = gtk_entry_get_text(GTK_ENTRY(ROI_entry));
	months_str = gtk_entry_get_text(GTK_ENTRY(months_entry));
	//g_print("principle string %s and roi string %s\n", principle_str, ROI_str);
	principle = atoi(principle_str);
	ROI = atof(ROI_str);
	months = atoi(months_str);
	//months = 12*year + month;
	monthly_ROI = ROI/12.0;
	value = 1 + monthly_ROI/100;
	factor = pow(value, months);
	EMI = principle*(monthly_ROI/100)*factor/(factor-1);
	//ldtoa(3.2, EMI_str, 3);
	gcvt(EMI, 5, EMI_str);
	gtk_entry_set_text(GTK_ENTRY(result_entry), EMI_str);
	//g_print("EMI calcuted is %Lf and factor is %Lf \n", EMI, factor);
}

int main(int argc, char* argv[])
{
	GtkApplication *app;
	GtkWidget *window, *button, *halign, *box;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//gtk_window_set_title(GTK_WINDOW(window), "");
	
	amount_label = gtk_label_new("Amount");
	amount_entry = gtk_entry_new();
	
	ROI_label = gtk_label_new("Rate of interest");
	ROI_entry = gtk_entry_new();
	
	months_label = gtk_label_new("Months");
	months_entry = gtk_entry_new();
	
	result_label = gtk_label_new("EMI");
	result_entry = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(result_entry), "0");
	
	button = gtk_button_new_with_label ("Calculate");
	g_signal_connect(button, "clicked", G_CALLBACK(print_msg), NULL);
	
	//halign = gtk_alignment_new(0, 0, 0, 0);
	gtk_widget_set_halign(button, GTK_ALIGN_CENTER);
	gtk_widget_set_valign(button, GTK_ALIGN_CENTER);
	
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
	gtk_box_pack_start(GTK_BOX(box),amount_label, TRUE, TRUE, TRUE);
	gtk_box_pack_start(GTK_BOX(box),amount_entry, TRUE, TRUE, TRUE);
	gtk_box_pack_start(GTK_BOX(box),ROI_label, TRUE, TRUE, TRUE);
	gtk_box_pack_start(GTK_BOX(box),ROI_entry, TRUE, TRUE, TRUE);
	gtk_box_pack_start(GTK_BOX(box),months_label, TRUE, TRUE, TRUE);
	gtk_box_pack_start(GTK_BOX(box),months_entry, TRUE, TRUE, TRUE);
	gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, TRUE);
	gtk_box_pack_start(GTK_BOX(box),result_label, TRUE, TRUE, TRUE);
	gtk_box_pack_start(GTK_BOX(box),result_entry, TRUE, TRUE, TRUE);
	//gtk_container_add(GTK_CONTAINER(halign), button);
	//gtk_container_add(GTK_CONTAINER(window), halign);
	//gtk_container_add(GTK_CONTAINER(window), button);
	gtk_container_add(GTK_CONTAINER(window), box);
	
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
	gtk_widget_show_all(window);
  
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);  

	gtk_main();

	return 0;
}
