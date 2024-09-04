#include <stdio.h>
#include <string.h>

char titles[100][100];
char authors[100][100];
float prices[100];
int quantities[100];
int C = 0;

void ajouter_livre() {

    char titre[100];
    printf("Entrez le titre du livre: \n");
    scanf("%s", titre);

    for (int i = 0; i < C ; i++) {
        if (strcmp(titles[i], titre) == 0) {
            printf("le livre est deja existe ajoutez la quantite pour ajouter : \n");
            int q;
            scanf("%d", &q);
            quantities[i] += q;
            printf("quantite est ajouter !\n");
            return;
        }
    }

    if (C < 100) {
        strcpy(titles[C], titre);

        printf("Entrez l auteur du livre: \n");
        scanf("%s", authors[C]);

        printf("Entrez le prix du livre: \n");
        scanf("%f", &prices[C]);

        printf("Entrez la quantite: \n");
        scanf("%d", &quantities[C]);

        C++;
    } else {
        printf("Stock est plein !\n");
    }
}

void Afficher_Livre() {
    if(C==0){
        printf("Aucun livre disponible.\n");

    } else if (C > 0) {
        for (int i = 0; i < C ; i++) {
            printf("Livre %d:\n", i + 1);
            printf("Titre : %s\n", titles[i]);
            printf("Auteur : %s\n", authors[i]);
            printf("Prix : %.2f\n", prices[i]);
            printf("Quantité en stock : %d\n\n", quantities[i]);
        }
    }
}

void Chercher_livre() {
    char title[100];
    printf("Entrez le titre du livre a rechercher : ");
    scanf("%s", title);

    for (int i = 0; i < C ; i++) {
        if (strcmp(titles[i], title) == 0) {
            printf("Livre trouvé :\n");
            Afficher_Livre();
            return;
        }
    }
    printf("Livre non trouvé.\n");
}


void mis_a_jour() {
    char title[100];
    printf("Entrez le titre du livre : ");
    scanf("%s", title);

    for (int i = 0; i < C; i++) {
        if (strcmp(titles[i], title) == 0) {
            printf("Entrez la nouvelle quantite : ");
            scanf("%d", &quantities[i]);
            printf("Quantite mise a jour avec succes !\n");
            return;
        }
    }
    printf("Livre non trouve.\n");
}


void supprimer_livre() {
    char title[100];
    printf("Entrez le titre du livre à supprimer : ");
    scanf("%s", title);

    for (int i = 0; i < C; i++) {
        if (strcmp(titles[i], title) == 0) {
            for (int j = i; j < C - 1; j++) {
                strcpy(titles[j], titles[j + 1]);
                strcpy(authors[j], authors[j + 1]);
                prices[j] = prices[j + 1];
                quantities[j] = quantities[j + 1];
            }
            C--;
            printf("Livre supprime avec succes !\n");
            return;
        }
    }
    printf("Livre non trouve.\n");
}


void nombre_livre() {
    int total = 0;
    if(C>0){
        for (int i = 0; i < C; i++) {
        total += quantities[i];
    printf("Nombre total de livres en library : %d\n", total);
}
    }
    else{
        printf("aucun livre dans library");
    }
}
int main() {
    int choix;
    do {
        printf("\n--- Gestion de Librairie ---\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres disponibles\n");
        printf("3. Rechercher un livre par son titre\n");
        printf("4. Mettre a jour la quantite d un livre\n");
        printf("5. Supprimer un livre\n");
        printf("6. Afficher le nombre total de livres en stock\n");
        printf("7. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_livre();
                break;
            case 2:
                Afficher_Livre();
                break;
            case 3:
                Chercher_livre();
                break;
            case 4:
                mis_a_jour() ;
                break;
            case 5:
                supprimer_livre();
                break;
            case 6:
                nombre_livre();
                break;
            case 7:
                printf(" Merci de votre participation !\n");

                break;
            default:
                printf("Option invalide.\n");
        }
    } while (choix != 7);

    return 0;
}
