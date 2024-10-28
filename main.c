#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char rue[20];
    char ville[20];
    int code_postal;
} adresse;

typedef struct {
    char nom[12];
    int age;
    adresse adresse;
} personne;

void afficher(personne *p, int n) {
    printf("Voici l'affichage des personnes : \n");
    for (int i = 0; i < n; i++) {
        printf("Personne %d:\n", i + 1);
        printf("Nom : %s\n", p[i].nom);
        printf("Âge : %d\n", p[i].age);
        printf("Rue : %s\n", p[i].adresse.rue);
        printf("Ville : %s\n", p[i].adresse.ville);
        printf("Code postal : %d\n", p[i].adresse.code_postal);
        printf("---------------------\n");
    }
}

void modifier(personne *p, int n) {
    int index;
    char choice[12];
    printf("Tapez le numero de la personne a modifier (1 a %d) : ", n);
    scanf("%d", &index);
    getchar(); // Vider le tampon

    if (index > 0 && index <= n) {
        index--;
        printf("Que souhaitez-vous modifier ? (nom, age, adresse) : ");
        scanf("%s", choice);
        getchar(); // Vider le tampon

        if (strcmp(choice, "nom") == 0) {
            printf("Saisir le nom : ");
            scanf("%s", p[index].nom);
        } else if (strcmp(choice, "age") == 0) {
            printf("Saisir l'âge : ");
            scanf("%d", &p[index].age);
        } else if (strcmp(choice, "adresse") == 0) {
            printf("Saisir la rue : ");
            scanf("%s", p[index].adresse.rue);
            printf("Saisir la ville : ");
            scanf("%s", p[index].adresse.ville);
            printf("Saisir le code postal : ");
            scanf("%d", &p[index].adresse.code_postal);
        } else {
            printf("Option invalide\n");
        }
    } else {
        printf("Numéro invalide\n");
    }
}

void supprimer(personne *p, int *n) {
    char choix[4];
    int deleted;

    printf("Voulez-vous supprimer une personne ? (Oui / Non) : ");
    scanf("%s", choix);

    if (strcmp(choix, "oui") == 0) {
        printf("Quel est le numéro de la personne à supprimer ? ");
        scanf("%d", &deleted);

        if (deleted >= 1 && deleted <= *n) {
            for (int i = deleted - 1; i < *n - 1; i++) {
                p[i] = p[i + 1]; // Décaler les personnes
            }
            (*n)--; // Réduire le nombre de personnes
        } else {
            printf("Numéro invalide\n");
        }
    }
}

int main() {
    int n;

    printf("Quel est le nombre de personnes que vous voulez creer : ");
    scanf("%d", &n);
    personne p[n];

    // Saisie des informations des personnes
    for (int i = 0; i < n; i++) {
        printf("Saisir le nom : ");
        scanf("%s", p[i].nom);
        printf("Saisir l'age : ");
        scanf("%d", &p[i].age);
        printf("Saisir la rue : ");
        scanf("%s", p[i].adresse.rue);
        printf("Saisir la ville : ");
        scanf("%s", p[i].adresse.ville);
        printf("Saisir le code postal : ");
        scanf("%d", &p[i].adresse.code_postal);
        printf("###############################\n");
    }

     _Bool running = true;
do {

    int choix;
    printf("Que voulez-vous choisir ?\n");
    printf("1. Afficher\n 2. Modifier\n 3. Supprimer\n 4.Quitter\n");
    printf("ecrire le numéro : ");
    scanf("%d", &choix);



        switch (choix) {
            case 1:
                afficher(p, n);
                break;
            case 2:
                modifier(p, n);
                afficher(p, n); // Afficher après modification
                break;
            case 3:
                supprimer(p, &n);
                afficher(p, n); // Afficher après suppression
                break;
            case 4:
                running = false;
                break;
            default:
                printf("Choix invalide\n");
        }

    } while ( running );



    return 0;
}

